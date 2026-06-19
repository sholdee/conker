#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_1C1150/func_15193CA0.s")

extern void func_15193CA0(s32, s32, s32, s32);

void func_151942B0(s32 arg0, s32 arg1, s32 arg2) {
    func_15193CA0(arg1, 0, 0xFF, 1);
}

void func_151942E8(s32 arg0, s32 arg1, s32 arg2) {
    func_15193CA0(arg1, 1, 0xFF, 1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C1150/func_15194320.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C1150/func_15194394.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C1150/func_15194408.s")

extern void func_150C7020(s32, s32, s32, s32);
extern void func_15194408(s32, s32);

void func_15194588(s32 arg0, s32 arg1, s32 arg2) {
    func_150C7020(arg0, 0x1F4, 0xFF, 1);
    func_15194408(arg0, arg1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C1150/func_151945CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C1150/func_15194794.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C1150/func_15194810.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C1150/func_151949E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C1150/func_151949F4.s")

extern void func_1507DE4C(s32);
extern void func_15138BC0(s32, s32, s32);
extern void func_151949F4(s32, s32, s32);

void func_15194A68(s32 arg0, s32 arg1, s32 arg2) {
    func_1507DE4C(arg1);
    func_15138BC0(arg1, 0xFF, 1);
    func_151949F4(0, arg0, arg1);
}

void func_15194AB4(struct127* arg0) {
    s32 sp_a1;

    arg0->unk9C |= 0xFFFE;
    sp_a1 = -1;
    switch (arg0->id) {
    case 0x75:
        sp_a1 = 0x73;
        break;
    case 0x80:
        sp_a1 = 0x72;
        break;
    }
    if (sp_a1 != -1) {
        func_15083568(arg0, sp_a1, 1.0f, 0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C1150/func_15194B1C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C1150/func_15194B94.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C1150/func_15194BF0.s")

s32 func_15194FF4(s32, s32, s32, s32);

s32 func_15194D80(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    return func_15194FF4(arg0, arg1, 0, arg3);
}

s32 func_15194DA4(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    return func_15194FF4(arg0, arg1, 1, arg3);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C1150/func_15194DC8.s")

extern void func_150B06B0(s32, s32, s32, s32);

void func_15194E54(s32 arg0, s32 arg1, s32 arg2) {
    if ((*(u8 *)(arg1 + 4) == 0x3E) || (*(u8 *)(arg1 + 4) == 0xA6)) {
        func_150B06B0(arg1, arg0, 0xFF, 1);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C1150/func_15194EA8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C1150/func_15194F48.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C1150/func_15194FF4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C1150/func_151951E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C1150/func_15195528.s")

void func_151B01B8(s32, s32);
void func_151B09BC(s32, s32, s32, s32, s32);

void func_15195650(s32 arg0, s32 arg1, s32 arg2) {
    func_151B01B8(arg0, arg1);
    func_151B09BC(arg0, arg1, 0x3E8, 0xFF, 0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C1150/func_15195698.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C1150/func_15195738.s")
