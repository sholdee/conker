#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_FF5C0/func_150D2110.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_FF5C0/func_150D21CC.s")

void func_150D22D4(s32 arg0);

void func_150D227C(s32 arg0) {
    func_150D22D4(arg0);
    func_1514933C((struct260 *)arg0);
}

void func_150D22A8(s32 arg0) {
    func_150D22D4(arg0);
    func_15149368((struct260 *)arg0);
}

extern u8 D_800D9900;

void func_150D22D4(s32 arg0) {
    D_800D9900--;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_FF5C0/func_150D22F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_FF5C0/func_150D2374.s")
