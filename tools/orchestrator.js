export const meta = {
  name: 'conker-orchestrator',
  description: 'Self-driving Conker decomp loop: select candidates, self-iterate-match, distill, then verify + ROM-gate + commit — repeated for N rounds',
  phases: [
    { title: 'Select', detail: 'pick the next distinct-file chunk' },
    { title: 'Match', detail: 'one self-iterating agent per function' },
    { title: 'Distill', detail: 'fold lessons into the cookbook' },
    { title: 'Rescue', detail: 'Codex second-pass on Claude near-misses' },
    { title: 'Integrate', detail: 're-verify, full ROM sha1 gate, commit' },
  ],
}

const A = typeof args === 'string' ? JSON.parse(args) : (args || {})
const ROUNDS = A.rounds || 4
const CHUNK = A.chunk || 8
const MAXI = A.maxi || 40

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

YOUR FUNCTION: ${c.func}   (in ~/conker/conker/src/${c.file}.c)
Target asm: ~/conker/conker/asm/nonmatchings/${c.file}/${c.func}.s

THE LOOP:
0. FIRST: cat ~/conker/tools/ido_cookbook.md  — proven IDO 5.3 -O2 matching idioms. Apply the relevant ones; obey its "When to BAIL" section.${c.ref_func ? `
0b. A SIMILAR ALREADY-MATCHED function is your strongest guide (asm similarity ${c.ref_similarity}): its byte-matching C is at /tmp/ref_${c.func}.c and its asm at ~/conker/conker/asm/nonmatchings/${c.ref_file}/${c.ref_func}.s. READ BOTH FIRST. Diff its asm against YOUR target .s to see what differs; reuse its structure, types, casts, loop/branch shapes, and idioms as a template — adapt offsets/constants/symbols to your function. This is a worked example of exactly the codegen you're targeting.` : ''}
1. Read the target .s and src/${c.file}.c (neighbor style/types); read structs.h/functions.h/variables.h for types.
2. Replace the line  #pragma GLOBAL_ASM("asm/nonmatchings/${c.file}/${c.func}.s")  in src/${c.file}.c with your candidate C.
3. Run:  ~/conker/tools/iter_match.sh ${c.file} ${c.func}   → builds ONLY your object and prints a diff + "SCORE: N" (0 = byte-perfect).
4. Read the diff (TARGET vs CURRENT; 'r' = register-only; '>' = extra instr; missing line = absent instr), refine, re-run. Up to ~12 iterations toward 0.

HARD RULES (a violation corrupts the shared build tree):
- ONLY edit src/${c.file}.c. NEVER touch other src/ files or shared headers (include/*.h). Add any missing extern/prototype as a LOCAL decl at the TOP of your file.
- IDO is C89: all locals declared at the top of their block.
- NEVER run make / make -C conker / build.sh / any full build. ONLY iter_match.sh. It is concurrency-safe because every agent owns a different file.

WHEN DONE:
- SCORE: 0 → STOP, LEAVE the matching C in the file, return matched=true, file="${c.file}", final_c=your function.
- Cannot reach 0 → FIRST, if your best SCORE was <= 80 (a near miss worth permuting), harvest the seed: mkdir -p ~/conker/.nearmiss, then write the best-scoring C you reached to ~/conker/.nearmiss/${c.func}.json as JSON {"func","file","score","c"} (use python3 -c with json.dump so the C string is escaped correctly). THEN REVERT src/${c.file}.c so ${c.func} is exactly its original stub line  #pragma GLOBAL_ASM("asm/nonmatchings/${c.file}/${c.func}.s")  again, and return matched=false with best score. Leaving non-matching C would break the build; reverting on failure is MANDATORY. (The harvested seed feeds a background decomp-permuter pass on spare CPU.)`

const distillPrompt = (notesBlob) => `You curate ~/conker/tools/ido_cookbook.md, a TIGHT set of transferable IDO 5.3 -O2 matching idioms. It is already MATURE (~250 idioms) and the idiom set has largely plateaued, so your DEFAULT is to make NO edit. Read the file first.

Add a bullet ONLY if this round's notes reveal a technique that is genuinely NOVEL — not covered, even loosely, by ANY existing bullet. Ignore function-specific facts (addresses, specific constants, per-func offsets). When in doubt, add NOTHING.

If you DO add (rare):
- MERGE it as ONE tight bullet under the single most relevant EXISTING "## " section. NEVER create a new "## " section (that fragments the file).
- Keep it one or two lines; no examples longer than the existing style.
- If you notice two existing bullets that say the same thing, you MAY merge them into one (dedup), but otherwise do not rewrite existing entries.

ROUND NOTES:
${notesBlob}

Return a one-line summary (what you added, or "no new idioms").`

const rescuePrompt = (m, c) => `You are Codex, a SECOND decompiler brought in to RESCUE a function Claude could NOT byte-match. Match it to its target IDO 5.3 -O2 -g3 assembly using a real compile+diff loop. Claude's best was SCORE ${m.score} (0 = byte-perfect; lower = closer). A different reasoning approach may crack it.

YOUR FUNCTION: ${m.func}  (in ~/conker/conker/src/${m.file}.c)
Target asm: ~/conker/conker/asm/nonmatchings/${m.file}/${m.func}.s

START FROM CLAUDE'S BEST ATTEMPT — do not restart from scratch:
- Claude's near-miss C is at ~/conker/.nearmiss/${m.func}.json (the "c" field), if it scored <= 80. Load it as your starting candidate.
- What diverged, per Claude: ${JSON.stringify((m.notes || '').slice(0, 500))}${c && c.ref_func ? `
- A SIMILAR already-matched function (asm similarity ${c.ref_similarity}) is a strong template: its byte-matching C is at /tmp/ref_${m.func}.c and its asm at ~/conker/conker/asm/nonmatchings/${c.ref_file}/${c.ref_func}.s. Diff that asm against your target to see exactly what to change.` : ''}
- IDO idioms: cat ~/conker/tools/ido_cookbook.md (apply the relevant ones; obey its "When to BAIL").

THE LOOP:
1. Replace  #pragma GLOBAL_ASM("asm/nonmatchings/${m.file}/${m.func}.s")  in src/${m.file}.c with your candidate C.
2. Run  ~/conker/tools/iter_match.sh ${m.file} ${m.func}  → prints a diff + "SCORE: N" (0 = perfect). Read the diff (TARGET vs CURRENT; 'r' = register-only), refine, re-run. Up to ~12 iterations, then STOP — do NOT grind.

HARD RULES (a violation corrupts the shared build tree):
- ONLY edit src/${m.file}.c. NEVER touch other src/ files or shared headers. Add any missing extern/prototype as a LOCAL decl at the TOP of the file.
- IDO is C89: declare all locals at the top of their block.
- NEVER run make / make -C conker / any full build. ONLY iter_match.sh (it builds just your one object; concurrency-safe).
- Do NOT run the decomp-permuter or any long brute-force/seed search — a background daemon ALREADY permutes register-allocation/JUSTREG ties on spare CPU. Your value is the STRUCTURAL / idiom fix. If after ~12 iterations the ONLY remaining diff is register-only ('r' lines) or a pure instruction-schedule tie, that is permuter territory — harvest and bail (below), do not search.

WHEN DONE (stay within the iteration budget — this phase must not stall the round):
- SCORE: 0 → STOP, LEAVE your matching C in the file. Report "MATCHED ${m.func}" + a 1-line note on the fix.
- Cannot reach 0 → FIRST, if your best score was <= 80, harvest the seed: write your best C to ~/conker/.nearmiss/${m.func}.json as JSON {"func","file","score","c"} (python3 -c with json.dump) so the daemon can finish it. THEN run  git checkout conker/src/${m.file}.c  to revert ${m.func} to its exact stub line, and report your best score. Leaving non-matching C breaks the shared build. (The gate re-verifies independently, so only a true SCORE-0 de-stub commits.)`

const integratePrompt = (claimed) => `You are the INTEGRATION gate for the Conker decomp orchestrator. The match agents this round left matching C in these files (one function each); failures already reverted themselves to stubs. Your job: re-verify, ROM-gate, and commit ONLY what truly matches. Be strict — never commit a non-matching tree.

CLAIMED MATCHES (func, file): ${JSON.stringify(claimed.map(c => ({ func: c.func, file: c.file })))}

STEPS (run from ~/conker, activate venv: source .venv/bin/activate):
1. For EACH claimed (func,file): run  ~/conker/tools/iter_match.sh <file> <func>  and read the SCORE line.
   - SCORE: 0 → keep it.
   - NOT 0 → that file is suspect: run  git checkout conker/src/<file>.c  to revert it, and exclude that func. (Within a round each file holds at most one new function, so reverting affects only that one.)
2. If NO functions remain verified, return committed=[], rom_ok=true, summary="nothing to commit". Otherwise:
3. Full build + ROM gate:  make -C conker && make -C conker replace && make -j   then  sha1sum build/conker.us.z64  — it MUST equal 4cbadd3c4e0729dec46af64ad018050eada4f47a.
   - If it does NOT match: do NOT commit. Revert the verified files one at a time (git checkout) and rebuild until the ROM matches again, to find the culprit; exclude it. Re-confirm the ROM matches before committing the rest.
4. Commit: git add the verified conker/src/<file>.c files AND tools/ido_cookbook.md, then
   git commit -m "game: match <N> functions via orchestrator (round)\n\n<one bullet per func: name + 1-phrase desc>\n\nasm-differ score 0 each; full-ROM sha1 verifies.\n\nCo-Authored-By: Claude Opus 4.8 (1M context) <noreply@anthropic.com>"
   (git identity sholdee@gmail.com on branch decomp/game-matches is already configured.)
5. Append any of THIS round's near-misses you were told about? (skip — handled elsewhere.)

Return: committed (list of func names actually committed), reverted (funcs you reverted), rom_ok (did the final ROM sha1 match), commit_hash (short hash or ""), summary (one line).`

// ---- the self-driving loop ----
let totalCommitted = 0
for (let r = 0; r < ROUNDS; r++) {
  phase('Select')
  // Similarity-based scheduling: prefer stubs with a strong matched reference
  // (writes /tmp/ref_<func>.c for each); falls back to smallest-first to fill.
  const sel = await agent(`Run EXACTLY: python3 ~/conker/tools/similar_chunk.py ${CHUNK} ${MAXI}\nReturn its stdout JSON array as {"candidates": <array>}, preserving each object's func, file, ref_func, ref_file, ref_similarity fields. Do nothing else — no edits, no other commands.`,
    { label: `select:r${r + 1}`, phase: 'Select', schema: CHUNK_SCHEMA })
  const chunk = (sel && sel.candidates) || []
  if (!chunk.length) { log(`round ${r + 1}: candidate pool empty — stopping`); break }
  const withRef = chunk.filter(c => c.ref_func).length
  log(`round ${r + 1}: ${chunk.length} candidates (${withRef} with matched reference) — ${chunk.map(c => c.ref_func ? `${c.func}~${c.ref_func}(${c.ref_similarity})` : c.func).join(', ')}`)

  phase('Match')
  const results = (await parallel(chunk.map((c) => () =>
    agent(matchPrompt(c), { label: `iter:${c.func}`, phase: 'Match', schema: MATCH_SCHEMA })
      .then(x => x && ({ ...x, hadRef: !!c.ref_func }))
  ))).filter(Boolean)
  const matched = results.filter((x) => x.matched)
  const mRef = matched.filter(x => x.hadRef).length, nRef = results.filter(x => x.hadRef).length
  log(`round ${r + 1}: ${matched.length}/${results.length} matched — with-ref ${mRef}/${nRef}, no-ref ${matched.length - mRef}/${results.length - nRef}`)

  phase('Distill')
  const notesBlob = results.map((x) => `${x.func} [${x.matched ? 'MATCH' : 'miss ' + x.score}]: ${x.notes}`).join('\n')
  await agent(distillPrompt(notesBlob), { label: `distill:r${r + 1}`, phase: 'Distill' })

  phase('Rescue')
  // Codex (unlimited tokens, different reasoning) takes a SECOND pass at Claude's
  // near-misses, seeded with Claude's best C + the similarity reference. Successes
  // leave matching C; the deterministic gate re-verifies independently, so Codex's
  // word is never trusted. Misses are distinct-file → safe in parallel; failures
  // revert to stub and are skipped by integrate.py. Graceful: a Codex error → null.
  // Rescue every real miss: with similarity scheduling ~all have a reference, so even
  // a hard bail is a viable Codex target (different reasoning + the template). The gate
  // reverts anything Codex can't truly match, so over-triggering only costs Codex time.
  const misses = results.filter((x) => !x.matched && x.score > 0)
  let rescuedFuncs = []
  if (misses.length) {
    await parallel(misses.map((m) => () =>
      agent(rescuePrompt(m, chunk.find((c) => c.func === m.func)),
        { label: `codex:${m.func}`, phase: 'Rescue', agentType: 'codex:codex-rescue' })))
    rescuedFuncs = misses
    log(`round ${r + 1}: codex rescue attempted ${misses.length} near-miss(es) [${misses.map(m => m.func).join(', ')}]`)
  }

  phase('Integrate')
  // DETERMINISTIC integration: integrate.py force-clean rebuilds + dual-SHA1 gates +
  // bisects + commits. It keeps ONLY truly de-stubbed funcs (Claude matches AND any
  // Codex rescues that reached score 0); stubs/failures are skipped. No LLM judgement
  // in the gate — this is what makes autonomous commits safe.
  const integPairs = [...matched, ...rescuedFuncs]
  if (!integPairs.length) { log(`round ${r + 1}: no matches to commit`); continue }
  const pairs = integPairs.map((m) => `${m.file} ${m.func}`).join(' ')
  const integ = await agent(
    `Run EXACTLY this one command and report its full stdout verbatim — do nothing else, edit nothing:\n  python3 ~/conker/tools/integrate.py ${pairs}`,
    { label: `integrate:r${r + 1}`, phase: 'Integrate', schema: INTEG_SCHEMA })
  const n = (integ && integ.committed) ? integ.committed.length : 0
  totalCommitted += n
  log(`round ${r + 1}: integrate.py — ${integ ? integ.summary : 'no report'}`)
}

return { rounds: ROUNDS, totalCommitted }
