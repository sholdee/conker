#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern f32 D_800A05E0[];
extern f32 D_800A05EC[];
void func_15143134(void *, f32 *, s32);
void func_1504715C(s32, s32);
s32 func_15046C80(f32 *, s32, f32, s32);

s32 func_150CB0E0(f32 *arg0, s32 arg1, s32 arg2, u8 arg3) {
    f32 sp2C[3];
    f32 *temp_a0;
    s32 temp_a2;

    if ((arg3 != 1) && (arg3 != 2)) {
        return 0;
    }

    if (arg3 == 1) {
        temp_a0 = D_800A05EC;
    } else {
        temp_a0 = D_800A05E0;
    }

    if (arg3 == 1) {
        temp_a2 = *(s32 *)(arg1 + 0x1D4) + 0xA00;
    } else {
        temp_a2 = *(s32 *)(arg1 + 0x1D4) + 0xBC0;
    }

    func_15143134(temp_a0, arg0, temp_a2);
    if (arg2 == 0) {
        return 1;
    }

    sp2C[0] = arg0[0];
    sp2C[1] = arg0[1] + 100.0f;
    sp2C[2] = arg0[2];
    func_1504715C(arg2, arg1);
    return func_15046C80(sp2C, 0, arg0[1] - 500.0f, arg2);
}

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
