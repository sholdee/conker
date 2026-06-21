export const meta = {
  name: 'conker-orchestrator',
  description: 'Self-driving Conker decomp loop: select candidates, self-iterate-match, distill, then verify + ROM-gate + commit — repeated for N rounds',
  phases: [
    { title: 'Select', detail: 'pick the next distinct-file chunk' },
    { title: 'Match', detail: 'one self-iterating agent per function' },
    { title: 'Distill', detail: 'fold lessons into the cookbook' },
    { title: 'Integrate', detail: 're-verify, full ROM sha1 gate, commit' },
  ],
}

// Agent-agnostic: the match/distill/integrate steps run as the workflow's DEFAULT
// agent, so ANY agent runtime drives this identically — no agent-specific code or
// prompts. `repo` lets any clone path work; the rest are tuning dials.
const A = typeof args === 'string' ? JSON.parse(args) : (args || {})
const ROUNDS = A.rounds || 4
const CHUNK = A.chunk || 8
const MAXI = A.maxi || 40
const REPO = A.repo || '~/conker'

const MATCH_SCHEMA = {
  type: 'object', additionalProperties: false,
  required: ['func', 'file', 'matched', 'score', 'final_c', 'notes'],
  properties: {
    func: { type: 'string' }, file: { type: 'string' },
    matched: { type: 'boolean', description: 'true ONLY if iter_match.sh printed SCORE: 0' },
    score: { type: 'integer' }, final_c: { type: 'string' }, notes: { type: 'string' },
  },
}
const CHUNK_SCHEMA = {
  type: 'object', additionalProperties: false, required: ['candidates'],
  properties: { candidates: { type: 'array', items: {
    type: 'object', additionalProperties: false, required: ['func', 'file'],
    properties: {
      func: { type: 'string' }, file: { type: 'string' },
      ref_func: { type: 'string' }, ref_file: { type: 'string' },
      ref_similarity: { type: 'number' },
    } } } },
}
const INTEG_SCHEMA = {
  type: 'object', additionalProperties: false,
  required: ['committed', 'rom_ok', 'summary'],
  properties: {
    committed: { type: 'array', items: { type: 'string' } },
    reverted: { type: 'array', items: { type: 'string' } },
    rom_ok: { type: 'boolean' }, commit_hash: { type: 'string' }, summary: { type: 'string' },
  },
}

const matchPrompt = (c) => `You are matching ONE function in the mkst/conker N64 decompilation (IDO 5.3, -O2 -g3) to byte-identical assembly, using a real compile+diff feedback loop.

YOUR FUNCTION: ${c.func}   (in ${REPO}/conker/src/${c.file}.c)
Target asm: ${REPO}/conker/asm/nonmatchings/${c.file}/${c.func}.s

THE LOOP:
0. FIRST: cat ${REPO}/tools/ido_cookbook.md  — the CORE IDO 5.3 -O2 idioms + a When-to-BAIL checklist; apply the relevant ones. For a stubborn diff or a specific instruction pattern not in the core, grep ${REPO}/tools/ido_reference.md (the full idiom set).${c.ref_func ? `
0b. A SIMILAR ALREADY-MATCHED function is your strongest guide (asm similarity ${c.ref_similarity}): its byte-matching C is at /tmp/ref_${c.func}.c and its asm at ${REPO}/conker/asm/nonmatchings/${c.ref_file}/${c.ref_func}.s. READ BOTH FIRST. Diff its asm against YOUR target .s to see what differs; reuse its structure, types, casts, loop/branch shapes, and idioms as a template — adapt offsets/constants/symbols to your function. This is a worked example of exactly the codegen you're targeting.` : ''}
0c. IF your function builds DISPLAY LISTS (signature has "Gfx *", or the target asm writes packet words via gSP*/gDP* macros or raw stores to ->w0/->w1): READ ${REPO}/.claude/skills/decompile-microcode/f3dex2-reference.md (and s2dex-reference.md for S2DEX/sprites) for the full F3DEX2 command encodings. Hand-write the matching gSP*/gDP* macros against the raw words; do NOT leave raw word stores.
1. Read the target .s and src/${c.file}.c (neighbor style/types); read structs.h/functions.h/variables.h for types.
2. Replace the line  #pragma GLOBAL_ASM("asm/nonmatchings/${c.file}/${c.func}.s")  in src/${c.file}.c with your candidate C.
3. Run:  CONKER_REPO=${REPO} ${REPO}/tools/iter_match.sh ${c.file} ${c.func}   → builds ONLY your object and prints a diff + "SCORE: N" (0 = byte-perfect).
4. Read the diff (TARGET vs CURRENT; 'r' = register-only; '>' = extra instr; missing line = absent instr), refine, re-run. Up to ~12 iterations toward 0.

HARD RULES (a violation corrupts the shared build tree):
- ONLY edit src/${c.file}.c. NEVER touch other src/ files or shared headers (include/*.h). Add any missing extern/prototype as a LOCAL decl at the TOP of your file.
- IDO is C89: all locals declared at the top of their block.
- NEVER run make / make -C conker / build.sh / any full build. ONLY iter_match.sh. It is concurrency-safe because every agent owns a different file.

WHEN DONE:
- SCORE: 0 → STOP, LEAVE the matching C in the file, return matched=true, file="${c.file}", final_c=your function.
- Cannot reach 0 → FIRST, if your best SCORE was <= 80 (a near miss worth permuting), harvest the seed: mkdir -p ${REPO}/.nearmiss, then write the best-scoring C you reached to ${REPO}/.nearmiss/${c.func}.json as JSON {"func","file","score","c"} (use python3 -c with json.dump so the C string is escaped correctly). THEN REVERT src/${c.file}.c so ${c.func} is exactly its original stub line  #pragma GLOBAL_ASM("asm/nonmatchings/${c.file}/${c.func}.s")  again, and return matched=false with best score. Leaving non-matching C would break the build; reverting on failure is MANDATORY. (The harvested seed feeds a background decomp-permuter pass on spare CPU.)`

const distillPrompt = (notesBlob) => `You curate ${REPO}/tools/ido_cookbook.md, a TIGHT set of transferable IDO 5.3 -O2 matching idioms. It is already MATURE (~250 idioms) and the idiom set has largely plateaued, so your DEFAULT is to make NO edit. Read the file first.

Add a bullet ONLY if this round's notes reveal a technique that is genuinely NOVEL — not covered, even loosely, by ANY existing bullet. Ignore function-specific facts (addresses, specific constants, per-func offsets). When in doubt, add NOTHING.

If you DO add (rare):
- MERGE it as ONE tight bullet under the single most relevant EXISTING "## " section. NEVER create a new "## " section (that fragments the file).
- Keep it one or two lines; no examples longer than the existing style.
- If you notice two existing bullets that say the same thing, you MAY merge them into one (dedup), but otherwise do not rewrite existing entries.

ROUND NOTES:
${notesBlob}

Return a one-line summary (what you added, or "no new idioms").`

// ---- the self-driving loop ----
let totalCommitted = 0
for (let r = 0; r < ROUNDS; r++) {
  phase('Select')
  // Similarity-based scheduling: prefer stubs with a strong matched reference
  // (writes /tmp/ref_<func>.c for each); falls back to smallest-first to fill.
  const sel = await agent(`Run EXACTLY: CONKER_REPO=${REPO} python3 ${REPO}/tools/similar_chunk.py ${CHUNK} ${MAXI}\nReturn its stdout JSON array as {"candidates": <array>}, preserving each object's func, file, ref_func, ref_file, ref_similarity fields. Do nothing else — no edits, no other commands.`,
    { label: `select:r${r + 1}`, phase: 'Select', schema: CHUNK_SCHEMA })
  const chunk = (sel && sel.candidates) || []
  if (!chunk.length) { log(`round ${r + 1}: candidate pool empty — stopping`); break }
  const withRef = chunk.filter(c => c.ref_func).length
  log(`round ${r + 1}: ${chunk.length} candidates (${withRef} with matched reference)`)

  phase('Match')
  // One self-iterating agent per function (distinct files → concurrency-safe).
  const results = (await parallel(chunk.map((c) => () =>
    agent(matchPrompt(c), { label: `iter:${c.func}`, phase: 'Match', schema: MATCH_SCHEMA })
  ))).filter(Boolean)
  const matched = results.filter((x) => x.matched)
  log(`round ${r + 1}: ${matched.length}/${results.length} matched`)

  phase('Distill')
  const notesBlob = results.map((x) => `${x.func} [${x.matched ? 'MATCH' : 'miss ' + x.score}]: ${x.notes}`).join('\n')
  await agent(distillPrompt(notesBlob), { label: `distill:r${r + 1}`, phase: 'Distill' })

  phase('Integrate')
  // DETERMINISTIC integration: integrate.py force-clean rebuilds + dual-SHA1 gates +
  // bisects + commits. It keeps ONLY truly de-stubbed score-0 matches; the rest are
  // skipped/reverted. No LLM judgement in the gate — this makes autonomous commits safe.
  if (!matched.length) { log(`round ${r + 1}: no matches to commit`); continue }
  const pairs = matched.map((m) => `${m.file} ${m.func}`).join(' ')
  const integ = await agent(
    `Run EXACTLY this one command and report its full stdout verbatim — do nothing else, edit nothing:\n  CONKER_REPO=${REPO} python3 ${REPO}/tools/integrate.py ${pairs}`,
    { label: `integrate:r${r + 1}`, phase: 'Integrate', schema: INTEG_SCHEMA })
  const n = (integ && integ.committed) ? integ.committed.length : 0
  totalCommitted += n
  log(`round ${r + 1}: integrate.py — ${integ ? integ.summary : 'no report'}`)
}

return { rounds: ROUNDS, totalCommitted }
