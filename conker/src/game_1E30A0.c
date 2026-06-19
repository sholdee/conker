#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_1E30A0/func_151B5BF0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E30A0/func_151B5E94.s")

void func_151B5FCC(u8 *arg0) {
    if (*(s32 *)(arg0 + 0x88) != 0) {
        func_100111C8(*(s32 *)(arg0 + 0x88));
        *(s32 *)(arg0 + 0x88) = 0;
    }
}
