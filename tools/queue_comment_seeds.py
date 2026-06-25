#!/usr/bin/env python3
"""Queue manual decomp-attempt comments (from the audit) into the matching pipeline as .nearmiss seeds.

For each audited usable seed (a commented-out C attempt under a still-GLOBAL_ASM stub): anchor on the func's
stub in the CURRENT file (drift-safe), grab the adjacent commented block, de-comment it, wrap with the file's
includes, and write .nearmiss/<func>.json {func,file,score,c}. The matching loop then re-attempts the func
seeded with this attempt (and BAILs if it's a dead end). PURELY ADDITIVE: only writes the seed store, never
src/, so it's safe alongside the live orchestrator. Skips funcs already matched (no stub) or already seeded.

  usage: queue_comment_seeds.py <workflow_output.json> [--apply]
         (without --apply: dry-run, prints what it would do)
"""
import json, os, re, sys

REPO = os.path.expanduser("~/conker")
INNER = os.path.join(REPO, "conker")
NEAR = os.path.join(REPO, ".nearmiss")

CLOSE = re.compile(r'JUSTREG|9\d%|almost only reg|mostly.*regalloc|just.*regalloc|1 line|\bCLOSE\b|not.*far|'
                   r'80%|strong seed|~?complete|near-?complete|nearly', re.I)
FAR = re.compile(r'miles away|pretty far|\b10%\b|maybe next year|mips2c|decomp\.me|phi.?var|no idea|'
                 r'very rough|unstructured|raw ', re.I)

def score_for(note):
    if FAR.search(note or ""):
        return 80          # far/raw -> low priority (agent must largely rewrite)
    if CLOSE.search(note or ""):
        return 35          # author-flagged near-match -> jump the queue
    return 50

def includes(txt):
    out = []
    for l in txt.split("\n"):
        if l.lstrip().startswith("#include"):
            out.append(l)
        elif out and l.strip() == "":
            continue
        elif out:
            break
    return "\n".join(out)

LABEL = re.compile(r'(?i)^(non-?match|nonmatch|justreg|matched\b|wip\b|todo|fixme|xxx\b|hack\b|note:|'
                   r'\d{1,3}%|close\b|miles away|pretty far|maybe next year|downhill)')

def decomment(block):
    """Strip the // prefix from CODE lines; DROP author-label lines (NON-MATCHING/JUSTREG/...); keep other
    prose AS a comment (re-bare prose would be invalid C). Drops the #if-0 wrapper, keeps its inner C."""
    out = []
    for l in block:
        st = l.strip()
        if st.startswith("#if 0") or st == "#endif" or st.startswith("#else"):
            continue
        if not st.startswith("//"):
            out.append(l); continue                    # real C (inside an #if 0)
        dec = re.sub(r'^(\s*)//\s?', r'\1', l)
        d = dec.strip()
        if not d:
            out.append(""); continue
        if LABEL.match(d):
            continue                                   # author note/label -> drop
        is_code = bool(re.search(r'[;{}()=]', d)) or bool(re.match(r'(case|default|goto|return|break|continue)\b', d)) or d.endswith(":")
        out.append(dec if is_code else "// " + d)      # code -> de-comment; prose -> keep commented
    return "\n".join(out).strip()

def grab_block(lines, si, step):
    """Consecutive comment / #if-0 / interior / blank lines from si in direction step."""
    blk, i, in0 = [], si, False
    while 0 <= i < len(lines):
        st = lines[i].strip()
        if st.startswith("//") or st.startswith("#if 0") or in0 or (st == "" and blk):
            blk.append(lines[i])
            if st.startswith("#if 0"):
                in0 = True
            if st.startswith("#endif"):
                in0 = False
        else:
            break
        i += step
    return blk if step > 0 else blk[::-1]

def extract(txt, func, file):
    lines = txt.split("\n")
    prag = f'GLOBAL_ASM("asm/nonmatchings/{file}/{func}.s")'
    si = next((i for i, l in enumerate(lines) if prag in l), None)
    if si is None:
        return None, "matched"                          # no stub -> func matched since the audit
    after = grab_block(lines, si + 1, 1)
    before = grab_block(lines, si - 1, -1)
    blk = before if len([l for l in before if l.strip()]) > len([l for l in after if l.strip()]) else after
    while blk and not blk[0].strip():
        blk.pop(0)
    while blk and not blk[-1].strip():
        blk.pop()
    if len([l for l in blk if l.strip()]) < 3:
        return None, "too-short"
    body = decomment(blk)
    if func not in body:                                # the de-commented block should mention the func
        return None, "no-func-in-body"
    return includes(txt) + "\n\n" + body + "\n", "ok"

def main():
    wf = json.load(open(sys.argv[1]))
    queue = wf["result"]["summary"]["seed_queue"]
    apply = "--apply" in sys.argv
    stats = {"seeded": 0, "skip_seeded": 0, "skip_matched": 0, "skip_bad": 0, "by_score": {}}
    for s in queue:
        func = s["func"]
        # audit returns file as "src/<path>.c"; normalize to the src-relative basename ("game_X",
        # "game/entrypoint", "libultra/audio/n_csq") used by .nearmiss + the GLOBAL_ASM pragma.
        file = s["file"]
        if file.startswith("src/"):
            file = file[len("src/"):]
        if file.endswith(".c"):
            file = file[:-2]
        if not re.match(r'[a-zA-Z_]', func):
            stats["skip_bad"] += 1; continue
        out = os.path.join(NEAR, func + ".json")
        if os.path.exists(out):
            stats["skip_seeded"] += 1; continue          # keep existing (may be a tuned crack)
        cpath = os.path.join(INNER, "src", file + ".c")
        try:
            txt = open(cpath).read()
        except OSError:
            stats["skip_bad"] += 1; continue
        body, why = extract(txt, func, file)
        if body is None:
            stats["skip_matched" if why == "matched" else "skip_bad"] += 1; continue
        sc = score_for(s.get("note"))
        stats["by_score"][sc] = stats["by_score"].get(sc, 0) + 1
        stats["seeded"] += 1
        if apply:
            os.makedirs(NEAR, exist_ok=True)
            json.dump({"func": func, "file": file, "score": sc, "c": body, "src": "manual-comment"},
                      open(out, "w"))
        else:
            print(f"  WOULD seed {func} ({file}) score={sc} [{len(body.splitlines())} lines]")
    print(f"\n{'SEEDED' if apply else 'DRY-RUN'}: {stats['seeded']} | skip existing {stats['skip_seeded']} | "
          f"skip matched {stats['skip_matched']} | skip bad {stats['skip_bad']} | scores {stats['by_score']}")

if __name__ == "__main__":
    main()
