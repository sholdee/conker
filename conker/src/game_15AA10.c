#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_15AA10/func_1512D560.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_15AA10/func_1512D604.s")

extern s32 D_800DC2B0;

void func_1512D66C(u8 *arg0) {
    *(s32 *)((*(s32 *)&D_800DC2B0) + arg0[0x23D] * 0xB0 + 0xA8) = 0;
    *(s32 *)((*(s32 *)&D_800DC2B0) + arg0[0x23D] * 0xB0 + 0xAC) = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_15AA10/func_1512D6B0.s")
