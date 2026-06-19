#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_F2820/func_150C5370.s")

void func_150C5430(struct102 *arg0) {
    func_15169804(arg0);
}

void func_150C5450(struct102 *arg0) {
    func_15169824(arg0);
}

extern void (*D_800887B8[])(void);

void func_150C5470(struct102 *arg0) {
    s32 temp = *(u8 *)((u8 *)arg0 + 0x38);

    if (temp < 0) {
        temp = 0;
    } else if (temp >= 2) {
        temp = 0;
    }
    D_800887B8[temp]();
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_F2820/func_150C54C0.s")

extern void func_1514EDF0(struct102 *arg0, s32 arg1);

void func_150C5510(struct102 *arg0) {
    func_1514EDF0(arg0, *(s32 *)((u8 *)arg0 + 0xC8));
    func_150C5430(arg0);
}

void func_150C553C(struct102 *arg0) {
    func_1514EDF0(arg0, *(s32 *)((u8 *)arg0 + 0xC8));
    func_150C5450(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_F2820/func_150C5568.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_F2820/func_150C56A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_F2820/func_150C5B88.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_F2820/func_150C5BD4.s")

void func_150C5C74(s32 arg0) {
    func_1514D3B0(arg0, 0x15, 1, 0);
}

void func_150C5C9C(s32 arg0) {
    func_1514D3B0(arg0, 0x15, 2, 0);
}

extern void (*D_800887C8[])(struct102 *, s32, u8);

void func_150C5CC4(struct102 *arg0, s32 arg1, u8 arg2) {
    void (*temp)(struct102 *, s32, u8) = D_800887C8[*(u8 *)((u8 *)arg0 + 0x38)];

    if (temp != NULL) {
        temp(arg0, arg1, arg2);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_F2820/func_150C5D0C.s")
