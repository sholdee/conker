#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_113480/func_150E5FD0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_113480/func_150E6230.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_113480/func_150E63A0.s")

s32 func_150E679C(void *arg0) {
    s32 v0 = *(s16 *)((u8 *)arg0 + 0x1C);
    s32 v1;
    if (v0 < 8) {
        v1 = v0 << 5;
        if (v1 < *(u8 *)((u8 *)arg0 + 0x5C)) {
            *(u8 *)((u8 *)arg0 + 0x5C) = v1;
        }
    }
    return 1;
}

struct LocalDef150E67D0 {
    s32 unk0;
    s16 unk4;
    s8  unk6;
    s8  unk7;
    s32 unk8;
    s32 unkC;
    u8  unk10;
    u8  unk11;
    u8  unk12;
    u8  unk13;
    u8  unk14;
    u8  unk15;
    s8  unk16;
    s8  unk17;
    s32 unk18;
    s32 unk1C;
    s32 unk20;
    s32 unk24;
    s32 unk28;
    s32 unk2C;
};

s32 func_150E67D0(void *arg0) {
    struct LocalDef150E67D0 tmp;
    u8 *temp;

    tmp.unk6 = 0x3A;
    tmp.unk0 = 1;
    tmp.unk4 = 0x64;
    tmp.unk8 = 0;
    tmp.unkC = 0;
    tmp.unk10 = 0xFF;
    tmp.unk11 = 0xFF;
    tmp.unk12 = 0;
    tmp.unk13 = 0;
    tmp.unk14 = 0;
    tmp.unk15 = 0xFF;
    tmp.unk18 = 0x130001;

    temp = (u8 *)arg0 + 0x110;
    func_1513C73C((s32)&tmp, 0, 0, (s32)(temp + 0x14), *(f32 *)(temp + 4), *(f32 *)(temp + 8), *(f32 *)(temp + 0xC), 50.0f, 50.0f, func_150ADA20() & 0xFF, 0, 0, *(u8 *)((u8 *)arg0 + 0xC), *(u8 *)((u8 *)arg0 + 1));
    return 0;
}
