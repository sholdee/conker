#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_205C90/func_151D87E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_205C90/func_151D8868.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_205C90/func_151D8A24.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_205C90/func_151D8B24.s")

void func_151D8B24(struct102 *);

void func_151D8B88(struct102 *arg0) {
    func_151D8B24(arg0);
    func_15169804(arg0);
}

void func_151D8BB4(struct102 *arg0) {
    func_151D8B24(arg0);
    func_15169824(arg0);
}

void func_151D8C00(void *, void *);

void func_151D8BE0(u8 *arg0) {
    func_151D8C00(arg0, arg0 + 0x18);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_205C90/func_151D8C00.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_205C90/func_151D8D5C.s")

extern f32 D_800AB300;

void func_151D8DB4(s32 arg0, u8 arg1) {
    func_15169260(&D_800AB300, 1, arg0, arg1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_205C90/func_151D8DE8.s")
