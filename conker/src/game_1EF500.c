#include <ultra64.h>
#include "functions.h"
#include "variables.h"

typedef void (*GameFunc151C455CDispatch)(s32);
typedef void (*GameFunc151C455CCallback)(struct17 *, s32);

extern GameFunc151C455CDispatch D_8008FBD0[];

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

typedef struct {
    s32 unk0;
    u8 unk4;
    u8 pad[0x122];
    u8 unk127;
} GameStruct151C2E94;

s32 func_151C2E94(GameStruct151C2E94 *a0, GameStruct151C2E94 *a1) {
    if (a0 == a1) {
        return 0;
    }
    if (a0->unk0 == 0) {
        return 0;
    }
    if (a0->unk4 == 0xFF) {
        return 0;
    }
    if (a0->unk127 == 0xFF) {
        return 0;
    }
    return 1;
}

s32 func_151D4DAC(s32, s32, s32, s32, s32, s32, void *, s32, s32);

s32 func_151C2EF0(s32 a0, s32 a1, struct108 *a2, s32 a3, s32 arg4, s32 arg5) {
    return func_151D4DAC(a0, a1, a3, arg4, arg5, *(s32 *)((u8 *)a2 + 0x1B4),
                         (u8 *)a2 + 0x170, *((u8 *)a2 + 0xC), *((u8 *)a2 + 0x1));
}

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

typedef struct {
    u8 unk0;
    u8 pad1[0x83];
    struct131 *unk84;
    u8 pad88[0x4];
    f32 unk8C;
    u8 pad90[0xC];
    s8 unk9C;
} GameStruct151C455C;

s32 func_151C455C(s32 arg0, GameStruct151C455C *arg1, f32 arg2) {
    s32 ret;
    GameFunc151C455CCallback callback;
    struct131 *temp_v1;
    s8 index;

    arg1->unk8C -= arg2;
    ret = 1;
    if (arg1->unk8C <= 0.0f) {
        callback = (GameFunc151C455CCallback)D_800E0940;
        if ((callback != 0) && (arg1->unk0 & 1)) {
            temp_v1 = arg1->unk84;
            if (temp_v1 != 0) {
                callback((struct17 *)((u8 *)arg1 + 0x30), temp_v1 - D_800DBEF4);
            }
        }
        if (arg1->unk0 & 2) {
            index = arg1->unk9C;
            if (index != -1) {
                D_8008FBD0[index](arg0);
            }
        }
        ret = 0;
    }
    return ret;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1EF500/func_151C4644.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1EF500/func_151C4820.s")

typedef struct {
    s32 unk0;
    s32 unk4;
    u8 unk8;
    u8 unk9;
} GameStruct151C4AB0a;

typedef struct {
    u8 pad0[0x90];
    s32 unk90;
    u8 unk94;
} GameStruct151C4AB0b;

void func_151C4AB0(void *a0, GameStruct151C4AB0a *a1, u8 a2) {
    GameStruct151C4AB0b *v0 = (GameStruct151C4AB0b *)((u8 *)a0 + 0x110);
    if (a2 == 0x2D) {
        if (v0->unk90 == a1->unk0) {
            v0->unk90 = a1->unk4;
            v0->unk94 = a1->unk9;
        } else if (v0->unk90 == a1->unk4) {
            v0->unk90 = a1->unk0;
            v0->unk94 = a1->unk8;
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1EF500/func_151C4B0C.s")
