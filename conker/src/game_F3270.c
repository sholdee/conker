#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_F3270/func_150C5DC0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_F3270/func_150C5E0C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_F3270/func_150C5EFC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_F3270/func_150C5F40.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_F3270/func_150C5F94.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_F3270/func_150C60D8.s")

s32 func_150C63EC(u8 *arg0) {
    s32 ret = 1;

    if (arg0[0x5C] == 0) {
        ret = 0;
    }
    arg0[0x5C] = 0;
    return ret;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_F3270/func_150C6410.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_F3270/func_150C6438.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_F3270/func_150C6460.s")
