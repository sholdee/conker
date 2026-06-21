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

s32 func_150DFDD0(s32 arg0, s32 arg1) {
    f32 temp_f2;
    s32 *temp_v0;
    s32 temp_a0;
    s32 temp_a2;
    s32 temp_v1;

    if (*(s32 *)(arg1 + 0x2EC) != 0) {
        *(u8 *)(arg0 + 0x13) = 2;
        *(f32 *)(arg1 + 0x2D8) = *(f32 *)(arg1 + 0x2D8) - D_800BE9A4;
        if (*(f32 *)(arg1 + 0x2D8) < 0.0f) {
            *(s32 *)(arg1 + 0x2EC) = 0;
            return 1;
        }
        temp_f2 = 1.0f - (*(f32 *)(arg1 + 0x2D8) * *(f32 *)(arg1 + 0x2DC));
    } else {
        temp_f2 = 0.0f;
        *(u8 *)(arg0 + 0x13) = 0;
    }

    temp_v0 = *(s32 **)(*(s32 *)(arg0 + 0x24));
    if (temp_v0 != 0) {
        temp_v1 = 0;
        if (*(s8 *)((temp_v1 << 3) + (u8 *)temp_v0) != -0xE) {
            do {
            } while (*(s8 *)((u8 *)temp_v0 + (++temp_v1 << 3)) != -0xE);
        }
        temp_a0 = *(s32 *)((u8 *)temp_v0 + (temp_v1 * 8));
        arg1 = (s32)((u8 *)temp_v0 + (temp_v1 * 8));
        temp_a2 = 2 - ((s32)(((u32)temp_a0 >> 12) & 0xFFF) / 3);
        while (temp_a2 < 0) {
            temp_a2 += 0x40;
        }
        *(s32 *)arg1 = 0xF2000000 | ((((s32)((500.0f * temp_f2) + 2.0f)) & 0xFFF) << 12) | (temp_a2 & 0xFFF);
    }

    return 0;
}

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
