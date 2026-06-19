#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_1A89B0/func_1517B500.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1A89B0/func_1517B6E8.s")

s32 func_1517B7A8(s16 *a0, s16 *a1, s32 *a2, s32 a3) {
    s32 v0 = *a2;

    if (v0 >= 0x300) {
        if (v0 >= 0x501) {
            *a2 = v0 - 0x200;
        } else {
            *a2 = 0x300;
        }
    }

    a1[0] = a0[0];
    a1[1] = a0[1];
    a1[2] = a0[2];
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1A89B0/func_1517B7F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1A89B0/func_1517B89C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1A89B0/func_1517BBAC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1A89B0/func_1517CFC4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1A89B0/func_1517D074.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1A89B0/func_1517D578.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1A89B0/func_1517D5FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1A89B0/func_1517D690.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1A89B0/func_1517D7B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1A89B0/func_1517DE5C.s")

extern struct { s16 unk0; s16 unk2; s16 unk4; } D_800DD470;

void func_1517E05C(s32 arg0, s32 arg1, s32 arg2) {
    D_800DD470.unk0 = arg0;
    D_800DD470.unk2 = arg1;
    D_800DD470.unk4 = arg2;
}
