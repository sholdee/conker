#include <ultra64.h>
#include "functions.h"
#include "variables.h"


u16 *func_150B58F0(u16 *arg0, s32 arg1) {
    if (D_800C35EA == 1) {
        return arg0;
    }
    arg0[0] = 0x1A;
    arg0[1] = *(u16 *)((u8 *)D_800CC34A + 812 * arg1);
    return arg0 + 2;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_E2DA0/func_150B5950.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_E2DA0/func_150B5A3C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_E2DA0/func_150B5C38.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_E2DA0/func_150B5E34.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_E2DA0/func_150B6000.s")

extern void func_15143134(void *, s32, s32);
extern s32 D_8009FC30;

void func_150B60E0(s32 *arg0, s32 arg1) {
    func_15143134(&D_8009FC30, arg1, arg0[0x1D4 / 4] + 0x140);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_E2DA0/func_150B6110.s")

void func_150B6450(struct102 *arg0, s32 arg1, u8 arg2) {
    if (arg2 == 0x4A) {
        func_1516972C(arg0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_E2DA0/func_150B648C.s")

struct inner150B66DC {
    u8 pad[0x68];
    u8 unk68;
};
struct sub150B66DC {
    u8 pad0[0x14];
    u8 *unk14;
    struct inner150B66DC *unk18;
};

s32 func_150B66DC(struct sub150B66DC *arg0) {
    struct inner150B66DC *p = arg0->unk18;
    switch (p->unk68 - 0xF) {
    case 0:
        arg0->unk14[9] = 1;
        break;
    case 1:
        arg0->unk14[9] = 0;
        arg0->unk14[0x2F] = 0x14;
        break;
    case 2:
    default:
        arg0->unk14[9] = 0;
        arg0->unk14[0x2F] = 0x28;
        break;
    }
    return 1;
}

extern void func_15182670(s32, s32, s32, s32, s32, s32, s32, s32);

void func_150B6754(u8 arg0, s32 arg1) {
    u32 temp1;
    u32 temp0;

    temp0 = func_150ADA20();
    temp1 = func_150ADA20();
    func_15182670(0xCC, 0xCC, 0xFF, (u8)(temp0 % 0x38 + 0xC8), temp1 % 0xB + 0xF, 0, arg0, arg1);
}
