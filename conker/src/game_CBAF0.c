#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_CBAF0/func_1509E640.s")

s32 func_151F2CDC(void);

s32 func_1509E6F0(s32 arg0, s32 arg1, s32 arg2) {
    if (arg1 == 3) {
        return func_151F2CDC() == 1;
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_CBAF0/func_1509E730.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_CBAF0/func_1509E8A0.s")
