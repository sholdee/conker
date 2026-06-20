#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_DC6B0/func_150AF200.s")

extern void func_151CF898(void *, f32, f32);

void func_150AF2E0(void *arg0, s16 *arg1) {
    func_151CF898(arg0, (f32)(arg1[4] + arg1[1]), (f32)arg1[1]);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_DC6B0/func_150AF328.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_DC6B0/func_150AF6E4.s")

extern void func_1515FF74(void *, s32, u8, s32);

struct sp18 {
    s8 unk0;
    s8 unk1;
    s8 unk2;
    s8 pad3;
    s16 unk4;
    s8 unk6;
};

void func_150AF738(s16 arg0, u8 arg1, s32 arg2) {
    struct sp18 sp18;

    sp18.unk0 = 1;
    sp18.unk1 = -1;
    sp18.unk2 = 2;
    sp18.unk4 = arg0;
    sp18.unk6 = 0;
    func_1515FF74(&sp18, 0, arg1, arg2);
}

extern void func_150B1DB0(void *, void *);

void func_150AF790(void *arg0, u8 *arg1) {
    func_150B1DB0(arg1, arg1 + 0x1ECC0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_DC6B0/func_150AF7C4.s")

extern f32 sinf(f32);

struct Sub150AFBF4 {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
};

struct Obj150AFBF4 {
    char pad0[0x10];
    f32 unk10;
    char pad14[0x5C];
    struct Sub150AFBF4 unk70;
};

s32 func_150AFBF4(struct Obj150AFBF4 *arg0) {
    struct Sub150AFBF4 *p = &arg0->unk70;
    p->unk8 = p->unk8 + p->unkC * D_800BE9A4;
    p->unk8 = func_15144B68(p->unk8);
    arg0->unk10 = sinf(p->unk8) * p->unk4 + p->unk0;
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_DC6B0/func_150AFC68.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_DC6B0/func_150AFDB0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_DC6B0/func_150AFE64.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_DC6B0/func_150B003C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_DC6B0/func_150B0094.s")

void func_150B02C0(void *arg0) {
    if (*(s32 *)((u8 *)arg0 + 0x170) != 0) {
        func_1516972C(*(struct102 **)((u8 *)arg0 + 0x170));
    }
}

extern void func_150B02C0(void *);
extern void func_15132570(void *);

void func_150B02F0(void *arg0) {
    func_150B02C0(arg0);
    func_15132570(arg0);
}

extern void func_1513259C(void *);

void func_150B031C(void *arg0) {
    func_150B02C0(arg0);
    func_1513259C(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_DC6B0/func_150B0348.s")

extern s32 func_151149AC(u32);

struct Obj150B060C {
    f32 unk0;
    f32 unk4;
    s16 *unk8;
    f32 unkC;
    f32 unk10;
    f32 unk14;
};

s32 func_150B060C(u8 arg0, struct Obj150B060C *arg1) {
    arg1->unk8 = (s16 *)func_151149AC(arg0);
    if (arg1->unk8 == 0) {
        return 0;
    }
    arg1->unk0 = -150.0f;
    arg1->unk4 = 4.5f;
    arg1->unkC = (f32)arg1->unk8[8];
    arg1->unk10 = (f32)arg1->unk8[9];
    arg1->unk14 = (f32)arg1->unk8[10];
    return 1;
}
