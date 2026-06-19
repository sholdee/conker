#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_FF5C0/func_150D2110.s")

extern f32 D_800BE9A4;

struct sub150D21CC {
    u8  unk0;
    u8  pad1[3];
    f32 unk4;
    f32 unk8;
    u8  padC[4];
    f32 unk10;
};

struct obj150D21CC {
    u8  pad0[0x28];
    struct sub150D21CC unk28;
};

void func_150D21CC(struct obj150D21CC *arg0) {
    struct sub150D21CC *p = &arg0->unk28;

    arg0->unk28.unk4 += D_800BE9A4;
    if (arg0->unk28.unk10 < arg0->unk28.unk4) {
        do {
            p->unk4 -= p->unk10;
        } while (p->unk10 < p->unk4);
    }
    if (p->unk4 <= p->unk8) {
        p->unk0 = 1;
        func_1515D4D4(255, 255, 255, 255);
    } else {
        p->unk0 = 0;
    }
}

void func_150D22D4(s32 arg0);

void func_150D227C(s32 arg0) {
    func_150D22D4(arg0);
    func_1514933C((struct260 *)arg0);
}

void func_150D22A8(s32 arg0) {
    func_150D22D4(arg0);
    func_15149368((struct260 *)arg0);
}

extern u8 D_800D9900;

void func_150D22D4(s32 arg0) {
    D_800D9900--;
}

s32 func_1517F08C(s32, s32, s32, s32, s32, s32);

s32 func_150D22F4(s32 arg0, s32 arg1, s32 arg2) {
    if (*(u8 *)(arg1 + 0x28) == 1) {
        arg0 = func_1517F08C(arg0, *(u8 *)(arg1 + 0x3C), 0xFF, 0xFF, 0xFF, (s16)arg2);
    } else {
        arg0 = func_1517F08C(arg0, *(u8 *)(arg1 + 0x3D), 0, 0, 0, (s16)arg2);
    }
    return arg0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_FF5C0/func_150D2374.s")
