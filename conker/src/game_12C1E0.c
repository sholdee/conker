#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_12C1E0/func_150FED30.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_12C1E0/func_150FEFD0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_12C1E0/func_150FF084.s")

struct126 *func_150FF288(struct127 *arg0) {
    return func_1503195C(arg0, 0x82, 0);
}

extern f32 D_800A211C;
void func_15145740(struct127 *arg0, struct17 *arg1, struct17 *arg2, struct17 *arg3, f32 arg4);

void func_150FF2AC(struct127 *arg0, struct17 *arg1, struct17 *arg2, struct17 *arg3) {
    func_15145740(arg0, arg1, arg2, arg3, D_800A211C);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_12C1E0/func_150FF2D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_12C1E0/func_150FF474.s")

s32 func_150FF6B4(struct127 *arg0, s32 arg1, s32 arg2) {
    if (arg0->id == 0x98) {
        return 0;
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_12C1E0/func_150FF6E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_12C1E0/func_150FF840.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_12C1E0/func_150FFB6C.s")

extern s32 func_15145EA4(s32 *arg0, s32 *arg1, s32 arg2, s32 arg3);
extern u8 D_80088BB0;
extern s32 D_800A2130;

void func_150FFBDC(s32 arg0, s32 arg1, s32 arg2) {
    s32 sp1C;
    s32 sp18;

    sp1C = (s32)&D_800A2130;
    sp18 = arg2;
    func_15145EA4(&sp1C, &sp18, *(s32 *)(arg0 + 0x1D4) + D_80088BB0 * 0x40, 1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_12C1E0/func_150FFC3C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_12C1E0/func_150FFCC8.s")

void func_15081E0C(struct127 *arg0, s32 arg1, s32 arg2);

void func_150FFD2C(struct127 *arg0, struct127 *arg1, s32 arg2) {
    if (arg1->id == 0x9F || arg1->id == 0xA0) {
        if (!(arg1->unk94 & 0x80)) {
            func_15081E0C(arg1, 4, 0);
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_12C1E0/func_150FFD84.s")
