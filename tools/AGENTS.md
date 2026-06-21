# Conker Decomp — Orchestrator Runbook

Match every `game` function to byte-identical IDO 5.3 `-O2 -g3` asm. Branch `decomp/game-matches`.
Two engines run in PARALLEL: the **orchestrator** (LLM agents match `GLOBAL_ASM` stubs) and the
**permuter daemon** (cracks JUSTREG residue on spare CPU). You coordinate them BETWEEN runs.

## CURRENT MODE — Codex engine (rationing Claude tokens)
The matching now runs on **Codex** (zero Claude tokens), via a shell mirror of the orchestrator:
- **Run:** `bash tools/orchestrator_codex.sh 8 150 8` (chunk maxi rounds) as a tracked background task →
  one completion notification. Uses `codex exec --full-auto` for matching; similar_chunk + integrate.py
  are the deterministic glue.
- **MAXI regime (size cap, RAISE as bands deplete):** ≤90 was the early sweet spot but is now EXHAUSTED
  (run 9 starved). Unattempted runway as of run 10: 91-150≈559, 151-250≈488, 251-400≈280, 400+≈210. Now at
  `maxi 150`; when round-1 candidates drop below ~8 again, bump to 250, then 400, etc. Bigger funcs = lower
  match rate but more bytes each.
- **Cadence each gap (lean — minimal Claude tokens):** force-clean ROM gate → `apply_wins.py` →
  `permuter_daemon.py import_new` → relaunch `orchestrator_codex.sh` → `git push sholdee decomp/game-matches`.
- **Cookbook is TIERED:** `ido_cookbook.md` = 182-line CORE (always read); `ido_reference.md` = full
  270-bullet set (grep on-demand). Codex/Claude prompts read core + grep reference.
- **DISTILL (back on):** `orchestrator_codex.sh` ends each run with a codex distill step — skims the run's
  `/tmp/codexm_*.log`, APPENDS only genuinely-novel idioms to `ido_reference.md` under `## Post-cutover distilled`.
  Append-only guard (new file must start with old + ≤2KB growth, else revert) + reverts stray edits; self-commits.
- **Fork port (DONE — 42/70 committed):** sibling-fork matches were ported via `port_fork.py` (per-func
  iter_match filter) → integrate.py. Re-running yields ~0 (the other 28 fail in our tree on header/struct
  drift); skip unless ~/conker-llm-fork advances materially.
- **Backup remote:** `sholdee` → https://github.com/sholdee/conker (branch decomp/game-matches). `git push sholdee` each gap.
- The Claude Workflow `orchestrator.js` still exists (agent-agnostic) if switching back from Codex.

## INVARIANTS — learned the hard way; violating these corrupts commits
1. **Act ONLY on a workflow's completion NOTIFICATION.** `ps`/output-size checks LIE (a workflow shows
   no process between agent spawns). Acting early ⇒ your build races the running one ⇒ stale-bin ⇒ bad commit.
2. **Never build / edit src / git while ANY workflow or build runs.** One actor on the tree at a time.
3. **FORCE-clean before every ROM check:** `rm -f conker/build/conker.us.bin build/conker.us.z64` FIRST.
   A failed compile leaves a STALE matching bin → a false "ROM OK". This caused both integrity incidents.
4. **The gate is the full ROM sha1** (inner `842e3d34…`, outer `4cbadd3c…`). `integrate.py` enforces it
   deterministically — trust it; never hand-commit a match without a force-clean ROM verify. A pre-commit hook
   (`tools/git-hooks/`, active via `core.hooksPath`) blocks edits to these SHA constants — the "fake a match"
   vector (override a genuine gate change with `ALLOW_GATE_EDIT=1 git commit`).

## THE CYCLE  (run only when NOTHING else is running)
```
0. INSPECT (force-clean):
   . .venv/bin/activate
   rm -f conker/build/conker.us.bin build/conker.us.z64
   make -C conker && make -C conker replace && make -j
   sha1sum build/conker.us.z64   # MUST be 4cbadd3c4e0729dec46af64ad018050eada4f47a
   git status --short | grep conker/src   # any stray .c = failed-agent cruft → git checkout it
1. APPLY PERMUTER WINS:   python3 tools/apply_wins.py        # collect→port→verify→commit; non-porters auto-.noport
2. INGEST HARVEST:        python3 tools/permuter_daemon.py import_new
3. REFILL (if pool low):  python3 tools/stub_expand.py expand 30   (ROM-gated) ; then REGEN RANKING (below) ; force-clean ROM verify
4. PERMUTERS: a SUPERVISOR keeps MAX_PARALLEL alive automatically (auto-replaces dead/cracked/timed-out
   with the newest seeds). Just ensure it's running (safe any time — only permutes what's imported):
   kill -0 $(cat /tmp/permuter_supervisor.pid 2>/dev/null) 2>/dev/null || \
     setsid python3 tools/permuter_daemon.py supervise 180 3600 >/tmp/permuter_supervise.log 2>&1 </dev/null &
5. ORCHESTRATOR:  Workflow { scriptPath: "tools/orchestrator.js", args: {rounds:8, chunk:8, maxi:55} }
6. WAIT for the completion notification. Repeat.
```
REGEN RANKING (after any expand):
```
cd conker; for d in asm/nonmatchings/game_*; do for f in "$d"/*.s; do [ -f "$f" ]||continue; \
  echo "$(grep -cE '^\s+/\*' "$f") ${f#asm/nonmatchings/}"; done; done | sort -n > /tmp/game_ranked2.txt
```

## TOOLS
- `orchestrator.js` — self-driving loop: select→match→distill→**rescue(Codex)**→integrate ×N rounds (Workflow).
  Claude agents read the cookbook + a similar matched reference, harvest near-misses (score ≤80) to
  `~/conker/.nearmiss/<func>.json`; Codex (`agentType: codex:codex-rescue`) takes a 2nd pass at misses ≤150.
  Integration = `integrate.py` (gates BOTH engines — only true de-stubbed score-0 matches commit).
- `select_chunk.py N M` — next N DISTINCT-file stubs (6..M instr), not in `/tmp/orchestrator_attempted.txt` (smallest-first; legacy).
- `find_similar.py FUNC [--top N]` — rank MATCHED functions by asm similarity to FUNC (cached corpus, register-normalized; drops low-quality refs).
- `similar_chunk.py N M` — like select_chunk but prioritizes stubs with a STRONG matched reference (similarity scheduling);
  writes each reference C to `/tmp/ref_<func>.c` for the match/rescue agents. This is what the orchestrator's Select stage runs.
- `iter_match.sh FILE FUNC` — build ONE object + object-diff vs `expected/`. `SCORE: 0` = match.
  ⚠ a STUB also scores 0 — only trust it for an already-de-stubbed function.
- `integrate.py FILE FUNC …` — DETERMINISTIC gate: force-clean build, dual-sha1, bisect out broken funcs, commit good.
- `stub_expand.py expand N` — flip N pure-asm game segments `asm`→`c` in the yaml + extract → new stubs.
  ROM-gated; auto-bisects rodata/jtbl segments that fail; refreshes `expected/`.
- `permuter_daemon.py {import_new | run SECS | collect | supervise [interval] [timeout]}` — spare-CPU decomp-permuter
  over `.nearmiss/` seeds (nice 19, detached, newest-first). `supervise` = long-running self-restarting pool (pidfile-guarded);
  `run` one-shot tops up free slots. `import_new` touches the build tree → run only BETWEEN runs.
- `apply_wins.py` — port + project-re-verify + commit permuter winners (their score-0 is isolated; re-verify!).
- `ido_cookbook.md` — IDO matching idioms agents read; the orchestrator's distiller MERGES novel ones (no new sections).
- `setup.sh` — fresh-host bring-up (re-applies n64splat marker-label patch, pins `pycparser<3`, venv).

## PROGRESS / STATE
```
git log --oneline | grep -c "game: match"                          # match commits
grep -rho GLOBAL_ASM conker/src/game_*.c | wc -l                   # stubs remaining
grep -cE '^\s+- \[0x[0-9A-Fa-f]+, asm\]' conker/conker.us.yaml     # un-stubbed segments left
```

## KNOWN LIMITS
- A few un-stubbed segments fail the expand sha1-gate (rodata/jump-table) — need manual yaml rodata subsegments.
- Some permuter wins don't port (isolated import context ≠ project) — `apply_wins` auto-`.noport`s them.
- jtbl-externalized & native-64-bit functions are unmatchable as stubbed C (BAIL — see cookbook).
- After `stub_expand`, run `permuter_daemon import_new` only between runs; the `expected/` refresh is automatic.

## FRESH HOST
`tools/setup.sh`, then place `baserom.us.z64` (sha1 `4cbadd3c…`) in repo root, then run THE CYCLE.
