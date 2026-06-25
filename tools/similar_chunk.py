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


def _nondefault_flag_files():
    """Src files the Makefile builds with a NON-default OPT_FLAGS (default is -O2 -g3). libultra is -O1/-g,
    and several init_*.c are -g (=-O0) or -O2. The match prompt + cookbook are -O2 -g3-specific, so the
    pipeline must NOT attempt these — wrong opt level => wrong codegen idioms (they need -O0-literal or
    per-file handling). The BUILD stays correct (asm_processor applies the real flag), this only stops us
    feeding mis-modelled files to agents. See mkst/conker#32 (libultra flag map)."""
    try:
        mk = open(os.path.join(ROOT, "Makefile")).read()
    except OSError:
        return set()
    return {m.group(1) for m in re.finditer(r'\$\(SRC_DIR\)/([\w/]+)\.c\.o:\s*OPT_FLAGS', mk)}


def segment_stubs(maxi, attempted):
    """Stubs from the init/debugger segments — the files the game RANK never lists. Enabled by
    CONKER_SEGMENTS (e.g. "init,debugger"). Reads each file's GLOBAL_ASM pragmas directly and sizes
    from the asm instruction count; smallest-first; handles the debugger/ subdir; distinct funcs.
    SKIPS files with a non-default Makefile OPT_FLAGS (the -O2 -g3 prompt/cookbook don't apply)."""
    segs = os.environ.get("CONKER_SEGMENTS", "")
    pats = []
    if "init" in segs:
        pats.append("src/init_*.c")
    if "debugger" in segs:
        pats += ["src/debugger_*.c", "src/debugger/*.c"]
    if not pats:
        return []
    PRAG = re.compile(r'GLOBAL_ASM\("(asm/nonmatchings/[^"]+/(func_[0-9A-Fa-f]+)\.s)"\)')
    nondefault = _nondefault_flag_files()
    rows, seen = [], set()
    for pat in pats:
        for c in glob.glob(os.path.join(ROOT, pat)):
            file = os.path.relpath(c, os.path.join(ROOT, "src"))[:-2]   # "init_1050" or "debugger/foo"
            if file in nondefault:                 # non -O2 -g3 build (e.g. -g/-O0) -> prompt/cookbook wrong
                continue
            try:
                txt = open(c).read()
            except OSError:
                continue
            for asmrel, func in PRAG.findall(txt):
                if func in attempted or func in seen:
                    continue
                try:
                    a = open(os.path.join(ROOT, asmrel)).read()
                except OSError:
                    continue
                if "handwritten" in a:
                    continue
                n = len(re.findall(r'(?m)^\s+/\*', a))
                if n < 6 or n > maxi:
                    continue
                seen.add(func)
                rows.append((n, file, func))
    rows.sort()
    return rows


def main():
    count = int(sys.argv[1]) if len(sys.argv) > 1 else 5
    maxi = int(sys.argv[2]) if len(sys.argv) > 2 else 55

    attempted = set()
    if os.path.exists(LOG):
        attempted = set(l.strip() for l in open(LOG) if l.strip())

    # EFFORT TRIAGE: also skip proven-plateau funcs (tools/difficult_functions.txt, derived from the
    # attempts.tsv history by difficult_functions.py). Bypassed on re-probe cycles (CONKER_REPROBE=1)
    # so a func thawed by a typing/struct/ref change since its last attempt still gets a fresh shot.
    if os.environ.get("CONKER_REPROBE") != "1":
        dpath = os.path.join(HERE, "difficult_functions.txt")
        if os.path.exists(dpath):
            attempted |= set(l.strip() for l in open(dpath) if l.strip())

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
    # [audit 15] exclude score-0 seeds from RE-ATTEMPT priority: a score-0-but-still-stub seed is an
    # object-match-but-ROM-fail dead-end — re-attempting just reproduces the same and steals the top
    # slots from real near-misses. (They remain pickable via normal similarity selection.)
    nm_order = sorted((f for f in nearmiss if f in row_file and nearmiss[f].get("score", 999) > 0),
                      key=lambda f: nearmiss[f].get("score", 999))
    ordered, seen_q = [], set()
    for func in nm_order:
        ordered.append(scored_by_func.get(func, (0.0, 0, row_file[func], func, [])))
        seen_q.add(func)
    ordered += [s for s in scored if s[3] not in seen_q]

    picked = []
    seen_files = set()
    picked_funcs = set()

    # RESERVED SLICE (CONKER_SEGMENTS): pre-seed up to CONKER_SEG_SLOTS init/debugger stubs — the segments
    # the game RANK never selects, so they make progress alongside game in the SAME pipeline (one integrate,
    # no concurrency risk). The game loops below then fill the rest of `count`; if no segment stubs remain,
    # the slots fall through to game (no permanent waste once init/debugger are exhausted). ref_c empty —
    # the agent still gets the target asm + m2c draft + cookbook.
    seg_slots = int(os.environ.get("CONKER_SEG_SLOTS", "3")) if os.environ.get("CONKER_SEGMENTS") else 0
    for n, file, func in (segment_stubs(maxi, attempted) if seg_slots else []):
        if len(picked) >= seg_slots:
            break
        if file in seen_files or func in picked_funcs:
            continue
        picked.append({"func": func, "file": file, "ref_func": "", "ref_file": "",
                       "ref_similarity": 0.0, "ref_c": "", "ref2_c": "", "ref3_c": ""})
        seen_files.add(file)
        picked_funcs.add(func)

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
                if nm.get("src") == "permuter-noport":
                    hdr = (f"/* decomp-permuter CRACKED this (byte-exact in ISOLATION) but it scored "
                           f"{nm.get('score','?')} in the full project -- the STRUCTURE is right; the remaining "
                           f"gap is project-context (a drifted neighbor, a constant, or rodata/jtbl). Start from "
                           f"THIS and close it. If the residual is an externalized jtbl or unreconcilable rodata, "
                           f"BAIL per the cookbook. */")
                elif nm.get("src") == "manual-comment":
                    hdr = (f"/* a PRIOR DEVELOPER's manual decomp attempt (was left commented-out, never matched; "
                           f"may be incomplete or rough -- the score {nm.get('score','?')} is a coarse quality "
                           f"estimate, NOT a measured asm-differ score). Use it as a starting point: finish/fix it "
                           f"toward a byte-exact match, re-deriving types from the asm. BAIL per the cookbook if "
                           f"it's far off or unsteerable. */")
                else:
                    hdr = f"/* your previous best attempt: SCORE {nm.get('score','?')} -- refine THIS toward 0 */"
                open(pp, "w").write(hdr + "\n" + nm["c"])
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
