#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_1B8F40/func_1518BA90.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1B8F40/func_1518BBF4.s")

s32 func_15167A68(s32, s32, s32, s32, s32, s32);

s32 func_1518BCD0(s32 arg0, s32 arg1, s32 arg2) {
    s32 temp_v0;

    temp_v0 = func_15167A68(0x1F, arg2, 0x44, 1, (u8)arg1, 1);
    if (temp_v0 == 0) {
        return 0;
    }
    memcpy((void *)(temp_v0 + 0x10), (void *)arg0, 0x1C);
    *(s32 *)(temp_v0 + 0x2C) = func_150ADA20() & 0x1F;
    *(s32 *)(temp_v0 + 0x30) = func_150ADA20() & 0x1F;
    return temp_v0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1B8F40/func_1518BD60.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1B8F40/func_1518C0B8.s")

s32 func_1518C540(void* arg0) {
    s32 v1;
    void* p;

    p = *(void**)((u8*)arg0 + 0x98);
    v1 = *(s16*)((u8*)arg0 + 0x1C) << 3;
    if (v1 >= 0x100) {
        v1 = 0xFF;
    }
    *(s8*)((u8*)p + 0x1B) = v1;
    if ((v1 & 0xFF) < 0) {
        return 0;
    }
    return 1;
}

void func_1516865C(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
s32 func_15168800(s32 arg0, s32 arg1, s32 arg2);

struct Struct1518C57C {
    u8 pad[0xA8];
};

struct Elem1518C57C {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    s32 unkC;
    s32 unk10;
};

s32 func_1518C57C(void *arg0, s32 arg1, s32 arg2, s32 arg3, f32 arg4) {
    struct Struct1518C57C sp38;
    void *temp;
    struct Elem1518C57C *base;

    temp = *(void **)((u8 *)arg0 + 0x98);
    base = *(struct Elem1518C57C **)((u8 *)arg0 + 0x94);
    *(s32 *)(sp38.pad + 0x80) = 0;
    *(s16 *)(sp38.pad + 0x8A) = 0x100;
    *(s16 *)(sp38.pad + 0x8C) = (s32)base[*(s8 *)((u8 *)arg0 + 0x2D)].unk0;
    *(s16 *)(sp38.pad + 0x8E) = (s32)arg4;
    *(s16 *)(sp38.pad + 0x90) = (s32)base[*(s8 *)((u8 *)arg0 + 0x2D)].unk8;
    *(s16 *)(sp38.pad + 0x94) = (func_150ADA20() % 0x15U) + 0x23;
    *(s16 *)(sp38.pad + 0x92) = *(s16 *)(sp38.pad + 0x94);
    *(s8 *)(sp38.pad + 0xA2) = -1;
    *(s8 *)(sp38.pad + 0xA0) = 0x12;
    *(s16 *)(sp38.pad + 0x98) = 0xC;
    *(s8 *)(sp38.pad + 0xA1) = 0;
    *(s16 *)(sp38.pad + 0x96) = (s32)arg4;
    func_1516865C(&sp38, 0xFF, 0xFF, 0xFF, 0xFF);
    func_15168800((s32)&sp38, *(u8 *)((u8 *)arg0 + 0xC), *(u8 *)((u8 *)arg0 + 1));
    *(s8 *)((u8 *)temp + 0x20) = 4;
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1B8F40/func_1518C69C.s")

typedef struct {
    u8 pad0[0x24];
    s32 unk24;
    u8 unk28;
} SubA1518C850;

typedef struct {
    s32 unk0;
    union {
        s32 w4;
        u8 b4;
    } u4;
    u8 unk8;
    u8 unk9;
} ArgB1518C850;

void func_1518C850(struct102 *arg0, s32 arg1, u8 arg2) {
    SubA1518C850 *dst = (SubA1518C850 *)arg0;
    ArgB1518C850 *b = (ArgB1518C850 *)arg1;
    s32 b0;

    if (arg2 == 0x2D) {
        b0 = b->unk0;
        if (b0 == dst->unk24) {
            dst->unk24 = b->u4.w4;
            dst->unk28 = b->unk9;
        } else {
            if (dst->unk24 == b->u4.w4) {
                dst->unk24 = b0;
                dst->unk28 = b->unk8;
            }
trailing_label_1518C850:
            ;
        }
    } else if (arg2 == 0) {
        b0 = b->unk0;
        if ((b0 == dst->unk24) || (b->u4.b4 == dst->unk28)) {
            func_1516972C(arg0);
        }
    }
}
