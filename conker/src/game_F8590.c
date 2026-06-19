#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_F8590/func_150CB0E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_F8590/func_150CB1E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_F8590/func_150CB1F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_F8590/func_150CB7CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_F8590/func_150CB800.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_F8590/func_150CBA30.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_F8590/func_150CBABC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_F8590/func_150CBCE0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_F8590/func_150CBE88.s")

struct Func150CBF5C {
    char pad0[0x1C];
    s16 unk1C;
    char pad1E[0x58 - 0x1E];
    s32 unk58;
};

void func_150CBF5C(struct Func150CBF5C *arg0) {
    arg0->unk58 |= 1;
    arg0->unk1C = 0x20;
}
