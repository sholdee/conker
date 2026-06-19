#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void func_151B1918(struct260 *arg0);
void func_15149368(struct260 *arg0);


#pragma GLOBAL_ASM("asm/nonmatchings/game_1DD500/func_151B0050.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1DD500/func_151B01B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1DD500/func_151B03B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1DD500/func_151B09BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1DD500/func_151B0B88.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1DD500/func_151B118C.s")

s32 func_151B1478(struct260 *arg0) {
    s32 v1;
    if (*(s16 *)((u8 *)arg0 + 0x1C) < 0x20) {
        v1 = *(s16 *)((u8 *)arg0 + 0x1C) << 3;
        if (v1 < *(u8 *)((u8 *)arg0 + 0x5C)) {
            *(u8 *)((u8 *)arg0 + 0x5C) = v1;
        }
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1DD500/func_151B14AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1DD500/func_151B1828.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1DD500/func_151B1918.s")

typedef struct {
    s32 unk0;
    u8  unk4;
} SubA151B19A4;

typedef struct {
    s32 unk0;
    union {
        s32 w4;
        u8  b4;
    } u4;
    u8  unk8;
    u8  unk9;
} ArgB151B19A4;

void func_151B19A4(struct260 *arg0, s32 arg1, u8 arg2) {
    SubA151B19A4 *temp_v0 = (SubA151B19A4 *)((u8 *)arg0 + 0x28);
    ArgB151B19A4 *b = (ArgB151B19A4 *)arg1;
    s32 v1 = temp_v0->unk0;

    if (arg2 == 0 || arg2 == 0x13) {
        if ((v1 == b->unk0) || (b->u4.b4 == temp_v0->unk4)) {
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

void func_151B1A58(struct260 *arg0) {
    func_151B1918(arg0);
    func_1514933C(arg0);
}

void func_151B1A84(struct260 *arg0) {
    func_151B1918(arg0);
    func_15149368(arg0);
}

void func_151B1AB0(void *arg0) {
    struct260 *temp_v0;
    struct {
        void *unk0;
        u8 unk4;
        f32 unk8;
    } sp28;

    if (*(s32 *)&arg0 != 0) {
        sp28.unk0 = arg0;
        sp28.unk4 = *(u8 *)((s32)arg0 + 0x3B);
        sp28.unk8 = 0.0f;

        temp_v0 = func_151491F4(0x3C, -1, 0x15, 1, 0x11, 0xC, 0xFF, 1);
        if (temp_v0 != NULL) {
            memcpy((void *)((s32)temp_v0 + 0x28), &sp28, 0xC);
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1DD500/func_151B1B34.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1DD500/func_151B1FAC.s")
