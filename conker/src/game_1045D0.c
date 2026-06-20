#include <ultra64.h>
#include "functions.h"
#include "variables.h"


extern f32 D_800A0AE0;
extern f32 D_800A0AE4;
extern f32 D_800A0AE8;
void func_151C04F8(f32 *, u8, s32);
void func_151C05A4(f32 *, u8, s32);
void func_151C05F0(f32 *, u8, s32);

typedef struct {
    /* 0x0 */ s32 a;
    /* 0x4 */ s32 b;
    /* 0x8 */ s32 c;
} Struct3W;

typedef struct {
    /* 0x00 */ s16 unk00;
    /* 0x02 */ s16 unk02;
    /* 0x04 */ s16 unk04;
    /* 0x06 */ s16 unk06;
    /* 0x08 */ s32 unk08;
    /* 0x0C */ s32 unk0C;
    /* 0x10 */ Struct3W unk10;
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
} Struct150D7120;

void func_150D7120(f32 *arg0, u8 arg1, s32 arg2) {
    Struct150D7120 sp1C;

    func_151C04F8(arg0, arg1, arg2);
    func_151C05A4(arg0, arg1, arg2);
    func_151C05F0(arg0, arg1, arg2);

    sp1C.unk00 = 0;
    sp1C.unk02 = 0xFF;
    sp1C.unk04 = -0x40;
    sp1C.unk06 = 0x47;
    sp1C.unk08 = 6;
    sp1C.unk0C = 4;
    sp1C.unk10 = *(*(Struct3W **) &arg0);
    sp1C.unk1C = 23.0f;
    sp1C.unk20 = 30.0f;
    sp1C.unk24 = 45.0f;
    sp1C.unk28 = 53.0f;
    sp1C.unk2C = 203.0f;
    sp1C.unk30 = 414.0f;
    sp1C.unk34 = 7;
    sp1C.unk38 = 3;
    sp1C.unk3C = 15.0f;
    sp1C.unk40 = D_800A0AE0;
    sp1C.unk44 = D_800A0AE4;
    sp1C.unk48 = D_800A0AE8;
    sp1C.unk4C = 25;
    sp1C.unk4E = 15;
    sp1C.unk50 = 100;
    sp1C.unk52 = 100;
    sp1C.unk54 = 12;
    sp1C.unk56 = 20;
    sp1C.unk58 = 0;

    func_1514FCE8(&sp1C, arg1, arg2);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1045D0/func_150D728C.s")
