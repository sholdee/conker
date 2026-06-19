#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_19E040/func_15170B90.s")

extern s32 D_800BE9F0;
void func_15170B90(s32, s32, s32, s32, u8, s32);

void func_15170EC4(s32 arg0, u8 arg1, s32 arg2) {
    switch (D_800BE9F0) {
    case 2:
        func_15170B90(arg0, 1, 1, 1, arg1, arg2);
        break;
    case 0x10:
        func_15170B90(arg0, 0xA9, 8, 0, arg1, arg2);
        break;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_19E040/func_15170F4C.s")

extern void func_150C3D5C(struct127 *);

void func_151711C4(struct127 *arg0) {
    if (((u8 *)arg0)[4] == 0x33) {
        func_150C3D5C(arg0);
    }
    func_15060F28(arg0, 1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_19E040/func_15171200.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_19E040/func_15171600.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_19E040/func_151717FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_19E040/func_151718F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_19E040/func_15171BF4.s")
