#!/usr/bin/env python3
"""Lean live dashboard for the Conker decomp pipeline. Read-only; stdlib only.

  python3 tools/dashboard.py [port=8077]   then open http://localhost:8077

Scrapes the live state already emitted by the pipeline (codex logs with SCORE lines,
attempts.tsv, .nearmiss, git, the linker map, permuter dirs) and serves it as a
self-refreshing page. Does not touch the matching pipeline.
"""
import http.server, socketserver, json, os, re, glob, subprocess, time, sys, importlib.util

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
    def build():
        s = {}
        for c in glob.glob(os.path.join(INNER, "src/*.c")):
            try:
                txt = open(c).read()
            except Exception:
                continue
            for m in re.finditer(r'GLOBAL_ASM\("asm/nonmatchings/([^/]+)/(func_[0-9A-F]+)\.s"\)', txt):
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
    chunk = "/tmp/codex_chunk.txt"
    if not os.path.exists(chunk):
        return []
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
        log = f"/tmp/codexm_{func}.log"
        scores, mtime = [], 0
        if os.path.exists(log):
            try:
                txt = open(log).read()
                # ONLY iter_match's own output (line ends in the number); the match prompt
                # contains "SCORE: 0 -> ..." text that must NOT be counted as a real score.
                scores = [int(x) for x in re.findall(r'(?m)SCORE: (\d+)\s*$', txt)]
                mtime = os.path.getmtime(log)
            except Exception:
                pass
        best = min(scores) if scores else None
        instrs = (sizes.get(func, (None, 0))[1] // 4) if func in sizes else None
        # Status from log freshness + score, NOT the src de-stub state (a function is
        # de-stubbed during ALL active work, not just on a match). While Codex is still
        # iterating (fresh log) it's "working" even if it has already hit 0; once the log
        # goes quiet, score 0 = matched, else idle/reverted.
        fresh = (time.time() - mtime) < 90 if mtime else False
        if fresh:
            status = "working"
        elif best == 0:
            status = "matched"
        else:
            status = "idle"
        res.append({"func": func, "file": file, "instrs": instrs, "best": best,
                    "latest": scores[-1] if scores else None, "iters": len(scores),
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
            if len(parts) == 3 and "match" in parts[2]:
                m = re.search(r'match (\d+)', parts[2])
                cyc = re.search(r'\[cycle (\d+)\]', parts[2])
                res.append({"hash": parts[0], "when": parts[1],
                            "n": int(m.group(1)) if m else None,
                            "cycle": int(cyc.group(1)) if cyc else None})
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
            live = subprocess.run("pgrep -f permuter.py | wc -l", shell=True,
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

def collect():
    return {"updated": time.strftime("%H:%M:%S"), "progress": progress(), "active": active(),
            "commits": recent_commits(), "nearmiss": nearmiss(), "permuter": permuter(),
            "cycle": cycle_status(), "cycle_matched": cycle_matched(),
            "rom": rom_status(), "tree": tree_status()}

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
</style></head><body>
<h1>Conker's Bad Fur Day — decomp pipeline</h1>
<div class=statusbar id=statusbar>connecting…</div>
<div class=grid>
  <div class=card style="grid-column:1/-1">
    <h2>Progress (README method)</h2>
    <div id=prog></div>
  </div>
  <div class=card><h2>Active workers <span id=acount style=color:#8b949e></span></h2><div id=workers>idle</div></div>
  <div class=card><h2>Recent matches</h2><div id=commits></div></div>
  <div class=card><h2>Near-miss reservoir (re-attempt runway)</h2><div class=nm id=nm></div></div>
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
 return `<span class="badge ${rc}">${rt}</span><span class="badge neutral">${ct}</span>${tt?`<span class="badge neutral">${tt}</span>`:''}<span style=color:#6e7681>updated ${d.updated}</span>`;}
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
 const w=d.active||[];$('acount').textContent=w.length?`(${w.filter(x=>x.status=='working').length} working)`:'';
 $('workers').innerHTML=w.length?w.map(x=>`<div class=worker>
   <div class="sc ${scClass(x.best)}" title="latest ${x.latest}">${x.best===null?'—':x.best}</div>
   <div class=fn><b>${x.func}</b> <span>${x.file} · ${x.instrs?x.instrs+'i':'?'} · ${x.iters}it${x.latest!=null&&x.latest!==x.best?` · now ${x.latest}`:''}</span></div>
   <div class="tag ${x.status}">${x.status}</div></div>`).join(''):'idle — no active run';
 $('commits').innerHTML=(d.commits||[]).map(c=>`<div class=cm><b>+${c.n??'?'}</b> ${c.cycle?`<span style="color:#388bfd">c${c.cycle}</span>`:''} <span>${c.when}</span> ${c.hash}</div>`).join('')||'—';
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
                try:
                    body = json.dumps(collect()).encode()
                except Exception as e:
                    body = json.dumps({"error": str(e)}).encode()
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

if __name__ == "__main__":
    socketserver.TCPServer.allow_reuse_address = True
    with socketserver.TCPServer(("", PORT), H) as httpd:
        print(f"dashboard: http://localhost:{PORT}  (CONKER_REPO={REPO})")
        httpd.serve_forever()
