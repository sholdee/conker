#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_E1280/func_150B3DD0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_E1280/func_150B3E74.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_E1280/func_150B3EE8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_E1280/func_150B3F5C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_E1280/func_150B40E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_E1280/func_150B4294.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_E1280/func_150B4710.s")

void func_150B5060(void *arg0) {
    void *temp_v0 = *(void **)((u8 *)arg0 + 0x98);

    *(u8 *)((u8 *)arg0 + 0x30) = 0;
    *(u16 *)((u8 *)arg0 + 0x1E) = *(u16 *)((u8 *)arg0 + 0x1E) & 0xFFFD;
    *(u8 *)((u8 *)temp_v0 + 0x1C) = *(u8 *)((u8 *)temp_v0 + 0x1C) | 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_E1280/func_150B5088.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_E1280/func_150B538C.s")
