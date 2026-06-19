#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_113480/func_150E5FD0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_113480/func_150E6230.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_113480/func_150E63A0.s")

s32 func_150E679C(void *arg0) {
    s32 v0 = *(s16 *)((u8 *)arg0 + 0x1C);
    s32 v1;
    if (v0 < 8) {
        v1 = v0 << 5;
        if (v1 < *(u8 *)((u8 *)arg0 + 0x5C)) {
            *(u8 *)((u8 *)arg0 + 0x5C) = v1;
        }
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_113480/func_150E67D0.s")
