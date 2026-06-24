#!/usr/bin/env python3
"""Derive the SHELF list of proven-plateau functions from the attempts.tsv ledger, so SELECT
stops re-grinding them every cycle. Writes tools/difficult_functions.txt (one func per line,
consumed by similar_chunk.py) + a tools/difficult_functions.tsv sidecar with the reason.

A function is shelved ONLY on ATTEMPTS-WITHOUT-PROGRESS, never on raw score height — a far
score is often one early residue cascading (see cookbook), so a single far attempt proves
nothing. Criteria (all required):
  - >= MIN_ATTEMPTS scored attempts (so we have plateau evidence), AND
  - best score > NEAR (a near-miss is permuter territory — keep it selectable), AND
  - FLAT across attempts (spread/max < FLAT_FRAC, i.e. retries didn't get meaningfully closer).
PLUS a separate bucket: >= MIN_ATTEMPTS rows that ALL failed to even produce a score (NA) —
the candidate never compiles; shelve it too.

NOT permanent: the orchestrator re-probes the whole shelf every Nth cycle (ignores this list),
so anything thawed by a typing/struct/ref change since its last attempt gets a fresh shot.

  usage: difficult_functions.py [min_attempts=2] [near=80] [flat_frac=0.10]
"""
import os, sys, collections

REPO = os.environ.get("CONKER_REPO", os.path.expanduser("~/conker"))
TSV = os.path.join(REPO, "tools", "attempts.tsv")
OUT = os.path.join(REPO, "tools", "difficult_functions.txt")
SIDE = os.path.join(REPO, "tools", "difficult_functions.tsv")

MIN_ATTEMPTS = int(sys.argv[1]) if len(sys.argv) > 1 else 2
NEAR = int(sys.argv[2]) if len(sys.argv) > 2 else 80
FLAT_FRAC = float(sys.argv[3]) if len(sys.argv) > 3 else 0.10

scores = collections.defaultdict(list)   # func -> [numeric score, ...] in attempt order
na = collections.Counter()               # func -> count of NA (uncompilable) attempts
file_of = {}

if not os.path.exists(TSV):
    open(OUT, "w").close(); sys.exit(0)

for line in open(TSV):
    p = line.rstrip("\n").split("\t")
    if len(p) < 3 or p[0] == "func":
        continue
    func, file, score = p[0], p[1], p[2]
    file_of[func] = file
    try:
        scores[func].append(int(score))
    except ValueError:
        na[func] += 1

shelved = []   # (func, reason)
for func in set(list(scores) + list(na)):
    sc = scores.get(func, [])
    best = min(sc) if sc else None
    if best == 0:
        continue                         # already matched — never shelve
    if len(sc) >= MIN_ATTEMPTS and best is not None and best > NEAR:
        spread = max(sc) - min(sc)
        if max(sc) == 0 or spread / max(sc) < FLAT_FRAC:   # flat across retries -> plateau
            shelved.append((func, f"plateau best={best} attempts={len(sc)} spread={spread}"))
            continue
    if not sc and na[func] >= MIN_ATTEMPTS:                # never even compiled a candidate
        shelved.append((func, f"uncompilable na_attempts={na[func]}"))

shelved.sort()
with open(OUT, "w") as f:
    for func, _ in shelved:
        f.write(func + "\n")
with open(SIDE, "w") as f:
    f.write("func\tfile\treason\n")
    for func, reason in shelved:
        f.write(f"{func}\t{file_of.get(func,'?')}\t{reason}\n")
print(f"difficult_functions: shelved {len(shelved)} proven-plateau funcs -> {OUT}", file=sys.stderr)
