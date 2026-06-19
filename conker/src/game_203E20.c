#include <ultra64.h>
#include "functions.h"
#include "variables.h"


extern void func_150D6730(s32 arg0, s32 arg1, s32 arg2);

void func_151D6970(s32 arg0, s32 arg1) {
    if ((D_800BE9F0 == 0x32) || (D_800BE9F0 == 0x33)) {
        func_150D6730(arg0, 0xFF, 1);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_203E20/func_151D69B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_203E20/func_151D6BFC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_203E20/func_151D6E60.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_203E20/func_151D7000.s")

void func_151D70CC(s32 *arg0, s32 arg1, u8 arg2) {
    func_15169850(arg1, arg2, arg0[0x12], arg0[0x12] + 4, (s32)arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_203E20/func_151D710C.s")
