#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_E7380/func_150B9ED0.s")

s32 func_150BA35C(s16 *arg0) {
    s16 temp = arg0[0xE];
    if (temp < 0x40) {
        *((s8 *)arg0 + 0x28) = temp << 2;
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_E7380/func_150BA37C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_E7380/func_150BA424.s")
