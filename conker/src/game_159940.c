#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_159940/func_1512C490.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_159940/func_1512D070.s")

extern s32 D_800DC280[];
extern s32 D_800DC290[];
s32 func_1502B5C8(s32 *, s32, s32, s32);

void func_1512D238(void) {
    u32 sp3C;
    s32 i;

    for (i = 0; i < 4; i++) {
        D_800DC280[i] = func_1502B5C8((s32 *)&sp3C, 2, 0x1B, i);
        D_800DC290[i] = sp3C / 0x18;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_159940/func_1512D2E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_159940/func_1512D2F8.s")

void func_1512D368(s32 arg0) {
    arg0 = arg0;
}
