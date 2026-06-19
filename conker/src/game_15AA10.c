#include <ultra64.h>
#include "functions.h"
#include "variables.h"


extern s32 D_800DC2B0;

typedef u8 Entry15[0xB0];

void func_1512D560(u8 *arg0, s32 arg1, s32 arg2) {
    u8 *entry;

    entry = (*(Entry15 **)&D_800DC2B0)[arg0[0x23D]];
    *(s32 *)&entry[*(s32 *)&entry[0xAC] * 8] = arg1;

    entry = (*(Entry15 **)&D_800DC2B0)[arg0[0x23D]];
    *(s32 *)&entry[*(s32 *)&entry[0xAC] * 8 + 4] = arg2;

    entry = (*(Entry15 **)&D_800DC2B0)[arg0[0x23D]];
    *(s32 *)&entry[0xAC] = *(s32 *)&entry[0xAC] + 1;

    entry = (*(Entry15 **)&D_800DC2B0)[arg0[0x23D]];
    if (*(s32 *)&entry[0xAC] == 0x14) {
        *(s32 *)&entry[0xAC] = 0;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_15AA10/func_1512D604.s")

extern s32 D_800DC2B0;

void func_1512D66C(u8 *arg0) {
    *(s32 *)((*(s32 *)&D_800DC2B0) + arg0[0x23D] * 0xB0 + 0xA8) = 0;
    *(s32 *)((*(s32 *)&D_800DC2B0) + arg0[0x23D] * 0xB0 + 0xAC) = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_15AA10/func_1512D6B0.s")
