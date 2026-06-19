#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_F21D0/func_150C4D20.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_F21D0/func_150C4E9C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_F21D0/func_150C522C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_F21D0/func_150C5280.s")

extern s32 func_150C5280(void);
extern s32 (*D_8008ADA8)(s32);

s32 func_150C52CC(s32 arg0) {
    if (func_150C5280()) {
        return 0;
    }
    return D_8008ADA8(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_F21D0/func_150C5310.s")
