#!/usr/bin/env python3
"""Continuous decomp-permuter pass over harvested near-misses, using spare host
CPU WITHOUT disturbing the orchestrator.

The orchestrator's match agents drop near-miss seeds in ~/conker/.nearmiss/
<func>.json {func,file,score,c}. This daemon:

  import_new   de-stub each new seed, import into decomp-permuter, restore tree.
               TOUCHES THE BUILD TREE — run only BETWEEN orchestrator runs.
  run <secs>   launch nice'd, thread-capped permuters (--stop-on-zero) on every
               imported dir that hasn't cracked yet. SELF-CONTAINED (compiles to
               its own temp dirs) — safe to run DURING an orchestrator run.
  collect      print func|file for every dir that now has an output-0-* winner,
               so the caller can apply + verify + commit (between runs).

Typical coordination between orchestrator runs:
  permuter_daemon.py collect      # harvest last cycle's winners -> commit them
  permuter_daemon.py import_new   # ingest this run's new near-misses
  permuter_daemon.py run 5400     # (re)launch background permuters for next run
"""
import glob, json, os, re, shutil, subprocess, sys, time

REPO = os.path.expanduser("~/conker")
INNER = os.path.join(REPO, "conker")
PERM = "../tools/decomp-permuter"
PY = os.path.expanduser("~/conker/.venv/bin/python3")   # venv python (has permuter deps)
NEARMISS = os.path.join(REPO, ".nearmiss")
NM_DIR = os.path.join(INNER, "nonmatchings")
MAX_PARALLEL = 10         # permuter dirs running at once (24-core host, nice-19; raised 6->10 to work the
                          # import backlog faster AND permute seeds before src-context drifts them to noport)
THREADS = 2               # -j per permuter

def sh(cmd, cwd=INNER):
    return subprocess.run(cmd, shell=True, cwd=cwd, capture_output=True, text=True)

def imported(func):
    return os.path.isdir(os.path.join(NM_DIR, func))

def cracked(func):
    return bool(glob.glob(os.path.join(NM_DIR, func, "output-0-*")))

def import_new():
    # [audit 5] backstop: a SIGKILL between a seed's copy and its finally-restore could leave a seed
    # body in the live tree. import_new runs only on a clean tree (between orchestrator runs), so
    # restore any such leak before we start touching files.
    sh("git checkout -- src/ 2>/dev/null")
    seeds = sorted(glob.glob(os.path.join(NEARMISS, "*.json")))
    n = 0
    for sp in seeds:
        try:
            s = json.load(open(sp))
        except Exception:
            continue
        if s.get("score", 1) == 0:
            continue                       # base-0 seed (matched / object-match-but-ROM-fail): the
                                           # permuter would just load score 0 and exit — never import
        func, file = s["func"], s["file"]
        full = os.path.join(NEARMISS, func + ".full.c")
        if not os.path.exists(full):
            continue                       # no whole-file snapshot -> the extracted body alone won't
                                           # compile (undefined externs/struct fields); skip it
        if imported(func):
            base = os.path.join(NM_DIR, func, "base.c")
            # [audit 8] re-import ONLY if the seed improved since import (its .full.c is newer than the
            # imported base.c); otherwise the permuter keeps permuting a stale body. Same body -> skip.
            if os.path.exists(base) and os.path.getmtime(full) <= os.path.getmtime(base):
                continue
            shutil.rmtree(os.path.join(NM_DIR, func), ignore_errors=True)
        cfile = f"src/{file}.c"
        cpath = os.path.join(INNER, cfile)
        try:
            orig = open(cpath).read()
        except OSError:
            continue
        pragma = f'#pragma GLOBAL_ASM("asm/nonmatchings/{file}/{func}.s")'
        if pragma not in orig:
            continue                       # already matched/destubbed elsewhere
        try:
            shutil.copy(full, cpath)       # the whole compilable best-C file (carries the func's decls)
            asm = f"asm/nonmatchings/{file}/{func}.s"
            r = sh(f"{PY} {PERM}/import.py {cfile} {asm} 2>&1")
        finally:
            open(cpath, "w").write(orig)   # ALWAYS restore the live tree
        if "Done. Imported" in r.stdout and imported(func):
            st = os.path.join(NM_DIR, func, "settings.toml")
            txt = open(st).read().replace('compiler_type = "base"', 'compiler_type = "ido"')
            open(st, "w").write(txt)
            n += 1
            print(f"  imported {func} (seed score {s.get('score','?')})")
    print(f"import_new: {n} new near-misses imported")

def running_funcs():
    """Distinct funcs that currently have a live permuter.py process."""
    r = subprocess.run("ps -eo args", shell=True, capture_output=True, text=True)
    out = set()
    for line in r.stdout.splitlines():
        m = re.search(r"permuter\.py nonmatchings/(func_\w+)", line)
        if m:
            out.add(m.group(1))
    return out

def _stub_set():
    """Funcs still GLOBAL_ASM stubs in src (i.e. NOT yet matched by codex)."""
    s = set()
    # [audit 6/7] recurse src/ (8 subdirs) AND match [^"]+ not [^/]+ so NESTED asm paths
    # (nonmatchings/a/b/func.s) match too — ~1/3 of seeds live under multi-segment dirs; the
    # single-segment flat version missed them, so _eligible would rmtree their still-valid imports.
    for c in glob.glob(os.path.join(INNER, "src", "**", "*.c"), recursive=True):
        try:
            for m in re.finditer(r'GLOBAL_ASM\("asm/nonmatchings/[^"]+/(func_[0-9A-Fa-f]+)\.s"\)', open(c).read()):
                s.add(m.group(1))
        except OSError:
            pass
    return s

def _eligible(exclude):
    # newest imports first, skip cracked / no-port / already-running. Deterministically PRUNE seeds
    # whose func has since been matched by codex (no longer a stub) — they'd just load score-0 and
    # exit, wasting a slot. Keeps the permuter on the real backlog without a manual prune step.
    stubs = _stub_set()
    out = []
    for d in glob.glob(os.path.join(NM_DIR, "func_*")):
        f = os.path.basename(d)
        if f not in stubs:
            shutil.rmtree(d, ignore_errors=True)        # matched since import → prune stale seed
            continue
        if cracked(f) or os.path.exists(os.path.join(d, ".noport")) or f in exclude:
            continue
        # base.c already score 0 in isolation (permuter exits instantly with "Found zero"): nothing
        # to permute — these object-matches-but-ROM-fails were hogging slots from real near-misses.
        log = f"/tmp/permd_{f}.log"
        if os.path.exists(log):
            try:
                if "Found zero score" in open(log).read(1024):
                    continue
            except OSError:
                pass
        out.append(d)
    return sorted(out, key=os.path.getmtime, reverse=True)

def _launch_one(func, seconds):
    log = f"/tmp/permd_{func}.log"
    subprocess.Popen(
        f"nice -n 19 timeout {seconds} {PY} {PERM}/permuter.py nonmatchings/{func} "
        f"--best-only --stop-on-zero -j {THREADS} > {log} 2>&1",
        shell=True, cwd=INNER, start_new_session=True)   # detach so it survives the launcher

def _topup(seconds):
    """Fill free slots up to MAX_PARALLEL without duplicating running funcs."""
    running = running_funcs()
    free = MAX_PARALLEL - len(running)
    launched = 0
    for d in (_eligible(running)[:free] if free > 0 else []):
        _launch_one(os.path.basename(d), seconds)
        launched += 1
    return launched, len(running)

def run(seconds):
    launched, already = _topup(seconds)
    print(f"run: launched {launched} nice'd permuters ({already} already running; "
          f"{THREADS} threads each, {seconds}s)")

PIDFILE = "/tmp/permuter_supervisor.pid"

def supervise(interval=180, per_timeout=3600):
    """Long-running: keep MAX_PARALLEL permuters alive forever, auto-replacing the
    dead/cracked/timed-out with the newest seeds. Launch detached (setsid) once;
    it does NOT import (that touches the build tree) — only permutes what's imported.
    Self-guards via a pidfile so a second launch is a no-op (no shell self-match)."""
    if os.path.exists(PIDFILE):
        try:
            old = int(open(PIDFILE).read().strip())
            os.kill(old, 0)                         # alive?
            print(f"supervise: already running (pid {old}); exiting"); return
        except (ValueError, OSError):
            pass                                    # stale/unreadable → take over
    open(PIDFILE, "w").write(str(os.getpid()))
    print(f"supervise: maintaining {MAX_PARALLEL} permuters (check every {interval}s, "
          f"{per_timeout}s each); pid {os.getpid()}")
    while True:
        launched, running = _topup(per_timeout)
        if launched:
            print(f"supervise: topped up {launched} (was {running} running)", flush=True)
        time.sleep(interval)

def file_of(func):
    """Find the src/game_*.c that still has this func as a GLOBAL_ASM stub."""
    seed = os.path.join(NEARMISS, f"{func}.json")
    if os.path.exists(seed):
        return json.load(open(seed)).get("file")
    r = sh(f'grep -rl "asm/nonmatchings/[^\\"]*/{func}.s" src/', cwd=INNER)
    line = r.stdout.strip().splitlines()
    return os.path.basename(line[0])[:-2] if line else None

def still_stub(func, file):
    if not file:
        return False
    pragma = f'#pragma GLOBAL_ASM("asm/nonmatchings/{file}/{func}.s")'
    try:
        return pragma in open(os.path.join(INNER, f"src/{file}.c")).read()
    except OSError:
        return False

def collect():
    wins = []
    for d in sorted(glob.glob(os.path.join(NM_DIR, "func_*"))):
        func = os.path.basename(d)
        if os.path.exists(os.path.join(d, ".noport")):
            continue
        if not cracked(func):
            continue
        file = file_of(func)
        if not still_stub(func, file):        # already matched/committed — skip
            continue
        src = sorted(glob.glob(os.path.join(d, "output-0-*", "source.c")))[0]
        wins.append((func, file, src))
    for func, file, src in wins:
        print(f"WIN {func} {file} {src}")
    if not wins:
        print("collect: no NEW winners (all cracked dirs already integrated)")

if __name__ == "__main__":
    if len(sys.argv) >= 2 and sys.argv[1] == "import_new":
        import_new()
    elif len(sys.argv) >= 3 and sys.argv[1] == "run":
        run(int(sys.argv[2]))
    elif len(sys.argv) >= 2 and sys.argv[1] == "collect":
        collect()
    elif len(sys.argv) >= 2 and sys.argv[1] == "supervise":
        supervise(*(int(a) for a in sys.argv[2:4]))
    else:
        print(__doc__)
