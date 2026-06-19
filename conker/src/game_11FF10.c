#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_11FF10/func_150F2A60.s")

void func_150F2C8C(struct127 *arg0) {
    struct {
        struct127 *unk0;
        u8 unk4;
        u8 unk5;
        f32 unk8;
        u8 unkC;
    } sp38;
    struct260 *temp_v0;

    sp38.unk0 = arg0;
    sp38.unk4 = arg0->unique_id;
    sp38.unk5 = 0;
    sp38.unk8 = 0.0f;
    sp38.unkC = 0;

    temp_v0 = func_15149130(0x12C, -1, 0x5C, -1, 0, 0x44, (struct37 *)0x10, 0xFF, 1);
    if (temp_v0 != NULL) {
        memcpy((void *)((s32)temp_v0 + 0x28), &sp38, 0x10);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_11FF10/func_150F2D14.s")

void func_150F3194(s32 arg0, s32 arg1, u8 arg2) {
    func_15169850(arg1, arg2, arg0 + 0x28, arg0 + 0x2C, arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_11FF10/func_150F31D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_11FF10/func_150F3214.s")

void func_150F337C(s32 arg0, s16 arg1) {
    func_15140410(arg0, arg0 + 0x12C, arg0 + 0x138, arg1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_11FF10/func_150F33B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_11FF10/func_150F33F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_11FF10/func_150F34A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_11FF10/func_150F34F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_11FF10/func_150F43F0.s")
