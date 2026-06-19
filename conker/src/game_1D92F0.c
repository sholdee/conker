#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_1D92F0/func_151ABE40.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D92F0/func_151AC078.s")

s32 func_151AC3CC(s16 *arg0) {
    u8 *ptr = *(u8 **)((u8 *)arg0 + 0x98);
    s32 val = arg0[0x1C / 2] << 3;
    if (val >= 0x100) {
        val = 0xFF;
    }
    if (val < ptr[0x1B]) {
        ptr[0x1B] = val;
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D92F0/func_151AC408.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D92F0/func_151AC550.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D92F0/func_151AC61C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D92F0/func_151AC810.s")

extern f32 D_800BE9A4;

s32 func_151AC9EC(u8 *arg0) {
    f32 temp = *(f32 *)(arg0 + 0x4C) * D_800BE9A4;
    *(f32 *)(arg0 + 0x2C) += temp;
    *(f32 *)(arg0 + 0x30) += temp;
    return 1;
}

s32 func_151ACA20(s16 *arg0) {
    s32 val = 0xFF;
    if (arg0[0x1C / 2] < 0x10) {
        val = (s16)(arg0[0x1C / 2] << 4);
    }
    if (val < ((u8 *)arg0)[0x5C]) {
        ((u8 *)arg0)[0x5C] = val;
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D92F0/func_151ACA60.s")

s32 func_151ACB38(u8 *arg0, u8 *arg1) {
    s32 ret = 0;
    if (arg0[0x3B] == 1) {
        arg1[0] = 1;
        ret = 1;
    }
    return ret;
}

s32 func_151AE3A8(u8 *arg0);
s32 func_151ACB60(u8 *arg0)
{
  s32 new_var;
  s32 v0 = *((s32 *) ((*((s32 *) ((*((s32 *) (arg0 + 0x1C))) + 0x31C))) + 0x9C));
  if (v0 != 0)
  {
    new_var = func_151AE3A8(arg0);
    if (arg0)
    {
    }
    return new_var;
  }
}


void func_151ACB94(s32 arg0, s32 arg1, u8 arg2) {
    func_15169850(arg1, arg2, arg0 + 0x1C, arg0 + 0x20, arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D92F0/func_151ACBD4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D92F0/func_151AD174.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D92F0/func_151AD92C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D92F0/func_151AE06C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D92F0/func_151AE0E4.s")

extern f32 D_800A9294;

void func_151AE264(u8 *arg0) {
    f32 temp = *(f32 *)(arg0 + 0x3C) * D_800A9294;
    u8 *v0 = *(u8 **)(*(s32 *)(arg0 + 0x31C) + 0x9C);
    *(f32 *)(v0 + 0x4C) = temp;
    *(s8 *)(v0 + 0x50) = *(u16 *)(arg0 + 0x76) >> 8;
    *(s8 *)(v0 + 0x51) = *(u8 *)(*(s32 *)(arg0 + 0x31C) + 0xAE);
    *(s16 *)(v0 + 0x52) = 0x14;
    *(s32 *)(v0 + 0x44) = 0;
    *(s8 *)(*(s32 *)(arg0 + 0x31C) + 0x98) = 0;
    *(s32 *)(*(s32 *)(arg0 + 0x31C) + 0x9C) = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D92F0/func_151AE2BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D92F0/func_151AE3A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D92F0/func_151AE590.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D92F0/func_151AE640.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D92F0/func_151AE6B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D92F0/func_151AE7B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D92F0/func_151AE890.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D92F0/func_151AE984.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D92F0/func_151AEAB4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D92F0/func_151AECA0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D92F0/func_151AF270.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D92F0/func_151AF338.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D92F0/func_151AF388.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D92F0/func_151AF4D0.s")
