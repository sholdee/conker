# Conker Decomp — Orchestrator Runbook

Match every `game` function to byte-identical IDO 5.3 `-O2 -g3` asm. Branch `decomp/game-matches`.
Two engines run in PARALLEL: the **orchestrator** (LLM agents match `GLOBAL_ASM` stubs) and the
**permuter daemon** (cracks JUSTREG residue on spare CPU). You coordinate them BETWEEN runs.

## LATEST STATE & PENDING (read FIRST after compaction)
- **Active run:** `bash tools/orchestrator_codex.sh 12 400 8` (cycle 5), tracked → notifies. At **~62.7% matched
  (3703/5904), ~32% bytes**. Rate declining (47→37→27%/cycle) = the FRONTIER, NOT a bug (see FAILURE ANALYSIS);
  keep matching ($0 trickle), do not treat the decline as fixable.
- **UNCOMMITTED tools — live on-disk, COMMIT AT GAP:** `dashboard.py` (worker `best` now from
  `/tmp/best_<func>.score` not the codex log; phase pgrep uses `[x]pat` bracket trick to stop self-match; typing
  card/phase), `harvest_nearmiss.py` + `permuter_daemon.py` (PERMUTER SEED FIX below), NEW `build_actor.py` +
  `map_select.py` (Phase-2 analysis). Already committed: type_pass/type_select/type_orchestrator/struct_cluster,
  integrate add-back + CONKER_TYPING msg.
- **GAP CHECKLIST (cycle-5 gap):**
  1. **Cookbook tweaks** (commit, so distill's `git checkout -- ido_cookbook.md` can't revert): (a) diagnostic
     reframe "far score on a big func = one early residue cascading; diagnose the FIRST mismatch, don't chase
     magnitude"; (b) BAIL bullets: reloc-spelling `%lo(sym±off)` on identical bytes + stack-aggregate off-by-one-
     word; (c) `register`/`volatile` grows the -g3 frame, try last.
  2. Commit the uncommitted tools above + push sholdee.
  3. **Wire `match→type` into `orchestrator_codex.sh`** (after match rounds): `while pairs=$(python3
     tools/type_select.py 12); [ -n "$pairs" ]; do bash tools/type_pass.sh $pairs; done` — self-skips when no
     casts. CANNOT edit while running.
  4. **Permuter — BACKFILL then feed (it is PAUSED, killed 2026-06-23; was idle-spinning).** Diagnosis: 323
     `.nearmiss` json seeds but only 4 had `.full.c` (the rest are stale OLD-harvester seeds the fixed importer
     skips), and those 4 had all since MATCHED → `nonmatchings_perm/` was EMPTY → supervisor spin-looped
     "topped up 6 (was 0 running)" launching workers that instantly died. So the reservoir is ~99% unusable.
     FIX = **backfill `.full.c` for STILL-UNMATCHED seeds**: for each `.nearmiss/<func>.json` whose
     `asm/nonmatchings/*/<func>.s` still exists (still a stub), re-run `iter_match.sh` once to regenerate the
     compilable `.full.c` (harvest_nearmiss now saves it). $0 Claude (codex/CPU only) but iter_match swaps `src`
     + builds → RACES the live orchestrator, so run ONLY at the gap (tree quiescent). THEN prune any seed dirs
     w/o `.full.c`, `permuter_daemon.py import_new`, VERIFY one worker actually compiles+permutes (real proof),
     then RELAUNCH the supervisor (`setsid python3 tools/permuter_daemon.py supervise 180 3600 >/tmp/permuter_
     supervise.log 2>&1 </dev/null &`). Do NOT relaunch the supervisor until the backfill has fed it — else it
     resumes the empty-pantry spin-loop.
  5. **EFFORT TRIAGE — progress-gated bail + difficult-list shelving** (stops the far-grind: measured 10/13 live
     slots were on >500-score funcs; no `attempts.tsv` existed so plateau was undetectable). Design (agreed
     2026-06-23, user-approved): **(a) instrument** — `iter_match.sh` appends `(func, round, best_score)` to
     `attempts.tsv` each round (it already computes the score). **(b) progress-gated bail, NOT count-gated** — the
     match loop/prompt bails when best-score shows NO improvement for M iterations (stall), NOT at a fixed attempt
     count. Keeps the converging "one-residue-away" agent running; kills only true plateaus. Tie to the diagnostic
     reframe: bail only after the FIRST mismatch was diagnosed + its fix tried + score still won't move. Keep a
     generous absolute ceiling as backstop. **(c) shelve on stall** — that stall verdict writes `func + last_score
     + reason` to `difficult_functions.txt`; `similar_chunk.py` SELECT excludes that list (ONE signal drives both
     layers). **(d) thaw, don't abandon** — re-admit a shelved func only when its inputs change (new typed struct /
     new shared decl / neighboring permuter crack), not permanently. **(e) bias SELECT toward tractable** —
     prefer near/mid + low-instr + never-plateaued; let the permuter own the 321-`.nearmiss` reservoir. NOTE: this
     raises throughput-per-token on the tractable frontier and stops the bleed; it does NOT raise the intrinsic
     ceiling (~80-85% of the tail stays hard). Shelve criterion is ATTEMPTS-WITHOUT-PROGRESS, never raw score (a
     far score is often one early residue cascading = crackable). CANNOT edit `iter_match.sh`/`similar_chunk.py`/
     `orchestrator_codex.sh` while running.
  6. Relaunch.
- **PERMUTER SEED FIX (harvest side validated):** permuter seeds died on undefined-symbol COMPILE errors — the
  `.nearmiss` body lacked the func's supporting externs/struct decls. FIX: `harvest_nearmiss.py` also saves the
  whole compilable best-C file as `.nearmiss/<func>.full.c`; `import_new` imports from it (skips seeds w/o it).
  Live for cycle-5 harvests. **NO worktree needed** — the supervisor IS already an async daemon; the "build-race"
  was a red herring (real cause = broken seeds). Crack count undercounts (prune deletes matched funcs' output-0).
- **PHASE 1 TYPING: DONE** — 170 funcs typed, 0 reverts, **0 offset-casts left** (~10.5k `->`, port-ready). via
  `type_orchestrator.sh` (offset-casts → local typed structs, iter_match-verified). PHASE 2 (consolidate local →
  shared semantic structs) DEFERRED: the "99-copy Actor" was a CLUSTERING OVER-MERGE (1-2-field fragments chained
  via common offsets); needs K≥3 subset-aware clustering + per-function judgment. No cheap win (include/ structs
  are ~160 `struct<N>` placeholders, only ~9 semantic).
- **FAILURE ANALYSIS (subagent, 1674 transcripts):** ~80-85% of failures are INTRINSIC + already correctly BAILed
  (coupled regalloc 16.6%, reloc/jtbl 11.7%, scheduling 6%, -g3 spill 5.2%, FP/64-bit ~7%). Cookbook comprehensive.
  Fixable upside ~5-10% (near/mid). Score magnitude tracks FUNC SIZE not wrongness (big-func address cascade).
- **UPSTREAM (subagent-verified):** CLEAN LINEAR DESCENDANT of mkst/origin (still at fork `3adf229`); NO re-split
  divergence — same config/naming, append-only. Upstreaming = normal PR. The "re-split" was toolchain modernization
  (spimdisasm 1.42 marker fix, `libglib2.0-0`, `pycparser<3` — fixes mkst's own broken build). **PR drafts ready in
  `~/conker-pr-draft/`** (PR_DESCRIPTION, TOOLCHAIN_FIXES, INDEX). User handles the PR/comms later.
- **STRATEGIC:** matching near its practical ceiling. Keep it ($0), but upstream PR / data-rodata sections / struct
  consolidation are higher leverage when the user shifts focus.
- **DASHBOARD:** `tools/dashboard.py` :8077. Restart: kill `tools/dashboard.py` procs + `setsid python3
  tools/dashboard.py 8077 >/tmp/dashboard.log 2>&1 </dev/null &`. Read-only. Background refresher serves pre-built
  snapshot (client count doesn't drive git/pgrep load). History graph = our de-stub timeline (not the README).
- **DETERMINISTIC HARVEST:** `iter_match.sh` prints `BEST: M`, snapshots best-C → `/tmp/bestc_<func>.c`; orchestrator
  harvests `.nearmiss` (keep-best). Read the TRACKED `/tmp/best_<func>.score`, NOT the codex log (agent echoes the
  prompt's literal "SCORE: 0"). `.cycle` counter (gitignored); `integrate.py` tags commits `[cycle N]`.

## CURRENT MODE — Codex engine (rationing Claude tokens)
The matching now runs on **Codex** (zero Claude tokens), via a shell mirror of the orchestrator:
- **Run:** `bash tools/orchestrator_codex.sh 12 400 8` (chunk maxi rounds) as a tracked background task →
  one completion notification. Uses `codex exec --full-auto` for matching; similar_chunk + integrate.py
  are the deterministic glue.
- **MAXI regime (size cap, RAISE as bands deplete):** raise when a band's match RATE decays OR round-1
  candidates drop below ~8 — opening a fresh band refreshes the high-similarity supply. History: ≤90 (runs 1-9)
  → 150 (runs 10-16, 91-150 band ~80% drained) → now `maxi 250`. Unattempted runway as of run 16:
  151-250≈487, 251-400≈280, 400+≈210. Next bumps: 400, then uncapped. Bigger funcs = lower count, more bytes each.
- **Cadence each gap (lean — minimal Claude tokens):** force-clean ROM gate → `apply_wins.py` →
  `permuter_daemon.py import_new` → relaunch `orchestrator_codex.sh` → `git push sholdee decomp/game-matches`.
- **Cookbook is TIERED:** `ido_cookbook.md` = 182-line CORE (always read); `ido_reference.md` = full
  270-bullet set (grep on-demand). Codex/Claude prompts read core + grep reference.
- **DISTILL (back on):** `orchestrator_codex.sh` ends each run with a codex distill step — skims the run's
  `/tmp/codexm_*.log`, APPENDS only genuinely-novel idioms to `ido_reference.md` under `## Post-cutover distilled`.
  Append-only guard (new file must start with old + ≤2KB growth, else revert) + reverts stray edits; self-commits.
- **MATCH CAPTURE (defeats codex over-run — was losing ~55% of found matches):** codex `--full-auto` keeps
  editing PAST `SCORE: 0` and destroys the match. `iter_match.sh` now snapshots `src/<file>.c` to
  `/tmp/match_<func>.c` the instant it prints SCORE 0; the orchestrator clears stale snapshots before MATCH and
  RESTORES each file from its snapshot after MATCH (before integrate). Deterministic — immune to whatever codex
  does after. (Prompt also hard-stops at 0; secondary.) NOTE: can't kill codex on capture to stop the over-run —
  its work runs in a DETACHED broker, so killing the `codex exec` client orphans the broker (it keeps editing →
  chaos). Over-run waste (codex tokens + wall-clock) is tolerated; the snapshot still captures the match. TODO
  parity: restore in orchestrator.js.
- **SEEDS (`similar_chunk.py` writes them; both orchestrators read them):** per picked func it writes the top-3
  similar matched functions' C → `/tmp/ref_`, `/tmp/ref2_`, `/tmp/ref3_<func>.c`, AND an m2c structural draft →
  `/tmp/m2c_<func>.c` (best-effort `--context`, falls back to raw). Prompts use refs for style + m2c for structure,
  with guardrails (never copy verbatim; m2c types are guesses). Both engines benefit since both call similar_chunk.
- **RETENTION (deterministic, via iter_match's tracked best):** `iter_match.sh` tracks the per-func running-best,
  prints `BEST: M` to the agent (so it sees regression), and snapshots the best-C to `/tmp/bestc_<func>.c`. The
  orchestrator harvests `.nearmiss` from that snapshot via `harvest_nearmiss.py` (keep-best) when `score ≤ 80 OR
  ≤ ½ instr count` — NOT from codex self-report (which drifted to over-run versions) or the log (prompt-polluted).
  `attempts.tsv` best-score also reads `/tmp/best_<func>.score`. `.nearmiss/*.json` tracked + backed up; permuter
  `import_new` keeps its ≤80 filter.
- **RE-ATTEMPT (ACTIVE — m2c validated +18% on run 18):** `rm /tmp/orchestrator_attempted_*.txt` re-opens every
  still-stubbed function (safe — only stubs re-open). `similar_chunk.py` then prioritizes **near-miss funcs first,
  lowest prior score first** (closest), and seeds each with its OWN best-C at `/tmp/prev_<func>.c` (#1) on top of
  m2c + top-3 refs. Prompts: step 0e starts the agent FROM /tmp/prev_<func>.c. Run at high maxi (400) so most
  near-misses are eligible. Closest near-misses (score 2-8) crack first; stop/raise when yield decays.
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
