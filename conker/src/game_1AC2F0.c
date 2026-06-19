#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_1AC2F0/func_1517EE40.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1AC2F0/func_1517EF00.s")

extern s32 func_1517EF00(s32);

s32 func_1517EFAC(s32 arg0) {
    if (func_1517EF00(arg0) == 0xFF) {
        return 1;
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1AC2F0/func_1517EFDC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1AC2F0/func_1517F08C.s")

extern u8 D_800DDDA0[];
s32 func_1517F08C(s32 arg0, s32 arg1, u8 arg2, u8 arg3, u8 arg4, s32 arg5);

s32 func_1517F3A0(s32 arg0, s32 arg1) {
    s32 v0 = func_1517EF00(arg1);
    u8 *p;
    if (v0 == 0) {
        return arg0;
    }
    p = &D_800DDDA0[arg1 * 3];
    return func_1517F08C(arg0, v0, p[0], p[1], p[2], arg1);
}

s32 func_1517F40C(s32 arg0) {
    if ((&D_800DDDB0)[arg0] >= (&D_800DDE28)[arg0]) {
        return 1;
    }
    return 0;
}

void func_1517F448(s32 arg0) {
    if ((&D_800DDDB0)[arg0] != (&D_800DDE28)[arg0]) {
        (&D_800DDDB0)[arg0] += D_800BE9E4;
    }
}

extern u8 D_800DDD90[];
extern u8 D_800DDD9C[];
extern s16 D_800DDE10[];

void func_1517F488(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    u8 *p = &D_800DDD90[arg5 * 3];
    p[0] = arg0;
    p[1] = arg1;
    p[2] = arg2;
    D_800DDD9C[arg5] = arg3;
    D_800DDE10[arg5] = arg4;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1AC2F0/func_1517F4D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1AC2F0/func_1517F564.s")

extern u8 D_800DDD88;
extern u8 D_800DDD89;
extern u8 D_800DDD8A;
extern u8 D_800DDD8B;
extern u8 D_800DDD8C;

void func_1517F720(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    D_800DDE08 = arg1;
    D_800DDD88 = arg2;
    D_800DDD89 = 0;
    D_800DDD8A = arg0;
    D_800DDD8B = arg3;
    D_800DDD8C = arg4;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1AC2F0/func_1517F75C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1AC2F0/func_1517F7B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1AC2F0/func_1517F814.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1AC2F0/func_1517F9F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1AC2F0/func_1517FB9C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1AC2F0/func_15180580.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1AC2F0/func_151814FC.s")

extern f32 D_800DDDC8;

s32 func_15181CC8(s32 arg0) {
    if ((&D_800DDDC8)[arg0] == 0.0f) {
        return 1;
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1AC2F0/func_15181D00.s")

extern f32 D_800A72B0;
extern f32 D_800DDDE8[][2];

void func_15181D70(s32 arg0) {
    (&D_800DDDD8)[arg0] = D_800A72B0;
    (&D_800DDDC8)[arg0] = 0.0f;
    D_800DDDE8[arg0][0] = 0.0f;
    D_800DDDE8[arg0][1] = 0.0f;
    (&D_800DDE20)[arg0] = 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1AC2F0/func_15181DC8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1AC2F0/func_15181E18.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1AC2F0/func_15181EE0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1AC2F0/func_15182670.s")

void func_15182748(s32 arg0) {
    *(u8 *)(arg0 + 0x2B) = *(s16 *)(arg0 + 0xE) * *(s16 *)(arg0 + 0x2E);
}

s32 func_15182768(s32 arg0, s32 arg1, s16 arg2) {
    u8 *p = (u8 *)(*(s32 *)&arg1 + 0x28);
    if (arg2 == *(u8 *)(*(s32 *)&arg1 + 0x2C)) {
        arg0 = func_1517F08C(arg0, p[3], p[0], p[1], p[2], p[4]);
    }
    return arg0;
}
