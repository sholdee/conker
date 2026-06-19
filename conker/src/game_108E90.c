#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_108E90/func_150DB9E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_108E90/func_150DBC60.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_108E90/func_150DBD70.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_108E90/func_150DC558.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_108E90/func_150DCEA0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_108E90/func_150DD640.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_108E90/func_150DDED0.s")

s32 func_150DBD70(s32);

s32 func_150DDF88(u8 *arg0) {
    return func_150DBD70(arg0[0x28]);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_108E90/func_150DDFAC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_108E90/func_150DE12C.s")

s32 func_150DE2A4(void *arg0) {
    s16 temp = *(s16 *)((u8 *)arg0 + 0x1C);
    if (temp < 0x20) {
        *(s8 *)((u8 *)arg0 + 0x28) = temp << 3;
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_108E90/func_150DE2C4.s")
