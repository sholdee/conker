#include <ultra64.h>
#include "functions.h"
#include "variables.h"


void func_15100180(s32 arg0) {
    struct {
        s32 unk0;
        u8 unk4;
    } sp18;

    sp18.unk0 = arg0;
    sp18.unk4 = *(u8 *)(arg0 + 0x3B);
    func_151494E0((s32)&sp18, 0x48);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_12D630/func_151001B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_12D630/func_15100230.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_12D630/func_151002BC.s")
