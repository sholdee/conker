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

extern void (*D_8008A2F0[])(void *);

void func_151479E0(void *arg0) {
    s32 idx = *(s32 *)((u8 *)arg0 + 0x20);
    if (idx < 0) {
        idx = 0;
    } else if (idx >= 0x14) {
        idx = 0;
    }
    D_8008A2F0[idx](arg0);
}

extern void (*D_8008A340[])(void *);

void func_15147A30(void *arg0) {
    s32 idx = *(s32 *)((u8 *)arg0 + 0x20);
    if (idx < 0) {
        idx = 0;
    } else if (idx >= 0x14) {
        idx = 0;
    }
    D_8008A340[idx](arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_174BF0/func_15147A80.s")

extern void *func_151462C8(void *, void *, u8, void *, s32, s16, void *, s32, void *);
extern void *(*D_8008A2A4[])(void *, void *, s16);

void *func_15147C4C(void *arg0, void *arg1, s16 arg2) {
    s32 v0;
    u8 v1;

    if (*(u16 *)((u8 *)arg1 + 0x1E) & 0x20) {
        v0 = *(s32 *)((u8 *)arg1 + 0x28);
    } else {
        v0 = 0;
    }
    arg0 = func_151462C8(arg0, (u8 *)arg1 + 0x34, 0, 0, 0, arg2, (u8 *)arg1 + 0x54, 2, (void *)v0);
    v1 = *(u8 *)((u8 *)arg1 + 0x31);
    if (v1 >= 0x13) {
        func_1516972C((struct102 *)arg1);
        return arg0;
    }
    if (v1 != 0) {
        return D_8008A2A4[v1](arg1, arg0, arg2);
    }
    return arg0;
}

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
