#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern f32 D_800AA0F0[];
extern f32 D_800AA0FC[];

void func_15143134(f32 *, f32 *, s32);
void func_1504715C(s32, s32);
s32 func_15046C80(f32 *, s32, f32, s32);

s32 func_151AF5C0(f32 *arg0, s32 arg1, s32 arg2, u8 arg3) {
    f32 sp2C[3];
    f32 *temp_a0;
    s32 temp_a2;

    if ((arg3 != 1) && (arg3 != 2)) {
        return 0;
    }

    if (arg3 == 1) {
        temp_a0 = D_800AA0FC;
    } else {
        temp_a0 = D_800AA0F0;
    }

    if (arg3 == 1) {
        temp_a2 = *(s32 *)(arg1 + 0x1D4) + 0x800;
    } else {
        temp_a2 = *(s32 *)(arg1 + 0x1D4) + 0x640;
    }

    func_15143134(temp_a0, arg0, temp_a2);
    if (arg2 == 0) {
        return 1;
    }

    sp2C[0] = arg0[0];
    sp2C[1] = arg0[1] + 100.0f;
    sp2C[2] = arg0[2];
    func_1504715C(arg2, arg1);
    return func_15046C80(sp2C, 0, arg0[1] - 500.0f, arg2);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1DCA70/func_151AF6C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1DCA70/func_151AF6D4.s")

s32 func_151AFBD4(void *arg0) {
    s32 v0 = *(s16 *)((u8 *)arg0 + 0x1C);
    s32 v1;
    if (v0 < 0x20) {
        v1 = v0 * 8;
        if (v1 < *(u8 *)((u8 *)arg0 + 0x28)) {
            *(u8 *)((u8 *)arg0 + 0x28) = v1;
        }
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1DCA70/func_151AFC08.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1DCA70/func_151AFC88.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1DCA70/func_151AFEA4.s")
