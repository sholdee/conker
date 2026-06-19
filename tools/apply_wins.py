#!/usr/bin/env python3
"""Apply decomp-permuter winners to the project, re-verify in the PROJECT context
(permuter score-0 is only relative to its isolated import; some don't port), and
commit the ones that match. Non-porters are marked .noport so collect skips them.

Run BETWEEN orchestrator runs (it edits src + builds + commits).
"""
import glob, json, os, re, subprocess, sys

REPO = os.path.expanduser("~/conker")
INNER = os.path.join(REPO, "conker")
NM = os.path.join(INNER, "nonmatchings")

def sh(cmd, cwd=REPO):
    return subprocess.run(cmd, shell=True, cwd=cwd, capture_output=True, text=True)

def extract_func(srcfile):
    """Return the agent's local decls + the winning function, stripping the
    permuter's base-typedef / intrinsic / project-struct-expansion preamble."""
    lines = open(srcfile).read().splitlines()
    out, i, n = [], 0, len(lines)
    skip_scalar = re.compile(r"^\s*typedef\s+(unsigned|signed|long|short|float|int|char|double)\b")
    fwd = re.compile(r"^\s*typedef struct (struct\d+|_PermuterTemp\d+) ")
    intrinsic = re.compile(r"sqrtf|fabsf|#pragma intrinsic")
    expand = re.compile(r"^\s*struct struct\d+\s*$|^\s*struct struct\d+\s*\{")
    while i < n:
        ln = lines[i]
        if skip_scalar.match(ln) or fwd.match(ln) or intrinsic.search(ln):
            i += 1; continue
        if expand.match(ln):                      # multi-line project-struct expansion
            depth = ln.count("{") - ln.count("}")
            i += 1
            while i < n and depth > 0:
                depth += lines[i].count("{") - lines[i].count("}")
                i += 1
            continue
        out.append(ln); i += 1
    return "\n".join(out).strip() + "\n"

def main():
    r = sh(f"python3 {REPO}/tools/permuter_daemon.py collect")
    wins = [l.split() for l in r.stdout.splitlines() if l.startswith("WIN ")]
    committed = []
    for _, func, file, src in wins:
        cfile = os.path.join(INNER, f"src/{file}.c")
        orig = open(cfile).read()
        pragma = f'#pragma GLOBAL_ASM("asm/nonmatchings/{file}/{func}.s")'
        if pragma not in orig:
            continue
        body = extract_func(src)
        open(cfile, "w").write(orig.replace(pragma, body, 1))
        sc = sh(f"{REPO}/tools/iter_match.sh {file} {func}")
        if re.search(r"SCORE: 0\b", sc.stdout):
            committed.append((file, func))
            print(f"  PORTS  {func} ({file})")
        else:
            open(cfile, "w").write(orig)          # revert
            open(os.path.join(NM, func, ".noport"), "w").close()
            m = re.search(r"SCORE: (\d+)", sc.stdout)
            print(f"  noport {func} (project score {m.group(1) if m else '?'})")
    if committed:
        args = " ".join(f"{f} {fn}" for f, fn in committed)
        print(sh(f". {REPO}/.venv/bin/activate && python3 {REPO}/tools/integrate.py {args}").stdout.strip())
    else:
        print("apply_wins: no porting winners this pass")

if __name__ == "__main__":
    main()
