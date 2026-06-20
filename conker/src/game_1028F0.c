#include <ultra64.h>
#include "functions.h"
#include "variables.h"


void func_150D5440(void *arg0, u8 arg1, s32 arg2) {
    struct {
        void *unk0;
        u8 unk4;
        u8 pad5;
        u8 pad6;
        u8 pad7;
        f32 unk8;
    } sp34;
    struct260 *temp_v0;

    sp34.unk0 = arg0;
    sp34.unk4 = *(u8 *)((s32)arg0 + 0x3B);
    sp34.unk8 = 0.0f;

    temp_v0 = func_15149130(0x12C, -1, 0x38, -1, 0, 0x28, (struct37 *)0xC, arg1, arg2);
    if (temp_v0 != NULL) {
        memcpy((void *)((s32)temp_v0 + 0x28), &sp34, 0xC);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1028F0/func_150D54C8.s")

typedef struct {
    s32 unk0;
    u8  unk4;
} SubA150D596C;

typedef struct {
    s32 unk0;
    union {
        s32 w4;
        u8  b4;
    } u4;
    u8  unk8;
    u8  unk9;
} ArgB150D596C;

void func_150D596C(struct260 *arg0, s32 arg1, u8 arg2) {
    SubA150D596C *temp_v0 = (SubA150D596C *)((u8 *)arg0 + 0x28);
    ArgB150D596C *b = (ArgB150D596C *)arg1;
    s32 b0;

    if (arg2 == 0 || arg2 == 0x2F || arg2 == 0x3) {
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

void func_150D5A2C(struct260 *arg0) {
    func_1514933C(arg0);
}

void func_150D5A4C(struct260 *arg0) {
    func_15149368(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1028F0/func_150D5A6C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1028F0/func_150D6388.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1028F0/func_150D6434.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1028F0/func_150D64E8.s")

void func_151A5D58(f32, s32, s32, s32, s32, s32, s32, s32, s32);

void func_150D65F0(s32 arg0, s32 arg1, u8 arg2, s32 arg3) {
    union { u32 w; f64 _a; } temp_a;
    f32 temp_f0;
    u32 temp_b;

    temp_f0 = func_150ADA68();
    temp_a.w = func_150ADA20();
    temp_b = func_150ADA20();
    func_151A5D58(temp_f0 * 100.0f + 150.0f, ((temp_a.w % 71) + 0x82) & 0xFF, arg0, arg1,
                  (temp_b % 31) + 0x32, 0, 1, arg2, arg3);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1028F0/func_150D66A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1028F0/func_150D6730.s")

void func_150D6C98(f32 *arg0, f32 *arg1) {
    arg1[0] = arg0[5];
    arg1[1] = arg0[6] + 60.0f;
    arg1[2] = arg0[7];
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1028F0/func_150D6CC4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1028F0/func_150D6E60.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1028F0/func_150D6F0C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1028F0/func_150D7068.s")
