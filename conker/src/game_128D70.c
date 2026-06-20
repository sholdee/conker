#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_128D70/func_150FB8C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_128D70/func_150FC368.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_128D70/func_150FC438.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_128D70/func_150FC614.s")

typedef struct {
    s32 unk0;
    u8  unk4;
    u8  pad5[0x13];
    s32 unk18;
    u8  unk1C;
} SubA_150FC818;

typedef struct {
    s32 unk0;
    union { s32 w4; u8 b4; } u4;
    u8  unk8;
    u8  unk9;
} ArgB_150FC818;

void func_150FC818(void *arg0, s32 arg1, u8 arg2) {
    ArgB_150FC818 *b = (ArgB_150FC818 *)arg1;
    SubA_150FC818 *a = (SubA_150FC818 *)((u8 *)arg0 + 0x28);
    s32 bu0;
    s32 bu0b;
    s32 au0;

    if (arg2 == 0) {
        bu0 = b->unk0;
        au0 = a->unk0;
        if ((au0 == bu0) || (a->unk4 == b->u4.b4)) {
            func_1516972C((struct102 *)arg0);
        } else if (a->unk18 != 0) {
            if ((bu0 == a->unk18) || (a->unk1C == b->u4.b4)) {
                func_1516972C((struct102 *)arg0);
            }
        }
    } else if (arg2 == 0x2D) {
        bu0b = b->unk0;
        if (bu0b == a->unk0) {
            a->unk0 = b->u4.w4;
            a->unk4 = b->unk9;
        } else if (a->unk0 == b->u4.w4) {
            a->unk0 = bu0b;
            a->unk4 = b->unk8;
        } else if (a->unk18 != 0) {
            if (bu0b == a->unk18) {
                a->unk18 = b->u4.w4;
                a->unk1C = b->unk9;
            } else if (a->unk18 == b->u4.w4) {
                a->unk18 = bu0b;
                a->unk1C = b->unk8;
            }
        }
    }
}

s32 func_150FC930(struct260 *arg0, s32 arg1, s32 arg2) {
    u8 v = *((u8 *)arg0 + 4);
    if (v == 0x12 || v == 0x23 || v == 0x73 || v == 0x8A) {
        return 0;
    }
    return 1;
}

void func_150FC974(struct260 *arg0) {
    s32 *p = (s32 *)((u8 *)arg0 + 0x38);
    if (*p != 0) {
        func_1516972C((struct102 *)*p);
    }
}

extern void func_150FC974(struct260 *);

void func_150FC9A4(struct260 *arg0) {
    func_150FC974(arg0);
    func_1514933C(arg0);
}

extern void func_15149368(struct260 *);

void func_150FC9D0(struct260 *arg0) {
    func_150FC974(arg0);
    func_15149368(arg0);
}
