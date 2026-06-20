#include <ultra64.h>
#define func_1513EDE4 func_1513EDE4_orig
#include "functions.h"
#undef func_1513EDE4
#include "variables.h"

extern s32 *func_1513EDE4(s32 arg0, s16 arg1);


#pragma GLOBAL_ASM("asm/nonmatchings/game_129EE0/func_150FCA30.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_129EE0/func_150FCBC0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_129EE0/func_150FCF1C.s")

void func_150FCFB0(s32 arg0) {
    func_15103828();
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_129EE0/func_150FCFD4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_129EE0/func_150FD514.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_129EE0/func_150FDB0C.s")

s32 *func_150FDBA0(s32 arg0, s16 arg1) {
    s32 *node;

    node = func_1513EDE4(arg0, arg1);
    if (node != NULL) {
        *(s16 *)((u8 *)node + 0x8) = *(f32 *)(arg0 + 0x124);
        *(s16 *)((u8 *)node + 0x18) = *(f32 *)(arg0 + 0x128);
        *(s16 *)((u8 *)node + 0x28) = *(f32 *)(arg0 + 0x128);
        *(s16 *)((u8 *)node + 0x38) = *(f32 *)(arg0 + 0x124);
    }
    return node;
}

void func_150FDC2C(struct210 *arg0) {
    struct102 **p;

    p = (struct102 **)((u8 *)arg0 + 0x110);
    if (p[9] != 0) {
        func_1516972C(p[9]);
    }
    if (p[10] != 0) {
        func_1516972C(p[10]);
    }
    if (*(u16 *)((u8 *)p + 0x54) != 0) {
        func_100111C8(*(u16 *)((u8 *)p + 0x54));
    }
    if (*(u16 *)((u8 *)p + 0x56) != 0) {
        func_100111C8(*(u16 *)((u8 *)p + 0x56));
    }
}

extern void func_150FDC2C(struct210 *);

void func_150FDCAC(struct210 *arg0) {
    func_150FDC2C(arg0);
    func_1513CA6C(arg0);
}

void func_150FDCD8(struct210 *arg0) {
    func_150FDC2C(arg0);
    func_1513CAA0(arg0);
}
