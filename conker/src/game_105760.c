#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_105760/func_150D82B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_105760/func_150D82BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_105760/func_150D83D8.s")

s16 *func_150D8590(s16 *arg0, s32 arg1) {
    arg0[0] = 0x42;
    arg0[1] = 0;
    return arg0 + 2;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_105760/func_150D85AC.s")

struct S150D88AC {
    u8 pad0[0x14];
    u8 *unk14;
    u8 *unk18;
};

s32 func_150D88AC(struct S150D88AC *arg0) {
    if (arg0->unk18[0x6F] != 0) {
        arg0->unk14[0x9] = 0;
    } else {
        arg0->unk14[0x9] = 1;
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_105760/func_150D88E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_105760/func_150D8A20.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_105760/func_150D8A34.s")
