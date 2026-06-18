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
    properties: { func: { type: 'string' }, file: { type: 'string' } } } } },
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
0. FIRST: cat ~/conker/tools/ido_cookbook.md  — proven IDO 5.3 -O2 matching idioms. Apply the relevant ones; obey its "When to BAIL" section.
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
- Cannot reach 0 → REVERT src/${c.file}.c so ${c.func} is exactly its original stub line  #pragma GLOBAL_ASM("asm/nonmatchings/${c.file}/${c.func}.s")  again, return matched=false with best score. Leaving non-matching C would break the build; reverting on failure is MANDATORY.`

const distillPrompt = (notesBlob) => `You curate ~/conker/tools/ido_cookbook.md, a tight set of TRANSFERABLE IDO 5.3 -O2 matching idioms. From this round's agent notes, append only GENERALIZABLE idioms NOT already covered (ignore function-specific facts: addresses, specific constants, per-func offsets). Deduplicate; do not rewrite/remove existing entries; if nothing generalizes, make NO edit. Edit the file in place.

ROUND NOTES:
${notesBlob}

Return a one-line summary of what you added (or "no new idioms").`

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
  const sel = await agent(`Run EXACTLY: python3 ~/conker/tools/select_chunk.py ${CHUNK} ${MAXI}\nReturn its stdout JSON array as {"candidates": <array>}. Do nothing else — no edits, no other commands.`,
    { label: `select:r${r + 1}`, phase: 'Select', schema: CHUNK_SCHEMA })
  const chunk = (sel && sel.candidates) || []
  if (!chunk.length) { log(`round ${r + 1}: candidate pool empty — stopping`); break }
  log(`round ${r + 1}: ${chunk.length} candidates — ${chunk.map(c => c.func).join(', ')}`)

  phase('Match')
  const results = (await parallel(chunk.map((c) => () =>
    agent(matchPrompt(c), { label: `iter:${c.func}`, phase: 'Match', schema: MATCH_SCHEMA })
  ))).filter(Boolean)
  const matched = results.filter((x) => x.matched)
  log(`round ${r + 1}: ${matched.length}/${results.length} matched`)

  phase('Distill')
  const notesBlob = results.map((x) => `${x.func} [${x.matched ? 'MATCH' : 'miss ' + x.score}]: ${x.notes}`).join('\n')
  await agent(distillPrompt(notesBlob), { label: `distill:r${r + 1}`, phase: 'Distill' })

  phase('Integrate')
  if (!matched.length) { log(`round ${r + 1}: no matches to commit`); continue }
  const integ = await agent(integratePrompt(matched), { label: `integrate:r${r + 1}`, phase: 'Integrate', schema: INTEG_SCHEMA })
  totalCommitted += (integ && integ.committed ? integ.committed.length : 0)
  log(`round ${r + 1}: committed ${integ && integ.committed ? integ.committed.length : 0} (ROM ${integ && integ.rom_ok ? 'OK' : 'CHECK!'}) — ${integ ? integ.summary : 'no report'}`)
}

return { rounds: ROUNDS, totalCommitted }
