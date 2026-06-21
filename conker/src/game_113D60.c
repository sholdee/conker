#include <ultra64.h>
#include "functions.h"
#include "variables.h"

typedef struct {
    /* 0x0 */ s32 unk0;
    /* 0x4 */ s32 unk4;
    /* 0x8 */ s32 unk8;
} Struct150E81A8Vec;

typedef struct {
    /* 0x00 */ s16 unk00;
    /* 0x02 */ s16 unk02;
    /* 0x04 */ s16 unk04;
    /* 0x06 */ s16 unk06;
    /* 0x08 */ s32 unk08;
    /* 0x0C */ s32 unk0C;
    /* 0x10 */ Struct150E81A8Vec unk10;
    /* 0x1C */ f32 unk1C;
    /* 0x20 */ f32 unk20;
    /* 0x24 */ f32 unk24;
    /* 0x28 */ f32 unk28;
    /* 0x2C */ f32 unk2C;
    /* 0x30 */ f32 unk30;
    /* 0x34 */ s32 unk34;
    /* 0x38 */ s32 unk38;
    /* 0x3C */ f32 unk3C;
    /* 0x40 */ f32 unk40;
    /* 0x44 */ f32 unk44;
    /* 0x48 */ f32 unk48;
    /* 0x4C */ s16 unk4C;
    /* 0x4E */ s16 unk4E;
    /* 0x50 */ s16 unk50;
    /* 0x52 */ s16 unk52;
    /* 0x54 */ s16 unk54;
    /* 0x56 */ s16 unk56;
    /* 0x58 */ s8 unk58;
} Struct150E81A8;

typedef struct {
    /* 0x0 */ u8 unk0;
    /* 0x1 */ u8 unk1;
    /* 0x2 */ s16 unk2;
    /* 0x4 */ u8 unk4;
    /* 0x5 */ u8 unk5;
    /* 0x6 */ s8 unk6;
    /* 0x7 */ u8 unk7;
} Struct150E81A8Small;

extern Struct150E81A8Vec D_800A1290[];
extern f32 D_800A1354;
extern f32 D_800A1358;
extern f32 D_800A135C;
extern f32 D_800A1360;
extern f32 D_800A1364;
extern void func_151D3FF4(Struct150E81A8Vec *arg0, u8 arg1, s32 arg2);
extern void func_1514FCE8(Struct150E81A8 *arg0, u8 arg1, s32 arg2);
extern void func_151D8868(void *arg0, s32 arg1, s32 arg2, s32 arg3);


#pragma GLOBAL_ASM("asm/nonmatchings/game_113D60/func_150E68B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_113D60/func_150E6B84.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_113D60/func_150E6E34.s")

extern s32 func_1514470C(struct134 *, s32);

void func_150E6ED8(s32 arg0) {
    func_1514470C((&D_800D9A20)[func_150ADA20() & 1], arg0);
}

extern f32 *D_80088A44[];

void func_150E6F18(f32 *out) {
    f32 *p;
    f32 t;
    p = D_80088A44[(u32)func_150ADA20() % 6];
    t = func_150ADA68();
    out[0] = p[0] + (p[3] - p[0]) * t;
    out[1] = p[1] + (p[4] - p[1]) * t;
    out[2] = p[2] + (p[5] - p[2]) * t;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_113D60/func_150E6FAC.s")

void func_150E70CC(f32 *arg0, f32 *arg1) {
    arg0[0] = arg1[5];
    arg0[1] = arg1[6];
    arg0[2] = arg1[7];
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_113D60/func_150E70EC.s")

extern f32 D_800A1324;
extern f32 D_800A1328;
extern f32 D_800A132C;
extern f32 D_800A1330;
extern f32 D_800A1334;
extern f32 D_800A1338;
extern f32 D_800A133C;

void func_150E71E4(s32 arg0, s32 arg1, f32 *arg2, f32 *out) {
    out[0] = func_150484A0(arg2[0], arg2[2]);
    out[2] = D_800A1324;
    out[4] = func_150ADA68() * D_800A1328;
    out[6] = func_150ADA68() * D_800A132C;
    out[1] = D_800A1330;
    out[3] = D_800A1334;
    out[5] = func_150ADA68() * D_800A1338;
    out[7] = func_150ADA68() * D_800A133C;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_113D60/func_150E7290.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_113D60/func_150E75A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_113D60/func_150E76D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_113D60/func_150E7994.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_113D60/func_150E7C9C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_113D60/func_150E7FEC.s")

void func_150E81A8(u8 arg0, s32 arg1, s32 arg2) {
    Struct150E81A8Vec sp84;
    Struct150E81A8 sp28;
    Struct150E81A8Small sp20;

    if (arg0 == 4 || arg0 == 5 || arg0 == 6 || arg0 == 7) {
        sp84 = D_800A1290[arg0];
        *(f32 *)&sp84.unk4 += 200.0f;
        func_151D3FF4(&sp84, ((u8 *)&arg1)[3], arg2);

        sp28.unk00 = 0;
        sp28.unk02 = 0xFF;
        sp28.unk04 = -0x40;
        sp28.unk06 = 0x4D;
        sp28.unk08 = 0xA;
        sp28.unk0C = 5;
        sp28.unk10 = sp84;
        sp28.unk1C = 252.0f;
        sp28.unk20 = 117.0f;
        sp28.unk24 = 308.0f;
        sp28.unk28 = 256.0f;
        sp28.unk2C = D_800A1354;
        sp28.unk30 = D_800A1358;
        sp28.unk34 = 4;
        sp28.unk38 = 7;
        sp28.unk3C = 27.0f;
        sp28.unk40 = D_800A135C;
        sp28.unk44 = D_800A1360;
        sp28.unk48 = D_800A1364;
        sp28.unk4C = 25;
        sp28.unk4E = 15;
        sp28.unk50 = 100;
        sp28.unk52 = 100;
        sp28.unk54 = 12;
        sp28.unk56 = 20;
        sp28.unk58 = 0;

        func_1514FCE8(&sp28, ((u8 *)&arg1)[3], arg2);

        sp20.unk0 = 1;
        sp20.unk2 = (func_150ADA20() % 0xBU) + 0x1E;
        sp20.unk4 = 8;
        sp20.unk6 = -1;
        sp20.unk5 = 1;
        func_151D8868(&sp20, 0, 0xFF, 0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_113D60/func_150E83AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_113D60/func_150E8470.s")

extern s32 func_15131828(s32, s32, s32, s32);

s32 func_150E8824(s32 arg0, s32 arg1) {
    func_15131828(arg0, arg0 + 0xAC, arg0 + 0xA8, arg0 + 0xAA);
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_113D60/func_150E8854.s")

extern f32 D_800A1378;
extern void func_150E8930(void *);

void func_150E88C0(void *arg0) {
    *(f32 *)((u8 *)arg0 + 0x28) -= D_800BE9A4;
    if (*(f32 *)((u8 *)arg0 + 0x28) < 0.0f) {
        *(f32 *)((u8 *)arg0 + 0x28) = (func_150ADA68() * D_800A1378) + 201.0f;
        func_150E8930(arg0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_113D60/func_150E8930.s")

extern f32 D_800A137C;
extern f32 D_800A1380;

void func_150E8A80(void) {
    struct260 *temp_v0;
    struct {
        f32 unk0;
        f32 unk4;
        f32 unk8;
    } sp38;

    sp38.unk0 = D_800A137C;
    sp38.unk4 = D_800A1380;
    sp38.unk8 = 0.0f;

    temp_v0 = func_15149130((func_150ADA20() % 0x29U) + 0x1E, -1, 0x33, -1, 1, 0, (struct37 *)0xC, 0xFF, 1);
    if (temp_v0 != NULL) {
        memcpy((void *)((s32)temp_v0 + 0x28), &sp38, 0xC);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_113D60/func_150E8B1C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_113D60/func_150E8D5C.s")

extern f32 D_800A13B0;
extern f32 D_800A13B4;

void func_150E90DC(void) {
    struct260 *temp_v0;
    struct {
        f32 unk0;
        f32 unk4;
        f32 unk8;
    } sp38;

    sp38.unk0 = D_800A13B0;
    sp38.unk4 = D_800A13B4;
    sp38.unk8 = 0.0f;

    temp_v0 = func_15149130((func_150ADA20() % 0x1AU) + 0x5, -1, 0x36, -1, 1, 0, (struct37 *)0xC, 0xFF, 1);
    if (temp_v0 != NULL) {
        memcpy((void *)((s32)temp_v0 + 0x28), &sp38, 0xC);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_113D60/func_150E9178.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_113D60/func_150E93DC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_113D60/func_150E971C.s")
