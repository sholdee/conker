#include <ultra64.h>
#include "functions.h"
#include "variables.h"

typedef struct GameStruct151B2100Sub {
    struct127 *unk0;
    u8 unk4;
    u8 pad5[3];
    struct127 *unk8;
    u8 unkC;
    u8 unkD;
    u8 padE[2];
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s32 unk1C;
} GameStruct151B2100Sub;

typedef struct GameStruct151B2100 {
    u8 pad0[0xE];
    s16 unkE;
    u8 pad10[0x18];
    GameStruct151B2100Sub unk28;
} GameStruct151B2100;

s32 func_151B22F4(s32 *arg0);
void func_151B222C();
void func_151B2348(s32 *arg0);
void func_151B2690(s32 *arg0);
void func_151B47D8(s32 arg0, s32 arg1, s32 arg2, u8 arg3);


void func_151B2060(void *arg0) {
    struct260 *temp_v0;
    struct {
        void *unk0;
        s8 unk4;
        struct127 *unk8;
        s8 unkC;
        s8 unkD;
        u8 padE[2];
        s32 unk10;
        s32 unk14;
        s32 unk18;
        s32 unk1C;
    } tmp;

    if (arg0 != NULL) {
        tmp.unk0 = arg0;
        tmp.unk4 = *((u8 *)arg0 + 0x3B);
        tmp.unk8 = func_15083E90(1);
        tmp.unkC = 1;
        tmp.unkD = 0;
        bzero(&tmp.unk10, 0xC);
        tmp.unk1C = 0;

        temp_v0 = func_151491F4(0x12C, -1, 0x16, 0, 0x12, 0x20, 0xFF, 1);
        if (temp_v0 != NULL) {
            memcpy((u8 *)temp_v0 + 0x28, &tmp, 0x20);
        }
    }
}

void func_151B2100(GameStruct151B2100 *arg0) {
    GameStruct151B2100Sub *sub;
    struct127 *obj0;
    struct127 *obj1;
    u8 old;

    obj0 = arg0->unk28.unk0;
    obj1 = arg0->unk28.unk8;
    sub = &arg0->unk28;
    if ((obj0->interaction_state == 0) || (obj0->id == 0xFF) || (obj0->unique_id != sub->unk4) ||
        (obj1->interaction_state == 0) || (obj1->id == 0xFF) || (obj1->unique_id != sub->unkC)) {
        arg0->unkE = -1;
        return;
    }

    old = sub->unkD;
    sub->unkD = func_151B22F4((s32 *)arg0);
    if (sub->unkD != old) {
        func_151B222C(arg0);
        if (sub->unkD == 1) {
            func_151B2348((s32 *)arg0);
        }

        if ((sub->unkD == 2) || (sub->unkD == 0)) {
            func_151B2690((s32 *)arg0);
        }
    }
}

void func_151B222C();

void func_151B220C() {
    func_151B222C();
}

void func_151B222C(arg0)
struct260 *arg0;
{
    s32 i;
    s32 v;
    s32 *p = (s32 *)((u8 *)arg0 + 0x28);

    for (i = 0; i < 3; i = (u8)(i + 1)) {
        v = p[i + 4];
        if (v != 0) {
            func_1516972C((struct102 *)v);
        }
    }
    v = p[7];
    if (v != 0) {
        func_1516972C((struct102 *)v);
    }
}

void func_151B229C(struct260 *arg0) {
    func_151B220C(arg0);
    func_1514933C(arg0);
}

void func_151B22C8(struct260 *arg0) {
    func_151B220C(arg0);
    func_15149368(arg0);
}

s32 func_151B22F4(s32 *arg0) {
    s32 temp = arg0[0x28 / 4];
    if ((((((s32)temp - (s32)D_800CC2D0) / 0x32C) + 1) == ((struct127 *)arg0[0x30 / 4])->unk65)) {
        if (((struct127 *)arg0[0x30 / 4])->unk5C == 1) {
            return 1;
        }
    }
    return 2;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1DF510/func_151B2348.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1DF510/func_151B2690.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1DF510/func_151B2950.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1DF510/func_151B2974.s")

void func_151B2EC4(s32 arg0, s32 arg1, u8 arg2) {
    func_15169850(arg1, arg2, arg0 + 0x28, arg0 + 0x2C, arg0);
}

typedef struct {
    s32 unk0;
    s32 unk4;
    u8 unk8;
    u8 unk9;
} GameStruct151B2F04a;

typedef struct {
    s32 unk0;
    u8 unk4;
    u8 pad5[3];
    s32 unk8;
    u8 unkC;
} GameStruct151B2F04b;

void func_151B2F04(void *a0, GameStruct151B2F04a *a1, u8 a2) {
    GameStruct151B2F04b *v0 = (GameStruct151B2F04b *)((u8 *)a0 + 0x28);
    if (a2 == 0x2D) {
        if (v0->unk0 == a1->unk0) {
            v0->unk0 = a1->unk4;
            v0->unk4 = a1->unk9;
        } else if (v0->unk0 == a1->unk4) {
            v0->unk0 = a1->unk0;
            v0->unk4 = a1->unk8;
        }
        if (v0->unk8 == a1->unk0) {
            v0->unk8 = a1->unk4;
            v0->unkC = a1->unk9;
        } else if (v0->unk8 == a1->unk4) {
            v0->unk8 = a1->unk0;
            v0->unkC = a1->unk8;
        }
    }
}

void func_151B2FA0(s32 arg0, s32 arg1, u8 arg2) {
    func_151B47D8(arg0, arg0 + 0x150, arg1, arg2);
}

void func_151B2FD0(s32 *arg0) {
    s32 *temp = (s32 *)arg0[0x4C / 4];
    if (temp != 0) {
        temp[0x44 / 4] = 0;
    }
}

void func_151B2FE8(s32 *arg0) {
    func_151B2FD0(arg0);
    func_1514933C((struct260 *)arg0);
}

void func_151B3014(s32 *arg0) {
    func_151B2FD0(arg0);
    func_15149368((struct260 *)arg0);
}

void func_151B3040(s32 arg0, s32 arg1, u8 arg2) {
    s32 a;
    s32 temp;
    temp = arg0 + 0x150;
    func_15169850(arg1, arg2, temp, arg0 + 0x154, arg0);
    func_15169850(arg1, arg2, temp + 0x14, temp + 0x18, arg0);
}
