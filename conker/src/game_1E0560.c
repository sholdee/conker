#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_1E0560/func_151B30B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E0560/func_151B3184.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E0560/func_151B32C8.s")

extern void (*D_8008FB68[])(void *, s32, u8);

void func_151B3A34(struct102 *arg0, s32 arg1, u8 arg2) {
    void (*fn)(void *, s32, u8) = D_8008FB68[*(u8 *)((u8 *)arg0 + 0x44)];
    if (fn != NULL) {
        fn(arg0, arg1, arg2);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E0560/func_151B3A7C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E0560/func_151B3CF0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E0560/func_151B3F28.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E0560/func_151B3FDC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E0560/func_151B42A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E0560/func_151B47D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E0560/func_151B48DC.s")

s32 func_151B498C(s32 arg0, s32 *arg1, s32 *arg2, s32 *arg3, s32 *arg4, s32 *arg5,
                   s32 *arg6, s32 *arg7, s32 *arg8, s32 *arg9, s32 *arg10, s32 *arg11,
                   u8 *arg12, u8 *arg13) {
    *arg1 = 0x220005;
    *arg2 = 0x40600;
    *arg3 = 0xFF;
    *arg4 = 0xFF;
    *arg5 = 0xFF;
    *arg6 = 0xFF;
    *arg7 = 0xFF;
    *arg8 = 0xFF;
    *arg9 = 0xFF;
    *arg10 = 0xFF;
    *arg11 = 0;
    *arg12 = 5;
    *arg13 = 0x2B;
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E0560/func_151B4A14.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E0560/func_151B4B78.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E0560/func_151B4C1C.s")

void func_151B4C1C(struct102 *);

void func_151B4C6C(struct102 *arg0) {
    func_151B4C1C(arg0);
    func_15169824(arg0);
}

void func_151B4C98(struct102 *arg0) {
    func_151B4C1C(arg0);
    func_15169824(arg0);
}
