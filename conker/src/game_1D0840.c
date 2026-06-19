#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_1D0840/func_151A3390.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D0840/func_151A3504.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D0840/func_151A361C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D0840/func_151A37C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D0840/func_151A3BE4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D0840/func_151A4590.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D0840/func_151A4638.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D0840/func_151A483C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D0840/func_151A4900.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D0840/func_151A499C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D0840/func_151A4A38.s")

typedef struct {
    s32 unk0;
    u8 unk4;
} SubA_151A4CE0;

typedef struct {
    s32 unk0;
    union {
        u8 b4;
        s32 w4;
    } u4;
    u8 unk8;
    u8 unk9;
} ArgB_151A4CE0;

void func_151A4E9C(void *arg0);

void func_151A4CE0(struct260 *arg0, s32 arg1, u8 arg2) {
    SubA_151A4CE0 *temp_v0 = *(SubA_151A4CE0 **)((u8 *)arg0 + 0x98);
    ArgB_151A4CE0 *b = (ArgB_151A4CE0 *)arg1;

    if (arg2 == 0) {
        if ((b->unk0 == temp_v0->unk0) || (b->u4.b4 == temp_v0->unk4)) {
            func_151A4E9C(arg0);
        }
    } else if (arg2 == 0x2D) {
        if (temp_v0->unk0 == b->unk0) {
            temp_v0->unk0 = b->u4.w4;
            temp_v0->unk4 = b->unk9;
        } else if (temp_v0->unk0 == b->u4.w4) {
            temp_v0->unk0 = b->unk0;
            temp_v0->unk4 = b->unk8;
        }
    }
}

void func_1516972C(struct102 *arg0);

typedef struct {
    s32 unk0;
    u8 unk4;
} SubA_151A4D88;

typedef struct {
    s32 unk0;
    union {
        u8 b4;
        s32 w4;
    } u4;
    u8 unk8;
    u8 unk9;
} ArgB_151A4D88;

void func_151A4D88(struct260 *arg0, s32 arg1, u8 arg2) {
    SubA_151A4D88 *temp_v0 = (SubA_151A4D88 *)((u8 *)arg0 + 0x28);
    ArgB_151A4D88 *b = (ArgB_151A4D88 *)arg1;

    if (arg2 == 0) {
        if ((b->unk0 == temp_v0->unk0) || (b->u4.b4 == temp_v0->unk4)) {
            func_1516972C((struct102 *)arg0);
        }
    } else if (arg2 == 0x2D) {
        if (temp_v0->unk0 == b->unk0) {
            temp_v0->unk0 = b->u4.w4;
            temp_v0->unk4 = b->unk9;
        } else if (temp_v0->unk0 == b->u4.w4) {
            temp_v0->unk0 = b->unk0;
            temp_v0->unk4 = b->unk8;
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D0840/func_151A4E34.s")

void func_151A4E9C(void *arg0)
{
  u8 *p;
  u8 v;
  int new_var;
  *((u8 *) (((u8 *) arg0) + 0x30)) = 0;
  *((u16 *) (((u8 *) arg0) + 0x1E)) &= 0xFFFD;
 new_var = 0xFFu; do { p = *((u8 **) (((u8 *) arg0) + 0x98)); v = (p[0x30] & new_var) | 1; *(p + 0x30) = v; *((volatile u8 *) (p + 0x30)) = v | 4; } while (0);
}


#pragma GLOBAL_ASM("asm/nonmatchings/game_1D0840/func_151A4ECC.s")

void func_1516972C(struct102 *arg0);

struct struct151A4F7C {
    s32 unk0;
    u8 unk4;
};

void func_151A4F7C(struct102 *arg0, struct102 *arg1, u8 arg2)
{
    struct struct151A4F7C *p = (struct struct151A4F7C *)((u8 *)arg0 + 0x28);
    struct struct151A4F7C *q = (struct struct151A4F7C *)arg1;
    if (!arg2) {
        if (q->unk0 == p->unk0 || q->unk4 == p->unk4) {
            func_1516972C(arg0);
        }
    }
}

struct Obj151A4FD0 {
    char pad0[0x10];
    s32 unk10;
    u8  unk14;
    u8  unk15;
    u8  unk16;
    u8  unk17;
    u8  unk18;
    u8  unk19;
    u8  unk1A;
};

extern struct Obj151A4FD0 *func_15167A68(s32, s32, s32, s32, s32, s32);

struct Obj151A4FD0 *func_151A4FD0(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, u8 a6, s32 a7) {
    struct Obj151A4FD0 *ret = func_15167A68(0x5A, 0, a7 + 0x20, 0, 0xFF, 1);
    if (ret == 0) {
        return NULL;
    }
    ret->unk14 = a0;
    ret->unk10 = a1;
    ret->unk15 = a2;
    ret->unk16 = a3;
    ret->unk17 = a4;
    ret->unk19 = a6;
    ret->unk18 = 0;
    ret->unk1A = a5;
    return ret;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D0840/func_151A5070.s")

extern void (*D_8008F900[])(void *, void *, s16);

void func_151A5130(void *arg0, void *arg1, s16 arg2)
{
  D_8008F900[*((u8 *) (((u8 *) arg1) + 0x14))](arg0, arg1, arg2);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D0840/func_151A5170.s")

extern void (*D_8008F904[])(void *, void *, u8);

void func_151A55D4(void *arg0, void *arg1, u8 arg2)
{
  void (*f)(void *, void *, u8);
  f = D_8008F904[*((u8 *) (((u8 *) arg0) + 0x19))];
  if (f != NULL) {
    f(arg0, arg1, arg2);
  }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D0840/func_151A561C.s")
