#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void func_15132444(struct102 *arg0);
s32 func_1513264C(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, u8 arg5, s32 arg6);

#pragma GLOBAL_ASM("asm/nonmatchings/game_15F680/func_151321D0.s")

extern void (*D_800899B0[])(s32);

void func_151323AC(s32 arg0) {
    s32 idx;

    idx = (*(s32 *)(arg0 + 0x60) & 0x100) ? *(u8 *)(arg0 + 0x68) : 0;
    D_800899B0[idx](arg0);
}

extern void (*D_800899D4[])(s32);

void func_151323F8(s32 arg0) {
    s32 idx;

    idx = (*(s32 *)(arg0 + 0x60) & 0x100) ? *(u8 *)(arg0 + 0x68) : 0;
    D_800899D4[idx](arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_15F680/func_15132444.s")

void func_15132570(struct102 *arg0) {
    func_15132444(arg0);
    func_15169804(arg0);
}

void func_1513259C(struct102 *arg0) {
    func_15132444(arg0);
    func_15169824(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_15F680/func_151325C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_15F680/func_1513264C.s")

s32 func_15132A4C(s32 arg0, s32 arg1, s32 arg2, s32 arg3, u8 arg4, s32 arg5) {
    return func_1513264C(arg0, arg1, arg2, 0, arg3, arg4, arg5);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_15F680/func_15132A88.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_15F680/func_15132B80.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_15F680/func_15132DDC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_15F680/func_151332DC.s")

s32 func_151424F4(s32 arg0, s32 arg1, s32 arg2, s32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, f32 arg8, f32 arg9, f32 arg10, f32 arg11);

s32 func_15133510(s32 arg0, s32 arg1) {
    func_151424F4(arg0,
                  *(s32 *)(arg1 + 0x18),
                  *(s32 *)(arg1 + 0x1C),
                  *(s32 *)(arg1 + 0x20),
                  *(f32 *)(arg1 + 0x24),
                  *(f32 *)(arg1 + 0x28),
                  *(f32 *)(arg1 + 0x2C),
                  *(f32 *)(arg1 + 0x30),
                  *(f32 *)(arg1 + 0x34),
                  *(f32 *)(arg1 + 0x38),
                  *(f32 *)(arg1 + 0x3C),
                  *(f32 *)(arg1 + 0x40));
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_15F680/func_15133588.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_15F680/func_151336A8.s")

s32 func_15142838(s32 arg0, f32 arg1, f32 arg2, s32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, f32 arg8);

s32 func_15133760(s32 arg0, s32 arg1) {
    func_15142838(arg0, *(f32 *)(arg1 + 0x18), *(f32 *)(arg1 + 0x1C), *(s32 *)(arg1 + 0x20),
                  *(f32 *)(arg1 + 0x24), *(f32 *)(arg1 + 0x28), *(f32 *)(arg1 + 0x38),
                  *(f32 *)(arg1 + 0x3C), *(f32 *)(arg1 + 0x40));
    return 1;
}

s32 func_151337C0(f32 *arg0) {
    arg0[14] += arg0[17] * D_800BE9A4;
    arg0[15] += (arg0[18] * D_800BE9A4) + (((arg0[23] * D_800BE9A4) * D_800BE9A4) * 0.5f);
    arg0[16] += arg0[19] * D_800BE9A4;
    arg0[18] += arg0[23] * D_800BE9A4;
    arg0[8] += arg0[20] * D_800BE9A4;
    arg0[9] += arg0[21] * D_800BE9A4;
    arg0[10] += arg0[22] * D_800BE9A4;
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_15F680/func_15133894.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_15F680/func_151339D4.s")

s32 func_15133A50(s32 arg0, s32 arg1, s32 arg2, s32 arg3, f32 arg4) {
    *(f32 *)(arg0 + 0x3C) = *(f32 *)(arg0 + 0x10) + arg4;
    *(f32 *)(arg0 + 0x44) = 0.0f;
    *(f32 *)(arg0 + 0x48) = 0.0f;
    *(f32 *)(arg0 + 0x4C) = 0.0f;
    *(f32 *)(arg0 + 0x50) = 0.0f;
    *(f32 *)(arg0 + 0x54) = 0.0f;
    *(f32 *)(arg0 + 0x58) = 0.0f;
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_15F680/func_15133A94.s")

s32 func_15133B98(s32 arg0, s32 arg1, s32 arg2, s32 arg3, f32 arg4, s32 arg5) {
    f32 temp;

    temp = *(f32 *)(arg0 + 0x14);
    *(f32 *)(arg0 + 0x3C) = *(f32 *)(arg0 + 0x10) + arg4;
    *(f32 *)(arg0 + 0x44) = *(f32 *)(arg0 + 0x44) * temp;
    *(f32 *)(arg0 + 0x48) = *(f32 *)(arg0 + 0x48) * -temp;
    *(f32 *)(arg0 + 0x4C) = *(f32 *)(arg0 + 0x4C) * temp;
    *(f32 *)(arg0 + 0x50) = *(f32 *)(arg0 + 0x50) * temp;
    *(f32 *)(arg0 + 0x54) = *(f32 *)(arg0 + 0x54) * temp;
    *(f32 *)(arg0 + 0x58) = *(f32 *)(arg0 + 0x58) * temp;
    if (fabsf(*(f32 *)(arg0 + 0x48)) < 4.0f) {
        *(s32 *)(arg0 + 0x60) &= -0x6A;
        *(f32 *)(arg0 + 0x44) = 0.0f;
        *(f32 *)(arg0 + 0x48) = 0.0f;
        *(f32 *)(arg0 + 0x4C) = 0.0f;
        *(f32 *)(arg0 + 0x50) = 0.0f;
        *(f32 *)(arg0 + 0x54) = 0.0f;
        *(f32 *)(arg0 + 0x58) = 0.0f;
        *(f32 *)(arg0 + 0x5C) = 0.0f;
    }
    return 1;
}

s32 func_15133C58(s32 arg0, s32 arg1, s32 arg2, s32 arg3, f32 arg4, s32 arg5) {
    func_15133B98(arg0, arg1, arg2, arg3, arg4, arg5);
    if (func_150ADA20() & 1) {
        func_10010F88(((u32)func_150ADA20() % 9) + 0x2DE, 0x2EE0, 0, 0, 0,
                      (s32)*(f32 *)&arg1, (s32)*(f32 *)&arg2, (s32)*(f32 *)&arg3,
                      0x1F4, 0x3E8);
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_15F680/func_15133D20.s")

void func_15133DE8(s32 arg0, s32 arg1, u8 arg2) {
    s32 temp;

    if (arg2 == 0) {
        temp = *(s32 *)(arg1 + 0x0);
        if ((temp == *(s32 *)(arg0 + 0x7C)) ||
            (*(u8 *)(arg1 + 0x4) == *(u8 *)(arg0 + 0x80))) {
            func_1516972C((struct102 *)arg0);
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_15F680/func_15133E3C.s")

s32 func_15133EEC(s32 arg0, u16 arg1, u8 arg2, s32 arg3);

void func_15133E84(s32 arg0, void *arg1, s32 arg2) {
    func_15133EEC(arg0, *(u16 *)((u8 *)arg1 + 0x170), *(u8 *)((u8 *)arg1 + 0x172), *(s32 *)((u8 *)arg1 + 0x174));
}

void func_15133EB8(s32 arg0, void *arg1, s32 arg2) {
    func_15133EEC(arg0, *(u16 *)((u8 *)arg1 + 0x174), *(u8 *)((u8 *)arg1 + 0x176), *(s32 *)((u8 *)arg1 + 0x178));
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_15F680/func_15133EEC.s")

typedef struct {
    u8 unk0[4];
    u16 unk4;
    u8 unk6;
    u8 unk7;
    s32 unk8;
} Elem15133FD8B;

typedef u8 Entry15133FD8[8];

s32 func_15133FD8(s32 arg0, void *arg1, s32 arg2) {
    u8 i;
    Entry15133FD8 *base;
    Elem15133FD8B *e;

    base = (Entry15133FD8 *)((u8 *)arg1 + 0x170);
    for (i = 0; i < (*base)[0]; i++) {
        e = (Elem15133FD8B *)base[i];
        arg0 = func_15133EEC(arg0, e->unk4, e->unk6, e->unk8);
    }
    return arg0;
}
