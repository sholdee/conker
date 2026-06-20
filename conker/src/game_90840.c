#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_90840/func_15063390.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_90840/func_15063404.s")

void func_150836CC(struct127 *arg0, s32 arg1);

void func_150634E4(struct127 *arg0) {
    D_800CC2D0[arg0 - D_800CC2D0].unk31C->unk78 = 0;
    D_800CC2D0[arg0 - D_800CC2D0].unk31C->unk11A = 0;
    func_150836CC(arg0, 0x1D);
    func_150836CC(arg0, 0x1E);
    arg0->disable_jump = 0;
    arg0->disable_run = 0;
    arg0->unk83 = 0;
}

void func_15063570(struct127 *arg0) {
    D_800CC2D0[arg0 - D_800CC2D0].unk31C->unk78 = 0x3B;
    D_800CC2D0[arg0 - D_800CC2D0].unk31C->unk11A = 2;
    func_15083568(arg0, 0x89, 1.0f, 0);
    arg0->disable_jump = 0x14;
    arg0->disable_run = 0;
    arg0->unk83 = 0;
    func_1505E650(arg0, 0x221, 1.0f, 0.0f, 0.0f, 0.0f, 0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_90840/func_15063628.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_90840/func_150636A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_90840/func_150636F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_90840/func_150639BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_90840/func_15063A38.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_90840/func_15063B64.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_90840/func_15063C60.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_90840/func_15063E84.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_90840/func_15063FA0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_90840/func_150641D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_90840/func_150642AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_90840/func_150649A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_90840/func_15064A14.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_90840/func_15064B94.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_90840/func_15065A5C.s")
