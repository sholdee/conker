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

extern f32 D_8009FE60;
void func_1504715C(s32 *arg0);
void func_15046C80(struct17 *arg0, s32 arg1, f32 arg2, s32 *arg3);

s32 func_150BA930(struct17 *arg0, struct127 *arg1, s32 *arg2, s32 arg3) {
    struct17 sp24;

    arg0->unk0 = arg1->x_position;
    if (D_8009FE60 < arg1->unk180) {
        arg0->unk4 = arg1->unk180;
    } else {
        arg0->unk4 = arg1->y_position;
    }
    arg0->unk8 = arg1->z_position;
    if (arg2 == 0) {
        return 1;
    }
    sp24.unk0 = arg0->unk0;
    sp24.unk4 = arg0->unk4 + 100.0f;
    sp24.unk8 = arg0->unk8;
    func_1504715C(arg2);
    func_15046C80(&sp24, 0, arg0->unk4 - 100.0f, arg2);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_E7970/func_150BAA00.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_E7970/func_150BAA14.s")
