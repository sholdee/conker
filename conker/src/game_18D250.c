#include <ultra64.h>
#include "functions.h"
#include "variables.h"


extern void *func_15167A68(s32, s32, s32, s32, u8, s32);

#pragma GLOBAL_ASM("asm/nonmatchings/game_18D250/func_1515FDA0.s")

void *func_1515FF74(void *arg0, s32 arg1, u8 arg2, s32 arg3) {
    void *temp_v0;
    void *sp24;

    temp_v0 = func_15167A68(0x34, arg3, arg1 + 0x18, 1, arg2, 1);
    if (temp_v0 == 0) {
        return NULL;
    }
    sp24 = temp_v0;
    memcpy((s32)temp_v0 + 0xE, arg0, 8);
    return sp24;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_18D250/func_1515FFEC.s")

extern void (*D_8008B0E4[])(void*, s32, u8);

void func_15160090(void *arg0, s32 arg1, u8 arg2) {
    void (*func)(void*, s32, u8);

    func = D_8008B0E4[*(u8*)((char*)arg0 + 0x14)];
    if (func != NULL) {
        func(arg0, arg1, arg2);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_18D250/func_151600D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_18D250/func_15160274.s")
