#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_EC420/func_150BEF70.s")

extern void func_1516D99C();

void func_150BEF7C(s32 arg0) {
    s32 i;
    s32 pos;
    s32 v;
    v = arg0 & 0xFFFF;
    pos = 0x17C;
    for (i = 0; i != 2; i++) {
        func_1516D99C(0x1FDB, 0x25, (s16)pos, 0xD,
            0, 0x50, 0x8F, 0, 0, 0, 0, 0,
            8, 0xC8, 0xA, 0, 0, 0, 0, 0,
            0x28, 0x28, 4, 0, 0, 0, 0, 0x555,
            0x555, 0x555, 0x555, v, 0x32, 0, 0xFF, 0x14,
            0xFA0, 0x7D0, 1, 6, 0, 1, 0, 0,
            0, 0, 3, 0xFF, 0);
        pos = -pos;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_EC420/func_150BF0F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_EC420/func_150BF21C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_EC420/func_150BF760.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_EC420/func_150BFA7C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_EC420/func_150BFFE0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_EC420/func_150C01DC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_EC420/func_150C04C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_EC420/func_150C0648.s")
