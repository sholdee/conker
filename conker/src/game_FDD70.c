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

extern f32 D_800A0898;
extern f32 D_800A089C;
extern f32 D_800A08A0;
extern f32 D_800A08A4;

void func_151DB5D0(s32, f32 *, f32 *, f32, f32, f32, f32, s32, s32, s32, s32, s32, s32, s32);

void func_150D1204(f32 *arg0, f32 *arg1, f32 *arg2, f32 *arg3, f32 arg4, void *arg5) {
    f32 sp6C[3];
    f32 t0;
    f32 t1;
    f32 t2;
    f32 sp54[3];
    s32 pad50;
    s32 r1;
    f32 f2;
    f32 f1;

    sp6C[0] = arg2[0] * arg4 + arg0[0];
    sp6C[1] = arg2[1] * arg4 + arg0[1];
    sp6C[2] = arg2[2] * arg4 + arg0[2];

    t0 = arg3[0] * arg4 + arg1[0];
    t1 = arg3[1] * arg4 + arg1[1];
    t2 = arg3[2] * arg4 + arg1[2];

    sp54[0] = *(f32 *)((u8 *)arg5 + 0x74) * (t0 - sp6C[0]);
    sp54[1] = *(f32 *)((u8 *)arg5 + 0x74) * (t1 - sp6C[1]);
    sp54[2] = *(f32 *)((u8 *)arg5 + 0x74) * (t2 - sp6C[2]);

    f1 = func_150ADA68();
    f2 = func_150ADA68();
    r1 = func_150ADA20();

    func_151DB5D0(0, sp6C, sp54, f1 * 61.0f + 60.0f, D_800A0898, D_800A089C,
                  f2 * D_800A08A0 + D_800A08A4, (r1 & 0xF) + 0x23,
                  (s32)((u32)func_150ADA20() % 0x9CU) + 0x64, 0x1E, 8, 0,
                  *((u8 *)arg5 + 0xC), *((u8 *)arg5 + 1));
}
