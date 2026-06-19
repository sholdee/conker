#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_E8090/func_150BABE0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_E8090/func_150BAFEC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_E8090/func_150BB260.s")

extern void func_1513F6C0(void *arg0, s32 arg1, s32 arg2);

void func_150BB408(void *arg0) {
    *(s32 *)((u8 *)arg0 + 0x18) |= 1;
    *(s16 *)((u8 *)arg0 + 0xB0) = (*(s16 *)((u8 *)arg0 + 0x1C) = 0x32);
    *(s16 *)((u8 *)arg0 + 0xB2) = 5;
    func_1513F6C0(arg0, 6, *(u8 *)((u8 *)arg0 + 0x81));
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_E8090/func_150BB450.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_E8090/func_150BB498.s")
