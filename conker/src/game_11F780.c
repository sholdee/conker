#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_11F780/func_150F22D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_11F780/func_150F237C.s")

extern s32 func_150F22D0(void *, void *, s32);
extern void func_151C329C(void *, s32, s32);

void func_150F2390(void *arg0, s32 arg1, s32 arg2) {
    s32 sp1C[3];

    if (*(s32 *)((u8 *)arg0 + 0x1D4) != 0) {
        func_150F22D0(sp1C, arg0, (u8)arg1);
        func_151C329C(sp1C, 0xFF, 0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_11F780/func_150F23E0.s")

extern f32 sinf(f32);
extern f32 func_15144B68(f32);
extern f32 D_800BE9A4;

struct Arg0 {
    u8 pad[0x50];
    s32 off;
};

s32 func_150F2480(struct Arg0 *arg0) {
    f32 *p = (f32 *)((u8 *)arg0 + arg0->off + 0xF8);

    p[9] = p[4] * sinf(p[0]);
    p[10] = p[5] * sinf(p[1]);
    p[0] = func_15144B68(p[2] * D_800BE9A4 + p[0]);
    p[1] = func_15144B68(p[3] * D_800BE9A4 + p[1]);
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_11F780/func_150F2518.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_11F780/func_150F25A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_11F780/func_150F26A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_11F780/func_150F2994.s")
