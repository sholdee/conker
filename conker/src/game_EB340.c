#include <ultra64.h>
#include "functions.h"
#include "variables.h"


void func_150BDE90(void *arg0, u8 arg1, s32 arg2) {
    struct {
        void *unk0;
        u16 unk4;
        u16 unk6;
    } sp38;
    struct260 *temp_v0;

    sp38.unk0 = arg0;
    sp38.unk4 = 0;

    temp_v0 = func_15149130(0x12C, -1, 0x4F, -1, 0, 0x3C, (struct37 *)0x8, arg1, arg2);
    if (temp_v0 != NULL) {
        memcpy((void *)((s32)temp_v0 + 0x28), &sp38, 8);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_EB340/func_150BDF0C.s")

void func_1516972C(struct102 *arg0);

void func_150BE150(struct102 *arg0, s32 **arg1, u8 arg2) {
    if (arg2 == 0x21) {
        if (*(s32 *)((u8 *)arg0 + 0x28) == (s32)arg1[0]) {
            func_1516972C(arg0);
        }
    } else if (arg2 == 0) {
        s32 *temp = arg1[0];
        if (*(s32 *)((u8 *)arg0 + 0x28) == temp[0xC6]) {
            func_1516972C(arg0);
        }
    }
}

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
