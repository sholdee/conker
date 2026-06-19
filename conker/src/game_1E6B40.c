#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_1E6B40/func_151B9690.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E6B40/func_151B9964.s")

typedef struct {
    u8  pad0[0x10];
    s32 unk10;
    u8  unk14;
    u8  unk15;
    s16 unk16;
    s16 unk18;
    s16 unk1A;
    s16 unk1C;
    s16 unk1E;
    s16 unk20;
    s16 unk22;
    s16 unk24;
    s16 unk26;
    s16 unk28;
    s16 unk2A;
} struct_151B9BF0;

s32 func_15167A68(s32, s32, s32, s32, s32, s32);

void func_151B9BF0(s32 arg0, s32 arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5,
                   s16 arg6, s16 arg7, s16 arg8, s16 arg9, s16 arg10, s16 arg11,
                   s16 arg12, s32 arg13, u8 arg14, s32 arg15) {
    struct_151B9BF0 *ret;

    ret = (struct_151B9BF0 *)func_15167A68(7, arg15, 0x2C, 0, arg14, 1);
    if (ret != 0) {
        ret->unk14 = arg0;
        ret->unk15 = arg1;
        ret->unk16 = arg2;
        ret->unk18 = arg3;
        ret->unk1A = arg4;
        ret->unk1C = arg5;
        ret->unk1E = arg6;
        ret->unk20 = arg7;
        ret->unk22 = arg8;
        ret->unk24 = arg9;
        ret->unk26 = arg10;
        ret->unk28 = arg11;
        ret->unk2A = arg12;
        ret->unk10 = arg13;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E6B40/func_151B9CB0.s")
