#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_58F80/func_1502BAD0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_58F80/func_1502BD84.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_58F80/func_1502BEE4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_58F80/func_1502C1A4.s")

extern s32 D_800C3E88;
extern s32 D_800C3E8C;
extern u16 D_800C3E7A;

void func_1502C380(void) {
    D_800C3E8C = D_800C3E88 = (&D_800C3E80)[D_800BE9C0];
    D_800C3E7A = 0;
}

extern u8 D_800CC406[];

s32 func_1502C3BC(s32 arg0) {
    s32 temp = D_800CC406[arg0 * 0x32C];

    if (temp >= 0x46) {
        temp = 0xB;
    }
    return temp;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_58F80/func_1502C408.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_58F80/func_1502C608.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_58F80/func_1502C6E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_58F80/func_1502C974.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_58F80/func_1502CC34.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_58F80/func_1502CCFC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_58F80/func_1502D54C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_58F80/func_1502D630.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_58F80/func_1502D824.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_58F80/func_1502DB20.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_58F80/func_1502DB84.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_58F80/func_1502DF38.s")

extern u8 D_800C3E90;
extern void func_150A9984(s32, s32);

void func_1502E474(void) {
    if (D_800C3E7A != 0) {
        func_150A9984((&D_800C3E80)[D_800BE9C0], D_800C3E7A);
    }
    D_800C3E90 = 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_58F80/func_1502E4C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_58F80/func_1502E9FC.s")

void func_1502EA0C(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    arg0[0xA4] = 4;
    arg0[0xA5] = 0;
    arg0[0xA6] = arg5;
    *(u32 *)(arg0 + 0xA0) = (arg4 << 24) | (arg1 << 16) | (arg2 << 8) | arg3;
    arg0[0xA7] = 0xFF;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_58F80/func_1502EA50.s")

void func_1502EA60(u8 *arg0, s32 arg1) {
    arg0[0xA4] = 2;
    arg0[0xA5] = 0xFF;
    arg0[0xA6] = arg1;
}

void func_1502EA7C(u8 *arg0, s32 arg1) {
    arg0[0xA4] = 3;
    arg0[0xA5] = 0xFF;
    arg0[0xA6] = arg1;
}

void func_1502EA98(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    if (arg0[0xA4] != 6 && arg0[0xA4] != 7) {
        if (arg5 != 0) {
            arg0[0xA5] = 0xFF;
        } else {
            arg0[0xA5] = 0;
        }
        *(u32 *)(arg0 + 0xA0) = (arg4 << 24) | (arg1 << 16) | (arg2 << 8) | arg3;
        arg0[0xA6] = arg6;
    }
    arg0[0xA4] = 6;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_58F80/func_1502EAFC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_58F80/func_1502EC34.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_58F80/func_1502EE8C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_58F80/func_1502EEF4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_58F80/func_1502F01C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_58F80/func_1502F264.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_58F80/func_1502F3C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_58F80/func_1502F490.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_58F80/func_1502F948.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_58F80/func_1502F9FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_58F80/func_1502FBE8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_58F80/func_1502FD70.s")
