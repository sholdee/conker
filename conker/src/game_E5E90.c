#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_E5E90/func_150B89E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_E5E90/func_150B8F44.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_E5E90/func_150B9560.s")

s32 func_150B95FC(void *arg0) {
    s16 v0 = *(s16*)((u8*)arg0 + 0x1C);
    if (v0 < 0x20) {
        *(u8*)((u8*)arg0 + 0x5C) = v0 << 3;
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_E5E90/func_150B961C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_E5E90/func_150B963C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_E5E90/func_150B9D14.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_E5E90/func_150B9D8C.s")
