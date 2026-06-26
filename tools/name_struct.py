#!/usr/bin/env python3
"""NAME-ONLY typing pass (2026-06-26 pivot, track 2). Pick a matched source FILE with the most untyped
`->unkNN` field accesses, have an agent give those fields meaningful names inferred from usage (renaming
the local struct typedef + every use), then verify the change is byte-identical via the force-clean
dual-SHA ROM gate. A pure rename is codegen-identical; the gate AUTO-ENFORCES name-only — any edit that
changes field offsets/sizes/types/order (i.e. changes codegen) alters the ROM and is REVERTED.

RUN IN THE GAP (orchestrator quiescent) — it builds + commits, so it races a live matching pipeline.

  usage: name_struct.py [src/FILE.c]   (no arg = auto-pick the file with the most ->unkNN, fully-matched first)
"""
import glob, os, re, subprocess, sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import integrate as _ig                       # reuse rom_matches() (force-clean dual-SHA)

REPO = os.path.expanduser("~/conker")
INNER = os.path.join(REPO, "conker")
DONE = os.path.join(REPO, "tools", "typed_files.txt")     # files already attempted (path<TAB>result)

def sh(cmd):
    return subprocess.run(cmd, shell=True, cwd=REPO, capture_output=True, text=True)

def _unk(txt):
    return len(re.findall(r'->unk[0-9A-Fa-f]', txt))

def pick():
    done = set()
    if os.path.exists(DONE):
        done = {l.split("\t")[0] for l in open(DONE) if l.strip()}
    cand = []
    for c in glob.glob(f"{INNER}/src/**/*.c", recursive=True):
        rel = os.path.relpath(c, INNER)
        if rel in done or rel.startswith("src/libultra/"):
            continue                                # libultra has canonical upstream types — out of scope
        txt = open(c, errors="ignore").read()
        n = _unk(txt)
        if n:
            # fully-matched files (no stub) are safest -> sort them first, then by unk count
            cand.append((0 if "GLOBAL_ASM" not in txt else 1, -n, rel, c))
    cand.sort()
    return (cand[0][3], -cand[0][1], cand[0][0] == 0) if cand else (None, 0, False)

def prompt(cfile, nunk, fully):
    rel = os.path.relpath(cfile, REPO)
    stub_note = ("" if fully else
                 "\nNOTE: this file still has some #pragma GLOBAL_ASM stubs (unmatched funcs). IGNORE them — "
                 "do NOT edit any GLOBAL_ASM line or asm/ file. Only touch matched C and the struct typedefs.")
    return f"""TASK: give MEANINGFUL NAMES to the `unkNN` struct fields used in {rel} (about {nunk} `->unkNN`
accesses), inferred from how each field is USED, then update every reference. This is a pure RENAME for
readability — it must not change the compiled output at all.

A build gate will REVERT all your work if you break ANY of these rules, so follow them exactly:
1. ONLY rename fields. DO NOT change any field's offset, byte size, type, order, or the struct's total
   size. Keep every `/* 0xNN */` offset comment correct. Do NOT touch `pad` fields.
2. ONLY rename fields of structs that are DEFINED IN THIS FILE and (as far as you can tell) used only
   here — i.e. LOCAL `struct_<hex>`-style typedefs. If a struct/type is shared (defined in a header under
   conker/include, or referenced in other files), LEAVE IT ALONE — renaming it here breaks other files.
3. Rename `unkNN` -> a clear name from usage (loop bound -> `count`; holds a pointer -> a `*Ptr` name; an
   x/y/z triple -> `x`/`y`/`z`; bitflags -> `flags`). If a field's purpose is genuinely unclear, LEAVE it
   as `unkNN` — do not invent a misleading name. A few confident correct renames beat many shaky guesses.
4. Update EVERY use of each renamed field in this file. A missed use is a compile error.
5. When done, run `make -C conker` from {REPO} and fix any compile error you introduced.{stub_note}

Edit {rel} directly."""

def _record(rel, result):
    open(DONE, "a").write(f"{rel}\t{result}\n")

def main():
    arg = sys.argv[1] if len(sys.argv) > 1 else None
    if arg:
        cfile = os.path.join(INNER, arg) if not os.path.isabs(arg) else arg
        txt = open(cfile, errors="ignore").read(); nunk = _unk(txt); fully = "GLOBAL_ASM" not in txt
    else:
        cfile, nunk, fully = pick()
        if not cfile:
            print("name_struct: no files with ->unkNN left to type"); return
    rel = os.path.relpath(cfile, INNER)
    print(f"TYPING {rel}: ~{nunk} ->unkNN accesses ({'fully-matched' if fully else 'has stubs'})")
    if sh("git status --porcelain conker/src").stdout.strip():
        print("name_struct: src tree dirty — aborting (run in a clean gap)"); return
    before = _unk(open(cfile, errors="ignore").read())
    open("/tmp/name_struct_prompt.txt", "w").write(prompt(cfile, nunk, fully))
    print("  running codex agent...")
    subprocess.run(f'timeout 1800 codex exec --full-auto --cd "{REPO}" "$(cat /tmp/name_struct_prompt.txt)"',
                   shell=True, cwd=REPO, capture_output=True, text=True)
    if sh("git status --porcelain conker/src").stdout.strip() == "":
        print("  agent made no edits — skipping"); _record(rel, "noop"); return
    print("  gating (force-clean dual-SHA ROM)...")
    if _ig.rom_matches():
        named = before - _unk(open(cfile, errors="ignore").read())   # ->unkNN accesses cleared
        sh("git add conker/src")
        sh(f'git commit -q -m "type: name fields in {rel} ({named} unk accesses cleared, ROM-identical) [typing]"')
        print(f"  COMMITTED — {rel}: {named} unk accesses named, ROM verified byte-identical")
        _record(rel, f"named:{named}")
    else:
        sh("git checkout conker/src")
        print(f"  REVERTED — {rel} change was not ROM-identical (or broke build)")
        _record(rel, "reverted")

if __name__ == "__main__":
    main()
