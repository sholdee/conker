#!/usr/bin/env python3
"""Port functions matched in a sibling fork but still stubbed in ours.

For each function with a real C definition in FORK/conker/src/game_*.c AND a
GLOBAL_ASM stub here, replace our stub with the fork's C body and verify it with
iter_match (builds ONLY that object, ~30s) — isolating every compile error /
mismatch per function. Survivors (SCORE: 0) are LEFT in the tree and printed as
(file func ...) pairs to feed integrate.py for the final force-clean ROM gate +
commit; failures are restored to their stub (prior survivors in the same file kept).

  usage: port_fork.py [FORK_CONKER_DIR] [LIMIT]
Run BETWEEN orchestrator runs (edits src). Prints survivor pairs to stdout.
"""
import glob, os, re, subprocess, sys

OURS = os.path.expanduser("~/conker/conker")
REPO = os.path.expanduser("~/conker")
FORK = os.path.expanduser(sys.argv[1] if len(sys.argv) > 1 else "~/conker-llm-fork/conker")
LIMIT = int(sys.argv[2]) if len(sys.argv) > 2 else 0   # 0 = all

def extract_def(text, func):
    """Extract a C function definition body from text via brace matching."""
    m = re.search(rf'^[A-Za-z_][A-Za-z0-9_ \*]*\b{func}\s*\([^;{{]*\)\s*\{{', text, re.M)
    if not m:
        return None
    i, depth, start = m.end() - 1, 0, m.start()
    while i < len(text):
        if text[i] == '{': depth += 1
        elif text[i] == '}':
            depth -= 1
            if depth == 0:
                return text[start:i+1]
        i += 1
    return None

def iter_match(file, func):
    """Build only this object + diff; return True iff SCORE: 0."""
    r = subprocess.run(["bash", f"{REPO}/tools/iter_match.sh", file, func],
                       capture_output=True, text=True, env={**os.environ, "CONKER_REPO": REPO})
    return "SCORE: 0" in (r.stdout + r.stderr)

def main():
    # fork C-defs
    fork_def = {}                     # func -> C body
    for p in glob.glob(f"{FORK}/src/game_*.c"):
        t = open(p).read()
        for m in re.finditer(r'^[A-Za-z_][A-Za-z0-9_ \*]*\b(func_[0-9A-F]+)\s*\([^;{]*\)\s*\{', t, re.M):
            fn = m.group(1)
            if fn not in fork_def:
                body = extract_def(t, fn)
                if body:
                    fork_def[fn] = body
    # our stubs, grouped by file (port file-by-file so survivors accumulate)
    by_file = {}                      # file -> [func, ...]
    for p in sorted(glob.glob(f"{OURS}/src/game_*.c")):
        file = os.path.basename(p)[:-2]
        for m in re.finditer(rf'GLOBAL_ASM\("asm/nonmatchings/{file}/(func_[0-9A-F]+)\.s"\)', open(p).read()):
            fn = m.group(1)
            if fn in fork_def:
                by_file.setdefault(file, []).append(fn)

    survivors, tested = [], 0
    for file, funcs in by_file.items():
        path = f"{OURS}/src/{file}.c"
        for func in funcs:
            if LIMIT and tested >= LIMIT:
                break
            tested += 1
            before = open(path).read()
            pragma = re.search(rf'#pragma GLOBAL_ASM\("asm/nonmatchings/{file}/{func}\.s"\)', before)
            if not pragma:
                continue
            open(path, "w").write(before[:pragma.start()] + fork_def[func] + before[pragma.end():])
            if iter_match(file, func):
                survivors.append((file, func))
                print(f"  ok   {func} ({file})", file=sys.stderr)
            else:
                open(path, "w").write(before)        # restore; keeps prior survivors in this file
                print(f"  fail {func} ({file})", file=sys.stderr)
        if LIMIT and tested >= LIMIT:
            break
    print(f"# {len(survivors)}/{tested} fork funcs verified (SCORE:0); feed to integrate.py", file=sys.stderr)
    print(" ".join(f"{f} {fn}" for f, fn in survivors))

if __name__ == "__main__":
    main()
