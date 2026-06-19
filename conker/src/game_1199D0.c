#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_1199D0/func_150EC520.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1199D0/func_150EC6B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1199D0/func_150ECA68.s")

void func_150ECB4C(s32 arg0, s32 arg1, u8 arg2) {
    func_15169850(arg1, arg2, arg0 + 0x28, arg0 + 0x2C, arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1199D0/func_150ECB8C.s")

extern void func_151C9AC0(s32, u8, s32);
extern void func_150ECA68(s32, s32, s32, s32, u8, u8, s16, s32, s32);

void func_150ECC00(s32 arg0, u8 arg1, s32 arg2) {
    func_151C9AC0(arg0, arg1, arg2);
    func_150ECA68(arg0, 0, 0xFF, 0, 0xFF, 4, -1, arg1, arg2);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1199D0/func_150ECC70.s")
