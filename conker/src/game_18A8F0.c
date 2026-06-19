#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_18A8F0/func_1515D440.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_18A8F0/func_1515D480.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_18A8F0/func_1515D4D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_18A8F0/func_1515D520.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_18A8F0/func_1515D5AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_18A8F0/func_1515D5F8.s")

struct Node1515D69C {
    struct Node1515D69C *next;
    char pad4[8];
    s8 unkC;
    char pad10[0x23];
    s8 unk30;
};

void func_1515D69C(void) {
    struct Node1515D69C *p;

    for (p = (struct Node1515D69C *)D_800DCD78; p != 0; p = p->next) {
        p->unkC = 0;
        p->unk30 = 0;
    }
}

void func_1515D6C8(void) {
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_18A8F0/func_1515D6D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_18A8F0/func_1515D914.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_18A8F0/func_1515E278.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_18A8F0/func_1515E43C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_18A8F0/func_1515E544.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_18A8F0/func_1515E888.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_18A8F0/func_1515EB84.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_18A8F0/func_1515EC78.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_18A8F0/func_1515EF74.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_18A8F0/func_1515F008.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_18A8F0/func_1515F040.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_18A8F0/func_1515F0AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_18A8F0/func_1515F10C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_18A8F0/func_1515F170.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_18A8F0/func_1515F1B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_18A8F0/func_1515F25C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_18A8F0/func_1515F270.s")

s32 func_1505D024(struct127 *arg0, s32 arg1, u16 arg2, s32 arg3);

s32 func_1515F2B8(struct127 *arg0, s32 arg1) {
    return func_1505D024(arg0, 0x6001D, arg0->unk7A, -1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_18A8F0/func_1515F2E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_18A8F0/func_1515F338.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_18A8F0/func_1515F5C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_18A8F0/func_1515F850.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_18A8F0/func_1515FB70.s")

s32 func_1515FB94(struct127 *arg0, s32 arg1) {
    return func_1505D024(arg0, 0x6002D, arg0->unk7A, -1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_18A8F0/func_1515FBC4.s")

s32 func_1505D024(struct127 *arg0, s32 arg1, u16 arg2, s32 arg3);

s32 func_1515FC34(struct127 *arg0, s32 arg1) {
    return func_1505D024(arg0, 0x33, 0xC000, -1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_18A8F0/func_1515FC60.s")
