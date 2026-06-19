#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_15D730/func_15130280.s")

void func_15130280(s32 a0, u8 a1, s32 a2, s32 a3, u8 a4, s32 a5);

void func_15130374(s32 a0, u8 a1, s32 a2, u8 a3, s32 a4) {
    func_15130280(a0, a1, 0, a2, a3, a4);
}

void func_151303BC(s32 a0, u8 a1, s32 a2) {
    func_15130374(a0, a1, a2, 0xFF, 0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_15D730/func_151303EC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_15D730/func_15130A9C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_15D730/func_1513137C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_15D730/func_15131514.s")

void func_15131514(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4);
void func_1513137C(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4);

void func_1513164C(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6, s32 a7, s32 a8) {
    func_15131514(a4, a5, a6, a7, a8);
    func_1513137C(a0, a1, a2, a3, a8);
}

void func_151318E8(s32 a0, s32 a1);

s32 func_151316AC(s32 *a0, s32 a1) {
    func_151318E8((s32)a0 + 0x58, a0[0x2A]);
    return 1;
}

s32 func_15131918(s32 a0, s32 a1);

s32 func_151316DC(s32 *a0, s32 a1) {
    func_15131918((s32)a0 + 0x58, a0[0x2A]);
    return 1;
}

s32 func_15131958(f32 *a0, f32 a1);

s32 func_1513170C(s32 *a0, s32 a1) {
    func_15131958((f32 *)((s32)a0 + 0x58), *(f32 *)&a0[0x2A]);
    return 1;
}

void func_1513173C(void) {
    extern void func_15169804();
    func_15169804();
}

void func_1513175C(void) {
    extern void func_15169824();
    func_15169824();
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_15D730/func_1513177C.s")

extern s32 (*D_80089844[])(s32 *);

s32 func_151317C8(s32 *a0) {
    s32 idx;

    if (a0[0x1A] & 0x4000) {
        idx = *((u8 *)a0 + 0x75);
    } else {
        idx = 0;
    }
    return D_80089844[idx](a0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_15D730/func_15131814.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_15D730/func_15131828.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_15D730/func_151318E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_15D730/func_15131918.s")

s32 func_15131958(f32 *a0, f32 a1) {
    s32 i;

    for (i = D_800BE9E4; i > 0; i--) {
        a0[0] = a0[0] * a1;
        a0[1] = a0[1] * a1;
        a0[2] = a0[2] * a1;
    }
}

s32 func_151319C4(void *arg0, s32 arg1, void *arg2);

s32 func_151319A4(u8 *arg0, s32 arg1) {
    return func_151319C4(arg0, arg1, arg0 + 0xA8);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_15D730/func_151319C4.s")

s32 func_15131AFC(u8 *arg0, s32 arg1) {
    func_15131958((f32 *)((s32)arg0 + 0x58), *(f32 *)(arg0 + 0xA8));
    return func_151319C4(arg0, arg1, arg0 + 0xB0);
}

s32 func_15131B3C(u8 *arg0, s32 arg1) {
    func_15131918((s32)arg0 + 0x58, *(s32 *)(arg0 + 0xA8));
    return func_151319C4(arg0, arg1, arg0 + 0xB0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_15D730/func_15131B7C.s")

extern s32 (*D_80089878[])(s32 *, s32, u8);

s32 func_15131C2C(s32 *a0, s32 a1, u8 a2) {
    s32 (*fn)(s32 *, s32, u8);

    if (a0[0x1A] & 0x4000) {
        fn = D_80089878[*((u8 *)a0 + 0x75)];
        if (fn != 0) {
            fn(a0, a1, a2);
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_15D730/func_15131C84.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_15D730/func_15131D4C.s")

s32 func_15131C84(void *a0, void *a1, s32 a2, void *a3, void *a4, void *a5);

s32 func_15131D9C(u8 *arg0, s32 arg1) {
    func_15131C84(arg0 + 0xA8, arg0 + 0xAA, *(s32 *)(arg0 + 0xAC), arg0 + 0xB0, arg0 + 0x38, arg0 + 0x3C);
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_15D730/func_15131DEC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_15D730/func_15131EE4.s")
