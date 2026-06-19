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
- To copy a global aggregate BY VALUE into a stack local, declare a TAGGED struct
  (e.g. `struct foo { s32 unk0[6]; }`) for it; an anonymous-struct local triggers
  an "incompatible struct" assignment error on the copy.

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
- Dividing a float by an INT literal (`x/2`) preserves a real `div.s` by 2.0;
  using a FLOAT literal (`x/2.0f`) makes IDO -O2 strength-reduce to `mul.s` by the
  reciprocal (0.5). Pick the literal form that matches the asm's div vs mul.
- Unsigned modulo: `x % NU` (unsigned literal, or an unsigned `x`) emits `divu`;
  a signed `x % N` emits `div`. Type the operand/literal to match divu vs div.
- A `-1` sentinel stored to a field: an `s8`/`s16` field emits `li reg,-1`,
  whereas a `u8`/`u16` field masks the constant to `li reg,0xff`/`0xffff`. Pick
  the field's signedness to match the `-1` vs masked immediate in the asm.
- Unsigned-int-to-float: a `(u32)` cast on the integer source reproduces the
  unsigned conversion idiom (`bgez`, `lui 0x4F800000`, `add.s` 2^32 correction),
  even when the value is loaded via `lbu`. A signed cast omits the correction.

## Return values
- A value still live in v0 (int) or f0 (float) at `jr ra` usually means the
  function RETURNS it. Add an explicit `return <that value>;` to force it — this
  also pins the value's register and often fixes downstream allocation.
- Early-return ordering: `if (temp == 0) return 0; <body>; return temp;`
  preserves `temp`'s register across the body (`bnez v0; move v1,v0`) and gives a
  fallthrough `move v0,zero`. The inverted `if(temp!=0){...return temp;} return 0;`
  flips to `beqz` and adds an instruction. Pick the form matching the branch shape.

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
- A two-constant ternary's operand order controls which `li` is emitted FIRST:
  `(cond)?A:B` lays out `li B` then `li A` (matching `slti/bnez`-fallthrough);
  the inverted condition swaps the two `li`s. Pick the form matching the asm order.
- To force EAGER loading of later call args (e.g. `lbu a2` before a branch, `lbu
  a3` in its delay slot) that surround a conditional, read those globals/fields
  into local temps BEFORE the controlling ternary/if; IDO then interleaves their
  loads with the branch. Computing the condition first defers the arg loads.
- Switch with sparse/negative case labels: IDO SORTS cases ascending and emits the
  beq/beql/bnel chain in that sorted order. Write each label in the form that sorts
  to the target's test order (e.g. `case 0xDE:` not the equal `case -0x22:`); a
  wrong-signed label sorts to the wrong slot, and an if-else-if chain inlines the
  FIRST case body instead of the sorted one. Also: ordering the case BODIES in the
  source (e.g. handled-case, default, shared-cases) can be required to get the exact
  branch layout without spilling a shared `result` local to the stack; a `default`
  that simply falls through needs no explicit test.
- To force a per-iteration reload of a global pointer/value, deref-cast it inline
  IN the loop body; binding it to a local lets IDO hoist it out of the loop.
- Inlining a value in the for-CONDITION (vs a named `count` local) also pins its
  register: the named local can swap which reg holds the bound vs the index `i`.
- abs/trunc intrinsics: use `fabsf` to emit `abs.s`, and an `(s32)` cast on a
  float to emit `trunc.w.s`. `sqrtf` emits a native `sqrt.s` under IDO 5.3.
- A signed `(s16)` cast on a u16 field forces a signed `lh` load (vs `lhu`) and a
  signed branch (`bgtzl`/`blez`) on its value; use it when the asm sign-extends.
- Read a `u8`/`u16` param into a WIDER local (`s32 a = arg2;`) to reproduce a
  word home (`sw`, not `sb`) with no re-masking `andi`; the narrow type would home
  byte-width and re-mask on use.
- Inversely, binding a value to a `u8` local before passing it to a call forces an
  `andi reg,0xff` (mask) right before the `jal` plus a `move a0,reg`; narrow-type
  the local when the target masks an arg into the low byte at the call site.

## Register allocation & evaluation order (the usual "so close" diffs)
- Multiply/commutative operand order matters: `a*b` vs `b*a` changes which FPU
  register is the destination. Match the asm's operand order literally.
- Commutative operand order also controls the LOAD ORDER of the two operands, not
  just the destination reg: writing the product `b*a` (vs `a*b`) makes IDO emit
  `b`'s `lwc1` before `a`'s. When a multiply/add chain's loads come out in the
  wrong order, swap the operands of that term to reorder the `lwc1`s.
- Store each call's result in its OWN dedicated f32 local (not a reused temp) to
  pin the later operand order (`argN*result` -> f2,f0) and the load order of those
  results into the following expression.
- Casting changes BOTH load width and evaluation order: `*(u8*)(p+0xC)` forces
  `lbu` (vs `lh` for an `s16` struct field) and can force the other operand to be
  evaluated first. Use a raw cast to control which side loads first.
- Reuse one register for a repeated value by binding it to a single local used
  everywhere — BUT IDO constant-propagates small literals and may rematerialize
  them anyway (a known unavoidable diff for absolute-address stores).
- Bit packing `x * 65537` => write `(x << 16) + x`, shift-operand first; type the
  source as `s16` when the asm sign-extends (sll/sra pair) before the multiply.
- A conditionally-assigned value spills: `if (cond) x = ...;` makes IDO home `x`
  to the stack (sw/lw) so both paths agree. Rewrite as a ternary
  `x = cond ? A : B;` (and keep any following call UNCONDITIONAL) to keep `x` in a
  register with a `move` default + branch-with-computed-value-in-delay-slot shape.
- A read-modify-write (`x &= ~m;`) loads the lvalue EARLY, steering the scheduler;
  a plain assignment can't reproduce that load order. If the target loads a
  destination before computing, prefer the compound-assignment form.
- A compound `x += A*K` (read-modify-write on an accumulator) emits the
  accumulator-FIRST operand order (`addu dst,x,tmp`) AND schedules the add after a
  nearby store; a plain `x = x + A*K` reverses the operand order and cannot steer
  the schedule. Use `+=` when the target adds the destination in as the first
  operand.
- Group related locals into ONE local struct to keep a store live; separate
  scalar locals get DCE'd while a struct member used later survives.
- Defeat DCE of all-but-last stores to a PLAIN global: IDO -O2 drops every store
  but the last to a bare global. Make each store "observed" by having the NEXT
  statement READ the global back (e.g. `arr[i] = D_glob;` after `D_glob = ...`);
  the read value CSEs to the same register (no reload) so each `sw` stays live.
- Passing `&local` DIRECTLY to multiple calls (no named pointer var) makes IDO
  spill the address to its own 8-aligned temp slot and reload it before the
  later call — matches target spill/reload. A named pointer keeps it in a reg.
- Param homing: a param NEVER homed if only forwarded/used as-is; it IS homed
  (`sw aN,off`) if reassigned. Forward ALL args through to callees to suppress a
  spurious dead-param home; verify against objdump of matched sibling funcs.
- Selective homing in a forwarding/dispatch call: to home ONLY the later param
  (e.g. `sw a1` but NOT `sw a0`), forward the EARLIER arg as the call's argument
  (it passes through a0 with no move and stays un-homed) and leave the later param
  named-but-unused (IDO -g3 homes it at its own arg slot). Passing the later arg to
  the call adds a wrong `move a0,aN`+home; passing nothing/`void` homes BOTH;
  varargs homes ALL arg regs with a larger frame.
- To reproduce a param HOMED to the stack and reloaded on every use, take its
  address into a local (`s32 **pp = &arg0;`) and read through `**pp` each time.
- To force IDO to emit fresh registers + `move`s (e.g. an XOR-swap), use two
  distinct temp locals rather than reusing one — the extra temp pins the moves.
- The OPERAND ORDER of an equality test steers `bnel`/`beql` register order: `a==b`
  vs `b==a` swaps which reg is first in the branch (`bnel b,a` vs `bnel a,b`).
  When a likely-branch's two registers are reversed, flip the comparison operands.
- To pin the LOAD ORDER of fields feeding a call/compare, bind each to its OWN
  named temp in the exact sequence the asm loads them (and bind a value that is
  both compared and stored FIRST so it loads before the others and the store
  reuses it). Reusing one temp or reordering the binds reorders the loads.
- Defeat CSE of a duplicated priming load from C: instead of reading `arg0`
  directly, write `p = &arg0[i];` (with i=0) then deref `p` — the indexed address
  blocks the collapse and forces the separate load IDO's target emits.
- Passing a struct BY VALUE reproduces IDO's word-unrolled do-while struct copy
  before a forwarding call; match the callee's by-value signature, don't pass `&`.
- When a near-identical SIBLING func already matches, mirror its exact C structure
  (call order, arg casts via prototype, last-arg literals) — often a 1-try match.
- Local DECLARATION ORDER controls stack-slot assignment: declare an earlier-slot
  local before a temp to land them on the slots the asm expects (e.g. 0x1C/0x18).
- STATEMENT/assignment order steers t-register grouping: assigning all the
  load/computed struct fields FIRST then the constant fields LAST puts loads in one
  t-register band (t6-t9) and constants in another (t0-t3) to match the target;
  the reverse order compiles identically except for swapped t-register names.
- A base pointer (`addiu vN,base,off`) only stays distinct (not folded into
  base-relative `+4`/`+8` loads) if you actually read/write THROUGH that pointer;
  do the field access via `*p` to keep `p` live and force the separate base.
- A float param arriving in an INTEGER register (`mtc1 aN,fM` at entry) is still a
  `f32` in the signature — declare it `f32`; IDO emits the int-reg-to-FPU move.
- A param the target loads as a low BYTE of its un-homed caller stack slot wants
  `*((u8*)&arg + 3)` (big-endian byte-3) to emit the exact `lbu off+3(sp)`; neither
  `arg` nor `(u8)arg` produces the `lbu` (both give a full-word `lw`).
- To read a sub-byte of a wider struct field the PROTOTYPE doesn't expose (e.g. the
  high byte of a `u16 unkN` accessed as `unkN+1`), cast through a raw byte pointer:
  `*((u8*)arg + 0xNN) & mask` — don't edit the shared header to add the field.
- Plain truthiness (`if (x)`/`if (!x)`) keeps a value already live in a register
  (e.g. v1) across all branch arms; the explicit `x != 0`/`x == 0` form can inject
  a spurious `move v1,v0` (re-materializing the test value). Use bare truthiness
  when the asm reuses the existing register with no extra move.
- To read a struct field that is DECLARED non-float (e.g. `f32`-as-bits or `s32`)
  AS a float pointer, write `**(f32**)&field` — IDO emits `lw ptr; lwc1 0(ptr)`.
  This forces the load-pointer-then-`lwc1` pair when several such fields each hold a
  distinct `f32*` (vs collapsing them into base+offset `lwc1`s off one struct read).
- Param-type tension with an existing PROTOTYPE: if a forward decl types a param
  `s32`, the definition MUST also be `s32` (a `u8` def is "Incompatible type"
  redeclaration). Match the narrowing at the use site/call cast, not the signature.
- An EXTRA dead trailing arg at a call site makes IDO reload it from its home slot
  into the `jal` delay slot (and reorders nearby stores) — a large score. Verify
  the true callee arg count from a sibling CALLER's asm (which regs it loads).
- Array-index form `D_xxxx[idx]` is needed for the reloc pattern
  `lui at,%hi; addu at,at,idx; lwc1 %lo(D_xxxx)(at)`. Pointer/byte arithmetic
  (`(u8*)D - n`, `D - arg`) instead materializes a base pointer + `0(reg)` load.
- Index-add operand order: `base[idx]` emits `addu index,base`, whereas byte
  arithmetic `(Struct*)((u8*)base + idx*size)` emits `addu base,index`. Use the
  byte form when the asm adds the base into the index register (not vice versa).
- Two DIFFERENT element strides off one base (e.g. a *2 stride for 16-bit fields
  and a *4 stride for 32-bit fields, same index): use raw byte-pointer casts
  `((u8*)base + idx*N + offset)` per group to reproduce the distinct scaled adds;
  a single struct-sized `&base[idx]` stride is wrong for both.
- For a NEGATED index, write `0 - v` (binary subtract from 0), not unary `-v`:
  the binary form scales-then-negates (`sll`,`negu`, the order IDO's target uses);
  unary negates-then-scales (wrong order). Same fix for any negate+shift ordering.
- Switch dispatch through a function-pointer table: a local
  `extern void (*D_xxxx[])(void *);` plus `D_xxxx[idx](arg)` reproduces the
  table-load + `jalr`. (See bail note on case-pointer delay-slot hoisting below.)
- An EMPTY if-body with a populated else (`if (cond) {} else x = 0;`) reproduces a
  branch layout where the taken/condition-true path simply skips over the else
  store — use it (don't invert to `if (!cond) x = 0;`) when the asm branches around
  an else-only body.
- A `goto` INTO a following if-block's body merges consecutive same-valued return
  paths: jumping to a label inside the next block forces IDO's tail-merge so several
  `return 0;` paths share ONE epilogue (a `bc1t`-to-shared-ret + `bc1fl`-enter-body
  branch shape) that plain separate `if`s each with their own `return 0;` cannot
  produce.
- To deref a struct field the prototype only PARTIALLY declares (e.g. header
  declares `next`@0x18 but not `prev`@0x1C), define a LOCAL tagged struct with
  explicit padding (`struct { u8 pad[0x18]; void *next, *prev; }`) to reach the
  undeclared offsets, rather than editing the shared header.
- Varargs printf-style wrapper: `#include "libc/stdarg.h"` and a `va_arg` copy loop
  give the exact pointer-bump alignment idiom (`(p+3)&~3` / `(p+7)&~3`); size the
  stack buffer so its last element OVERLAPS the arg-home region (e.g. `s32 buf[17]`
  where buf[16] would give the wrong frame size) to land the right frame/offset.

## When to BAIL (don't burn iterations)
- Callee-saved promotion of a cross-call pure pass-through: when the target carries
  a value across a call in a callee-saved reg (`or sN,v0,zero` in the call's delay
  slot, `or v0,sN,zero` at return, with sN saved/restored + a larger frame), IDO
  -O2 -g3 from C instead SPILLS it to the stack (`sw v0,off`; `lw v0,off`; no sN) —
  it won't burn a callee-saved register for a value used only at the return. Every C
  form (named local, `register`, comma-expr `return (r=..., f(), r)`, `if(1)`-wrap)
  produces the same stack spill; the frame-size + offset cascade is the whole diff.
  Unsteerable from C; bail, decomp-permuter candidate.
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
  No C construct externalizes it. The external rodata jtbl references the asm
  function's internal labels (.L...), so compiling it as C FAILS TO LINK
  (undefined .L refs) — it does NOT silently match the ROM. Leave it as a
  GLOBAL_ASM stub; needs jtbl/asm-processor work, not steering/permuter — BAIL.
- Loop-rotation / strength-reduction of an indexed reload: when the target
  converges every branch onto ONE shared bottom load (or hoists/duplicates an
  `arr[i*k]` reload into branch delay slots) and your C produces the other shape,
  the schedule is driven by IDO's induction-variable rewrite — unsteerable from C.
  Bail (stub); decomp-permuter candidate.
- Switch case-pointer delay-slot hoist: when the target hoists a case body's
  `lui %hi` into the preceding `beq` branch delay slot and keeps that pointer in
  the branch register (reading fields through it), while IDO from your C emits a
  `nop` in the delay slot and computes the `lui` inline at the case body top (in a
  different reg) — no C form (temp before/inside the case, if/else) steers IDO to
  that hoist without over-hoisting or growing the frame. Register-rename + 1-slot
  store shift remains. Bail; decomp-permuter candidate. (Reading the shared operand
  FIRST so its load fills the delay slot can still fix a `beql`->`beq` likely-bit.)
- Aggregate-relative reloc you can't produce: when the target accesses a field via
  a base symbol + addend (e.g. `%lo(D_xxxx+4)`, the +4 element of a 2-element
  aggregate WITHOUT a base pointer), every C layout (array, struct, `(&x)[1]`,
  `*(&x+1)`, volatile) instead makes IDO materialize a base pointer
  (`addiu vN,vN,%lo`; `0(vN)/4(vN)`), and the only clean-layout form references the
  DISTINCT scalar symbol at that address. The linked ROM bytes are identical (same
  resolved address); the divergence is purely object-level relocation
  representation. Bail (stub) — decomp-permuter / reloc-aware match candidate.
- Constant load hoisted ABOVE the prologue saves: when the target schedules a
  float/loop-invariant constant load (`lui at,%hi; lwc1 %lo`) ahead of the prologue
  register saves (`sw ra`, `sw aN`), IDO from every C form emits the integer saves
  first then the constant load. A single swapped pair; unsteerable from C — bail,
  decomp-permuter candidate. (Inlining the constant into its uses is worse — it
  materializes a base pointer instead of the at-relative `lwc1`.)
- Hand-written asm with lazily-scheduled int-to-float arg conversions: when the
  target keeps surplus integer args (`mtc1 aN`) converted lazily/per-use and live
  in FPU regs across the whole function with NO stack frame (`jr ra`, no `addiu
  sp`), IDO from C converts EAGERLY and SPILLS the surplus arg (`sw aN,off(sp)` +
  `lwc1`), allocating a frame; the spill cascades into pervasive FPU renames. Not
  even a permuter candidate (it won't introduce lazy mtc1 or drop the frame). Leave
  as GLOBAL_ASM. (Tell-tale: file comment says "handwritten?", and a no-frame
  matrix/vector transform with args arriving in integer registers.)
- Loop-invariant load hoisted ABOVE the first arg load: when the target emits an
  invariant constant load (e.g. `lwc1 $f2,%lo(D_xxxx)`) BEFORE the first arg load,
  IDO from every C form (`<`/`>`/reversed operands, named local, `||` chain) emits
  the arg load first — a single swapped-instruction diff. Separate `if`s break the
  branch structure instead. Irreducible schedule case; bail, decomp-permuter.
- Loop limit-substitution: when the target keeps a signed index test against an
  immediate (`slti at,sN,LIMIT; bnezl`), but IDO from EVERY C loop form (for /
  while / do-while / goto-SSA, `< LIMIT` vs `<= LIMIT-1`, struct-index vs
  byte-offset vs explicit `(i<<k)+base`, even forcing `i` live after the loop)
  instead MATERIALIZES the trip-count limit in a register and uses an equality
  test (`li sM,LIMIT; bnel sN,sM`), the divergence is IDO's induction/limit-rewrite
  backend pass. The extra bound register cascades into renames + an extra save
  slot + a `move`. An EMPTY warm-up loop may keep `slti`, but any active body
  triggers the rewrite. Unsteerable from C; bail, decomp-permuter candidate.
- IDO never uses `$at` ($1, the assembler temp) as a general compiler temp from C.
  If the target REUSES `$at` for some loads (e.g. holding offset-0/offset-8 copies
  while a named t-reg holds the middle one), no C form (struct member, raw
  pointer+offset casts) reproduces it — IDO allocates sequential `$t`/`$v`
  registers and a `$v1` base instead. Register-only diff; bail (JUSTREG).
- Native 64-bit ops in the target (`ld`/`sd`/`dsll32`/`dsrl`/`dsra32` on a u64)
  are UNMATCHABLE under the project's -mips2/-o32 build: IDO lowers `long long`
  shifts to `__ll_lshift`/`__ull_rshift` helper CALLS, never native d-shifts.
  Bail (stub) unless a -mips3 per-file rule or inline asm is on the table.
  Corollary for 64-bit STORES specifically: a target that zeroes/copies an
  aggregate with native `sd $zero,off` doublewords is unmatchable too — every C
  form (`u64 *`, a tagged `struct{long long d[N];}`, direct `d[i]=0`) SCALARIZES
  into `li tN,0; sw tN,off` pairs (no helper call, just split stores), and the
  split + reg renames are the whole diff. Tell-tale that the project punted: a
  byte-identical sibling left as a raw `asm` segment in the yaml. Bail (stub).
