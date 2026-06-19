#include <ultra64.h>
#include "functions.h"
#include "variables.h"


s32 func_15167A68(s32, s32, s32, s32, s32, s32);

s32 func_15169900(s32 arg0, s32 arg1) {
    s32 ret;

    ret = func_15167A68(0x5E, 0, 0x4C, 0, arg1, 1);
    if (ret != 0) {
        bcopy((void *)arg0, (void *)(ret + 0x10), 0x3C);
    }
    return ret;
}

s32 func_15169968(s32 arg0) {
    return func_15169900(arg0, 0xFF);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_196DB0/func_15169988.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_196DB0/func_15169A48.s")
