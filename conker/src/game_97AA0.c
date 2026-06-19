#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_97AA0/func_1506A5F0.s")

s32 func_150E0348(s32, s32, s32);

s32 func_1506A6FC(s32 arg0, s32 arg1) {
    return func_150E0348(arg0, 0xFF, 1);
}

extern s32 D_800D1560;
extern s32 D_800D1570;
s32 func_151BB61C(s32, s32, s32, s32, s32);

s32 func_1506A724(s32 arg0, s32 arg1) {
    return func_151BB61C(arg0, (s32)&D_800D1560, (s32)&D_800D1570, 0xFF, 1);
}

s32 func_151BBA9C(s32, s32, s32, s32, s32);

s32 func_1506A760(s32 arg0, s32 arg1) {
    return func_151BBA9C(arg0, (s32)&D_800D1560, (s32)&D_800D1570, 0xFF, 1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_97AA0/func_1506A79C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_97AA0/func_1506A83C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_97AA0/func_1506A864.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_97AA0/func_1506A968.s")

s32 func_151B7144(s32, s32, s32);
s32 func_151B6320(s32, s32, s32);

s32 func_1506AA08(s32 arg0, s32 arg1) {
    func_151B7144(arg0, 0xFF, 1);
    return func_151B6320(arg0, 0xFF, 1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_97AA0/func_1506AA48.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_97AA0/func_1506AAE0.s")

void func_15103E40(struct127 *, struct127 *, struct17 *, u8, u8, u8, u8);

struct struct1506AB7C {
    /* 0x00 */ struct127 *unk0;
    /* 0x04 */ struct17 unk4;
    /* 0x10 */ s32 unk10;
};

void func_1506AB7C(s32 arg0, struct struct1506AB7C *arg1) {
    func_15103E40(arg0, arg1->unk0, &arg1->unk4, 1, arg1->unk10, 0xFF, 1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_97AA0/func_1506ABC4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_97AA0/func_1506AC0C.s")

s32 func_151CEAAC(s32, s32, s32, s32, s32);

s32 func_1506AC58(s32 arg0, s32 arg1) {
    return func_151CEAAC(arg0, 0, 1, 0xFF, 1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_97AA0/func_1506AC8C.s")
