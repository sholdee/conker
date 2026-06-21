#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void func_15142314(s32, s32, f32 *);
void func_1504715C(s32, s32);
s32 func_15046C80(f32 *, s32, f32, s32);

s32 func_150EAF50(f32 *arg0, s32 arg1, s32 arg2, u8 arg3) {
    f32 sp2C[3];
    s32 temp_a1;

    if ((arg3 != 1) && (arg3 != 2)) {
        return 0;
    }

    if (arg3 == 1) {
        temp_a1 = 0x21;
    } else {
        temp_a1 = 0x1D;
    }

    func_15142314(*(s32 *)(arg1 + 0x1D4), temp_a1, arg0);
    if (arg2 == 0) {
        return 1;
    }

    sp2C[0] = arg0[0];
    sp2C[1] = arg0[1] + 10.0f;
    sp2C[2] = arg0[2];
    func_1504715C(arg2, arg1);
    return func_15046C80(sp2C, 0, arg0[1] - 50.0f, arg2);
}

extern s32 func_151420F8(s32);

s32 func_150EB030(s32 arg0, s32 arg1) {
    if (arg0 == 1) {
        if (D_800BE9F0 == 4) {
            if (func_151420F8(arg1) != 0) {
                return 6;
            }
            return 3;
        }
        return -1;
    }
    return -1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_118400/func_150EB090.s")
