#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern u16 *D_800C35C8[];
extern u8 *D_800C35F0[];
extern void func_1507E7E4(void *, s32, s32, s32, s32);
extern s8 D_8008FD84[];
extern u8 D_800C35E8;
extern s32 D_800C35B0[];
extern s32 D_800C3640[];
extern u8 D_800C3C99;
extern u8 D_800C3C9C;
extern u8 D_800D2E40;
extern s32 func_1501D2C4(s32, s32);

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

s32 func_1501E05C(s32 arg0) {
    s32 temp_a2;
    s32 temp_v1;

    temp_a2 = D_800BE9F0;
    temp_v1 = (s32) D_8008FD84;

    if (temp_a2 == 0x1D) {
        if (*(s8 *)temp_v1 == 0) {
            goto check_mode_1d;
        }
        *(s8 *)temp_v1 = 0;
        return 1;
check_mode_1d:
        if (D_800C35E8 != 5) {
            return 0;
        }
    }

    if (temp_a2 == 0x21) {
        if ((D_800BE710[0] & 0x1000) && (D_8000030C == 1) && (D_800C35B0[0] >= 0x12D)) {
            return 1;
        }
        return 0;
    }

    if (D_800BE710[0] & 0x20) {
        if (D_800C3C9C == 0) {
            if (D_800D2E40 != 0) {
                return 1;
            }
            if (func_1501D2C4(temp_a2, (&D_800C35E8)[arg0]) != 0) {
                if ((D_800C3C99 != 0) || ((D_800C35B0[arg0] + 0x1E) < D_800C3640[arg0])) {
                    return 1;
                }
            }
        }
    }
    return 0;
}

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

void func_150222E0(s32 arg0, s32 arg1) {
    struct127 *temp_v0;
    u8 *temp_v1;

    if (D_800C35C8[arg1][arg0] != 0) {
        temp_v1 = &D_800C35F0[arg1][arg0 * 8];
        if (*(u16 *)temp_v1 == 2) {
            temp_v0 = func_15083E90(temp_v1[2]);
            if (temp_v0 != 0) {
                *(u8 *)((u8 *)temp_v0 + 0x6C) = 0;
                *(u8 *)((u8 *)temp_v0 + 0x6D) = 0;
                *(u8 *)((u8 *)temp_v0 + 0x6A) = 0;
                *(u8 *)((u8 *)temp_v0 + 0x6B) = 0;
                *(u16 *)((u8 *)temp_v0 + 0x282) = 0;
                *(u16 *)((u8 *)temp_v0 + 0x27A) = 0;
                *(u16 *)((u8 *)temp_v0 + 0x27C) = 0;
                *(u16 *)((u8 *)temp_v0 + 0x27E) = 0;
                *(u16 *)((u8 *)temp_v0 + 0x280) = 0;
                func_1507E7E4(temp_v0, 0, 3, 0xFFFF, 0xA);
                *(u8 *)((u8 *)temp_v0 + 0x71) = 0;
            }
        }
    }
}

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

s32 func_15022B08(s32 arg0, s32 arg1) {
    s32 i;

    for (i = 0; i < D_800C363A[arg1]; i++) {
        if (D_800C35C8[arg1][i] != 0) {
            if (D_800C35F0[arg1][(i * 8) + 2] == ((u8 *)*(&D_800DBEF4) + (arg0 * 0xA0))[0x72]) {
                return 1;
            }
        }
    }

    return 0;
}

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
