#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_128D70/func_150FB8C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_128D70/func_150FC368.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_128D70/func_150FC438.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_128D70/func_150FC614.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_128D70/func_150FC818.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_128D70/func_150FC930.s")

void func_150FC974(struct260 *arg0) {
    s32 *p = (s32 *)((u8 *)arg0 + 0x38);
    if (*p != 0) {
        func_1516972C((struct102 *)*p);
    }
}

extern void func_150FC974(struct260 *);

void func_150FC9A4(struct260 *arg0) {
    func_150FC974(arg0);
    func_1514933C(arg0);
}

extern void func_15149368(struct260 *);

void func_150FC9D0(struct260 *arg0) {
    func_150FC974(arg0);
    func_15149368(arg0);
}
