#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern u8 D_80084060[];


#pragma GLOBAL_ASM("asm/nonmatchings/game_48FD0/func_1501BB20.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_48FD0/func_1501BBB8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_48FD0/func_1501C010.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_48FD0/func_1501C0F0.s")

void func_1501C17C(u8 arg0) {
    u8 temp = D_80084060[arg0];
    if (temp < 4) {
        D_800BE93C[temp] = 0;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_48FD0/func_1501C1B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_48FD0/func_1501C53C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_48FD0/func_1501C57C.s")
