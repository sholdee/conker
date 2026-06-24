#!/usr/bin/env python3
"""Lean live dashboard for the Conker decomp pipeline. Read-only; stdlib only.

  python3 tools/dashboard.py [port=8077]   then open http://localhost:8077

Scrapes the live state already emitted by the pipeline (codex logs with SCORE lines,
attempts.tsv, .nearmiss, git, the linker map, permuter dirs) and serves it as a
self-refreshing page. Does not touch the matching pipeline.
"""
import http.server, socketserver, json, os, re, glob, subprocess, time, sys, importlib.util, threading

REPO = os.environ.get("CONKER_REPO", os.path.expanduser("~/conker"))
INNER = os.path.join(REPO, "conker")
PORT = int(sys.argv[1]) if len(sys.argv) > 1 else 8077

_cache = {}
def cached(key, ttl, fn):
    now = time.time()
    if key in _cache and now - _cache[key][0] < ttl:
        return _cache[key][1]
    try:
        val = fn()
    except Exception:
        val = _cache.get(key, (0, None))[1]
    _cache[key] = (now, val)
    return val

def map_sizes():
    def build():
        sizes = {}
        mp = os.path.join(INNER, "build/conker.us.map")
        if not os.path.exists(mp):
            return sizes
        spec = importlib.util.spec_from_file_location("prog", os.path.join(REPO, "tools/progress.py"))
        prog = importlib.util.module_from_spec(spec); spec.loader.exec_module(prog)
        for seg in [".init", ".game", ".debugger"]:
            try:
                with open(mp) as mf:
                    _, functions = prog.parse_map(mf, seg, None)   # None = blank-line delimited (matches Makefile)
                for fn, info in functions.items():
                    if "length" in info:
                        sizes[fn] = (seg[1:], info["length"])
            except Exception:
                pass
        return sizes
    return cached("map", 999999, build)

def stub_map():
    """Stubs from COMMITTED HEAD — NOT the working tree. The matching agents de-stub functions in the
    working tree mid-round BEFORE integrate gates them, so a working-tree read counts dozens of unproven
    in-flight matches and the progress % fluctuates up/down as integrate commits-or-reverts them. Reading
    HEAD shows only committed matches, which is what progress()/runway()/history should reflect. (The live
    in-flight churn is surfaced separately by tree_status()'s 'N in-flight' badge.)"""
    def build():
        s = {}
        # [^"]+ (not [^/]+) so NESTED asm paths (nonmatchings/a/b/func.s) match too — else nested-path
        # stubs are missed and counted as matched, overstating %.
        try:
            out = subprocess.run(
                ["git", "-C", REPO, "grep", "-hoE",
                 r'asm/nonmatchings/[^"]+/func_[0-9A-Fa-f]+\.s', "HEAD", "--", "conker/src/*.c"],
                capture_output=True, text=True, timeout=10).stdout
        except Exception:
            out = ""
        for m in re.finditer(r'asm/nonmatchings/([^"\n]+)/(func_[0-9A-Fa-f]+)\.s', out):  # [^"\n]: stay on
            s[m.group(2)] = m.group(1)                                                     # one line (no quotes
        if not s:                                # git grep failed/empty -> fall back to working tree   # in -o out)
            for c in glob.glob(os.path.join(INNER, "src/*.c")):   # (don't degrade to a false 100%)
                try:
                    txt = open(c).read()
                except Exception:
                    continue
                for m in re.finditer(r'GLOBAL_ASM\("asm/nonmatchings/([^"]+)/(func_[0-9A-Fa-f]+)\.s"\)', txt):
                    s[m.group(2)] = m.group(1)
        return s
    return cached("stubs", 20, build)

def progress():
    def build():
        sizes = map_sizes() or {}
        st = set(stub_map().keys())
        out = {}
        is_data = lambda f: f.startswith(("D_", "B_", "jtbl", "jpt_", "_pad"))
        for seg in ["init", "game", "debugger"]:
            allf = {f: l for f, (sg, l) in sizes.items() if sg == seg}
            # BYTES: functions + .L code labels, but NOT data (D_/jtbl/…) — data isn't function code.
            funcs = {f: l for f, l in allf.items() if not is_data(f)}
            # COUNT: functions only — also exclude .L gcc local labels (branch targets inside a func).
            real = {f for f in funcs if not f.startswith(".L")}
            tf = len(real); cf = sum(1 for f in real if f not in st)
            tb = sum(funcs.values()); cb = sum(l for f, l in funcs.items() if f not in st)
            out[seg] = {"cf": cf, "tf": tf, "cb": cb, "tb": tb,
                        "fpct": round(cf / tf * 100, 1) if tf else 0,
                        "bpct": round(cb / tb * 100, 1) if tb else 0}
        cf = sum(o["cf"] for o in out.values()); tf = sum(o["tf"] for o in out.values())
        cb = sum(o["cb"] for o in out.values()); tb = sum(o["tb"] for o in out.values())
        out["overall"] = {"cf": cf, "tf": tf, "cb": cb, "tb": tb,
                          "fpct": round(cf / tf * 100, 1) if tf else 0,
                          "bpct": round(cb / tb * 100, 1) if tb else 0}
        return out
    return cached("progress", 25, build)

def active():
    # follow whichever pipeline is live: matching (codex_chunk) or typing (type_chunk), by freshest chunk.
    cands = [(c, p) for c, p in (("/tmp/type_chunk.txt", "typel_"), ("/tmp/codex_chunk.txt", "codexm_"))
             if os.path.exists(c)]
    if not cands:
        return []
    chunk, logpfx = max(cands, key=lambda cp: os.path.getmtime(cp[0]))
    st = stub_map(); sizes = map_sizes() or {}
    res = []
    try:
        lines = open(chunk).read().split("\n")
    except Exception:
        lines = []
    for line in lines:
        p = line.split()
        if len(p) != 2:
            continue
        func, file = p
        log = f"/tmp/{logpfx}{func}.log"
        mtime = os.path.getmtime(log) if os.path.exists(log) else 0
        # best score from iter_match's DETERMINISTIC tracked file — NOT the agent log. The agent echoes
        # the match prompt's literal "SCORE: 0" text on its own line, which slips past an anchored regex
        # and shows a false best=0. /tmp/best_ is what the score-0 snapshot + harvest actually trust.
        best = None
        bf = f"/tmp/best_{func}.score"
        if os.path.exists(bf):
            try:
                best = int(open(bf).read().strip())
            except Exception:
                pass
        # iteration count from iter_match's own "BEST:" lines (one per iteration; the agent doesn't echo
        # those, unlike "SCORE:").
        iters = 0
        if os.path.exists(log):
            try:
                iters = len(re.findall(r'(?m)^BEST: \d+', open(log).read()))
            except Exception:
                pass
        instrs = (sizes.get(func, (None, 0))[1] // 4) if func in sizes else None
        # While Codex is still iterating (fresh log) it's "working"; once quiet, best 0 = matched.
        fresh = (time.time() - mtime) < 90 if mtime else False
        status = "working" if fresh else "matched" if best == 0 else "idle"
        res.append({"func": func, "file": file, "instrs": instrs, "best": best,
                    "latest": best, "iters": iters,
                    "status": status, "age": int(time.time() - mtime) if mtime else None})
    res.sort(key=lambda r: (r["status"] != "working", r["best"] if r["best"] is not None else 999))
    return res

def recent_commits():
    def build():
        try:
            out = subprocess.run(["git", "-C", REPO, "log", "--format=%h|%cr|%s", "-15"],
                                 capture_output=True, text=True, timeout=5).stdout
        except Exception:
            return []
        res = []
        for l in out.splitlines():
            parts = l.split("|", 2)
            if len(parts) != 3:
                continue
            m = re.search(r'(match|type) (\d+) function', parts[2])
            if not m:
                continue
            cyc = re.search(r'\[cycle (\d+)\]', parts[2])
            res.append({"hash": parts[0], "when": parts[1], "kind": m.group(1),
                        "n": int(m.group(2)), "cycle": int(cyc.group(1)) if cyc else None})
        return res
    return cached("commits", 10, build)

def nearmiss():
    def build():
        bands = {"<=8": 0, "9-20": 0, "21-50": 0, "51-80": 0, "81+": 0}
        for p in glob.glob(os.path.join(REPO, ".nearmiss/*.json")):
            try:
                s = json.load(open(p)).get("score", 999)
            except Exception:
                continue
            if s <= 8: bands["<=8"] += 1
            elif s <= 20: bands["9-20"] += 1
            elif s <= 50: bands["21-50"] += 1
            elif s <= 80: bands["51-80"] += 1
            else: bands["81+"] += 1
        return {"bands": bands, "total": sum(bands.values())}
    return cached("nearmiss", 20, build)

def permuter():
    def build():
        seeded = len(glob.glob(os.path.join(INNER, "nonmatchings/func_*")))
        cracked = len(glob.glob(os.path.join(INNER, "nonmatchings/func_*/output-0-*")))
        try:
            live = subprocess.run("pgrep -f '[p]ermuter.py' | wc -l", shell=True,
                                  capture_output=True, text=True).stdout.strip()
        except Exception:
            live = "?"
        return {"seeded": seeded, "cracked": cracked, "backlog": seeded - cracked, "live": live}
    return cached("permuter", 15, build)

def cycle_status():
    try:
        return json.load(open("/tmp/cycle_status.json"))
    except Exception:
        return {}

def rom_status():
    try:
        d = json.load(open("/tmp/rom_status.json"))
        d["age"] = int(time.time() - os.path.getmtime("/tmp/rom_status.json"))
        return d
    except Exception:
        return {}

def tree_status():
    def build():
        try:
            out = subprocess.run(["git", "-C", REPO, "status", "--porcelain", "conker/src"],
                                 capture_output=True, text=True, timeout=5).stdout
            return {"inflight": len([l for l in out.splitlines() if l.strip()])}
        except Exception:
            return {"inflight": None}
    return cached("tree", 4, build)

def cycle_matched():
    cyc = cycle_status().get("cycle")
    if not cyc:
        return 0
    def build():
        try:
            out = subprocess.run(["git", "-C", REPO, "log", f"--grep=\\[cycle {cyc}\\]",
                                  "--format=%s", "-300"], capture_output=True, text=True, timeout=5).stdout
            return sum(int(m.group(1)) for l in out.splitlines()
                       for m in [re.search(r'match (\d+)', l)] if m)
        except Exception:
            return 0
    return cached(f"cyc{cyc}", 8, build)

HIST = os.path.join(REPO, ".progress_history.tsv")

def _full_bytes():
    """func -> full code bytes (func_ length + the .L branch-target chunks the map lists separately).
    Approximate vs progress()'s total; used only for the SHAPE of the byte curve, which is then
    anchored to exact endpoints, so the approximation washes out."""
    def build():
        spec = importlib.util.spec_from_file_location("prog", os.path.join(REPO, "tools/progress.py"))
        prog = importlib.util.module_from_spec(spec); spec.loader.exec_module(prog)
        mp = os.path.join(INNER, "build/conker.us.map"); fb = {}
        for seg in [".init", ".game", ".debugger"]:
            try:
                with open(mp) as mf:
                    _, fns = prog.parse_map(mf, seg, None)
            except Exception:
                continue
            syms = sorted((i.get("offset", 0), fn, i.get("length", 0)) for fn, i in fns.items())
            for k, (off, fn, ln) in enumerate(syms):
                if fn.startswith((".L", "D_", "B_", "jtbl", "jpt_")):
                    continue
                end = off + ln; j = k + 1
                while j < len(syms) and syms[j][1].startswith(".L"):
                    end = syms[j][0] + syms[j][2]; j += 1
                fb[fn] = max(ln, end - off)
        return fb
    return cached("fullbytes", 999999, build)

def _reconstruct_history():
    """Branch-long series from DE-STUB events (every match removes a GLOBAL_ASM pragma — reliable).
    SELF-CONSISTENT, no external anchor: restricted to OUR commits (since the fork from upstream,
    which re-split the ROM into a different function universe — mkst's % is NOT comparable). The
    baseline is current progress minus our contribution; function counts are exact, byte sizes are
    scaled so they reconcile exactly with progress()'s matched-byte total. Endpoints land on exact
    current progress."""
    ov = progress()["overall"]; tf = ov["tf"] or 1; tb = ov["tb"] or 1
    fb = _full_bytes(); st = set(stub_map().keys())
    matched_fb = sum(b for f, b in fb.items()
                     if f not in st and not f.startswith(("D_", "B_", "jtbl", "jpt_"))) or 1
    sf = ov["cb"] / matched_fb                            # scale full_bytes -> exact matched-byte total
    mb = subprocess.run("git merge-base HEAD origin/master", shell=True, cwd=REPO,
                        capture_output=True, text=True).stdout.strip()
    rng = (mb + "..HEAD") if mb else ""                   # OUR commits only (fall back to all)
    out = subprocess.run(f"git log --reverse --format='C%ct' -p -U0 {rng} -- 'conker/src/*.c'",
                         shell=True, cwd=REPO, capture_output=True, text=True).stdout
    ts = None; last = {}
    for ln in out.splitlines():
        if ln.startswith("C") and ln[1:].isdigit():
            ts = int(ln[1:])
        elif ln.startswith("-") and "GLOBAL_ASM" in ln and ts:
            m = re.search(r'(func_[0-9A-Fa-f]+)', ln)
            if m:
                last[m.group(1)] = ts                     # last de-stub wins (handles revert+redo)
    events = sorted((t, f) for f, t in last.items() if f not in st)   # currently-matched only
    if not events:
        return
    base_cf = ov["cf"] - len(events)
    base_cb = ov["cb"] - sf * sum(fb.get(f, 0) for _, f in events)
    rows = [f"{events[0][0]}\t{round(base_cf/tf*100,2)}\t{round(base_cb/tb*100,2)}"]
    cc = 0; cbq = 0.0
    for t, f in events:
        cc += 1; cbq += sf * fb.get(f, 0)
        rows.append(f"{t}\t{round((base_cf+cc)/tf*100,2)}\t{round((base_cb+cbq)/tb*100,2)}")
    if len(rows) > 150:                                   # smooth ~150-pt curve over the sprint
        step = len(rows) / 150.0
        rows = [rows[int(i * step)] for i in range(150)] + [rows[-1]]
    try:
        open(HIST, "w").write("\n".join(rows) + "\n")
    except OSError:
        pass

def sample_history(pr):
    """Keep today's point live + add one point per new day, with EXACT progress() numbers (matches
    the UI). Over time the reconstructed/approximate tail is replaced by exact daily samples."""
    try:
        if not os.path.exists(HIST):
            return
        lines = [l for l in open(HIST).read().strip().split("\n") if l]
        today = int(time.time()) // 86400
        o = pr["overall"]; new = f"{today*86400}\t{o['fpct']}\t{o['bpct']}"
        lastday = int(float(lines[-1].split("\t")[0])) // 86400 if lines else -1
        if lastday == today:
            if lines[-1] == new:
                return
            lines[-1] = new
        else:
            lines.append(new)
        open(HIST, "w").write("\n".join(lines) + "\n")
    except Exception:
        pass

def progress_history():
    def build():
        if not os.path.exists(HIST):
            _reconstruct_history()
        pts = []
        try:
            for ln in open(HIST):
                a = ln.strip().split("\t")
                if len(a) == 3:
                    pts.append({"t": int(float(a[0])), "f": float(a[1]), "b": float(a[2])})
        except OSError:
            return []
        if len(pts) > 180:                          # downsample for the SVG
            step = len(pts) / 180.0
            pts = [pts[int(i * step)] for i in range(180)] + [pts[-1]]
        return pts
    return cached("history", 30, build)

def runway():
    """Unmatched game functions by instruction-size band — where the remaining work lives."""
    def build():
        sizes = map_sizes() or {}; st = set(stub_map().keys())
        order = ["≤100", "101–200", "201–400", "401–700", ">700"]
        bins = {k: 0 for k in order}
        for f, (seg, length) in sizes.items():
            if seg != "game" or f not in st or f.startswith((".L", "D_", "B_", "jtbl", "jpt_")):
                continue
            n = length // 4
            k = ("≤100" if n <= 100 else "101–200" if n <= 200 else "201–400" if n <= 400
                 else "401–700" if n <= 700 else ">700")
            bins[k] += 1
        return {"order": order, "bins": bins, "total": sum(bins.values())}
    return cached("runway", 60, build)

def phase_status():
    # bracket the first char so the pattern doesn't match the pgrep shell command's OWN cmdline
    # (which contains the literal pattern) — that self-match pinned every phase to the first check.
    def r(pat):
        return subprocess.run(f"pgrep -f '[{pat[0]}]{pat[1:]}' >/dev/null 2>&1", shell=True).returncode == 0
    if r("type_pass.sh") or r("type_orchestrator.sh"):          # Phase-1 typing sweep
        return "TYPE"
    return ("SELECT" if r("similar_chunk.py") else "MATCH" if r("codex exec")
            else "INTEGRATE" if r("tools/integrate.py") else "")

_CAST = re.compile(r'\*\([A-Za-z0-9_]+\s*\*\)\(\(?[A-Za-z_][A-Za-z0-9_]*[^)]*?\+\s*0x')
def typing():
    """Phase-1 typing progress: offset-casts remaining in game src (the un-typed debt) + functions still
    holding casts. Tracks a baseline (max seen) so we can show % converted since tracking began."""
    def build():
        casts = files = 0
        for c in glob.glob(os.path.join(INNER, "src/game_*.c")):
            try:
                n = len(_CAST.findall(open(c).read()))
            except OSError:
                n = 0
            if n:
                files += 1; casts += n
        bf = "/tmp/typing_baseline.txt"; base = casts
        try:
            base = max(casts, int(open(bf).read().strip()))
        except Exception:
            pass
        try:
            open(bf, "w").write(str(base))
        except OSError:
            pass
        return {"casts": casts, "files": files, "base": base,
                "pct": round((base - casts) / base * 100, 1) if base else 0}
    return cached("typing", 20, build)

def collect():
    pr = progress()
    return {"updated": time.strftime("%H:%M:%S"), "progress": pr, "active": active(),
            "commits": recent_commits(), "nearmiss": nearmiss(), "permuter": permuter(),
            "cycle": cycle_status(), "cycle_matched": cycle_matched(),
            "rom": rom_status(), "tree": tree_status(),
            "history": progress_history(), "runway": runway(), "phase": phase_status(),
            "typing": typing()}

# Decouple data collection from the request path: ONE background thread refreshes the snapshot on a
# fixed cadence, serializing it once. do_GET just writes the pre-built bytes — so client count never
# drives git/pgrep load and a slow rebuild never blocks a request. (Collectors keep their own cached()
# TTLs, so each git/pgrep still runs at most once per its TTL even though the refresher loops faster.)
REFRESH = 2.5
_snapshot_json = json.dumps({"updated": "starting…"}).encode()
def _refresher():
    global _snapshot_json
    while True:
        try:
            snap = collect()
            sample_history(snap["progress"])
            _snapshot_json = json.dumps(snap).encode()
        except Exception:
            pass
        time.sleep(REFRESH)

HTML = r"""<!doctype html><html><head><meta charset=utf-8><meta name=viewport content="width=device-width,initial-scale=1"><title>Conker decomp</title>
<style>
:root{color-scheme:dark}
body{background:#0d1117;color:#c9d1d9;font:13px/1.5 ui-monospace,Menlo,monospace;margin:0;padding:16px}
h1{font-size:16px;margin:0 0 6px}.sub{color:#8b949e;font-size:11px;margin-bottom:14px}
.statusbar{display:flex;flex-wrap:wrap;gap:8px;align-items:center;margin-bottom:14px;font-size:12px}
.badge{padding:3px 9px;border-radius:5px;font-weight:bold;white-space:nowrap}
.badge.ok{background:#23863633;color:#3fb950;border:1px solid #2386364d}
.badge.bad{background:#6e253055;color:#f85149;border:1px solid #da3633}
.badge.neutral{background:#21262d;color:#adbac7;border:1px solid #30363d}
.grid{display:grid;grid-template-columns:1fr 1fr;gap:14px}@media(max-width:900px){.grid{grid-template-columns:1fr}}@media(max-width:560px){body{padding:10px}h1{font-size:14px}.big{font-size:18px}.card{padding:10px}.kv{gap:10px}.worker{gap:6px}.fn span{font-size:10px}}
.card{background:#161b22;border:1px solid #30363d;border-radius:8px;padding:12px}
.card h2{font-size:12px;text-transform:uppercase;letter-spacing:.5px;color:#8b949e;margin:0 0 10px}
.bar{height:18px;background:#21262d;border-radius:4px;overflow:hidden;margin:3px 0 8px}
.bar>i{display:block;height:100%;background:linear-gradient(90deg,#1f6feb,#388bfd)}
.bar.byte>i{background:linear-gradient(90deg,#238636,#2ea043)}
.prow{display:flex;justify-content:space-between;font-size:11px;color:#8b949e}
.worker{display:flex;align-items:center;gap:8px;padding:5px 0;border-bottom:1px solid #21262d}
.sc{min-width:42px;text-align:center;font-weight:bold;border-radius:4px;padding:2px 0}
.sc0{background:#238636;color:#fff}.scl{background:#9e6a03;color:#fff}.sch{background:#6e2530;color:#fff}.scn{background:#30363d;color:#8b949e}
.fn{flex:1;min-width:0;overflow:hidden}.fn b{color:#e6edf3}.fn span{color:#6e7681;font-size:11px}
.tag{font-size:10px;padding:1px 6px;border-radius:10px}
.tag.working{background:#1f6feb33;color:#58a6ff}.tag.matched{background:#23863633;color:#3fb950}.tag.idle{background:#30363d;color:#8b949e}
.nm{display:flex;gap:6px;align-items:flex-end;min-height:96px;margin-top:12px}
.nm>div{flex:1;display:flex;flex-direction:column;justify-content:flex-end;text-align:center;min-width:0}
.nm .b{background:#388bfd;border-radius:3px 3px 0 0;min-height:2px;max-height:56px}
.nm small{display:block;color:#8b949e;font-size:10px;margin-top:4px;line-height:1.2}
.cm{padding:3px 0;border-bottom:1px solid #21262d;font-size:12px}.cm b{color:#3fb950}.cm span{color:#6e7681}
.big{font-size:22px;font-weight:bold;color:#e6edf3}.kv{display:flex;gap:16px;flex-wrap:wrap;margin-top:6px}
.kv div{color:#8b949e;font-size:11px}.kv b{color:#c9d1d9;font-size:14px;display:block}
.badge.phase{background:#132035;color:#58a6ff;border:1px solid #1f6feb}
.dot{display:inline-block;width:7px;height:7px;border-radius:50%;background:#58a6ff;margin-right:5px;animation:pulse 1s infinite}
@keyframes pulse{0%,100%{opacity:1}50%{opacity:.15}}
#hist{background:#0a0e14;border-radius:4px}
</style></head><body>
<h1>Conker's Bad Fur Day — decomp pipeline</h1>
<div class=statusbar id=statusbar>connecting…</div>
<div class=grid>
  <div class=card style="grid-column:1/-1">
    <h2>Progress</h2>
    <div id=prog></div>
  </div>
  <div class=card style="grid-column:1/-1"><h2>Progress history — this branch</h2><div style="position:relative"><div id=hist style="width:100%;height:140px"></div><div id=htip style="position:absolute;display:none;top:3px;pointer-events:none;background:#161b22;border:1px solid #30363d;border-radius:4px;padding:3px 7px;font-size:11px;line-height:1.4;white-space:nowrap;z-index:5"></div><span style="position:absolute;top:-2px;right:4px;font-size:9px;color:#484f58;pointer-events:none">100%</span><span style="position:absolute;top:48%;right:4px;font-size:9px;color:#484f58;pointer-events:none">50%</span></div><div class=prow style="margin-top:5px;gap:16px;font-size:11px"><span style="color:#388bfd">●&nbsp;functions</span><span style="color:#2ea043">●&nbsp;bytes</span><span style="color:#6e7681">hover for values</span></div></div>
  <div class=card><h2>Active workers <span id=acount style=color:#8b949e></span></h2><div id=workers>idle</div></div>
  <div class=card><h2>Recent commits</h2><div id=commits></div></div>
  <div class=card><h2>Near-miss reservoir (re-attempt runway)</h2><div class=nm id=nm></div></div>
  <div class=card><h2>Unmatched runway (by instr size)</h2><div class=nm id=runway></div></div>
  <div class=card><h2>Typing sweep <span style="color:#8b949e;font-size:11px">offset-casts → structs</span></h2><div id=typing></div></div>
  <div class=card><h2>Permuter (backstop)</h2><div class=kv id=perm></div></div>
</div>
<script>
const $=id=>document.getElementById(id);
function scClass(s){return s===null?'scn':s===0?'sc0':s<=15?'scl':'sch'}
function fmtAge(s){return s==null?'':s<60?s+'s ago':s<3600?Math.floor(s/60)+'m ago':Math.floor(s/3600)+'h ago'}
function statusbar(d){const r=d.rom||{},c=d.cycle||{},t=d.tree||{};
 const rc=r.ok===true?'ok':r.ok===false?'bad':'neutral';
 const rt=r.sha1?`ROM ${r.ok?'✓':'✗'} ${r.sha1.slice(0,8)}${r.age!=null?' · '+fmtAge(r.age):''}`:'ROM —';
 const ct=c.cycle?`Cycle ${c.cycle} · round ${c.round}/${c.rounds} · ${d.cycle_matched||0} this cycle`:'idle';
 const tt=t.inflight==null?'':t.inflight>0?`${t.inflight} in-flight`:'tree clean';
 const ph=d.phase?`<span class="badge phase"><span class=dot></span>${d.phase}</span>`:'';
 return `${ph}<span class="badge ${rc}">${rt}</span><span class="badge neutral">${ct}</span>${tt?`<span class="badge neutral">${tt}</span>`:''}<span style=color:#6e7681>updated ${d.updated}</span>`;}
function renderHistory(h){
 if(!h||!h.length){$('hist').innerHTML='';return}
 const W=600,H=140,n=h.length,x=i=>n<2?W/2:i/(n-1)*W,y=v=>H-v/100*H;
 const iso=t=>new Date(t*1000).toISOString().slice(0,10);
 const pl=(k,c)=>`<polyline fill="none" stroke="${c}" stroke-width="2" vector-effect="non-scaling-stroke" points="${h.map((p,i)=>x(i).toFixed(1)+','+y(p[k]).toFixed(1)).join(' ')}"/>`;
 const grid=[25,50,75,100].map(g=>`<line x1="0" y1="${y(g)}" x2="${W}" y2="${y(g)}" stroke="#21262d"/>`).join('');
 $('hist').innerHTML=`<svg viewBox="0 0 ${W} ${H}" preserveAspectRatio="none" style="width:100%;height:140px;display:block;background:#0a0e14;border-radius:4px">${grid}${pl('b','#2ea043')}${pl('f','#388bfd')}<line id=hcur x1="0" y1="0" x2="0" y2="${H}" stroke="#6e7681" stroke-width="1" vector-effect="non-scaling-stroke" style="display:none"/></svg>`;
 const el=$('hist');el._h=h;
 if(!el._bound){el._bound=1;const tip=$('htip');
  el.onmousemove=e=>{const d=el._h;if(!d||!d.length)return;const r=el.getBoundingClientRect();
   const fx=(e.clientX-r.left)/r.width;let i=Math.round(fx*(d.length-1));i=Math.max(0,Math.min(d.length-1,i));const p=d[i];
   const cur=$('hcur');if(cur){cur.setAttribute('x1',fx*600);cur.setAttribute('x2',fx*600);cur.style.display='';}
   tip.style.display='block';tip.style.left=Math.max(2,Math.min(r.width-140,e.clientX-r.left-35))+'px';
   tip.innerHTML=`<b>${new Date(p.t*1000).toISOString().slice(5,16).replace('T',' ')} UTC</b><br><span style="color:#388bfd">functions ${p.f}%</span> · <span style="color:#2ea043">bytes ${p.b}%</span>`;};
  el.onmouseleave=()=>{tip.style.display='none';const c=$('hcur');if(c)c.style.display='none';};}
}
function renderRunway(rw){
 if(!rw||!rw.order){return}
 const mx=Math.max(1,...rw.order.map(k=>rw.bins[k]));
 const le=rw.bins['≤100']+rw.bins['101–200']+rw.bins['201–400'];
 $('runway').innerHTML=rw.order.map(k=>`<div><div class=b style="height:${Math.round(rw.bins[k]/mx*56)}px;background:#1f6feb"></div><small>${rw.bins[k]}<br>${k}</small></div>`).join('')+`<div style="align-self:center;color:#8b949e">Σ${rw.total}<br>≤400i: ${le}</div>`;}
function pbar(o,seg){return `<div style="font-size:11px;margin-bottom:2px">${seg}</div>
 <div class=bar><i style="width:${o.fpct}%"></i></div><div class=prow><span>${o.cf}/${o.tf} funcs</span><span>${o.fpct}%</span></div>
 <div class="bar byte"><i style="width:${o.bpct}%"></i></div><div class=prow><span>${o.cb.toLocaleString()}/${o.tb.toLocaleString()} bytes</span><span>${o.bpct}%</span></div>`}
async function tick(){
 let d; try{d=await (await fetch('/state.json')).json()}catch(e){$('statusbar').textContent='offline';return}
 $('statusbar').innerHTML=statusbar(d);
 const p=d.progress;
 $('prog').innerHTML=`<div class=big>${p.overall.fpct}% funcs · ${p.overall.bpct}% bytes</div>
   <div style="margin:8px 0">${pbar(p.game,'game')}</div>
   <div class=prow style="margin-top:8px"><span>init ${p.init.fpct}%/${p.init.bpct}%b</span><span>debugger ${p.debugger.fpct}%/${p.debugger.bpct}%b</span><span>overall ${p.overall.cf}/${p.overall.tf}</span></div>`;
 renderHistory(d.history);renderRunway(d.runway);
 const t=d.typing;if(t)$('typing').innerHTML=`<div class=big>${t.casts.toLocaleString()} casts left</div><div class=bar style="margin:3px 0 6px"><i style="width:${t.pct}%;background:linear-gradient(90deg,#8957e5,#a371f7)"></i></div><div class=prow><span>${t.files} functions to type</span><span>${t.pct}% converted</span></div>`;
 const w=d.active||[];$('acount').textContent=w.length?`(${w.filter(x=>x.status=='working').length} working)`:'';
 $('workers').innerHTML=w.length?w.map(x=>`<div class=worker>
   <div class="sc ${scClass(x.best)}" title="latest ${x.latest}">${x.best===null?'—':x.best}</div>
   <div class=fn><b>${x.func}</b> <span>${x.file} · ${x.instrs?x.instrs+'i':'?'} · ${x.iters}it${x.latest!=null&&x.latest!==x.best?` · now ${x.latest}`:''}</span></div>
   <div class="tag ${x.status}">${x.status}</div></div>`).join(''):'idle — no active run';
 $('commits').innerHTML=(d.commits||[]).map(c=>`<div class=cm><b>+${c.n??'?'}</b> <span style="color:${c.kind==='type'?'#a371f7':'#3fb950'}">${c.kind||'match'}</span> ${c.cycle?`<span style="color:#388bfd">c${c.cycle}</span>`:''} <span>${c.when}</span> ${c.hash}</div>`).join('')||'—';
 const nm=d.nearmiss.bands,mx=Math.max(1,...Object.values(nm));
 $('nm').innerHTML=Object.entries(nm).map(([k,v])=>`<div><div class=b style="height:${Math.round(v/mx*56)}px"></div><small>${v}<br>${k}</small></div>`).join('')+`<div style="align-self:center;color:#8b949e">Σ${d.nearmiss.total}</div>`;
 const pm=d.permuter;$('perm').innerHTML=`<div><b>${pm.cracked}</b>cracked</div><div><b>${pm.backlog}</b>backlog</div><div><b>${pm.seeded}</b>seeded</div><div><b>${pm.live}</b>live procs</div>`;
}
tick();setInterval(tick,3000);
</script></body></html>"""

class H(http.server.BaseHTTPRequestHandler):
    def log_message(self, *a):
        pass
    def do_GET(self):
        try:
            if self.path.startswith("/state.json"):
                body = _snapshot_json            # pre-built by the refresher; no work on this thread
                ct = "application/json"
            else:
                body = HTML.encode(); ct = "text/html"
            self.send_response(200); self.send_header("Content-Type", ct)
            self.send_header("Content-Length", str(len(body))); self.end_headers()
            self.wfile.write(body)
        except (ConnectionResetError, BrokenPipeError):
            pass            # client (browser) dropped the connection — ignore, keep serving
        except Exception:
            pass

class _Server(socketserver.ThreadingTCPServer):
    allow_reuse_address = True
    daemon_threads = True            # don't let in-flight requests block shutdown

if __name__ == "__main__":
    _snapshot_json = json.dumps(collect()).encode()           # warm the first snapshot synchronously
    threading.Thread(target=_refresher, daemon=True).start()  # then refresh on a fixed cadence
    with _Server(("", PORT), H) as httpd:
        print(f"dashboard: http://localhost:{PORT}  (CONKER_REPO={REPO})")
        httpd.serve_forever()
