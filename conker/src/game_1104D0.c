#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_1104D0/func_150E3020.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1104D0/func_150E3208.s")

extern u8 *func_150E3020(s32, s32, s32, s32, s32, s32, s32, f32, s32, f32, f32, f32, s32, s16);

s32 func_150E32D0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, f32 arg5) {
    u8 *temp;

    temp = func_150E3020(arg0, arg1, arg2, 0, 0, 0, arg4, arg5, arg3, 0.0f, 0.0f, 0.0f, 0, -99);
    if (temp != 0) {
        return temp[0x48] + 1;
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1104D0/func_150E3340.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1104D0/func_150E33CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1104D0/func_150E3414.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1104D0/func_150E3514.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1104D0/func_150E35DC.s")

void func_150E36BC(s32 arg0, s32 *arg1, s32 *arg2, s32 *arg3) {
    u8 *temp;

    arg0 -= 1;
    if ((arg0 >= 0) && (arg0 < 8)) {
        temp = (u8 *)D_800D99D0[arg0];
        if (temp != 0) {
            if (temp[0] == 0x27) {
                *arg1 = (s32)*(f32 *)(temp + 0x10);
                *arg2 = (s32)*(f32 *)(temp + 0x14);
                *arg3 = (s32)*(f32 *)(temp + 0x18);
            }
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1104D0/func_150E3738.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1104D0/func_150E4010.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1104D0/func_150E411C.s")

extern f32 D_800BE9A4;

s32 func_150E4174(u8 *arg0) {
    *(f32 *)(arg0 + 0x2C) += *(f32 *)(arg0 + 0x4C) * D_800BE9A4;
    *(f32 *)(arg0 + 0x30) += *(f32 *)(arg0 + 0x54) * D_800BE9A4;
    return 1;
}
