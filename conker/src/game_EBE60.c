#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_EBE60/func_150BE9B0.s")

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
