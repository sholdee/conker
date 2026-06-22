#!/usr/bin/env bash
# Codex-driven orchestrator — ZERO Claude tokens. Shell mirror of orchestrator.js:
# similar_chunk.py selects, `codex exec --full-auto` does each match, integrate.py gates.
# Codex's tokens (not Claude's) pay for the matching reasoning.
#   usage: orchestrator_codex.sh [chunk=8] [maxi=90] [rounds=8]
set -uo pipefail
REPO="$HOME/conker"
CHUNK="${1:-8}"; MAXI="${2:-90}"; ROUNDS="${3:-8}"
cd "$REPO"; . .venv/bin/activate

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

HARD RULES (a violation corrupts the shared build tree):
- ONLY edit $REPO/conker/src/$2.c. NEVER touch other src/ files or shared headers. Add any missing extern/prototype as a LOCAL declaration at the TOP of your file.
- IDO is C89: declare all locals at the top of their block.
- NEVER run make / make -C conker / any full build. ONLY iter_match.sh.

WHEN DONE:
- SCORE: 0 -> STOP and LEAVE the matching C in the file.
- Cannot reach 0 -> FIRST, if your best SCORE was <= 80 OR <= half the instruction count of the target .s (a structurally-close attempt worth keeping for later), write the best-scoring C to $REPO/.nearmiss/$1.json as JSON with keys func,file,score,c (use python3 -c with json.dump). THEN revert: make $REPO/conker/src/$2.c contain exactly the original stub line  #pragma GLOBAL_ASM("asm/nonmatchings/$2/$1.s")  again. Leaving non-matching C breaks the build; reverting on failure is MANDATORY.
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
  echo "=== round $r: SELECT ==="
  CONKER_REPO="$REPO" python3 tools/similar_chunk.py "$CHUNK" "$MAXI" \
    | python3 -c "import json,sys
for c in json.load(sys.stdin): print(c['func'], c['file'])" > /tmp/codex_chunk.txt
  [ -s /tmp/codex_chunk.txt ] || { echo "round $r: candidate pool empty -- stopping"; break; }
  echo "round $r: $(wc -l < /tmp/codex_chunk.txt) candidates"

  echo "=== round $r: MATCH (codex exec --full-auto, parallel, distinct files) ==="
  while read -r func file; do
    match_prompt "$func" "$file" > "/tmp/codexp_${func}.txt"
    ( timeout 2400 codex exec --full-auto --cd "$REPO" "$(cat /tmp/codexp_${func}.txt)" \
        > "/tmp/codexm_${func}.log" 2>&1 ) &
  done < /tmp/codex_chunk.txt
  wait

  echo "=== round $r: INTEGRATE (deterministic gate) ==="
  pairs=$(awk '{print $2" "$1}' /tmp/codex_chunk.txt | tr '\n' ' ')
  CONKER_REPO="$REPO" python3 tools/integrate.py $pairs

  # durable provenance: record best score + size for EVERY attempt this round
  while read -r func file; do
    best=$(grep -oE 'SCORE: [0-9]+' "/tmp/codexm_${func}.log" 2>/dev/null | grep -oE '[0-9]+' | sort -n | head -1)
    size=$(grep -cE '^\s+/\*' "$REPO/conker/asm/nonmatchings/${file}/${func}.s" 2>/dev/null)
    printf '%s\t%s\t%s\t%s\n' "$func" "$file" "${best:-NA}" "${size:-NA}" >> "$REPO/tools/attempts.tsv"
  done < /tmp/codex_chunk.txt
done

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
