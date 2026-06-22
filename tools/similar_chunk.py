#!/usr/bin/env python3
"""Pick the next chunk of decomp candidates, prioritizing ones with a strong
matched reference function (similarity-based scheduling).

Analog of select_chunk.py, but instead of selecting the smallest unattempted
functions, it selects functions that have a HIGH-similarity matched reference
(so an agent can decompile by analogy). Picks are:
  - still a GLOBAL_ASM stub (not already matched),
  - not in the persistent attempted-log (/tmp/orchestrator_attempted.txt),
  - <= M instructions, no handwritten asm,
  - ALL from DISTINCT .c files (concurrent agents never collide),
  - have a matched reference with similarity >= SIM_THRESHOLD,
  - ordered by HIGHEST similarity first.

For each pick we extract the reference matched function's full C body from its
src/<file>.c so the agent has a concrete example to follow.

If fewer than N strong-reference picks exist, the remainder is filled the OLD
way (smallest-size unattempted, distinct files) with ref_c="" so the
orchestrator always gets a full chunk.

Output: JSON array of
  {"func","file","ref_func","ref_file","ref_similarity","ref_c"}

Usage: similar_chunk.py [count=5] [maxi=55]
"""
import json
import os
import sys
import re
import hashlib
import subprocess
import glob

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)
import find_similar as fs  # reuse parsing / similarity / corpus / badness

_REPO = os.environ.get("CONKER_REPO", os.path.expanduser("~/conker"))
ROOT = os.path.join(_REPO, "conker")
RANK = "/tmp/game_ranked2.txt"


def _m2c_context():
    """Generate the m2c context file once (best-effort); return its path or None.
    Preprocesses the standard game includes so m2c can resolve project types."""
    ctx, src = "/tmp/m2c_ctx.c", "/tmp/m2c_ctxsrc.c"
    try:
        open(src, "w").write('#include <ultra64.h>\n#include "functions.h"\n'
                             '#include "variables.h"\n#include "macros.h"\n')
        r = subprocess.run(
            ["cpp", "-nostdinc", "-undef", "-D_LANGUAGE_C", "-DF3DEX_GBI_2",
             "-I", os.path.join(ROOT, "include"),
             "-I", os.path.join(ROOT, "include/2.0L"),
             "-I", os.path.join(ROOT, "include/2.0L/PR"), src],
            capture_output=True, text=True)
        if r.returncode == 0 and r.stdout.strip():
            open(ctx, "w").write(r.stdout)
            return ctx
    except Exception:
        pass
    return None


def _write_m2c_seed(func, file, ctx):
    """Run m2c on the function's asm -> /tmp/m2c_<func>.c (best-effort structural draft)."""
    mp = f"/tmp/m2c_{func}.c"
    spath = os.path.join(ROOT, "asm/nonmatchings", file, func + ".s")
    cmd = ["python3", os.path.join(HERE, "mips_to_c", "m2c.py")]
    if ctx:
        cmd += ["--context", ctx]
    cmd.append(spath)
    try:
        r = subprocess.run(cmd, capture_output=True, text=True, timeout=90)
        out = (r.stdout or "").strip()
        if out:
            open(mp, "w").write(out)
            return
    except Exception:
        pass
    if os.path.exists(mp):
        try:
            os.remove(mp)
        except OSError:
            pass

# Partitioning: split candidate stubs by file hash so two engines (Claude/Codex)
# work disjoint sets. "even"|"odd"|"all" (default "all" = no partitioning).
PARTITION = os.environ.get("CONKER_PARTITION", "all")
LOG = f"/tmp/orchestrator_attempted_{PARTITION}.txt"

SIM_THRESHOLD = 0.4


def file_partition(file):
    """0 = even, 1 = odd."""
    return int(hashlib.md5(file.encode()).hexdigest(), 16) % 2


def in_partition(file):
    if PARTITION == "all":
        return True
    want = 0 if PARTITION == "even" else 1
    return file_partition(file) == want


def is_stub(file, func):
    cpath = os.path.join(ROOT, f"src/{file}.c")
    pragma = f'#pragma GLOBAL_ASM("asm/nonmatchings/{file}/{func}.s")'
    try:
        return pragma in open(cpath).read()
    except OSError:
        return False


def candidate_stubs(maxi, attempted):
    """Yield (n_instr, file, func) for eligible stubs, smallest first (rank order)."""
    rows = []
    for line in open(RANK):
        parts = line.split()
        if len(parts) != 2:
            continue
        n, s = parts
        n = int(n)
        file, func = s[:-2].split("/")
        if func in attempted or n < 6 or n > maxi:
            continue
        if not in_partition(file):
            continue
        sfile = os.path.join(ROOT, "asm/nonmatchings", s)
        try:
            if "handwritten" in open(sfile).read():
                continue
        except OSError:
            continue
        if not is_stub(file, func):
            continue
        rows.append((n, file, func))
    rows.sort()
    return rows


def main():
    count = int(sys.argv[1]) if len(sys.argv) > 1 else 5
    maxi = int(sys.argv[2]) if len(sys.argv) > 2 else 55

    attempted = set()
    if os.path.exists(LOG):
        attempted = set(l.strip() for l in open(LOG) if l.strip())

    rows = candidate_stubs(maxi, attempted)

    # Build / load the matched corpus once (cached).
    corpus = fs.load_corpus(verbose=False)
    corpus_by_name = {c.name: c for c in corpus}
    # cache of per-file C text for ref-body extraction
    file_text = {}

    def c_text(file):
        if file not in file_text:
            try:
                file_text[file] = open(os.path.join(ROOT, f"src/{file}.c")).read()
            except OSError:
                file_text[file] = ""
        return file_text[file]

    # Score every eligible stub against the corpus; keep its top-3 strong refs.
    scored = []  # (similarity, n, file, func, [(ref_func, ref_file), ...])
    row_file = {}
    for n, file, func in rows:
        row_file[func] = file
        spath = os.path.join(ROOT, "asm/nonmatchings", file, func + ".s")
        query = fs.parse_asm_file(spath, func, file)
        if query is None:
            continue
        best = fs.rank(query, corpus, top_n=3, threshold=SIM_THRESHOLD,
                       drop_low_quality=True)
        if best:
            sim = best[0][0]
            refs = [(cand.name, cand.file) for _s, cand, _ in best]
            scored.append((sim, n, file, func, refs))

    # Highest similarity first; distinct files only.
    scored.sort(key=lambda r: (-r[0], r[1], r[3]))

    # RE-ATTEMPT priority: eligible stubs we have a prior near-miss for go FIRST, closest
    # (lowest prior score) first — each later seeded with its own best-C at /tmp/prev_<func>.c.
    # Only takes effect once the attempted-log is cleared (normally these are excluded as
    # already-attempted), so it doesn't change steady-state selection.
    nearmiss = {}
    for p in glob.glob(os.path.join(_REPO, ".nearmiss", "*.json")):
        try:
            d = json.load(open(p)); nearmiss[d["func"]] = d
        except Exception:
            pass
    scored_by_func = {s[3]: s for s in scored}
    nm_order = sorted((f for f in nearmiss if f in row_file),
                      key=lambda f: nearmiss[f].get("score", 999))
    ordered, seen_q = [], set()
    for func in nm_order:
        ordered.append(scored_by_func.get(func, (0.0, 0, row_file[func], func, [])))
        seen_q.add(func)
    ordered += [s for s in scored if s[3] not in seen_q]

    picked = []
    seen_files = set()
    picked_funcs = set()
    for sim, n, file, func, refs in ordered:
        if file in seen_files:
            continue
        ref_cs = []
        for rfunc, rfile in refs[:3]:
            r = corpus_by_name.get(rfunc)
            ref_cs.append((fs.extract_c_body(c_text(rfile), rfunc) or "") if r else "")
        ref_func, ref_file = (refs[0] if refs else ("", ""))
        picked.append({
            "func": func,
            "file": file,
            "ref_func": ref_func,
            "ref_file": ref_file,
            "ref_similarity": round(sim, 3),
            "ref_c": ref_cs[0] if ref_cs else "",
            "ref2_c": ref_cs[1] if len(ref_cs) > 1 else "",
            "ref3_c": ref_cs[2] if len(ref_cs) > 2 else "",
        })
        seen_files.add(file)
        picked_funcs.add(func)
        if len(picked) >= count:
            break

    # Fill remainder the OLD way: smallest-size unattempted, distinct files,
    # no strong reference (ref_c="").
    if len(picked) < count:
        for n, file, func in rows:  # rows already sorted smallest-first
            if file in seen_files or func in picked_funcs:
                continue
            picked.append({
                "func": func,
                "file": file,
                "ref_func": "",
                "ref_file": "",
                "ref_similarity": 0.0,
                "ref_c": "",
                "ref2_c": "",
                "ref3_c": "",
            })
            seen_files.add(file)
            picked_funcs.add(func)
            if len(picked) >= count:
                break

    # Write each reference C body + an m2c structural draft to files the match
    # agent reads directly, so large bodies never flow through structured output.
    ctx = _m2c_context()
    for p in picked:
        for key, suffix in (("ref_c", "ref"), ("ref2_c", "ref2"), ("ref3_c", "ref3")):
            rp = f"/tmp/{suffix}_{p['func']}.c"
            try:
                if p.get(key):
                    open(rp, "w").write(p[key])
                elif os.path.exists(rp):
                    os.remove(rp)          # clear any stale ref from a prior run
            except OSError:
                pass
        _write_m2c_seed(p["func"], p["file"], ctx)
        # prior best-C seed (re-attempt): start the agent from its own closest attempt
        pp = f"/tmp/prev_{p['func']}.c"
        nm = nearmiss.get(p["func"])
        try:
            if nm and nm.get("c"):
                open(pp, "w").write(f"/* your previous best attempt: SCORE {nm.get('score','?')} -- refine THIS toward 0 */\n{nm['c']}")
            elif os.path.exists(pp):
                os.remove(pp)
        except OSError:
            pass

    # Persist so the next chunk doesn't repeat these.
    with open(LOG, "a") as f:
        for p in picked:
            f.write(p["func"] + "\n")

    # Emit lightweight records (ref bodies stay on disk at /tmp/{ref,ref2,ref3,m2c}_<func>.c).
    drop = {"ref_c", "ref2_c", "ref3_c"}
    print(json.dumps([{k: v for k, v in p.items() if k not in drop} for p in picked]))


if __name__ == "__main__":
    main()
