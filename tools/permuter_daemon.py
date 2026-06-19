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
import glob, json, os, subprocess, sys

REPO = os.path.expanduser("~/conker")
INNER = os.path.join(REPO, "conker")
PERM = "../tools/decomp-permuter"
PY = os.path.expanduser("~/conker/.venv/bin/python3")   # venv python (has permuter deps)
NEARMISS = os.path.join(REPO, ".nearmiss")
NM_DIR = os.path.join(INNER, "nonmatchings")
MAX_PARALLEL = 6          # permuter dirs running at once
THREADS = 2               # -j per permuter

def sh(cmd, cwd=INNER):
    return subprocess.run(cmd, shell=True, cwd=cwd, capture_output=True, text=True)

def imported(func):
    return os.path.isdir(os.path.join(NM_DIR, func))

def cracked(func):
    return bool(glob.glob(os.path.join(NM_DIR, func, "output-0-*")))

def import_new():
    seeds = sorted(glob.glob(os.path.join(NEARMISS, "*.json")))
    n = 0
    for sp in seeds:
        try:
            s = json.load(open(sp))
        except Exception:
            continue
        func, file = s["func"], s["file"]
        if imported(func):
            continue
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
            open(cpath, "w").write(orig.replace(pragma, s["c"], 1))
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

def run(seconds):
    # newest imports first, skip cracked + no-port — so fresh high-value
    # near-misses get the slots, not the never-cracking old hard cases.
    dirs = sorted(
        [d for d in glob.glob(os.path.join(NM_DIR, "func_*"))
         if not cracked(os.path.basename(d)) and not os.path.exists(os.path.join(d, ".noport"))],
        key=os.path.getmtime, reverse=True)
    launched = 0
    for d in dirs[:MAX_PARALLEL]:
        func = os.path.basename(d)
        log = f"/tmp/permd_{func}.log"
        subprocess.Popen(
            f"nice -n 19 timeout {seconds} {PY} {PERM}/permuter.py nonmatchings/{func} "
            f"--best-only --stop-on-zero -j {THREADS} > {log} 2>&1",
            shell=True, cwd=INNER, start_new_session=True)   # detach so they survive the launcher
        launched += 1
    print(f"run: launched {launched} nice'd permuters ({THREADS} threads each, {seconds}s)")

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
    else:
        print(__doc__)
