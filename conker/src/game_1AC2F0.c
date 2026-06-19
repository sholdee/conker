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

#pragma GLOBAL_ASM("asm/nonmatchings/game_1AC2F0/func_1517F3A0.s")

s32 func_1517F40C(s32 arg0) {
    if ((&D_800DDDB0)[arg0] >= (&D_800DDE28)[arg0]) {
        return 1;
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1AC2F0/func_1517F448.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1AC2F0/func_1517F488.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1AC2F0/func_1517F4D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1AC2F0/func_1517F564.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1AC2F0/func_1517F720.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/game_1AC2F0/func_15181D70.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1AC2F0/func_15181DC8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1AC2F0/func_15181E18.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1AC2F0/func_15181EE0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1AC2F0/func_15182670.s")

void func_15182748(s32 arg0) {
    *(u8 *)(arg0 + 0x2B) = *(s16 *)(arg0 + 0xE) * *(s16 *)(arg0 + 0x2E);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1AC2F0/func_15182768.s")
