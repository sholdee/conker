#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_1A7260/func_15179DB0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1A7260/func_15179FE0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1A7260/func_1517A1EC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1A7260/func_1517A394.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1A7260/func_1517A3A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1A7260/func_1517A644.s")

struct func_1517A84C_obj {
    u8 pad0[0x90];
    s16 unk90;
    s16 unk92;
    s16 unk94;
    s16 unk96;
    s16 unk98;
    s16 unk9A;
    s8 unk9C;
    s8 unk9D;
    s8 unk9E;
    u8 unk9F;
    s16 unkA0;
    s16 unkA2;
    s16 unkA4;
    u16 unkA6;
    f32 unkA8;
    u16 unkAC;
    u16 unkAE;
    s16 unkB0;
    u8 unkB2;
    s8 unkB3;
};

void func_1517A84C(struct func_1517A84C_obj *arg0) {
    s32 temp_v0;
    s32 temp_v1;

    temp_v0 = arg0->unkA6;
    if (temp_v0 == 0) {
        arg0->unk90 += arg0->unkA0;
        temp_v0 = arg0->unkA2;
        arg0->unk92 += temp_v0;
        arg0->unk94 += arg0->unkA4;
        if (temp_v0 > 0) {
            arg0->unkA2 = temp_v0 - 1;
            if (arg0->unkA2 <= 0) {
                arg0->unkA2 = -3;
            }
        }
        temp_v1 = arg0->unkB0;
        temp_v0 = arg0->unk92 - temp_v1;
        if (temp_v0 <= 0) {
            arg0->unk96 = 0x5A;
            arg0->unk9A = 0;
            arg0->unkA6 = 0x3C;
            arg0->unk92 = temp_v1;
        } else {
            arg0->unk96 += arg0->unk9C;
            arg0->unk98 += arg0->unk9D;
            arg0->unk9A += arg0->unk9E;
        }
    } else {
        temp_v0 -= D_800BE9E4;
        if (temp_v0 > 0) {
            arg0->unkA6 = temp_v0;
            arg0->unkB3 = (temp_v0 << 8) / 0x3C;
        } else {
            func_1516972C((struct102 *)arg0);
        }
    }
}

extern s16 D_800DD450;
extern s32 func_1517A394();

s32 func_1517A958(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    arg2 = arg2;
    arg3 = arg3;
    D_800DD450 = -1;
    if ((arg1 == 0xC) || (arg1 == 0x59)) {
        arg0 = func_1517A394();
    }
    return arg0;
}

extern s32 D_800DD1B0;
extern s32 D_80090614;
struct sp34_t { s32 unk0[5]; };
extern s32 func_15094F70(s32, s32, s32, struct sp34_t*, s32, s32, s32, s32, s32);

s32 func_1517A9A8(s32 arg0, s32 arg1) {
    struct sp34_t sp34;

    if (arg1 != D_800DD1B0) {
        arg0 = func_15094F70(arg0, (s32)&D_80090614, (s32)((u32)arg1 << 8), &sp34, 0, 0, 0, 2, 3);
        D_800DD1B0 = arg1;
    }
    return arg0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1A7260/func_1517AA20.s")

extern void func_1510B7B4(s32, s32);

void func_1517AB7C(s32 arg0, s32 arg1, s16 arg2) {
    func_1510B7B4(arg0, arg2);
}
