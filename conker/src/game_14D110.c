#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_14D110/func_1511FC60.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_14D110/func_15120158.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_14D110/func_15121490.s")

void func_151216F8(struct108 *arg0) {
    s32 temp_v0;

    temp_v0 = arg0->unk23E;
    if (temp_v0) {
        if (temp_v0 == 0x34) {
            arg0->unk190 = 80.0f;
            *(f32 *)((u8 *)arg0 + 0x784) = 350.0f;
            return;
        }
        if ((temp_v0 == 0x3B) && ((D_800BE9F0 == 0x41) || (D_800BE9F0 == 0x3C))) {
            arg0->unk190 = -12.0f;
            *(f32 *)((u8 *)arg0 + 0x99C) = -28.0f;
            *(f32 *)((u8 *)arg0 + 0x784) = 106.0f;
            return;
        }
        if ((temp_v0 == 2) || (temp_v0 == 0xA) || (temp_v0 == 0x13)) {
            arg0->unk190 = 10.0f;
            arg0->unk84 |= 0x80;
            *(f32 *)((u8 *)arg0 + 0x784) = 135.0f;
            *(f32 *)((u8 *)arg0 + 0x99C) = 0.0f;
            return;
        }
        if ((temp_v0 == 0x12) && (D_800BE9F0 == 0x3C)) {
            arg0->unk190 = 10.0f;
            *(f32 *)((u8 *)arg0 + 0x784) = 180.0f;
            *(f32 *)((u8 *)arg0 + 0x99C) = 0.0f;
            return;
        }
        if (temp_v0 == 0xF) {
            arg0->unk190 = 10.0f;
            *(f32 *)((u8 *)arg0 + 0x784) = 480.0f;
            *(f32 *)((u8 *)arg0 + 0x99C) = 0.0f;
            return;
        }
        if (temp_v0 == 0x38) {
            *(f32 *)((u8 *)arg0 + 0x784) = 110.0f;
            arg0->unk190 = 5.0f;
            *(f32 *)((u8 *)arg0 + 0x99C) = 0.0f;
            return;
        }
        if (temp_v0 == 0x15) {
            *(f32 *)((u8 *)arg0 + 0x784) = 110.0f;
            arg0->unk190 = 25.0f;
            *(f32 *)((u8 *)arg0 + 0x99C) = 0.0f;
            return;
        }
        arg0->unk190 = 5.0f;
        *(f32 *)((u8 *)arg0 + 0x784) = 75.0f;
        *(f32 *)((u8 *)arg0 + 0x99C) = 0.0f;
        return;
    }
    *(f32 *)((u8 *)arg0 + 0x784) = 90.0f;
    arg0->unk190 = 25.0f;
    *(f32 *)((u8 *)arg0 + 0x99C) = 0.0f;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_14D110/func_151218C4.s")
