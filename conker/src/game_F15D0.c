#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_F15D0/func_150C4120.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_F15D0/func_150C44A4.s")

void func_150C4AD8(struct260 *arg0) {
    if (*(s32 *)((u8 *)arg0 + 0x34) != 0) {
        func_1516972C(*(struct102 **)((u8 *)arg0 + 0x34));
    }
}

extern void func_150C4AD8(struct260 *);

void func_150C4B08(struct260 *arg0) {
    func_150C4AD8(arg0);
    func_1514933C(arg0);
}

extern void func_15149368(struct260 *);

void func_150C4B34(struct260 *arg0) {
    func_150C4AD8(arg0);
    func_15149368(arg0);
}

void func_150C4B60(s32 arg0, s32 arg1, u8 arg2) {
    s32 *p = &arg0;
    s32 q;

    if (arg2 == 0x55) {
        q = *p;
        q += 0x28;
        *(u8 *)(q + 0x16) = *(u8 *)(q + 0x16) & 0xFFFD;
    } else if (arg2 == 0x56) {
        q = *p;
        q += 0x28;
        *(u8 *)(q + 0x16) = *(u8 *)(q + 0x16) | 2;
    } else {
        q = *p + 0x28;
        func_15149514(arg1, arg2, q, q + 4, *p);
    }
}
