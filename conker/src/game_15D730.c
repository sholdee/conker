#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_15D730/func_15130280.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_15D730/func_15130374.s")

void func_15130374(s32 a0, u8 a1, s32 a2, u8 a3, s32 a4);

void func_151303BC(s32 a0, u8 a1, s32 a2) {
    func_15130374(a0, a1, a2, 0xFF, 0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_15D730/func_151303EC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_15D730/func_15130A9C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_15D730/func_1513137C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_15D730/func_15131514.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_15D730/func_1513164C.s")

void func_151318E8(s32 a0, s32 a1);

s32 func_151316AC(s32 *a0, s32 a1) {
    func_151318E8((s32)a0 + 0x58, a0[0x2A]);
    return 1;
}

s32 func_15131918(s32 a0, s32 a1);

s32 func_151316DC(s32 *a0, s32 a1) {
    func_15131918((s32)a0 + 0x58, a0[0x2A]);
    return 1;
}

s32 func_15131958(s32 a0, s32 a1);

s32 func_1513170C(s32 *a0, s32 a1) {
    func_15131958((s32)a0 + 0x58, a0[0x2A]);
    return 1;
}

void func_1513173C(void) {
    extern void func_15169804();
    func_15169804();
}

void func_1513175C(void) {
    extern void func_15169824();
    func_15169824();
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_15D730/func_1513177C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_15D730/func_151317C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_15D730/func_15131814.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_15D730/func_15131828.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_15D730/func_151318E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_15D730/func_15131918.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_15D730/func_15131958.s")

s32 func_151319C4(void *arg0, s32 arg1, void *arg2);

s32 func_151319A4(u8 *arg0, s32 arg1) {
    return func_151319C4(arg0, arg1, arg0 + 0xA8);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_15D730/func_151319C4.s")

s32 func_15131AFC(u8 *arg0, s32 arg1) {
    func_15131958((s32)arg0 + 0x58, *(s32 *)(arg0 + 0xA8));
    return func_151319C4(arg0, arg1, arg0 + 0xB0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_15D730/func_15131B3C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_15D730/func_15131B7C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_15D730/func_15131C2C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_15D730/func_15131C84.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_15D730/func_15131D4C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_15D730/func_15131D9C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_15D730/func_15131DEC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_15D730/func_15131EE4.s")
