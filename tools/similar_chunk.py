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

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import find_similar as fs  # reuse parsing / similarity / corpus / badness

ROOT = os.path.expanduser("~/conker/conker")
RANK = "/tmp/game_ranked2.txt"
LOG = "/tmp/orchestrator_attempted.txt"

SIM_THRESHOLD = 0.4


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

    # Score every eligible stub against the corpus; keep its best strong ref.
    scored = []  # (similarity, n, file, func, ref_func, ref_file)
    for n, file, func in rows:
        spath = os.path.join(ROOT, "asm/nonmatchings", file, func + ".s")
        query = fs.parse_asm_file(spath, func, file)
        if query is None:
            continue
        best = fs.rank(query, corpus, top_n=1, threshold=SIM_THRESHOLD,
                       drop_low_quality=True)
        if best:
            sim, cand, _ = best[0]
            scored.append((sim, n, file, func, cand.name, cand.file))

    # Highest similarity first; distinct files only.
    scored.sort(key=lambda r: (-r[0], r[1], r[3]))

    picked = []
    seen_files = set()
    picked_funcs = set()
    for sim, n, file, func, ref_func, ref_file in scored:
        if file in seen_files:
            continue
        ref = corpus_by_name.get(ref_func)
        ref_c = fs.extract_c_body(c_text(ref_file), ref_func) or "" if ref else ""
        picked.append({
            "func": func,
            "file": file,
            "ref_func": ref_func,
            "ref_file": ref_file,
            "ref_similarity": round(sim, 3),
            "ref_c": ref_c,
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
            })
            seen_files.add(file)
            picked_funcs.add(func)
            if len(picked) >= count:
                break

    # Write each reference C body to a file the match agent reads directly, so
    # large bodies never flow through the orchestrator's structured output.
    for p in picked:
        rp = f"/tmp/ref_{p['func']}.c"
        try:
            if p["ref_c"]:
                open(rp, "w").write(p["ref_c"])
            elif os.path.exists(rp):
                os.remove(rp)              # clear any stale ref from a prior run
        except OSError:
            pass

    # Persist so the next chunk doesn't repeat these.
    with open(LOG, "a") as f:
        for p in picked:
            f.write(p["func"] + "\n")

    # Emit lightweight records (ref_c stays on disk at /tmp/ref_<func>.c).
    print(json.dumps([{k: v for k, v in p.items() if k != "ref_c"} for p in picked]))


if __name__ == "__main__":
    main()
