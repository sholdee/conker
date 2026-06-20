#include <ultra64.h>
#include "functions.h"
#include "variables.h"


extern void func_150D6730(s32 arg0, s32 arg1, s32 arg2);

void func_151D6970(s32 arg0, s32 arg1) {
    if ((D_800BE9F0 == 0x32) || (D_800BE9F0 == 0x33)) {
        func_150D6730(arg0, 0xFF, 1);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_203E20/func_151D69B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_203E20/func_151D6BFC.s")

extern f32 func_15144AA8(s32);
extern f32 D_800AB278;

struct Foo203E20 {
    u8 pad0[0x4C];
    s32 *unk4C;
    u8 pad50[0x7C - 0x50];
    f32 mat[1][4][4];
};

s32 func_151D6E60(struct Foo203E20 *arg0) {
    f32 m;

    func_150A8050(arg0->mat[D_800BE9C0], 0.0f, func_15144AA8(0) + 25.0f, 0.0f);

    m = D_800AB278;
    arg0->mat[D_800BE9C0][3][0] = ((f32 *)arg0->unk4C)[5];
    arg0->mat[D_800BE9C0][3][1] = ((f32 *)arg0->unk4C)[6] + 120.0f;
    arg0->mat[D_800BE9C0][3][2] = ((f32 *)arg0->unk4C)[7];

    arg0->mat[D_800BE9C0][0][0] *= m;
    arg0->mat[D_800BE9C0][0][1] *= m;
    arg0->mat[D_800BE9C0][0][2] *= m;
    arg0->mat[D_800BE9C0][1][0] *= m;
    arg0->mat[D_800BE9C0][1][1] *= m;
    arg0->mat[D_800BE9C0][1][2] *= m;
    arg0->mat[D_800BE9C0][2][0] *= m;
    arg0->mat[D_800BE9C0][2][1] *= m;
    arg0->mat[D_800BE9C0][2][2] *= m;

    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_203E20/func_151D7000.s")

void func_151D70CC(s32 *arg0, s32 arg1, u8 arg2) {
    func_15169850(arg1, arg2, arg0[0x12], arg0[0x12] + 4, (s32)arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_203E20/func_151D710C.s")
