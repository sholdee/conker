#!/usr/bin/env python3
"""In-project permuter (v2): brute-force the residue the ISOLATED decomp-permuter can't see.

Big-func near-misses score 0 in isolation (the permuter's world) but N>0 in the full PROJECT
build -- a full-translation-unit stack-frame/local-LAYOUT effect. This searches it directly:
mutate the function's LOCAL LAYOUT *and the stack STRUCT typedefs it uses*, scoring each variant
with the REAL full-file build via iter_match.sh. Hill-climb toward SCORE 0.

v2 vs v1: (a) robust baseline via apply_wins-style conflict-resolve (v1 BUILD-FAILed on several
funcs); (b) struct-field mutations -- reorder/resize/pad fields inside the local `*_<func>` typedefs,
which is where the real residue lives (e.g. func_150CF140's frame size is set by its Stack_* struct).

  usage: CONKER_REPO=$HOME/conker python3 tools/inproject_search.py FUNC FILE [iters=200] [seed=0]

Runs ONLY between orchestrator cycles (de-stubs the live src). ALWAYS restores src on exit unless
it CRACKS (then leaves src de-stubbed + writes /tmp/inproj_<func>.c for integrate).
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
        return None, r.stdout
    m = re.search(r"SCORE: (\d+)", r.stdout)
    return (int(m.group(1)) if m else None), r.stdout


def place_and_score(cfile, orig, pragma, body, file, func):
    open(cfile, "w").write(orig.replace(pragma, body, 1))
    return iter_match(file, func)


def clean_baseline(cfile, orig, pragma, body, file, func):
    """Strip redeclaration conflicts (cfe names them) until it compiles -- like apply_wins."""
    b = body
    for _ in range(8):
        sc, out = place_and_score(cfile, orig, pragma, b, file, func)
        if sc is not None:
            return b, sc
        syms = aw._conflict_syms(out)
        if not syms:
            return b, None        # genuine build failure, not a redeclaration
        nb = aw._strip_decls(b, syms, func)
        if nb == b:
            return b, None
        b = nb
    return b, None


# ---- struct-typedef mutation: target the `*_<func>` local structs (where frame size is set) ----
FIELD_ARR = re.compile(r'^(\s*[A-Za-z_][\w\s\*]*?\b\w+\s*\[)(0x[0-9A-Fa-f]+|\d+)(\]\s*;.*)$')
PAD_FIELD = re.compile(r'^\s*u8 _pf\d+\[\d+\];\s*$')


def struct_blocks(body, func):
    """Yield (start_idx, end_idx, name) for each `typedef struct {...} NAME_<funcsuffix>;`."""
    sfx = func.split("func_")[-1]
    out = []
    lines = body.split("\n")
    i = 0
    while i < len(lines):
        if re.match(r'\s*typedef struct', lines[i]):
            j = i
            while j < len(lines) and "}" not in lines[j]:
                j += 1
            if j < len(lines) and sfx in lines[j]:
                out.append((i, j))
            i = j + 1
        else:
            i += 1
    return out, lines


def mutate(body, rng, n, func):
    """Return a mutated copy of the whole body (local-decl + struct-field operators)."""
    lines = body.split("\n")
    blocks, _ = struct_blocks(body, func)
    ops = ["reorder_decl", "addpad_decl", "rmpad", "volatile", "resize_decl",
           "struct_field_resize", "struct_field_reorder", "struct_addpad", "struct_field_resize"]
    op = rng.choice(ops)

    # local declaration block (after the func's opening brace)
    bm = re.search(r'\bfunc_[0-9A-Fa-f]+\s*\([^;{]*\)\s*\{', body)
    if op in ("reorder_decl", "addpad_decl", "rmpad", "volatile", "resize_decl") and bm:
        brace_line = body[:bm.end()].count("\n")
        di = brace_line + 1
        dj = di
        decl_re = re.compile(r'^\s+[A-Za-z_].*;\s*$')
        while dj < len(lines) and (lines[dj].strip() == "" or
              (decl_re.match(lines[dj]) and "=" not in lines[dj] and "(" not in lines[dj].split(";")[0])):
            dj += 1
        block = lines[di:dj]
        real = [k for k, l in enumerate(block) if l.strip() and not re.match(r'\s*volatile s32 _pad\d+', l)]
        if op == "reorder_decl" and len(real) > 1:
            dl = [block[k] for k in real]; rng.shuffle(dl)
            for k, idx in enumerate(real): block[idx] = dl[k]
        elif op == "addpad_decl":
            block.insert(rng.randrange(len(block) + 1), f"  volatile s32 _pad{n}[{rng.choice([1,1,2,3,4])}];")
        elif op == "rmpad":
            pads = [k for k, l in enumerate(block) if re.match(r'\s*volatile s32 _pad\d+', l)]
            if pads: block.pop(rng.choice(pads))
        elif op == "volatile":
            cand = [k for k in real if re.match(r'^\s+(s32|u8|s16|f32|u16|u32)\s+\w+;', block[k]) and "volatile" not in block[k]]
            if cand:
                k = rng.choice(cand); block[k] = re.sub(r'^(\s+)', r'\1volatile ', block[k], 1)
        elif op == "resize_decl":
            cand = [k for k in real if re.search(r'\[(0x[0-9A-Fa-f]+|\d+)\]', block[k])]
            if cand:
                k = rng.choice(cand); m = re.search(r'\[(0x[0-9A-Fa-f]+|\d+)\]', block[k])
                v = max(1, int(m.group(1), 0) + rng.choice([-8, -4, 4, 8]))
                block[k] = block[k][:m.start()] + f"[{v}]" + block[k][m.end():]
        lines[di:dj] = block
        return "\n".join(lines)

    # struct-field operators (operate on a randomly chosen local struct typedef)
    if blocks:
        si, sj = rng.choice(blocks)
        fields = lines[si + 1:sj]
        fi = [k for k, l in enumerate(fields) if l.strip().endswith(";")]
        if op == "struct_field_resize":
            cand = [k for k in fi if FIELD_ARR.match(fields[k])]
            if cand:
                k = rng.choice(cand); m = FIELD_ARR.match(fields[k])
                v = max(1, int(m.group(2), 0) + rng.choice([-8, -4, -1, 1, 4, 8]))
                fields[k] = m.group(1) + str(v) + m.group(3)
        elif op == "struct_field_reorder" and len(fi) > 1:
            fl = [fields[k] for k in fi]; rng.shuffle(fl)
            for k, idx in enumerate(fi): fields[idx] = fl[k]
        elif op == "struct_addpad":
            if not any(PAD_FIELD.match(fields[k]) for k in fi):  # cap padding churn
                fields.insert(rng.randrange(len(fields) + 1), f"  u8 _pf{n}[{rng.choice([1,2,3,4])}];")
        lines[si + 1:sj] = fields
        return "\n".join(lines)
    return body


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
    cracked = False
    try:
        body, best = clean_baseline(cfile, orig, pragma, body0, file, func)
        print(f"baseline in-project score: {best}")
        if best is None:
            print("baseline BUILD-FAIL after conflict-resolve; cannot search"); return 2
        if best == 0:
            print("baseline already 0 -> integrate to confirm"); cracked = True; return 0
        best_body = body
        for n in range(iters):
            cand = mutate(best_body, rng, n, func)
            sc, _ = place_and_score(cfile, orig, pragma, cand, file, func)
            if sc is not None and sc < best:
                best, best_body = sc, cand
                print(f"  iter {n}: improved -> {best}")
                if best == 0:
                    open(f"/tmp/inproj_{func}.c", "w").write(best_body)
                    open(cfile, "w").write(orig.replace(pragma, best_body, 1))
                    print(f"CRACKED {func} at iter {n} (in-project SCORE 0); src de-stubbed for integrate")
                    cracked = True; return 0
        print(f"no crack in {iters} iters; best={best}")
        return 1
    finally:
        if not cracked:
            open(cfile, "w").write(orig)


if __name__ == "__main__":
    sys.exit(main())
