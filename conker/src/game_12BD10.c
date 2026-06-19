#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_12BD10/func_150FE860.s")

extern s32 func_15145EA4(s32 *arg0, s32 *arg1, s32 arg2, s32 arg3);
extern u8 D_80088BA0;
extern s32 D_800A2000;

void func_150FEBC8(s32 arg0, s32 arg1, s32 arg2) {
    s32 sp20[2];
    s32 sp1C;
    s32 a2;

    a2 = *(s32 *)(arg0 + 0x1D4) + D_80088BA0 * 0x40;
    sp20[0] = (s32)&D_800A2000;
    sp1C = arg2;
    func_15145EA4(sp20, &sp1C, a2, 1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_12BD10/func_150FEC28.s")
