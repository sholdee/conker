#include <ultra64.h>
#include "functions.h"
#include "variables.h"


typedef struct {
    char pad_0[0x6A];
    u8 field_0x6A;
} GameObjectStateBytes;

typedef struct {
    char pad_0[0x58];
    s32 field_0x58;
    char pad_0x5C[0x12C];
    GameObjectStateBytes *field_0x188;
} GameObjectWithStateBytes;

#pragma GLOBAL_ASM("asm/nonmatchings/game_1B74A0/func_15189FF0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1B74A0/func_1518A094.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1B74A0/func_1518A214.s")

s32 func_1518A2E8(GameObjectWithStateBytes *arg0, u8 *arg1) {
    if (arg0->field_0x188->field_0x6A != 0) {
        arg0->field_0x58 &= ~2;
        *arg1 = 0;
    } else {
        *arg1 = 1;
    }
    return 1;
}

s32 func_1518A324(s32 arg0, u8 *arg1) {
    if (*(u8 *)(*(s32 *)(arg0 + 0x188) + 0x6F) == 0) {
        *(s32 *)(arg0 + 0x58) &= ~2;
        *arg1 = 0;
    } else {
        *arg1 = 1;
    }
    return 1;
}

typedef struct {
    s32 unk0;
    s32 unk4;
    u8 unk8;
    u8 unk9;
} GameStruct1518A360a;

typedef struct {
    u8 unk0[0x18];
    s32 unk18;
    u8 unk1C;
    u8 unk1D;
} GameStruct1518A360b;

void func_1518A360(void *arg0, GameStruct1518A360a *arg1, u8 arg2) {
    GameStruct1518A360b *v0 = (GameStruct1518A360b *)((u8 *)arg0 + 0x170);
    if (arg2 == 0x2D) {
        if (v0->unk18 == arg1->unk0) {
            v0->unk18 = arg1->unk4;
            v0->unk1D = arg1->unk9;
        } else if (v0->unk18 == arg1->unk4) {
            v0->unk18 = arg1->unk0;
            v0->unk1D = arg1->unk8;
        }
    }
}
