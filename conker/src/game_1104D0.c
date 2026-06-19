#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_1104D0/func_150E3020.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1104D0/func_150E3208.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1104D0/func_150E32D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1104D0/func_150E3340.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1104D0/func_150E33CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1104D0/func_150E3414.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1104D0/func_150E3514.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1104D0/func_150E35DC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1104D0/func_150E36BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1104D0/func_150E3738.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1104D0/func_150E4010.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1104D0/func_150E411C.s")

extern f32 D_800BE9A4;

s32 func_150E4174(u8 *arg0) {
    *(f32 *)(arg0 + 0x2C) += *(f32 *)(arg0 + 0x4C) * D_800BE9A4;
    *(f32 *)(arg0 + 0x30) += *(f32 *)(arg0 + 0x54) * D_800BE9A4;
    return 1;
}
