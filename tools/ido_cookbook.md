# IDO 5.3 -O2 Matching Cookbook

Transferable idioms for matching IDO 5.3 (`-O2 -g3`) codegen, distilled from
matched functions. Read this before iterating; append NEW generalizable idioms
(not function-specific facts) after a batch. Keep entries tight and general.

## Language / syntax (these cause hard compile errors)
- C89 ONLY: declare ALL locals at the TOP of their block, before any statement.
  A mid-block declaration is a "Syntax Error" in IDO's cfe.
- Missing global/callee: add a LOCAL `extern <type> D_xxxx;` or a callee
  prototype at the TOP of your own .c file. Never edit shared headers.
- For an empty/trivial body, declare params with EXACT types (e.g. `(f32,f32,
  s32,s32)`), not `(...)`: a varargs signature adds a spurious -8 stack frame.

## Constants
- Read float/double constants EXACTLY from the `lui` immediate, never guess:
  0x3F000000=0.5, 0x3F400000=0.75, 0x3F800000=1.0, 0x40000000=2.0,
  0x40400000=3.0, 0x40800000=4.0, 0xBF800000=-1.0.
- A single wrong constant shows as a tiny non-zero score on an otherwise-perfect
  diff — check immediates first when score is small.
- IDO -O2 constant-folds `D_xxxx + off` into ONE relocated `%lo(D_xxxx+off)`. If
  the target instead emits a separate base + temp (`lui`/`addiu sN,s0,off`), no C
  form (pointer, index, separate-base) splits the fold — BAIL.
- An all-ones mask: `*(u16*)&x = ...` / `(u16)-1` yields `ori reg,0xFFFF`, whereas
  a plain `-1` yields `li reg,-1`. Cast to the field width when the asm uses `ori`.

## Return values
- A value still live in v0 (int) or f0 (float) at `jr ra` usually means the
  function RETURNS it. Add an explicit `return <that value>;` to force it — this
  also pins the value's register and often fixes downstream allocation.

## Loops
- Backward branch at the bottom of the body => `do { } while (cond);`, not for/while.
- `while (i--)` (implicit `!= 0`) blocks IDO's -O2 loop-unrolling that
  `for(...)` and `while(i != 0)` trigger; it also emits `move/beqz` on the raw
  value instead of an `sltu` boolean. Use it for simple countdown loops.
- `bnel`/`beql` are branch-LIKELY: the delay-slot instruction executes ONLY when
  the branch is taken. Watch for stores/ops that belong to the taken path only.
- A branch-LIKELY (`bnel`) with a delayed `v0=0` often means an `if(cond==1){...}
  else return 0;` wrapper — the explicit else-return-0 produces both. Use two
  SEPARATE `if`s (not `else if`) to keep a middle test as a non-likely `bnez`.
- A case that should "fall off" returning garbage v0 (matching an EC epilogue)
  needs NO trailing `return` on that path; adding one pins v0 and breaks the match.
- To force a per-iteration reload of a global pointer/value, deref-cast it inline
  IN the loop body; binding it to a local lets IDO hoist it out of the loop.
- Inlining a value in the for-CONDITION (vs a named `count` local) also pins its
  register: the named local can swap which reg holds the bound vs the index `i`.
- abs/trunc intrinsics: use `fabsf` to emit `abs.s`, and an `(s32)` cast on a
  float to emit `trunc.w.s`.
- A signed `(s16)` cast on a u16 field forces a signed `lh` load (vs `lhu`) and a
  signed branch (`bgtzl`/`blez`) on its value; use it when the asm sign-extends.

## Register allocation & evaluation order (the usual "so close" diffs)
- Multiply/commutative operand order matters: `a*b` vs `b*a` changes which FPU
  register is the destination. Match the asm's operand order literally.
- Casting changes BOTH load width and evaluation order: `*(u8*)(p+0xC)` forces
  `lbu` (vs `lh` for an `s16` struct field) and can force the other operand to be
  evaluated first. Use a raw cast to control which side loads first.
- Reuse one register for a repeated value by binding it to a single local used
  everywhere — BUT IDO constant-propagates small literals and may rematerialize
  them anyway (a known unavoidable diff for absolute-address stores).
- Bit packing `x * 65537` => write `(x << 16) + x`, shift-operand first; type the
  source as `s16` when the asm sign-extends (sll/sra pair) before the multiply.
- A read-modify-write (`x &= ~m;`) loads the lvalue EARLY, steering the scheduler;
  a plain assignment can't reproduce that load order. If the target loads a
  destination before computing, prefer the compound-assignment form.
- Group related locals into ONE local struct to keep a store live; separate
  scalar locals get DCE'd while a struct member used later survives.
- Passing `&local` DIRECTLY to multiple calls (no named pointer var) makes IDO
  spill the address to its own 8-aligned temp slot and reload it before the
  later call — matches target spill/reload. A named pointer keeps it in a reg.
- Param homing: a param NEVER homed if only forwarded/used as-is; it IS homed
  (`sw aN,off`) if reassigned. Forward ALL args through to callees to suppress a
  spurious dead-param home; verify against objdump of matched sibling funcs.
- To reproduce a param HOMED to the stack and reloaded on every use, take its
  address into a local (`s32 **pp = &arg0;`) and read through `**pp` each time.
- To force IDO to emit fresh registers + `move`s (e.g. an XOR-swap), use two
  distinct temp locals rather than reusing one — the extra temp pins the moves.
- Defeat CSE of a duplicated priming load from C: instead of reading `arg0`
  directly, write `p = &arg0[i];` (with i=0) then deref `p` — the indexed address
  blocks the collapse and forces the separate load IDO's target emits.
- Passing a struct BY VALUE reproduces IDO's word-unrolled do-while struct copy
  before a forwarding call; match the callee's by-value signature, don't pass `&`.
- When a near-identical SIBLING func already matches, mirror its exact C structure
  (call order, arg casts via prototype, last-arg literals) — often a 1-try match.

## When to BAIL (don't burn iterations)
- If after ~4-6 iterations the ONLY remaining diff is a single register name
  ('r' markers, everything else identical), or a single instruction's delay-slot
  placement, it is almost certainly an irreducible JUSTREG / instruction-schedule
  case. IDO won't be steered there from C; STOP, record best score, REVERT to the
  stub, and flag it as a decomp-permuter candidate in notes.
- CSE mismatch: when the target re-loads/re-indexes a value but IDO collapses your
  two identical accesses into one (register-only 'r' diffs from the missing
  reload), you cannot force the duplicate load from C. Same bail as JUSTREG.
- Coupled/cyclic JUSTREG: if fixing one register diff forces a different one (e.g.
  keeping an index live frees one reg but changes a multiply distribution), the
  alloc is cyclically constrained — unsteerable from C. Bail.
- Same-symbol read+write where the target uses SPLIT `lui %hi`/`%lo` with a
  SEPARATE lui for load vs store (huge score, e.g. 900): IDO at -O2 CSEs both into
  one `lui+addiu` pointer and no C form (--, -=, x=x-1, temp, ptr-cast, [0]) splits
  them. NOTE: this is an -O2 codegen quirk, NOT -O3 — a sibling function in the
  same file matching at -O2 proves the file is -O2 (and asm-processor rejects -O3
  anyway). Bail and flag as a decomp-permuter candidate.
- Score inflation: a single extra/missing nop or JUSTREG can 4-byte-shift ALL
  later functions, inflating a per-object score (e.g. 200/630) far above the true
  per-func delta. Judge the func in isolation (objdump its bytes); don't chase the
  inflated number — if the isolated diff is one nop/regname, BAIL.
- Jump-table externalization: the expected .c.o references an EXTERNAL jtbl symbol
  (HI16/LO16 + R_MIPS_PC16 default branch encoded `ffff`), but compiling C makes
  IDO emit a LOCAL .rodata table (R_MIPS_32 entries, baked intra-section branch).
  No C construct externalizes it; the per-object differ never hits 0 though the
  linked ROM matches. Needs separate-rodata/asm-processor handling, not steering
  or decomp-permuter — BAIL.
- Native 64-bit ops in the target (`ld`/`sd`/`dsll32`/`dsrl`/`dsra32` on a u64)
  are UNMATCHABLE under the project's -mips2/-o32 build: IDO lowers `long long`
  shifts to `__ll_lshift`/`__ull_rshift` helper CALLS, never native d-shifts.
  Bail (stub) unless a -mips3 per-file rule or inline asm is on the table.
