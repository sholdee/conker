#include <ultra64.h>
#include "functions.h"
#include "variables.h"


s32 *allocate_memory(s32, s32, s32, s32);

s32 *func_1515D440(void) {
    s32 *temp;

    temp = allocate_memory(0x10, 1, 2, 0);
    bzero(temp, 0x10);
    return temp;
}

s32 *func_1515D480(s32 arg0) {
    s32 *temp;
    s32 size;
    s32 *pp = &arg0;

    size = *pp * 0x60;
    temp = allocate_memory(size, 1, 2, 0);
    bzero(temp, size);
    return temp;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_18A8F0/func_1515D4D4.s")

struct Node1515D520 {
    struct Node1515D520 *next;
};

s32 *func_1515D520(void) {
    struct Node1515D520 *node;
    struct Node1515D520 *p;
    struct Node1515D520 *q;

    node = (struct Node1515D520 *)allocate_memory(0x34, 1, 2, 2);
    if (node != 0) {
        bzero(node, 0x34);
        if (D_800DCD78 != 0) {
            p = (struct Node1515D520 *)D_800DCD78;
            q = p->next;
            while (q != 0) {
                p = q;
                q = q->next;
            }
            p->next = node;
        } else {
            D_800DCD78 = (s32)node;
        }
        node->next = 0;
    }
    return (s32 *)node;
}

s32 func_1515D5F8(s32, s32, s32, s32, s32, s32, s32, s32, s32, u8);

s32 func_1515D5AC(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8, u8 arg9) {
    return func_1515D5F8(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_18A8F0/func_1515D5F8.s")

struct Node1515D69C {
    struct Node1515D69C *next;
    char pad4[8];
    s8 unkC;
    char pad10[0x23];
    s8 unk30;
};

void func_1515D69C(void) {
    struct Node1515D69C *p;

    for (p = (struct Node1515D69C *)D_800DCD78; p != 0; p = p->next) {
        p->unkC = 0;
        p->unk30 = 0;
    }
}

void func_1515D6C8(void) {
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_18A8F0/func_1515D6D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_18A8F0/func_1515D914.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_18A8F0/func_1515E278.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_18A8F0/func_1515E43C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_18A8F0/func_1515E544.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_18A8F0/func_1515E888.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_18A8F0/func_1515EB84.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_18A8F0/func_1515EC78.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_18A8F0/func_1515EF74.s")

f32 func_1515F008(s16 *arg0, s32 arg1) {
    s32 hi = arg0[arg1];
    hi = (hi << 16) | (u16)arg0[arg1 + 0x10];
    return (f32)hi * 1.52587890625e-05f;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_18A8F0/func_1515F040.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_18A8F0/func_1515F0AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_18A8F0/func_1515F10C.s")

struct Node1515F170 {
    struct Node1515F170 *next;
    char pad4[5];
    s8 unk9;
    char padA[1];
    u8 unkB;
};

void func_1515F170(s32 arg0, u8 arg1) {
    struct Node1515F170 *p;

    for (p = (struct Node1515F170 *)D_800DCD78; p != 0; p = p->next) {
        if (arg0 == p->unkB) {
            p->unk9 = arg1;
        }
    }
}

struct Node1515F1B0 {
    s32 unk0;
    f32 unk4;
    f32 unk8;
    s32 unkC;
};

struct Node1515F1B0 *func_1515F1B0(s32 arg0) {
    struct Node1515F1B0 *temp;

    temp = (struct Node1515F1B0 *)func_10003C6C(0x10, 1, 2, 0, 1);
    if (temp == 0) {
        return 0;
    }
    temp->unk0 = arg0;
    if (arg0 != 0) {
        temp->unk4 = func_1514462C(arg0);
    } else {
        temp->unk4 = 0.0f;
    }
    if (arg0 != 0) {
        temp->unk8 = func_15144598((struct134 *)arg0);
    } else {
        temp->unk8 = 0.0f;
    }
    temp->unkC = 0;
    return temp;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_18A8F0/func_1515F25C.s")

extern void (*D_8008B090[])(s32);

void func_1515F270(s32 arg0, s32 *arg1) {
    s32 idx = arg1[6];

    if (idx >= 0 && idx < 12) {
        if (D_8008B090[idx] != 0) {
            D_8008B090[idx](arg0);
        }
    }
}

s32 func_1505D024(struct127 *arg0, s32 arg1, u16 arg2, s32 arg3);

s32 func_1515F2B8(struct127 *arg0, s32 arg1) {
    return func_1505D024(arg0, 0x6001D, arg0->unk7A, -1);
}

extern void (*D_8008B0C0[])(void);

void func_1515F2E8(u8 *arg0, s32 *arg1) {
    s32 idx;

    if (arg0[0x3B] == 1) {
        idx = arg1[7];
        if (idx >= 0 && idx < 3) {
            D_8008B0C0[idx]();
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_18A8F0/func_1515F338.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_18A8F0/func_1515F5C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_18A8F0/func_1515F850.s")

long func_1515FB70(u8 *a0, u8 *a1)
{
  long new_var;
  s32 v0;
  s32 *new_var2;
  v0 = (*((u8 *) (a0 + 0x3B))) == 1;
  if ((*((u8 *) (a0 + 0x3B))) == 1)
  {
 if (0) { *new_var2 = v0; }
    v0 = *((s32 *) (a1 + 0x1C));
    if (v0 >= 0)
    {
      new_var = 0x1C;
      if (!v0)
      {
        new_var2 = (s32 *) (a1 + new_var);
      }
    }
  }
}


s32 func_1515FB94(struct127 *arg0, s32 arg1) {
    return func_1505D024(arg0, 0x6002D, arg0->unk7A, -1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_18A8F0/func_1515FBC4.s")

s32 func_1505D024(struct127 *arg0, s32 arg1, u16 arg2, s32 arg3);

s32 func_1515FC34(struct127 *arg0, s32 arg1) {
    return func_1505D024(arg0, 0x33, 0xC000, -1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_18A8F0/func_1515FC60.s")
