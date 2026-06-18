#!/usr/bin/env python3
"""Import near-miss seeds into decomp-permuter and (optionally) launch runs.

Usage:
  permuter_pass.py import   # de-stub each seed, import into permuter, restore tree, set ido
  permuter_pass.py launch <seconds>   # run permuter --stop-on-zero on each imported func

Seeds come from /tmp/permuter_seeds.json [{func,file,seed_c,score}, ...].
Each seed's best-attempt C is the permuter's starting point; the permuter
randomizes it looking for a register/scheduling permutation that scores 0.
Only ONE seed needs a local extern (D_800DCE50); the rest resolve via variables.h.
"""
import json, os, re, subprocess, sys, glob

ROOT = os.path.expanduser("~/conker/conker")
PERM = "../tools/decomp-permuter"
os.chdir(ROOT)

# symbols not in variables.h that a seed references -> local extern to prepend
EXTERNS = {
    "func_15168A4C": "extern u8 D_800DCE50[];\n\n",
    "func_15144B68": "extern f32 D_800A56A4;\n\n",
}

def run(cmd, **kw):
    return subprocess.run(cmd, shell=True, capture_output=True, text=True, **kw)

def do_import():
    seeds = json.load(open("/tmp/permuter_seeds.json"))
    for s in seeds:
        func, fnbase = s["func"], s["file"]
        cfile = f"src/{fnbase}.c"
        orig = open(cfile).read()
        pragma = f'#pragma GLOBAL_ASM("asm/nonmatchings/{fnbase}/{func}.s")'
        if pragma not in orig:
            print(f"  SKIP {func}: stub not found (already matched?)"); continue
        body = EXTERNS.get(func, "") + s["seed_c"]
        open(cfile, "w").write(orig.replace(pragma, body, 1))
        # import: builds the function with PERMUTER=1 and snapshots target + base.c.
        # Pass the asm FILE (not func name) since we just replaced its GLOBAL_ASM block.
        asm = f"asm/nonmatchings/{fnbase}/{func}.s"
        r = run(f"python3 {PERM}/import.py {cfile} {asm} 2>&1")
        open(cfile, "w").write(orig)  # restore tree immediately
        d = f"nonmatchings/{func}"
        if "Done. Imported" in r.stdout and os.path.isdir(d):
            # force the IDO randomization profile
            st = f"{d}/settings.toml"
            txt = open(st).read().replace('compiler_type = "base"', 'compiler_type = "ido"')
            open(st, "w").write(txt)
            print(f"  IMPORTED {func} (seed score {s['score']}) -> {d}")
        else:
            err = "\n".join(l for l in r.stdout.splitlines() if "rror" in l or "undefined" in l)[:200]
            print(f"  IMPORT-FAIL {func}: {err}")

def launch(seconds):
    for d in sorted(glob.glob("nonmatchings/func_*")):
        func = os.path.basename(d)
        log = f"/tmp/perm_{func}.log"
        # detached; --stop-on-zero halts on a perfect match
        subprocess.Popen(
            f"timeout {seconds} python3 {PERM}/permuter.py {d} --best-only --stop-on-zero -j2 "
            f"> {log} 2>&1",
            shell=True)
        print(f"  launched permuter for {func} ({seconds}s, -j2) -> {log}")

if __name__ == "__main__":
    if len(sys.argv) >= 2 and sys.argv[1] == "import":
        do_import()
    elif len(sys.argv) >= 3 and sys.argv[1] == "launch":
        launch(int(sys.argv[2]))
    else:
        print(__doc__)
