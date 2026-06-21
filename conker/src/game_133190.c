#include <ultra64.h>
#include "functions.h"
#include "variables.h"

struct Vec15107A20 { f32 x; f32 y; f32 z; };

void func_15107A20(struct127 *arg0, s32 arg1, s32 arg2, struct Vec15107A20 *arg3, struct Vec15107A20 *arg4);
void func_15107AE0(struct Vec15107A20 *arg0, struct Vec15107A20 *arg1, struct Vec15107A20 *arg2, struct Vec15107A20 *arg3);
void func_15107F54(s32 *arg0, u8 arg1, void *arg2, s32 arg3);

#pragma GLOBAL_ASM("asm/nonmatchings/game_133190/func_15105CE0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_133190/func_1510608C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_133190/func_151061E0.s")

struct S151061EC {
    u8 pad0[0x48];
    s32 idx;
    u8 pad4C[0x88 - 0x4C];
    u8 elems[1][0x34];
};

void *func_151061EC(struct S151061EC *arg0) {
    s32 i = arg0->idx;
    return &arg0->elems[i];
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_133190/func_15106214.s")

f32 func_151064B4(f32 arg0) {
    f32 t = 1.0f - arg0;
    return t * t * t;
}

f32 func_151064DC(f32 arg0) {
    f32 t = 1.0f - arg0;
    return 3.0f * arg0 * t * t;
}

f32 func_15106510(f32 arg0) {
    return 3.0f * arg0 * arg0 * (1.0f - arg0);
}

f32 func_15106540(f32 arg0) {
    return arg0 * arg0 * arg0;
}

f32 func_15106558(f32 arg0) {
    f32 t = 1.0f - arg0;
    return -3.0f * t * t;
}

f32 func_15106584(f32 arg0) {
    return 9.0f * arg0 * arg0 - 12.0f * arg0 + 3.0f;
}

f32 func_151065BC(f32 arg0) {
    return -9.0f * arg0 * arg0 + 6.0f * arg0;
}

f32 func_151065EC(f32 arg0) {
    return 3.0f * arg0 * arg0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_133190/func_15106610.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_133190/func_151067B8.s")

extern void (*D_80088C18[])(struct102 *);
void func_151D5E30(void *arg0);

void func_15106E78(struct102 *arg0) {
    void (*fn)(struct102 *);
    struct102 *p6C;

    fn = D_80088C18[*(u8 *)((u8 *)arg0 + 0x5C)];
    if (fn != NULL) {
        fn(arg0);
    }
    p6C = *(struct102 **)((u8 *)arg0 + 0x6C);
    if (p6C != NULL) {
        func_1516972C(p6C);
    }
    p6C = *(struct102 **)((u8 *)arg0 + 0x70);
    if (p6C != NULL) {
        func_1516972C(p6C);
    }
    func_151D5E30((u8 *)arg0 + 0x74);
}

void func_15106EF8(struct102 *arg0) {
    func_15106E78(arg0);
    func_15169804(arg0);
}

void func_15169824(struct102 *arg0);

void func_15106F24(struct102 *arg0) {
    func_15106E78(arg0);
    func_15169824(arg0);
}

extern void (*D_80088C28[])(void *, s32, u8);

void func_15106F50(struct102 *arg0, s32 arg1, u8 arg2) {
    void (*fn)(void *, s32, u8) = D_80088C28[*(u8 *)((u8 *)arg0 + 0x5C)];
    if (fn != NULL) {
        fn(arg0, arg1, arg2);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_133190/func_15106F98.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_133190/func_151070F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_133190/func_151072BC.s")

struct S15107604 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
};

void func_15107604(s32 **arg0) {
    s32 **q = (s32 **)arg0[0x18];
    struct S15107604 *p = (struct S15107604 *)((u8 *)q[0] + 0x28);
    p->unk8 = 0;
}

void func_1510761C(struct260 *arg0) {
    if (*(struct102 *volatile *)((u8 *)arg0 + 0x30) != 0) {
        func_1516972C(*(struct102 *volatile *)((u8 *)arg0 + 0x30));
    }
}

void func_1510764C(struct260 *arg0) {
    func_1510761C(arg0);
    func_1514933C(arg0);
}

void func_15149368(struct260 *arg0);

void func_15107678(struct260 *arg0) {
    func_1510761C(arg0);
    func_15149368(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_133190/func_151076A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_133190/func_15107700.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_133190/func_151078E4.s")

struct S15107924 {
    struct127 *unk0;
    u8 unk4;
    u8 unk5;
    s16 unk6;
    s16 unk8;
};

s32 func_15107924(struct127 *arg0, u8 *arg1) {
    struct S15107924 *data;
    struct127 *obj;
    struct Vec15107A20 oldPos;

    data = (struct S15107924 *)arg0->unk60;
    obj = data->unk0;
    if ((obj->interaction_state == 0) || (obj->unique_id != data->unk4)) {
        return 0;
    }
    *arg1 = 0;
    oldPos = *(struct Vec15107A20 *)&arg0->x_position;
    func_15107A20(obj, data->unk6, data->unk8, (struct Vec15107A20 *)&arg0->x_position, NULL);
    if ((oldPos.x == arg0->x_position) && (oldPos.y == arg0->y_position) && (oldPos.z == arg0->z_position)) {
        goto ret1;
    }
    *arg1 = 1;
    func_15107AE0((struct Vec15107A20 *)&arg0->x_position, (struct Vec15107A20 *)&arg0->unk38, (struct Vec15107A20 *)&arg0->y_velocity, (struct Vec15107A20 *)&arg0->old_x_position);
ret1:
    return 1;
}

void func_1515C244(struct127 *, f32 *, f32 *, f32 *);
void func_15143794(s32, s32, f32, f32 *);

void func_15107A20(struct127 *arg0, s32 arg1, s32 arg2, struct Vec15107A20 *arg3, struct Vec15107A20 *arg4) {
    struct Vec15107A20 sp2C;
    f32 sp28;
    f32 sp24;

    func_1515C244(arg0, &sp2C.x, &sp28, &sp24);
    func_15143794((s16)arg1, (s16)arg2, sp28, &arg3->x);
    arg3->y *= arg0->unkF0;
    arg3->x += sp2C.x;
    arg3->y += sp2C.y;
    arg3->z += sp2C.z;
    if (arg4 != NULL) {
        *arg4 = sp2C;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_133190/func_15107AE0.s")

extern void func_1515C244(struct127 *, f32 *, f32 *, f32 *);
extern void func_15143794(s32, s32, f32, f32 *);
extern void func_151C329C(void *, s32, s32);

void func_15107B78(struct127 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    struct { f32 x; f32 y; f32 z; } sp2C;
    struct { f32 x; f32 y; f32 z; } sp20;
    f32 sp1C;
    f32 sp18;

    if (arg0->unk1D4 != NULL) {
        func_1515C244(arg0, &sp20.x, &sp1C, &sp18);
        func_15143794((s16)arg1, (s16)arg2, sp1C, &sp2C.x);
        sp2C.y *= arg0->unkF0;
        sp2C.x += sp20.x;
        sp2C.y += sp20.y;
        sp2C.z += sp20.z;
        func_151C329C(&sp2C, (u8)arg3, arg4);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_133190/func_15107C1C.s")

struct S15107E48 {
    struct127 *unk0;
    u8 unk4;
    u8 pad5[3];
    u8 unk8[0xC];
    u8 unk14;
};

s32 func_15107E48(struct127 *arg0, u8 *arg1) {
    struct S15107E48 *data;
    struct127 *obj;
    struct Vec15107A20 oldPos;

    data = (struct S15107E48 *)arg0->unk60;
    obj = data->unk0;
    if ((obj->interaction_state == 0) || (obj->unique_id != data->unk4)) {
        return 0;
    }
    if (obj->unk1D4 == NULL) {
        return 0;
    }
    *arg1 = 0;
    oldPos = *(struct Vec15107A20 *)&arg0->x_position;
    func_15107F54((s32 *)obj, data->unk14, data->unk8, (s32)(struct Vec15107A20 *)&arg0->x_position);
    if ((oldPos.x == arg0->x_position) && (oldPos.y == arg0->y_position) && (oldPos.z == arg0->z_position)) {
        goto ret1;
    }
    *arg1 = 1;
    func_15107AE0((struct Vec15107A20 *)&arg0->x_position, (struct Vec15107A20 *)&arg0->unk38, (struct Vec15107A20 *)&arg0->y_velocity, (struct Vec15107A20 *)&arg0->old_x_position);
ret1:
    return 1;
}

void func_15143134(void *, s32, s32);

void func_15107F54(s32 *arg0, u8 arg1, void *arg2, s32 arg3) {
    func_15143134(arg2, arg3, arg0[0x1D4 / 4] + (arg1 << 6));
}

void func_15169850(s32, u8, s32, s32, s32);

void func_15107F98(s32 *arg0, s32 arg1, u8 arg2) {
    func_15169850(arg1, arg2, arg0[0x18], arg0[0x18] + 4, (s32)arg0);
}
