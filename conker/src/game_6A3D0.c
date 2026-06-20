#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_6A3D0/func_1503CF20.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_6A3D0/func_1503D368.s")

void func_1503D438(s32 *arg0, s32 arg1) {
    s32 temp = *arg0;
    if (temp != 0 && (temp & 0x0F000000) == 0) {
        *arg0 = temp + arg1;
    }
}

void func_1503D45C(s32 *arg0, s32 arg1) {
    s32 temp = *arg0;
    while (temp != 0) {
        *arg0 = temp + arg1;
        temp = arg0[2];
        arg0 += 2;
    }
}

struct Elem1503D484 {
    u16 unk0;
    s32 unk4;
};

void func_1503D484(struct Elem1503D484 *arg0, s32 arg1) {
    struct Elem1503D484 *p = arg0;

    while (arg0->unk0 != 0x3E7) {
        if (arg0->unk4 != 0) {
            func_1503D438(&arg0->unk4, (s32)p);
        }
        arg0++;
    }

    D_800C5A90[arg1] = arg0 - p;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_6A3D0/func_1503D510.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_6A3D0/func_1503D5F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_6A3D0/func_1503D660.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_6A3D0/func_1503D774.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_6A3D0/func_1503D804.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_6A3D0/func_1503D984.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_6A3D0/func_1503DA3C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_6A3D0/func_1503DA9C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_6A3D0/func_1503DC3C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_6A3D0/func_1503DD1C.s")
