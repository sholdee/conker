#!/usr/bin/env python3
"""In-project permuter: brute-force the residue the ISOLATED decomp-permuter can't see.

Big-func near-misses score 0 in isolation (the permuter's world) but N>0 in the full PROJECT
build -- a full-translation-unit stack-frame/local-layout effect. The isolated permuter is blind
to it; the LLM can't reliably reason it out. This searches it directly: mutate the function's
LOCAL LAYOUT (declaration order, padding, local sizes, volatile/register) and score each variant
with the REAL full-file build via iter_match.sh. Hill-climb toward SCORE 0.

  usage: CONKER_REPO=$HOME/conker python3 tools/inproject_search.py FUNC FILE [iters=200] [seed=0]

Runs ONLY between orchestrator cycles (de-stubs the live src). ALWAYS restores src on exit.
"""
import os, re, sys, subprocess, random

REPO = os.environ.get("CONKER_REPO", os.path.expanduser("~/conker"))
INNER = os.path.join(REPO, "conker")
sys.path.insert(0, os.path.join(REPO, "tools"))
import apply_wins as aw


def iter_match(file, func):
    r = subprocess.run(f"{REPO}/tools/iter_match.sh {file} {func}",
                       shell=True, capture_output=True, text=True)
    if "BUILD-FAIL" in r.stdout:
        return None
    m = re.search(r"SCORE: (\d+)", r.stdout)
    return int(m.group(1)) if m else None


def split_locals(body):
    """Return (head, decls, tail): head up to & incl the func's opening '{', decls = the run of
    leading declaration lines, tail = the rest. Robust-ish for IDO C89 (all locals declared first)."""
    # find the target function definition's opening brace (last top-level '{' before statements)
    m = re.search(r'\n(\w[\w\s\*]*\bfunc_[0-9A-Fa-f]+\s*\([^;{]*\)\s*)\{', body)
    if not m:
        return None
    brace = m.end()  # index just after '{'
    head = body[:brace]
    rest = body[brace:]
    lines = rest.split("\n")
    decls, i = [], 0
    decl_re = re.compile(r'^\s+[A-Za-z_].*;\s*$')
    assign_re = re.compile(r'^\s*\w[\w\s\*\[\]]*=')  # an assignment is NOT a decl
    while i < len(lines):
        ln = lines[i]
        if ln.strip() == "":
            decls.append(ln); i += 1; continue
        if decl_re.match(ln) and "=" not in ln and "(" not in ln.split(";")[0]:
            decls.append(ln); i += 1
        else:
            break
    tail = "\n".join(lines[i:])
    return head, decls, tail


def assemble(head, decls, tail):
    return head + "\n" + "\n".join(decls) + "\n" + tail


PAD_RE = re.compile(r'^\s*volatile s32 _pad\d+\[\d+\];\s*$')
ARR_RE = re.compile(r'(\[)(0x[0-9A-Fa-f]+|\d+)(\])')


def mutate(decls, rng, n):
    """Return a mutated copy of the decls list (layout-focused operators)."""
    d = [x for x in decls]
    real = [i for i, l in enumerate(d) if l.strip() and not PAD_RE.match(l)]
    op = rng.choice(["reorder", "addpad", "rmpad", "volatile", "resize", "reorder", "addpad"])
    if op == "reorder" and len(real) > 1:
        decl_lines = [d[i] for i in real]
        rng.shuffle(decl_lines)
        for i, idx in enumerate(real):
            d[idx] = decl_lines[i]
    elif op == "addpad":
        k = rng.choice([1, 1, 2, 3, 4])
        pos = rng.randrange(len(d) + 1)
        d.insert(pos, f"  volatile s32 _pad{n}[{k}];")
    elif op == "rmpad":
        pads = [i for i, l in enumerate(d) if PAD_RE.match(l)]
        if pads:
            d.pop(rng.choice(pads))
    elif op == "volatile":
        cand = [i for i in real if re.match(r'^\s+(s32|u8|s16|f32|u16|u32)\s+\w+;', d[i])
                and "volatile" not in d[i]]
        if cand:
            i = rng.choice(cand)
            d[i] = d[i].replace("  ", "  volatile ", 1) if d[i].startswith("  ") else "volatile " + d[i]
    elif op == "resize":
        cand = [i for i in real if ARR_RE.search(d[i])]
        if cand:
            i = rng.choice(cand)
            mm = ARR_RE.search(d[i])
            val = int(mm.group(2), 0)
            delta = rng.choice([-8, -4, 4, 8])
            nv = max(1, val + delta)
            d[i] = d[i][:mm.start()] + f"[{nv}]" + d[i][mm.end():]
    return d


def main():
    func, file = sys.argv[1], sys.argv[2]
    iters = int(sys.argv[3]) if len(sys.argv) > 3 else 200
    seed = int(sys.argv[4]) if len(sys.argv) > 4 else 0
    rng = random.Random(seed)
    base = os.path.join(INNER, "nonmatchings", func, "base.c")
    if not os.path.exists(base):
        print(f"no base.c for {func}; import it first"); return 2
    cfile = os.path.join(INNER, f"src/{file}.c")
    orig = open(cfile).read()
    pragma = f'#pragma GLOBAL_ASM("asm/nonmatchings/{file}/{func}.s")'
    if pragma not in orig:
        print(f"{func} not a stub in src/{file}.c (already matched?)"); return 2
    body0 = aw.extract_func(base, aw._project_types() | aw._type_names(orig))
    parts = split_locals(body0)
    if not parts:
        print("could not parse locals; aborting"); return 2
    head, decls, tail = parts

    def score_body(b):
        open(cfile, "w").write(orig.replace(pragma, b, 1))
        return iter_match(file, func)

    try:
        best = score_body(assemble(head, decls, tail))
        print(f"baseline in-project score: {best}")
        if best == 0:
            print("already 0 (false non-zero?) -> integrate will confirm"); return 0
        best_decls = decls
        for n in range(iters):
            cand = mutate(best_decls, rng, n)
            sc = score_body(assemble(head, cand, tail))
            if sc is not None and sc < (best if best is not None else 1 << 30):
                best, best_decls = sc, cand
                print(f"  iter {n}: improved -> {best}")
                if best == 0:
                    # leave the winning body in place; caller integrates
                    open(cfile, "w").write(orig.replace(pragma, assemble(head, best_decls, tail), 1))
                    print(f"CRACKED {func} at iter {n} (in-project SCORE 0); src left de-stubbed for integrate")
                    # persist the winner
                    open(f"/tmp/inproj_{func}.c", "w").write(assemble(head, best_decls, tail))
                    return 0
        print(f"no crack in {iters} iters; best={best}")
        return 1
    finally:
        # restore unless we cracked (cracked path returns before finally restore? no -> finally always runs)
        if best != 0:
            open(cfile, "w").write(orig)


if __name__ == "__main__":
    sys.exit(main())
