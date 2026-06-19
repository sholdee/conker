#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_1D92F0/func_151ABE40.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D92F0/func_151AC078.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D92F0/func_151AC3CC.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D92F0/func_151ACA20.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D92F0/func_151ACA60.s")

s32 func_151ACB38(u8 *arg0, u8 *arg1) {
    s32 ret = 0;
    if (arg0[0x3B] == 1) {
        arg1[0] = 1;
        ret = 1;
    }
    return ret;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D92F0/func_151ACB60.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D92F0/func_151ACB94.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D92F0/func_151ACBD4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D92F0/func_151AD174.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D92F0/func_151AD92C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D92F0/func_151AE06C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D92F0/func_151AE0E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D92F0/func_151AE264.s")

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
