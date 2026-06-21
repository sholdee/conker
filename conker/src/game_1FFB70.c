#include <ultra64.h>
#include "functions.h"
#include "variables.h"


s32 func_15167A68(s32, s32, s32, s32, s32, s32);

struct Obj151D26C0 {
    u8  pad0[0xE];
    s16 unkE;
    s16 unk10;
    s16 unk12;
    s16 unk14;
    s8  unk16;
};

struct Obj151D26C0 *func_151D26C0(s16 arg0) {
    struct Obj151D26C0 *ret;

    ret = func_15167A68(0x3C, 1, 0x18, 0, 0xFF, 1);
    ret->unk14 = 0;
    ret->unk12 = 0;
    ret->unkE = 0;
    ret->unk16 = 1;
    ret->unk10 = arg0;
    return ret;
}

struct SomeNode {
    char pad0[0x8];
    struct SomeNode *unk8;
    char padC[0x4];
    s16 unk10;
    char pad12[0x4];
    s8 unk16;
};

extern struct SomeNode *D_800DD0E0;

void func_151D2718(s16 arg0) {
    struct SomeNode *node;

    for (node = D_800DD0E0; node != NULL; node = node->unk8) {
        if (arg0 == node->unk10) {
            node->unk16 = -2;
        }
    }
}

void func_151D275C(struct Obj151D26C0 *arg0) {
    s32 temp_v0;
    s32 temp_t5;

    temp_t5 = 0x80;
    arg0->unkE += (u32)D_800BE9E4 * (temp_v0 = arg0->unk16);

    if ((temp_v0 > 0) && (arg0->unkE >= 0xED)) {
        arg0->unk14 = (0x128 - arg0->unkE) << 2;
        if (arg0->unk14 < 0) {
            arg0->unk14 = 0;
        }
    } else {
        arg0->unk14 = (*(volatile s16 *)&arg0->unkE) * 2;
    }

    if (arg0->unk14 >= 0x80) {
        arg0->unk14 = temp_t5;
    }

    arg0->unk12++;
    if (arg0->unk12 >= 0x100) {
        arg0->unk12 -= 0x100;
    }

    if ((arg0->unkE >= 0x12D) || (arg0->unkE < 0)) {
        func_1516972C((struct102 *)arg0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1FFB70/func_151D2830.s")
