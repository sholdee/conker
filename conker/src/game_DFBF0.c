#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_DFBF0/func_150B2740.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_DFBF0/func_150B2EB4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_DFBF0/func_150B3188.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_DFBF0/func_150B36AC.s")

s32 func_150B378C(void *a0) {
    u8 *p;
    s32 v1;
    p = *(u8 **)((u8 *)a0 + 0x98);
    v1 = *(s16 *)((u8 *)a0 + 0x1C) << 4;
    if (v1 >= 0x100) {
        v1 = 0xFF;
    }
    if (v1 < p[0x1B]) {
        p[0x1B] = v1;
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_DFBF0/func_150B37C8.s")
