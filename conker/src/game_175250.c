#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_175250/func_15147DA0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_175250/func_15147EB8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_175250/func_1514803C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_175250/func_151488C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_175250/func_15148AF4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_175250/func_15148BA4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_175250/func_15148DE0.s")

s32 func_15148EF8(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    u8 *temp = (u8 *)*(s32 *)((u8 *)arg0 + 0x98);
    temp[0x20] = 4;
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_175250/func_15148F1C.s")

s32 func_151490C8(void *arg0) {
    u8 *v0 = (u8 *)*(s32 *)((u8 *)arg0 + 0x98);
    s32 v1 = *(s16 *)((u8 *)arg0 + 0x1C) << 3;

    if (v1 >= 0x100) {
        v1 = 0xFF;
    }
    v0[0x1B] = v1;
    if ((v1 & 0xFF) < 0) {
        return 0;
    }
    return 1;
}

void func_151478F4(void);

void func_15149104(void) {
    func_151478F4();
}
