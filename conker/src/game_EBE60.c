#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void func_15142314(s32, s32, f32 *);
void func_1504715C(s32, s32);
s32 func_15046C80(f32 *, s32, f32, s32);

s32 func_150BE9B0(f32 *arg0, s32 arg1, s32 arg2, u8 arg3) {
    f32 sp2C[3];
    s32 temp_a1;

    switch (arg3) {
    case 4:
        temp_a1 = 0x17;
        break;
    case 5:
        temp_a1 = 0x14;
        break;
    case 6:
        temp_a1 = 0xC;
        break;
    case 7:
    default:
        temp_a1 = 0x10;
        break;
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

s32 func_150BEAA8(s32 arg0, s32 arg1) {
    switch (arg0) {
    case 0:
    case 1:
        return 0x11;
    default:
        return -1;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_EBE60/func_150BEACC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_EBE60/func_150BEC30.s")

s32 func_150BED28(s32 arg0, s32 arg1) {
    switch (arg0) {
    case 0:
    case 1:
        return 0x12;
    default:
        return -1;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_EBE60/func_150BED4C.s")

void func_150BEEB0(struct108 *arg0) {
    if (func_1509BE40(1, 0x4063, 6, 0x2000) || func_1509BE40(1, 0x4001, 6, 0x9000)) {
        arg0->unk84 |= 0x1010;
    } else {
        arg0->unk84 &= ~0x1010;
    }
    if (func_1509BE40(1, 0x4069, 6, 0x2000)) {
        arg0->unk84 |= 0x1000000;
    } else {
        arg0->unk84 &= ~0x1000000;
    }
}
