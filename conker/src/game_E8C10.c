#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_E8C10/func_150BB760.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_E8C10/func_150BBB5C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_E8C10/func_150BC488.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_E8C10/func_150BCBBC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_E8C10/func_150BCFB8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_E8C10/func_150BD070.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_E8C10/func_150BD740.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_E8C10/func_150BD954.s")

struct Sub150BDB3C {
    u8 pad1B[0x1B];
    u8 unk1B;
};

struct Obj150BDB3C {
    u8 pad98[0x1C];
    s16 unk1C;
    u8 pad1E[0x98 - 0x1E];
    struct Sub150BDB3C *unk98;
};

s32 func_150BDB3C(struct Obj150BDB3C *arg0) {
    struct Sub150BDB3C *sp = arg0->unk98;
    s32 val = arg0->unk1C << 3;

    if (val < sp->unk1B) {
        sp->unk1B = val;
    }
    return 1;
}
