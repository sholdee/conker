#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_68C70/func_1503B7C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_68C70/func_1503B840.s")

extern u8 D_800CC5CB[];

s32 func_1503B95C(s32 arg0, u8 *arg1) {
    s32 v = D_800CC5CB[arg0 * 812];
    if (v & 2) {
        arg1[0x4E] = 0;
        return 0;
    }
    if (v & 1) {
        return 0;
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_68C70/func_1503B9BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_68C70/func_1503CB98.s")
