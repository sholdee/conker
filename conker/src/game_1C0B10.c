#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_1C0B10/func_15193660.s")

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
} struct_10E4_1937F4;

extern f32 D_800A81E4;
void func_15134DAC(struct_10E4_1937F4 *, s32);

void func_151937F4(s32 *arg0, s32 arg1, s32 arg2) {
    struct_10E4_1937F4 sp1C;

    if (arg0 != 0) {
        if (arg0[0] != 0) {
            sp1C.unk0 = *((u8 *)arg0 + 0x3B);
            sp1C.unk4 = arg0;
            sp1C.unk8 = 0;
            sp1C.unkC = -28.0f;
            sp1C.unk10 = 6.0f;
            sp1C.unk14 = 1.0f;
            sp1C.unk18 = -58.0f;
            sp1C.unk1C = -3.0f;
            sp1C.unk20 = -31.0f;
            sp1C.unk24 = 2;
            sp1C.unk26 = 30;
            sp1C.unk28 = 25;
            sp1C.unk2A = 750;
            sp1C.unk2E = 3;
            sp1C.unk2F = 3;
            sp1C.unk30 = -1;
            sp1C.unk34 = D_800A81E4;
            sp1C.unk38 = 4;
            sp1C.unk39 = -1;
            func_15134DAC(&sp1C, 0);
        }
    }
}

extern f32 D_800A81E8;

s32 func_151938E4(f32 *arg0) {
    arg0[0x1D] = D_800A81E8;
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C0B10/func_151938FC.s")
