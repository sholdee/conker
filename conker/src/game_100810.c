#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_100810/func_150D3360.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_100810/func_150D3A68.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_100810/func_150D3FD4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_100810/func_150D4300.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_100810/func_150D49C0.s")

extern s32 func_1514654C(struct127 *, struct126 *, s32, void *, void *, s32);
extern f32 D_800A09D0;
extern f32 D_800A09DC;

s32 func_150D4AE0(struct17 *arg0, struct17 *arg1, struct127 *arg2, struct126 *arg3) {
    void *sp30[2];
    void *sp28[2];

    if (arg2->unk1D4 != 0) {
        sp30[0] = &D_800A09D0;
        sp30[1] = &D_800A09DC;
        sp28[0] = arg0;
        sp28[1] = (void *)arg1;
        if (func_1514654C(arg2, arg3, 0, sp30, sp28, 2) != 0) {
            return 1;
        }
        return 0;
    }

    arg0->unk0 = arg2->x_position;
    arg0->unk4 = arg2->y_position + 100.0f;
    arg0->unk8 = arg2->z_position;
    arg1->unk0 = arg2->x_position;
    arg1->unk4 = arg2->y_position + 100.0f + 500.0f;
    arg1->unk8 = arg2->z_position;
    return 2;
}

extern void func_150D4C2C(void *);
extern void func_151478F4(void *);
extern void func_15147928(void *);

void func_150D4BD4(void *arg0) {
    func_150D4C2C(arg0);
    func_151478F4(arg0);
}

void func_150D4C00(void *arg0) {
    func_150D4C2C(arg0);
    func_15147928(arg0);
}

extern void func_1000FD38(void *, void *, s32);
extern void func_150D5124(void);
extern s8 D_8008FD8C;

void func_150D4C2C(void *arg0) {
    struct102 **s0;

    s0 = *(struct102 ***)((u8 *)arg0 + 0x98);
    if (D_8008FD8C < 5) {
        func_1000FD38(func_150D5124, s0, 0x5B3);
    }
    func_1000FD38(func_150D5124, s0, 0x5B4);
    func_1000FD38(func_150D5124, s0, 0x5BC);
    if (s0[3] != 0) {
        func_1516972C(s0[3]);
    }
    if (s0[4] != 0) {
        func_1516972C(s0[4]);
    }
}

struct Bar150D4CC4 {
    char pad48[0x48];
    f32 unk48;
};

struct Obj150D4CC4 {
    char pad18[0x18];
    u8 unk18;
    char pad19[0x170 - 0x19];
    s16 unk170;
    char pad172[0x2];
    f32 unk174;
};

extern s32 D_800A09C0[];
extern f32 D_800A0A14;

s32 func_150D4CC4(struct Obj150D4CC4 *arg0) {
    struct Bar150D4CC4 *v1 = (struct Bar150D4CC4 *)((char *)arg0 + 0x110);

    arg0->unk170 -= D_800BE9E4;
    if (arg0->unk170 < 0) {
        arg0->unk18 = D_800A09C0[func_150ADA20() & 3];
        arg0->unk170 = (func_150ADA20() & 7) + 3;
    }

    v1->unk48 = v1->unk48 + (arg0->unk174 - v1->unk48) * D_800A0A14;
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_100810/func_150D4D58.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_100810/func_150D5124.s")
