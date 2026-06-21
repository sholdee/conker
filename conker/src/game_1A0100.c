#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_1A0100/func_15172C50.s")

extern s8 D_800DD2B0[];
void func_1517EE40(s32, s32, s32, s32, s32, s32);

void func_15172CA8(s32 arg0) {
    if (D_800DD2B0[arg0] != -1) {
        D_800DD2B0[arg0] = -1;
        func_1517EE40(0, 0, 0, 0, 1, arg0);
        func_1517EE40(0, 0, 0, 0x32, 0, arg0);
    }
}

extern u8 D_800BE9B4;
void func_15085430(struct127 *, s32, s32);

void func_15172D28(struct127 *arg0, s32 arg1) {
    func_15085430(arg0, arg1, 1);
    arg0->unk2F8 &= 0xFFEF;
    if (D_800BE9B4 == 0) {
        if (arg0->unk31C != NULL) {
            arg0->unk31C->pad56 = 3;
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1A0100/func_15172D80.s")

void func_15172E7C(struct127 *arg0, s32 arg1, s32 arg2) {
    s32 temp_v1;

    temp_v1 = arg0->unk127;
    if (arg0->health != 0) {
        if ((arg0->unk31C != NULL) && (*(s8 *)((u8 *)arg0->unk31C + 0x23) > 0)) {
            return;
        }
        if (arg0->camera != NULL) {
            if (D_800DD2B0[temp_v1] == -1) {
                func_1517EE40(0, 0, 0, 0xA, 1, temp_v1);
                arg0->unk2F8 |= 0x10;
                D_800DD2B0[temp_v1] = arg1;
                (&D_800DD2C0)[temp_v1] = arg2;
            }
        } else if (arg1 == D_800BE9F0) {
            func_15172D28(arg0, arg2);
        }
    }
}
