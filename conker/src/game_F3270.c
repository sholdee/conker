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

void func_150C6410(struct102 *arg0) {
    s32 *temp = (s32 *)((*(u8 **)((u8 *)arg0 + 0x58)) + 0x58);
    temp[1] = 0;
    func_151346EC(arg0);
}

void func_150C6438(struct102 *arg0) {
    s32 *temp = (s32 *)((*(u8 **)((u8 *)arg0 + 0x58)) + 0x58);
    temp[1] = 0;
    func_1513470C(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_F3270/func_150C6460.s")
