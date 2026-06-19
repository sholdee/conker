#include <ultra64.h>
#include "functions.h"
#include "variables.h"

// loops and loops
extern u8 D_800DCE50[];

void func_15008870(s32 arg0) {
    s32 lo;
    s32 hi;
    s32 i;
    s32 j;

    lo = 0;
    hi = 0x68;
    if (arg0 == 1) {
        hi = 0x65;
    } else if (arg0 == 2) {
        lo = 0x65;
    }
    for (i = 0; i < 2; i++) {
        for (j = lo; j < hi; j++) {
            ((s32 *)&D_800DCE50[i * 0x1A0])[j] = 0;
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_35D20/func_15008930.s")
