#include <ultra64.h>

#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_16DC80/func_151407D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_16DC80/func_151408A4.s")

void func_151411A4(struct210 *arg0) {
    func_1513CA6C(arg0);
}

void func_151411C4(struct210 *arg0) {
    func_1513CAA0(arg0);
}

extern s32 D_800DC9F0;
extern void (*D_80089F9C[])(void *);
void func_1517E134(void *);

struct conk1411E4 { u8 pad0[0x154]; void *unk154; u8 pad158[0x10]; u8 unk168; };

void func_151411E4(struct conk1411E4 *arg0) {
    void **pp = &arg0->unk154;

    if (*pp != 0) {
        func_1517E134(*pp);
    }
    D_800DC9F0 -= 1;
    D_80089F9C[arg0->unk168](arg0);
}

extern s32 D_800DC9F0;
extern void (*D_80089FE4[])(void *);

void func_15141250(void *arg0) {
    s32 **pp = (s32 **)((u8 *)arg0 + 0x154);
    if (*pp != 0) {
        func_1517E134(*pp);
    }
    D_800DC9F0 -= 1;
    D_80089FE4[*(u8 *)((u8 *)arg0 + 0x168)](arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_16DC80/func_151412BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_16DC80/func_1514143C.s")

extern f32 D_800BE9A4;

struct conk141478b {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    f32 unk14;
    f32 unk18;
};

struct conk141478a {
    u8 pad0[0x48];
    f32 unk48;
};

struct conk141478 {
    u8 pad0[0x110];
    struct conk141478a unk110;
    u8 pad15C[0x14];
    struct conk141478b unk170;
};

s32 func_15141478(struct conk141478 *arg0) {
    struct conk141478b *v1;
    struct conk141478a *a0;

    a0 = &arg0->unk110;
    v1 = &arg0->unk170;
    v1->unk10 -= D_800BE9A4;
    if (v1->unk10 < 0.0f) {
        v1->unk10 = func_150ADA68() * v1->unk14;
        if (func_150ADA20() & 3) {
            v1->unkC = func_150ADA68() * (v1->unk0 - v1->unk4) + v1->unk4;
        } else {
            v1->unkC = func_150ADA68() * (v1->unk8 - v1->unk0) + v1->unk0;
        }
    }
    a0->unk48 = a0->unk48 + (v1->unkC - a0->unk48) * v1->unk18;
    return 1;
}

s32 func_15141564(u8 *arg0) {
    f32 *v1 = (f32 *)(arg0 + 0x170);
    f32 *p;

    *(f32 *)(arg0 + 0x158) = v1[1] * sinf(*(f32 *)(arg0 + 0x178)) + v1[0];
    p = &v1[2];
    *p = v1[3] * D_800BE9A4 + *p;
    *p = func_15144B68(*p);
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_16DC80/func_151415D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_16DC80/func_151416E8.s")

// ???
#pragma GLOBAL_ASM("asm/nonmatchings/game_16DC80/func_151417C4.s")

s32 func_15141818(s32 arg0, s32 arg1) {
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_16DC80/func_1514182C.s")
// f32 func_1514182C(void *arg0, void *arg1, s32 arg2, f32 arg3, s32 arg4, s32 arg5) {
//     f32 sp6C;
//     f32 sp68;
//     f32 sp64;
//     ? sp34;
//     f32 temp_f0;
//     f32 temp_f12;
//     f32 temp_f2;
//
//     func_150A8050(&sp34, arg4, 0, arg5);
//     sp64 = arg1->unk0;
//     sp68 = arg1->unk4;
//     sp6C = arg1->unk8;
//     func_150A7960(&sp34, 0, arg2, 0, arg0 + 0x34, arg0 + 0x38, arg0 + 0x3C);
//     temp_f0 = arg0->unk34;
//     temp_f2 = arg0->unk38;
//     temp_f12 = arg0->unk3C;
//     arg0->unk40 = (f32) (temp_f0 + ((temp_f0 - arg1->unk0) * arg3 * 500.0f));
//     arg0->unk44 = (f32) (temp_f2 + ((temp_f2 - arg1->unk4) * arg3 * 500.0f));
//     arg0->unk48 = (f32) (temp_f12 + ((temp_f12 - arg1->unk8) * arg3 * 500.0f));
//     return temp_f0;
// }

#pragma GLOBAL_ASM("asm/nonmatchings/game_16DC80/func_15141928.s")
// s32 func_15141928(void *arg0) {
//     void *temp_v0 = arg0->unk178;
//     func_1514182C(arg0, arg0->unk17C, arg0->unk170, arg0->unk174, temp_v0->unk0, temp_v0->unk8);
//     return 1;
// }
