#!/usr/bin/env bash
# type_orchestrator.sh [chunk=12] [rounds=40] — Phase-1 typing sweep. Each round: SELECT the highest-cast
# not-yet-typed functions (one per file, distinct-file = concurrency-safe) -> type them via type_pass.sh
# (codex agents convert offset-casts to local typed structs, iter_match SCORE 0) -> integrate.py full-ROM
# gate + commit. Self-progresses: typed functions drop out of SELECT until the corpus is cast-free.
set -uo pipefail
REPO="$HOME/conker"; cd "$REPO"; . .venv/bin/activate
CHUNK="${1:-12}"; ROUNDS="${2:-40}"
for r in $(seq 1 "$ROUNDS"); do
  echo "=== TYPE round $r/$ROUNDS: SELECT ==="
  pairs=$(CONKER_REPO="$REPO" python3 tools/type_select.py "$CHUNK" | tr '\n' ' ')
  pairs=$(echo $pairs)
  [ -n "$pairs" ] || { echo "no cast-having functions left — typing sweep COMPLETE"; break; }
  echo "round $r: typing $(( $(echo "$pairs" | wc -w) / 2 )) functions"
  bash tools/type_pass.sh $pairs
done
echo "=== type_orchestrator: done ==="
