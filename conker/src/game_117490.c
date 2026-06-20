#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void func_150E5AE0(void);

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
} struct_E9FE0;

typedef struct {
    /* 0x00 */ s32 unk0;
    /* 0x04 */ s32 unk4;
    /* 0x08 */ f32 unk8;
    /* 0x0C */ f32 unkC;
} struct_E9FE0b;

extern f32 D_800A1410;
extern f32 D_800A1414;
void *func_15134DAC(struct_E9FE0 *, s32);

void *func_150E9FE0(void *arg0, s16 arg1, s32 arg2, s32 arg3) {
    struct_E9FE0 sp2C;
    void *temp_v1;
    struct_E9FE0b sp18;

    sp2C.unk0 = *((u8 *)arg0 + 0x3B);
    sp2C.unk4 = arg0;
    sp2C.unk8 = 8;
    sp2C.unkC = -9.0f;
    sp2C.unk10 = -14.0f;
    sp2C.unk14 = 27.0f;
    sp2C.unk18 = -21.0f;
    sp2C.unk1C = -14.0f;
    sp2C.unk20 = 41.0f;
    sp2C.unk24 = 2;
    sp2C.unk26 = 0x3C;
    sp2C.unk28 = 0x3C;
    sp2C.unk2A = arg1;
    sp2C.unk2E = 2;
    sp2C.unk2F = 2;
    sp2C.unk30 = 2;
    sp2C.unk34 = 0.5f;
    sp2C.unk38 = 3;
    sp2C.unk39 = -1;

    sp18.unk0 = 0;
    sp18.unk4 = 0x11111;
    sp18.unk8 = D_800A1410;
    sp18.unkC = D_800A1414;

    temp_v1 = func_15134DAC(&sp2C, 0x10);
    if (temp_v1 != NULL) {
        memcpy((u8 *)temp_v1 + 0x80, &sp18, 0x10);
    }
    return temp_v1;
}

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
