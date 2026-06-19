#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_139FC0/func_1510CB10.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_139FC0/func_1510CDB8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_139FC0/func_1510CE60.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_139FC0/func_1510D0EC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_139FC0/func_1510D374.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_139FC0/func_1510D404.s")

void func_1510D608(s32 arg0, s32 arg1) {
    s8 *p = (s8 *)&D_800BC448[arg0];
    s8 temp = *p;
    if (temp != 0) {
        *p = (temp & 0x40) | arg1;
    }
}

extern s32 func_1510D694(s16);
extern s32 func_10004074(s16 *);

void func_1510D630(s16 *arg0) {
    s16 *p;
    s16 *end;
    s16 count = arg0[0];

    p = arg0 + 1;
    if (count > 0) {
        end = arg0 + count + 1;
        do {
            func_1510D694(*p);
            p++;
        } while (end != p);
    }
    func_10004074(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_139FC0/func_1510D694.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_139FC0/func_1510D720.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_139FC0/func_1510D7AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_139FC0/func_1510D864.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_139FC0/func_1510D874.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_139FC0/func_1510D8C0.s")
