#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_1D2B10/func_151A5660.s")

void func_151A5D2C(u16 arg0);

void func_151A5CAC(struct260 *arg0) {
    if (*(u16 volatile *)((u8*)arg0 + 0x6C) != 0) {
        func_151A5D2C(*(u16*)((u8*)arg0 + 0x6C));
    }
    func_1514933C(arg0);
}

void func_151A5CEC(struct260 *arg0) {
    if (*(u16 volatile *)((u8*)arg0 + 0x6C) != 0) {
        func_151A5D2C(*(u16*)((u8*)arg0 + 0x6C));
    }
    func_15149368(arg0);
}

void func_151A5D2C(u16 arg0) {
    func_100111C8(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D2B10/func_151A5D58.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D2B10/func_151A5F70.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D2B10/func_151A6068.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D2B10/func_151A6350.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D2B10/func_151A6600.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D2B10/func_151A6AB8.s")

extern void func_151A6AB8(struct210 *);

void func_151A6B10(struct210 *arg0) {
    func_151A6AB8(arg0);
    func_1513CA6C(arg0);
}

void func_151A6B3C(struct210 *arg0) {
    func_151A6AB8(arg0);
    func_1513CAA0(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D2B10/func_151A6B68.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D2B10/func_151A6BD8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D2B10/func_151A6C90.s")
