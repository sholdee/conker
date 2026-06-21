#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern s32 D_800DBDC0;
extern s32 D_800DBDC4;
extern s32 D_800DBDC8;
extern f32 D_800DBDCC;
extern f32 D_800DBDD0;

extern void func_150A6760(s32);
extern void func_150F33F8(s32);
extern s32 func_1510FE30(s32);

#pragma GLOBAL_ASM("asm/nonmatchings/game_13BB20/func_1510E670.s")

void func_1510E950(s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32, u16, s32, f32, f32, s32);

void func_1510E7A4(s32 a0, s32 a1, s32 a2, s32 a3, s32 arg4, s32 arg5, f32 arg6, f32 arg7, f32 arg8, f32 arg9, u16 arg10, s32 arg11, f32 arg12, f32 arg13) {
    func_1510E950(a0, a1, 0, a2, a3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, 0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_13BB20/func_1510E82C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_13BB20/func_1510E8BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_13BB20/func_1510E950.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_13BB20/func_1510F648.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_13BB20/func_1510F720.s")

extern void func_150A49F4(void);

void func_1510F800(void) {
    func_150A49F4();
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_13BB20/func_1510F820.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_13BB20/func_1510F8CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_13BB20/func_1510F8D8.s")

void func_1510FC34(s32 arg0) {
    struct108 *temp_v0;
    s32 temp_a0;
    s32 temp_a1;
    s32 temp_v0_2;
    s16 *temp_v1;

    D_800DBDC0 = arg0;
    temp_v0 = (struct108 *)((u8 *)D_800DBFF0 + (arg0 * sizeof(struct108)));
    temp_a0 = temp_v0->unk2F8;
    temp_a1 = temp_v0->unk300;
    D_800DBDCC = temp_a0;
    D_800DBDD0 = temp_a1;
    temp_v0_2 = func_1510FD20(temp_a0, temp_a1);
    D_800DBDC8 = temp_v0_2;
    temp_v0_2 = func_1510FE30(temp_v0_2);
    D_800DBDC4 = temp_v0_2;
    temp_v1 = &((s16 *)&D_800DBE30)[arg0];
    if (temp_v0_2 != *temp_v1) {
        *temp_v1 = temp_v0_2;
        func_150A6760(arg0);
    }
    if (D_800BE9F0 == 0x3C) {
        func_150F33F8(arg0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_13BB20/func_1510FD20.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_13BB20/func_1510FE30.s")
