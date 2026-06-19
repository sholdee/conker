#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_135D00/func_15108850.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_135D00/func_15108AB4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_135D00/func_15108B80.s")

struct Arg0_15108BC0 {
    u8 pad[0x50];
    s32 off;
};

void func_15108BC0(struct Arg0_15108BC0 *arg0) {
    u8 *v0 = (u8 *)arg0 + arg0->off;
    s32 v1 = *(s32 *)(v0 + 0x10C);

    v0 += 0xF8;
    if (v1 == 0x3E7) {
        *(f32 *)(v0 + 0x10) = 226.0f;
        return;
    }
    if (D_800C35EA == 1) {
        struct233 **tmp = &D_800C3958;
        struct233 *e = *tmp + v1;
        *(f32 *)(v0 + 0x10) = e->unk4;
    } else {
        *(f32 *)(v0 + 0x10) = 226.0f;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_135D00/func_15108C38.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_135D00/func_15108D24.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_135D00/func_15108E10.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_135D00/func_15108FFC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_135D00/func_15109064.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_135D00/func_151090DC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_135D00/func_15109120.s")
