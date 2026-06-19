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

#pragma GLOBAL_ASM("asm/nonmatchings/game_1FFB70/func_151D275C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1FFB70/func_151D2830.s")
