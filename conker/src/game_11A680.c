#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_11A680/func_150ED1D0.s")

extern void func_150ED1D0(f32, f32);

void func_150ED234(f32 *arg0, f32 *arg1) {
    s32 temp;
    temp = func_1505A630(arg1[5] - arg0[5], arg0[7] - arg1[7], 0) + 0x4000;
    func_150ED1D0((f32)temp * 0.0054931640625f, arg0[0x10]);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_11A680/func_150ED298.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_11A680/func_150ED578.s")

extern void func_15062FC0(struct127 *, s32, s32, s32, s32, s32, s32, s32);

void func_150ED638(struct127 *arg0, s32 arg1, s32 arg2) {
    s32 temp;
    s32 count;

    if (arg1 < -0x2D) {
        arg1 = -0x2D;
    } else {
        temp = (arg1 >= 0x2E) ? 0x2D : arg1;
        arg1 = temp;
    }

    if (arg2 < -0x2D) {
        arg2 = -0x2D;
    } else {
        temp = (arg2 >= 0x2E) ? 0x2D : arg2;
        arg2 = temp;
    }

    if (arg0->id == 0x28) {
        count = 0x7C;
    } else {
        temp = arg1;
        arg1 = arg2;
        count = 0x1C;
        arg2 = temp;
    }

    func_15062FC0(arg0, 0, 0, 0x800, 0x800, count, -arg2 * 7, 0);
    func_15062FC0(arg0, 1, count, 0x800, 0x800, count, -arg1 * 7, 0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_11A680/func_150ED748.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_11A680/func_150EEC84.s")

extern void func_151045E0(void *, s32, f32);
extern void func_15052590(void);

void func_150EEDA8(u8 *arg0) {
    if (arg0[5] != 3) {
        func_151045E0(arg0, 0xF, 250.0f);
        arg0[5] = 3;
        *(s16 *)(arg0 + 0xE4) = 0;
        arg0[0x125] = 0xFF;
    }
    func_15052590();
}
