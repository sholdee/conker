#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_C1D70/func_150948C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_C1D70/func_1509499C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_C1D70/func_15094AB8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_C1D70/func_15094EA0.s")

extern Gfx D_800873D0[];
extern s32 D_800D2CA0;

Gfx *func_15094F40(Gfx *arg0) {
    gSPDisplayList(arg0++, D_800873D0);
    D_800D2CA0 = 0;
    return arg0;
}

extern void func_15095060(s32, s32, s32);
extern void func_150950D4(s32, s32 *, s32, s32, s32, s32, s32, s32, s32, s32);
extern s32 D_800D2C90;

void func_15094F70(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8) {
    func_15095060(arg1, arg2, arg3);
    func_150950D4(arg0, &D_800D2C90, arg4, arg5, 0, arg6, arg7, 0x100, 0x100, arg8);
}

void func_15094FE8(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8, s32 arg9, s32 arg10) {
    func_15095060(arg1, arg2, arg3);
    func_150950D4(arg0, &D_800D2C90, arg4, arg5, 0, arg6, arg7, arg8, arg9, arg10);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_C1D70/func_15095060.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_C1D70/func_150950D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_C1D70/func_1509563C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_C1D70/func_15095760.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_C1D70/func_150958B0.s")

void func_15095A90(s32, s32, f32, f32, f32, s32, s32, s32, s32);

void func_15095A48(s32 arg0, s32 arg1, f32 arg2, f32 arg3) {
    func_15095A90(arg0, arg1, arg2, arg3, 4096.0f, 0, 0, 0, 0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_C1D70/func_15095A90.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_C1D70/func_15095B08.s")

void func_15095D34(s32, s32, s32, s32, s32);

void func_15095D0C(s32 arg0, s32 arg1) {
    func_15095D34(arg0, arg1, 0, 0, 0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_C1D70/func_15095D34.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_C1D70/func_1509629C.s")

extern Gfx D_80087408[];

Gfx *func_15096934(Gfx *arg0) {
    gSPDisplayList(arg0++, D_80087408);
    D_800D2DAB = 0;
    return arg0;
}
