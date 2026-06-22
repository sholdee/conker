#include <ultra64.h>
#include "functions.h"
#include "variables.h"


extern void func_15147D64(s32, s32);

void func_150B3DD0(void) {
    u8 sp24[4];

    func_15147D64(0, 5);
    sp24[0] = 0;
    func_151494E0((s32)&sp24[0], 0x18);
    sp24[0] = 2;
    func_151494E0((s32)&sp24[0], 0x18);
    sp24[0] = 4;
    func_151494E0((s32)&sp24[0], 0x18);
    sp24[0] = 1;
    func_151494E0((s32)&sp24[0], 0x18);
    sp24[0] = 3;
    func_151494E0((s32)&sp24[0], 0x18);
    sp24[0] = 5;
    func_151494E0((s32)&sp24[0], 0x18);
}

extern void func_1000FC18(s32, s16, s16, s16, s32);
extern void func_151478F4(void *);

void func_150B3E74(void *arg0) {
    func_1000FC18(0x221, (s16)(s32)*(f32 *)((u8 *)arg0 + 0x10),
                  (s16)(s32)*(f32 *)((u8 *)arg0 + 0x14),
                  (s16)(s32)*(f32 *)((u8 *)arg0 + 0x18), 0xFA0);
    func_151478F4(arg0);
}

extern void func_15147928(void *);

void func_150B3EE8(void *arg0) {
    func_1000FC18(0x221, (s16)(s32)*(f32 *)((u8 *)arg0 + 0x10),
                  (s16)(s32)*(f32 *)((u8 *)arg0 + 0x14),
                  (s16)(s32)*(f32 *)((u8 *)arg0 + 0x18), 0xFA0);
    func_15147928(arg0);
}

extern s32 func_15147A80(void *, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);

s32 func_150B3F5C(void *arg0, void *arg1, s16 arg2) {
    s32 pad_dummy;
    struct vec150B3F5C {
        s32 unk0;
        s32 unk4;
        s32 unk8;
    };
    struct {
        struct vec150B3F5C unk0;
        s16 unkC;
        s16 unkE;
        s32 unk10;
        u8 unk14;
        u8 unk15;
    } sp9C;
    struct {
        u8 pad0[0x40];
        f32 unk40;
        f32 unk44;
        u8 unk48;
        u8 pad49[3];
        f32 unk4C;
        u8 unk50;
        u8 pad51[3];
        f32 unk54;
    } sp44;
    s32 temp_v0;
    s32 rnd;

    memcpy(&sp44, arg0, 0x40);
    sp44.unk44 = 0.0f;
    sp9C.unk15 = arg2;
    sp44.unk48 = 0;
    sp9C.unkE = 2;
    sp9C.unkC = 0x1F4;
    sp44.unk4C = *(f32 *)((u8 *)arg0 + 0x18) + *(f32 *)((u8 *)arg0 + 0x14);
    sp44.unk50 = 0;
    sp44.unk54 = 0.0f;
    sp44.unk40 = sp44.unk4C;
    sp9C.unk0 = *(struct vec150B3F5C *)arg1;
    sp9C.unk10 = 9;

    temp_v0 = func_15147A80(&sp9C, 0x58, 0x24, 7, 7, 7, 0, 0, 0, 0xFF, 1);
    if (temp_v0 != 0) {
        rnd = func_150ADA20();
        func_1000FA64(0x221, (s16)(s32)*(f32 *)((u8 *)arg1 + 0),
                      (s16)(s32)*(f32 *)((u8 *)arg1 + 4),
                      (s16)(s32)*(f32 *)((u8 *)arg1 + 8), 0x61A8, 0xFA0,
                      0x258, (s32)func_1000EF40, 0, 0, 8, rnd & 0x40);
        memcpy((void *)*(s32 *)((u8 *)temp_v0 + 0x98), &sp44, 0x58);
    }
    return temp_v0;
}

s32 func_150B40E8(void *arg0, s32 var_a1) {
    typedef struct {
        f32 unk0;
        f32 unk4;
        f32 unk8;
    } Vec3f;
    void *temp_v0;
    void *temp_v1;
    s32 var_a2;
    s32 var_a3;
    s32 var_t0;
    void *temp_a3;

    var_a1 = *(s8 *)((u8 *)arg0 + 0x2C);
    temp_v0 = *(void **)((u8 *)arg0 + 0x98);
    temp_v1 = *(void **)((u8 *)arg0 + 0x94);

    if ((var_a1 < 2) && ((*(u8 *)((u8 *)temp_v0 + 0x1C) & 1) != 0)) {
        return 0;
    }

    var_a2 = *(s8 *)((u8 *)arg0 + 0x2E);
    var_a3 = *(s8 *)((u8 *)arg0 + 0x2D);

    if (var_a2 != var_a3) {
        var_t0 = 0x24;

        do {
            var_a2--;
            var_a1 = 0;
            if (var_a2 < 0) {
                var_a2 = *(u8 *)((u8 *)arg0 + 0x25) - 1;
            }

            temp_a3 = (u8 *)temp_v1 + (var_a2 * var_t0);
            *(s16 *)((u8 *)temp_a3 + 0x1C) = 0xFF;
            *(s16 *)((u8 *)temp_a3 + 0x1E) = *(s16 *)((u8 *)temp_a3 + 0x1E) - D_800BE9E4;
            if (*(s16 *)((u8 *)temp_a3 + 0x1E) < 0) {
                var_a1 = 1;
            }

            *(f32 *)((u8 *)temp_a3 + 0x10) += *(f32 *)((u8 *)temp_v0 + 0xC) * (&D_800BE9A4)[0];
            *(f32 *)((u8 *)temp_a3 + 0x0) += *(f32 *)((u8 *)temp_a3 + 0xC) * (&D_800BE9A4)[0];
            *(f32 *)((u8 *)temp_a3 + 0x4) += *(f32 *)((u8 *)temp_a3 + 0x10) * (&D_800BE9A4)[0];
            *(f32 *)((u8 *)temp_a3 + 0x8) += *(f32 *)((u8 *)temp_a3 + 0x14) * (&D_800BE9A4)[0];
            *(f32 *)((u8 *)temp_a3 + 0x18) += *(f32 *)((u8 *)temp_v0 + 0x28) * (&D_800BE9A4)[0];

            if (var_a1 != 0) {
                var_a3 = *(s8 *)((u8 *)arg0 + 0x2D);
                if (var_a2 != var_a3) {
                    do {
                        *(s8 *)((u8 *)arg0 + 0x2D) = var_a3 + 1;
                        var_a3 = *(s8 *)((u8 *)arg0 + 0x2D);
                        if (*(u8 *)((u8 *)arg0 + 0x25) != *(s8 *)((u8 *)arg0 + 0x2D)) {
                        } else {
                            *(s8 *)((u8 *)arg0 + 0x2D) = 0;
                            var_a3 = *(s8 *)((u8 *)arg0 + 0x2D);
                        }
                        *(s8 *)((u8 *)arg0 + 0x2C) = *(s8 *)((u8 *)arg0 + 0x2C) - 1;
                    } while (var_a2 != var_a3);
                }
            }

            var_a3 = *(s8 *)((u8 *)arg0 + 0x2D);
        } while (var_a2 != var_a3);

        var_a1 = *(s8 *)((u8 *)arg0 + 0x2C);
    }

    if (var_a1 > 0) {
        var_t0 = 0x24;
        temp_a3 = (u8 *)temp_v1 + (var_a3 * var_t0);
        *(Vec3f *)((u8 *)arg0 + 0x54) = *(Vec3f *)temp_a3;
    } else {
        *(f32 *)((u8 *)arg0 + 0x54) = 0.0f;
        *(f32 *)((u8 *)arg0 + 0x58) = 0.0f;
        *(f32 *)((u8 *)arg0 + 0x5C) = 0.0f;
    }

    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_E1280/func_150B4294.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_E1280/func_150B4710.s")

void func_150B5060(void *arg0) {
    void *temp_v0 = *(void **)((u8 *)arg0 + 0x98);

    *(u8 *)((u8 *)arg0 + 0x30) = 0;
    *(u16 *)((u8 *)arg0 + 0x1E) = *(u16 *)((u8 *)arg0 + 0x1E) & 0xFFFD;
    *(u8 *)((u8 *)temp_v0 + 0x1C) = *(u8 *)((u8 *)temp_v0 + 0x1C) | 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_E1280/func_150B5088.s")

void func_150B538C(void *arg0, s32 arg1, u8 arg2) {
    if (arg2 == 5) {
        func_150B5060(arg0);
    }
}
