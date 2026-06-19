#include <ultra64.h>
#include "functions.h"
#include "variables.h"


s32 func_1516A770(u8 *arg0) {
    s32 count = 1;

    while (*arg0 != 0) {
        if (*arg0 == 0xBD) {
            *arg0 = 0;
            count++;
        }
        arg0++;
    }
    return count;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_197C20/func_1516A7B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_197C20/func_1516AA70.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_197C20/func_1516B6BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_197C20/func_1516C878.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_197C20/func_1516C934.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_197C20/func_1516CC58.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_197C20/func_1516D0CC.s")

void func_1516D2E0(u8 *arg0) {
    if ((arg0 != 0) && (*arg0 == 0x51)) {
        *(u8 *)(*(s32 *)(arg0 + 0x10) + 8) = 0;
        func_1516972C((struct102 *)arg0);
        arg0[0x15] = 0;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_197C20/func_1516D328.s")

u8 *func_1516D378(u8 *arg0) {
    if ((arg0 != 0) && (*arg0 == 0x51)) {
        *(s32 *)(*(s32 *)(arg0 + 0x10)) |= 0x100;
        *(s32 *)(*(s32 *)(arg0 + 0x10)) &= ~0x400;
        return arg0;
    }
    return 0;
}

s32 func_1516D3C4(u8 *arg0) {
    s32 *temp;

    if ((arg0 != 0) && (*arg0 == 0x51)) {
        temp = *(s32 **)(arg0 + 0x10);
        *temp |= 0x500;
        return (s32)arg0;
    }
    return 0;
}
