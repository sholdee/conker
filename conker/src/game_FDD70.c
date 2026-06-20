#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_FDD70/func_150D08C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_FDD70/func_150D0E90.s")

typedef struct {
    /* 0x00 */ u8  unk0;
    /* 0x01 */ u8  pad1[0x3];
    /* 0x04 */ void *unk4;
    /* 0x08 */ u8  unk8;
    /* 0x09 */ u8  pad9[0x3];
    /* 0x0C */ f32 unkC;
    /* 0x10 */ f32 unk10;
    /* 0x14 */ f32 unk14;
    /* 0x18 */ f32 unk18;
    /* 0x1C */ f32 unk1C;
    /* 0x20 */ f32 unk20;
    /* 0x24 */ u8  unk24;
    /* 0x25 */ u8  pad25[0x1];
    /* 0x26 */ s16 unk26;
    /* 0x28 */ s16 unk28;
    /* 0x2A */ s16 unk2A;
    /* 0x2C */ s16 unk2C;
    /* 0x2E */ u8  unk2E;
    /* 0x2F */ u8  unk2F;
    /* 0x30 */ s8  unk30;
    /* 0x31 */ u8  pad31[0x3];
    /* 0x34 */ f32 unk34;
    /* 0x38 */ u8  unk38;
    /* 0x39 */ s8  unk39;
} struct_10E4;

extern f32 D_800A0890;
void func_15134DAC(struct_10E4 *, s32);

void func_150D10E4(void *arg0, u8 arg1) {
    struct_10E4 sp1C;

    sp1C.unk0 = *((u8 *)arg0 + 0x3B);
    sp1C.unk4 = arg0;
    sp1C.unk8 = 0;
    sp1C.unkC = 0.0f;
    sp1C.unk10 = 0.0f;
    sp1C.unk14 = 0.0f;
    sp1C.unk18 = 0.0f;
    if (arg1 != 0) {
        sp1C.unk1C = -30.0f;
    } else {
        sp1C.unk1C = 30.0f;
    }
    sp1C.unk20 = 0.0f;
    sp1C.unk24 = 2;
    sp1C.unk26 = 0x32;
    sp1C.unk28 = 0x16;
    sp1C.unk2A = 0x7D0;
    sp1C.unk2C = 0;
    sp1C.unk2E = 6;
    sp1C.unk2F = 7;
    sp1C.unk30 = -1;
    sp1C.unk34 = D_800A0890;
    sp1C.unk38 = 0;
    sp1C.unk39 = -1;
    func_15134DAC(&sp1C, 0);
}

extern f32 D_800A0894;

s32 func_150D11B4(void *arg0) {
    *(f32 *)((char *)arg0 + 0x74) = (func_150ADA68() * 150.0f + 350.0f) * D_800A0894;
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_FDD70/func_150D1204.s")
