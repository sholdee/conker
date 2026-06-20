#!/usr/bin/env python3
"""Find matched functions whose reference asm is similar to an unmatched stub.

Usage:
    python3 tools/find_similar.py <func> [--top N] [--threshold T] [--verbose]
    python3 tools/find_similar.py --rebuild-cache

Given an UNMATCHED stub function, this parses its splat .s, then compares it
against EVERY MATCHED function's .s (functions that already have a C body in
src/game_*.c). It prints the top-N most similar matched functions, which can
serve as decompilation references.

Project layout (Conker):
  - asm/nonmatchings/<file>/<func>.s   reference asm for ALL functions.
  - src/<file>.c                       C source.
      * UNMATCHED stub: has `#pragma GLOBAL_ASM("asm/nonmatchings/<file>/<func>.s")`
      * MATCHED:        has a real C body `<sig> <func>(...) { ... }`

Similarity reuses the snowboardkids2 algorithm: register-class normalization,
instruction trigram Jaccard (+ edit distance for small funcs), a control-flow
opcode signature, data-access offset patterns, and structural metrics
(instruction / branch / jump count, stack size).

Low-quality matched candidates (heavy pointer-arithmetic casts instead of
struct-field access) are dropped, since they make poor decompilation references.
"""

import sys
import os
import re
import json
import time
import argparse
import hashlib
from pathlib import Path
from dataclasses import dataclass, field
from typing import List, Dict, Tuple, Optional, Set
from collections import Counter

_REPO = os.environ.get("CONKER_REPO", os.path.expanduser("~/conker"))
ROOT = os.path.join(_REPO, "conker")
CACHE_DIR = os.path.join(_REPO, ".cache")
CACHE_FILE = os.path.join(CACHE_DIR, "find_similar_corpus.json")
CACHE_VERSION = 2

# Drop matched candidates whose pointer-arithmetic "badness" (violations per
# line of C) exceeds this. They compile but are poor references.
BADNESS_THRESHOLD = 0.12

# ---------------------------------------------------------------------------
# ASM parsing (ported from snowboardkids2 find_similar_functions.py)
# ---------------------------------------------------------------------------

INSTRUCTION_PATTERN = re.compile(
    r'/\*\s*[0-9A-Fa-f]+\s+[0-9A-Fa-f]+\s+[0-9A-Fa-f]+\s*\*/\s*(.+)')
LABEL_PATTERN = re.compile(r'^\s*\.L[0-9A-Fa-f_]+:')
GLABEL_PATTERN = re.compile(r'glabel\s+(\S+)')
BRANCH_PATTERN = re.compile(
    r'\b(beq|bne|bnez|beqz|blez|bgtz|bltz|bgez|blt|bgt|ble|bge|beql|bnel|'
    r'bltzal|bgezal|bc1t|bc1f|bc1tl|bc1fl)\b')
JUMP_PATTERN = re.compile(r'\b(jal|jalr|j|jr)\b')
JAL_PATTERN = re.compile(r'\bjal\s+(\S+)')
STACK_PATTERN = re.compile(r'addiu\s+\$sp,\s*\$sp,\s*-0x([0-9A-Fa-f]+)')
MEMORY_ACCESS_PATTERN = re.compile(r'(-?0x[0-9A-Fa-f]+|-?\d+)\s*\(\s*\$\w+\s*\)')

REGISTER_CLASSES = {
    '$t0': '$tN', '$t1': '$tN', '$t2': '$tN', '$t3': '$tN', '$t4': '$tN',
    '$t5': '$tN', '$t6': '$tN', '$t7': '$tN', '$t8': '$tN', '$t9': '$tN',
    '$s0': '$sN', '$s1': '$sN', '$s2': '$sN', '$s3': '$sN', '$s4': '$sN',
    '$s5': '$sN', '$s6': '$sN', '$s7': '$sN',
    '$a0': '$aN', '$a1': '$aN', '$a2': '$aN', '$a3': '$aN',
    '$v0': '$vN', '$v1': '$vN',
    # float regs collapsed to classes too
    '$f0': '$fN', '$f1': '$fN', '$f2': '$fN', '$f3': '$fN', '$f4': '$fN',
    '$f5': '$fN', '$f6': '$fN', '$f7': '$fN', '$f8': '$fN', '$f9': '$fN',
    '$f10': '$fN', '$f11': '$fN', '$f12': '$fN', '$f13': '$fN', '$f14': '$fN',
    '$f15': '$fN', '$f16': '$fN', '$f17': '$fN', '$f18': '$fN', '$f19': '$fN',
    '$f20': '$fN', '$f21': '$fN', '$f22': '$fN', '$f23': '$fN', '$f24': '$fN',
    '$f25': '$fN', '$f26': '$fN', '$f27': '$fN', '$f28': '$fN', '$f29': '$fN',
    '$f30': '$fN', '$f31': '$fN',
}
_REG_RE = {r: re.compile(r'\b' + re.escape(r) + r'\b') for r in REGISTER_CLASSES}


@dataclass
class ParsedFunction:
    name: str
    file: str  # e.g. "game_100810"
    instruction_count: int = 0
    branch_count: int = 0
    jump_count: int = 0
    label_count: int = 0
    stack_size: int = 0
    control_flow_signature: str = ""
    data_access_offsets: List[int] = field(default_factory=list)
    normalized_instructions: List[str] = field(default_factory=list)
    instruction_ngrams: Set[Tuple[str, ...]] = field(default_factory=set)
    badness: float = 0.0  # C-body pointer-arithmetic badness (matched only)


def normalize_instruction(instr: str) -> str:
    n = instr.strip()
    if '#' in n:
        n = n.split('#')[0].strip()
    for reg, repl in REGISTER_CLASSES.items():
        n = _REG_RE[reg].sub(repl, n)
    n = re.sub(r'%hi\([^)]+\)', '%hi(SYM)', n)
    n = re.sub(r'%lo\([^)]+\)', '%lo(SYM)', n)
    n = re.sub(r'\b0x[0-9A-Fa-f]{5,}\b', 'ADDR', n)
    n = re.sub(r'\.L[0-9A-Fa-f_]+', '.LABEL', n)
    n = re.sub(r'\bjal\s+\S+', 'jal FUNC', n)
    return n


def parse_asm_text(name: str, file: str, content: str) -> ParsedFunction:
    func = ParsedFunction(name=name, file=file)
    opcodes = []
    for raw in content.split('\n'):
        line = raw.strip()
        if not line or line.startswith('glabel') or line.startswith('.'):
            if LABEL_PATTERN.match(line):
                func.label_count += 1
                opcodes.append('LABEL')
            continue
        m = INSTRUCTION_PATTERN.match(line)
        if not m:
            continue
        instr = m.group(1).strip()
        func.instruction_count += 1
        opcode = instr.split()[0] if instr.split() else ""
        if opcode:
            opcodes.append(opcode)
        func.normalized_instructions.append(normalize_instruction(instr))
        if BRANCH_PATTERN.search(instr):
            func.branch_count += 1
        if JUMP_PATTERN.search(instr):
            func.jump_count += 1
        sm = STACK_PATTERN.search(instr)
        if sm:
            func.stack_size = int(sm.group(1), 16)
        for mm in MEMORY_ACCESS_PATTERN.finditer(instr):
            o = mm.group(1)
            try:
                func.data_access_offsets.append(int(o, 16) if 'x' in o else int(o))
            except ValueError:
                pass

    cf = [op for op in opcodes if op in (
        'beq', 'bne', 'bnez', 'beqz', 'blez', 'bgtz', 'bltz', 'bgez', 'beql',
        'bnel', 'blt', 'bgt', 'ble', 'bge', 'j', 'jal', 'jr', 'jalr', 'LABEL')]
    func.control_flow_signature = ' '.join(cf)

    if len(func.normalized_instructions) >= 3:
        ni = func.normalized_instructions
        func.instruction_ngrams = {tuple(ni[i:i + 3]) for i in range(len(ni) - 2)}
    return func


def parse_asm_file(path: str, name: str, file: str) -> Optional[ParsedFunction]:
    try:
        content = open(path).read()
    except OSError:
        return None
    if 'glabel' not in content:
        return None
    func = parse_asm_text(name, file, content)
    return func if func.instruction_count > 0 else None


# ---------------------------------------------------------------------------
# Low-quality match detection (ported from detect_low_quality_matches.py)
# ---------------------------------------------------------------------------

_BAD_PATTERNS = [re.compile(p) for p in (
    r'\(\s*\(\s*\w+\s*\*\s*\)\s*[^)]+\)\s*\[\s*[^]]+\]',
    r'\(\s*\w+\s*\*\s*\)\s*[^+\-;,)]+\s*[+\-]\s*(?:0x)?[0-9A-Fa-f]+',
    r'\*\s*\(\s*\w+\s*\*\s*\)\s*\(\s*\(\s*u8\s*\*\s*\)',
)]


def badness_of_body(body: str) -> float:
    """Violations-per-line for a single C function body string."""
    violations = 0
    lines = 0
    for line in body.split('\n'):
        s = line.strip()
        if s and not s.startswith('//'):
            lines += 1
        for p in _BAD_PATTERNS:
            violations += len(p.findall(line))
    return violations / max(lines, 1)


# ---------------------------------------------------------------------------
# Matched-corpus extraction from src/game_*.c
# ---------------------------------------------------------------------------

PRAGMA_RE = re.compile(r'#pragma GLOBAL_ASM\("asm/nonmatchings/([^/]+)/([^"]+)\.s"\)')


def _matching_brace(text: str, open_idx: int) -> int:
    depth = 0
    j = open_idx
    while j < len(text):
        c = text[j]
        if c == '{':
            depth += 1
        elif c == '}':
            depth -= 1
            if depth == 0:
                return j
        j += 1
    return -1


def extract_c_body(text: str, func: str) -> Optional[str]:
    """Return the full C definition (signature + body) of `func` in `text`,
    or None if it's only called / extern-declared (not defined here)."""
    for m in re.finditer(re.escape(func) + r'\s*\(', text):
        # find the matching close paren of the arg list
        i = m.end() - 1
        depth = 0
        j = i
        while j < len(text):
            if text[j] == '(':
                depth += 1
            elif text[j] == ')':
                depth -= 1
                if depth == 0:
                    break
            j += 1
        if j >= len(text):
            continue
        line_start = text.rfind('\n', 0, m.start()) + 1
        prefix = text[line_start:m.start()]
        if 'extern' in prefix or 'typedef' in prefix:
            continue
        # after ')' allow K&R param decls until the body '{'
        k = j + 1
        # skip whitespace / K&R declarations up to either '{' or ';'
        rest = text[k:k + 400]
        # find first '{' or ';' at this brace level
        brace = text.find('{', k)
        semi = text.find(';', k)
        if brace == -1:
            continue
        if semi != -1 and semi < brace:
            # it's a declaration/prototype, not a body
            continue
        # everything between ) and { should be K&R param decls or whitespace
        between = text[k:brace]
        if '}' in between or '#pragma' in between:
            continue
        close = _matching_brace(text, brace)
        if close == -1:
            continue
        return text[line_start:close + 1]
    return None


def discover_matched_corpus() -> List[Tuple[str, str]]:
    """Return list of (file, func) for all MATCHED functions (C body, not stub).

    Used both to compute the cache key and to know what to parse.
    """
    result = []
    nm = os.path.join(ROOT, "asm/nonmatchings")
    for sdir in sorted(Path(nm).glob("game_*")):
        if not sdir.is_dir():
            continue
        file = sdir.name
        cpath = os.path.join(ROOT, f"src/{file}.c")
        if not os.path.exists(cpath):
            continue
        txt = open(cpath).read()
        stubs = set(m.group(2) for m in PRAGMA_RE.finditer(txt))
        for sf in sorted(sdir.glob("*.s")):
            fn = sf.stem
            if fn in stubs:
                continue
            if re.search(r'\b' + re.escape(fn) + r'\b', txt):
                result.append((file, fn))
    return result


def corpus_key(pairs: List[Tuple[str, str]]) -> str:
    h = hashlib.sha256()
    h.update(str(CACHE_VERSION).encode())
    for file, fn in pairs:
        h.update(file.encode())
        h.update(b'/')
        h.update(fn.encode())
        h.update(b'\n')
    return h.hexdigest()


# ---------------------------------------------------------------------------
# Cache (keyed by hash of the matched-function set)
# ---------------------------------------------------------------------------

def serialize(f: ParsedFunction) -> dict:
    return {
        'name': f.name, 'file': f.file,
        'ic': f.instruction_count, 'bc': f.branch_count, 'jc': f.jump_count,
        'lc': f.label_count, 'ss': f.stack_size, 'cf': f.control_flow_signature,
        'do': f.data_access_offsets, 'ni': f.normalized_instructions,
        'bad': f.badness,
    }


def deserialize(d: dict) -> ParsedFunction:
    ni = d['ni']
    grams = {tuple(ni[i:i + 3]) for i in range(len(ni) - 2)} if len(ni) >= 3 else set()
    return ParsedFunction(
        name=d['name'], file=d['file'], instruction_count=d['ic'],
        branch_count=d['bc'], jump_count=d['jc'], label_count=d['lc'],
        stack_size=d['ss'], control_flow_signature=d['cf'],
        data_access_offsets=d['do'], normalized_instructions=ni,
        instruction_ngrams=grams, badness=d.get('bad', 0.0))


def build_corpus(pairs: List[Tuple[str, str]], verbose=True) -> List[ParsedFunction]:
    if verbose:
        print(f"Building matched corpus ({len(pairs)} functions)...", file=sys.stderr)
    # cache the per-file C text so we extract bodies once per file
    file_text: Dict[str, str] = {}
    out = []
    for file, fn in pairs:
        spath = os.path.join(ROOT, "asm/nonmatchings", file, fn + ".s")
        pf = parse_asm_file(spath, fn, file)
        if pf is None:
            continue
        if file not in file_text:
            try:
                file_text[file] = open(os.path.join(ROOT, f"src/{file}.c")).read()
            except OSError:
                file_text[file] = ""
        body = extract_c_body(file_text[file], fn)
        pf.badness = badness_of_body(body) if body else 0.0
        out.append(pf)
    if verbose:
        print(f"  parsed {len(out)} functions", file=sys.stderr)
    return out


def load_corpus(verbose=True, force_rebuild=False) -> List[ParsedFunction]:
    pairs = discover_matched_corpus()
    key = corpus_key(pairs)
    if not force_rebuild and os.path.exists(CACHE_FILE):
        try:
            data = json.load(open(CACHE_FILE))
            if data.get('key') == key:
                return [deserialize(d) for d in data['funcs']]
        except (json.JSONDecodeError, OSError, KeyError):
            pass
    corpus = build_corpus(pairs, verbose=verbose)
    os.makedirs(CACHE_DIR, exist_ok=True)
    tmp = CACHE_FILE + ".tmp"
    with open(tmp, 'w') as f:
        json.dump({'key': key, 'funcs': [serialize(c) for c in corpus]}, f)
    os.replace(tmp, CACHE_FILE)
    return corpus


# ---------------------------------------------------------------------------
# Similarity (ported weights from snowboardkids2)
# ---------------------------------------------------------------------------

def jaccard(a: set, b: set) -> float:
    if not a and not b:
        return 1.0
    if not a or not b:
        return 0.0
    return len(a & b) / len(a | b)


def lev_ratio(a: List[str], b: List[str]) -> float:
    if not a and not b:
        return 1.0
    if not a or not b:
        return 0.0
    la, lb = len(a), len(b)
    prev = list(range(lb + 1))
    cur = [0] * (lb + 1)
    for i in range(1, la + 1):
        cur[0] = i
        ai = a[i - 1]
        for j in range(1, lb + 1):
            cost = 0 if ai == b[j - 1] else 1
            cur[j] = min(prev[j] + 1, cur[j - 1] + 1, prev[j - 1] + cost)
        prev, cur = cur, prev
    return 1.0 - prev[lb] / max(la, lb)


def instruction_similarity(a: ParsedFunction, b: ParsedFunction) -> float:
    ngram = jaccard(a.instruction_ngrams, b.instruction_ngrams) \
        if a.instruction_ngrams and b.instruction_ngrams else 0.0
    if len(a.normalized_instructions) < 50 and len(b.normalized_instructions) < 50:
        return (ngram + lev_ratio(a.normalized_instructions, b.normalized_instructions)) / 2
    return ngram


def control_flow_similarity(a: ParsedFunction, b: ParsedFunction) -> float:
    sa, sb = a.control_flow_signature.split(), b.control_flow_signature.split()
    if not sa and not sb:
        return 1.0
    sig = lev_ratio(sa, sb)
    ra = a.branch_count / max(a.instruction_count, 1)
    rb = b.branch_count / max(b.instruction_count, 1)
    ratio = max(0.0, 1.0 - abs(ra - rb) * 5)
    return sig * 0.7 + ratio * 0.3


def data_access_similarity(a: ParsedFunction, b: ParsedFunction) -> float:
    oa, ob = set(a.data_access_offsets), set(b.data_access_offsets)
    if not oa and not ob:
        return 1.0
    exact = jaccard(oa, ob)
    if oa and ob:
        sa, sb = sorted(oa), sorted(ob)
        da = {sa[i + 1] - sa[i] for i in range(len(sa) - 1)}
        db = {sb[i + 1] - sb[i] for i in range(len(sb) - 1)}
        return exact * 0.6 + jaccard(da, db) * 0.4
    return exact


def structural_similarity(a: ParsedFunction, b: ParsedFunction) -> float:
    instr = min(a.instruction_count, b.instruction_count) / max(a.instruction_count, b.instruction_count, 1)
    branch = 1.0 - abs(a.branch_count - b.branch_count) / max(a.branch_count, b.branch_count, 1)
    jump = 1.0 - abs(a.jump_count - b.jump_count) / max(a.jump_count, b.jump_count, 1)
    if a.stack_size == b.stack_size:
        stack = 1.0
    elif a.stack_size == 0 or b.stack_size == 0:
        stack = 0.5
    else:
        stack = min(a.stack_size, b.stack_size) / max(a.stack_size, b.stack_size)
    return instr * 0.3 + branch * 0.25 + jump * 0.25 + stack * 0.2


def similarity(a: ParsedFunction, b: ParsedFunction) -> Tuple[float, dict]:
    isim = instruction_similarity(a, b)
    cf = control_flow_similarity(a, b)
    da = data_access_similarity(a, b)
    st = structural_similarity(a, b)
    total = isim * 0.35 + cf * 0.25 + da * 0.20 + st * 0.20
    return total, {'instr': isim, 'cf': cf, 'data': da, 'struct': st}


def find_query(func: str) -> Optional[ParsedFunction]:
    """Parse the query func's .s from anywhere under asm/nonmatchings."""
    hits = list(Path(os.path.join(ROOT, "asm/nonmatchings")).glob(f"*/{func}.s"))
    if not hits:
        return None
    p = hits[0]
    return parse_asm_file(str(p), func, p.parent.name)


def rank(query: ParsedFunction, corpus: List[ParsedFunction], top_n: int,
         threshold: float, drop_low_quality=True):
    results = []
    qsize = max(query.instruction_count, 1)
    for cand in corpus:
        if cand.name == query.name:
            continue
        # Early bound: instruction-count ratio caps structural & overall score.
        # If even a perfect match elsewhere can't clear threshold, skip cheaply.
        ratio = min(query.instruction_count, cand.instruction_count) / \
            max(query.instruction_count, cand.instruction_count, 1)
        # structural is 20% of score and instr ratio is 30% of structural;
        # max possible total given this ratio ~= 1 - 0.2*0.3*(1-ratio).
        if 1.0 - 0.06 * (1.0 - ratio) < threshold:
            continue
        if drop_low_quality and cand.badness > BADNESS_THRESHOLD:
            continue
        total, parts = similarity(query, cand)
        if total >= threshold:
            results.append((total, cand, parts))
    results.sort(key=lambda r: (-r[0], r[1].name))
    return results[:top_n]


def main():
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument('function_name', nargs='?')
    ap.add_argument('--top', '-n', type=int, default=10)
    ap.add_argument('--threshold', '-t', type=float, default=0.0)
    ap.add_argument('--verbose', '-v', action='store_true')
    ap.add_argument('--rebuild-cache', action='store_true')
    ap.add_argument('--keep-low-quality', action='store_true',
                    help="don't drop high-badness candidates")
    args = ap.parse_args()

    if args.rebuild_cache:
        t = time.time()
        corpus = load_corpus(verbose=True, force_rebuild=True)
        print(f"Cached {len(corpus)} matched functions to {CACHE_FILE} "
              f"in {time.time() - t:.1f}s", file=sys.stderr)
        if not args.function_name:
            return 0

    if not args.function_name:
        ap.print_help()
        return 1

    query = find_query(args.function_name)
    if query is None:
        print(f"Error: no asm found for '{args.function_name}' under "
              f"asm/nonmatchings/*/", file=sys.stderr)
        return 1
    print(f"Query {query.name}: {query.instruction_count} instrs, "
          f"{query.branch_count} branches, stack 0x{query.stack_size:X}",
          file=sys.stderr)

    corpus = load_corpus(verbose=True, force_rebuild=False)
    print(f"Loaded {len(corpus)} matched candidates", file=sys.stderr)

    results = rank(query, corpus, args.top, args.threshold,
                   drop_low_quality=not args.keep_low_quality)
    if not results:
        print("No similar matched functions found above threshold.")
        return 0

    print(f"\nMost similar MATCHED functions to {query.name}:\n")
    for i, (score, cand, parts) in enumerate(results, 1):
        print(f"{i}. {score:.3f}  {cand.name}  ({cand.file}.c)")
        if args.verbose:
            print(f"     instr={parts['instr']:.3f} cf={parts['cf']:.3f} "
                  f"data={parts['data']:.3f} struct={parts['struct']:.3f} "
                  f"badness={cand.badness:.3f} "
                  f"[ic={cand.instruction_count} bc={cand.branch_count} "
                  f"ss=0x{cand.stack_size:X}]")
    return 0


if __name__ == '__main__':
    sys.exit(main())
