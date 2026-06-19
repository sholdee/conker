#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern f32 D_800A5760;

#pragma GLOBAL_ASM("asm/nonmatchings/game_174BF0/func_15147740.s")

extern void func_151D5E30(void *);

void func_151478D0(void *arg0) {
    func_151D5E30((void *)((u8 *)arg0 + 0x84));
}

extern void func_1514795C(void *);

void func_151478F4(void *arg0) {
    func_151478D0(arg0);
    func_1514795C(arg0);
    func_15169804((struct102 *)arg0);
}

void func_15147928(void *arg0) {
    func_151478D0(arg0);
    func_1514795C(arg0);
    func_15169824((struct102 *)arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_174BF0/func_1514795C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_174BF0/func_151479E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_174BF0/func_15147A30.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_174BF0/func_15147A80.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_174BF0/func_15147C4C.s")

extern void (*D_8008A390[])(void *, s32, u8);

void func_15147D1C(void *arg0, s32 arg1, u8 arg2) {
    void (*fn)(void *, s32, u8) = D_8008A390[*(s32 *)((u8 *)arg0 + 0x20)];
    if (fn != NULL) {
        fn(arg0, arg1, arg2);
    }
}

void func_15147D64(s32 arg0, u8 arg1) {
    func_15169260(&D_800A5760, 2, arg0, arg1);
}
