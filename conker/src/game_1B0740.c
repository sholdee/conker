#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_1B0740/func_15183290.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1B0740/func_151838B0.s")

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
} Struct15183974;

void func_15183ACC(s32);

void func_15183974(s32 arg0) {
    if (((Struct15183974 *)D_800DDE80)[arg0].unk0 == 0) {
        func_15183ACC(arg0);
    }
    if (((Struct15183974 *)D_800DDE80)[arg0 + 1].unk0 == 0) {
        func_15183ACC(arg0 + 1);
        ((Struct15183974 *)D_800DDE80)[arg0 + 1].unkC = ((Struct15183974 *)D_800DDE80)[arg0].unkC;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1B0740/func_151839F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1B0740/func_15183ACC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1B0740/func_15183BA4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1B0740/func_15183C28.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1B0740/func_15183D28.s")

typedef struct {
    char pad[0x57];
    u8 unk57;
} Struct15184118;

typedef struct {
    char pad[0x31C];
    Struct15184118 *unk31C;
} Obj15184118;

s32 func_15184118(Obj15184118 *a0) {
    if (a0->unk31C != 0) {
        if (a0->unk31C->unk57 != 0) {
            return 1;
        }
    }
    return 0;
}
