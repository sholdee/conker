#include <ultra64.h>
#include "functions.h"
#include "variables.h"


extern void func_15147D64(u8 *arg0, s32 arg1);

void func_1519CF70(u8 arg0) {
    u8 sp1C[4];

    sp1C[0] = arg0;
    func_15147D64(sp1C, 6);
}

struct s_1519CFA0 {
    char pad0[0x1E];
    u16 unk1E;
    char pad20[0x10];
    u8 unk30;
    char pad31[0x67];
    u8 *unk98;
};

void func_1519CFA0(struct s_1519CFA0 *arg0) {
    u8 *temp;

    arg0->unk30 = 0;
    temp = arg0->unk98;
    arg0->unk1E &= 0xFFFD;
    temp[6] |= 1;
    temp[6] |= 4;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1CA420/func_1519CFD0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1CA420/func_1519D000.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1CA420/func_1519D030.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1CA420/func_1519D240.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1CA420/func_1519D454.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1CA420/func_1519D9F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1CA420/func_1519E1F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1CA420/func_1519E304.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1CA420/func_1519E3BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1CA420/func_1519E464.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1CA420/func_1519E570.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1CA420/func_1519E61C.s")

extern void func_1519CF70(u8);

void func_1519E65C(s32 arg0) {
    func_1519CF70(3);
    func_1519CF70(4);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1CA420/func_1519E688.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1CA420/func_1519E6BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1CA420/func_1519E754.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1CA420/func_1519E818.s")

extern void func_1514EDF0(struct260 *, s32);

void func_1519E8CC(struct260 *arg0) {
    func_1514EDF0(arg0, *(s32 *)((u8 *)arg0 + 0x28));
    func_1514933C(arg0);
}

void func_1519E8F8(struct260 *arg0) {
    func_1514EDF0(arg0, *(s32 *)((u8 *)arg0 + 0x28));
    func_15149368(arg0);
}

extern s32 D_800E0920;

void func_1519E924(struct260 *arg0) {
    D_800E0920 = 0;
    func_1514933C(arg0);
}

void func_1519E948(struct260 *arg0) {
    D_800E0920 = 0;
    func_15149368(arg0);
}
