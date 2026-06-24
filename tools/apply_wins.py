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

_TD = re.compile(r'\btypedef\b[^;{}]*?(\w+)\s*;')         # typedef <...> NAME;  (scalar/alias/fn-ptr)
_CB = re.compile(r'\}\s*(\w+)\s*;')                        # } NAME;  (struct/union/enum/typedef-struct)

def _type_names(text):
    """Type names DEFINED in a chunk of C (typedef targets + `} NAME;` tags)."""
    return {m.group(1) for m in _TD.finditer(text)} | {m.group(1) for m in _CB.finditer(text)}

def _project_types():
    """Type names DEFINED in the project headers (Gfx, Tri, Mtx, s32, f32, ...). The permuter inlines
    these to compile standalone; the project src #includes them, so re-emitting them REDEFINES and the
    port fails. We strip these (plus the names already in the TARGET src file — see main) — agent-local
    typedefs NOT defined anywhere else MUST be kept or the function references an undefined type."""
    names = set()
    for h in glob.glob(os.path.join(INNER, "include", "**", "*.h"), recursive=True):
        try:
            names |= _type_names(open(h, errors="ignore").read())
        except OSError:
            continue
    return names

def extract_func(srcfile, project_types=None):
    """Return the agent's local decls + the winning function, stripping ONLY the permuter's inlined
    PROJECT types (those in project_types) — they redefine the headers and break the port. Agent-local
    typedefs (a typed struct_<hex> from the type sweep) are KEPT (not in headers; the function needs
    them). A typedef is stripped iff the type NAME it defines is project-defined."""
    if project_types is None:
        project_types = _project_types()
    lines = open(srcfile).read().splitlines()
    out, i, n = [], 0, len(lines)
    intrinsic = re.compile(r"sqrtf|fabsf|#pragma intrinsic")
    ts_open = re.compile(r"^\s*typedef\s+(struct|union|enum)\b")   # block typedef (named OR anon)
    s_open = re.compile(r"^\s*(struct|union|enum)\s+struct\d+\b")  # bare anon project-struct expansion
    td_any = re.compile(r"^\s*typedef\b")                          # any other typedef (scalar/alias/fn-ptr)
    name_re = re.compile(r'(\w+)\s*;')
    while i < n:
        ln = lines[i]
        if intrinsic.search(ln):
            i += 1; continue
        if ts_open.match(ln) or s_open.match(ln):                 # multi-line block typedef/struct
            j = i
            while j < n and j < i + 3 and "{" not in lines[j]:
                j += 1
            if j < n and "{" in lines[j]:
                depth = 0
                while j < n:                                       # brace-count to matching close ("} Name;")
                    depth += lines[j].count("{") - lines[j].count("}")
                    j += 1
                    if depth <= 0:
                        break
                stmt_end = j
            else:
                stmt_end = i + 1                                   # forward/one-line block typedef
        elif td_any.match(ln):                                    # scalar/alias/fn-ptr typedef
            j = i
            while j < n and ";" not in lines[j]:
                j += 1
            stmt_end = j + 1
        else:
            out.append(ln); i += 1; continue
        # decide keep-vs-strip by the defined type NAME (identifier before the final ';')
        stmt = " ".join(lines[i:stmt_end])
        m = list(name_re.finditer(stmt))
        tyname = m[-1].group(1) if m else None
        if tyname is None or tyname in project_types:             # project type (or unparseable) -> strip
            i = stmt_end; continue
        out.extend(lines[i:stmt_end]); i = stmt_end               # agent-local type -> KEEP
    return "\n".join(out).strip() + "\n"

def main():
    r = sh(f"python3 {REPO}/tools/permuter_daemon.py collect")
    wins = [l.split() for l in r.stdout.splitlines() if l.startswith("WIN ")]
    ptypes = _project_types()              # compute the project-type set ONCE for all wins
    committed = []
    for _, func, file, src in wins:
        cfile = os.path.join(INNER, f"src/{file}.c")
        orig = open(cfile).read()
        pragma = f'#pragma GLOBAL_ASM("asm/nonmatchings/{file}/{func}.s")'
        if pragma not in orig:
            continue
        # strip project types AND types already defined in THIS target file (a sibling match since the
        # seed snapshot may have hoisted the same local struct -> re-emitting it would redeclare).
        body = extract_func(src, ptypes | _type_names(orig))
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
