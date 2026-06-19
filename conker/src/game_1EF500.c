#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_1EF500/func_151C2050.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1EF500/func_151C229C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1EF500/func_151C2734.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1EF500/func_151C2AD0.s")

typedef struct {
    s32 unk0;
    u8 unk4;
} GameStruct151C2E4C;

s32 func_151C2E4C(GameStruct151C2E4C *a0, GameStruct151C2E4C *a1) {
    if (a0 == a1) {
        return 0;
    }
    if (a0->unk0 == 0) {
        return 0;
    }
    if (a0->unk4 == 0xFF) {
        return 0;
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1EF500/func_151C2E94.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1EF500/func_151C2EF0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1EF500/func_151C2F48.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1EF500/func_151C329C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1EF500/func_151C36D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1EF500/func_151C3B0C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1EF500/func_151C436C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1EF500/func_151C43E0.s")

typedef struct {
    u8 pad0[0x34];
    f32 unk34;
    f32 unk38;
    f32 unk3C;
} GameStruct151C4510a;

typedef struct {
    u8 pad0[0x4];
    f32 unk4;
    f32 unk8;
    f32 unkC;
} GameStruct151C4510b;

void func_151C4510(GameStruct151C4510a *a0, GameStruct151C4510b *a1, f32 a2) {
    a0->unk34 += a1->unk4 * a2;
    a0->unk38 += a1->unk8 * a2;
    a0->unk3C += a1->unkC * a2;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1EF500/func_151C455C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1EF500/func_151C4644.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1EF500/func_151C4820.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1EF500/func_151C4AB0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1EF500/func_151C4B0C.s")
