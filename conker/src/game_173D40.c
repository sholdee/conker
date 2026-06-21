#include <ultra64.h>
#include "functions.h"
#include "variables.h"


typedef struct {
    f32 unk0;
    f32 unk4;
    s32 unk8;
} Struct15147040;

extern s32 func_15142314(s32, s32, Struct15147040 *);
extern void func_1504715C(s32, s32);
extern s32 func_15046C80(f32 *, s32, f32, s32);
extern void func_15141F78(u8, struct157 *, f32, u8, struct157 *, u8);
extern f32 D_800A5728;
extern f32 D_800A572C;

s32 func_15146890(Struct15147040 *arg0, s32 arg1, s32 arg2, u8 arg3) {
    f32 sp2C[3];
    s32 temp_a1;

    if ((arg3 != 1) && (arg3 != 2)) {
        return 0;
    }

    if (arg3 == 1) {
        temp_a1 = 0x13;
    } else {
        temp_a1 = 0x17;
    }

    func_15142314(*(s32 *)(arg1 + 0x1D4), temp_a1, arg0);
    if (arg2 == 0) {
        return 1;
    }

    sp2C[0] = arg0->unk0;
    sp2C[1] = arg0->unk4 + 10.0f;
    sp2C[2] = *(f32 *)&arg0->unk8;
    func_1504715C(arg2, arg1);
    return func_15046C80(sp2C, 0, arg0->unk4 - 50.0f, arg2);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_173D40/func_15146970.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_173D40/func_15146A98.s")

void func_15146BF8(s32, s32, s32, s32);

void func_15146BB8(s32 arg0, s32 arg1, s32 arg2) {
    func_15146BF8(arg0, arg1, arg2, 0);
}

void func_15146BD8(s32 arg0, s32 arg1, s32 arg2) {
    func_15146BF8(arg0, arg1, arg2, 1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_173D40/func_15146BF8.s")

void func_15146D60(s32 arg0, s32 arg1, s32 arg2) {
    Struct15147040 sp4C;
    s32 sp2C[8];
    s32 temp_a3;

    temp_a3 = (u8)arg1;
    if (*(s32 *)(arg0 + 0x1D4) != 0) {
        if (func_15146890(&sp4C, arg0, (s32)&sp2C[-1], temp_a3) != 0) {
            func_15141F78(0xA, (struct157 *)&sp2C[-1], (f32)arg2 * D_800A5728,
                          (u8)(u32)(*(f32 *)(arg0 + 0x40) * D_800A572C),
                          (struct157 *)&sp4C, temp_a3);
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_173D40/func_15146E84.s")

extern s32 func_15146890(Struct15147040 *, s32, s32, u8);
extern void func_1514C678(f32, f32, s32, f32, s32, s32, s32, s32, s32, f32, s32, s32);

void func_15147040(s32 arg0, s32 arg1, s32 arg2) {
    Struct15147040 sp44;
    s16 temp;

    if (*(s32 *)(arg0 + 0x1D4) != 0) {
        func_15146890(&sp44, arg0, 0, (u8)arg1);
        temp = (func_150ADA20() % 11U) + 5;
        func_1514C678(sp44.unk0, sp44.unk4, sp44.unk8,
                      func_150ADA68() * 11.0f,
                      0, 0xFF, temp, 0x16, 0, 0.0f, 0, 0xFF);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_173D40/func_151470FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_173D40/func_15147318.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_173D40/func_15147478.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_173D40/func_151475D8.s")
