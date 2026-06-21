#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern u8 D_800DBEA8[];
extern u8 D_800DD2E4[];
void func_151733E4(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);

#pragma GLOBAL_ASM("asm/nonmatchings/game_1A0790/func_151732E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1A0790/func_151733D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1A0790/func_151733E4.s")

void func_151738C4(s32 arg0) {
    if (*((s8 *)D_800B0DF0 + 0x46) == -1) {
        if (D_800DBFF0->unk5F0 & 1) {
            func_151733E4(6, 6, arg0, 0, -1);
            D_800DBEA8[0] = D_800DD2E4[0];
            D_800DBEA8[1] = D_800DD2E4[1];
            D_800DBEA8[2] = D_800DD2E4[2];
        } else {
            func_151733E4(0, 0, arg0, 0, -1);
            D_800DBEA8[0] = D_800B0DF0->unk5;
            D_800DBEA8[1] = D_800B0DF0->unk6;
            D_800DBEA8[2] = D_800B0DF0->unk7;
        }
    }
}

s8 func_15173994(s32 arg0) {
    return *((s8*)D_800B0DF0 + 0x46);
}
