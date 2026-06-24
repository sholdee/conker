#!/usr/bin/env python3
"""Cheap-win selector: find game functions whose typing-pass local offset-struct (field_0xNN) UNIQUELY
and exactly matches an existing SHARED struct in include/*.h. Those can be swapped to the real semantic
struct (dedup + readable field names) with zero conflict and byte-identical codegen.
  output: "<func> <file> <existing_struct>" per uniquely-mappable function.
"""
import glob, re, os, sys

REPO = os.environ.get("CONKER_REPO", os.path.expanduser("~/conker"))
STRUCT = re.compile(r'typedef\s+struct\s*\{(.*?)\}\s*(\w+)\s*;', re.S)
NEWF = re.compile(r'([A-Za-z_][\w ]*?\**)\s*field_0x([0-9A-Fa-f]+)\s*(?:\[[^\]]*\])?\s*;')
EXF = re.compile(r'^\s*([A-Za-z_][\w ]*?\**)\s*([A-Za-z_]\w*)\s*(?:\[([^\]]*)\])?\s*;', re.M)
SZ = {"s8": 1, "u8": 1, "char": 1, "s16": 2, "u16": 2, "s32": 4, "u32": 4, "f32": 4, "f64": 8, "s64": 8, "u64": 8}
def sz(t):
    t = t.strip(); return 4 if "*" in t else SZ.get(t, 0)
def parse_ex(body):
    off = 0; f = {}
    for typ, name, arr in EXF.findall(body):
        s = sz(typ)
        if s == 0:
            return None
        n = 1
        if arr:
            try:
                n = int(arr, 0)
            except Exception:
                return None
        if 'pad' not in name.lower():
            f[off] = (typ.strip(), name)
        off += s * n
    return f

existing = []
for h in glob.glob(os.path.join(REPO, "conker/include/*.h")):
    for body, name in STRUCT.findall(open(h).read()):
        if 'field_0x' in body:
            continue
        f = parse_ex(body)
        if f:
            existing.append((name, f))

seen = set()
for c in glob.glob(os.path.join(REPO, "conker/src/game_*.c")):
    txt = open(c).read(); file = os.path.basename(c)[:-2]
    for body, sname in STRUCT.findall(txt):
        nf = {int(o, 16): t.strip() for t, o in NEWF.findall(body)}
        if not nf:
            continue
        m = re.search(r'([0-9A-Fa-f]{8})', sname)            # struct name embeds its function's hex
        if not m:
            continue
        func = "func_" + m.group(1).upper()
        if func not in txt or (func, file) in seen:
            continue
        matches = {en for en, ef in existing if set(nf) <= set(ef) and all(nf[o] == ef[o][0] for o in nf)}
        if len(matches) == 1:
            seen.add((func, file))
            print(func, file, next(iter(matches)))
print(f"# {len(seen)} uniquely-mappable functions -> shared existing structs", file=sys.stderr)
