#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_108320/func_150DAE70.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_108320/func_150DB114.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_108320/func_150DB2D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_108320/func_150DB518.s")

s32 func_150DB630(void *arg0) {
    f32 temp_f0;
    s32 ret;

    ret = 1;
    if (255.0f < **(f32 * volatile *)((u8 *)arg0 + 0x120)) {
        *(u8 *)((u8 *)arg0 + 0x5C) = 0xFF;
    } else {
        temp_f0 = **(f32 * volatile *)((u8 *)arg0 + 0x120);
        if (temp_f0 < 0.0f) {
            *(u8 *)((u8 *)arg0 + 0x5C) = 0;
        } else {
            *(u8 *)((u8 *)arg0 + 0x5C) = (u32)temp_f0;
        }
    }
    return ret;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_108320/func_150DB714.s")
