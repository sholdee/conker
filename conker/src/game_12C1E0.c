#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_12C1E0/func_150FED30.s")

extern s32 func_1514654C(struct127 *, struct126 *, s32, void *, void *, s32);
extern f32 D_800A2050;

void func_150FEFD0(struct127 *arg0, s16 arg1, struct17 *arg2) {
    f32 *p1;
    struct17 *p2;
    struct126 *temp;

    if (arg1 == -1) {
        arg2->unk0 = arg0->x_position;
        arg2->unk4 = arg0->y_position;
        arg2->unk8 = arg0->z_position;
    } else {
        temp = func_1503195C(arg0, arg1, 0);
        if (temp == 0) {
            arg2->unk0 = arg0->x_position;
            arg2->unk4 = arg0->y_position;
            arg2->unk8 = arg0->z_position;
        } else {
            p1 = &D_800A2050;
            p2 = arg2;
            func_1514654C(arg0, temp, 0, &p1, &p2, 1);
        }
    }
}

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

extern void func_151D8868(void *arg0, s32 arg1, s32 arg2, s32 arg3);

struct sp18_150FFC3C {
    /* 0x0 */ u8 unk0;
    /* 0x1 */ u8 unk1;
    /* 0x2 */ s16 unk2;
    /* 0x4 */ u8 unk4;
    /* 0x5 */ u8 unk5;
    /* 0x6 */ s8 unk6;
    /* 0x7 */ u8 unk7;
};

void func_150FFC3C(struct127 *arg0) {
    struct sp18_150FFC3C sp18;

    if (arg0->camera != 0) {
        sp18.unk0 = 1;
        sp18.unk2 = (func_150ADA20() % 0xBU) + 0x14;
        sp18.unk5 = 1 << arg0->camera->unk23D;
        sp18.unk4 = (func_150ADA20() & 1) + 7;
        sp18.unk6 = -1;
        func_151D8868(&sp18, 0, 0xFF, 1);
    }
}

extern s32 D_8008FC8C;
extern u8 *D_8008FC94;
void func_151D5A18(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, u8 arg6);
void func_151D3E6C(s32 arg0, s32 arg1, s32 arg2, s32 arg3);

void func_150FFCC8(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    func_151D5A18(arg0, arg1, arg2, arg3, arg4, D_8008FC8C, *D_8008FC94);
    func_151D3E6C(arg0, arg1, arg1, 0x8003A);
}

void func_15081E0C(struct127 *arg0, s32 arg1, s32 arg2);

void func_150FFD2C(struct127 *arg0, struct127 *arg1, s32 arg2) {
    if (arg1->id == 0x9F || arg1->id == 0xA0) {
        if (!(arg1->unk94 & 0x80)) {
            func_15081E0C(arg1, 4, 0);
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_12C1E0/func_150FFD84.s")
