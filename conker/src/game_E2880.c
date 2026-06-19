#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_E2880/func_150B53D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_E2880/func_150B54A8.s")

extern void func_151D2B4C(s32);

void func_150B57C4(s32 arg0) {
    func_151D2B4C(6);
}

void func_150B57E8(struct260 *arg0) {
    func_150B57C4((s32)arg0);
    func_1514933C(arg0);
}

void func_150B5814(struct260 *arg0) {
    func_150B57C4((s32)arg0);
    func_15149368(arg0);
}

typedef struct {
    s32 unk0;
    u8  unk4;
} SubA;

typedef struct {
    s32 unk0;
    union {
        s32 w4;
        u8  b4;
    } u4;
    u8  unk8;
    u8  unk9;
} ArgB;

void func_150B5840(struct260 *arg0, s32 arg1, u8 arg2) {
    SubA *temp_v0 = (SubA *)((u8 *)arg0 + 0x28);
    ArgB *b = (ArgB *)arg1;
    s32 b0;

    if (arg2 == 0) {
        b0 = b->unk0;
        if ((b0 == temp_v0->unk0) || (b->u4.b4 == temp_v0->unk4)) {
            func_1516972C((struct102 *)arg0);
        }
    } else if (arg2 == 0x2D) {
        if (temp_v0->unk0 == b->unk0) {
            temp_v0->unk0 = b->u4.w4;
            temp_v0->unk4 = b->unk9;
        } else if (temp_v0->unk0 == b->u4.w4) {
            temp_v0->unk0 = b->unk0;
            temp_v0->unk4 = b->unk8;
        }
    }
}
