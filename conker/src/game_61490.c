#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_61490/func_15033FE0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_61490/func_150341BC.s")

s16 *func_15034340(s16 *arg0, s32 arg1) {
    struct127 *obj = &D_800CC2D0[arg1];

    if (obj->unk1D1 != 0) {
        *arg0 = 6;
        arg0 += 2;
        arg0[-1] = obj->unk1D1 * 200;
    }
    return arg0;
}

s16 *func_150343B0(s16 *arg0, s32 arg1) {
    struct127 *obj = &D_800CC2D0[arg1];

    if (obj->unk1D1 != 0) {
        *arg0 = 6;
        arg0 += 2;
        arg0[-1] = obj->unk1D1 * 200;
    }
    return arg0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_61490/func_15034420.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_61490/func_150344A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_61490/func_1503453C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_61490/func_150345E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_61490/func_15034728.s")

extern void func_15034728(struct127 *);

void func_150347E8(void) {
    struct127 *obj;

    if (D_800BEAC0 != 0) {
        return;
    }

    obj = D_800CC2D0;
    do {
        if (obj->interaction_state != 0 && obj->unk9C != 0) {
            func_15034728(obj);
        }
        obj++;
    } while (obj != (struct127 *)&D_800D121C);
}
