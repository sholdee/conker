---
name: decompile-microcode
description: Use this skill to decompile a Conker function that builds an F3DEX2 display list. Strong indicators are a `Gfx *` type or parameter, `gSP*`/`gDP*` macros, or raw 8-byte command writes to `->w0`/`->w1`. Conker is built with `-DF3DEX_GBI_2` (F3DEX2); its `gbi.h` is at `include/2.0L/PR/gbi.h`.
---

# Decompiling F3DEX2 display-list code (Conker)

Conker builds display lists by writing 8-byte microcode commands through a passed `Gfx *`
pointer — commonly named `gfx`, `pkt`, `tmp`, or `arg` — incremented inline. The original
developer used macros from `include/2.0L/PR/gbi.h`; those macro calls must be replicated
exactly for the function to byte-match. (Conker does **not** use `gRegionAllocPtr` — that is
a different project's pattern.)

## Method

1. **Identify the 8-byte commands.** A naive decompilation of a display-list write looks like:
   ```
   temp->words.w0 = 0xDA380003;
   temp->words.w1 = (s32)arg0->unk30;
   ```
   That is ONE F3DEX2 command — the high byte of `w0` (`0xDA` = G_MTX) is the opcode.

2. **Decode the command.** Look up the `w0` opcode byte in @f3dex2-reference.md (the full
   command table). `0xDA38…` → `gsSPMatrix(…)`. (If `gfxdis.f3dex2` is installed you can run
   `gfxdis.f3dex2 -d <w0hex><w1hex>` to auto-decode, but it is NOT installed by default — the
   reference table is sufficient to decode by hand.)

3. **Write the pointer-taking macro with inline increment.** Convert the static `gs…` form to
   the dynamic `g…` form that takes the display-list pointer, and substitute the real args:
   ```
   gSPMatrix(gfx++, (s32)arg0->unk30, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
   ```
   The inline `gfx++` (match the neighbor functions' pointer name — `pkt++`, `tmp++`, …) is the
   standard Conker pattern.

## Aggregate macros (usually required to match)
Several `gbi.h` macros aggregate multiple raw F3DEX2 commands into one. Always look for command
runs that collapse into an aggregate — the original almost certainly used it:
- `gDPLoadTLUT*` — palette loads
- `gDPLoadTextureBlock*` / `gDPLoadTextureTile*` — texture loads (a run of `gDPSetTextureImage`
  + `gDPSetTile` + `gDPLoadBlock`/`gDPLoadSync` collapses into one of these)
- `gDPLoadMultiBlock*`, `gDPLoadTextureBlockYuv`, etc.

A sequence of individual raw commands that exactly matches an aggregate's expansion means the
source used the aggregate, not the individual commands.

## S2DEX (rare in Conker)
Conker's matched code is currently all F3DEX2, but `gs2dex.h` is present, so a 2D-sprite
function may appear. Indicators: `gSPObj*` macros, `uObjSprite`/`uObjBg`/`uObjMtx`/`uObjTxtr`
structs, `0x01/0x02/0x05`-prefixed command words. Same method — decode via @s2dex-reference.md
(and `tools/s2dex_dis.py` if needed). Watch for compound macros (`gSPObjLoadTxSprite`,
`gSPObjLoadTxRect`) when a texture load immediately precedes a draw.

## Notes
- Consult `include/2.0L/PR/gbi.h` for exact macro signatures and the `G_*` flag constants.
- For LOW-LEVEL command constants the public `gbi.h` doesn't expose — `gSPMoveMem`/`gSPMoveWord`
  indices (`G_MV_MMTX/PMTX/VIEWPORT/LIGHT/MATRIX`, `G_MWO_*`), struct sizes (`lightSize`,
  `inputVtxSize`), and vertex-field offsets (`VTX_IN_*`) — see @gbi_internal.h (from the matching
  F3DEX2 microcode disassembly). Use it to identify which macro produced a raw move/light/matrix word.
  The full microcode disasm (definitive command-processing reference) lives at `~/f3dex2/f3dex2.s` if installed.
- Match neighbor functions' style: pointer name, struct-field access (define/extend structs
  rather than pointer arithmetic), and macro choice.
