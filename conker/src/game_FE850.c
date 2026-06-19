#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_FE850/func_150D13A0.s")

extern s32 func_151149AC(u32);

struct Obj150D1410 {
    u8 pad0[0x6E];
    u8 unk6E;
};

void func_150D1410(s32 arg0) {
    struct Obj150D1410 *temp;

    temp = (struct Obj150D1410 *)func_151149AC(0xF9);
    if (temp != 0) {
        if (((arg0 - (s32)&D_800CC2D0[0]) / 0x32C) == 0) {
            temp->unk6E = 1;
        } else {
            temp->unk6E = 0;
        }
    }
}

struct Obj150D146C {
    u8 pad0[0x6E];
    u8 unk6E;
};

void func_150D146C(s32 arg0) {
    struct Obj150D146C *temp;

    temp = (struct Obj150D146C *)func_151149AC(0xF9);
    if (temp != 0) {
        temp->unk6E = 1;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_FE850/func_150D149C.s")
