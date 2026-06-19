#include <ultra64.h>
#include "functions.h"
#include "variables.h"


void func_150BA4C0(struct127 *arg0, u8 arg1, s32 arg2) {
    struct {
        struct127 *unk0;
        u8 unk4;
        f32 unk8;
    } sp3C;
    struct260 *temp_v0;

    sp3C.unk0 = arg0;
    sp3C.unk4 = arg0->unique_id;
    sp3C.unk8 = 0.0f;

    temp_v0 = func_15149130((func_150ADA20() % 9U) + 0xF, -1, 0x52, -1, 1, 0x3F, (struct37 *)0xC, arg1, arg2);
    if (temp_v0 != NULL) {
        memcpy((void *)((s32)temp_v0 + 0x28), &sp3C, 0xC);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_E7970/func_150BA55C.s")

void func_15149514(s32 arg0, u8 arg1, s32 arg2, s32 arg3, s32 arg4);

void func_150BA8F0(s32 arg0, s32 arg1, u8 arg2) {
    func_15149514(arg1, arg2, arg0 + 0x28, arg0 + 0x2C, arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_E7970/func_150BA930.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_E7970/func_150BAA00.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_E7970/func_150BAA14.s")
