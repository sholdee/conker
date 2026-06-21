#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern f32 sqrtf(f32);

typedef struct Struct15130280 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
} Struct15130280;

typedef struct Struct15130280Payload {
    Struct15130280 unk0[3];
} Struct15130280Payload;

typedef struct Obj15130280 {
    u8 pad0[0x80];
    Struct15130280Payload unk80;
} Obj15130280;

extern void *func_15167A68(s32, s32, s32, s32, s32, s32);

void *func_15130280(void *arg0, u8 arg1, s32 arg2, s32 arg3, u8 arg4, s32 arg5) {
    void *temp_v0;
    void *sp24;
    s32 id;

    switch (arg1) {
    case 0:
        id = 0x2B;
        break;
    case 1:
        id = 0x52;
        break;
    case 2:
        id = 0x47;
        break;
    default:
        id = 0x2B;
        break;
    }

    temp_v0 = func_15167A68(id, arg5, arg3 + 0xA8, 1, arg4, 1);
    if (temp_v0 == 0) {
        return NULL;
    }

    sp24 = temp_v0;
    memcpy((s32)temp_v0 + 0x10, arg0, 0x70);

    if (arg2 != 0) {
        ((Obj15130280 *)sp24)->unk80 = *(Struct15130280Payload *)arg2;
    } else {
        *(u8 *)((s32)sp24 + 0x9C) = 0;
    }

    return sp24;
}

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

void func_15131C84(u8 *a0, s8 *a1, f32 a2, f32 *a3, f32 *a4, f32 *a5) {
    a0[0] = a1[0] * D_800BE9E4 + a0[0];
    a0[1] = a1[1] * D_800BE9E4 + a0[1];
    *a4 = a3[0] * func_151423D8((u8)(a0[0] - 0x40)) + a2;
    *a5 = a3[1] * func_151423D8((u8)(a0[1] - 0x40)) + a2;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_15D730/func_15131D4C.s")

s32 func_15131D9C(u8 *arg0, s32 arg1) {
    func_15131C84(arg0 + 0xA8, arg0 + 0xAA, *(f32 *)(arg0 + 0xAC), arg0 + 0xB0, arg0 + 0x38, arg0 + 0x3C);
    return 1;
}

s32 func_15131DEC(u8 *arg0, s32 arg1) {
    f32 temp_f2;
    f32 temp_f12;

    temp_f2 = *(f32 *)(arg0 + 0xA8);
    temp_f12 = *(f32 *)(arg0 + 0xB0) * sqrtf(temp_f2);
    *(f32 *)(arg0 + 0x3C) = temp_f12;
    *(f32 *)(arg0 + 0x38) = temp_f12;

    arg0[0x2B] = (u32)(*(f32 *)(arg0 + 0xB4) - ((*(f32 *)(arg0 + 0xB8) * temp_f2) * temp_f2));
    *(f32 *)(arg0 + 0xA8) = temp_f2 + D_800BE9A4;

    if (*(f32 *)(arg0 + 0xAC) < *(f32 *)(arg0 + 0xA8)) {
        return 0;
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_15D730/func_15131EE4.s")
