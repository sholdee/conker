#include <ultra64.h>
#include "functions.h"
#include "variables.h"


extern s32 func_15147A80(void *, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);

struct Struct15147DA0_cpy { s32 unk0[8]; };

s32 func_15147DA0(void *arg0, void *arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5,
                  s32 arg6, s32 arg7, s32 arg8, s32 arg9, s32 arg10, s32 *arg11,
                  s32 arg12, u8 arg13, s32 arg14) {
    s32 v1;
    u8 *temp;

    *(s32 *)((u8 *)arg0 + 0x10) = 1;
    v1 = func_15147A80(arg0, (s32)arg2 + 0x48, 0x14, 1, 0, 1, arg9, arg10,
                       arg12, arg13, arg14);
    if (v1 == 0) {
        return 0;
    }
    temp = (u8 *)*(s32 *)((u8 *)v1 + 0x98);
    memcpy(temp, arg1, 0x20);
    temp[0x20] = arg3;
    temp[0x21] = arg4;
    temp[0x22] = arg5;
    temp[0x23] = arg6;
    temp[0x24] = arg7;
    temp[0x25] = arg8;
    *(struct Struct15147DA0_cpy *)(temp + 0x28) = *(struct Struct15147DA0_cpy *)arg11;
    return v1;
}


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
