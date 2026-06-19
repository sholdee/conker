#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void func_15132444(struct102 *arg0);
s32 func_1513264C(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, u8 arg5, s32 arg6);

#pragma GLOBAL_ASM("asm/nonmatchings/game_15F680/func_151321D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_15F680/func_151323AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_15F680/func_151323F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_15F680/func_15132444.s")

void func_15132570(struct102 *arg0) {
    func_15132444(arg0);
    func_15169804(arg0);
}

void func_1513259C(struct102 *arg0) {
    func_15132444(arg0);
    func_15169824(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_15F680/func_151325C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_15F680/func_1513264C.s")

s32 func_15132A4C(s32 arg0, s32 arg1, s32 arg2, s32 arg3, u8 arg4, s32 arg5) {
    return func_1513264C(arg0, arg1, arg2, 0, arg3, arg4, arg5);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_15F680/func_15132A88.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_15F680/func_15132B80.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_15F680/func_15132DDC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_15F680/func_151332DC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_15F680/func_15133510.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_15F680/func_15133588.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_15F680/func_151336A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_15F680/func_15133760.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_15F680/func_151337C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_15F680/func_15133894.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_15F680/func_151339D4.s")

s32 func_15133A50(s32 arg0, s32 arg1, s32 arg2, s32 arg3, f32 arg4) {
    *(f32 *)(arg0 + 0x3C) = *(f32 *)(arg0 + 0x10) + arg4;
    *(f32 *)(arg0 + 0x44) = 0.0f;
    *(f32 *)(arg0 + 0x48) = 0.0f;
    *(f32 *)(arg0 + 0x4C) = 0.0f;
    *(f32 *)(arg0 + 0x50) = 0.0f;
    *(f32 *)(arg0 + 0x54) = 0.0f;
    *(f32 *)(arg0 + 0x58) = 0.0f;
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_15F680/func_15133A94.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_15F680/func_15133B98.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_15F680/func_15133C58.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_15F680/func_15133D20.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_15F680/func_15133DE8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_15F680/func_15133E3C.s")

void func_15133EEC(s32 arg0, u16 arg1, u8 arg2, s32 arg3);

void func_15133E84(s32 arg0, void *arg1, s32 arg2) {
    func_15133EEC(arg0, *(u16 *)((u8 *)arg1 + 0x170), *(u8 *)((u8 *)arg1 + 0x172), *(s32 *)((u8 *)arg1 + 0x174));
}

void func_15133EB8(s32 arg0, void *arg1, s32 arg2) {
    func_15133EEC(arg0, *(u16 *)((u8 *)arg1 + 0x174), *(u8 *)((u8 *)arg1 + 0x176), *(s32 *)((u8 *)arg1 + 0x178));
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_15F680/func_15133EEC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_15F680/func_15133FD8.s")
