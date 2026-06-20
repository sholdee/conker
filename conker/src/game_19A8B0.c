#include <ultra64.h>
#define func_15048A40 func_15048A40_void_unused
#include "functions.h"
#undef func_15048A40
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_19A8B0/func_1516D400.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_19A8B0/func_1516D4E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_19A8B0/func_1516D678.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_19A8B0/func_1516D738.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_19A8B0/func_1516D99C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_19A8B0/func_1516DB90.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_19A8B0/func_1516E778.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_19A8B0/func_1516E8CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_19A8B0/func_1516ECAC.s")

extern void func_1516D99C();

void func_1516ED68(s32 a0, s32 a1, u8 a2, s32 a3) {
    u8 v;
    v = D_800CC2D4[a0 * 812];
    if (v != 0x3A) {
        return;
    }
    func_1516D99C(5, 0, 0, 4,
        0, 0xFF, 0xFF, 0xFF, 0, 0, 0, 0,
        2, 0, 0, 0, 0, 0, 0, 8,
        0, 0, 0, 0, 0, 0, 0, 0x124,
        0x124, 0, 0, a1, 0, 0, a0, 0xC,
        0, 0, 0x81, 2, 0, 1, 0, 0,
        0, 5, 0, a2, a3);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_19A8B0/func_1516EED4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_19A8B0/func_1516F024.s")

extern void func_1516D99C();

void func_1516F1C0(s32 a0, s32 a1, u8 a2, s32 a3) {
    func_1516D99C(2, 0, 0, 0x2D,
        0, 0xFF, 0xFF, 0xFF, 0, 0, 0, 0,
        2, 0, 0, 0, 0, 0, 0, 1,
        0, 0, 0, 0, 0, 0, 0, 0x50,
        0x50, 0, 0, a1, 0xA, 0xA, a0, 0x3C,
        0, 0, 0x81, 4, 0, 1, 0, 0,
        0, 4, 2, a2, a3);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_19A8B0/func_1516F2F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_19A8B0/func_1516F548.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_19A8B0/func_1516F864.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_19A8B0/func_1516F8EC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_19A8B0/func_1516F91C.s")

extern void func_1516F8EC(s32, s32);
extern void func_1516F91C(s32, s32);

void func_1516F94C(s32 arg0, s32 arg1) {
    func_1516F8EC(arg0, arg1);
    func_1516F91C(arg0, arg1);
}

void func_1516F984(s32 arg0, s32 arg1) {
    s32 temp;
    func_1516F94C(arg0, arg1);
    temp = *(s16*)(arg0 + 0x18);
    temp = temp * arg1;
    *(s16*)(arg0 + 0x18) = temp >> 8;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_19A8B0/func_1516F9C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_19A8B0/func_1516FA88.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_19A8B0/func_1516FBCC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_19A8B0/func_1516FD50.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_19A8B0/func_1516FE1C.s")

extern u8 func_150ADA20(void);
extern f32 func_150489B0(u8);
extern f32 func_15048A40(u8);

void func_15170034(s32 arg0, f32 *arg1, f32 *arg2, f32 *arg3) {
    s32 mask;
    f32 r;
    f32 sp24;
    f32 sp20;
    s32 v;

    mask = (arg0 & 0x40) ? 0x3F : 0x7F;
    v = func_150ADA20() & mask;
    *arg2 = func_150489B0((u8)v);
    sp20 = func_15048A40((u8)v);
    v = func_150ADA20() & 0xFF;
    sp24 = func_150489B0((u8)v);
    r = func_15048A40((u8)v);
    *arg1 = sp20 * r;
    *arg3 = sp20 * sp24;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_19A8B0/func_151700D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_19A8B0/func_15170500.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_19A8B0/func_151707E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_19A8B0/func_151709B4.s")
