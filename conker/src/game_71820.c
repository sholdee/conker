#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_71820/func_15044370.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_71820/func_15044380.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_71820/func_1504452C.s")

void func_15044658(void) {
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_71820/func_15044660.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_71820/func_150448D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_71820/func_15044964.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_71820/func_15044A28.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_71820/func_15044B78.s")

struct conker15044CE4 {
    char pad0[6];
    s16 unk6;
    s16 unk8;
    s16 unkA;
    char padC[4];
    s16 unk10;
    s16 unk12;
    s16 unk14;
    char pad16[2];
    s16 *unk18;
    s16 *unk1C;
};

extern void func_15044B78(struct conker15044CE4 *);

void func_15044CE4(struct conker15044CE4 *arg0) {
    s16 *sp18 = arg0->unk18;
    s32 temp;

    arg0->unk6 = sp18[0];
    arg0->unk8 = sp18[1];
    arg0->unkA = sp18[2];
    temp = arg0->unk1C[0] / 32;
    arg0->unk10 = temp;
    arg0->unk12 = temp;
    arg0->unk14 = temp;
    func_15044B78(arg0);
}

extern s32 func_1505D1C4(f32, f32, f32, s32, s32, u16, s32, s32);

s32 func_15044D40(struct conker15044CE4 *arg0) {
    func_1505D1C4(arg0->unk6, arg0->unk8, arg0->unkA, arg0->unk10, 0xFF, 0, 0, 0);
    return 0;
}

s32 func_1505D024(struct127 *arg0, s32 arg1, u16 arg2, s32 arg3);

void func_15044DA0(void) {
    if (D_800CC2D0[0].stunned != 0) {
        return;
    }
    if (D_800CC2D0[0].immune != 0) {
        return;
    }
    func_1505D024(&D_800CC2D0[0], 5, D_800CC2D0[0].unk7A, -1);
}

void func_15044DE8(void) {
    if (D_800CC2D0[0].stunned != 0) {
        return;
    }
    if (D_800CC2D0[0].immune != 0) {
        return;
    }
    if (D_800C35EA != 1) {
        func_1505D024(&D_800CC2D0[0], 4, D_800CC2D0[0].unk7A, -1);
    }
}

void func_15044E40(void) {
    if (D_800CC2D0[0].stunned != 0) {
        return;
    }
    if (D_800CC2D0[0].immune != 0) {
        return;
    }
    func_1505D024(&D_800CC2D0[0], 0x40, D_800CC2D0[0].unk7A, -1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_71820/func_15044E88.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_71820/func_15044ED0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_71820/func_150450CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_71820/func_1504530C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_71820/func_15045384.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_71820/func_1504554C.s")

extern void func_1510F800(s32);
extern s32 func_150A6500(s16, s16, s32, u16);

struct conker15045714 {
    f32 unk0;
    f32 unk4;
    f32 unk8;
};

void func_15045714(struct conker15045714 *arg0, s32 arg1, s32 *arg2, s32 arg3) {
    func_1510F800(2);
    *arg2 = func_150A6500((s16)arg0->unk0, (s16)arg0->unk8, arg3, (u16)arg1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_71820/func_15045780.s")

extern s32 func_15047004(s32, s32, s32);
extern s32 func_15045780(s32, u16, s32, s32);

s32 func_15045800(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    switch (func_15047004(arg0, arg2, arg3)) {
    case 0:
        return func_15045780(arg0, (u16)arg1, arg2, arg3);
    case 1:
        return 0;
    case 2:
        return 1;
    default:
        break;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_71820/func_15045880.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_71820/func_15045AE4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_71820/func_15045D48.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_71820/func_15045F8C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_71820/func_150461D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_71820/func_15046460.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_71820/func_150466F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_71820/func_1504697C.s")

s32 func_150470B0(s32, s32, s32);
s32 func_150466F8(s32, u16, s32, s32);

s32 func_15046C00(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    switch (func_150470B0(arg0, arg2, arg3)) {
    case 0:
        return func_150466F8(arg0, (u16)arg1, arg2, arg3);
    case 1:
        return 0;
    case 2:
        return 1;
    default:
        break;
    }
}

s32 func_1504697C(s32, u16, s32, s32);

s32 func_15046C80(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    switch (func_15047004(arg0, arg2, arg3)) {
    case 0:
        return func_1504697C(arg0, (u16)arg1, arg2, arg3);
    case 1:
        return 0;
    case 2:
        return 1;
    default:
        break;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_71820/func_15046D00.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_71820/func_15046F84.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_71820/func_15047004.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_71820/func_150470B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_71820/func_1504715C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_71820/func_150472C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_71820/func_15047390.s")

void func_15047390(f32 mf[4][4], f32, f32, f32, f32, f32, f32, f32, f32, f32);

void func_15047688(Mtx *arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, f32 arg8, f32 arg9) {
    f32 sp30[4][4];

    func_15047390(&sp30, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9);
    guMtxF2L(&sp30, arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_71820/func_15047700.s")

void func_15047700(f32 mf[4][4], s32, f32, f32, f32, f32, f32, f32, f32, f32, f32);

void func_15047B80(Mtx *arg0, s32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, f32 arg8, f32 arg9, f32 arg10) {
    f32 sp38[4][4];

    func_15047700(&sp38, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10);
    guMtxF2L(&sp38, arg0);
}
