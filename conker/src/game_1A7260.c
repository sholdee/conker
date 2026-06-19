#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_1A7260/func_15179DB0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1A7260/func_15179FE0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1A7260/func_1517A1EC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1A7260/func_1517A394.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1A7260/func_1517A3A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1A7260/func_1517A644.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1A7260/func_1517A84C.s")

extern s16 D_800DD450;
extern s32 func_1517A394();

s32 func_1517A958(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    arg2 = arg2;
    arg3 = arg3;
    D_800DD450 = -1;
    if ((arg1 == 0xC) || (arg1 == 0x59)) {
        arg0 = func_1517A394();
    }
    return arg0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1A7260/func_1517A9A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1A7260/func_1517AA20.s")

extern void func_1510B7B4(s32, s32);

void func_1517AB7C(s32 arg0, s32 arg1, s16 arg2) {
    func_1510B7B4(arg0, arg2);
}
