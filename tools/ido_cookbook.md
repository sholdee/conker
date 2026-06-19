# IDO 5.3 -O2 Matching Cookbook

Transferable idioms for matching IDO 5.3 (`-O2 -g3`) codegen, distilled from
matched functions. Read this before iterating; append NEW generalizable idioms
(not function-specific facts) after a batch. Keep entries tight and general.

## Language / syntax (compile errors)
- C89 ONLY: declare ALL locals at the TOP of their block, before any statement.
  A mid-block declaration is a "Syntax Error" in IDO's cfe.
- Missing global/callee: add a LOCAL `extern <type> D_xxxx;` or a callee
  prototype at the TOP of your own .c file. Never edit shared headers.
- For an empty/trivial body, declare params with EXACT types (e.g. `(f32,f32,
  s32,s32)`), not `(...)`: a varargs signature adds a spurious -8 stack frame.
- To copy a global aggregate BY VALUE into a stack local, declare a TAGGED struct
  (e.g. `struct foo { s32 unk0[6]; }`) for it; an anonymous-struct local triggers
  an "incompatible struct" assignment error on the copy.
- When the asm body USES an arg (saved/reloaded across calls) but every in-file caller
  invokes it with NO args, a prototyped definition errors ("number of arguments doesn't
  agree") at those call sites. Define the function K&R-style (param declared AFTER the
  empty paren list) so it establishes NO prototype — the no-arg calls compile and the
  body still references the arg. Also drop any preceding `void f(void);` forward decl.
- Param-type tension with a PROTOTYPE: if a forward decl types a param `s32`, the
  definition MUST also be `s32` (a `u8` def is "Incompatible type" redeclaration);
  match the narrowing at the use site/call cast, not the signature. Inverse — when
  the asm REQUIRES the narrow param (e.g. a `u8` entry `andi`/byte-spill) and a
  pre-existing in-file forward decl says `s32` — you must UPDATE that decl too; the
  definition can narrow only once every in-file decl of the function agrees. Edit
  the local/in-file decl, never a shared header.

## Constants
- Read float/double constants EXACTLY from the `lui` immediate, never guess:
  0x3F000000=0.5, 0x3F400000=0.75, 0x3F800000=1.0, 0x40000000=2.0,
  0x40400000=3.0, 0x40800000=4.0, 0xBF800000=-1.0. A single wrong constant shows
  as a tiny non-zero score on an otherwise-perfect diff — check immediates first.
- A single-precision float literal must be written to FULL precision to match the
  low-halfword `ori`: a `f32` is built as `lui reg,%hi; ori reg,%lo`, and a rounded
  literal (e.g. `0.352f`) yields the right `lui` but an `ori` off by 1 in the low 16
  bits. Write the exact decimal that reproduces the mantissa (e.g. `0.352000028f`);
  recover it from the full 32-bit pattern (lui<<16 | ori), not by eyeballing the high
  half. (The `lui`-only rule above catches the high half; this catches the `ori`.)
- IDO -O2 constant-folds `D_xxxx + off` into ONE relocated `%lo(D_xxxx+off)`.
  Inverse: a `%lo` reference at a small offset from a known global may be its OWN
  DISTINCT symbol — when the asm references `%lo(D_at_off)` as a self-contained reloc
  (e.g. a `lhu`/`andi` reading what looks like `D_base+0x2`), declare a SEPARATE local
  `extern T D_at_off[];` and access it directly; reaching it as `D_base[...]+off`
  emits the folded `%lo(D_base+off)` and scores worse. (See BAIL for the unsteerable
  split-base-vs-fold case.)
- An all-ones mask: `*(u16*)&x = ...` / `(u16)-1` yields `ori reg,0xFFFF`, whereas
  a plain `-1` yields `li reg,-1`. Cast to the field width when the asm uses `ori`.
- A `-1` sentinel stored to a field: an `s8`/`s16` field emits `li reg,-1`, whereas
  a `u8`/`u16` field masks it to `li reg,0xff`/`0xffff`. Pick the field's signedness
  to match the `-1` vs masked immediate.
- Single- vs double-precision from the LITERAL TYPE: a bare decimal literal
  (e.g. `x * 3.64`) promotes to DOUBLE (`cvt.d.w`/`mul.d`/`trunc.w.d`); an `f`
  suffix (`3.64f`) keeps it single (`mul.s`).
- Dividing a float by an INT literal (`x/2`) preserves a real `div.s` by 2.0;
  a FLOAT literal (`x/2.0f`) makes IDO strength-reduce to `mul.s` by 0.5. Pick
  the literal form to match the asm's div vs mul.
- Doubling a float: `x + x` (self-add) emits `add.s fN,fN`; `2.0f * x` emits a
  `mul.s` by a materialized 2.0. Use `x + x` when the asm doubles via add.
- Unsigned modulo: `x % NU` (unsigned literal or unsigned `x`) emits `divu`; a
  signed `x % N` emits `div`. Type the operand/literal to match.
- Unsigned-int-to-float: a `(u32)` cast on the integer source reproduces the
  unsigned-conversion idiom (`bgez`, `lui 0x4F800000`, `add.s` 2^32 correction),
  even when loaded via `lbu`. A signed cast omits the correction.
- Always-false low-byte sign test: when the asm tests a byte with `andi reg,0xFF;
  bgez` (masked value compared `< 0`, always false), write `(v & 0xFF) < 0`. A
  `(s8)v` cast instead emits a sign-extend `sll/sra` pair and a real signed branch.
- IDO constant-propagates small literals and may rematerialize them even when bound
  to a single local (a known unavoidable diff for absolute-address stores).

## Return values
- A value still live in v0 (int) or f0 (float) at `jr ra` usually means the function
  RETURNS it. Add an explicit `return <that value>;` to force it — this also pins the
  value's register and often fixes downstream allocation.
- Declare a function `void` (not `s32`) when its callee's result is meant to flow
  straight out: an `s32` return type makes IDO PRESERVE the call result, emitting a
  spurious `move v1,v0` (and/or using v1 where the target uses v0, e.g. in a `beqz`
  delay slot). If the asm uses v0 directly with no such move, type it `void` and let
  v0 pass through (call siblings without `return`).
- A `u8`/`u16` RETURN TYPE truncates v0 with `andi v0,reg,0xFF`/`0xFFFF` right before
  `jr ra`. Declare the function (and any forwarded callee prototype) at that narrow
  width when the asm masks the return; an `s32` return emits no mask. (Return-side
  analog of the narrow-param promotion mask.)
- A case that should "fall off" returning garbage v0 (matching an EC epilogue) needs
  NO trailing `return` on that path; adding one pins v0 and breaks the match.
- Branch-sense from `slt`+`beqz`: `slt at,a0,X; beqz at,->body` runs the body when
  `a0 < X`, so write `a0 < X` (NOT the inverted `>=`/`!=`, which flips `beqz`↔`bnez`).
- Early-return ordering: `if (temp == 0) return 0; <body>; return temp;` preserves
  `temp`'s register across the body (`bnez v0; move v1,v0`) with a fallthrough
  `move v0,zero`; the inverted `if(temp!=0){...return temp;} return 0;` flips to
  `beqz` and adds an instruction. Pick the form matching the branch shape.
- Equality-against-a-NONZERO-constant 0/1 return: `return field == K;` (K!=0) emits
  `xori reg,reg,K; sltiu reg,reg,1`. An `== 0` test collapses to a plain `sltiu
  reg,reg,1` (no xori); a `!=` flips to an `sltu zero,reg`-style test. Use `== K` to
  reproduce the xori.
- Boolean comparison return (`return a < b;`): the BARE comparison-return emits a
  NON-likely `bc1f` (float compare) with `li v0,1` falling THROUGH into ONE shared
  `jr ra`. `if(cond) ret=1; return ret;` emits branch-LIKELY (`bc1fl`); the two-return
  `if(cond) return 1; return 0;` emits the plain `bc1f` but DUPLICATES the epilogue.
  Use the bare comparison-return when the asm tests once and falls through to one `jr ra`.
- Masked-bit 0/1 return (`(field >> n) & 1`): when the asm EAGERLY loads `li v0,1`
  then `bnez ...,->jr ra` (separate epilogue), write the test-FALSE-first
  fall-through-1 form `if (!(field & 1)) return 0; return 1;`. The inverted
  `if(field & 1) return 1; return 0;` emits eager `move v0,zero`+`beqz` (wrong prime);
  the prime-then-demote form regresses with an extra instruction.
- INTEGER two-value compare 0/1 return (`a >= b`): when the asm EAGERLY primes `move
  v0,zero` then `slt at,a,b; bnez at,->jr ra`, then `li v0,1` falling through, write
  `if (a >= b) return 1; return 0;`. The inverted `if(a<b) return 0; return 1;` primes
  1 + `beqz` (worse); the BARE `return a >= b;` collapses into `slt;xori` (no eager
  zero-prime). (Integer-`slt` analog of the float `bc1f` and masked-bit prime rules.)
- Float-vs-ZERO compare with zero as FIRST FPU operand: a strict `return x > 0.0f;`
  compiles to `c.lt.s fZero,fX` (IDO rewrites `x > 0` as `0 < x`, zero on the LEFT);
  the mirror `x <= 0.0f` emits `c.le.s fX,fZero` (zero on the RIGHT). Pick the
  strict/non-strict and `>`/`<=` form to match which operand holds the zero.
- Read-and-clear flag: write `ret = 1; if (field == 0) ret = 0; field = 0; return
  ret;` (prime nonzero, demote on the zero test) — NOT the symmetric if/else. The
  `==0` demote makes IDO emit a `bnel` branch-likely with the CLEARING store (`sb
  zero,off`) in its delay slot; the if/else materializes both constants and stores
  the clear separately.
- Null-guard return-default: `if (ptr != 0) return *ptr_field; return 0;` emits an
  EAGER `move v0,zero` BEFORE the branch, then OVERRIDES v0 via the field load on the
  non-null path. Inverting to `if(ptr==0) return 0; ...` flips the branch sense and
  drops the eager-zero priming.
- Post-call `bnez v0` => the POINTER-return is the FALL-THROUGH: when a function ends
  `r = call(arg); if(!r){...; return &D_glob;}` and the asm emits `bnez v0,->skip`
  after the `jal`, make the null (taken) path the early-return body and let the other
  path fall through. An else-branch or named `ret` local regresses with `move v0,v1`.
- Match-EITHER-of-two-values 0/1 return (`v==A || v==B`): when the asm tests via TWO
  `beql`s that both jump to a SHARED tail priming `li v0,1` (falling through to
  `return 0`), write the NESTED NEGATIVE-test form `if (v != A) { if (v != B) return
  0; } return 1;`. Two positive tests invert to `bnel`; the `||` form emits
  `xori`/`sltiu`. Operand order is canonicalized field-first in `beql t,a` — write the
  VALUE first (`v != p->field`).

## Loops & branches
- Backward branch at bottom of body => `do { } while (cond);`, not for/while.
- `bnel`/`beql` are branch-LIKELY: the delay-slot instruction executes ONLY when the
  branch is taken — watch for stores/ops belonging to the taken path only. A NON-likely
  `beqz`/`bnez` delay-slot instruction ALWAYS executes (both paths): a store sitting in
  a plain branch's delay slot is UNCONDITIONAL — pull it OUT of the conditional in
  source. Putting it inside the if-true block makes IDO emit a LIKELY branch and
  DUPLICATE the store on the else path. Identify which writes are conditional by the
  likely-bit, not by proximity to the if (e.g. `b=a; if(...)c=K;` when `b=a` is in a
  plain-beqz delay slot).
- A likely-branch delay slot that REDEFINES a register (e.g. `bnezl ...; addiu v0,a0,0x28`)
  is NULLIFIED on the not-taken path, so a later load on that fall-through still uses the
  OLD register value (`lhu off(v0)` reads the PRE-delay-slot `v0`, not `a0+0x28`). Source
  such a load from the pre-delay-slot expression, not the pointer the delay slot computes;
  the `!(flag)` test form (not `flag != 0`) gives the bnezl-to-clear shape.
- `while (i--)` (implicit `!= 0`) blocks IDO's -O2 loop-unrolling that `for(...)` and
  `while(i != 0)` trigger; it also emits `move/beqz` on the raw value instead of an
  `sltu` boolean. Use it for simple countdown loops.
- No-unroll vs upward-`slt` mutual exclusion (lookup/match scan): a SINGLE-BODY inner
  loop that counts UP with an index test (`slt at,j,count; bnez at`) generally cannot
  be gotten from C. Every upward `<`-bound form (`for`, `while(j<count)`,
  `do{}while(++j<count)`, `base[j]`, walking pointer, `p != base+count`) makes IDO
  UNROLL 4-way (`andi t,_,0x3` remainder prologue + duplicated early-return bodies).
  The only non-unrolling form is `while(count--)`, but it counts DOWN (wrong bound test).
  Not simultaneously satisfiable; if the only residual, bail (decomp-permuter).
- Constant-bound `for (i = 0; i < N; i++)` with a literal `N` triggers IDO's
  unroll-by-4 with NO `divu`/remainder trip guard. ANY pointer-bound form (`p != end`,
  a named end local, `&arr[N]`) either injects a `divu` guard or fails to unroll; a
  `p < end` form also fails to unroll. Use the literal-count index loop for clean unroll.
- Flip the SAVED-REGISTER coloring of a counter/pointer pair (target wants counter=s0,
  walk-ptr=s1 but for/do-while gives the inverse) by writing
  `init_counter; while(1){ <body>; counter++; ptr+=stride; if(counter==N) break; }`
  with an EXPLICIT bottom break. IDO allocates saved regs in the order locals become
  live: the counter init must stay BEFORE the entry test (`move s0,zero` ahead of the
  leading `beq`), and the pointer init must sit INSIDE the leading guard (its `lui`
  lands in the entry branch's delay slot). A for/do-while reorders these.
- Linked-list search (walk `node=node->next` until a field matches): write a `do{}while`
  ENTRY form so the top emits `beqzl`-likely with `move v0,zero` in its delay slot (the
  not-found default). Inside, load `next = node->next` BEFORE the field compare to get
  `lw v0,nextoff(v1)`-then-compare, giving bottom `bnez v0,->loop` with `move v1,v0`
  (advance) in the delay slot. Write the compare field-FIRST. The entry-load-next-
  before-compare ordering is load-bearing.
- strlen / string-end finder: write the ROTATED do-while `if (*p) { do { p++; }
  while (*p); }` to emit the bottom-test `bnel` with the load HOISTED to `1(base)`
  (next char in the likely-slot). A `while(p[1])` peels the entry test AND is
  off-by-one. Type the param `unsigned char*` so loads are `lbu`.
- Defeat trip-count unrolling on a POINTER-walk WITHOUT losing the bound: `do{}while(p
  != end)` triggers IDO's runtime unroll (`subu; li; divu; mfhi` + duplicated body). A
  `goto`-based loop — body's first read at the TOP after the label, then `p++; if(p !=
  end) goto loop;` at the bottom — yields a single-body `bnel vN,end,top; <reload>`
  with NO unroll.
- Walk-loop back-edge: to keep the `bnel vN,end` LIKELY back-edge, the loop END must be
  a SEPARATE end symbol (`%hi/%lo(D_END)` in a reg). A RELATIVE end (`&arr[N]`) keeps
  the START base alive and emits `addiu t,base,size; bne` (no bnel).
- A u8-masked loop counter (`i = (u8)(i + 1)` with a plain `i < N` compare) blocks IDO
  from turning a per-iteration `sll/addu/lw` address recompute into a POINTER induction
  (`addiu sN,sN,stride`). A plain `i++` strength-reduces to a running pointer; the
  masked form emits one `andi tN,sM,0xff; slti at,tN,N; move sM,tN` and keeps the
  recompute.
- Base-pointer BIAS (target does `addiu base,base,K` upfront then NEGATIVE offsets,
  e.g. `dst[-3]..dst[0]`): plain positive-index `dst[i]` won't trigger it. Force it by
  ADVANCING the pointer (`dst += K;`) and addressing `dst[-K]..dst[0]`; IDO keeps the
  runtime `addiu` because the advanced pointer feeds later statements. Write any field
  that must load through the UN-advanced base BEFORE the advance.
- A branch-LIKELY (`bnel`) with a delayed `v0=0` often means `if(cond==1){...} else
  return 0;` — use two SEPARATE `if`s (not `else if`) to keep a middle test as a
  non-likely `bnez`. CONVERSELY, a chained `else if` is sometimes REQUIRED to fill a
  `bne` delay slot with the default value and turn the second test into `bnel`: the
  fall-through default `li` emits standalone before the bne, and the chained second
  test becomes the likely branch with the loop-init in its delay slot. Pick chained
  vs separate to match the bne/bnel + delay-slot shape.
- All-paths-return-same-constant via branch-likely: when EVERY path ends at `jr ra`
  with the same value AND the asm sets it in a `beql`/`bnel` delay slot (e.g. `addiu
  v0,zero,1`), write plain nested `if`s with a SINGLE trailing `return K;` (no per-
  branch return); the delay-slot constant IS the shared return.
- Conditional store-on-change via branch-likely: a `beql`/`bnel` whose delay slot is a
  STORE (e.g. `sb`) to a field, possibly gating a following call, is the "update only
  if changed" idiom: `if (newval != p->field) { p->field = newval; func(p); }`.
- A second call whose RETURN is discarded but whose DELAY SLOT does work needs an
  explicit bare `func();`; dropping it because the value is unused deletes the
  delay-slot work too.
- Alloc-and-init returning the call's pointer (`p=alloc(); if(p){init} return p;`):
  when the target keeps the alloc result in v0 throughout with NO copy, OMIT the
  explicit trailing `return p;` and fall through — v0 already holds the result (or 0).
  Both `if(p){...} return p;` and `if(!p) return NULL; ...` force a redundant phi
  `move v1,v0`/`move v0,v1`.
- Alloc-then-CLEAR-then-return (`p=alloc(N); bzero(p,N); return p;`): UNLIKE the above,
  when an intervening call clobbers v0, IDO SPILLS the alloc result across it (`sw
  v0,off`; `lw v0,off`) and you MUST write the explicit `return p;`. Pick fall-through
  only when NOTHING clobbers v0 between alloc and return.
- Merge two `return 0;` tails: `if (a < K || b < K) return 0; return 1;` makes the
  FIRST compare's `bc1t` branch to the SHARED `jr ra; move v0,zero`. Two SEPARATE
  `if(a<K)return 0; if(b<K)return 0;` emit an inline epilogue for the first (extra
  instrs). (The `>=`/`&&` inverse flips the float compare to `c.le.s` — match the asm.)
- A `goto` INTO a following if-block's body merges consecutive same-valued return
  paths into ONE epilogue (a `bc1t`-to-shared-ret + `bc1fl`-enter-body shape) that
  plain separate `if`s each with their own `return 0;` cannot produce.
- `&&` short-circuit / nested-if => stacked branch-LIKELY (`beql`) tests, one per
  short-circuited operand. When the tail is a shared epilogue, the `ra`-restore (`lw
  ra,off(sp)`) commonly lands in those `beql` delay slots. Write the test as
  `&&`/nested-if when the asm shows the per-operand twin `beql`s with the ra-reload sunk.
- Two-sided index CLAMP to a default: write `if (idx < 0) idx = 0; else if (idx >= N)
  idx = 0;` for the bgez-skip-then-bnezl shape. `idx<0 || idx>=N` and the empty-if
  `if(idx>=0 && idx<N){}else idx=0;` both fold to ONE inverted `bltz`; the nested
  `if(idx>=0){if(idx>=N)...}else...` gives the right tests but REVERSED branch order.
- Decrement-a-field-if-positive: `if (p->field > 0) p->field--;` on a SIGNED field
  emits the `> 0` test as `blez ...,->skip`. Write the literal `> 0` (not `>= 1` or
  `!= 0`) to get the `blez`.
- An EMPTY if-body with a populated else (`if (cond) {} else x = 0;`) reproduces a
  branch that skips over the else store — use it (don't invert) when the asm branches
  around an else-only body.
- A two-constant ternary's operand order controls which `li` is emitted FIRST:
  `(cond)?A:B` lays out `li B` then `li A`; the inverted condition swaps them.
- Switch with sparse/negative labels: IDO SORTS cases ascending and emits the
  beq/beql/bnel chain in sorted order. Write each label in the form that sorts to the
  target's test order (e.g. `case 0xDE:` not `case -0x22:`); an if-else-if chain inlines
  the FIRST case body instead of the sorted one. Ordering the case BODIES (handled,
  default, shared) can be required to avoid spilling a shared `result` to the stack; a
  `default` that falls through needs no explicit test.
- Two cases with IDENTICAL bodies but BOTH compares needed: use an if/else-if chain,
  NOT a switch — a switch COALESCES same-body arms into one target and DROPS the second
  comparison. Order the if/else-if conditions to match the asm's compare sequence.
- Switch min-subtraction: when the asm normalizes by subtracting the smallest case
  (`addiu v1,v1,-MIN`) then compares against 0/1/2, write `switch(field - MIN)` with
  cases `0/1/2` (NOT absolute labels, which compile to direct compares). The highest
  case carries `default:`.
- Switch dispatch through a function-pointer table: a local
  `extern void (*D_xxxx[])(void *);` plus `D_xxxx[idx](arg)` reproduces the table-load
  + `jalr`. (See BAIL on case-pointer delay-slot hoisting.)
- Counted loop bounded by an ADJACENT distinct end-symbol: `for(i=0;i<N;i++)` synthesizes a WRONG `%lo(D_A+N*stride)` bound reloc, and a pointer-compare `p != &D_B[0]` makes IDO 4x-unroll. Winning shape: a counted `do-while` naming BOTH externs as locals - body reads `D_A[i+k]`, condition `&D_B[0] != &D_A[i]` (uses `D_B` directly as the bound reloc, non-unrolled `bnel`); condition operand order sets the `bnel` rs/rt.
- Assignment-in-for-condition sentinel: `for (i=0; (v = arr[i+off]) != 0; i++)` keeps the sentinel load IN the test (one `lw`+`beqz`), vs pre-loading into a separate local which adds an assignment/register. [banjo-mined]

## Type & access width (loads, stores, casts)
- abs/trunc intrinsics: `fabsf` emits `abs.s`; `(s32)` on a float emits `trunc.w.s`;
  `sqrtf` emits a native `sqrt.s` under IDO 5.3.
- Float truncated to a NARROW int (`(s16)f`): write `(s16)(s32)f` to emit `trunc.w.s`
  then the `sll reg,16; sra reg,16` narrowing pair; a bare `(s16)f` omits it.
- INTEGER left-shift-then-narrow `(s16)(x << n)`: when the asm fuses `sll
  tN,x,(16+n); sra dst,tN,16`, write the `(s16)(x << n)` cast. A plain `x << n` emits
  a single `sll reg,n`. (Integer analog of the float-trunc-narrow rule.)
- High-halfword extraction: `(x & 0xFFFF0000) >> 16` emits `lui at,0xffff; and; srl
  reg,16`; a plain `x >> 16` or `(u16)(x >> 16)` collapses to a bare `srl`.
- Bit packing `x * 65537` => `(x << 16) + x`, shift-operand first; type `s16` when the
  asm sign-extends (sll/sra) before the multiply.
- A signed `(s16)` cast on a u16 field forces a signed `lh` (vs `lhu`) and a signed
  branch (`bgtzl`/`blez`); use it when the asm sign-extends.
- Force `lbu` (unsigned) vs `lb` on a field the prototype declares `s8` by reading
  `*(u8*)&p->field`; plain `p->field` emits `lb`. (Byte analog of the s16/u16 rule.)
- A signed-byte (`lb`) read off a global declared `u8[]` needs the s8 typing AND an
  explicit `s8 *p = (s8*)&D_xxxx[i]; ... *p`: materializing the address into a pointer
  local pins (address-in-pointer-reg, value-in-other); indexing the array directly
  (`((s8*)D_xxxx)[i]`) gives the INVERSE register pair.
- Read a `u8`/`u16` param into a WIDER local (`s32 a = arg2;`) to reproduce a word
  home (`sw`, not `sb`) with no re-masking `andi`.
- A param STORED directly as a halfword (`sh`) wants `s32`, NOT `s16`: the `sh` already
  truncates, so `s16` adds a spurious entry sign-extension; `s32` stores straight.
- A shift/arithmetic result then STORED to a byte field must be held in an `s32` local,
  not `s16`: an `s16` local re-truncates and emits a spurious `sll;sra` before the `sb`.
- Declare a param `s32` and write the mask INLINE at its use (`arg3 & 0xFF`) rather
  than typing it `u8`, when the asm has NO prologue narrow-entry: a `u8` param forces
  an extra entry-`andi` + a homed store; the `s32`+inline-mask keeps it wide and masks
  only at the use site. Do NOT re-mask an already-`u8`/`u16` param when scaling/indexing
  it (`arg * K`, NOT `(arg & 0xFF) * K`): the explicit `& 0xFF` emits a REDUNDANT andi
  and shifts the scale onto the wrong register.
- Narrow-cast at the CALL SITE (not in the param type) to schedule the masked-byte load
  into the jal DELAY SLOT: declaring a param `s32` and writing `f(..., (u8)arg)` sinks
  the `lbu off(sp)` into the slot, whereas a `u8` param HOISTS it before the branch.
  (Inversely, binding a value to a `u8` local before a call forces an `andi reg,0xff`
  + `move a0,reg` right at the `jal`.)
- A struct field via the typed FIELD (`arg->unkN`) reproduces a base-FIRST add (`addu
  vN,base,off`), whereas a raw `*(s32*)((u8*)arg+N)` byte-deref emits offset-FIRST
  (`addu vN,off,base`). Use the typed form when the asm adds the base first.
- A float param arriving in an INTEGER register (`mtc1 aN,fM` at entry) is still `f32`
  — declare it `f32`; IDO emits the int-reg-to-FPU move.
- A param loaded as a low BYTE of its UN-homed caller slot wants `*((u8*)&arg + 3)`
  (big-endian byte-3) to emit `lbu off+3(sp)`; `arg`/`(u8)arg` give a full `lw`. The
  HALFWORD analog `*((s16*)&arg + 1)` emits `lh off+2(sp)` AND defeats CSE (forces a
  SECOND reload of a param). CONVERSELY, once a forwarder HOMES its own args, passing
  an `s32` arg to a `u8`-param callee (or `(u8)arg`) yields `lbu off+3(sp)` directly,
  with no byte-3 cast.
- To read a sub-byte of a wider field the prototype doesn't expose (e.g. high byte of
  `u16 unkN`), cast through a raw byte pointer: `*((u8*)arg + 0xNN) & mask`. Don't edit
  the shared header.
- To force a NARROWER STORE width than a field's declared type (asm `sb` where header
  says `u16`/`s16`): store through a byte-pointer cast `*(u8*)&arg->unkN = v;`. Mirror
  off a matched sibling; don't renarrow the shared header.
- To read a field DECLARED non-float (`f32`-as-bits/`s32`) AS a float, write
  `**(f32**)&field` — IDO emits `lw ptr; lwc1 0(ptr)`, forcing the load-pointer-then-
  `lwc1` pair (vs collapsing to base+offset `lwc1`s off one struct read).
- Dual-width access (same field read as both `lbu` and `lw` on different paths):
  declare it a UNION `union { s32 w; u8 b; }` and read `u.b`/`u.w` per path — matches
  both widths without a reinterpret cast and without re-masking.
- To deref a struct field the prototype only PARTIALLY declares (e.g. `next`@0x18 but
  not `prev`@0x1C), define a LOCAL tagged struct with explicit padding
  (`struct { u8 pad[0x18]; void *next, *prev; }`); don't edit the shared header.

## Globals & indexing
- Array-index form `D_xxxx[idx]` is needed for the reloc pattern `lui at,%hi; addu
  at,at,idx; lwc1 %lo(D_xxxx)(at)`. Pointer/byte arithmetic (`(u8*)D - n`, `D - arg`)
  materializes a base pointer + `0(reg)` load instead.
- A global the header DECLARES as an aggregate (`struct160 D_xxxx[]`) but the asm
  dereferences as a POINTER (`lw tN,0(base); addu...`) is a pointer variable: read it
  via `(*(struct160**)&D_xxxx)[i]` so IDO emits the `lw base` before indexing. A global
  the header DECLARES as a plain SCALAR (`s32 D_xxxx;`) but the asm INDEXES is actually
  an array: reach it via `(&D_xxxx)[i]` (or `*(&D_xxxx + i)`), which emits the
  `%hi/addu/%lo`-indexed load against the base symbol. Neither edits the header.
- Index-add operand order: `base[idx]` emits `addu index,base`; byte arithmetic
  `(Struct*)((u8*)base + idx*size)` emits `addu base,index`. Use the byte form when the
  asm adds the base into the index register.
- Scaled-index as the LEFT addu operand (target `addu dst,scaled_index,base`, result
  in a fresh reg): write `*(T*)(idx * sizeof(Struct) + (s32)base)` with the index term
  FIRST. `base[idx]`/`((Struct*)base)[idx]` puts the base-derived value left and lands
  the wrong register.
- Array-of-array cast for byte-stride indexing WITHOUT a product temp: when the byte
  form `(Struct*)((u8*)base + idx*size)` gives the right `addu base,index` order but an
  `off = idx*size` temp steals a register, use `typedef u8 Entry[size];
  (*(Entry**)&base)[idx]` — same add order, product stays in the index register.
- Fold the element-size scale INTO an odd-stride multiply: when the asm computes a BYTE
  offset directly (e.g. `812*idx` for a u16[] with stride 812=406*2) via one sll/subu/
  addu folded into the base, write `*(u16*)((u8*)base + 812*idx)`. The element-index
  form `base[406*idx]` emits a SEPARATE `<<1` scale.
- Two DIFFERENT element strides off one base (e.g. *2 for 16-bit, *4 for 32-bit fields,
  same index): use raw byte-pointer casts `((u8*)base + idx*N + offset)` per group; a
  single struct-sized `&base[idx]` stride is wrong for both.
- For a NEGATED index, write `0 - v` (binary subtract from 0), not unary `-v`: the
  binary form scales-then-negates (`sll`,`negu`); unary negates-then-scales. Same fix
  for any negate+shift ordering.
- Array-scan strength-reduction wants the INDEX form, not an explicit walking-pointer local:
  `((u8*)D_glob)[i*stride+off]` lets IDO reduce the per-iter address to a walking pointer
  (`addiu p,p,stride`, no sll/multu) AND DEFER the base load (`lw p,%lo(D_glob)`) into the
  guard's `blezl` (branch-likely) delay slot — pinning the count/pointer reg pair. An explicit
  `p = D_glob; p++` local forces an EAGER base load + plain `blez` (wrong reg pair); `&D_glob[i]`
  doesn't reduce at all (sll/addu). (Inverse of the masked-counter-blocks-induction rule.)
- Distinct `addiu vN,v0,K` + small-offset store (vs a folded `K+m(v0)`): null-check the SOURCE global DIRECTLY (`if (D_glob != 0)`, not a cached temp) to pin it in v0, AND compute the offset pointer into its OWN local via `u8*` arithmetic (`q = (T*)((u8*)D_glob + K)`). A temp null-check, `temp += K`, or `temp[1]` all fold or reuse v0.

## Register allocation & evaluation order (the usual "so close" diffs)
- Multiply/commutative operand order matters: `a*b` vs `b*a` changes which FPU register
  is the destination — match the asm's order literally. It ALSO controls the LOAD ORDER
  of the two operands: `b*a` (vs `a*b`) makes IDO emit `b`'s `lwc1` before `a`'s. When a
  multiply/add chain's loads come out wrong, swap the term's operands.
- Pointer-base term FIRST in a multi-term integer add: in `base + C + (idx << k)`,
  write the POINTER BASE first so IDO keeps it the first `addu` operand. Leading with
  the shifted term reverses the operands.
- Reassign a computed result back INTO a local that already held one of its operands to
  REUSE that operand's register as the destination (e.g. `hi = (hi << 16) | lo;` emits
  `or v0,t,t` reusing `hi`'s register). A fresh local lands the result in a new temp.
- A compound `x += A*K` (RMW accumulator) emits accumulator-FIRST operand order (`addu
  dst,x,tmp`) AND schedules the add after a nearby store; a plain `x = x + A*K` reverses
  the order and can't steer the schedule. Similarly a RMW (`x &= ~m;`) loads the lvalue
  EARLY, steering the scheduler; prefer the compound form when the target loads a
  destination before computing.
- Casting changes BOTH load width and evaluation order: `*(u8*)(p+0xC)` forces `lbu`
  (vs `lh` for an `s16` field) and can force the other operand evaluated first.
- Store each call's result in its OWN dedicated f32 local (not a reused temp) to pin
  the later operand order (`argN*result` -> f2,f0) and the load order into the next
  expression. To pin the LOAD ORDER of fields feeding a call/compare, bind each to its
  OWN named temp in the exact sequence the asm loads them (bind a value that is both
  compared and stored FIRST). Reusing one temp or reordering the binds reorders loads.
- Force REUSE of a product across two consumers: bind a `field*global` product to a
  shared `f32 prod` and use it in both. Separate inline expressions RELOAD the global
  and RECOMPUTE the multiply per use. (An intermediate named float product can also
  stop IDO from DUPLICATING an integer load into a branch-LIKELY delay slot — bind the
  sub-expression to a temp when the asm has no such duplicated load.)
- To force IDO to emit fresh registers + `move`s (e.g. an XOR-swap), use two distinct
  temp locals rather than reusing one — the extra temp pins the moves.
- A conditionally-assigned value spills: `if (cond) x = ...;` homes `x` to the stack so
  both paths agree. Rewrite as a ternary `x = cond ? A : B;` (keep any following call
  UNCONDITIONAL) to keep `x` in a register with a `move` default + computed-value-in-
  delay-slot.
- STATEMENT/assignment order steers t-register grouping: assigning all the
  load/computed fields FIRST then constant fields LAST puts loads in one t-band (t6-t9)
  and constants in another (t0-t3); the reverse swaps the t-register names only.
- Local DECLARATION ORDER controls stack-slot assignment: declare an earlier-slot local
  before a temp to land them on the slots the asm expects.
- Source-ASSIGNMENT order wins over asm LOAD order for v0/v1 coloring: IDO colors two
  fields by the order their LOCALS are first assigned, NOT by the order the asm emits
  the loads. If the target loads the pointer SECOND yet colors it into v0, assign/read
  the POINTER local FIRST anyway. Don't match source order to the asm's load order —
  match it to the desired coloring.
- To pin which register holds a deref vs an address (`*p`->v1, `&field`->v0), declare
  the POINTER local FIRST (`s32 *p = (s32*)(arg+off);`), THEN read `v1 = *p`. Declaring
  the deref value first reverses the two assignments.
- Pointer-field-into-v0 via a NAMED local: when a pointer loaded from a field
  (`arg->unk98`) must land in v0, bind it to a NAMED local and deref THROUGH it
  (`s32 *p = arg->unk98; ... = *p;`), NOT an inline `*(s32*)arg->unk98` (which lands a
  t-register). The local's WIDTH further steers the reg: a `u16 *` local can claim v0
  where a `u32`/`s32` claimed a t-register (convert byte offsets to element units).
- Widen an index local to free the return register: when a loaded byte indexes a
  returned `base[idx]`, declare the index `s32` (not the field's narrow type) to force
  it into a TEMP (`$v1`) and keep the result in `$v0`. The narrow type can collapse
  onto v0.
- Switch base-pointer into v0 so a constant return eager-primes early: when a switch
  dispatches on `arg0->subptr->bytefield` AND returns a constant, hoist the sub-pointer
  into a NAMED local (`struct X *p = arg0->subptr; switch(p->field...)`). This forces v0
  onto the loaded sub-pointer (`lw v0,off(a0); lbu v1,off(v0)`), freeing v0 to be
  eager-primed `li v0,1` BEFORE the switch. Pair with a SINGLE trailing `return K;`.
- Decompose a constant multiply to steer the WORKING register: `v * K` vs the
  shift-subtract identity (`(v<<n) - v`) changes which register IDO picks; when a
  JUSTREG cascade hangs on a product's temp, try the other form.
- Split the loaded index off the offset chain in `&base->elems[base->idx]`: when the
  target keeps the loaded index in one reg and the byte-offset stride in another,
  introduce a SEPARATE named index local first (`s32 i = arg->idx; &arg->elems[i]`).
  The inline form folds the index load into the offset-chain register.
- Plain truthiness (`if(x)`/`if(!x)`) keeps a value already live in a register across
  all arms; the explicit `x != 0`/`x == 0` form can inject a spurious `move v1,v0`. Use
  bare truthiness when the asm reuses the existing register with no extra move.
- The OPERAND ORDER of an equality test steers `bnel`/`beql` register order: `a==b` vs
  `b==a` swaps which reg is first. (Plain `beq`/`bne` is canonicalized and NOT
  steerable — see BAIL.) When canonicalization blocks the swap, RAISE one side's
  register pressure: write one operand `((u8*)p)[off]` (cast+index) so its extra address
  arithmetic claims the later (t9) register and the bare deref the earlier (t8).
- Capture a field into a local BEFORE an intervening call to spill it across that call:
  `ret = node->unk10; func(node); if (ret) ...` homes `ret` to the stack, fills the
  `jal` delay slot with the spill, and reloads it so the trailing test becomes a `beqzl`
  with the reload in ITS delay slot. Reading the field AFTER the call (or inlining the
  test) re-loads from the struct instead.
- A single FUNCTION-SCOPE local assigned INDEPENDENTLY in each branch (no value carried
  across arms) unifies the result onto ONE register in every branch. Declaring it
  PER-BLOCK gives a different reg per arm; sharing it LIVE across branches forces a
  callee-saved (s0) promotion.
- Bind a now-DEAD register's next consumer to its OWN local to make IDO REUSE that dead
  register (e.g. after v0 is spent, `s32 *p = ...; ... = *p;` reuses the freed v0 for
  the load instead of a fresh t3).
- Declaring a flag/init local INSIDE the conditional block that first sets it sinks its
  `move reg,zero` init into the TAKEN path (vs an eager pre-branch init). Similarly,
  declaring a nested-if-LOCAL (`s32 u = p->field;`) inside the if-body PULLS that
  field's address `addu` INSIDE the branch; reading the same field before the if hoists
  it above the branch.
- Modify an integer PARAM in place (`arg0 += 1;`) to reuse the incoming aN register as
  the result; a fresh expression/local uses a temp instead.
- Route a CALL RESULT back through the first param: `arg0 = f(arg0, ...); return arg0;`
  flows the value through a0 (`move a0,v0` then `move v0,a0`); a separate `ret` local
  lands it in v1.
- REASSIGN the SAME local for a second derived value (e.g. recompute `base` for a
  compare) instead of a fresh `base2`: reusing it forces IDO to compute any still-needed
  earlier value EAGERLY before the register is clobbered. Distinct locals let IDO sink
  that into both return paths (+1 instr).
- A dual-path increment of a global (`G = idx + 1` reached by fall-through AND a call
  path): write TWO statements `idx = G; G = idx + 1;` where `idx` is also live on the
  no-call path. Plain `G = G + 1` routes through a spare arg reg + extra move; `G = idx
  + 1` without the separate read spills idx and grows the frame.
- Chained assignment to order two same-RHS stores: when the asm sets up the rightmost-
  addressed destination's `%lo`/`addiu` FIRST, write `DST_B = DST_A = expr;` (IDO
  evaluates right-to-left, materializing `DST_A`'s address first). Two separate
  statements recompute or reverse the order.
- Hoist a `p = &arg->sub` pointer assignment ONCE above an if/switch chain to keep the
  sub-object base live in a value reg: each branch re-emits `addiu vN,base,off` off vN,
  instead of IDO folding every access to one big `off(base)`. Per-branch reassignment or
  struct casts let the fold happen. (A cluster of HIGH-offset fields through an explicit
  base pointer at +K wants a SEPARATE cast pointer `struct Bar *p = (Bar*)((u8*)arg + K)`
  read with LOW offsets, while LOW-offset fields use `arg` directly — reproduces the
  base-pointer home a flat `arg->highfield` doesn't.)
- A base pointer (`addiu vN,base,off`) only stays distinct (not folded into base-
  relative loads) if you actually read/write THROUGH it; access via `*p` to keep `p`
  live. A field-read-and-shift that folds to a single load off a biased base (e.g.
  `lh 0x21c(base)`) must be evaluated UNCONDITIONALLY, BEFORE any inner `if`; gating it
  behind the branch makes IDO sink the load and re-derive a small offset.
- Biased pointer that must emit `addiu vN,base,K` THEN `lw 0(vN)` (offset-0 deref) when
  ANOTHER nearby field at K+m is also read: bind ONE pointer `T *p = (T*)(base+K);` at
  the function top and reach BOTH fields through it — the far field as `*(u8*)((s32)p+m)`
  (IDO folds it to `lbu (K+m)(base)` but the read PINS `p` in the addiu reg) and the
  offset-0 field as `*p` (emits `lw 0(p)`, addiu preserved). This beats the in-place
  advance (`u8 *t=base; flag=t[K+m]; t+=K; ...*t`), which DOES materialize the addiu but
  forces the flag temp into v1 and shifts the whole t-register pool by one (JUSTREG).
  Separate `base`+`temp` locals OR a struct-field `p->memberat0` both fold the addiu
  away. The single-pointer-two-offsets form satisfies addiu-placement AND register
  coloring simultaneously — the way out of the split-base-vs-fold + JUSTREG tension when
  a second field sits at a nonzero offset off the SAME biased base.
- Shared biased base across both arms of a branch (the `addiu vN,vN,K` lands in the
  BRANCH DELAY SLOT, both paths reuse `vN=base+K`): load the field pointer ONCE, bias it
  once (`s32 *p = base + K;`), and have each arm index OFF it (`p[1]`, `p[3]`). A naive
  per-arm pointer-add emits a separate base load/add per branch.
- A NAMED-pointer store/load materializes a "dead" advance: `s32 *temp = (s32*)(child +
  K); temp[0] = v` FOLDS the store offset (`sw v,K(child)`) yet STILL emits `addiu
  vN,child,K`. Use it for an otherwise-unexplained `addiu vN,base,K` before a folded-
  offset store/load (`named_ptr->field` does the same for reads). INTEGER-address
  variant: a standalone `addiu reg,base,K` immediately OVERWRITTEN is modeled as
  `s32 addr = base + K;` used for later `*(T*)(addr + off)` — IDO keeps the addiu live
  but FOLDS each access back to `(K+off)(base)` off the original base. (Pass the
  unmodified base, not temp/temp+K, to a trailing call arg, or the base spills.)
- Split a COMPOUND offset on a freshly-LOADED pointer (standalone `addiu vN,vN,HI` then
  `sw/sb zero,LO(vN)` rather than one folded `sw zero,HI+LO(base)`): bind a separately-
  typed pointer at `+HI` (`struct T *p = (T*)(load + HI);`) and store at its `+LO`
  field. Writing the full `*(t*)(load + HI+LO) = 0` folds both. A raw cast store at LO
  works if no clean field falls there.
- Group related locals into ONE local struct to keep a store live; separate scalar
  locals get DCE'd while a struct member used later survives.
- Scope-based init sink: declaring a local INSIDE an `if` body (not at function top) confines its init store to the TAKEN path only; read the outer-scope value on the else-path - matches a branch that stores in one arm but not the other. [banjo-mined]
- Chained assignment `a = b = c = v;` (or `arr[0]=arr[1]=arr[2]=v;`) materializes `v` ONCE and propagates via `move`s, vs separate assignments that may re-materialize. Use when the asm sets several fields/registers from one value with moves. [banjo-mined]

## CSE & store/load duplication
- Defeat DCE of intermediate RMW byte stores to the SAME address (`*p |= 0x80; *p &=
  0xBF;` before a final overwrite): cast the lvalue through `(volatile u8*)` to keep
  every `sb`. (Distinct from non-redundant separate bit-ops below.) Combine with
  pre-computing the FINAL value before an intervening (also-volatile) store so it lands
  at the exact target slot.
- Separate bit-op statements => one load-modify-store EACH: distinct RMW statements on
  the SAME field touching DIFFERENT bits (`f &= ~0x2; f |= 0x8; f |= 0x1;`, or `*p |=
  1; *p |= 4;`) each emit their OWN `lhu/sh` (or `lbu/sb`) cycle. These are NOT dead, so
  IDO keeps every one — write each bit op as its own statement (don't fold into a
  combined mask) when the asm shows one load-modify-store per bit change.
- Defeat DCE of all-but-last stores to a PLAIN global (IDO drops every store but the
  last): make each store "observed" by having the NEXT statement READ the global back
  (`arr[i] = D_glob;` after `D_glob = ...`); the read CSEs to the same register so each
  `sw` stays live.
- Dead-store scheduling into a delay slot: to make a kept dead store (`field = 0` IDO
  won't DCE) land in a LATER load's delay slot, make it the LAST statement of its block.
  A zero/constant store materialized LAZILY (`mtc1 zero` just before its store): write
  that store LAST in source even if its offset is lower than a neighbor's; placing it
  earlier materializes the value early and perturbs the f-register allocation.
- Defeat CSE of a field used twice (once into a register, once as a call arg) so the
  SECOND use reloads in the `jal` DELAY SLOT: bind a raw pointer `s32 *p = (s32*)((u8*)
  arg + off);` and read `*p` at BOTH uses. A typed `arg->fieldN` CSEs and emits `move
  a0,reg`. (Handy for an off-prototype offset.)
- Defeat CSE of a duplicated priming load: instead of reading `arg0` directly, write
  `p = &arg0[i];` (i=0) then deref `p` — the indexed address blocks the collapse.
- Force TWO separate loads of the SAME field (condition load + body reload) by giving
  the test and body DIFFERENTLY-TYPED reads: condition `*(s32*)(arg+off) != 0` (int) and
  body `*(u8**)(arg+off)` (pointer). Same-typed reads CSE into ONE load.
- Force a pointer field RELOAD across an intervening call by casting through a VOLATILE
  pointer-to-pointer `*(T *volatile *)((u8*)arg + off)` at BOTH the test and the call:
  the `jal` may modify the struct, so the target reloads `lw aN,off(arg)` (often in the
  delay slot) + `move a1,a0` rather than CSE-caching. A plain struct access CSEs and
  emits `move aN,reg`. Same-width SCALAR no-intervening-call analog: cast only the TEST
  read through `(u16 volatile *)` while leaving the call-arg read plain, to re-emit a
  fresh `lhu` for the arg instead of a cached-value `andi`.
- Force a per-copy RELOAD of a pointer field that intervening stores may ALIAS by
  writing those stores through UNTYPED byte-pointer arithmetic (`*(f32*)((u8*)arg+off) =
  ...`): the raw cast defeats alias analysis, so IDO re-loads the pointer field before
  EACH copy. Typed member stores let IDO prove no-alias and cache once. (Read the
  pointer ONCE as a value for the null-check, again via its address for each copy.)
- Reload a struct-loaded pointer after writing THROUGH it: when a pointer is loaded then
  a field written through it, IDO RE-LOADS it (`lw vN,off(base)`) before the next access
  (can't prove no-alias). Reading via a raw `*(s16*)((u8*)p + off)` byte-cast reproduces
  this; don't try to cache the pointer once.
- Defeat CSE between a COMPARE's operand load and a later SHIFT of the SAME param/field
  by casting the shift operand `(s32)((u32)arg << k)`: the cast pair forces a distinct
  re-read (`lw a2,off; sll t,a2,k; move a2,t`); a plain `arg << k` reuses the compared
  register.
- Route a store to a FAR field through a sub-object pointer with a NEGATIVE offset to
  defeat cross-field alias analysis AND keep the folded store offset: `*(u8*)((u8*)sub -
  K) = v;` where `sub = &arg->farfield` folds to `sb v,off(arg)` AND forces a path-local
  reload of a nearby field after the store. A plain member store proves no-alias and
  DROPS that reload. (Assign `sub` before the conditional; reference it at two offsets so
  `base+K` is materialized into a register.)
- A field read once and reused across an early store of the SAME base wants the typed
  STRUCT-POINTER member (`arg->field`), not a raw cast: the member form keeps the loaded
  register live across the intervening store, whereas the raw-cast double-loads or
  defers the store.
- To force TWO separate (non-CSE'd) `addu`s of the SAME `base+off`: compute one use via
  INTEGER arithmetic and the other via POINTER arithmetic (`lbu` address as `*(u8*)((s32)
  base + off + k)`, call-arg as `(u8*)off + (s32)base`). The mix defeats GCSE. Make
  `off` the base to put it first in the arg's `addu`.
- Same-global first-use-folds-then-later-splits: when a global is read once as a direct
  `%lo` load but LATER reads load its address and deref `[0]`, write the FIRST use as
  `D_xxxx` and later uses as `(&D_xxxx)[0]`.
- A small-struct VALUE COPY reproduces an $at-reusing word-copy sequence (`at`/`t8`/`at`
  for a 3-word copy): write it as a struct-to-struct value assignment of a TAGGED struct
  (`temp->v = *arg1;`). Field-by-field allocates fresh sequential temps (no $at reuse).
  (Exception to "IDO never uses $at as a general temp from C" — a value-copy of the
  right width CAN land words in $at.) Sub-word widths key off the struct SIZE: a 3-byte
  tagged-struct copy (`struct{u8 c[3];}`) uniquely emits a single `lwr at,2(src)/swr
  at,2(dst)` through $at; 4 bytes gives `lw/sw`, 2 bytes gives `lhu/sh`. Size the tagged
  struct to the EXACT byte span to pick the copy instruction. Passing a struct BY VALUE
  also reproduces IDO's word-unrolled do-while struct copy before a forwarding call;
  match the by-value signature, don't pass `&`.
- `x - x*y` store-back to the SAME field x: write `temp = x; *p = temp - y * *(f32*)&x;` - the memory re-read of x CSE-collapses to f0 (first mul operand), y stays an inline temp reg, result lands fresh. A named `y` shifts every later FP reg by one; `-=`/reassigning `temp` reuses its reg for the result.
- Defeat CSE of a doubled SIGNED-byte read (sentinel `== -1` test + index use of the same byte) WITHOUT losing signedness: cast ONLY the TEST read `volatile s8 *`, leave the index read plain `s8` - both stay `lb`. Reading the index as `u8` also breaks CSE but emits `lbu` (wrong sign).

## Stack frame, homing & params
- Param homing: a param is NEVER homed if only forwarded/used as-is; it IS homed (`sw
  aN,off`) if reassigned. Forward ALL args through to callees to suppress a spurious
  dead-param home; verify against a matched sibling's objdump.
- Selective homing in a forwarding/dispatch call: to home ONLY the later param, forward
  the EARLIER arg as the call's argument (passes through a0 un-homed) and leave the later
  param named-but-unused (-g3 homes it). Passing the later arg adds a wrong `move`+home;
  passing nothing/`void` homes BOTH; varargs homes ALL.
- To reproduce a param HOMED and reloaded on every use, take its address into a local
  (`s32 **pp = &arg0;`) and read through `**pp`.
- A `void*` param CAST INLINE at each use makes IDO SPILL it to its home and RELOAD per
  access; a typed param or one cached local keeps it in a saved reg. Keep it `void*` +
  cast when the asm spills+reloads (also keeps the def consistent with a `void*` decl).
- A u8 param the target spills-then-NARROWS BEFORE saving ra (`sw a2,off; andi tN,a2,
  0xff; move a2,tN` ahead of `sw ra`) wants the param TYPED `u8` (not `s32`); the
  spill-then-mask-before-prologue ordering is IDO's u8-param codegen.
- To home ALL incoming register args to the standard caller arg-save slots WITHOUT a
  frame (a trivial body that just spills args), take the address of the FIRST param
  (`s32 *p = &arg0;`). Exact-typed params with no address-of home nothing; varargs adds
  a frame. A finer-grained alternative: self-assignment (`arg0 = arg0; arg1 = arg1;`)
  homes EXACTLY those params with no frame (a `return 0;` stub homes nothing).
- Pass the IDENTICAL conversion of `&local` to EVERY call so IDO unifies the address into
  ONE saved-register CSE temp (s0) with no named local and no extra slot: write the SAME
  integer expression `(s32)&local` at all call sites (callees pinning a `void*` param take
  `(void*)(s32)&local` — the inner s32 node still shares the CSE). MIXING `void*` and `s32`
  argument CONVERSIONS across the calls SPLITS the CSE into two spilled temps; raw `&local`
  (no cast) gets no CSE and recomputes the `addiu` per call. Constrain unprototyped callees
  with local `(s32,...)` decls so they take the raw cast.
- Passing `&local` DIRECTLY to multiple calls (no named pointer) makes IDO spill the
  address to its own 8-aligned temp slot and reload it — matches target spill/reload.
  CONVERSELY, routing `&local` through a NAMED pointer var GROWS the frame: the named
  pointer reserves an extra 8-aligned slot (bumping e.g. 0x28->0x30), shifting the local
  and recomputing `addiu aN,sp,off` fresh at each call. Use the named form when the
  frame is 8 short.
- In-place forwarder (callee's first param == this func's): pass it THROUGH UNCHANGED
  (`f(arg0, ...)`) so IDO emits NO `move a0` and leaves the slot a `nop`. A literal `0`
  emits `move a0,zero`; a function-pointer cast emits `jalr`. A wrapper passing arg0
  straight through AVOIDS the a0 stack-spill entirely (no `sw a0,off`). Pass the
  ORIGINAL arg (not a locally-computed temp) when the asm leaves a0 unchanged.
- Two SEQUENTIAL calls forwarding the SAME param: IDO homes it ONCE (`sw a0,off` in the
  prologue) and RELOADS (`lw a0,off`) before EACH call (the first call clobbers a0). Just
  forward to both; don't try to suppress the home.
- A0 RELOADED in a `jal`'s delay slot (vs a bare `nop`) reveals the CALLEE consumes the
  arg — forward it from C. This may expose a mis-signatured neighbor: if a sibling callee
  is typed `(void)` but forwards an arg, correct BOTH its signature and the function it
  forwards to (driven by the neighbor's own asm: nop slot = pass-through; forwarded
  callee reading a0 = consumes it). Forwarding a param to a callee that IGNORES it
  (purely to force the delay-slot reload) works too — widen the ignored callee's LOCAL
  prototype to take the arg; its codegen is unaffected.
- A 5th (stack) argument FORCES a frame + the stack-arg slot at sp+0x10 (e.g. `swc1
  fN,0x10(sp)` for an f32 5th arg), regardless of type. A 4-or-fewer-arg call stays
  frameless. Count callee args from the asm's sp+0x10 (and 0x14/0x18 for 6th/7th) to fix
  a wrong frame / missing slot store. An EXTRA dead trailing arg makes IDO reload it into
  the `jal` delay slot — verify the true callee arg count from a sibling CALLER's asm.
- Callee prototyped `void(void)` => call it with NO args even when this function receives
  args and the asm stores them to home slots (those come from the -g3 PROLOGUE, not the
  call). Override a WRONG-arg SHARED-header callee prototype with a block-scope empty K&R
  extern `extern void func();` (EMPTY `()`, not `(void)`) to get a no-arg call with a
  bare `nop` slot instead of a spurious `move a0,zero`.
- Forwarder that RE-SIGNS its param before the call homes that param: a thin forwarder
  passing an `s16`/`s8` UNCHANGED still emits a frame + `sw aN,off` home (the source-
  level sign-extend counts as a use). Declare the param at its true narrow signed width.
  Unsigned analog: a `u16`/`u8` param forwarded unchanged emits the entry-narrowing MASK
  (`andi reg,0xFFFF`/`0xFF`) + the -g3 home; declare it `u16`/`u8` (not `s32`).
- Thin wrapper forwarding `arg0 + CONST`: `f(arg0 + K);` emits IDO's `or a1,a0,zero;
  addiu a0,a1,K`; don't introduce a named `tmp = arg0 + K;` (it homes/reorders).
- Zero-a-buffer wrapper (single `jal bzero`/`memset` clearing N bytes of a global) is
  `bzero(&D_xxxx, N);` (or `memset(&D_xxxx, 0, N)` if the asm passes a 0 middle arg).
  Declare the global `extern u8 D_xxxx[N];` so `&D_xxxx` yields the bare `%hi/%lo` arg.
- A WRONG-width or WRONG-COUNT param in a SHARED header is unfixable from the call site:
  a narrow-width prototype forces `andi tN,aM,0xff; move` before the `jal` (no call-site
  cast suppresses it; a fn-pointer cast emits `jalr`); a phantom extra param emits a
  stray `sw aN,off` home (-g3 homes every named param) and a correct definition won't
  COMPILE against the header. The only fix is correcting the shared header. If header
  edits are out of scope, bail (stub) and flag the prototype. ESCAPE HATCH (no header
  edit): `#define func_xxxx func_xxxx_orig` BEFORE the header `#include` to rename the
  wrong prototype out of the way, then declare the TRUE signature locally so the direct
  `jal func_xxxx` (correct arg count/widths) is emitted from this TU only.
- Reverse-engineer stack-arg local TYPES/SIZES (and frame size/offsets) from the
  CALLEE's store widths: `sh`=>`s16[]`, `swc1`=>`f32[]`, `sb`/`sw`=>`u8`/`s32`. A local
  STACK BUFFER's array LENGTH controls the frame and slot: an exact-fit array keeps the
  minimal frame at the target's offset; an OVERSIZED array pads to the next 8-aligned
  size and shifts the offset. Size it to the EXACT span of bytes written.
- A stack-local AGGREGATE's slot alignment follows its FIRST member's type: a leading
  `void*`/pointer lands it 8-aligned (e.g. sp+0x28), an `s32` drops it to the next
  4-aligned slot. Type the leading member to match the asm's slot.
- Force a sub-word local onto a 4-ALIGNED slot by OVERSIZING it to an array: `s16 x[2]`
  (use `x[0]`) bumps alignment to 4 and forces the lower placement, no change to store
  width. Same trick for an address-taken `s32` scalar that IDO 8-byte-aligns into the
  TOP half of an 8-byte slot: `s32 x[2]` (use `x[0]`) forces it onto the low 4-aligned
  offset, matching both the store offset and the `addiu` of its address.
- An extra dummy/return local declared BEFORE a stack struct local reserves a 4-byte
  slot ABOVE the struct, growing the frame and pinning the struct at the target's
  offset. Declaring it AFTER places it below (wrong offset). Use before-the-struct to
  bump the frame when it's a word short.
- Varargs printf-style wrapper: `#include "libc/stdarg.h"` + a `va_arg` copy loop give
  the pointer-bump alignment idiom (`(p+3)&~3`); size the stack buffer so its last
  element OVERLAPS the arg-home region to land the right frame/offset.
- SOURCE POSITION of the function definition controls object-level emission order and
  can DESYNC the whole diff: a function must be defined at its ORIGINAL position relative
  to siblings. If an old prototype sat earlier and you define the body THERE, the object
  diff massively desyncs (huge cascading score) even when byte-correct. Leave a forward-
  declaration where the old prototype was and place the DEFINITION at the original
  position. Suspect this when a byte-correct body scores in the thousands.
- When a near-identical SIBLING func already matches, mirror its exact C structure (call
  order, arg casts via prototype, last-arg literals) — often a 1-try match.
- Cluster of HIGH-offset `arg0` fields accessed AFTER a call: assign `T *p = &arg0->sub;` (base = arg0+0x30) BEFORE the `jal` -> IDO homes a0 across the call and rematerializes `v0 = a0+0x30` after, addressing fields via small offsets. Call-crossing analog of hoist-above-branches.

## Float-arg CSE & zero registers
- Multiple ZERO float args CSE into one FPU register: passing several `0.0f` args makes
  IDO collapse them into a SINGLE materialized zero reg with a single store. When the
  target keeps TWO distinct zero registers (e.g. f2 and f12) and a grouped store order,
  pass literal int `0` (not `0.0f`) for the args that should land in the second zero reg
  — the int-vs-float mix defeats the CSE. STORE-to-global analog has NO such lever and is
  a BAIL: parallel `D_a[i]=0.0f; D_b[i]=0.0f;...` where the target keeps TWO `mtc1 zero`
  regs (one eager, one lazy) cannot be split — IDO 5.3 ALWAYS CSEs identical FP-zero
  literals into ONE register for stores (temp `f32 zero`, `&D` indirection, reorder, read-
  back all fail). A sibling earns a 2nd f-reg only by storing a LOADED global (lwc1), not
  a literal. Confirm against such a sibling, then stub.
- To force EAGER loading of later call args (e.g. `lbu a2` before a branch, `lbu a3` in
  its delay slot) surrounding a conditional, read those globals/fields into local temps
  BEFORE the controlling ternary/if; IDO then interleaves their loads with the branch.
- A branch-LIKELY over a float compare (`c.le.s` + `bc1fl`) naturally emits a DUPLICATED
  store when written as a plain if/else whose both arms store the same value — don't
  hand-dedupe; the if/else over the likely branch produces the duplicate for free.
- To force a per-iteration reload of a global pointer/value, deref-cast it inline IN the
  loop body; binding it to a local lets IDO hoist it out. Inlining a value in the
  for-CONDITION (vs a named `count` local) also pins its register.
- Keep a call's float result as the FIRST `mul.s` operand ($f0) by INLINING it (`func() * p->field`); binding it to a named temp moves it out of $f0. Converse of the dedicated-temp rule - pick inline-vs-named by which operand the asm keeps in $f0.

## Reusing a condition's loaded register as a call arg
- When the `if` tests a GLOBAL directly (`if (D_xxxx)`, loaded into v0 via a likely
  branch) and the taken block passes that same global to a call, RE-READ the global into
  a local temp INSIDE the block (`temp = D_xxxx;`) and pass `temp`. IDO reuses v0 and
  emits `move a0,v0`. Loading it before the if, or testing a temp, loads the value
  directly into a0 instead.
- Default-value-in-delay-slot + conditional load: to reproduce a `move aN,v0` default in
  a `bnez` delay slot FOLLOWED by a conditional load on the taken path (untaken keeps the
  default), write a TERNARY on the value: `arg = (cond) ? ((s32*)v)[idx] : v;`. A plain
  if/else copy-propagates `v` and DROPS the move.

## Display-list / macro-built constant words
- Building two DL words via the F3DEX macro (`gImmp21(dl, G_MOVEWORD, seg, off, &addr)`
  producing w0=0xDBxxxxxx, w1=addr) reproduces IDO's interleaved `lui/lui/addiu/ori`
  (the macro emits the constant word's `ori` AFTER the address's `addiu`). The raw form
  emits the `ori` BEFORE the `addiu`. Use the macro form for gbi-built DL words.
- Single-command DL builder returning the advanced pointer: invoke the GBI macro with a
  POST-INCREMENT argument (`gSPMatrix(pkt++, ...)`) and `return pkt;` to reproduce IDO's
  `move v1,a0; <stores via v1>; addiu a0,a0,8; move v0,a0`. Hand-written equivalents get
  coalesced into stores-via-a0 + one `addiu`. (Unused params spilled at entry confirm
  the signature; declare any undeclared global the macro references as a local extern.)
- DL-store pointer split: to write a record through one pointer (`move v0,a0`) while
  advancing the list pointer separately (`a0 += 8`), use a DISTINCT local for the store
  target and increment the list pointer BEFORE the macro store. A single pointer
  coalesces them. (See BAIL: increment-before vs store-first is a mutually-exclusive
  schedule tension.)

## Diagnosing a FALSE non-zero score
- Jump-table rodata-ref FALSE score: when a switch matches byte-for-byte but the scorer
  reports non-zero, check whether the diff is ONLY compiler-jtbl rodata references — IDO
  emits the jump table as an anonymous LOCAL `.rodata` label while the target references
  a NAMED jtbl symbol in a SEPARATELY-split rodata file, and the score CASCADES through
  following GLOBAL_ASM functions. Re-run with `-R`/`--no-show-rodata-refs`: a clean 0
  confirms a byte-perfect match. The residual is a rodata-split representation artifact,
  not an instruction diff — record it as matched.
- Whole-object score polluted by NEIGHBORING GLOBAL_ASM stubs: when your function is
  byte-perfect but the iter_match/whole-object score is large, the score is the
  Levenshtein of the ENTIRE object, which still contains adjacent `#pragma GLOBAL_ASM`
  stubs (the differ's `-o` mode bleeds their disassembly into trailing context). Verify
  in isolation: (1) asm-differ shows ZERO diff markers on your function's line range, and
  (2) raw `objdump` byte-compare of the function's object-offset range (per `nm`) is
  identical — modulo unresolved `%hi/%lo` reloc placeholders (`0x0000`) that resolve at
  link. A clean isolated diff means matched.
- FALSE huge score on a SHORT function: the object differ reads PAST `jr ra` into adjacent un-decompiled functions and counts those as diffs. Re-run `diff.py -o func -s` (stop-at-ret); a clean CURRENT (0) confirms. Or raw-byte-compare the function's own symbol-size range (build vs expected).

## When to BAIL (irreducible cases)
General rule: if after ~4-6 iterations the ONLY remaining diff is a single register name
('r' markers, all else identical) or a single instruction's delay-slot placement, it is
almost certainly an irreducible JUSTREG / instruction-schedule case. IDO won't be steered
there from C; STOP, record best score, REVERT to the stub, flag it as a decomp-permuter
candidate. Score inflation caveat: a single extra/missing nop or JUSTREG can 4-byte-shift
ALL later functions, inflating a per-object score far above the true per-func delta —
judge the func in ISOLATION (objdump its bytes); don't chase the inflated number.

Operand-order / canonicalization cases:
- Plain `beq`/`bne` EQUALITY operand order is canonicalized to put the LOCALLY-LOADED
  operand FIRST regardless of source order (`a==b`, `b==a`, `!=`, early-return,
  nested-if, width/cast all give the loaded-local-first form). Rewriting as `^`/`-`
  flips it but reserves a PHANTOM temp that cascades renames. Not steerable. (DISTINCT
  from the `bnel`/`beql` LIKELY-branch rule, which IS steerable by swapping operands.)
- mul.s memory-operand-first canonicalization: when one factor is a live value already
  in an FPU reg and the other a just-loaded memory operand, IDO ALWAYS emits `mul.s
  fD,fMEM,fLIVE` regardless of C order. The only flip (pre-loading the field into a
  named local) cascades the whole FP register-pair allocation. (Unlike the ordinary
  steerable commutative rule.)
- Integer `multu`/`mult` rs/rt canonicalization: when one factor is CACHED in a register
  and the other FRESHLY LOADED, IDO always allocates the fresh load as `rs` and the
  cached as `rt` (`multu fresh,cached`) regardless of C order; naming the fresh value or
  self-assigning the product back both REGRESS. (Integer analog of the float rule.)
- IDO never uses `$at` ($1) as a general compiler temp from C: if the target REUSES `$at`
  for some loads (vs a named t-reg for the middle one), no C form reproduces it — IDO
  allocates sequential `$t`/`$v` registers. (Exception: the struct value-copy width trick
  above CAN land copied words in $at.)

Register-allocation rotation / coupling:
- Coupled/cyclic JUSTREG: if fixing one register diff forces a different one (e.g.
  keeping an index live frees one reg but changes a multiply distribution), the alloc is
  cyclically constrained — bail.
- CSE mismatch: when the target re-loads/re-indexes but IDO collapses your two identical
  accesses into one (register-only 'r' diffs), you cannot force the duplicate load from
  C. Same bail as JUSTREG.
- v0/a0 split with NO `move a0,v0`: when the target computes a pointer via `addiu
  v0,v0,K` yet uses a0 as BOTH the store base and the jal arg, with no `move a0,v0`
  linking them, that split is unreachable — every C form forces the pointer into ONE
  register. The lone diff is the addiu's destination register.
- Small-switch (or straight-line indexed-RMW) +1 temp rotation: a byte-RMW switch over
  0/1/2, OR a tiny body that indexes a global array and ORs a bit into an adjacent byte
  field, can reach BYTE-IDENTICAL structure yet leave a uniform +1 temp-register rename
  — the target's allocator SKIPS one mid-pool register (coalescing a later case's value
  reg onto an earlier one) where C yields N+1 temps. No source lever (switch vs if-chain,
  body reorder, field type, pointer indirection, compound vs explicit ops, hoisting the
  load, `default:` label, address formulation) responds. Reg-only residual; bail.
- Two-array-index register-bank inversion: a tail-call/expr indexing TWO parallel arrays
  by the same param (a *4 word array and a *12 stride array + a field off the second) can
  match byte-for-byte yet have the bank INVERTED (word-array on one t-pair, stride-array
  on the other) and flip the final delay-slot `addu` operand order. No C reformulation
  flips the bank. Bail.
- Single-sll-vs-register-pair tension on an array-walk with a byte-offset counter: when
  the target needs ONE shared `sll` feeding BOTH the element-pointer-init `addu` AND a
  `-4`-stride byte-offset counter tested with `bgez`, byte/integer pointer-init gives the
  INVERSE pair, TYPED pointer arithmetic gives the right pair + `bgez` but DUPLICATES the
  `sll`, and `off = i<<2` re-CSEs the shift but reverts the pair. Harvest the typed form
  as a permuter seed; bail.
- Two-array-index variants aside, a saved-pointer vs array-subscript tradeoff in an
  indexed walk (saved `e = &base[idx]` avoids a recomputed base but a named `next = idx+1`
  is needed to keep the final compare unscaled) can leave a uniform reg cascade + one
  li-hoist — JUSTREG; bail.
- mflo-in-v0 vs dependent-shift-input-as-fresh-low-temp mutual exclusion: for `(val *
  a1) >> 8`, reassigning the SAME `val` through load->fold->multiply KEEPS mflo in v0,
  but then the dependent shift READS v0 while the target colors its input as a fresh LOW
  temp (which only happens if `res` is separate, displacing mflo from v0). Mutually
  exclusive; harvest the mflo-in-v0 form as a seed and bail.

Schedule / hoist artifacts:
- Struct-copy destination forced into v0 (spurious `move a0,v0`): when a function copies
  an aggregate into a stack local then passes that local's ADDRESS as the first call arg,
  and the target keeps the dest address in a0 throughout, EVERY C form (struct assign,
  init-at-decl, pointer-indirection, field-by-field, casts) allocates v0 as the copy
  destination and emits a spurious `move a0,v0`. Unsteerable; bail.
- Trailing dead doubled epilogue (`jr ra; nop` after the real return): an UNREACHABLE
  second `jr ra; nop` pair (more instructions than any C body emits) — else-branch, dual
  `return X;`, ternary/explicit-ret-local, trailing label, discard-call-result forms all
  regress. -g3 artifact; bail (stub).
- Callee-saved promotion of a cross-call pure pass-through: when the target carries a
  value across a call in a callee-saved reg (`or sN,v0,zero` in the delay slot, `or
  v0,sN,zero` at return, larger frame), IDO from C SPILLS it to the stack instead. Every
  C form (named local, `register`, comma-expr, `if(1)`-wrap) spills. Bail.
- -g3 home of a singly-used call result into the call's own register lineage: when the
  target homes a `jal`/`jalr` result (`sw v0,off` in the delay slot) and reloads into v0
  before its single use, IDO from a plain local FOLDS the home away; `volatile` reloads
  into a fresh temp at the wrong offset. Bail (stub).
- Loaded value held in v0 then `move`d to a call arg vs coalesced straight in: when the
  target loads a value into v0, HOISTS a sibling constant arg (`li a0,2`) before the
  branch, and copies with `move a1,v0`, every single-load C form coalesces the value
  DIRECTLY into the arg reg. Bail (stub).
- Opportunistic -g3 param-home filling an EMPTY jal delay slot: when the SOLE residual is
  a `sw aN,off(sp)` homing an incoming arg (to its caller arg-save slot, OUTSIDE this
  frame) in an otherwise-empty `jal`/`jalr` delay slot, there is no C use that reproduces
  it without a side effect (forwarding spills, `&arg`/`**pp`/volatile home at entry +
  reload, self-assign/comma DCE'd). Harvest as a permuter seed and bail.
- -g3 param self-home before an index-multiply (`move aN+1,aN` copy, multiply on the
  copy, result back in aN): when a tiny array-index lookup COPIES the index param into the
  NEXT register, multiplies on the copy, then lands the result back in the original param
  reg, no C index form triggers the leading copy (IDO multiplies on the param directly
  and lands the result in a fresh temp). Bail (harvest a near-miss seed).
- Prologue arg-homing order driven by clobber-prep: when the target homes the args it
  clobbers/preps FIRST (e.g. `sw a3; andi a3; move a3; move a2` at the TOP, before
  a0/a1) but every C form schedules the mask/move LATE and homes a0/a1 early, the order
  is set by IDO's clobber-prep ordering. Bail.
- Eager narrow of a LIVE arg register before a home-clobber: when the target masks an
  incoming arg WHILE STILL LIVE, ahead of the `move aN,aM` that clobbers it (`sw a2,off;
  andi a3,a2,0xff; move a2,a1`), IDO from every C form instead HOMES then RELOADS the
  value for the mask. A 1-instruction miss; bail.
- Size-arg homed INTO the call's delay slot then reloaded for a post-call add (`(s32)
  memcpy(dst,src,n)+n` tails): when the target homes the count arg IN the `jal memcpy`
  DELAY SLOT then reloads for the final `addu v0,v0,tN`, IDO from every body homes `a2`
  BEFORE the jal + a redundant reload in the slot. No C form moves the home into the
  slot. Bail.
- Return-phi shape when an intervening call SPILLS the result: the `if(p){...} return p;`
  phi idiom assumes p stays in v0. If a call (e.g. memcpy) spills it, IDO reloads
  OPTIMALLY into v0 on the non-null path while the target reloads into v1 then `move
  v0,v1`. No C form reproduces the redundant v1->v0 once a spill is in play. Bail.
- Pointer post-increment schedule lock: building successive records through a running
  pointer where the target schedules the bump (`addiu aN,aN,sz`) AFTER each record's
  stores. The only snapshot form (`p = arg0++`) ALWAYS hoists the increment BEFORE the
  stores; delaying it folds all stores into one base+offset (far worse). Coupled with a
  snapshot-count vs frame-size tradeoff. Bail. (Same tension as the DL-store split.)
- Branch-likely duplicated store reusing a call-clobbered register: when the target
  stores a value AFTER a `jal` that clobbers that same register (reusing a now-dead reg)
  and keeps the `jal` slot a NOP, store-after-call SPILLS across the call while store-
  before-call matches everything except it fills the jal slot with the store instead of
  the NOP. Bail.
- Branch-likely orientation vs constant-arg-in-delay-slot tension: when the target fires
  a `bnel`/`beql` AND keeps a constant second arg (`move a1,zero`) in the else-call's jal
  delay slot, the `==K`-fallthrough orientation HOISTS the constant (no likely-bit) while
  the `!=K` orientation fires the likely branch but swaps call sites. Neither gets both.
  Bail.
- Loop-rotation / strength-reduction of an indexed reload: when the target converges
  every branch onto ONE shared bottom load (or hoists/duplicates an `arr[i*k]` reload
  into branch delay slots) driven by IDO's induction-variable rewrite, unsteerable. Bail.
- Loop limit-substitution: when the target keeps a signed index test against an immediate
  (`slti at,sN,LIMIT; bnezl`) but IDO from EVERY loop form MATERIALIZES the trip-count
  limit in a register and uses an equality test (`li sM,LIMIT; bnel sN,sM`), the extra
  bound register cascades into renames + a save slot + a `move`. An EMPTY warm-up loop
  may keep `slti`, but any active body triggers the rewrite. Bail.
- Switch case-pointer delay-slot hoist: when the target hoists a case body's `lui %hi`
  into the preceding `beq` delay slot and reads fields through that register while IDO
  emits a `nop` and computes the `lui` inline, no C form steers it without over-hoisting
  or growing the frame. Bail. (Reading the shared operand FIRST can still fix a
  `beql`->`beq` likely-bit.)
- Constant load hoisted ABOVE the prologue saves: when the target schedules a float/loop-
  invariant load (`lui at,%hi; lwc1 %lo`) ahead of the prologue saves (`sw ra`, `sw aN`),
  IDO emits the integer saves first. A single swapped pair; bail. (Inlining is worse —
  materializes a base pointer.)
- Loop-invariant load hoisted ABOVE the first arg load: when the target emits an
  invariant constant load (`lwc1 $f2,%lo`) BEFORE the first arg load, IDO from every form
  emits the arg load first. Separate `if`s break the branch structure. Bail.
- Scheduler-priority hoist of a chain-feeding load vs a constant return: when the target
  loads a constant first, THEN a struct-pointer (`lw vN,off(a0)`), fills that load's slot
  with `li v0,1` (the return), and only then the float chain — but IDO HOISTS the `lw vN`
  to the top (it feeds a long float chain, higher list-scheduling priority) and pushes
  `li v0,1` to the END. No transform steers the tie-break. Bail. (Store order of the
  field copies still must match exactly.)
- End-to-end live value with no early C need (Horner `+D` / shared subexpression): when
  the target keeps an arg/element live in ONE FPU reg across the whole function (used in
  an INLINED early subexpression AND as the final trailing add), IDO loads it late and
  hoists an unrelated load into the first load's slot. A named local to force the early
  load adds a -g3 home and grows the frame. Bail.

Object-level / reloc / 64-bit cases:
- Same-symbol read+write where the target uses SPLIT `lui %hi`/`%lo` with a SEPARATE lui
  for load vs store (huge score, e.g. 900): IDO at -O2 CSEs both into one `lui+addiu`
  pointer and no C form (--, -=, x=x-1, temp, ptr-cast, [0]) splits them. NOTE: an -O2
  quirk, NOT -O3 (a sibling matching at -O2 proves the file is -O2; asm-processor rejects
  -O3). Bail.
- IDO -O2 constant-folds `D_xxxx + off` into ONE `%lo(D_xxxx+off)`: if the target instead
  emits a separate base + temp (`lui`/`addiu sN,s0,off`), no C form splits the fold. Bail.
  Folding-family note: a store/load whose address equals `base+4` may be the target's OWN
  relocated symbol (`%hi/%lo(D_NEXT)`), NOT `%lo(D_base+0x4)` — declare a SEPARATE
  `extern` for the +4 symbol and index it; `base[i].field_at_4` emits `%lo(D_base+0x4)`
  and scores worse.
- `%lo`-advance fusion: a target that fuses `addiu vN,vN,K` onto a constant-address base
  (instead of folding K into `%lo(D_xxxx+K)`) only does so when an earlier REAL (non-
  unrolled) loop left the pointer in a register at a runtime value. If your init of that
  base is UNROLLED (constant trip count), IDO has no live runtime pointer, so EVERY
  advance form folds K into a fresh `lui;addiu %lo(D_xxxx+K)`. Unsteerable when the init
  is unrolled. Bail.
- Unroll-vs-end-reloc-anchor tension on a region between two EXTERNAL symbols (clear
  `D_START..D_END`): a literal-trip-count `for(i=0;i<N;i++) D_START[i]=0;` gives the clean
  4x unroll but anchors the loop-end pointer reloc on the INDEXED base `%lo(D_START+N)`,
  while every pointer-compare naming the end (`p!=&D_END`, `i<&D_END-D_START`, negative
  index from `D_END`) anchors the reloc on `D_END` but DEFEATS the unroll (IDO can't prove
  the external-symbol span is a multiple of 4 -> auto-vectorize + Duff remainder, huge
  score). Same linked bytes; only the reloc symbol differs. Mutually exclusive; harvest the
  literal-count form as a seed and bail.
- Aggregate-relative reloc you can't produce: when the target accesses a field via a base
  symbol + addend (e.g. `%lo(D_xxxx+4)`, the +4 element of a 2-element aggregate WITHOUT a
  base pointer), every C layout materializes a base pointer instead, and the only clean
  form references the DISTINCT scalar symbol at that address. Linked ROM bytes are
  identical; the divergence is object-level relocation representation. Bail.
- Jump-table externalization: the expected .c.o references an EXTERNAL jtbl symbol
  (HI16/LO16 + R_MIPS_PC16 `ffff`), but compiling C makes IDO emit a LOCAL .rodata table
  (R_MIPS_32, baked branch). No C externalizes it, and the external rodata jtbl
  references the asm function's `.L` labels, so compiling as C FAILS TO LINK. Leave as a
  GLOBAL_ASM stub. Bail.
- Split lui/addiu cross-pairing between two pointers: when the target emits one pointer's
  `lui` EARLY but DEFERS its `addiu` to just before the loop while building a second
  pointer's `lui`+`addiu` eagerly between (lui order `lui p`, addiu order `addiu e`
  first), no declaration order decouples them (lui-hoist order and addiu order stay
  COUPLED to decl order). Bail.
- Spill-SLOT offset set by TU temp-counter, not source: when the instruction stream is
  byte-perfect and the ONLY residual is a spill/reload to a different 4-byte slot (e.g.
  target `sw/lw ...,0x20(sp)` vs your `...,0x24(sp)`), and the SAME character-identical C
  matches byte-perfect in ANOTHER file, the offset is driven by IDO's per-translation-unit
  temp/symbol counter — preceding GLOBAL_ASM stubs here vs real C there shift it. No
  within-function lever (named/register/RMW/pointer temp, arg form, callee return type)
  moves it. Decompile the neighbors (or run a permuter with TU context); bail on this func.
- Address spill 4-align vs 8-align (`0x1c` vs `0x18` in a `0x20` frame): a NAMED pointer
  local is spilled to its own 8-ALIGNED slot. If the target spills the reloaded address
  at the 4-aligned slot adjacent to the homed param, DROP the named pointer and write the
  index expression INLINE at each use; IDO CSEs it into one register but treats the spill
  as a 4-aligned temp. (Same instructions, spill offset flips 0x18->0x1c — steerable, not
  a true bail, but a frequent near-miss.)
- Phantom 8-byte stack slot from `&local` to >4-arg calls: passing `&local` to calls with
  STACK args can make IDO reserve an unused 8-aligned temp slot between saves and the
  first local (recomputing `addiu aN,sp,off`, no spill), landing the local one word too
  high. The slot appears ONLY with the stack-arg calls (3-arg drops it). Named pointers
  GROW the frame instead. If the target lacks the slot, bail.

Hand-written asm clusters:
- Hand-written asm with lazily-scheduled int-to-float arg conversions: when the target
  keeps surplus integer args (`mtc1 aN`) converted lazily/per-use, live in FPU regs with
  NO frame, IDO from C converts EAGERLY and SPILLS the surplus arg + allocates a frame.
  Not even a permuter candidate. Leave as GLOBAL_ASM. (Tell-tale: "handwritten?" comment,
  no-frame matrix/vector transform with args in integer registers.)
- Custom register-level calling convention: when a function receives MORE float args than
  the ABI allows in non-standard FPU registers (IDO passes floats only in `$f12`/`$f14`;
  a callee taking `$f6`-`$f11` is impossible from C), and/or saves `ra` in a t-register
  and tail-calls via `jr $t9` with NO frame, it is hand-written asm with a private
  convention. Confirm via a CALLER materializing values into those non-ABI registers.
  Leave as GLOBAL_ASM. Bail.
- Native 64-bit ops (`ld`/`sd`/`dsll32`/`dsrl`/`dsra32` on a u64) are UNMATCHABLE under
  -mips2/-o32: IDO lowers `long long` shifts to `__ll_lshift`/`__ull_rshift` helper CALLS,
  never native d-shifts. Bail unless a -mips3 per-file rule or inline asm is on the table.
  64-bit STORE corollary: a target zeroing/copying with native `sd $zero,off` is
  unmatchable too — every C form SCALARIZES into `li tN,0; sw tN,off` pairs. (Tell-tale:
  a byte-identical sibling left as a raw `asm` segment in the yaml.)
- `ld`/`sd` only for 64-bit ARITHMETIC, never a memory COPY: IDO emits a GPR `ld` only
  when the loaded 64-bit value feeds a 64-bit op. For a store-only 8-aligned copy it
  ALWAYS word-splits into `lw/lw + sw/sw`, so a target whose copy loop uses bare `ld aN;
  sd aN` is unmatchable from any plain-copy C; bail. Secondary (steerable): the loop
  COMPARISON steers memmove inlining — `src != end` triggers an inlined memmove (4-way
  unroll + `andi 0x1f` guard) while `src < end` yields a tight loop (but `sltu at; bnez
  at` instead of a direct `bne`). Use `src < end` to avoid the memmove inline.

Special empty-guard case:
- Empty-body sign-test guard that survives only with a side effect: when the target loads
  a field, tests its sign to an EMPTY inner if (`lw v0,off; bltz v0,end; nop`, v0 unused
  after, function effectively void), NO truly-empty C form keeps the `lw`+`bltz` (IDO DCEs
  the guard); every two-return/boolean form injects a phi `move`/`bgez` or `slti/xori`.
  The ONLY thing preserving the guard is a MEMORY side effect inside the if — but that
  emits an extra store the target lacks. If the lone residual is one extra store vs the
  bare guard, harvest the +1-store form as a permuter seed and bail.
