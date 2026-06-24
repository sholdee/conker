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
    """Return the agent's local decls + the winning function, stripping the permuter's inlined
    project-type preamble. The permuter inlines project header types (scalars AND named/anon
    typedef-struct blocks like Tri/Gdma/Gtri) so it can compile standalone; the project src
    #includes those types, so they must be dropped or they REDEFINE the header and the port fails
    to compile. Match-stage seeds carry no local typedefs (agents add extern/prototype decls, not
    typedefs), so dropping every typedef is safe; a wrong strip just yields a graceful .noport."""
    lines = open(srcfile).read().splitlines()
    out, i, n = [], 0, len(lines)
    intrinsic = re.compile(r"sqrtf|fabsf|#pragma intrinsic")
    ts_open = re.compile(r"^\s*typedef\s+(struct|union|enum)\b")   # block typedef (named OR anon)
    s_open = re.compile(r"^\s*(struct|union|enum)\s+struct\d+\b")  # bare anon project-struct expansion
    td_any = re.compile(r"^\s*typedef\b")                          # any other typedef (scalar/alias/fn-ptr)
    while i < n:
        ln = lines[i]
        if intrinsic.search(ln):
            i += 1; continue
        if ts_open.match(ln) or s_open.match(ln):
            # find the opening brace in a short window (permuter emits "typedef struct\n{")
            j = i
            while j < n and j < i + 3 and "{" not in lines[j]:
                j += 1
            if j < n and "{" in lines[j]:
                depth = 0
                while j < n:                          # brace-count to the matching close (incl "} Name;")
                    depth += lines[j].count("{") - lines[j].count("}")
                    j += 1
                    if depth <= 0:
                        break
                i = j; continue
            i += 1; continue                          # forward/one-line block typedef -> drop the line
        if td_any.match(ln):                          # scalar/alias/fn-ptr typedef -> drop to terminating ';'
            while i < n and ";" not in lines[i]:
                i += 1
            i += 1; continue
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
