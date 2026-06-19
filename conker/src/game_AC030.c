#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_AC030/func_1507EB80.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_AC030/func_1507EBB8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_AC030/func_1507EC38.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_AC030/func_1507EE58.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_AC030/func_1507EEB8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_AC030/func_1507EEF4.s")

void func_1507EFA0(s32 c, u8 *arg1) {
    s32 i = 4;
    u8 *p = arg1 + 4;
    do {
        if (*p == c) {
            *p = 0;
            return;
        }
        i--;
        p--;
    } while (i >= 0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_AC030/func_1507EFD0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_AC030/func_1507F454.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_AC030/func_1507F4C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_AC030/func_1507F54C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_AC030/func_1507F640.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_AC030/func_1507FC2C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_AC030/func_1507FEA0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_AC030/func_1507FF94.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_AC030/func_1507FFD8.s")
