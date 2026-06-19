#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_1E2180/func_151B4CD0.s")

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Vec3f_local_4E4C;

void func_151B4EA4(Vec3f_local_4E4C *, f32, f32, f32, s32, s32);

void func_151B4E4C(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, void *arg6) {
    Vec3f_local_4E4C sp24;

    sp24.x = arg0;
    sp24.y = arg1;
    sp24.z = arg2;
    func_151B4EA4(&sp24, arg3, arg4, arg5, *(u8 *)((s32)arg6 + 0x58), *(u8 *)((s32)arg6 + 0xC));
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E2180/func_151B4EA4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E2180/func_151B4FE0.s")

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Vec3f_local;

void func_151B50F4(Vec3f_local *, f32, f32, f32, s32);

void func_151B50A4(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, void *arg6) {
    Vec3f_local sp24;

    sp24.x = arg0;
    sp24.y = arg1;
    sp24.z = arg2;
    func_151B50F4(&sp24, arg3, arg4, arg5, *(u8 *)((s32)arg6 + 0xC));
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E2180/func_151B50F4.s")
