#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_1BF090/func_15191BE0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1BF090/func_15191D54.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1BF090/func_1519203C.s")

extern void func_15131C84(s32, s32, s32, s32, s32, s32);

u8 func_15192308(s32 arg0, s32 arg1) {
    func_15131C84(arg0 + 0xAC, arg0 + 0xAE, *(s32 *)(arg0 + 0xA8), arg0 + 0xB0, arg0 + 0x38, arg0 + 0x3C);
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1BF090/func_15192358.s")

u8 func_15192308(s32 arg0, s32 arg1);
u8 func_15192358(s32 arg0, s32 arg1);

u8 func_1519257C(s32 arg0, s32 arg1) {
    u8 ret;
    ret = func_15192308(arg0, arg1);
    if (ret != 0) {
        ret = func_15192358(arg0, arg1);
    }
    return ret;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1BF090/func_151925C4.s")

void func_1519277C(s32 arg0, s32 arg1, u8 arg2) {
    func_15169850(arg1, arg2, arg0 + 0x28, arg0 + 0x2C, arg0);
}
