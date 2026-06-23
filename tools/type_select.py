#!/usr/bin/env python3
"""Select cast-having game functions to type, highest-cast first, ONE per file (distinct-file = the typing
agents are concurrency-safe, same as matching). Already-typed functions have 0 casts in current src and drop
out automatically, so the orchestrator self-progresses until the corpus is cast-free.
  usage: type_select.py [chunk=12]   -> prints "<func> <file>" lines
"""
import glob, re, os, sys

REPO = os.environ.get("CONKER_REPO", os.path.expanduser("~/conker"))
CHUNK = int(sys.argv[1]) if len(sys.argv) > 1 else 12
DEF = re.compile(r'^[A-Za-z_][A-Za-z0-9_ \*]*?\b(func_[0-9A-Fa-f]+)\s*\([^;{]*\)\s*\{', re.M)
CAST = re.compile(r'\*\([A-Za-z0-9_]+\s*\*\)\(\(?[A-Za-z_][A-Za-z0-9_]*[^)]*?\+\s*0x')

best = {}   # file -> (cast_count, func)   the highest-cast not-yet-typed func in each file
for c in glob.glob(os.path.join(REPO, "conker/src/game_*.c")):
    try:
        txt = open(c).read()
    except OSError:
        continue
    file = os.path.basename(c)[:-2]
    for m in DEF.finditer(txt):
        i, d = m.end() - 1, 0
        while i < len(txt):
            if txt[i] == '{':
                d += 1
            elif txt[i] == '}':
                d -= 1
                if d == 0:
                    break
            i += 1
        n = len(CAST.findall(txt[m.start():i + 1]))
        if n > 0 and (file not in best or n > best[file][0]):
            best[file] = (n, m.group(1))

for file, (n, func) in sorted(best.items(), key=lambda kv: -kv[1][0])[:CHUNK]:
    print(func, file)
