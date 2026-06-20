#include <ultra64.h>
#include "functions.h"
#include "variables.h"


extern f32 D_80098250;

typedef struct {
    u8 pad0[0x324];
    f32 *unk324;
} GameStruct_15036C70;

void func_15036C70(GameStruct_15036C70 *arg0) {
    s32 i;
    f32 val;

    arg0->unk324 = allocate_memory(0x48, 1, 0, 0);
    bzero(arg0->unk324, 0x48);
    val = D_80098250;
    for (i = 0; i != 0xC; i += 4) {
        *(f32 *)((u8 *)arg0->unk324 + i) = val;
        *(f32 *)((u8 *)arg0->unk324 + i + 0xC) = val;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_64120/func_15036CE8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_64120/func_15036F34.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_64120/func_15037698.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_64120/func_15037880.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_64120/func_150379DC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_64120/func_150380C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_64120/func_15038468.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_64120/func_15038620.s")

typedef struct {
    s32 unk0[6];
} GameStruct_15039A54;

extern GameStruct_15039A54 D_80098068[];

GameStruct_15039A54 *func_15039A54(s32 arg0, s32 arg1) {
    return &D_80098068[arg1];
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_64120/func_15039A78.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_64120/func_15039CC8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_64120/func_15039ED0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_64120/func_1503A08C.s")

typedef struct {
    u8  pad0[0x30];
    f32 unk30;
    f32 unk34;
    f32 unk38;
} GameStruct_1503A60C;

void func_1503A60C(void) {
    GameStruct_1503A60C *dst = (GameStruct_1503A60C *)((u8 *)D_800CC2D0[D_800C3E78].unk1D4 + 0x40);

    dst->unk30 = *(f32 *)&D_800CC2D0[D_800C3E78].pad174;
    dst->unk34 = D_800CC2D0[D_800C3E78].y_position;
    dst->unk38 = *(f32 *)&D_800CC2D0[D_800C3E78].pad178;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_64120/func_1503A678.s")

extern u8 D_800C3FFA;
extern void func_15036F34(void);
extern void func_1503A678(void);

void func_1503A7F0(void) {
    s32 temp = D_800C3FFA;
    D_800C3FFA = 0;
    func_15036F34();
    D_800C3FFA = temp;
    func_1503A678();
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_64120/func_1503A830.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_64120/func_1503B708.s")
