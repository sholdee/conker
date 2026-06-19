#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_121A20/func_150F4570.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_121A20/func_150F48D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_121A20/func_150F4A38.s")

struct sub150F4 { u8 pad[0x24]; u8 unk24; };

void func_150F4CFC(struct102 *arg0, s32 arg1, u8 arg2) {
    struct sub150F4 *p;
    p = (struct sub150F4 *)((u8 *)arg0 + 0x170);
    if (arg2 == 0x4E) {
        ((u8 *)arg0)[0x71] = 0;
        p->unk24 |= 0x5;
    } else if (arg2 == 0x4F) {
        func_1516972C(arg0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_121A20/func_150F4D5C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_121A20/func_150F4DEC.s")
