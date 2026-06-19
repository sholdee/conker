#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void func_1519CDB0(s32, f32, s32);

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C2C60/func_151957B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C2C60/func_1519582C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C2C60/func_15195868.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C2C60/func_15195984.s")

s16 func_15195A84(s16 arg0, s32 arg1, s32 arg2, s32 arg3) {
    return arg0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C2C60/func_15195AA8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C2C60/func_15195D00.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C2C60/func_15195DD4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C2C60/func_15195FB0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C2C60/func_15195FF0.s")

void func_15196318(u8 *arg0, s32 arg1, s32 arg2) {
    if (arg0 != 0) {
        arg0[0x12] = arg1;
        arg0[0x13] = arg2;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C2C60/func_15196330.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C2C60/func_151963B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C2C60/func_15196438.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C2C60/func_15196748.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C2C60/func_15196B4C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C2C60/func_15197148.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C2C60/func_151979F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C2C60/func_15197A0C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C2C60/func_15197A68.s")

struct ConkerStruct15197A7C {
    s32 unk0;
    u8 unk4;
};

extern void func_15147D64(struct ConkerStruct15197A7C *, s32);

void func_15197A7C(u8 *arg0) {
    struct ConkerStruct15197A7C sp18;

    if (arg0 != 0) {
        sp18.unk0 = (s32) arg0;
        sp18.unk4 = arg0[0x3B];
        func_15147D64(&sp18, 8);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C2C60/func_15197AB4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C2C60/func_15197BBC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C2C60/func_15197C10.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C2C60/func_15198054.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C2C60/func_15198110.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C2C60/func_15198570.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C2C60/func_151987CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C2C60/func_1519897C.s")

void func_15198C60(void) {
    func_10010F30(0x1AA, 0x7FFF, 0x40, 0, 0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C2C60/func_15198C90.s")

void func_15198D40(s8 *arg0) {
    u8 *temp = *(u8 **)(arg0 + 0x98);
    if (arg0[0x2C] != 0) {
        u16 val = *(u16 *)(temp + 0x66);
        if (val != 0) {
            func_100111C8(val);
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C2C60/func_15198D7C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C2C60/func_15198D88.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C2C60/func_151990AC.s")

struct ConkerStruct151993B4 {
    char pad0[0x1E];
    u16 unk1E;
    char pad20[0x10];
    u8 unk30;
    char pad31[0x67];
    u8 *unk98;
};

void func_151993B4(struct ConkerStruct151993B4 *arg0) {
    u8 *p;
    p = arg0->unk98;
    arg0->unk30 = 0;
    arg0->unk1E &= 0xFFFD;
    p[6] |= 1;
    p[6] |= 4;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C2C60/func_151993E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C2C60/func_1519944C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C2C60/func_151994B8.s")

void func_15199834(u8 *arg0) {
    struct ConkerStruct15197A7C sp18;

    if (arg0 != 0) {
        sp18.unk0 = (s32) arg0;
        sp18.unk4 = arg0[0x3B];
        func_15147D64(&sp18, 0x26);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C2C60/func_1519986C.s")

void func_15199980(void *);
void func_151478F4(void *);

void func_15199928(void *arg0) {
    func_15199980(arg0);
    func_151478F4(arg0);
}

void func_15147928(void *);

void func_15199954(void *arg0) {
    func_15199980(arg0);
    func_15147928(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C2C60/func_15199980.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C2C60/func_15199A10.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C2C60/func_15199C34.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C2C60/func_1519A9A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C2C60/func_1519B4B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C2C60/func_1519BE1C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C2C60/func_1519BEB8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C2C60/func_1519BF20.s")

void func_1519BF8C(void) {
    func_10010F30(0x1AA, 0x7FFF, 0x40, 0, 0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C2C60/func_1519BFBC.s")

void func_1519C06C(u8 *arg0) {
    u8 *temp = *(u8 **)(arg0 + 0x98);
    u16 val = *(u16 *)(temp + 0x130);
    if (val != 0) {
        func_100111C8(val);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C2C60/func_1519C09C.s")

void func_1519C258(s32);
void func_151617C4(s32);

void func_1519C200(s32 arg0) {
    func_1519C258(arg0);
    func_151617C4(arg0);
}

void func_151617E4(s32);

void func_1519C22C(s32 arg0) {
    func_1519C258(arg0);
    func_151617E4(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C2C60/func_1519C258.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C2C60/func_1519C26C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C2C60/func_1519C4E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C2C60/func_1519C56C.s")

struct ConkerStruct1519C910_inner {
    char pad0[0x84];
    u16 unk84;
};

struct ConkerStruct1519C910 {
    struct ConkerStruct1519C910_inner *unk0;
    char pad4[0x154];
    s32 unk158;
    s32 unk15C;
};

struct ConkerStruct1519C910Outer {
    char pad0[0x98];
    struct ConkerStruct1519C910 *unk98;
};

s32 func_1519C910(struct ConkerStruct1519C910Outer *arg0) {
    struct ConkerStruct1519C910 *p = arg0->unk98;
    struct ConkerStruct1519C910_inner *q = p->unk0;
    u16 v = q->unk84;

    if (v != p->unk158) {
        if (v != p->unk15C) {
            return 0;
        }
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C2C60/func_1519C948.s")

s32 func_1519C970(s32 arg0) {
    func_1519CDB0(arg0, 0.5f, 0x1D);
    return 0;
}

s32 func_1519C998(s32 arg0) {
    func_1519CDB0(arg0, 0.2f, 0x1D);
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C2C60/func_1519C9C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C2C60/func_1519CD64.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C2C60/func_1519CDB0.s")
