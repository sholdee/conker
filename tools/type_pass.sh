#!/usr/bin/env bash
# type_pass.sh — Phase-1 typing pass. Converts already-byte-matched functions from raw offset-cast
# pointer arithmetic into LOCAL typed struct access, keeping them byte-IDENTICAL (iter_match SCORE 0).
# Reuses the matching infra: per-function codex agent + iter_match (fast single-object verify) +
# integrate.py (full-ROM gate + commit). Concurrency-safe: one agent per distinct file.
#   usage: type_pass.sh <func1> <file1> <func2> <file2> ...
# Typing only re-expresses field access, so an object-level SCORE 0 is necessarily ROM-identical —
# no iter-0-but-ROM-fail risk. A failed typing is reverted to the committed matched version by the gate.
set -uo pipefail
REPO="$HOME/conker"; cd "$REPO"; . .venv/bin/activate

type_prompt() {  # $1=func  $2=file
  cat <<EOF
You are converting ONE already-byte-matched function in the Conker decompilation (IDO 5.3, -O2) from raw
offset-cast pointer arithmetic into TYPED struct member access, WITHOUT changing the compiled bytes.

YOUR FUNCTION: $1  (in $REPO/conker/src/$2.c) — already matched C, NOT a stub. Leave its logic identical.

GOAL: replace raw casts like  *(s32*)((u8*)arg0 + 0x18)  with typed access  arg0->field_0x18 , by defining a
LOCAL struct for each pointer that is accessed via offsets. Use OFFSET-BASED field names: field_0xNN.

THE LOOP:
0. Read the function. For each pointer (arg or local) accessed via  *(T*)((cast)base + 0xNN) , collect EVERY
   (offset, access-type) it is read/written at.
1. Define a LOCAL struct at the TOP of $2.c for each such pointer (or reuse an existing struct from
   $REPO/conker/include/structs.h if one already matches the offsets/types — check first). Place each field
   at its EXACT byte offset using explicit padding, e.g.:
     typedef struct { char pad_0[0x14]; s32 field_0x14; f32 field_0x18; char pad_1[0xC]; s16 field_0x28; } Foo;
   A field at offset O must have the SAME type+size as the cast there; pad every gap so each field lands on its
   exact offset. Verify the struct's implied size covers the largest offset accessed.
2. Change the pointer's declaration to the struct type ( Foo *arg0 ), and replace every
   *(T*)((cast)base + 0xNN)  with  base->field_0xNN .
3. Run:  CONKER_REPO=$REPO $REPO/tools/iter_match.sh $2 $1   — it rebuilds your object and diffs. SCORE 0 =
   byte-identical (SUCCESS). Non-zero = your layout is wrong (a field is at the wrong offset/size, or padding is
   off): read the diff, fix the offsets/padding, re-run. Up to ~10 iterations toward 0.

HARD RULES (a violation corrupts the shared build tree):
- The compiled output MUST stay byte-identical (SCORE 0). Typing that changes any instruction is WRONG — fix
  the struct layout until it is 0. Watch the "BEST:" line; do not drift away from 0.
- ONLY edit $REPO/conker/src/$2.c. Define structs LOCALLY in that file — do NOT edit include/*.h or any other
  src file (shared-header consolidation is a separate later pass).
- Change only HOW fields are accessed (cast -> member), never WHAT the code computes. IDO is C89: declare the
  struct typedef and all locals at the top of their block.

WHEN DONE:
- SCORE 0 with the offset-casts replaced by typed member access -> YOU ARE FINISHED. STOP. Run nothing further.
- Cannot reach SCORE 0 -> revert $2.c to its committed matched state (git checkout -- conker/src/$2.c) and stop.
  Leaving non-matching C breaks the build; reverting on failure is MANDATORY.
EOF
}

> /tmp/type_chunk.txt
while [ $# -ge 2 ]; do echo "$1 $2" >> /tmp/type_chunk.txt; shift 2; done
[ -s /tmp/type_chunk.txt ] || { echo "type_pass: no (func file) pairs given"; exit 1; }
echo "type_pass: typing $(wc -l < /tmp/type_chunk.txt) functions"

echo "=== TYPE (codex --full-auto, parallel, distinct files) ==="
rm -f /tmp/best_func_*.score /tmp/bestc_func_*.c /tmp/match_func_*.c
while read -r func file; do
  type_prompt "$func" "$file" > "/tmp/typep_${func}.txt"
  ( timeout 1800 codex exec --full-auto --cd "$REPO" "$(cat /tmp/typep_${func}.txt)" \
      > "/tmp/typel_${func}.log" 2>&1 ) &
done < /tmp/type_chunk.txt
wait

# restore each func from its SCORE-0 snapshot (defeats any codex over-run past 0), then gate.
while read -r func file; do
  [ -f "/tmp/match_${func}.c" ] && cp "/tmp/match_${func}.c" "$REPO/conker/src/${file}.c"
done < /tmp/type_chunk.txt

echo "=== GATE (integrate.py: force-clean full-ROM sha1 verify + commit the still-matching typed funcs) ==="
pairs=$(awk '{print $2" "$1}' /tmp/type_chunk.txt | tr '\n' ' ')
CONKER_TYPING=1 CONKER_REPO="$REPO" python3 tools/integrate.py $pairs
echo "=== type_pass done ==="
