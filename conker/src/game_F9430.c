#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_F9430/func_150CBF80.s")

extern f32 D_800BE9A4;

typedef struct {
    s16 unk0;
    f32 unk4;
} CC638Sub;

typedef struct {
    char pad0[0x1C];
    s16 unk1C;
    char pad1E[0x2C - 0x1E];
    f32 unk2C;
    f32 unk30;
    char pad34[0x58 - 0x34];
    s32 unk58;
    u8 unk5C;
    char pad5D[0x128 - 0x5D];
    CC638Sub unk128;
} CC638Struct;

s32 func_150CC638(CC638Struct *arg0) {
    CC638Sub *sub;

    if (arg0->unk58 & 1) {
        sub = &arg0->unk128;
        if (arg0->unk1C < 0x20) {
            if ((arg0->unk1C << 3) < arg0->unk5C) {
                *(u8*)((u8*)sub - 0xCC) = arg0->unk1C << 3;
            }
        }
        if (sub->unk0 < arg0->unk1C) {
            f32 v = sub->unk4 * D_800BE9A4;
            arg0->unk2C = arg0->unk2C + v;
            arg0->unk30 = arg0->unk30 + v;
        }
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_F9430/func_150CC6B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_F9430/func_150CC8D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_F9430/func_150CCA7C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_F9430/func_150CCCB4.s")
