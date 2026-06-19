#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_49D30/func_1501C880.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_49D30/func_1501CC3C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_49D30/func_1501CDC0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_49D30/func_1501CE54.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_49D30/func_1501CFF8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_49D30/func_1501D044.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_49D30/func_1501D1D4.s")

void func_1501D258(s32 arg0, s32 arg1) {
    if (!D_800C3670) {
        D_800C3A60[arg0] |= (1LL << arg1);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_49D30/func_1501D2C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_49D30/func_1501D348.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_49D30/func_1501DAAC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_49D30/func_1501DE18.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_49D30/func_1501DF04.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_49D30/func_1501E05C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_49D30/func_1501E1B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_49D30/func_1501E2F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_49D30/func_1501E400.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_49D30/func_1501E540.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_49D30/func_1501E73C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_49D30/func_1501E81C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_49D30/func_1501EA18.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_49D30/func_1501EC38.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_49D30/func_1501F72C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_49D30/func_1501FC8C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_49D30/func_1501FE68.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_49D30/func_1501FFE8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_49D30/func_15020388.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_49D30/func_15020878.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_49D30/func_15020EC4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_49D30/func_1502178C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_49D30/func_15021DB8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_49D30/func_15022024.s")

extern s16 D_800C358C[];
extern f32 D_800C3594;
extern u8 D_800C3663;

void func_15022190(s16 arg0, s16 arg1, s16 arg2, f32 arg3) {
    D_800C3594 = arg3;
    D_800C358C[0] = arg0;
    D_800C358C[1] = arg1;
    D_800C358C[2] = arg2;
    D_800C3663 = 1;
}

extern s16 D_800C3598[];
extern f32 D_800C35A0;

void func_150221E8(s16 arg0, s16 arg1, s16 arg2, f32 arg3) {
    D_800C35A0 = arg3;
    D_800C3598[0] = arg0;
    D_800C3598[1] = arg1;
    D_800C3598[2] = arg2;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_49D30/func_15022234.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_49D30/func_15022248.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_49D30/func_1502225C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_49D30/func_150222E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_49D30/func_15022398.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_49D30/func_15022528.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_49D30/func_15022640.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_49D30/func_150226BC.s")

extern u8 D_800C363A[];
extern void func_150226BC(s32, s32);

void func_15022754(s32 arg0) {
    s32 i;

    for (i = 0; i < D_800C363A[arg0]; i++) {
        func_150226BC(i, arg0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_49D30/func_150227BC.s")

extern void func_15022398(s32, s32);
extern void func_150222E0(s32, s32);

void func_15022848(s32 arg0) {
    s32 i;

    if ((&D_800C35EA)[arg0] == 1) {
        D_800C3638 = 0;
        for (i = 0; i < D_800C363A[arg0]; i++) {
            func_15022398(i, arg0);
            func_150222E0(i, arg0);
        }
        D_800C3638 = 1;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_49D30/func_150228E4.s")

void func_15022998(s32 *arg0) {
    if ((*arg0 == 0x1B) || (*arg0 == 4)) {
        if (D_80086014[*arg0] != 0) {
            D_80086014[*arg0](arg0);
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_49D30/func_150229E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_49D30/func_15022B08.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_49D30/func_15022BA4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_49D30/func_15023264.s")

void func_150233BC(void) {
    bzero(D_800C3CA0, 0xA8);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_49D30/func_150233E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_49D30/func_15023440.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_49D30/func_150234A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_49D30/func_150235DC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_49D30/func_1502378C.s")
