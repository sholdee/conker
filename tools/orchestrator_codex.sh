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
0b. If $REPO contains /tmp/ref_$1.c, READ it: it is a SIMILAR already-matched function's byte-matching C. Read its asm too and use it as a worked template.
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
- Cannot reach 0 -> FIRST, if your best SCORE was <= 80, write the best-scoring C to $REPO/.nearmiss/$1.json as JSON with keys func,file,score,c (use python3 -c with json.dump). THEN revert: make $REPO/conker/src/$2.c contain exactly the original stub line  #pragma GLOBAL_ASM("asm/nonmatchings/$2/$1.s")  again. Leaving non-matching C breaks the build; reverting on failure is MANDATORY.
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
done
echo "=== codex orchestrator: done ($ROUNDS rounds) ==="
