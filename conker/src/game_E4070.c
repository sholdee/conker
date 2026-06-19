#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_E4070/func_150B6BC0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_E4070/func_150B6C90.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_E4070/func_150B6D34.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_E4070/func_150B6D78.s")

void func_150B6DFC(void *arg0) {
    *(s16 *)((u8 *)arg0 + 0x34) += D_800BE9E4 * 0x30;
    if (*(s16 *)((u8 *)arg0 + 0x34) >= 0x801) {
        *(s16 *)((u8 *)arg0 + 0x34) = -0xC00;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_E4070/func_150B6E3C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_E4070/func_150B709C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_E4070/func_150B71A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_E4070/func_150B7220.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_E4070/func_150B73F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_E4070/func_150B7484.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_E4070/func_150B7560.s")

void func_150B76BC(s32, s32);

void func_150B765C(void) {
    func_150B76BC(0x3C, 1);
    D_800D9890 = 3;
}

void func_150B768C(void) {
    func_150B76BC(0xE6, 2);
    D_800D9890 = 3;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_E4070/func_150B76BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_E4070/func_150B77A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_E4070/func_150B791C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_E4070/func_150B7B40.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_E4070/func_150B82D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_E4070/func_150B85C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_E4070/func_150B879C.s")
