#include <ultra64.h>
#include "functions.h"
#include "variables.h"


typedef struct { u8 c[3]; } Outer;
extern Outer D_80088984;

s32 func_150DF8C0(s32 a0) {
    Outer sp4;
    sp4 = D_80088984;
    if (((struct178 *)*(s32 *)&D_800D3098)[((u8 *)&sp4)[a0]].unk6[0xE] != 0) {
        return 1;
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_10CD70/func_150DF920.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_10CD70/func_150DFBD0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_10CD70/func_150DFCA8.s")

extern f32 D_800A0FB0;

void func_150DFDA4(s32 a0) {
    f32 *p = (f32 *)(*(s32 *)(a0 + 0x1D4) + 0x40);
    p[0xC] = *(f32 *)(a0 + 0x14);
    p[0xD] = D_800A0FB0;
    p[0xE] = *(f32 *)(a0 + 0x1C);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_10CD70/func_150DFDD0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_10CD70/func_150DFEFC.s")

void func_150E02C0(s32 arg0, s32 arg1, s32 arg2) {
    func_15149514(arg1, (u8)arg2, arg0 + 0x28, arg0 + 0x2C, arg0);
}

void func_1513BAE8(void);

void func_150E0300(void) {
    if (D_80088980 == 0) {
        func_1515F170(6, 0);
        func_1513BAE8();
        D_80088980 = 1;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_10CD70/func_150E0348.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_10CD70/func_150E03F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_10CD70/func_150E05F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_10CD70/func_150E06D8.s")
