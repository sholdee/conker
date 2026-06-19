#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_3C740/func_1500F290.s")

typedef struct {
    u8  pad0[0x28];
    s16 unk28;
    s16 unk2A;
    s16 unk2C;
    s16 unk2E;
    s8  unk30;
} Struct1500F378;

s32 func_1500F378(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    Struct1500F378 *temp;

    temp = (Struct1500F378 *)func_151491F4((s16)((func_150ADA20() & 0x7F) + 0xA), 1, -1, 1, 0, 0xA, 0xFF, 0);
    if (temp != 0) {
        temp->unk28 = arg0;
        temp->unk2A = arg1;
        temp->unk2C = arg2;
        temp->unk2E = arg3;
        temp->unk30 = 1;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_3C740/func_1500F40C.s")
