#include <ultra64.h>
#include "functions.h"
#include "variables.h"

typedef struct {
    char pad_0[0x197];
    u8 field_0x197;
} ObjectState197;

typedef struct {
    char pad_0[0x31C];
    ObjectState197 *field_0x31C;
} ObjectWithState197;

typedef struct {
    ObjectWithState197 *field_0x0;
    char pad_0[0x1E];
    u8 field_0x22;
    char pad_1[0x1];
    s32 field_0x24;
    s32 field_0x28;
    s32 field_0x2C;
    s32 field_0x30;
    s32 field_0x34;
} Field124ChildBlock;

typedef struct {
    char pad_0[0x18];
    s32 field_0x18;
    char pad_1[0x8C];
    s32 field_0xA8;
    char pad_2[0x24];
    s32 field_0xD0;
    u8 field_0xD4;
    char pad_3[0x4F];
    s32 field_0x124;
    char pad_4[0x48];
    s32 field_0x170;
} Field124Owner;


#pragma GLOBAL_ASM("asm/nonmatchings/game_12DAB0/func_15100600.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_12DAB0/func_15101090.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_12DAB0/func_15101148.s")

void func_151011E8(Field124Owner *arg0) {
    Field124ChildBlock *temp = (Field124ChildBlock *)(arg0->field_0x124 + 0x110);
    temp->field_0x28 = 0;
    func_1513CA6C((struct210 *)arg0);
}

void func_15101210(Field124Owner *arg0) {
    Field124ChildBlock *temp = (Field124ChildBlock *)(arg0->field_0x124 + 0x110);
    temp->field_0x28 = 0;
    func_1513CAA0((struct210 *)arg0);
}

void func_151617C4(struct210 *arg0);

void func_15101238(Field124Owner *arg0) {
    Field124ChildBlock *temp = (Field124ChildBlock *)(arg0->field_0x18 + 0x110);

    temp->field_0x2C = 0;
    func_151617C4((struct210 *)arg0);
}

void func_151617E4(struct210 *arg0);

void func_15101260(Field124Owner *arg0) {
    Field124ChildBlock *temp = (Field124ChildBlock *)(arg0->field_0x18 + 0x110);

    temp->field_0x2C = 0;
    func_151617E4((struct210 *)arg0);
}

void func_1513173C(struct210 *);

void func_15101288(Field124Owner *arg0) {
    Field124ChildBlock *temp = (Field124ChildBlock *)(arg0->field_0xD0 + 0x110);
    temp->field_0x24 = 0;
    func_1513173C((struct210 *)arg0);
}

void func_1513175C(struct210 *);

void func_151012B0(Field124Owner *arg0) {
    Field124ChildBlock *temp = (Field124ChildBlock *)(arg0->field_0xD0 + 0x110);
    temp->field_0x24 = 0;
    func_1513175C((struct210 *)arg0);
}

void func_151012D8(Field124Owner *arg0) {
    Field124ChildBlock *temp = (Field124ChildBlock *)(arg0->field_0x170 + 0x110);
    temp->field_0x30 = 0;
    func_151411A4((struct210 *)arg0);
}

void func_15101300(Field124Owner *arg0) {
    Field124ChildBlock *temp = (Field124ChildBlock *)(arg0->field_0x170 + 0x110);
    temp->field_0x30 = 0;
    func_151411C4((struct210 *)arg0);
}

void func_15101328(Field124Owner *arg0) {
    Field124ChildBlock *temp = (Field124ChildBlock *)(arg0->field_0xA8 + 0x110);
    temp->field_0x34 = 0;
    func_1513173C((struct210 *)arg0);
}

void func_15101350(Field124Owner *arg0) {
    Field124ChildBlock *temp = (Field124ChildBlock *)(arg0->field_0xA8 + 0x110);
    temp->field_0x34 = 0;
    func_1513175C((struct210 *)arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_12DAB0/func_15101378.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_12DAB0/func_151019C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_12DAB0/func_15101F50.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_12DAB0/func_151022AC.s")

extern f32 D_800BE9A4;

s32 func_151025F4(u8 *arg0, s32 arg1) {
    f32 *v1 = (f32 *)(arg0 + 0xA8);
    f32 sin0[2];
    f32 sin1;

    sin0[0] = sinf(v1[6]);
    sin1 = sinf(v1[7]);
    v1[0] = v1[4] * sin0[0] + v1[2];
    v1[1] = v1[5] * sin1 + v1[3];
    v1[6] = v1[8] * D_800BE9A4 + v1[6];
    v1[7] = v1[9] * D_800BE9A4 + v1[7];
    v1[6] = func_15144B68(v1[6]);
    v1[7] = func_15144B68(v1[7]);
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_12DAB0/func_151026BC.s")

void func_151027E8(struct210 *arg0) {
    s8 sp18[5];

    *(struct210 **)&sp18[0] = arg0;
    sp18[4] = *(u8 *)((s32)arg0 + 0x3B);
    func_151403A8(&sp18, 0x1A);
}

s32 func_1510281C(Field124Owner *arg0, s16 arg1) {
    Field124ChildBlock *p = (Field124ChildBlock *)(arg0->field_0xD0 + 0x110);
    ObjectWithState197 *v1;

    if (arg1 != p->field_0x22) {
        goto tail;
    }
    v1 = p->field_0x0;
    if (v1 != 0) {
        if (v1->field_0x31C->field_0x197 == 0) {
            goto tail;
        }
    }
    return 0;
tail:
    if (!(arg0->field_0xD4 & 1)) {
        return 0;
    }
    return 1;
}

s32 func_15102884(struct210 *arg0, s32 arg1) {
    if (!(*(u8 *)((s32)arg0 + 0xAC) & 1)) {
        return 0;
    }
    return 1;
}

s32 func_151028AC(struct210 *arg0, s16 arg1) {
    s32 *p = (s32 *)(*(s32 *)((s32)arg0 + 0x170) + 0x110);
    s32 v1;

    if (arg1 != *(u8 *)((s32)p + 0x22)) {
        goto tail;
    }
    v1 = *p;
    if (v1 != 0) {
        if (*(u8 *)(*(s32 *)(v1 + 0x31C) + 0x197) == 0) {
            goto tail;
        }
    }
    return 0;
tail:
    if (!(*(u8 *)((s32)arg0 + 0x174) & 1)) {
        return 0;
    }
    return 1;
}
