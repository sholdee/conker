#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_F3BA0/func_150C66F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_F3BA0/func_150C673C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_F3BA0/func_150C682C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_F3BA0/func_150C6870.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_F3BA0/func_150C68C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_F3BA0/func_150C6A08.s")

typedef struct {
    char pad[0x5C];
    u8 unk5C;
} Func150C6D1CArg;

s32 func_150C6D1C(Func150C6D1CArg* arg) {
    s32 ret = 1;
    if (arg->unk5C == 0) {
        ret = 0;
    }
    arg->unk5C = 0;
    return ret;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_F3BA0/func_150C6D40.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_F3BA0/func_150C6D68.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_F3BA0/func_150C6D90.s")
