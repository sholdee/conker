#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_B21B0/func_15084D00.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_B21B0/func_15084D70.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_B21B0/func_15085410.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_B21B0/func_15085420.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_B21B0/func_15085430.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_B21B0/func_15085710.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_B21B0/func_150859AC.s")

void func_15085ABC(s16 arg0) {
    s32 i;

    i = 0;
    if (D_800D18A8 == 0) {
        for (i = 0; i != 4; i++) {
            if ((1 << i) & arg0) {
                func_15085710((s16)i, 5, D_800CC2D0[i].health);
            }
        }
    }
}
