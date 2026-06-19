#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_EB340/func_150BDE90.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_EB340/func_150BDF0C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_EB340/func_150BE150.s")

extern f32 D_800BE9A4;

s32 func_150BE1C4(f32 *arg0) {
    arg0[5] += arg0[32] * D_800BE9A4;
    if (arg0[5] > 120.0f) {
        return 0;
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_EB340/func_150BE210.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_EB340/func_150BE2E8.s")

s16 *func_150BE438(s16 *arg0, s32 arg1) {
    arg0[0] = 0x68;
    arg0[1] = D_800CC2D0[arg1].unk2E8;
    arg0[2] = 0xE;
    arg0[3] = D_800CC2D0[arg1].unk2E4;
    return arg0 + 4;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_EB340/func_150BE494.s")
