#include <ultra64.h>
#include "functions.h"
#include "variables.h"


void func_15179008(s32);
extern f32 D_800A26B0;
extern f32 D_800A26B4;
extern f32 D_800A26B8;
extern void func_15114D24(s32, s32, s32, s16, s32, s32);

void func_1510AA20(s32 arg0) {
    func_15179008(0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_137ED0/func_1510AA44.s")

void func_1510ADD8(s32 arg0) {
    f32 temp;

    *(f32 *)(arg0 + 0x80) += (D_800A26B0 * D_800BE9E4) / 60.0f;
    temp = cosf(*(f32 *)(arg0 + 0x80)) * 10.0f;
    *(f32 *)(arg0 + 0x60) = *(f32 *)arg0 - temp;
    *(f32 *)arg0 = temp;
    if (*(s32 *)(arg0 + 0x7C) == 0) {
        if (D_800A26B4 <= *(f32 *)(arg0 + 0x80)) {
            *(s32 *)(arg0 + 0x7C) = 1;
            func_15114D24(arg0, 0x4CA, 0x2EE0, 0xC8, 0x3E8, 4);
        }
    } else {
        temp = D_800A26B8;
        if (temp <= *(f32 *)(arg0 + 0x80)) {
            *(f32 *)(arg0 + 0x80) -= temp;
            *(s32 *)(arg0 + 0x7C) = 0;
            func_15114D24(arg0, 0x4CB, 0x2EE0, 0xC8, 0x3E8, 4);
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_137ED0/func_1510AEE0.s")
