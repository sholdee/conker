#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_DF260/func_150B1DB0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_DF260/func_150B1E20.s")

struct df260a { s32 unk0[3]; };

void func_150B1EE0(struct127 *arg0, struct df260a *arg1, s32 arg2, s32 arg3) {
    struct {
        struct df260a unk0;
        f32 unkC;
    } sp38;
    struct260 *temp_v0;

    sp38.unk0 = *arg1;
    sp38.unkC = 0.0f;

    temp_v0 = func_15149130((func_150ADA20() % 0x85U) + 0x45, -1, 0x49, -1, 1, 0, (struct37 *)0x10, *(u8 *)((s32)arg0 + 0xC), *(u8 *)((s32)arg0 + 0x1));
    if (temp_v0 != NULL) {
        memcpy((void *)((s32)temp_v0 + 0x28), &sp38, 0x10);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_DF260/func_150B1F90.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_DF260/func_150B2340.s")
