#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_204660/func_151D71B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_204660/func_151D7264.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_204660/func_151D73A8.s")

void func_151D77C8(void);

void func_151D7404(void) {
    func_151D77C8();
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_204660/func_151D7424.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_204660/func_151D7450.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_204660/func_151D747C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_204660/func_151D74B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_204660/func_151D7538.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_204660/func_151D75C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_204660/func_151D7724.s")

s32 func_151D7770(s32 *arg0) {
    u8 *p = (u8 *)arg0 + 0x28;
    s32 *v = (s32 *)arg0[0x40 / 4];
    if (*(u16 *)((u8 *)v + 0x84) == 0) {
        p[5] &= ~1;
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_204660/func_151D779C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_204660/func_151D77C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_204660/func_151D7830.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_204660/func_151D792C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_204660/func_151D7A38.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_204660/func_151D7CD0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_204660/func_151D80C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_204660/func_151D8718.s")

void func_151D8764(s32 *arg0) {
    s32 *temp = (s32 *)arg0[0x98 / 4];
    s32 *temp2 = (s32 *)temp[0];
    if (temp2 != 0) {
        temp2[0x28 / 4] = 0;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_204660/func_151D8780.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_204660/func_151D87AC.s")
