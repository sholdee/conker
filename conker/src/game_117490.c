#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void func_150E5AE0(void);

#pragma GLOBAL_ASM("asm/nonmatchings/game_117490/func_150E9FE0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_117490/func_150EA10C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_117490/func_150EA11C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_117490/func_150EA490.s")

typedef struct {
    /* 0x00 */ s32 unk0;
    /* 0x04 */ s32 unk4;
    /* 0x08 */ u8  unk8;
    /* 0x09 */ u8  pad9[0x3];
    /* 0x0C */ void *unkC;
    /* 0x10 */ u8  unk10;
    /* 0x11 */ u8  pad11[0x3];
    /* 0x14 */ f32 unk14;
    /* 0x18 */ f32 unk18;
    /* 0x1C */ f32 unk1C;
    /* 0x20 */ f32 unk20;
    /* 0x24 */ f32 unk24;
    /* 0x28 */ s16 unk28;
    /* 0x2A */ u8  unk2A;
    /* 0x2B */ u8  unk2B;
    /* 0x2C */ s8  unk2C;
    /* 0x2D */ u8  unk2D;
} struct_EA500;

extern f32 D_800A1438;
void *func_1513418C(struct_EA500 *, s32, u8, s32);

void *func_150EA500(void *arg0, s16 arg1, s32 arg2, s32 arg3) {
    struct_EA500 sp20;

    sp20.unk0 = 0;
    sp20.unk4 = 0;
    sp20.unk8 = *((u8 *)arg0 + 0x3B);
    sp20.unkC = arg0;
    sp20.unk10 = 1;
    sp20.unk14 = 0.0f;
    sp20.unk18 = 0.0f;
    sp20.unk1C = 0.0f;
    sp20.unk20 = 25.0f;
    sp20.unk24 = D_800A1438;
    if (arg1 == -1) {
        sp20.unk28 = 0x12C;
    } else {
        sp20.unk28 = arg1;
    }
    sp20.unk2A = ((arg1 == -1) ? 0 : 4) | 0xA;
    sp20.unk2B = 7;
    sp20.unk2C = -1;
    sp20.unk2D = 6;
    return func_1513418C(&sp20, 0, 0xFF, 0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_117490/func_150EA5CC.s")

void func_150EA8E0(s32 arg0) {
    func_150E5AE0();
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_117490/func_150EA904.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_117490/func_150EA944.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_117490/func_150EAB10.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_117490/func_150EAE24.s")
