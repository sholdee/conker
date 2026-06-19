#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_10EF60/func_150E1AB0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_10EF60/func_150E1D14.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_10EF60/func_150E28DC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_10EF60/func_150E2DA4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_10EF60/func_150E2DB4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_10EF60/func_150E2EA4.s")

s32 func_150E2DA4(s32, s32);

s32 func_150E2F90(s32 a0, s32 a1, s16 a2) {
    return func_150E2DA4(a0, a2);
}

void func_150E2FC0(u8 *a0, s32 *a1, u8 a2) {
    if (a2 == 0x2D) {
        if (a1[0] == *(s32 *)(a0 + 0xDC)) {
            *(s32 *)(a0 + 0xDC) = a1[1];
            a0[0xDA] = *(u8 *)((u8 *)a1 + 9);
        } else if (a1[1] == *(s32 *)(a0 + 0xDC)) {
            *(s32 *)(a0 + 0xDC) = a1[0];
            a0[0xDA] = *(u8 *)((u8 *)a1 + 8);
        }
    }
}
