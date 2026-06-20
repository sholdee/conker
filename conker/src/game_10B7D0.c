#include <ultra64.h>
#define func_15048A40 func_15048A40_hdr
#include "functions.h"
#undef func_15048A40
#include "variables.h"
extern f32 func_15048A40(u8 arg0);


#pragma GLOBAL_ASM("asm/nonmatchings/game_10B7D0/func_150DE320.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_10B7D0/func_150DE32C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_10B7D0/func_150DE458.s")

extern f32 D_800A0D48;
extern f32 D_800A0D4C;
extern f32 D_800A0D50;
extern f32 D_800A0D54;

struct Struct150DE6D8 {
    f32 unk0;
    char pad4[4];
    f32 unk8;
    char padC[6];
    s16 unk12;
    char pad14[0x68];
    s32 unk7C;
    s32 unk80;
    s32 unk84;
};

void func_150DE6D8(struct Struct150DE6D8 *arg0) {
    arg0->unk12 = (s16)(s32)(func_15048A40((u8)(arg0->unk7C >> 3)) * D_800A0D48 + D_800A0D4C);
    arg0->unk0 = func_15048A40((u8)(arg0->unk80 >> 3)) * D_800A0D50;
    arg0->unk8 = func_15048A40((u8)(arg0->unk84 >> 3)) * D_800A0D54;
    arg0->unk7C += D_800BE9E4 * 12;
    arg0->unk80 += D_800BE9E4 * 16;
    arg0->unk84 += D_800BE9E4 * 24;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_10B7D0/func_150DE7C0.s")

s32 func_150DEACC(f32 *arg0) {
    arg0[13] += arg0[68] * D_800BE9A4;
    arg0[14] += arg0[69] * D_800BE9A4;
    arg0[15] += arg0[70] * D_800BE9A4;
    arg0[71] -= D_800BE9A4;
    if (arg0[71] < 0.0f) {
        return 0;
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_10B7D0/func_150DEB58.s")

extern void func_150DEC28(u8, s32);
extern u8 D_800A0D0B[];
extern u8 D_800A0D2B[];
extern void func_151616D0(u8, u8, s32);
extern void func_151417C4(u8, s32);

void func_150DEBE0(s32 arg0) {
    u8 i;

    for (i = 0; i < 4; i++) {
        func_150DEC28(i, 1);
    }
}

void func_150DEC28(u8 arg0, s32 arg1) {
    s32 idx = arg0 * 4;

    func_151616D0(D_800A0D0B[idx], 0x22, 0);
    func_151417C4(D_800A0D2B[idx], 0x22);
}
