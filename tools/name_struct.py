#!/usr/bin/env python3
"""NAME-ONLY typing pass (2026-06-26 pivot, track 2). Rename a struct_<hex> type's unkNN fields to
meaningful names inferred from usage, across EVERY file that uses the type, then verify the change is
byte-identical (a pure rename is codegen-identical) via the force-clean dual-SHA ROM gate.

The gate AUTO-ENFORCES name-only: any edit that changes field offsets/sizes/types/order (i.e. changes
codegen) alters the ROM and is REVERTED. So this can only ever land ROM-identical renames.

RUN IN THE GAP (orchestrator quiescent) — it builds + commits, so it races a live matching pipeline.

  usage: name_struct.py [struct_NAME]   (no arg = auto-pick the highest-unk-field struct not yet done)
"""
import glob, os, re, subprocess, sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import integrate as _ig                       # reuse rom_matches() (force-clean dual-SHA) + sh()

REPO = os.path.expanduser("~/conker")
INNER = os.path.join(REPO, "conker")
DONE = os.path.join(REPO, "tools", "typed_structs.txt")   # structs already attempted (done<TAB>result)

def sh(cmd):
    return subprocess.run(cmd, shell=True, cwd=REPO, capture_output=True, text=True)

def struct_defs():
    """{struct_<hex>: (deffile, unk_field_count, [files that reference it])} for typedefs with unk fields."""
    src = {c: open(c, errors="ignore").read() for c in glob.glob(f"{INNER}/src/**/*.c", recursive=True)}
    defs = {}
    for c, t in src.items():
        for m in re.finditer(r'typedef struct\s*\{(.*?)\}\s*(struct_[0-9A-Fa-f]+)\s*;', t, re.S):
            body, name = m.group(1), m.group(2)
            if re.search(r'unk[0-9A-Fa-f]+\s*;', body):
                defs.setdefault(name, [c, len(re.findall(r'unk[0-9A-Fa-f]+\s*;', body)), []])
    for name, rec in defs.items():
        rec[2] = [c for c, t in src.items() if name in t]
    return defs

def pick(defs):
    done = set()
    if os.path.exists(DONE):
        done = {l.split("\t")[0] for l in open(DONE) if l.strip()}
    cand = [(n, r) for n, r in defs.items() if n not in done]
    cand.sort(key=lambda x: -x[1][1])          # most unk fields first (most typing value)
    return cand[0] if cand else (None, None)

def prompt(name, deffile, files):
    deftxt = ""
    for m in re.finditer(r'typedef struct\s*\{.*?\}\s*%s\s*;' % re.escape(name),
                         open(deffile, errors="ignore").read(), re.S):
        deftxt = m.group(0); break
    flist = "\n".join("  - " + os.path.relpath(f, REPO) for f in files)
    return f"""TASK: give MEANINGFUL NAMES to the unkNN fields of the C struct `{name}` in the Conker decomp,
inferred from how each field is USED, then update every reference. This is a pure RENAME for readability.

The type `{name}` is defined as:
{deftxt}

It is referenced in these files (the typedef may be copied into several of them — keep ALL copies identical):
{flist}

RULES (a build gate will REVERT your work if you break ANY of these, so follow them exactly):
1. ONLY rename fields. DO NOT change any field's offset, byte size, type, or order. DO NOT change the
   struct's total size. DO NOT touch `pad`/`unk` fields you are not renaming. Keep every typedef copy
   of `{name}` IDENTICAL across all files.
2. Rename `unkNN` -> a clear name based on usage (e.g. a field used as a loop bound -> `count`; assigned a
   pointer -> a `*Ptr` name; compared to flags -> `flags`; an x/y/z triple -> `x`/`y`/`z`). If a field's
   purpose is genuinely unclear, LEAVE IT as `unkNN` rather than guess a misleading name.
3. Update EVERY use of each renamed field on a `{name}` value, in ALL the files above. A missed use is a
   compile error. Do NOT rename same-named fields (`unkNN`) belonging to OTHER struct types.
4. When done, run `make -C conker` from {REPO} and fix any compile error you introduced. The change MUST
   compile. Do not edit any `asm/` file or any `#pragma GLOBAL_ASM` line.

Make the edits directly. Be conservative: a few confident, correct renames beat many shaky ones."""

def main():
    target = sys.argv[1] if len(sys.argv) > 1 else None
    defs = struct_defs()
    if target:
        rec = defs.get(target)
        if not rec:
            print(f"name_struct: {target} not found among unk-field structs"); return
        name = target
    else:
        name, rec = pick(defs)
        if not name:
            print("name_struct: no remaining unk-field structs to name"); return
    deffile, nunk, files = rec
    print(f"NAMING {name}: {nunk} unk fields across {len(files)} file(s) (def in {os.path.basename(deffile)})")
    # clean tree precondition (don't commit unrelated WIP)
    if sh("git status --porcelain conker/src").stdout.strip():
        print("name_struct: src tree dirty — aborting (run in a clean gap)"); return
    open("/tmp/name_struct_prompt.txt", "w").write(prompt(name, deffile, files))
    print("  running codex agent...")
    r = subprocess.run(f'timeout 1800 codex exec --full-auto --cd "{REPO}" "$(cat /tmp/name_struct_prompt.txt)"',
                       shell=True, cwd=REPO, capture_output=True, text=True)
    if sh("git status --porcelain conker/src").stdout.strip() == "":
        print("  agent made no edits — skipping"); _record(name, "noop"); return
    print("  gating (force-clean dual-SHA ROM)...")
    if _ig.rom_matches():
        named = max(0, nunk - _renamed_count(name))     # original unk minus the unk left after renaming
        sh("git add conker/src")
        sh(f'git commit -q -m "type: name {named} fields of {name} (name-only, ROM-identical) [typing]"')
        print(f"  COMMITTED — {name}: {named} fields named, ROM verified byte-identical")
        _record(name, f"named:{named}")
    else:
        sh("git checkout conker/src")
        print(f"  REVERTED — {name} change was not ROM-identical (or broke build)")
        _record(name, "reverted")

def _renamed_count(name):
    d = struct_defs().get(name)
    if not d: return 0
    txt = open(d[0], errors="ignore").read()
    m = re.search(r'typedef struct\s*\{(.*?)\}\s*%s\s*;' % re.escape(name), txt, re.S)
    return len(re.findall(r'unk[0-9A-Fa-f]+\s*;', m.group(1))) if m else 0  # remaining unk (lower = more named)

def _record(name, result):
    open(DONE, "a").write(f"{name}\t{result}\n")

if __name__ == "__main__":
    main()
