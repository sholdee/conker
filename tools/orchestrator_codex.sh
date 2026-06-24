#!/usr/bin/env bash
# Codex-driven orchestrator — ZERO Claude tokens. Shell mirror of orchestrator.js:
# similar_chunk.py selects, `codex exec --full-auto` does each match, integrate.py gates.
# Codex's tokens (not Claude's) pay for the matching reasoning.
#   usage: orchestrator_codex.sh [chunk=8] [maxi=90] [rounds=8]
set -uo pipefail
REPO="$HOME/conker"
CHUNK="${1:-8}"; MAXI="${2:-90}"; ROUNDS="${3:-8}"
cd "$REPO"; . .venv/bin/activate

# cycle counter (one per run) + status file the dashboard reads
CYCLE=$(( $(cat "$REPO/.cycle" 2>/dev/null || echo 0) + 1 )); echo "$CYCLE" > "$REPO/.cycle"
status() { printf '{"cycle":%s,"round":%s,"rounds":%s}\n' "$CYCLE" "$1" "$ROUNDS" > /tmp/cycle_status.json; }
status 0

# EFFORT TRIAGE: derive the proven-plateau shelf from attempts.tsv (similar_chunk SELECT skips it),
# so agents stop re-grinding far functions that never improve across attempts. Re-probe the whole
# shelf every 5th cycle (thaw — a typing/struct/ref change since last attempt may have unstuck it).
CONKER_REPO="$REPO" python3 tools/difficult_functions.py || true
if [ $(( CYCLE % 5 )) -eq 0 ]; then
  export CONKER_REPROBE=1; echo "cycle $CYCLE: RE-PROBE (difficult-shelf ignored this cycle)"
else
  unset CONKER_REPROBE || true
fi

match_prompt() {  # $1=func  $2=file  (heredoc expands the paths; no $ / backticks remain)
  cat <<EOF
You are matching ONE function in the mkst/conker N64 decompilation (IDO 5.3, -O2 -g3) to byte-identical assembly, using a real compile+diff loop.

YOUR FUNCTION: $1  (in $REPO/conker/src/$2.c)
Target asm: $REPO/conker/asm/nonmatchings/$2/$1.s

THE LOOP:
0. FIRST read $REPO/tools/ido_cookbook.md (core IDO 5.3 -O2 idioms; obey its When-to-BAIL checklist). For a stubborn diff or specific instruction pattern, grep $REPO/tools/ido_reference.md if it exists.
0b. WORKED EXAMPLES: read /tmp/ref_$1.c (and /tmp/ref2_$1.c, /tmp/ref3_$1.c if present) -- the byte-matching C of the 3 most similar already-matched functions. Diff each one's asm against YOUR target .s to see what carries over; reuse their structure, casts, loop/branch shapes, and idioms as templates, ADAPTING offsets/constants/symbols to your function. Use them for style -- do NOT force your function into their exact shape, and do NOT copy verbatim.
0d. m2c DRAFT: if /tmp/m2c_$1.c exists, read it -- a STRUCTURAL skeleton m2c decompiled from your target asm. Its control flow and call structure are usually right, but its TYPES are guesses (?, raw temp_/var_ names) and it can mis-analyze complex switches/loops. Treat it as a starting skeleton: keep the structure, re-derive types from the asm/headers, rewrite into idiomatic IDO C (use the refs above for style). NEVER submit m2c output verbatim -- verify every construct against the diff.
0e. PRIOR ATTEMPT (STRONGEST seed when present): if /tmp/prev_$1.c exists, it is YOUR OWN previous best attempt at THIS function (its asm-differ score is in the header comment -- already structurally close). START FROM IT: paste it in, run iter_match to see the remaining diff, and fix only the few differences left. Do NOT restart from scratch -- you were close, finish the job.
0c. If your function builds DISPLAY LISTS (Gfx*, gSP/gDP macros, or raw ->w0/->w1 word stores), read $REPO/.claude/skills/decompile-microcode/f3dex2-reference.md and hand-write the matching macros.
1. Read the target .s and src/$2.c (neighbor style/types); read include/structs.h, functions.h, variables.h for types.
2. Replace the line  #pragma GLOBAL_ASM("asm/nonmatchings/$2/$1.s")  in $REPO/conker/src/$2.c with your candidate C.
3. Run:  CONKER_REPO=$REPO $REPO/tools/iter_match.sh $2 $1   -- it builds ONLY your object and prints a diff then "SCORE: N" (0 = byte-perfect).
4. Read the diff (TARGET vs CURRENT; r = register-only; > = extra instr; missing line = absent instr), refine, re-run. Up to ~12 iterations toward 0.
4b. STALL RULE (do not waste iterations): score MAGNITUDE tracks function SIZE, not wrongness — one early wrong instr cascades into a huge score. So ALWAYS diagnose the FIRST diverging instruction and fix THAT; never chase the magnitude. BUT if BEST has not improved for ~3 consecutive iterations AFTER you've diagnosed that first mismatch and applied its indicated fix, it is a plateau: STOP, REVERT to the stub (per WHEN DONE), and finish. Grinding a stalled diff for more iterations almost never reaches 0 — your best is already captured.

HARD RULES (a violation corrupts the shared build tree):
- ONLY edit $REPO/conker/src/$2.c. NEVER touch other src/ files or shared headers. Add any missing extern/prototype as a LOCAL declaration at the TOP of your file.
- IDO is C89: declare all locals at the top of their block.
- NEVER run make / make -C conker / any full build. ONLY iter_match.sh.

WHEN DONE:
- SCORE: 0 -> YOU ARE FINISHED. STOP IMMEDIATELY: run NO further commands, make NO further edits, do NOT "verify" or "clean up". The instant iter_match prints SCORE: 0 the match is already captured for you; ANY further edit risks moving away from it and losing the match. Just stop.
- Cannot reach 0 -> revert: make $REPO/conker/src/$2.c contain exactly the original stub line  #pragma GLOBAL_ASM("asm/nonmatchings/$2/$1.s")  again. Leaving non-matching C breaks the build; reverting on failure is MANDATORY. (Your BEST attempt is captured automatically by iter_match -- you do NOT need to save it anywhere. Watch the "BEST:" line: once you hit it, do not edit away from it.)
EOF
}

distill_prompt() {  # reads this run's match logs; appends only genuinely-novel idioms to the reference
  cat <<EOF
You curate $REPO/tools/ido_reference.md, a grep-on-demand set of transferable IDO 5.3 -O2 matching idioms. It is MATURE — your DEFAULT is to make NO edit.

This run's match agents left reasoning logs at /tmp/codexm_*.log (each is one function's compile+diff loop). Skim them for a matching TECHNIQUE that is genuinely NOVEL and TRANSFERABLE — a codegen idiom, a register-shaping trick, a diff-reading insight — NOT already covered, even loosely, by an existing bullet. READ $REPO/tools/ido_reference.md FIRST. Ignore function-specific facts (addresses, constants, per-function offsets). When in doubt, add NOTHING.

If (and ONLY if) you found something genuinely new:
- APPEND to the END of $REPO/tools/ido_reference.md. If there is no "## Post-cutover distilled" heading at the end, add that heading line first, then your bullet(s) beneath it.
- One or two TIGHT lines per idiom; at most a few bullets total. NEVER modify, reorder, or delete any existing line — APPEND ONLY.
- Edit ONLY ido_reference.md. Touch no other file; run no build.
EOF
}

for r in $(seq 1 "$ROUNDS"); do
  status "$r"
  echo "=== round $r: SELECT ==="
  CONKER_REPO="$REPO" python3 tools/similar_chunk.py "$CHUNK" "$MAXI" \
    | python3 -c "import json,sys
for c in json.load(sys.stdin): print(c['func'], c['file'])" > /tmp/codex_chunk.txt
  [ -s /tmp/codex_chunk.txt ] || { echo "round $r: candidate pool empty -- stopping"; break; }
  echo "round $r: $(wc -l < /tmp/codex_chunk.txt) candidates"

  echo "=== round $r: MATCH (codex exec --full-auto, parallel, distinct files) ==="
  rm -f /tmp/match_func_*.c /tmp/best_func_*.score /tmp/bestc_func_*.c   # clear per-round best-tracking
  while read -r func file; do
    match_prompt "$func" "$file" > "/tmp/codexp_${func}.txt"
    ( timeout 2400 codex exec --full-auto --cd "$REPO" "$(cat /tmp/codexp_${func}.txt)" \
        > "/tmp/codexm_${func}.log" 2>&1 ) &
  done < /tmp/codex_chunk.txt
  wait   # NOTE: can't safely kill codex mid-work — its work runs in a DETACHED broker, so killing
         # the `codex exec` client orphans the broker. Over-run waste is tolerated; snapshot/restore
         # below still captures the match regardless of codex's post-0 edits.

  # CAPTURE confirmed matches: restore each func's source from its score-0 snapshot, defeating
  # codex over-running past SCORE 0 and destroying the match (~55% of found matches were lost this way).
  while read -r func file; do
    [ -f "/tmp/match_${func}.c" ] && cp "/tmp/match_${func}.c" "$REPO/conker/src/${file}.c"
  done < /tmp/codex_chunk.txt

  echo "=== round $r: INTEGRATE (deterministic gate) ==="
  pairs=$(awk '{print $2" "$1}' /tmp/codex_chunk.txt | tr '\n' ' ')
  CONKER_REPO="$REPO" python3 tools/integrate.py $pairs

  # provenance + deterministic near-miss harvest, from iter_match's TRACKED best (not the codex log,
  # which is polluted by the prompt's "SCORE: 0" text; not codex self-report, which drifts on over-run).
  while read -r func file; do
    best=$(cat "/tmp/best_${func}.score" 2>/dev/null || echo NA)
    size=$(grep -cE '^\s+/\*' "$REPO/conker/asm/nonmatchings/${file}/${func}.s" 2>/dev/null)
    printf '%s\t%s\t%s\t%s\n' "$func" "$file" "${best:-NA}" "${size:-NA}" >> "$REPO/tools/attempts.tsv"
    # harvest .nearmiss from the best-C IF still a stub (uncommitted), structurally close, keep-best
    if [ "${best:-NA}" != NA ] && [ -f "/tmp/bestc_${func}.c" ] \
       && grep -q "GLOBAL_ASM(\"asm/nonmatchings/${file}/${func}\.s\")" "$REPO/conker/src/${file}.c" 2>/dev/null; then
      half=$(( ${size:-0} / 2 ))
      if [ "$best" -le 80 ] 2>/dev/null || { [ "$half" -gt 0 ] && [ "$best" -le "$half" ] 2>/dev/null; }; then
        CONKER_REPO="$REPO" python3 tools/harvest_nearmiss.py "$func" "$file" "$best" "/tmp/bestc_${func}.c" 2>/dev/null
      fi
    fi
  done < /tmp/codex_chunk.txt
done

# TYPE SWEEP: convert this run's freshly-matched funcs from raw offset-casts to local typed structs
# (byte-IDENTICAL, iter_match SCORE-0 verified, integrate-gated + COMMITTED by type_pass.sh). Self-skips
# when no casts remain. Runs AFTER matching so newly-matched funcs get typed before distill's checkout.
echo "=== TYPE SWEEP (offset-casts -> local typed structs; iter_match-verified, integrate-committed) ==="
tsweep=0
while pairs=$(CONKER_REPO="$REPO" python3 tools/type_select.py "$CHUNK" 2>/dev/null); [ -n "$pairs" ]; do
  bash tools/type_pass.sh $pairs || break
  tsweep=$((tsweep+1)); [ "$tsweep" -ge 20 ] && { echo "TYPE SWEEP: hit 20-batch cap, stopping"; break; }
done
echo "TYPE SWEEP: done ($tsweep batches)"

echo "=== DISTILL (codex, append-only to ido_reference.md) ==="
cp tools/ido_reference.md /tmp/ref_before.md
distill_prompt > /tmp/codex_distill_prompt.txt
timeout 900 codex exec --full-auto --cd "$REPO" "$(cat /tmp/codex_distill_prompt.txt)" > /tmp/codex_distill.log 2>&1
git checkout -- conker/src/ tools/ido_cookbook.md 2>/dev/null   # undo any stray distill edits outside the reference
python3 - <<'PY'
before = open('/tmp/ref_before.md').read(); after = open('tools/ido_reference.md').read()
if not after.startswith(before) or len(after) > len(before) + 2000:
    open('tools/ido_reference.md', 'w').write(before); print("DISTILL: guard tripped (rewrite/bloat) — reverted reference")
elif len(after) > len(before):
    print(f"DISTILL: appended {len(after)-len(before)} chars of new idioms")
else:
    print("DISTILL: no new idiom this run")
PY
if ! git diff --quiet tools/ido_reference.md; then
  git add tools/ido_reference.md && git commit -q -m "cookbook: distill novel idioms into reference (codex, append-only)"
  echo "DISTILL: committed reference update"
fi

echo "=== codex orchestrator: done ($ROUNDS rounds) ==="
