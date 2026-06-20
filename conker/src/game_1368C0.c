#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_1368C0/func_15109410.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1368C0/func_151094FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1368C0/func_15109848.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1368C0/func_15109C20.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1368C0/func_15109ED4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1368C0/func_15109FB8.s")

extern f32 D_800A2684;
extern f32 D_800A2688;

struct260 *func_1510A344(void *arg0, s32 arg1, u8 arg2, s32 arg3) {
    struct260 *temp_v0;
    struct {
        void *unk0;
        u8 unk4;
        u8 pad5;
        u8 pad6;
        u8 pad7;
        f32 unk8;
        f32 unkC;
        f32 unk10;
    } sp30;

    if (arg0 == NULL) {
        return NULL;
    }

    sp30.unk0 = arg0;
    sp30.unk4 = *(u8 *)((s32)arg0 + 0x3B);
    sp30.unk8 = 0.0f;
    sp30.unkC = D_800A2684;
    sp30.unk10 = D_800A2688;

    temp_v0 = func_15149130((s16)arg1, -1, 0x1C, -1, 1, 0x1C, (struct37 *)0x14, arg2, arg3);
    if (temp_v0 != NULL) {
        memcpy((void *)((s32)temp_v0 + 0x28), &sp30, 0x14);
    }
    return temp_v0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1368C0/func_1510A40C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1368C0/func_1510A870.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1368C0/func_1510A8CC.s")
