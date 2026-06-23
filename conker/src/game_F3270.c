#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void *func_150C6460(u8 *arg0);

void func_150C5DC0(u8 *arg0) {
    u8 *temp;

    if (*(s32 *)(arg0 + 0x58) != 0) {
        temp = *(u8 **)(arg0 + 0x58) + 0xB0;
        temp[4] = 1;
        done:
            ;
    } else {
        *(void **)(arg0 + 0x58) = func_150C6460(arg0);
    }
}

struct Sub150C5E0C {
    /* 0x00 */ s32 unk0;
    /* 0x04 */ u8 unk4;
    /* 0x05 */ u8 pad5[3];
    /* 0x08 */ f32 unk8;
    /* 0x0C */ f32 unkC;
    /* 0x10 */ f32 unk10;
    /* 0x14 */ s16 unk14;
    /* 0x16 */ s16 unk16;
    /* 0x18 */ s16 unk18;
    /* 0x1A */ s16 unk1A;
    /* 0x1C */ f32 unk1C;
};

s32 func_150C5E0C(u8 *arg0) {
    s8 ret;
    struct Sub150C5E0C *sub;

    ret = 1;
    sub = (struct Sub150C5E0C *)(arg0 + 0xB0);
    if (sub->unk4 == 0) {
        ret = 0;
    }
    sub->unk4 = 0;
    sub->unk14 -= D_800BE9E4;
    if (sub->unk14 < 0) {
        sub->unk14 = (func_150ADA20() % (u32)(sub->unk18 + 1)) + sub->unk16;
        sub->unk10 = func_150ADA68() * sub->unkC + sub->unk8;
    }
    *(s32 *)(arg0 + 0x24) += (s32)((sub->unk10 - (f32)*(s32 *)(arg0 + 0x24)) * sub->unk1C);
    return ret;
}

extern s32 func_1513F6C0(void *arg0, s32 arg1, s32 arg2);

s32 func_150C5EFC(u8 *arg0) {
    s32 *temp = (s32 *)((*(u8 **)((u8 *)arg0 + 0xB0)) + 0x58);
    temp[0] = 0;
    *(s32 *)((u8 *)arg0 + 0x18) |= 2;
    *(u8 **)((u8 *)arg0 + 0xB0) = 0;
    func_1513F6C0(arg0, 0, 0);
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_F3270/func_150C5F40.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_F3270/func_150C5F94.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_F3270/func_150C60D8.s")

s32 func_150C63EC(u8 *arg0) {
    s32 ret = 1;

    if (arg0[0x5C] == 0) {
        ret = 0;
    }
    arg0[0x5C] = 0;
    return ret;
}

void func_150C6410(struct102 *arg0) {
    s32 *temp = (s32 *)((*(u8 **)((u8 *)arg0 + 0x58)) + 0x58);
    temp[1] = 0;
    func_151346EC(arg0);
}

void func_150C6438(struct102 *arg0) {
    s32 *temp = (s32 *)((*(u8 **)((u8 *)arg0 + 0x58)) + 0x58);
    temp[1] = 0;
    func_1513470C(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_F3270/func_150C6460.s")
