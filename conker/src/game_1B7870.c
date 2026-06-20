#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_1B7870/func_1518A3C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1B7870/func_1518A5F4.s")

struct Sub1518A914 {
    /* 0x00 */ f32 unk0;
    /* 0x04 */ f32 unk4;
    /* 0x08 */ f32 unk8;
    /* 0x0C */ f32 unkC;
};

struct Foo1518A914 {
    char pad0[0x48];
    /* 0x48 */ f32 unk48;
    /* 0x4C */ f32 unk4C;
    /* 0x50 */ f32 unk50;
    char pad54[0x100 - 0x54];
    /* 0x100 */ struct Sub1518A914 unk100;
};

s32 func_1518A914(Mtx *arg0, struct Foo1518A914 *arg1) {
    struct Sub1518A914 *p = &arg1->unk100;
    f32 sp24[4][4];

    func_150A8050(sp24, p->unk0, p->unk4, p->unk8);
    sp24[3][0] = arg1->unk48;
    sp24[3][1] = arg1->unk4C;
    sp24[3][2] = arg1->unk50;
    sp24[0][0] *= p->unkC;
    sp24[0][1] *= p->unkC;
    sp24[0][2] *= p->unkC;
    sp24[1][0] *= p->unkC;
    sp24[1][1] *= p->unkC;
    sp24[1][2] *= p->unkC;
    sp24[2][0] *= p->unkC;
    sp24[2][1] *= p->unkC;
    sp24[2][2] *= p->unkC;
    guMtxF2L(sp24, arg0);
    return 1;
}
