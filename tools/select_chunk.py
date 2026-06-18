#!/usr/bin/env python3
"""Pick the next chunk of decomp candidates for the self-driving orchestrator.

Selects up to N functions, ALL from DISTINCT .c files (so concurrent agents in a
chunk never collide), that are:
  - still a GLOBAL_ASM stub (not already matched),
  - not in the persistent attempted-log,
  - 6..MAXI instructions, no handwritten asm.
Appends the picks to the attempted-log so the next call won't repeat them, and
prints the chunk as a JSON array of {"func","file"}.

Usage: select_chunk.py [count=8] [maxi=40]
"""
import json, os, sys, re

ROOT = os.path.expanduser("~/conker/conker")
RANK = "/tmp/game_ranked2.txt"
LOG = "/tmp/orchestrator_attempted.txt"

def main():
    count = int(sys.argv[1]) if len(sys.argv) > 1 else 8
    maxi = int(sys.argv[2]) if len(sys.argv) > 2 else 40
    attempted = set()
    if os.path.exists(LOG):
        attempted = set(l.strip() for l in open(LOG) if l.strip())

    rows = []
    for line in open(RANK):
        n, s = line.split()
        n = int(n); file, func = s[:-2].split("/")
        if func in attempted or n < 6 or n > maxi:
            continue
        sfile = os.path.join(ROOT, "asm/nonmatchings", s)
        try:
            if "handwritten" in open(sfile).read():
                continue
        except OSError:
            continue
        # still a stub?
        cpath = os.path.join(ROOT, f"src/{file}.c")
        pragma = f'#pragma GLOBAL_ASM("asm/nonmatchings/{file}/{func}.s")'
        try:
            if pragma not in open(cpath).read():
                continue
        except OSError:
            continue
        rows.append((n, file, func))
    rows.sort()

    picked, seen = [], set()
    for n, file, func in rows:
        if file in seen:
            continue
        picked.append({"func": func, "file": file})
        seen.add(file)
        if len(picked) >= count:
            break

    # persist so the next chunk doesn't repeat these
    with open(LOG, "a") as f:
        for p in picked:
            f.write(p["func"] + "\n")

    print(json.dumps(picked))

if __name__ == "__main__":
    main()
