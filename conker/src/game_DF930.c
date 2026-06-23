#include <ultra64.h>
#include "functions.h"
#include "variables.h"


void func_1514C678(f32, f32, s32, f32, s32, s32, s32, s32, s32, f32, s32, s32);
void func_151D3FF4(struct17 *, u8, s32);

#pragma GLOBAL_ASM("asm/nonmatchings/game_DF930/func_150B2480.s")

void func_150B2494(struct127 *arg0, s32 arg1, s32 arg2) {
    struct17 sp3C;

    sp3C.unk0 = arg0->x_position;
    sp3C.unk4 = *(f32 *)((u8 *)arg0 + 0x180);
    sp3C.unk8 = arg0->z_position;
    func_1514C678(sp3C.unk0, sp3C.unk4, *(s32 *)&sp3C.unk8, 135.0f, 0, 0xFF,
                  (func_150ADA20() % 15U) + 0x1B, 7, 0, 0.0f, 0, 0xFF);
    func_151D5404(&sp3C, 1502.0f, 3000.0f, 0.00033333332976326346f, 0xC, 0xF, 0xFF, 0);
    func_151D3FF4(&sp3C, 0xFF, 0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_DF930/func_150B2570.s")
