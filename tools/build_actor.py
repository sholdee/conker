#!/usr/bin/env python3
"""Phase-2 step 1: build a CANONICAL struct from the biggest local-struct cluster (the Actor). Merges
every copy's {offset: type} into one definition (canonical type = most common per offset), and reports
the conflict profile so we can judge how reconcilable it is before migrating functions onto it.
  usage: build_actor.py            # biggest cluster
"""
import glob, re, os, collections

REPO = os.environ.get("CONKER_REPO", os.path.expanduser("~/conker"))
STRUCT = re.compile(r'typedef\s+struct\s*\{(.*?)\}\s*(\w+)\s*;', re.S)
FIELD = re.compile(r'([A-Za-z_][\w ]*?\**)\s*field_0x([0-9A-Fa-f]+)\s*(?:\[[^\]]*\])?\s*;')
SZ = {"s8": 1, "u8": 1, "char": 1, "s16": 2, "u16": 2, "s32": 4, "u32": 4, "f32": 4}
def sz(t):
    return 4 if "*" in t else SZ.get(t.strip(), 4)

structs = []
for c in glob.glob(os.path.join(REPO, "conker/src/game_*.c")):
    for body, name in STRUCT.findall(open(c).read()):
        f = {int(o, 16): t.strip() for t, o in FIELD.findall(body)}
        if f:
            structs.append((os.path.basename(c)[:-2], name, f))

parent = list(range(len(structs)))
def find(x):
    while parent[x] != x:
        parent[x] = parent[parent[x]]; x = parent[x]
    return x
for i in range(len(structs)):
    for j in range(i + 1, len(structs)):
        sh = set(structs[i][2]) & set(structs[j][2])
        if sh and all(structs[i][2][o] == structs[j][2][o] for o in sh):
            parent[find(i)] = find(j)
cl = collections.defaultdict(list)
for i in range(len(structs)):
    cl[find(i)].append(i)
actor = max(cl.values(), key=len)

off_types = collections.defaultdict(collections.Counter)
for i in actor:
    for o, t in structs[i][2].items():
        off_types[o][t] += 1
conflicts = {o: ts for o, ts in off_types.items() if len(ts) > 1}
print(f"Actor cluster: {len(actor)} copies across {len(set(structs[i][0] for i in actor))} files")
print(f"distinct field offsets: {len(off_types)} | conflicting offsets: {len(conflicts)}")
# classify conflicts
sizec = sum(1 for ts in conflicts.values() if len({sz(t) for t in ts}) > 1)
kindc = len(conflicts) - sizec
print(f"  size-mismatch conflicts (e.g. u8 vs s32 = sub-byte access): {sizec}")
print(f"  same-size kind conflicts (e.g. s32 vs f32 = reinterpret):   {kindc}")
print("\nsample conflicts (offset: type->count):")
for o in sorted(conflicts)[:12]:
    print(f"  0x{o:X}: {dict(conflicts[o])}")
print(f"\ncanonical extent: 0x0 .. 0x{max(off_types):X} ({max(off_types)} bytes); {len(off_types)} typed fields")
