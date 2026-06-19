# Conker decompilation

Active work: matching `game` functions to byte-identical IDO 5.3 asm on branch `decomp/game-matches`,
driven by a self-running orchestrator + spare-CPU permuter.

**→ Full operating runbook (the cycle, tools, safety invariants): [`tools/AGENTS.md`](tools/AGENTS.md). Read it before touching the pipeline.**

Critical safety rules (full detail in the runbook):
1. Act ONLY on a workflow's completion **notification** — never `ps`/output checks.
2. Never build / edit src / git while a workflow runs.
3. Force-clean (`rm` the bins) before every ROM check — stale bins give false "ROM OK".
4. The gate is the full ROM sha1 (`4cbadd3c…`); `tools/integrate.py` enforces it — don't hand-commit matches.
