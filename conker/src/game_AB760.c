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

#pragma GLOBAL_ASM("asm/nonmatchings/game_AB760/func_1507E908.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_AB760/func_1507E968.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_AB760/func_1507E9E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_AB760/func_1507E9F8.s")

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
