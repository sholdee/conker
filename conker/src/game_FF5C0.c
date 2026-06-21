#include <ultra64.h>
#include "functions.h"
#include "variables.h"


extern u8 D_800D9900;
struct260 *func_15149130(s16 arg0, s8 arg1, s8 arg2, s8 arg3, u8 arg4, u8 arg5, struct37 *arg6, u8 arg7, s32 arg8);

struct sub150D2110 {
    u8  unk0;
    u8  pad1[3];
    f32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    u8  unk14;
    u8  unk15;
    u8  pad16[2];
};

void func_150D2110(s16 arg0, f32 arg1, f32 arg2, u8 arg3, u8 arg4, u8 arg5, s32 arg6) {
    struct sub150D2110 sp38;
    struct260 *temp_v0;

    D_800D9900++;

    sp38.unk8 = arg1;
    sp38.unkC = arg2;
    sp38.unk10 = arg1 + arg2;
    sp38.unk0 = 0;
    sp38.unk4 = 0.0f;
    sp38.unk14 = arg3;
    sp38.unk15 = arg4;

    temp_v0 = func_15149130(arg0, -1, 0x2F, 2, 1, 0x26, (struct37 *)0x18, arg5, arg6);
    if (temp_v0 != NULL) {
        memcpy((u8 *)temp_v0 + 0x28, &sp38, 0x18);
    }
}

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

struct sub150D2374 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s16 unkC;
    s16 unkE;
    f32 unk10;
    f32 unk14;
    u8 unk18;
    u8 unk19;
};

void func_150D2374(u8 *arg0) {
    struct sub150D2374 *p;
    s32 temp;

    p = (struct sub150D2374 *)(arg0 + 0x28);
    p->unk8 -= D_800BE9E4;
    if (p->unk8 < 0) {
        temp = func_150ADA20();
        func_150D2110((s16)((temp % (u32)(p->unkE + 1)) + p->unkC), p->unk10, p->unk14, p->unk18, p->unk19, arg0[0xC], arg0[1]);
        p->unk8 = (func_150ADA20() % (u32)(p->unk4 + 1)) + p->unk0;
    }
}
