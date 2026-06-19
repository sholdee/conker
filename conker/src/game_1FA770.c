#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_1FA770/func_151CD2C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1FA770/func_151CD35C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1FA770/func_151CD394.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1FA770/func_151CD3CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1FA770/func_151CD4C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1FA770/func_151CD674.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1FA770/func_151CD7BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1FA770/func_151CDB94.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1FA770/func_151CDE20.s")

typedef struct {
    char pad0[0x1E];
    u16 unk1E;
    char pad20[0x10];
    u8 unk30;
} ConkerStruct151CE47C;

void func_151CE47C(ConkerStruct151CE47C *arg0) {
    arg0->unk30 = 0;
    arg0->unk1E &= ~0x2;
    arg0->unk1E |= 0x8;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1FA770/func_151CE49C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1FA770/func_151CE4DC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1FA770/func_151CE51C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1FA770/func_151CE634.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1FA770/func_151CE6D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1FA770/func_151CEA20.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1FA770/func_151CEAAC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1FA770/func_151CEC10.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1FA770/func_151CEC54.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1FA770/func_151CF120.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1FA770/func_151CF380.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1FA770/func_151CF844.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1FA770/func_151CF898.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1FA770/func_151CFA4C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1FA770/func_151D0024.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1FA770/func_151D0058.s")

typedef struct {
    char pad84[0x84];
    u16 unk84;
} ConkerStruct151D0128b;

typedef struct {
    char padE[0xE];
    s16 unkE;
    char pad10[0x18];
    ConkerStruct151D0128b *unk28;
    char pad2C[0x2];
    u16 unk2E;
} ConkerStruct151D0128;

void func_151D0128(ConkerStruct151D0128 *arg0) {
    ConkerStruct151D0128b *p = arg0->unk28;
    if (arg0->unk2E != p->unk84) {
        arg0->unkE = -1;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1FA770/func_151D014C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1FA770/func_151D08F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1FA770/func_151D09A8.s")

void func_151D0ED8(void *arg0) {
    if (*(struct102 *volatile *)((u8 *)arg0 + 0xA8) != 0) {
        func_1516972C(*(struct102 *volatile *)((u8 *)arg0 + 0xA8));
    }
}

void func_151D0ED8(void *arg0);

void func_1513173C(void *arg0);

void func_151D0F08(void *arg0) {
    func_151D0ED8(arg0);
    func_1513173C(arg0);
}

void func_1513175C(void *arg0);

void func_151D0F34(void *arg0) {
    func_151D0ED8(arg0);
    func_1513175C(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1FA770/func_151D0F60.s")

s32 func_151D1074(f32 *arg0, f32 *arg1) {
    arg1[0] = arg0[5];
    arg1[1] = arg0[96] + 8.0f;
    arg1[2] = arg0[7];
    return 1;
}

s32 func_151D10E4(void *arg0, s32 arg1, s32 arg2);

s32 func_151D10A4(void *arg0, s32 arg1) {
    return func_151D10E4(arg0, arg1, 0);
}

s32 func_151D10C4(void *arg0, s32 arg1) {
    return func_151D10E4(arg0, arg1, 1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1FA770/func_151D10E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1FA770/func_151D1138.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1FA770/func_151D1328.s")

void func_151D13E0(struct260 *arg0);

void func_151D1368(struct260 *arg0) {
    func_151D13E0(arg0);
}

void func_151D1388(struct260 *arg0) {
    func_151D1368(arg0);
    func_1514933C(arg0);
}

void func_15149368(struct260 *arg0);

void func_151D13B4(struct260 *arg0) {
    func_151D1368(arg0);
    func_15149368(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1FA770/func_151D13E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1FA770/func_151D1448.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1FA770/func_151D15D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1FA770/func_151D197C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1FA770/func_151D1C98.s")

void func_151D223C(s32 arg0) {
    s32 *temp_v0;
    s32 temp_v1;

    temp_v0 = *(s32 **)(arg0 + 0x98);
    temp_v1 = temp_v0[0];
    if (temp_v1 != 0) {
        *(s32 *)(temp_v1 + 0x30) = 0;
    }
}

extern void func_151478F4(void *);

void func_151D2258(s32 arg0) {
    func_151D223C(arg0);
    func_151478F4((void *)arg0);
}

extern void func_15147928(s32);

void func_151D2284(s32 arg0) {
    func_151D223C(arg0);
    func_15147928(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1FA770/func_151D22B0.s")
