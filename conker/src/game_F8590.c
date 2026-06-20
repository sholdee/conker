#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_F8590/func_150CB0E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_F8590/func_150CB1E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_F8590/func_150CB1F4.s")

struct Func150CB7CC {
    char pad0[0x1C];
    s16 unk1C;
    char pad1E[0x28 - 0x1E];
    u8 unk28;
};

s32 func_150CB7CC(struct Func150CB7CC *arg0) {
    s32 v1;

    if (arg0->unk1C < 0x20) {
        v1 = arg0->unk1C << 3;
        if (v1 < arg0->unk28) {
            arg0->unk28 = v1;
        }
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_F8590/func_150CB800.s")

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
    s16 unk128;
    char pad12A[0x12C - 0x12A];
    f32 unk12C;
} CBA30Struct;


s32 func_150CBA30(CBA30Struct *arg0) {
    arg0->unk128 -= D_800BE9E4;
    if (arg0->unk128 > 0) {
        f32 v = arg0->unk12C * D_800BE9A4;
        arg0->unk2C = arg0->unk2C + v;
        arg0->unk30 = arg0->unk30 + v;
    }
    if (arg0->unk58 & 1) {
        if (arg0->unk1C < 0x20) {
            if ((arg0->unk1C << 3) < arg0->unk5C) {
                arg0->unk5C = arg0->unk1C << 3;
            }
        }
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_F8590/func_150CBABC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_F8590/func_150CBCE0.s")

s32 func_150CBE88(f32 *arg0) {
    arg0[14] += arg0[17] * D_800BE9A4;
    arg0[15] += (arg0[18] * D_800BE9A4) + (((arg0[23] * D_800BE9A4) * D_800BE9A4) * 0.5f);
    arg0[16] += arg0[19] * D_800BE9A4;
    arg0[18] += arg0[23] * D_800BE9A4;
    arg0[8] += arg0[20] * D_800BE9A4;
    arg0[9] += arg0[21] * D_800BE9A4;
    arg0[10] += arg0[22] * D_800BE9A4;
    return 1;
}

struct Func150CBF5C {
    char pad0[0x1C];
    s16 unk1C;
    char pad1E[0x58 - 0x1E];
    s32 unk58;
};

void func_150CBF5C(struct Func150CBF5C *arg0) {
    arg0->unk58 |= 1;
    arg0->unk1C = 0x20;
}
