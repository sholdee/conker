#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_1DF510/func_151B2060.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1DF510/func_151B2100.s")

void func_151B222C(void);

void func_151B220C(void) {
    func_151B222C();
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1DF510/func_151B222C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1DF510/func_151B229C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1DF510/func_151B22C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1DF510/func_151B22F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1DF510/func_151B2348.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1DF510/func_151B2690.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1DF510/func_151B2950.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1DF510/func_151B2974.s")

void func_151B2EC4(s32 arg0, s32 arg1, u8 arg2) {
    func_15169850(arg1, arg2, arg0 + 0x28, arg0 + 0x2C, arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1DF510/func_151B2F04.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1DF510/func_151B2FA0.s")

void func_151B2FD0(s32 *arg0) {
    s32 *temp = (s32 *)arg0[0x4C / 4];
    if (temp != 0) {
        temp[0x44 / 4] = 0;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1DF510/func_151B2FE8.s")

void func_151B3014(s32 *arg0) {
    func_151B2FD0(arg0);
    func_15149368((struct260 *)arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1DF510/func_151B3040.s")
