#!/usr/bin/env python3
"""Scope Phase-2 consolidation. Scans the LOCAL typedef structs the typing sweep produces in game src,
parses each one's {offset: type} layout (from its field_0xNN names), and clusters structs that are
offset-COMPATIBLE (share >=1 offset, no type conflict at any shared offset). Reports how many DISTINCT
structs we likely have (the consolidated target) vs total local defs (the duplication), the biggest
shared structs (top consolidation value), and offset CONFLICTS (different type at the same offset across
two structs = either genuinely different structs or a typing inconsistency to review).

Clustering is a rough scoping estimate: union-find over pairwise compatibility may chain via a common
low offset (slight over-merge) and separates structs accessed at non-overlapping offsets (slight
under-merge). True distinct count is between the cluster count and the raw def count.
  usage: struct_cluster.py
"""
import glob, os, re, collections

REPO = os.environ.get("CONKER_REPO", os.path.expanduser("~/conker"))
STRUCT = re.compile(r'typedef\s+struct\s*\{(.*?)\}\s*(\w+)\s*;', re.S)
FIELD = re.compile(r'([A-Za-z_][\w ]*?\**)\s*field_0x([0-9A-Fa-f]+)\s*(?:\[[^\]]*\])?\s*;')

structs = []   # (file, name, {offset: type})
nofields = 0
for c in glob.glob(os.path.join(REPO, "conker/src/game_*.c")):
    try:
        txt = open(c).read()
    except OSError:
        continue
    file = os.path.basename(c)[:-2]
    for body, name in STRUCT.findall(txt):
        fields = {int(off, 16): typ.strip() for typ, off in FIELD.findall(body)}
        if fields:
            structs.append((file, name, fields))
        else:
            nofields += 1

n = len(structs)
print(f"local typedef structs: {n}  (across {len(set(s[0] for s in structs))} files; {nofields} parsed w/o field_0x names)")
if not n:
    raise SystemExit

# pairwise compatibility + union-find
parent = list(range(n))
def find(x):
    while parent[x] != x:
        parent[x] = parent[parent[x]]; x = parent[x]
    return x
conflicts = 0
for i in range(n):
    fi = structs[i][2]
    for j in range(i + 1, n):
        fj = structs[j][2]
        shared = set(fi) & set(fj)
        if not shared:
            continue
        if all(fi[o] == fj[o] for o in shared):
            parent[find(i)] = find(j)
        else:
            conflicts += 1

clusters = collections.defaultdict(list)
for i in range(n):
    clusters[find(i)].append(i)
k = len(clusters)
print(f"distinct structs (compatible clusters): ~{k}")
print(f"=> consolidation: {n} local defs -> ~{k} shared structs  ({round((1-k/n)*100)}% are duplicates)")
print(f"   pairwise type conflicts at shared offsets: {conflicts}")
print("\nbiggest shared structs (top consolidation targets):")
for cl in sorted(clusters.values(), key=len, reverse=True)[:10]:
    offs = set()
    for i in cl:
        offs |= set(structs[i][2])
    ex = sorted(set(structs[i][1] for i in cl))[:3]
    print(f"  {len(cl):3} copies | {len(offs):2} distinct fields | e.g. {ex}")
