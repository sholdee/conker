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
- `%lo`-advance fusion depends on whether the preceding stores leave the pointer at
  a RUNTIME value: a target that fuses `addiu vN,vN,K` onto a constant-address base
  (instead of folding K into `%lo(D_xxxx+K)`) only does so when an earlier REAL
  (non-unrolled) loop already left the pointer in a register at a runtime value. If
  your zeroing/init of that base is UNROLLED (constant trip count, e.g. 3 decreasing
  stores), IDO has no live runtime pointer, so EVERY advance form (`q+=K`, `q=q+K`,
  `((T*)q)[-1]`, `q-N`) folds the K into a fresh `lui;addiu %lo(D_xxxx+K)` instead of
  reusing the zero-store register. Unsteerable from C when the init is unrolled; the
  sibling that fuses has a real loop, not an artifact you can reproduce — bail.
- Single- vs double-precision from the LITERAL TYPE: a float operation against a
  bare decimal literal (e.g. `x * 3.64`) promotes to DOUBLE (`cvt.d.w`/`mul.d`/
  `trunc.w.d`); writing the literal with an `f` suffix (`3.64f`) keeps it single
  (`mul.s`). Use the `f`-suffixed literal when the asm stays single-precision.
- Dividing a float by an INT literal (`x/2`) preserves a real `div.s` by 2.0;
  using a FLOAT literal (`x/2.0f`) makes IDO -O2 strength-reduce to `mul.s` by the
  reciprocal (0.5). Pick the literal form that matches the asm's div vs mul.
- Doubling a float: `x + x` (self-add) emits `add.s fN,fN`, whereas `2.0f * x`
  emits a `mul.s` by a materialized 2.0 constant. Use `x + x` when the asm doubles
  via add rather than multiply.
- Unsigned modulo: `x % NU` (unsigned literal, or an unsigned `x`) emits `divu`;
  a signed `x % N` emits `div`. Type the operand/literal to match divu vs div.
- A `-1` sentinel stored to a field: an `s8`/`s16` field emits `li reg,-1`,
  whereas a `u8`/`u16` field masks the constant to `li reg,0xff`/`0xffff`. Pick
  the field's signedness to match the `-1` vs masked immediate in the asm.
- Unsigned-int-to-float: a `(u32)` cast on the integer source reproduces the
  unsigned conversion idiom (`bgez`, `lui 0x4F800000`, `add.s` 2^32 correction),
  even when the value is loaded via `lbu`. A signed cast omits the correction.
- Always-false low-byte sign test: when the asm tests a byte value with `andi
  reg,0xFF; bgez` (an unsigned masked value compared `< 0`, always false), write
  the condition as `(v & 0xFF) < 0`. A `(s8)v` cast instead emits a sign-extend
  `sll/sra` pair and a real signed branch; the `& 0xFF` form keeps the masked
  unsigned value with the (vacuous) `bgez`.

## Return values
- A value still live in v0 (int) or f0 (float) at `jr ra` usually means the
  function RETURNS it. Add an explicit `return <that value>;` to force it — this
  also pins the value's register and often fixes downstream allocation.
- Branch-sense from `slt`+`beqz`: a `slt at,a0,X; beqz at,->body` runs the body
  when `a0 < X`, so the source condition is `a0 < X` (NOT `>=`). Writing the
  inverted `>=`/`!=` form flips the only diff to `bnez` vs `beqz`; match the
  comparison direction to the asm's beqz/bnez to fix a single inverted-branch diff.
- Early-return ordering: `if (temp == 0) return 0; <body>; return temp;`
  preserves `temp`'s register across the body (`bnez v0; move v1,v0`) and gives a
  fallthrough `move v0,zero`. The inverted `if(temp!=0){...return temp;} return 0;`
  flips to `beqz` and adds an instruction. Pick the form matching the branch shape.
- Null-guard return-default: `if (ptr != 0) return *ptr_field; return 0;` (the
  non-null-deref-first, default-last form) emits an EAGER `move v0,zero` BEFORE the
  branch, then OVERRIDES v0 via the field load (`lbu`/`lw`) on the non-null path —
  matching a target that primes the zero return and patches it on the taken side.
  Inverting to `if (ptr == 0) return 0; return *field;` flips the branch sense and
  drops the eager-zero priming.
- Post-call `bnez v0` => the POINTER-return path is the FALL-THROUGH: when a
  function ends `r = call(arg); if(!r){...; return &D_glob;}` and the asm emits
  `bnez v0,->skip` after the `jal`, the &global (non-null) return must be the
  trailing EARLY-RETURN inside the `if(!r)` block, NOT an else-branch or a named
  `ret` local — both of those regress with an extra `move v0,v1`. Make the null
  (taken) path the early-return body and let the other path fall through.

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
- All-paths-return-same-constant via branch-likely: when EVERY path through nested
  `if`s ends at `jr ra` with the same value AND the asm sets that value in a `beql`/
  `bnel` delay slot (e.g. `addiu v0,zero,1`), write plain nested `if`s with a SINGLE
  trailing `return K;` (no per-branch return). The branch-likely's delay-slot
  constant IS that shared return; the nested ifs gate only the conditional stores and
  fall through to the one tail. Don't add a `return K;` inside each branch.
- Conditional store-on-change via branch-likely: a `beql`/`bnel` whose delay slot is
  a STORE (e.g. `sb`) to a field — and which may also gate a following call — is the
  "update only if the new value differs from the current" idiom: write
  `if (newval != p->field) { p->field = newval; func(p); }`. The not-equal test
  becomes the likely branch and the field store lands in its delay slot; the call (if
  any) runs only on the changed path.
- A case that should "fall off" returning garbage v0 (matching an EC epilogue)
  needs NO trailing `return` on that path; adding one pins v0 and breaks the match.
- Alloc-and-init returning the call's pointer (`p = alloc(); if(p){init} return p;`):
  when the target keeps the alloc result in v0 throughout (stores use v0, epilogue
  returns v0) with NO copy, OMIT the explicit trailing `return p;` and let the
  function fall through — v0 already holds the call result (or 0 on the null path).
  Both `if(p){...} return p;` and `if(!p) return NULL; ...return p;` force IDO to
  insert a redundant phi-resolution `move v1,v0`/`move v0,v1` pair (large score).
  This extends the "fall off returning v0" idiom to a legitimate pointer return.
- A second call whose RETURN VALUE is discarded but whose DELAY SLOT does work (e.g.
  a store) needs an explicit bare `func();` statement at that point in the source;
  dropping the call because "the value is unused" deletes the delay-slot work too.
- Multiple ZERO float args CSE into one FPU register: passing several `0.0f` args
  makes IDO -O2 collapse them into a SINGLE materialized zero reg (e.g. all -> f2),
  with a single store. When the target keeps TWO distinct zero registers (e.g. f2
  and f12) and a grouped store order, pass literal int `0` (not `0.0f`) for the args
  that should land in the second zero reg — the int-vs-float mix defeats the CSE and
  forces the separate zero register + the target's store grouping.
- A chained `else if` (vs two separate `if`s) is sometimes REQUIRED to fill a `bne`
  delay slot with the default value and turn the second test into a `bnel`
  branch-likely: the fall-through default `li` emits standalone before the bne, and
  the chained second test becomes the likely branch with the loop-init in its delay
  slot. (Converse of the separate-ifs rule: pick chained vs separate to match the
  bne/bnel + delay-slot shape.)
- Merge two `return 0;` tails: a trailing `if (a < K || b < K) return 0; return 1;`
  (short-circuit `||` of two comparisons) makes the FIRST comparison's `bc1t`
  branch straight to the SHARED `jr ra; move v0,zero` epilogue. Two SEPARATE
  `if (a<K) return 0; if (b<K) return 0;` instead emit an inline epilogue for the
  first return-0 (extra instructions) instead of branching to the shared tail. Use
  the `||` form when the asm routes both false paths to one epilogue. (The `>=`/`&&`
  inverse flips the float compare to `c.le.s` — match the asm's `c.lt.s`/`c.le.s`.)
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
- Float truncated to a NARROW int (`(s16)f`): write `(s16)(s32)f` to emit
  `trunc.w.s` followed by the `sll reg,16; sra reg,16` sign-extend-to-16 pair;
  a bare `(s16)f` does not produce the trunc + half-word narrowing sequence.
- High-halfword extraction: write `(x & 0xFFFF0000) >> 16` to emit the `lui
  at,0xffff; and; srl reg,16` triple; a plain `x >> 16` or `(u16)(x >> 16)`
  collapses to a bare `srl` and scores worse. Use the explicit mask form when the
  asm masks the high half before shifting.
- A signed `(s16)` cast on a u16 field forces a signed `lh` load (vs `lhu`) and a
  signed branch (`bgtzl`/`blez`) on its value; use it when the asm sign-extends.
- Force `lbu` (unsigned byte load) vs `lb` on a field the prototype declares signed
  (`s8`) by reading it through `*(u8*)&p->field`; the plain `p->field` emits the
  signed `lb`. (Byte-load analog of the s16/u16 lh/lhu rule.)
- Read a `u8`/`u16` param into a WIDER local (`s32 a = arg2;`) to reproduce a
  word home (`sw`, not `sb`) with no re-masking `andi`; the narrow type would home
  byte-width and re-mask on use.
- A u8-masked loop counter (`i = (u8)(i + 1)` with a plain `i < N` compare) blocks
  IDO -O2 from turning a per-iteration `sll/addu/lw` address recompute into a
  POINTER induction (`addiu sN,sN,stride`): a plain `i++` makes IDO strength-reduce
  to a running pointer, breaking the recompute. The masked form emits exactly one
  `andi tN,sM,0xff; slti at,tN,N; move sM,tN` and keeps the address recompute. Use
  it when the asm recomputes the element address each iteration from a masked index.
- A struct field load read via the typed FIELD (`arg->unkN` with arg typed as the
  real struct ptr) reproduces a base-FIRST add (`addu vN,base,off`), whereas a raw
  `*(s32*)((u8*)arg+N)` byte-deref emits the offset-FIRST add (`addu vN,off,base`).
  Use the typed-field form when the asm adds the base register first.
- Inversely, binding a value to a `u8` local before passing it to a call forces an
  `andi reg,0xff` (mask) right before the `jal` plus a `move a0,reg`; narrow-type
  the local when the target masks an arg into the low byte at the call site.
- Narrow-cast at the CALL SITE (not in the param type) to schedule the masked-byte
  load into the jal DELAY SLOT: declaring a param `s32` and writing the call as
  `f(..., (u8)arg)` lets IDO sink the `lbu off(sp)` into the `jal`'s delay slot,
  whereas declaring the param itself `u8` HOISTS the `lbu` before the controlling
  branch. Use the s32-param + call-site-cast form when the target loads the byte
  arg in the delay slot rather than ahead of the branch.

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
- Defeat DCE of intermediate read-modify-write byte stores to the SAME address
  (e.g. `*p |= 0x80; *p &= 0xBF;` before a final write that overwrites them): IDO
  -O2 drops the dead intermediate stores. Casting the lvalue through `(volatile
  u8*)` keeps every `sb` instruction. Combine with pre-computing the FINAL value
  into a local BEFORE an intervening (also-volatile) store, so the intervening
  store lands at the exact target slot instead of cascading the instruction order.
- Defeat DCE of all-but-last stores to a PLAIN global: IDO -O2 drops every store
  but the last to a bare global. Make each store "observed" by having the NEXT
  statement READ the global back (e.g. `arr[i] = D_glob;` after `D_glob = ...`);
  the read value CSEs to the same register (no reload) so each `sw` stays live.
- Passing `&local` DIRECTLY to multiple calls (no named pointer var) makes IDO
  spill the address to its own 8-aligned temp slot and reload it before the
  later call — matches target spill/reload. A named pointer keeps it in a reg.
- Conversely, routing `&local` through a NAMED pointer var can be used to GROW the
  frame: the named pointer reserves its own extra 8-aligned slot, bumping frame
  size (e.g. 0x28->0x30) and shifting the local onto the target's offset with params
  homed at the incoming arg slots. Use it when the frame is 8 short and the target
  recomputes `addiu aN,sp,off` fresh at each call rather than spilling the address.
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
- A `void*` param CAST INLINE at each use (vs a typed param or a single cached
  typed local) makes IDO SPILL the param to its stack home and RELOAD it at every
  use (`sw aN,off(sp)` once, then `lw tM,off(sp)` per access). A typed param or one
  cached local pointer instead keeps it in a SAVED register (sN), shrinking the
  frame. Keep the param `void*` and cast at each use when the asm spills+reloads it;
  this also keeps the def consistent with an existing `void*` forward decl/callers.
- A u8 param the target spills-then-NARROWS BEFORE saving ra (`sw a2,off(sp); andi
  tN,a2,0xff; move a2,tN` ahead of `sw ra`) wants the param TYPED `u8` (not `s32`):
  the spill-then-mask-before-prologue ordering is exactly IDO's u8-param codegen. An
  s32 param emits the andi/move in a different order with a different base register.
- To home ALL incoming register args (`sw a0,0(sp)`/`a1,4`/`a2,8`/`a3,0xc`) to the
  standard caller arg-save slots WITHOUT allocating a stack frame (a trivial body
  that just spills its args), take the address of the FIRST param
  (`s32 *p = &arg0;`): IDO -O2 -g3 spills/homes every register arg to its standard
  slot with NO frame. Declaring the params with exact types and no address-of
  homes nothing; a varargs signature adds a spurious frame and shifts the offsets.
- To force IDO to emit fresh registers + `move`s (e.g. an XOR-swap), use two
  distinct temp locals rather than reusing one — the extra temp pins the moves.
- To force TWO separate (non-CSE'd) `addu`s of the SAME `base+off` value, compute
  one use via INTEGER arithmetic and the other via POINTER arithmetic: e.g. an
  `lbu` address as `*(u8*)((s32)base + off + k)` but the call-arg as
  `(u8*)off + (s32)base`. Mixing int-cast and pointer-cast of the same sum defeats
  IDO's GCSE, so it emits a separate `addu` per use (e.g. one into a temp for the
  load, one into `a0` in the `jalr` delay slot) instead of one shared add + `nop`.
  The arg's operand order (`addu a0,off_reg,base_reg`) is set by which term is the
  pointer base — make `off` the base (`(u8*)off + base`) to put it first.
- An intermediate named float product (`f32 prod = a * b;`) can stop IDO from
  DUPLICATING an integer load (e.g. an `lb` of a flag) into a branch-LIKELY delay
  slot: without the temp IDO recomputes the load in the likely slot (extra
  instruction); binding the product to a local serializes it so the load happens
  once. Use a dedicated temp for the sub-expression when the asm has no duplicated
  load but your C emits one in a `bnezl`/`beqzl` slot.
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
- Force TWO separate loads of the SAME field (a condition load + a body reload) by
  giving the test and the body DIFFERENTLY-TYPED reads: e.g. condition
  `*(s32*)(arg+off) != 0` (int) and body `*(u8**)(arg+off)` (pointer). Same-typed
  double reads CSE into ONE load cached in a register; the type mismatch defeats CSE
  so IDO emits a fresh reload for the body. Use it when the target loads a field
  twice (a beqz test then a reload) rather than caching the first load.
- Passing a struct BY VALUE reproduces IDO's word-unrolled do-while struct copy
  before a forwarding call; match the callee's by-value signature, don't pass `&`.
- When a near-identical SIBLING func already matches, mirror its exact C structure
  (call order, arg casts via prototype, last-arg literals) — often a 1-try match.
- Local DECLARATION ORDER controls stack-slot assignment: declare an earlier-slot
  local before a temp to land them on the slots the asm expects (e.g. 0x1C/0x18).
- Force a sub-word local onto a 4-ALIGNED slot by OVERSIZING it to an array: a bare
  `s16 x` may land at an odd-of-4 offset (e.g. 0x1E), but the target stores it at a
  4-aligned slot (e.g. 0x1C). Declaring `s16 x[2]` (write/read `x[0]`) bumps the
  alignment to 4 and forces the lower 4-aligned placement, with no change to the
  emitted store width.
- STATEMENT/assignment order steers t-register grouping: assigning all the
  load/computed struct fields FIRST then the constant fields LAST puts loads in one
  t-register band (t6-t9) and constants in another (t0-t3) to match the target;
  the reverse order compiles identically except for swapped t-register names.
- A base pointer (`addiu vN,base,off`) only stays distinct (not folded into
  base-relative `+4`/`+8` loads) if you actually read/write THROUGH that pointer;
  do the field access via `*p` to keep `p` live and force the separate base.
- A NAMED-pointer store materializes a "dead" advance: declaring
  `s32 *temp = (s32*)(child + K);` and storing via `temp[0] = v` makes IDO FOLD the
  store offset (`sw v,K(child)`) yet STILL emit the `addiu vN,child,K` advance into a
  register (the named-pointer idiom forces the base+K to be computed even though no
  use needs it). A plain `*(s32*)(child+K) = v` omits the stray advance. Use the
  named-pointer form when the asm has an otherwise-unexplained `addiu vN,base,K`
  before a store whose offset is already folded. (Confirm the trailing CALL arg is
  the unmodified base, not temp/temp+K — passing temp+K spills the base instead.)
  The same dead-advance trick applies to LOADS, not just stores: reading
  `named_ptr->field` (with `named_ptr = (T*)(base + K)`) folds the read to
  `lw K+off(base)` yet STILL emits the stray `addiu vN,base,K`, while leaving an
  unmodified arg0 in a0 for a same-base store/call. This is the canonical way to
  reproduce an otherwise-unexplained dead base-advance that resists return-value,
  dead-local (DCE'd), and call-arg (mis-allocated regs) interpretations.
- A float param arriving in an INTEGER register (`mtc1 aN,fM` at entry) is still a
  `f32` in the signature — declare it `f32`; IDO emits the int-reg-to-FPU move.
- A param the target loads as a low BYTE of its un-homed caller stack slot wants
  `*((u8*)&arg + 3)` (big-endian byte-3) to emit the exact `lbu off+3(sp)`; neither
  `arg` nor `(u8)arg` produces the `lbu` (both give a full-word `lw`). The HALFWORD
  analog: `*((s16*)&arg + 1)` (big-endian low halfword) emits an `lh off+2(sp)` and
  ALSO defeats CSE — use it to force a SECOND reload of a param IDO would otherwise
  collapse to one load (a plain `arg`/`(s16)arg` re-uses the prior register).
- Decompose a constant multiply to steer the WORKING register: writing `v * K` (a
  literal multiply) vs the shift-subtract identity (`(v<<n) - v`) changes which
  register IDO picks for the subexpression. When a JUSTREG cascade hangs on a
  product's temp, try the other form (e.g. `v * 0x3F` instead of `(v<<6) - v`) — the
  literal-multiply form can move the work onto an arg/`a`-register and resolve it.
- Hoist a `p = &arg->sub` pointer assignment ONCE above an if/switch chain (not
  inside or per-branch) to keep the sub-object base live in a value reg: each branch
  then re-emits `addiu vN,base,off` and reads small offsets off vN, instead of IDO
  folding every access to one big `off(base)`. Per-branch reassignment or struct
  casts let the fold happen; the single hoisted assignment reproduces the separate
  addiu per branch (and reuses vN for both a switch-value move and the pointer).
- To read a sub-byte of a wider struct field the PROTOTYPE doesn't expose (e.g. the
  high byte of a `u16 unkN` accessed as `unkN+1`), cast through a raw byte pointer:
  `*((u8*)arg + 0xNN) & mask` — don't edit the shared header to add the field.
- To force a NARROWER STORE width than a field's declared type (asm uses `sb` where
  the header declares the field `u16`/`s16`, so a plain `field = v` emits `sh`),
  store through a byte-pointer cast of the field's address: `*(u8*)&arg->unkN = v;`
  emits `sb`. Mirror this off a matched sibling whose asm shows the true store width;
  don't edit the shared header to renarrow the field.
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
- A WRONG-width param in a SHARED callee prototype (header says `u8`/`u16` where the
  target's reg has the full `s32` with NO mask) is unfixable from the call site: the
  narrow prototype forces IDO to emit `andi tN,aM,0xff; move aM,tN` (+nop) before the
  `jal`, and NO call-site cast suppresses it. A local redeclaration with the correct
  width is "Incompatible type / redeclaration"; a function-pointer cast bypasses the
  prototype but emits `jalr` instead of `jal`. The only real fix is correcting the
  shared header width — a header-correctness fix, not a C-steering problem. If header
  edits are out of scope, bail (stub) and flag the prototype.
- An EXTRA dead trailing arg at a call site makes IDO reload it from its home slot
  into the `jal` delay slot (and reorders nearby stores) — a large score. Verify
  the true callee arg count from a sibling CALLER's asm (which regs it loads).
- Array-index form `D_xxxx[idx]` is needed for the reloc pattern
  `lui at,%hi; addu at,at,idx; lwc1 %lo(D_xxxx)(at)`. Pointer/byte arithmetic
  (`(u8*)D - n`, `D - arg`) instead materializes a base pointer + `0(reg)` load.
- Array-of-array cast for byte-stride indexing WITHOUT a product temp: when the
  byte form `(Struct*)((u8*)base + idx*size)` gives the right `addu base,index` order
  but an intermediate `off = idx*size;` temp steals a register (e.g. v0) for the
  product, instead `typedef u8 Entry[size]; (*(Entry**)&base)[idx]` reproduces the
  same byte-arithmetic add order while letting IDO keep the product in the index
  register (no extra temp), matching the target's exact allocation.
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
- A global the shared header DECLARES as an aggregate (e.g. `struct160 D_xxxx[]`)
  but the asm dereferences as a POINTER (`lw tN,0(base); addu ...` per access) is
  actually a pointer variable. Read it via `(*(struct160**)&D_xxxx)[i]` (cast the
  symbol's address to pointer-to-pointer) so IDO emits the `lw base` load before
  indexing — without editing the mistyped shared header.
- To deref a struct field the prototype only PARTIALLY declares (e.g. header
  declares `next`@0x18 but not `prev`@0x1C), define a LOCAL tagged struct with
  explicit padding (`struct { u8 pad[0x18]; void *next, *prev; }`) to reach the
  undeclared offsets, rather than editing the shared header.
- Modify an integer PARAM in place (`arg0 += 1; arg1 -= K;`) to reuse the incoming
  aN register as the result; computing into a fresh expression/local instead uses a
  temp (`tN`) and shows up as a register-only diff. Mutate the param when the asm
  writes the updated value back into the same aN.
- In-place forwarder (callee's first param == this func's first param): pass the
  param THROUGH UNCHANGED (`f(arg0, ...)`) so IDO emits NO `move a0,..` (a0 already
  holds it on entry) and leaves the `jal` delay slot a `nop`. Passing a literal `0`
  for that arg instead emits `move a0,zero` (score ~200); a function-pointer cast of
  the callee emits `jalr` instead of `jal` (score ~400). Forward the live param when
  the asm has the bare `jal` + `nop` with no arg move.
- Forwarder that RE-SIGNS its param before the call homes that param: a thin
  forwarder passing an `s16`/`s8` param UNCHANGED to a callee still emits a frame +
  `sw aN,off(sp)` home for it because the source-level sign-extend (`sll/sra`)
  counts as a use that pins/homes the arg under -g3. Declare the param at its true
  narrow signed width and forward it as-is; the home + re-sign pair is expected, not
  a sign you over-narrowed. (Mirror a re-signing sibling forwarder for the layout.)
- Thin wrapper forwarding `arg0 + CONST` to a single call: writing `f(arg0 + K);`
  emits IDO's `or a1,a0,zero; addiu a0,a1,K` (copy the live param into a scratch
  reg, then form `arg0+K` in/around the jal delay slot). This is the standard
  -O2 shape for keeping the original pointer live while passing a constant-biased
  copy — don't introduce a named `tmp = arg0 + K;` local (it homes/reorders).
- Route a CALL RESULT back through the first param: writing `arg0 = f(arg0, ...);
  return arg0;` flows the value through a0 (target emits `move a0,v0` then `move
  v0,a0`); a separate `ret` local lands the value in v1 instead (the only diff).
  Assign the result back into arg0 when the asm round-trips the return value via a0.
- To pin which register holds a deref vs an address (e.g. `*p` -> v1, `&field` -> v0),
  declare the POINTER local FIRST and compute it (`s32 *p = (s32*)(arg+off);`), THEN
  read `v1 = *p`, accessing the pointer's other fields via casts of `p`. Declaring
  the deref value first reverses the two register assignments — IDO allocates in the
  order the locals are computed.
- REASSIGN the SAME local for a second derived value (e.g. recompute `base` for a
  compare) instead of using a fresh `base2`: reusing the local forces IDO to compute
  any still-needed earlier value (e.g. the return addr) EAGERLY before the local's
  register is clobbered. Distinct locals let IDO sink that computation into both
  return paths, adding an instruction. Reuse the local when the asm computes-then-clobbers.
- A field read once and reused across an early store of the SAME base wants the field
  accessed via a typed STRUCT-POINTER member (`arg->field` with arg typed as the real
  struct ptr), not a raw `*(T*)(arg+off)`: the member form keeps the single loaded
  register live across the intervening store, whereas the raw-cast form either
  double-loads the base or defers the store to a later slot.
- Base-pointer BIAS (target does `addiu base,base,K` upfront then NEGATIVE offsets,
  e.g. `dst[-3]..dst[0]`): plain unrolled positive-index `dst[i]` won't trigger it —
  IDO uses positive offsets off one base. Force it by ADVANCING the pointer in source
  (`dst += K;`) and addressing elements as `dst[-K]..dst[0]`; IDO keeps the runtime
  `addiu` because the advanced pointer feeds later statements. Write any field that
  must load through the UN-advanced base (the lazy first read) BEFORE the advance.
- Dead-store scheduling into a delay slot: to make a kept dead store (e.g. `field = 0`
  IDO won't DCE) land in a LATER load's delay slot, make it the LAST statement of its
  block (after the real field writes); an earlier placement schedules it into an
  earlier slot.
- A zero/constant store materialized LAZILY: when the asm defers an `mtc1 zero`
  (or constant build) until just before its store, write that store LAST in source
  even if its memory offset is lower than a neighbor's (e.g. store 0x3C after 0x38).
  Placing the zero/constant store earlier materializes the value early and perturbs
  the surrounding f-register allocation; emitting it last lets IDO build it lazily
  and lands the other constants in the target's registers.
- Walk-loop back-edge: to keep the `bnel vN,end` branch-LIKELY back-edge (reload in
  the delay slot), the loop END must be a SEPARATE end symbol (`%hi/%lo(D_END)` loaded
  into a reg) — i.e. write the bound as the distinct global at the array's end. A
  RELATIVE end (`&arr[N]`) keeps the START base alive and emits `addiu t,base,size;
  bne` (no bnel). Use the separate end-symbol when the asm's back-edge is `bnel`.
- Defeat trip-count unrolling on a POINTER-walk loop WITHOUT losing the pointer bound:
  a `do { } while (p != end)` triggers IDO's runtime unroll (`subu; li; divu; mfhi` +
  duplicated body). A `goto`-based loop instead — body's first read placed at the TOP
  (right after the label), then `p++; if (p != end) goto loop;` at the BOTTOM — yields
  a single-body `bnel vN,end,top; <reload>` with NO unroll. Use the goto form when the
  target walks with one body + a likely back-edge.
- Declaring a nested-if-LOCAL (`s32 u = p->field;`) inside the if-body PULLS that
  field's address computation (`addu`) INSIDE the branch, matching an `addu` emitted
  AFTER the conditional branch; reading the same field before the if hoists the `addu`
  above the branch. Declare it locally inside the body when the asm computes the
  address only on the taken path.
- Constant-bound for-loop to trigger IDO's unroll-by-4 with NO trip guard: write
  `for (i = 0; i < N; i++)` with a literal `N` to get the auto-unrolled body and
  NO `divu`/remainder guard. ANY pointer-bound form (`p != end`, a named end local,
  or `&arr[N]`) either injects a `divu` trip-count guard or fails to unroll; a
  `p < end` form also fails to unroll. Use the literal-count index loop when the
  target unrolls cleanly with no remainder check.
- A cluster of HIGH-offset fields accessed through an explicit base pointer
  (`addiu vN,base,K` then small offsets off vN) wants a SEPARATE cast pointer at
  +K (`struct Bar *p = (struct Bar*)((u8*)arg + K)`) read with LOW offsets, while
  LOW-offset fields use the `arg` base directly (`arg->field`). This reproduces the
  base-pointer home (e.g. a `vN` save across calls / a larger frame) that a flat
  `arg->highfield` (one base + big offsets) does not.
- Same-global first-use-folds-then-later-splits: when a global is read once as a
  direct `%lo` load but LATER reads load its address into a register and deref `[0]`
  (`lw reg,%lo(sym); lwc1 0(reg)`), write the FIRST use as `D_xxxx` and the later
  uses as `(&D_xxxx)[0]`. The `&sym[0]` form forces the load-address-then-deref pair
  for the later occurrences while the first stays a folded `%lo`.
- A branch-LIKELY over a float compare (`c.le.s` + `bc1fl`) naturally emits a
  DUPLICATED store (e.g. `sb zero` once in the delay slot, once unreachable on the
  fall-through) when written as a plain `if/else` whose both arms store the same
  zero/value. Don't hand-dedupe or restructure — the if/else over the likely branch
  produces the duplicate for free.
- Reverse-engineer the TYPES/SIZES of stack-arg locals (and thus the frame size and
  each local's offset) from the CALLEE's asm store widths: a `sh` at the arg pointer
  means `s16[]`, `swc1` means `f32[]`, `sb`/`sw` give `u8`/`s32`. Sizing a local array
  to match the callee's accesses can be the fix that grows/shifts the frame to the
  target's layout.
- Varargs printf-style wrapper: `#include "libc/stdarg.h"` and a `va_arg` copy loop
  give the exact pointer-bump alignment idiom (`(p+3)&~3` / `(p+7)&~3`); size the
  stack buffer so its last element OVERLAPS the arg-home region (e.g. `s32 buf[17]`
  where buf[16] would give the wrong frame size) to land the right frame/offset.

## Diagnosing a FALSE non-zero score
- Jump-table rodata-ref FALSE score: when a switch matches byte-for-byte but the
  scorer still reports a non-zero score, check whether the diff is ONLY the
  compiler-jtbl rodata references — IDO emits the jump table as an anonymous LOCAL
  `.rodata` label, while the target asm references a NAMED global jtbl symbol that
  lives in a SEPARATELY-split rodata file. The differ renders the unresolved
  `.rodata -> .text` jump-table refs (`.rodata+0xN` markers, `%hi/%lo(.rodata)` vs
  `%hi/%lo(jtbl_xxx)`) as diffs, and the score then CASCADES through the following
  GLOBAL_ASM functions in the same object. Re-run the differ with `-R` /
  `--no-show-rodata-refs` (suppresses exactly these compiler-jtbl rodata refs): a
  clean 0 confirms the code is a genuine byte-perfect match. The residual score is
  a rodata-split representation artifact, not a real instruction diff — fixing it
  to 0 on the default invocation would require editing the rodata split YAML/data,
  not the C. Leave the matching C in place and record it as matched.

## Reusing a condition's loaded register as a call arg
- When the `if` tests a GLOBAL directly (`if (D_xxxx) { ... }`, IDO loads it into
  v0 via a `beqz`/`beqzl` likely-branch) and the taken block then passes that same
  global to a call, RE-READ the global into a local temp INSIDE the block
  (`temp = D_xxxx;`) and pass `temp`. IDO reuses the v0 from the condition load and
  emits `move a0,v0` for the call. Loading the global into a local BEFORE the if, or
  storing the condition value in a temp that the `if` tests, instead makes IDO load
  the value directly into a0 (the diff becomes a0-vs-v0 + `nop` vs `move a0,v0`).
  Test the global itself in the `if`, then re-read it inside the block.

## Display-list / macro-built constant words
- Building two display-list words via the F3DEX macro (e.g.
  `gImmp21(dl, G_MOVEWORD, seg, off, &addr)` producing w0=0xDBxxxxxx, w1=addr)
  reproduces IDO's interleaved `lui/lui/addiu/ori` schedule — the macro emits the
  constant word's `ori` AFTER the address's `addiu`. The raw form
  (`dl->words.w0 = 0xDBxxxxxx; dl->words.w1 = addr;`) instead emits the `ori` BEFORE
  the `addiu`, a large scheduling diff. Use the macro form when matching gbi-built
  DL words; don't hand-write the raw word stores.
- DL-store pointer split: to write a record through one pointer (`move v0,a0`) while
  separately advancing the list pointer (`a0 += 8`), use a DISTINCT local for the
  store target and increment the list pointer BEFORE the macro store. A single
  pointer (or `dl2 = arg0++`) coalesces the two and drops the `move v0,a0`. BUT note
  the bail tension: increment-BEFORE-store reproduces the `move v0,a0` yet makes
  IDO's list scheduler HOIST the `addiu aN,aN,8` earlier, while store-first defers
  the addiu correctly but coalesces away the move. These two requirements are
  mutually exclusive across every C form — if that one-instruction schedule placement
  is the only residual, bail, decomp-permuter candidate.

## Conditional load vs copy-propagation
- Default-value-in-delay-slot + conditional load: to reproduce a `move aN,v0`
  default sitting in a `bnez` delay slot FOLLOWED by a conditional load on the
  taken path (`lw v1,0(t0)`) with the untaken path keeping the default (`move
  v1,aN`), write it as a TERNARY on the value, e.g.
  `arg = (cond) ? ((s32*)v)[idx] : v;`. A plain `if/else` lets IDO copy-propagate
  `v` straight into the destination register and DROP the `move`, losing the
  delay-slot default. Use the ternary when the asm keeps the move + conditional load.

## More register-allocation / branch-shape idioms
- Two-sided index CLAMP to a default: write it as `if (idx < 0) idx = 0; else
  if (idx >= N) idx = 0;` to get the target's bgez-skip-then-bnezl shape (a
  `bgez` that skips the low fix, then a likely branch on the high test). Other
  forms collapse or reverse: `idx<0 || idx>=N` and the empty-if
  `if(idx>=0 && idx<N){}else idx=0;` both fold to ONE inverted `bltz`; the nested
  `if(idx>=0){if(idx>=N)...}else...` gives the right tests but REVERSED branch
  order. Use the explicit two-statement `if/else if` clamp.
- A dual-path increment of a global (`G = idx + 1` reached by both a fall-through
  and a call path) wants TWO statements `idx = G; G = idx + 1;` where `idx` is
  ALSO live on the no-call path (e.g. reused in a delay slot): the no-call path
  keeps the live `idx` ($v0) and the call path reloads `G` with its own fused
  `%hi/%lo`, and the store merges. Plain `G = G + 1` routes the value through a
  spare arg reg with an extra move; `G = idx + 1` (without the separate `idx = G`
  read) spills idx to the stack and GROWS the frame.
- A single FUNCTION-SCOPE local assigned INDEPENDENTLY in each branch (same
  variable, different value per arm, no value carried across arms) unifies the
  result onto ONE register (e.g. a2) in every branch WITHOUT cross-branch
  liveness. Declaring the local PER-BLOCK gives a different reg (e.g. v0) per arm;
  sharing it LIVE across branches forces a callee-saved (s0) promotion. Use one
  function-scope local written fresh in each branch when the asm lands the same
  arg register in all arms.
- Bind a now-DEAD register's next consumer to its OWN local to make IDO REUSE that
  dead register: e.g. after a value in v0 is clobbered/spent, declaring the next
  pointer load as its own local (`s32 *p = ...; ... = *p;`) lets IDO reuse the
  freed v0 for the load instead of allocating a fresh temp (t3). Pairs with the
  "void return, flag live in v0 because v0 is later reloaded" shape — the trailing
  pointer load is what frees v0 for reuse.
- Declaring a flag/init local INSIDE the conditional block that first sets it
  sinks its `move reg,zero` init into the TAKEN path (matching a zero-init placed
  after the entry branch), rather than an eager pre-branch init. (Block-scope
  declaration controls WHERE the initializer is scheduled, not just the field-
  address computation.)

## When to BAIL (don't burn iterations)
- IDO canonicalizes an EQUALITY compare to put the LOCALLY-LOADED operand FIRST in
  the `beq`/`bne` regardless of source operand order: `a==b`, `b==a`, `!=`,
  early-return, nested-if, and width/cast variants ALL emit the loaded-local-first
  form (e.g. `beq $v0,$t6`). If the target has the other order (`beq $t6,$v0`),
  rewriting the test as `^` or `-` (`if (idx ^ G)`) DOES flip the operand order but
  reserves a PHANTOM temp register that cascades a t-register rename chain (worse).
  Neither reaches 0 — single-instruction operand-order diff; bail, decomp-permuter.
  (Distinct from the `bnel`/`beql` LIKELY-branch operand-order rule, which IS
  steerable by swapping operands; this canonicalization applies to plain
  `beq`/`bne` equality and is NOT steerable.)

- Callee-saved promotion of a cross-call pure pass-through: when the target carries
  a value across a call in a callee-saved reg (`or sN,v0,zero` in the call's delay
  slot, `or v0,sN,zero` at return, with sN saved/restored + a larger frame), IDO
  -O2 -g3 from C instead SPILLS it to the stack (`sw v0,off`; `lw v0,off`; no sN) —
  it won't burn a callee-saved register for a value used only at the return. Every C
  form (named local, `register`, comma-expr `return (r=..., f(), r)`, `if(1)`-wrap)
  produces the same stack spill; the frame-size + offset cascade is the whole diff.
  Unsteerable from C; bail, decomp-permuter candidate.
- -g3 home of a singly-used call result into the call's own register lineage:
  when the target homes a `jal`/`jalr` result (`sw v0,off` in the delay slot) and
  RELOADS it into v0 before its single use, IDO from a plain `s32 res` local FOLDS
  the home away (no spill, with a v0/v1 swap). Marking `res` volatile forces a home
  but reloads into a FRESH temp at the WRONG offset (not v0), and every address-of /
  self-store / pointer-deref form either folds the home back out or grows the frame.
  IDO won't home a use-once value into a callee register from C — bail (stub),
  decomp-permuter candidate.
- If after ~4-6 iterations the ONLY remaining diff is a single register name
  ('r' markers, everything else identical), or a single instruction's delay-slot
  placement, it is almost certainly an irreducible JUSTREG / instruction-schedule
  case. IDO won't be steered there from C; STOP, record best score, REVERT to the
  stub, and flag it as a decomp-permuter candidate in notes.
- CSE mismatch: when the target re-loads/re-indexes a value but IDO collapses your
  two identical accesses into one (register-only 'r' diffs from the missing
  reload), you cannot force the duplicate load from C. Same bail as JUSTREG.
- v0/a0 split with NO `move a0,v0`: when the target computes a pointer via `addiu
  v0,v0,K` (into v0) yet uses a0 as BOTH the store base (`sw tN,off(a0)`) and the
  jal argument — with no `move a0,v0` linking them — that v0->a0 register split is an
  IDO scheduling artifact unreachable from C. Every C form forces the pointer into ONE
  register: computing it into the call-arg lineage emits `addiu a0,v0,K` (a0, not v0);
  a separate read/write split or a `move` shifts the whole shape. The lone diff is the
  addiu's destination register; bail, decomp-permuter candidate.
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
- Phantom 8-byte stack slot from `&local` to >4-arg calls: passing `&local` to
  several calls that have STACK args (>4 args) can make IDO reserve an unused
  8-aligned temp slot BETWEEN the saved regs and the first local (recomputing
  `addiu aN,sp,off` fresh, no actual spill), landing the local one word too high
  vs a target that places its first local directly after the saves. The slot appears
  ONLY with the stack-arg calls present (3-arg calls drop it) and is unaffected by
  buffer count/type, combined/tagged buffers, decl order, or the casts. Named pointers
  GROW the frame instead. If the target lacks the slot, it is unsteerable from C —
  bail, decomp-permuter candidate.
- Pointer post-increment schedule lock: building successive records through a running
  pointer where the target schedules the bump (`addiu aN,aN,sz`) AFTER each record's
  stores. The only C form keeping distinct snapshot pointers (`p = arg0++`) ALWAYS
  hoists the increment BEFORE the stores; any form that would delay it (`arg0 = p+1`,
  a separate `arg0++` statement) makes IDO fold all stores into one base + offset
  (`sw t,0; sw,4; ...; addiu`), far worse. Coupled with a snapshot-count vs frame-size
  tradeoff (more snapshot locals fix a v0/v1 reg but grow the frame). Unsteerable; bail.
- End-to-end live value with no early C need (Horner `+D` / shared subexpression):
  when the target keeps an arg/array element live in ONE FPU reg across the whole
  function — used in an INLINED early subexpression AND as the final trailing add
  operand — IDO will only load it early if the C creates an early need. If both the
  early producer is inlined-late and the final use is the last op, IDO loads it late
  and instead hoists an unrelated later load into the first load's delay slot,
  cascading into pervasive FPU renames + a swapped load order. You cannot force the
  early load without a named local, which adds a -g3 home and GROWS the frame.
  Unsteerable from C; bail, decomp-permuter candidate.
- Branch-likely duplicated store reusing a call-clobbered register: when the target
  stores a value (e.g. `sh v1,off`) AFTER a `jal` that clobbers that same register
  (so the store reuses a now-dead reg) and keeps the `jal` delay slot a NOP, no C
  form reproduces it. The store-AFTER-call source (`if(...){...}else{call;store}`)
  forces IDO to SPILL the value across the call (sw/reload, +3 instrs, bigger frame);
  the store-BEFORE-call form (`if(...){store;call}else{store}`) matches the frame, the
  branch-likely, AND the duplicated store but fills the jal delay slot with the store
  instead of the target's NOP (one residual diff). Unsteerable; bail, decomp-permuter.
- Branch-likely orientation vs constant-arg-in-delay-slot tension: when the target
  fires a `bnel`/`beql` (likely) AND keeps a constant second arg (`move a1,zero`) in
  the else-call's jal delay slot with a duplicated arg load, the `==K`-fallthrough
  source orientation makes IDO HOIST the cheap constant above the branch (filling the
  delay with the arg load -> plain `bne`, no likely-bit), while the inverted `!=K`
  orientation fires the likely branch but swaps the two call sites and hoists an
  unrelated `lui %hi` into a preceding `beq` delay slot. Neither orientation gets both
  the likely-bit and the in-slot constant; irreducible schedule. Bail, decomp-permuter.
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

## Register-allocation rotation (the unreachable +1 temp shift)
- A small switch (beqz/beq-at chain, no jump table) over 0/1/2 with per-case byte
  RMW + a store case can reach BYTE-IDENTICAL structure (same opcodes/order/
  immediates/symbols) yet leave a uniform +1 temp-register rename in two of three
  cases. Root cause: the target's allocator uses N temps and SKIPS one mid-pool
  (e.g. uses t6,t7,t9,t0,... never t8 -> 9 temps) by COALESCING a later exclusive
  case's value reg onto an earlier case's; the C form yields N+1 temps (no
  coalesce). This rotation does NOT respond to ANY source lever tried: switch vs
  if-chain (if-chain adds li at/bne per case = worse), case BODY reorder (worse),
  field type u8 vs s32-with-(u8*)cast, pointer-var indirection, shared pointer
  local across cases, compound `|=`/`&=` vs explicit `x = x | k`, hoisting the
  load, or a `default:` label — all give the identical 10-temp allocation. When
  only `r` (reg-only) diffs remain and the temp COUNT differs by one with a
  skipped mid-pool register, it is an allocator artifact: BAIL (stub).
- Dual-width access (same field read as both `lbu` and `lw` on different paths):
  declare the field as a UNION of the two widths (`union { s32 w; u8 b; } u4;`) and
  read `u.b` on the byte path, `u.w` on the word path. This matches both access
  widths cleanly without a `*(s32*)&` reinterpret cast and without re-masking.
- Hoist a field LOAD INSIDE a conditional block (after the `bnez`, as the first
  statement of the taken branch) to fix a load-ORDER mismatch in the controlling
  comparison: keeping the load scheduled inside the branch can force IDO to load the
  OTHER compared operand first, fixing a v0-vs-aN load-order diff. Reading the field
  before the if hoists its load above the branch.
- An extra dummy/return local declared BEFORE a stack struct local reserves a
  4-byte slot (plus alignment) ABOVE the struct, growing the frame and pinning the
  struct at the target's offset. Declaring that local AFTER the struct places it
  below (wrong struct offset). Use a before-the-struct local to bump frame size and
  shift the struct up when the frame is a word short. (Pairs with the named-pointer
  frame-grow idiom.)

## When to BAIL (additional schedule/JUSTREG cases)
- Prologue arg-homing order driven by clobber-prep: when the target homes the
  args it clobbers/preps FIRST (e.g. `sw a3; andi a3,0xff; move a3; move a2` as a
  tight group at the TOP, homing a2/a3 before a0/a1) but every C form schedules the
  mask/move LATE (or reloads via `lbu`/`lw`) and homes a0/a1 early, the homing order
  is set by IDO's clobber-prep ordering and is unsteerable from C (tried u8/s8/s32
  arg types, `(u8)`cast vs `&0xFF` vs reassign vs temp, eager arg locals). Bail.
- Return-phi shape when an intervening call SPILLS the result: the `if(p){...}
  return p;` phi idiom assumes p stays in v0 with no spill. If a call inside the
  body (e.g. `memcpy`) spills the result to the stack, IDO reloads OPTIMALLY into v0
  on the non-null path and gives the zero path its own `b epilogue; move v0,zero` —
  whereas the target reloads into v1 then `move v0,v1`. No C form (two-return,
  if/else, goto-merge, struct-ptr return) reproduces the redundant v1->v0 once a
  spill is in play. Single-schedule diff; bail, decomp-permuter candidate.
- Saved-pointer vs array-subscript tradeoff in an indexed walk: a saved element
  pointer `e = &base[idx]` keeps a later same-element access correct (no recomputed
  base) but an array-subscript form recomputes the byte offset (extra `addu`);
  CONVERSELY a named `next = idx+1` local is required to keep the final compare as
  `next*size < LIMIT*size` (inline `idx++`/`idx+1` strength-reduces the compare to a
  scaled form). When both a saved pointer AND a named-next are correct yet a uniform
  register-name cascade + one li-hoist remain, it is JUSTREG/schedule — bail.
- Split lui/addiu cross-pairing between two pointers: when the target emits one
  pointer's `lui` EARLY (hoisted first) but DEFERS its `addiu` to just before the
  loop, while building a second pointer's `lui`+`addiu` eagerly in between (so the
  lui order is `lui p` but the addiu order is `addiu e` first), no C declaration
  order reproduces it. The lui-hoist order and the addiu order stay COUPLED to
  declaration order: declaring p first gives `lui p,e + addiu p,e`; declaring e
  first gives `lui e,p + addiu e,p`. Neither matches a target that splits them (lui
  p but addiu e). Statement reorder, condition-operand swap, separate end local, and
  loop-form changes don't decouple them. Instruction-schedule artifact; bail.
- Folding note for that family: a store whose address equals `base+4` may be
  emitted by the target as its OWN relocated symbol (`%hi/%lo(D_NEXT)`), NOT as
  `%lo(D_base+0x4)`. Match it by declaring a SEPARATE `extern` for the +4 symbol
  and indexing that array; writing `base[i].field_at_4` emits `%lo(D_base+0x4)`
  and scores worse.
- Scheduler-priority hoist of a chain-feeding load vs a constant return: when the
  target loads a constant FIRST (`lui/lwc1`), THEN a struct-pointer (`lw vN,off(a0)`),
  fills that load's delay slot with `li v0,1` (the return value), and only then does
  the long float chain — but IDO instead HOISTS the `lw vN` to the very top (because
  vN feeds a long multi-load float chain, giving it higher list-scheduling priority)
  and pushes `li v0,1` to the END — no source transform steers it. Tried: split
  decl/assign of the pointer temp, scale before/after the load, inline the deref,
  explicit `s32 ret=1; return ret;`, commuted mul operands, reordered stores. All
  stay at the same residual or regress. The constant-return-in-the-delay-slot vs
  chain-priority hoist is an IDO -O2 list-scheduler tie-break source structure cannot
  control. Bail (keep the functionally-correct best candidate); decomp-permuter /
  scheduler-pragma candidate. (Store order of the field copies still MUST match the
  target exactly — reordering them regresses independently of this tie.)
