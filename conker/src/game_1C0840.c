#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern f32 D_800A81B0;
void func_1516865C(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
s32 func_15168800(s32 arg0, s32 arg1, s32 arg2);

struct Struct15193390 {
    u8 pad[0xB0];
};

void func_15193390(volatile s32 arg0) {
    struct Struct15193390 sp28;
    u8 *temp_v0;
    s16 temp_v1;

    bzero(&sp28, 0xA8);
    temp_v0 = (u8 *)arg0;
    temp_v1 = *(s16 *)(temp_v0 + 0x2E);
    temp_v0 += 0x28;

    if (D_800A81B0 != (f32)temp_v1) {
        *(s16 *)(sp28.pad + 0x96) = temp_v1;
    } else {
        *(s16 *)(sp28.pad + 0x96) = (s32)((f32)*(s16 *)(temp_v0 + 2) - 200.0f);
        *(u8 *)(temp_v0 + 8) = 0;
    }

    *(s16 *)(sp28.pad + 0x8C) = *(s16 *)(temp_v0 + 0);
    *(s16 *)(sp28.pad + 0x8E) = *(s16 *)(temp_v0 + 2);
    *(s16 *)(sp28.pad + 0x90) = *(s16 *)(temp_v0 + 4);
    *(s16 *)(sp28.pad + 0x92) = 0;
    *(s16 *)(sp28.pad + 0x94) = 0;
    *(u8 *)(sp28.pad + 0xA2) = 0xF;
    *(u8 *)(sp28.pad + 0xA0) = 0x45;
    *(s16 *)(sp28.pad + 0x86) = 0xA;
    *(u8 *)(sp28.pad + 0xA3) = *(u8 *)(temp_v0 + 8);
    *(s16 *)(sp28.pad + 0x98) = 0x4880;
    *(u8 *)(sp28.pad + 0xA4) = 0x80;

    func_1516865C(&sp28, 0xFF, 0xFF, 0xFF, 0x80);
    temp_v0 = (u8 *)arg0;
    func_15168800((s32)&sp28, *(u8 *)(temp_v0 + 0xC), *(u8 *)(temp_v0 + 1));
    *(s16 *)((u8 *)arg0 + 0xE) = (func_150ADA20() & 0x7F) + 0x64;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C0840/func_151934B4.s")
