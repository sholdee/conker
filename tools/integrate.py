#!/usr/bin/env python3
"""Deterministic integration gate for the orchestrator. Replaces the unreliable
LLM integration agent. Match agents leave matching C in their files (failures
self-revert); this script force-cleanly rebuilds, ROM-gates, and commits ONLY
what truly matches — bisecting out any broken function so the ROM can never
regress.

Usage: integrate.py <file1> <func1> <file2> <func2> ...
  (the claimed (file, func) matches from one round)

Robustness vs the prior agent:
- FORCE-clean rebuild (rm the bins) so a failed compile can't leave a stale
  matching bin that passes the sha1 check (the bug that broke 2 commits).
- Check the make exit code AND both sha1s.
- On mismatch, bisect: revert files one at a time until the ROM matches, so a
  single bad function never blocks the good ones.
"""
import os, subprocess, sys

REPO = os.path.expanduser("~/conker")
INNER_SHA = "842e3d348e3c8ae0039e2ab367ad492f9b5266d8"
OUTER_SHA = "4cbadd3c4e0729dec46af64ad018050eada4f47a"

def sh(cmd):
    return subprocess.run(cmd, shell=True, cwd=REPO, capture_output=True, text=True)

def rom_matches():
    """FORCE-clean build; True only if make succeeds AND both sha1s match."""
    sh("rm -f conker/build/conker.us.bin build/conker.us.z64")
    if sh(". .venv/bin/activate && make -C conker").returncode != 0:
        return False
    inner = sh("sha1sum conker/build/conker.us.bin").stdout.split()
    if not inner or inner[0] != INNER_SHA:
        return False
    if sh(". .venv/bin/activate && make -C conker replace && make -j").returncode != 0:
        return False
    outer = sh("sha1sum build/conker.us.z64").stdout.split()
    return bool(outer) and outer[0] == OUTER_SHA

def is_destubbed(file, func):
    p = f"{REPO}/conker/src/{file}.c"
    pragma = f'#pragma GLOBAL_ASM("asm/nonmatchings/{file}/{func}.s")'
    try:
        return pragma not in open(p).read()
    except OSError:
        return False

def main():
    args = sys.argv[1:]
    pairs = [(args[i], args[i + 1]) for i in range(0, len(args) - 1, 2)]
    # keep only the ones the agents actually de-stubbed (real attempts)
    claimed = [(f, fn) for f, fn in pairs if is_destubbed(f, fn)]
    if not claimed:
        print("INTEGRATE: nothing de-stubbed; nothing to commit"); return

    if rom_matches():
        good = claimed
    else:
        # bisect: revert one file at a time until the ROM matches; the reverted
        # files are the broken ones.
        good, bad = list(claimed), []
        for f, fn in list(claimed):
            if rom_matches():
                break
            sh(f"git checkout conker/src/{f}.c")
            good.remove((f, fn)); bad.append(fn)
        if not rom_matches():
            print("INTEGRATE: ROM still broken after reverting all claims — ABORT, no commit")
            sh("git checkout conker/src/")
            return
        if bad:
            print(f"INTEGRATE: reverted broken/unverifiable: {', '.join(bad)}")

    if not good:
        print("INTEGRATE: no verified matches to commit"); return
    files = " ".join(f"conker/src/{f}.c" for f, _ in good)
    funcs = ", ".join(fn for _, fn in good)
    sh(f"git add {files} tools/ido_cookbook.md")
    if sh("git diff --cached --quiet").returncode == 0:
        print("INTEGRATE: nothing staged (already committed?); no commit"); return
    msg = (f"game: match {len(good)} functions via orchestrator\\n\\n{funcs}\\n\\n"
           "asm-differ score 0; force-clean full-ROM sha1 verifies.\\n\\n"
           "Co-Authored-By: Claude Opus 4.8 (1M context) <noreply@anthropic.com>")
    r = sh(f'git commit -q -m "$(printf \'{msg}\')"')
    print(f"INTEGRATE: committed {len(good)} — {funcs}")

if __name__ == "__main__":
    main()
