# Match-rate improvement plans

Two plans to push past the current ~1–2 matches/cycle frontier, grounded in the existing
engine (see `orchestrator_codex.sh:match_prompt`, `iter_match.sh`, `similar_chunk.py`).
**Both are measured in BYTES matched/cycle, not func count** (per strategy pivot — ~40% of
remaining bytes sit in funcs bigger than either engine has ever matched).

Baseline the agent already gets per stub: m2c draft (`/tmp/m2c_$func.c`), 3 similar matched
funcs as worked examples (`/tmp/ref_$func.c`), its own prior best seed (`/tmp/prev_$func.c`),
a register-level asm-differ loop (`iter_match.sh`, ~12 iters), cookbook + reference idioms.

---

## PLAN A — Large-function match flow  (do FIRST: no new deps, targets the byte wall)

### STATUS: IMPLEMENTED 2026-06-27 (reviewed APPROVE-WITH-CHANGES; all MUST-FIXes applied; fan-out dropped)
Fully gated behind `CONKER_BIGLANE=1` — inert otherwise (off-path confirmed live on cycle 49 round 4).
**Activate (in a gap):**
```
CONKER_BIGLANE=1 CONKER_SEGMENTS=init,debugger bash tools/orchestrator_codex.sh 12 400 8
```
Knobs (env, defaults): `CONKER_BIGFUNC_MIN=200` (lane/no-shelve/carry-forward + region-anchored prompt),
`CONKER_BIGFUNC_HEAVY=250` (5400s timeout), `CONKER_BIGLANE_SLOTS=1` (big funcs/round),
`CONKER_BIGLANE_ROUNDS=2` (only first N rounds seed big funcs — bounds wall-clock), `CONKER_BIGLANE_MAXI`
(defaults to the run's maxi; raise to reach >400-insn funcs). Pool today: 456 funcs ≥200, 278 ≥250.
Changes: `similar_chunk.py` (big lane re-admitting via candidate_stubs, ignores attempted-log+shelf),
`difficult_functions.py` (size-aware no-shelve), `orchestrator_codex.sh` (size→prompt, heavy timeout,
region-anchored prompt block, always-harvest big for carry-forward, CONKER_ROUND for round-gating).
Measure in BYTES + median best-score trajectory from `attempts.tsv` (col 4 = size). Multi-strategy
fan-out (orig Element 4) REJECTED in review (one-actor-per-file invariant) — not implemented.



### Problem (grounded)
- >250-insn funcs = ~40% of remaining BYTES. LLM max-ever match = 252 insns; **permuter caps
  at 180, so it cannot rescue big funcs at all** — the LLM is the only path.
- Big funcs ARE selected (`candidate_stubs` filters only `n<6 or n>maxi`; run uses `maxi=400`),
  but `similar_chunk._harvest_key` pushes >260-insn seeds to the back of their score band, and
  after ONE plateau they're shelved to `difficult_functions.txt` (retried only ~every 8th
  re-probe). So they get rare attempts, always via the SAME generic one-agent / ~12-iter /
  whole-function flow that doesn't converge on them.
- `iter_match.sh` scores the WHOLE function (`asm-differ -o $func`); you cannot compile a
  fragment. So "partial match" must mean **region-anchored iteration**, never splitting the C.

### Why the generic flow fails at size
1. Budget: ~12 iterations + one context window can't converge 250+ insns where one early wrong
   instruction cascades the whole score (the prompt's own STALL RULE notes score ∝ size).
2. No region locking: the agent re-derives the whole body each iteration; matched regions regress.
3. m2c skeleton is more error-prone at size (mis-analyzed switches/loops) yet must be trusted wholesale.
4. Few matched big-func exemplars exist to seed `ref_$func.c`.

### Design — a dedicated big-func lane (threshold `BIGFUNC_MIN`, default ~150 insns)
1. **Guaranteed selection lane** (`similar_chunk.py`): emit 1–2 big close-seeds/cycle as a
   separate slice so they always get attempts; **do not auto-shelve big funcs after one plateau**
   (`difficult_functions.py`) — they need cumulative progress across cycles.
2. **Bigger budget** (`orchestrator_codex.sh` MATCH loop, per-func `is_big` flag): timeout
   2400→~5400s, target iters ~12→~30, plateau patience 3→~6 stalls.
3. **Region-anchored protocol** (size-conditional branch in `match_prompt`):
   a. Match the FRAME first (prologue/epilogue: frame size, saved regs, `$ra`) before the body.
   b. Walk the asm-differ diff TOP-DOWN: fix the first diverging instruction, re-run, confirm the
      region locks, advance. Keep a running "locked through instruction K" note.
   c. Treat the .s basic blocks (branch targets) as the unit; match block N before N+1.
   d. Recognize -O2 INLINED helpers (big funcs are often big from inlined memcpy/struct-copy/
      helpers): identify the pattern, write the inline-expanding C. Seed the cookbook with these.
4. **Multi-strategy fan-out** (optional, higher cost): spawn 2–3 codex attempts per big func from
   DIFFERENT starts (m2c-first / exemplar-first / prev-seed-first); the existing `/tmp/best_$func`
   tracking keeps the lowest; integrate gates. The MATCH loop already backgrounds attempts.
5. **Carry-forward**: `/tmp/prev_$func.c` already persists best-so-far via `.nearmiss/*.full.c`;
   ensure big funcs keep it across cycles so each cycle RESUMES closer — a multi-cycle grind, not
   a one-shot.

### Integration points
- `similar_chunk.py` — big-func lane in `main()`/`segment_stubs`; size-band split; skip shelving big.
- `orchestrator_codex.sh` — `is_big` → larger timeout/iters; optional multi-attempt fan-out.
- `match_prompt()` — size-conditional region-anchored protocol block.
- `difficult_functions.py` — exclude big funcs from the fast shelf (or a separate slow shelf).
- `tools/ido_cookbook.md` — big-func / inlined-helper idioms (DISTILL can target these).

### Measurement / success
- Track big-lane (n≥threshold) attempts vs matches/cycle; **plot median best-score across cycles
  for carried-forward big funcs** — converging (monotone down) is the leading indicator.
- Success: ≥1 >250-insn match landed within N cycles AND big-lane median best-score trending down.
- Headline metric = BYTES matched/cycle.

### Risks
- Compute cost (bigger budget + fan-out) — bound by big-lane size (1–2/cycle).
- Some big funcs are structurally unmatchable as stubbed C (jtbl-externalized, native 64-bit — a
  known BAIL class). Keep the cookbook BAIL checklist; don't grind the known-dead.
- Region locking is prompt discipline, not enforced; `/tmp/best_$func` snapshot already prevents
  LOSING the best, but regression mid-iteration is still possible.

---

## PLAN B — Ghidra type-oracle A/B  (do SECOND, gated: real infra cost, uncertain payoff)

### Hypothesis
m2c's per-function type guesses are a real weakness (the prompt itself says "its TYPES are
guesses — `?`, raw `temp_`/`var_` names"). A WHOLE-PROGRAM type/struct/global database from
Ghidra, fed in as high-confidence types for the symbols a target func references, should raise
match rate — correct field types/offsets drive correct load/store widths (`lw`/`lh`/`lbu`) and
addressing (`addiu` vs `lui+ori`), cutting diffs — especially for funcs touching globals/structs
not yet in `structs.h`/`variables.h`.

### Setup
1. Load into Ghidra: **`build/conker.us.elf` first** (it carries -g3 DWARF symbols for matched
   funcs — high signal), plus baserom via **N64LoaderWV** for full raw-ROM coverage. Run analysis.
2. Expose via **ghidra-mcp**. ROBUSTNESS: ghidra-mcp is interactively-authenticated MCP and may
   be ABSENT in headless/cron runs. So do NOT have the codex agent query MCP live. **PRECOMPUTE**
   instead: an orchestrator-side helper queries ghidra-mcp (or `analyzeHeadless` + an export
   post-script) and writes `/tmp/ghidra_types_$func.txt` — mirroring `_write_m2c_seed`. Keeps the
   agent flow deterministic and offline-safe.
3. Type-file content: for each global/struct symbol the target `.s` references (parse `%hi/%lo`,
   `jal` targets, `lui/addiu` relocs from the .s or m2c output), emit Ghidra's recovered
   type / struct layout / field offsets. Keep it TERSE — only what headers lack or where Ghidra
   disagrees (the agent already reads the headers).

### A/B design
- Held-out set: M≈20–30 stubs NOT on the difficult shelf, mid-size (30–150 insns, where types
  bite), disjoint from normal selection for the run.
- Two arms on the SAME funcs:
  - control = current `match_prompt`.
  - treatment = + step "0f: read `/tmp/ghidra_types_$func.txt` (high-confidence whole-program
    types; prefer over m2c guesses; still verify against the diff)".
- Compare: primary = match rate (score-0 / M); secondary = median final best-score,
  iters-to-match, build-fail (type-error) rate.
- Decision rule: adopt only if treatment shows meaningful uplift (≈ ≥ +15–20% relative) on the
  held-out set. Else shelve Ghidra for MATCHING and consider it only for the typing track.

### Integration points (only if adopted)
- `tools/ghidra_types.py` — precompute (modeled on `_write_m2c_seed`): symbol extraction + Ghidra
  query → `/tmp/ghidra_types_$func.txt`.
- `similar_chunk.py` SELECT — call it per chosen func, **gated behind `CONKER_GHIDRA=1`** (the A/B flag).
- `match_prompt()` — add step 0f, gated on file existence (control = file absent → step skipped).
- `tools/setup_ghidra.sh` — one-time: install Ghidra + N64LoaderWV + ghidra-mcp; load ELF/ROM;
  analysis project under `~/conker/.ghidra` (re-run analysis as more funcs get typed).

### Risks / caveats
- Setup + full-binary analysis is non-trivial and slow (one-time, periodic refresh).
- MCP headless-auth fragility → the precompute pattern mitigates it.
- Ghidra types on optimized code may be NOISY; a wrong type file HURTS (agent chases bad types).
  The A/B exists precisely to measure this BEFORE wiring into the main loop.
- Likely bigger payoff is the **typing flywheel** (Ghidra types → richer `structs.h` → better
  matcher input) than direct matching. Measure both; the held-out A/B decides matching specifically.

---

## Sequencing
1. **Plan A first.** Pure config/prompt/selection changes to the existing engine, zero new deps,
   directly targets the 40%-of-bytes wall, A/B-able within the running loop (big-lane on/off).
2. **Plan B second, gated.** Real infra investment; the held-out A/B must show uplift before it
   touches the main loop. Its probable home is the typing track, not the matcher.
