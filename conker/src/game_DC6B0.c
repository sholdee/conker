#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_DC6B0/func_150AF200.s")

extern void func_151CF898(void *, f32, f32);

void func_150AF2E0(void *arg0, s16 *arg1) {
    func_151CF898(arg0, (f32)(arg1[4] + arg1[1]), (f32)arg1[1]);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_DC6B0/func_150AF328.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_DC6B0/func_150AF6E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_DC6B0/func_150AF738.s")

extern void func_150B1DB0(void *, void *);

void func_150AF790(void *arg0, u8 *arg1) {
    func_150B1DB0(arg1, arg1 + 0x1ECC0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_DC6B0/func_150AF7C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_DC6B0/func_150AFBF4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_DC6B0/func_150AFC68.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_DC6B0/func_150AFDB0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_DC6B0/func_150AFE64.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_DC6B0/func_150B003C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_DC6B0/func_150B0094.s")

void func_150B02C0(void *arg0) {
    if (*(s32 *)((u8 *)arg0 + 0x170) != 0) {
        func_1516972C(*(struct102 **)((u8 *)arg0 + 0x170));
    }
}

extern void func_150B02C0(void *);
extern void func_15132570(void *);

void func_150B02F0(void *arg0) {
    func_150B02C0(arg0);
    func_15132570(arg0);
}

extern void func_1513259C(void *);

void func_150B031C(void *arg0) {
    func_150B02C0(arg0);
    func_1513259C(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_DC6B0/func_150B0348.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_DC6B0/func_150B060C.s")
