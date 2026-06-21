#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern f32 D_800A06DC;
extern f32 D_800A06E0;
extern f32 D_800A06E4;
extern f32 D_800A06E8;
extern f32 D_800A06EC;
extern f32 D_800A06F0;
extern f32 D_800A06F4;
extern f32 D_800A06F8;

void func_15143794(s32, s32, f32, f32 *);
s32 func_15132A4C(void *, s32, s32, s32, u8, s32);

#pragma GLOBAL_ASM("asm/nonmatchings/game_F9430/func_150CBF80.s")

extern f32 D_800BE9A4;

typedef struct {
    s16 unk0;
    f32 unk4;
} CC638Sub;

typedef struct {
    char pad0[0x1C];
    s16 unk1C;
    char pad1E[0x2C - 0x1E];
    f32 unk2C;
    f32 unk30;
    char pad34[0x58 - 0x34];
    s32 unk58;
    u8 unk5C;
    char pad5D[0x128 - 0x5D];
    CC638Sub unk128;
} CC638Struct;

s32 func_150CC638(CC638Struct *arg0) {
    CC638Sub *sub;

    if (arg0->unk58 & 1) {
        sub = &arg0->unk128;
        if (arg0->unk1C < 0x20) {
            if ((arg0->unk1C << 3) < arg0->unk5C) {
                *(u8*)((u8*)sub - 0xCC) = arg0->unk1C << 3;
            }
        }
        if (sub->unk0 < arg0->unk1C) {
            f32 v = sub->unk4 * D_800BE9A4;
            arg0->unk2C = arg0->unk2C + v;
            arg0->unk30 = arg0->unk30 + v;
        }
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_F9430/func_150CC6B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_F9430/func_150CC8D4.s")

s32 func_150CCA7C(s32 arg0, s32 arg1, f32 arg2, f32 arg3, f32 arg4, s32 arg5,
                  s32 arg6, s32 arg7, s16 arg8, s32 arg9, s32 arg10, s32 arg11,
                  s32 arg12, s32 arg13, u8 arg14) {
    struct {
            f32 unk00;
            f32 unk04;
            f32 unk08;
            f32 unk0C;
            f32 unk10;
            f32 unk14;
            f32 unk18;
            f32 unk1C;
            f32 unk20;
            f32 unk24;
            f32 unk28;
            f32 unk2C;
            f32 unk30;
            f32 unk34;
            f32 unk38;
            f32 unk3C;
            f32 unk40;
            f32 unk44;
            f32 unk48;
            f32 unk4C;
            s32 unk50;
            s16 unk54;
            s16 unk56;
            u8 unk58;
            u8 pad59[3];
            s32 unk5C;
            u8 unk60;
            u8 unk61;
            u8 unk62;
            u8 unk63;
            u8 unk64;
            u8 unk65;
            u8 unk66;
            u8 unk67;
            u8 unk68;
            u8 pad69;
            u8 unk6A;
            u8 pad6B;
            s32 unk6C;
            u8 unk70;
            u8 pad71;
            s16 unk72;
            s16 unk74;
            u8 pad76[0xA];
    } sp28;

    sp28.unk28 = arg2;
    sp28.unk2C = arg3;
    sp28.unk1C = 1.0f;
    sp28.unk20 = 1.0f;
    sp28.unk24 = 1.0f;
    sp28.unk50 = 0x29E8;
    sp28.unk10 = 0.0f;
    sp28.unk14 = 0.0f;
    sp28.unk18 = 0.0f;
    sp28.unk44 = 0.0f;
    sp28.unk00 = 1.0f;
    sp28.unk56 = 0x20;
    sp28.unk30 = arg4;
    sp28.unk04 = D_800A06DC;

    ((s32 *)&sp28)[-2] = func_150ADA20();
    func_15143794(arg8, (s16)((((s32 *)&sp28)[-2] % 0x2CU) - 0x3F),
                  (func_150ADA68() * 200.0f + 300.0f) * D_800A06E0,
                  &sp28.unk34);

    sp28.unk40 = (func_150ADA68() * 260.0f + -130.0f) * D_800A06E4;
    sp28.unk48 = (func_150ADA68() * 260.0f + -130.0f) * D_800A06E8;
    sp28.unk54 = (func_150ADA20() % 0x33U) + 0x32;
    sp28.unk4C = (func_150ADA68() * D_800A06EC + D_800A06F0) * D_800A06F4;

    sp28.unk0C = (func_150ADA68() * 500.0f + 100.0f) * D_800A06F8;
    sp28.unk08 = sp28.unk0C;
    sp28.unk58 = 0;
    sp28.unk5C = 0;

    sp28.unk60 = (func_150ADA20() % 0x65U) + 0x9B;
    sp28.unk61 = 3;
    sp28.unk62 = 0;
    sp28.unk63 = 0;
    sp28.unk64 = 0;
    sp28.unk65 = 0;
    sp28.unk66 = 0;
    sp28.unk67 = 0;
    sp28.unk68 = 0;
    sp28.unk6A = 2;
    sp28.unk6C = 0;
    sp28.unk70 = 0;
    sp28.unk72 = 0x20;
    sp28.unk74 = 7;

    func_15132A4C(&sp28, 3, 0xFF, 0, arg14, 0);
    return 1;
}

s32 func_150CCCB4(f32 *arg0) {
    arg0[14] += arg0[17] * D_800BE9A4;
    arg0[15] += (arg0[18] * D_800BE9A4) + (((arg0[23] * D_800BE9A4) * D_800BE9A4) * 0.5f);
    arg0[16] += arg0[19] * D_800BE9A4;
    arg0[18] += arg0[23] * D_800BE9A4;
    arg0[8] += arg0[20] * D_800BE9A4;
    arg0[9] += arg0[21] * D_800BE9A4;
    arg0[10] += arg0[22] * D_800BE9A4;
    return 1;
}
