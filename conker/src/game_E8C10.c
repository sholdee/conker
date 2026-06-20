#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_E8C10/func_150BB760.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_E8C10/func_150BBB5C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_E8C10/func_150BC488.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_E8C10/func_150BCBBC.s")

extern f32 D_8009FEF8;

struct Obj150BCFB8 {
    u8 pad0[0x10];
    f32 x10;
    f32 x14;
    u8 pad18[0x3C - 0x18];
    f32 x3C;
    u8 pad40[0x44 - 0x40];
    f32 x44;
    f32 x48;
    f32 x4C;
    f32 x50;
    f32 x54;
    f32 x58;
    u8 pad5C[0x60 - 0x5C];
    s32 x60;
};

s32 func_150BCFB8(struct Obj150BCFB8 *arg0, s32 a1, s32 a2, s32 a3, f32 arg5) {
    arg0->x3C = (arg0->x10 * D_8009FEF8) + arg5;
    if (-2.0f < arg0->x48) {
        arg0->x44 = 0.0f;
        arg0->x60 &= ~0x6F;
        arg0->x48 = 0.0f;
        arg0->x4C = 0.0f;
    } else {
        arg0->x44 = arg0->x44 * arg0->x14;
        arg0->x48 = -arg0->x48 * arg0->x14;
        arg0->x4C = arg0->x4C * arg0->x14;
        arg0->x50 = arg0->x50 * arg0->x14;
        arg0->x54 = arg0->x54 * arg0->x14;
        arg0->x58 = arg0->x58 * arg0->x14;
    }
    return 1;
}

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
