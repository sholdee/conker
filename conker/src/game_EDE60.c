#include <ultra64.h>
#include "functions.h"
#include "variables.h"


void func_150C09B0(s32 arg0, s32 arg1, s32 arg2) {
    func_15169850(arg1, (u8)arg2, arg0 + 0x20, arg0 + 0x24, arg0);
}

extern void func_150C0A48(struct102 *);

void func_150C09F0(struct102 *arg0) {
    func_150C0A48(arg0);
    func_15169804(arg0);
}

extern void func_15169824(struct102 *);

void func_150C0A1C(struct102 *arg0) {
    func_150C0A48(arg0);
    func_15169824(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_EDE60/func_150C0A48.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_EDE60/func_150C0AC0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_EDE60/func_150C0C38.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_EDE60/func_150C1198.s")
