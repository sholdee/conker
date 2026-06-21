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

extern f32 sinf(f32);
extern f32 func_15144B68(f32);
extern f32 D_800BE9A4;

s32 func_150F23E0(void *arg0) {
    f32 *p = (f32 *)((u8 *)arg0 + 0x170);

    *(f32 *)((u8 *)arg0 + 0x20) = p[4] * sinf(p[0]);
    *(f32 *)((u8 *)arg0 + 0x28) = p[5] * sinf(p[1]);
    p[0] = func_15144B68(p[2] * D_800BE9A4 + p[0]);
    p[1] = func_15144B68(p[3] * D_800BE9A4 + p[1]);
    return 1;
}

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

extern void func_150A8050(f32 (*)[4], f32, f32, f32);
extern void func_150A7960(f32 *, f32, s32, f32, f32 *, f32 *, f32 *);

struct Sub150F25A0 {
    u8 pad0[0x20];
    f32 unk20;
    f32 unk24;
    f32 unk28;
    u8 pad2C[0xC];
    f32 unk38;
    f32 unk3C;
    f32 unk40;
};

s32 func_150F25A0(struct242 *arg0) {
    struct Sub150F25A0 **pp;
    f32 tmp3;
    f32 tmp2;
    f32 tmp1;
    f32 tmp[16];

    pp = (struct Sub150F25A0 **)&arg0->unk18;
    func_150A8050((f32 (*)[4])&tmp, (*pp)->unk20 * 3.0f, 0.0f, (*pp)->unk28 * 3.0f);
    tmp[12] = (*pp)->unk38;
    tmp[13] = (*pp)->unk3C;
    tmp[14] = (*pp)->unk40;
    func_150A7960(&tmp[0], 0.0f, 0xC3F78000, 0.0f, &tmp1, &tmp2, &tmp3);
    arg0->unk14->unkE = (s16)tmp1;
    arg0->unk14->unk10 = (s16)tmp2;
    arg0->unk14->unk12 = (s16)tmp3;
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_11F780/func_150F26A0.s")

void func_150F2994(s32 arg0, s32 arg1) {
    s32 i;

    for (i = 0; i < 0xE; i++) {
        func_1509BFB0(0, i + 0x4016, arg1);
    }
    func_1509BFB0(0, 0x405D, arg1);
    func_1509BFB0(0, 0x405F, arg1);
    if (((u8 *)D_800D2E4C)[0x15] & 8) {
        func_1509BFB0(0, 0x4063, arg1);
        func_1509BFB0(0, 0x4064, arg1);
        func_1509BFB0(0, 0x4065, arg1);
    }
}
