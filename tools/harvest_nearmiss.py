#!/usr/bin/env python3
"""Harvest a near-miss seed from iter_match's best-C snapshot (whole file), keep-best.

  harvest_nearmiss.py <func> <file> <score> <bestc_path>

Extracts the function body from the best-C snapshot and writes .nearmiss/<func>.json ONLY if it
beats any existing entry. Deterministic — the orchestrator uses this instead of trusting codex to
self-report its best (codex was harvesting its over-run version, degrading the seed).
"""
import json, os, re, shutil, sys

func, file, score, cpath = sys.argv[1], sys.argv[2], int(sys.argv[3]), sys.argv[4]
REPO = os.environ.get("CONKER_REPO", os.path.expanduser("~/conker"))
out = os.path.join(REPO, ".nearmiss", func + ".json")


def extract_def(text, fn):
    m = re.search(rf'^[A-Za-z_][A-Za-z0-9_ \*]*\b{fn}\s*\([^;{{]*\)\s*\{{', text, re.M)
    if not m:
        return None
    i, depth, start = m.end() - 1, 0, m.start()
    while i < len(text):
        if text[i] == '{':
            depth += 1
        elif text[i] == '}':
            depth -= 1
            if depth == 0:
                return text[start:i + 1]
        i += 1
    return None


# keep-best: skip if an existing seed is better or equal
if os.path.exists(out):
    try:
        if json.load(open(out)).get("score", 999999) <= score:
            sys.exit(0)
    except Exception:
        pass
try:
    body = extract_def(open(cpath).read(), func)
except Exception:
    body = None
if not body:
    sys.exit(0)
os.makedirs(os.path.dirname(out), exist_ok=True)
json.dump({"func": func, "file": file, "score": score, "c": body}, open(out, "w"))
# Also keep the WHOLE compilable best-C file (it built — it carries the function's supporting externs
# and local struct decls that the extracted body alone lacks). The permuter imports from this so its
# compile doesn't die on undefined symbols.
try:
    shutil.copy(cpath, out[:-5] + ".full.c")
except OSError:
    pass
print(f"harvest: {func} score {score}")
