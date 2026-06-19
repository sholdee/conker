#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_11F780/func_150F22D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_11F780/func_150F237C.s")

extern s32 func_150F22D0(void *, void *, s32);
extern void func_151C329C(void *, s32, s32);

void func_150F2390(void *arg0, s32 arg1, s32 arg2) {
    s32 sp1C[3];

    if (*(s32 *)((u8 *)arg0 + 0x1D4) != 0) {
        func_150F22D0(sp1C, arg0, (u8)arg1);
        func_151C329C(sp1C, 0xFF, 0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_11F780/func_150F23E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_11F780/func_150F2480.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_11F780/func_150F2518.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_11F780/func_150F25A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_11F780/func_150F26A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_11F780/func_150F2994.s")
