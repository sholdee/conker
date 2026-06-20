#include <ultra64.h>
#include "functions.h"
#include "variables.h"


extern void func_15147D64(s32, s32);

void func_150B3DD0(void) {
    u8 sp24[4];

    func_15147D64(0, 5);
    sp24[0] = 0;
    func_151494E0((s32)&sp24[0], 0x18);
    sp24[0] = 2;
    func_151494E0((s32)&sp24[0], 0x18);
    sp24[0] = 4;
    func_151494E0((s32)&sp24[0], 0x18);
    sp24[0] = 1;
    func_151494E0((s32)&sp24[0], 0x18);
    sp24[0] = 3;
    func_151494E0((s32)&sp24[0], 0x18);
    sp24[0] = 5;
    func_151494E0((s32)&sp24[0], 0x18);
}

extern void func_1000FC18(s32, s16, s16, s16, s32);
extern void func_151478F4(void *);

void func_150B3E74(void *arg0) {
    func_1000FC18(0x221, (s16)(s32)*(f32 *)((u8 *)arg0 + 0x10),
                  (s16)(s32)*(f32 *)((u8 *)arg0 + 0x14),
                  (s16)(s32)*(f32 *)((u8 *)arg0 + 0x18), 0xFA0);
    func_151478F4(arg0);
}

extern void func_15147928(void *);

void func_150B3EE8(void *arg0) {
    func_1000FC18(0x221, (s16)(s32)*(f32 *)((u8 *)arg0 + 0x10),
                  (s16)(s32)*(f32 *)((u8 *)arg0 + 0x14),
                  (s16)(s32)*(f32 *)((u8 *)arg0 + 0x18), 0xFA0);
    func_15147928(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_E1280/func_150B3F5C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_E1280/func_150B40E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_E1280/func_150B4294.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_E1280/func_150B4710.s")

void func_150B5060(void *arg0) {
    void *temp_v0 = *(void **)((u8 *)arg0 + 0x98);

    *(u8 *)((u8 *)arg0 + 0x30) = 0;
    *(u16 *)((u8 *)arg0 + 0x1E) = *(u16 *)((u8 *)arg0 + 0x1E) & 0xFFFD;
    *(u8 *)((u8 *)temp_v0 + 0x1C) = *(u8 *)((u8 *)temp_v0 + 0x1C) | 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_E1280/func_150B5088.s")

void func_150B538C(void *arg0, s32 arg1, u8 arg2) {
    if (arg2 == 5) {
        func_150B5060(arg0);
    }
}
