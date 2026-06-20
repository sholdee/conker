#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_10B7D0/func_150DE320.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_10B7D0/func_150DE32C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_10B7D0/func_150DE458.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_10B7D0/func_150DE6D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_10B7D0/func_150DE7C0.s")

s32 func_150DEACC(f32 *arg0) {
    arg0[13] += arg0[68] * D_800BE9A4;
    arg0[14] += arg0[69] * D_800BE9A4;
    arg0[15] += arg0[70] * D_800BE9A4;
    arg0[71] -= D_800BE9A4;
    if (arg0[71] < 0.0f) {
        return 0;
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_10B7D0/func_150DEB58.s")

extern void func_150DEC28(u8, s32);
extern u8 D_800A0D0B[];
extern u8 D_800A0D2B[];
extern void func_151616D0(u8, u8, s32);
extern void func_151417C4(u8, s32);

void func_150DEBE0(s32 arg0) {
    u8 i;

    for (i = 0; i < 4; i++) {
        func_150DEC28(i, 1);
    }
}

void func_150DEC28(u8 arg0, s32 arg1) {
    s32 idx = arg0 * 4;

    func_151616D0(D_800A0D0B[idx], 0x22, 0);
    func_151417C4(D_800A0D2B[idx], 0x22);
}
