#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_1B74A0/func_15189FF0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1B74A0/func_1518A094.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1B74A0/func_1518A214.s")

s32 func_1518A2E8(s32 arg0, u8 *arg1) {
    if (*(u8 *)(*(s32 *)(arg0 + 0x188) + 0x6A) != 0) {
        *(s32 *)(arg0 + 0x58) &= ~2;
        *arg1 = 0;
    } else {
        *arg1 = 1;
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1B74A0/func_1518A324.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1B74A0/func_1518A360.s")
