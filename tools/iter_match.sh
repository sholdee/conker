#!/usr/bin/env bash
# iter_match.sh <file> <func>
# Single-function build + object-level diff for the conker decomp matching loop.
# Builds ONLY src/<file>.c.o (no full ROM build) and object-diffs <func> against
# the reference in expected/. Prints "SCORE: N" (0 == byte-perfect match).
#
# Run from anywhere. Safe to run concurrently with OTHER files (never edit a
# .c file another agent owns, and never run a full `make`).
set -uo pipefail
cd "${CONKER_REPO:-$HOME/conker}/conker"
# shellcheck disable=SC1091
source ../.venv/bin/activate 2>/dev/null

file="$1"; func="$2"
obj="build/src/${file}.c.o"

# FORCE a fresh build every time: removing the object defeats make's mtime check,
# which can otherwise treat a same-second .c edit as "up to date" and diff a STALE
# matching .o → a false SCORE: 0 that integrate.py later rejects (wasted bisect).
rm -f "$obj"
berr=$(make "$obj" 2>&1)
if [ $? -ne 0 ] || [ ! -f "$obj" ]; then
  echo "BUILD-FAIL"
  echo "$berr" | grep -iE "error|undefined|syntax" | head -6
  echo "SCORE: 999999"
  exit 0
fi

diff=$(python3 ../tools/asm-differ/diff.py -o "$func" 2>&1)
score=$(echo "$diff" | grep -oE "CURRENT \(([0-9]+)\)" | grep -oE "[0-9]+" | head -1)
echo "$diff"
echo "SCORE: ${score:-unknown}"
