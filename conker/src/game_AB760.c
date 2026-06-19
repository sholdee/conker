#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_AB760/func_1507E2B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_AB760/func_1507E3C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_AB760/func_1507E500.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_AB760/func_1507E5C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_AB760/func_1507E6B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_AB760/func_1507E73C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_AB760/func_1507E7E4.s")

extern struct124 *D_800D1C90[];
s32 func_150849A0(void *arg0);

s32 func_1507E908(void *arg0, s32 arg1) {
    s32 *temp;
    s32 base;

    temp = (s32 *)D_800D1C90[func_150849A0(arg0)];
    if (temp != 0) {
        temp -= 2;
        base = temp[0];
        if (base != 0) {
            return (arg1 * 10) + base;
        }
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_AB760/func_1507E968.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_AB760/func_1507E9E8.s")

extern s32 func_150849A0(void *);
extern s32 D_8009D910;

void *func_1507E9F8(void *arg0, s32 *arg1) {
    if (!func_150849A0(arg0)) {
        if (arg1 != 0) {
            *arg1 = 5;
        }
        return &D_8009D910;
    }
    if (arg1 != 0) {
        *arg1 = 0;
    }
    return (void *)0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_AB760/func_1507EA44.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_AB760/func_1507EABC.s")

void func_1507EB4C(void *, s32);
void func_1507EABC(void *);

void func_1507EB2C(void *arg0) {
    func_1507EB4C(arg0, 0);
}

void func_1507EB4C(void *arg0, s32 arg1) {
    if (arg1 != *(u8 *)((s32)arg0 + 0x70)) {
        *(u8 *)((s32)arg0 + 0x70) = arg1;
        func_1507EABC(arg0);
    }
}
