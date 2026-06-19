#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_200930/func_151D3480.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_200930/func_151D3D50.s")

void func_15143134(void *, s32, s32);

void func_151D3E04(s32 *arg0, f32 *arg1, void *arg2, u8 arg3, f32 arg4) {
    if (arg0[0x1D4 / 4] != 0) {
        func_15143134(arg2, (s32)arg1, arg0[0x1D4 / 4] + (arg3 << 6));
    } else {
        arg1[0] = *(f32 *)((u8 *)arg0 + 0x14);
        arg1[1] = *(f32 *)((u8 *)arg0 + 0x18) + arg4;
        arg1[2] = *(f32 *)((u8 *)arg0 + 0x1C);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_200930/func_151D3E6C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_200930/func_151D3F14.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_200930/func_151D3FF4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_200930/func_151D40D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_200930/func_151D42E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_200930/func_151D4408.s")

struct S151D4668 {
    void *unk0;
    u8 unk4;
};

void func_151D4668(void *arg0) {
    struct S151D4668 sp18;
    sp18.unk0 = arg0;
    sp18.unk4 = *((u8 *)arg0 + 0x3B);
    func_151494E0((s32)&sp18, 0x3C);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_200930/func_151D469C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_200930/func_151D4794.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_200930/func_151D4C38.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_200930/func_151D4D04.s")

void func_151D469C(void *arg0, s32 a1, s32 a2, s32 a3, s32 a4);

void func_151D4D58(void *arg0) {
    func_151D469C(arg0, 0, 0x50, 0xFF, 1);
    func_151D469C(arg0, 1, 0x50, 0xFF, 1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_200930/func_151D4DAC.s")

void func_151D5148(void *arg0) {
    s16 *p = *(s16 **)((u8 *)arg0 + 0x31C);
    if (p[0x24 / 2] > 0) {
        p[0x24 / 2]--;
        p = *(s16 **)((u8 *)arg0 + 0x31C);
    }
    p[0x1AA / 2]++;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_200930/func_151D5174.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_200930/func_151D5334.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_200930/func_151D5404.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_200930/func_151D5514.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_200930/func_151D5648.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_200930/func_151D5714.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_200930/func_151D57F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_200930/func_151D5A18.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_200930/func_151D5B6C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_200930/func_151D5D60.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_200930/func_151D5E30.s")
