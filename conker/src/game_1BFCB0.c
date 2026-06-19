#include <ultra64.h>
#include "functions.h"
#include "variables.h"


extern s32 func_151928B0(void *a0, s32 *a1);
extern s32 func_1510F8CC(s32);
extern void (**D_8008F860[])(void *);

void func_15192800(void *arg0, s32 arg1) {
    s32 sp2C;
    s32 *p;
    s32 v0;

    p = &sp2C;
    if (arg0 != 0 && func_151928B0(arg0, p) != 0) {
        switch (func_1510F8CC(*(s32 *)((u8 *)arg0 + 0x184))) {
        case 5:
            if (D_800BE9F0 == 0x14) {
                v0 = 2;
            } else {
                v0 = 1;
            }
            break;
        case 6:
            v0 = 3;
            break;
        default:
            v0 = 1;
            break;
        }
        if (D_8008F860[sp2C][v0] != 0) {
            D_8008F860[sp2C][v0](arg0);
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1BFCB0/func_151928B0.s")
