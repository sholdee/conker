#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_E4070/func_150B6BC0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_E4070/func_150B6C90.s")

extern s32 *D_800D9898[];
extern s32 *D_800D98A4[];

void func_150B6D34(void) {
    s32 i;
    s32 *e;

    i = 0;
    do {
        e = D_800D9898[i + 5];
        if (e != 0) {
            e[8] = 1;
        }
        i++;
    } while (&D_800D98A4[0] != &D_800D9898[i]);
    D_800D9890 = 3;
}

extern s32 *D_800D9894;
extern s32 *D_800D98C0[];

void func_150B6D78(void) {
    s32 i;

    if (D_800D9894 != 0) {
        func_1516972C((struct102 *)D_800D9894);
        D_800D9894 = 0;
    }
    i = 0;
    do {
        if (D_800D9898[i] != 0) {
            func_1516972C((struct102 *)D_800D9898[i]);
            D_800D9898[i] = 0;
        }
        i++;
    } while (&D_800D98C0[0] != &D_800D9898[i]);
    D_800D9890 = 3;
}

void func_150B6DFC(void *arg0) {
    *(s16 *)((u8 *)arg0 + 0x34) += D_800BE9E4 * 0x30;
    if (*(s16 *)((u8 *)arg0 + 0x34) >= 0x801) {
        *(s16 *)((u8 *)arg0 + 0x34) = -0xC00;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_E4070/func_150B6E3C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_E4070/func_150B709C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_E4070/func_150B71A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_E4070/func_150B7220.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_E4070/func_150B73F0.s")

typedef struct {
    /* 0x00 */ void *unk0;
    /* 0x04 */ u8  pad4[0x10];
    /* 0x14 */ s16 unk14;
    /* 0x16 */ s16 unk16;
    /* 0x18 */ s16 unk18;
    /* 0x1A */ u8  pad1A[0x2];
    /* 0x1C */ f32 unk1C;
    /* 0x20 */ f32 unk20;
    /* 0x24 */ s16 unk24;
    /* 0x26 */ s16 unk26;
    /* 0x28 */ s16 unk28;
    /* 0x2A */ s16 unk2A;
    /* 0x2C */ s16 unk2C;
    /* 0x2E */ s16 unk2E;
    /* 0x30 */ u8  unk30;
    /* 0x31 */ u8  unk31;
    /* 0x32 */ u8  unk32;
    /* 0x33 */ u8  unk33;
    /* 0x34 */ u8  unk34;
    /* 0x35 */ u8  unk35;
    /* 0x36 */ u8  unk36;
    /* 0x37 */ u8  unk37;
    /* 0x38 */ u8  unk38;
    /* 0x39 */ u8  unk39;
} struct_7484;

extern u8 D_800918DC;
struct102 *func_15169968(struct_7484 *);

void func_150B7484(void) {
    struct_7484 sp1C;

    sp1C.unk31 = 1;
    sp1C.unk2C = 0x58;
    sp1C.unk1C = 60.0f;
    sp1C.unk20 = 60.0f;
    sp1C.unk14 = 0;
    sp1C.unk16 = 0;
    sp1C.unk18 = 0;
    sp1C.unk2E = 0x58;
    sp1C.unk30 = 6;
    sp1C.unk0 = &D_800918DC;
    sp1C.unk32 = 0xFF;
    sp1C.unk33 = 0;
    sp1C.unk34 = 0;
    sp1C.unk35 = 0xFF;
    sp1C.unk24 = 0;
    sp1C.unk26 = 0;
    sp1C.unk39 = 0;
    sp1C.unk36 = 7;
    sp1C.unk37 = 0x15;
    sp1C.unk38 = 1;
    sp1C.unk28 = 0x51;
    sp1C.unk2A = 0x51;
    if (D_800D9898[0] != 0) {
        func_1516972C((struct102 *)D_800D9898[0]);
    }
    D_800D9898[0] = (s32 *)func_15169968(&sp1C);
    D_800D9890 = 3;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_E4070/func_150B7560.s")

void func_150B76BC(s32, s32);

void func_150B765C(void) {
    func_150B76BC(0x3C, 1);
    D_800D9890 = 3;
}

void func_150B768C(void) {
    func_150B76BC(0xE6, 2);
    D_800D9890 = 3;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_E4070/func_150B76BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_E4070/func_150B77A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_E4070/func_150B791C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_E4070/func_150B7B40.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_E4070/func_150B82D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_E4070/func_150B85C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_E4070/func_150B879C.s")
