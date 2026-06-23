#include <ultra64.h>
#include "functions.h"
#define D_800CBE00 D_800CBE00_s32
#include "variables.h"
#undef D_800CBE00


struct conker15044A28 {
    struct conker15044A28 *next;
    s16 unk4;
    s16 unk6;
    s16 unk8;
    s16 unkA;
    u8 unkC;
    u8 unkD;
    u8 unkE;
};

extern struct conker15044A28 *D_800CBE00[];
extern s32 (*D_80085E80[])(struct conker15044A28 *);
extern void (*D_80085E8C[])(void);
extern f32 D_80098D60;
extern f32 D_80098D64;
extern f32 D_80098D68;
extern f32 sqrtf(f32);

#pragma function sqrtf

#pragma GLOBAL_ASM("asm/nonmatchings/game_71820/func_15044370.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_71820/func_15044380.s")

void func_1504452C(s16 **arg0, struct17 *arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, s32 arg7) {
    s16 **src;
    struct17 *dst;
    s16 *vtx;
    f32 x;
    f32 y;
    f32 z;
    s32 offset;

    vtx = (s16 *)arg1;
    src = arg0;
    for (offset = 0, dst = (struct17 *)vtx; offset != 0x24; offset += sizeof(struct17)) {
        vtx = (s16 *)((u8 *)*src + arg7);
        x = vtx[0] - arg4;
        y = vtx[1] - arg5;
        z = vtx[2] - arg6;
        dst->unk0 = (x * arg3) + (z * arg2);
        dst->unk4 = y;
        dst->unk8 = (z * arg3) - (x * arg2);
        src++;
        dst++;
    }
}

void func_15044658(void) {
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_71820/func_15044660.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_71820/func_150448D0.s")

s32 func_15044964(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7) {
    struct conker15044A28 *node;
    struct conker15044A28 *head;
    struct conker15044A28 *tail;
    struct conker15044A28 *next;
    s32 ret;

    ret = allocate_memory(arg0, 1, 0, 0);
    if (ret == 0) {
        return 0;
    }

    node = (struct conker15044A28 *)ret;
    node->next = 0;
    node->unk4 = arg2;
    node->unkC = arg1;
    node->unkD = arg4;
    node->unkE = arg3;
    node->unk6 = arg5;
    node->unk8 = arg6;
    node->unkA = arg7;

    head = D_800CBE00[0];
    if (head == 0) {
        D_800CBE00[0] = node;
    } else {
        next = head->next;
        tail = head;
        if (next != 0) {
            do {
                tail = next;
                next = next->next;
            } while (next != 0);
        }
        tail->next = node;
    }

    return ret;
}

void func_15044A28(void) {
    struct conker15044A28 *node;
    struct conker15044A28 *prev;
    struct conker15044A28 *next;
    volatile s32 *delta;
    s32 (**funcs0)(struct conker15044A28 *);
    void (**funcs1)(void);
    s32 timer;
    s32 type;
    s32 countdown;
    s32 delay;
    s32 minusOne;

    node = D_800CBE00[0];
    prev = 0;
    minusOne = -1;
    if (node != 0) {
        delta = &D_800BE9E4;
        funcs0 = D_80085E80;
        funcs1 = D_80085E8C;
        do {
            countdown = node->unkE;
            type = node->unkC;
            next = node->next;
            if (countdown == 0) {
                if (funcs0[type](node) != 0) {
                    funcs1[node->unkD]();
                }
            } else {
                delay = countdown - *delta;
                if (delay < 0) {
                    delay = 0;
                }
                node->unkE = delay;
            }
            timer = node->unk4;
            if (timer != minusOne) {
                timer -= *delta;
                if (timer <= 0) {
                    if (prev == 0) {
                        D_800CBE00[0] = node->next;
                    } else {
                        prev->next = node->next;
                    }
                    func_100043B4((s32 *)node, 2);
                } else {
                    node->unk4 = timer;
                    prev = node;
                }
            } else {
                prev = node;
            }
            node = next;
        } while (node != 0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_71820/func_15044B78.s")

struct conker15044CE4 {
    char pad0[6];
    s16 unk6;
    s16 unk8;
    s16 unkA;
    char padC[4];
    s16 unk10;
    s16 unk12;
    s16 unk14;
    char pad16[2];
    s16 *unk18;
    s16 *unk1C;
};

extern void func_15044B78(struct conker15044CE4 *);

void func_15044CE4(struct conker15044CE4 *arg0) {
    s16 *sp18 = arg0->unk18;
    s32 temp;

    arg0->unk6 = sp18[0];
    arg0->unk8 = sp18[1];
    arg0->unkA = sp18[2];
    temp = arg0->unk1C[0] / 32;
    arg0->unk10 = temp;
    arg0->unk12 = temp;
    arg0->unk14 = temp;
    func_15044B78(arg0);
}

extern s32 func_1505D1C4(f32, f32, f32, s32, s32, u16, s32, s32);

s32 func_15044D40(struct conker15044CE4 *arg0) {
    func_1505D1C4(arg0->unk6, arg0->unk8, arg0->unkA, arg0->unk10, 0xFF, 0, 0, 0);
    return 0;
}

s32 func_1505D024(struct127 *arg0, s32 arg1, u16 arg2, s32 arg3);

void func_15044DA0(void) {
    if (D_800CC2D0[0].stunned != 0) {
        return;
    }
    if (D_800CC2D0[0].immune != 0) {
        return;
    }
    func_1505D024(&D_800CC2D0[0], 5, D_800CC2D0[0].unk7A, -1);
}

void func_15044DE8(void) {
    if (D_800CC2D0[0].stunned != 0) {
        return;
    }
    if (D_800CC2D0[0].immune != 0) {
        return;
    }
    if (D_800C35EA != 1) {
        func_1505D024(&D_800CC2D0[0], 4, D_800CC2D0[0].unk7A, -1);
    }
}

void func_15044E40(void) {
    if (D_800CC2D0[0].stunned != 0) {
        return;
    }
    if (D_800CC2D0[0].immune != 0) {
        return;
    }
    func_1505D024(&D_800CC2D0[0], 0x40, D_800CC2D0[0].unk7A, -1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_71820/func_15044E88.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_71820/func_15044ED0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_71820/func_150450CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_71820/func_1504530C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_71820/func_15045384.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_71820/func_1504554C.s")

extern void func_1510F800(s32);
extern s32 func_150A6500(s16, s16, s32, u16);

struct conker15045714 {
    f32 unk0;
    f32 unk4;
    f32 unk8;
};

void func_15045714(struct conker15045714 *arg0, u16 arg1, s32 *arg2, s32 arg3) {
    func_1510F800(2);
    *arg2 = func_150A6500((s16)arg0->unk0, (s16)arg0->unk8, arg3, arg1);
}

s32 func_15045F8C(struct conker15045714 *arg0, f32 arg1, s32 *arg2, s32 arg3);

s32 func_15045780(struct conker15045714 *arg0, u16 arg1, f32 arg2, s32 arg3) {
    s32 sp1C;
    s32 sp18;

    if (arg0->unk4 < arg2) {
        *((u8 *)arg3 + 0x1C) &= ~2;
        return 0;
    }
    func_15045714(arg0, arg1, &sp1C, (s32)&sp18);
    return func_15045F8C(arg0, arg2, &sp18, arg3);
}

extern s32 func_15047004(s32, s32, s32);
extern s32 func_15045780(struct conker15045714 *, u16, f32, s32);

s32 func_15045800(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    switch (func_15047004(arg0, arg2, arg3)) {
    case 0:
        return func_15045780((struct conker15045714 *)arg0, (u16)arg1, *(f32 *)&arg2, arg3);
    case 1:
        return 0;
    case 2:
        return 1;
    default:
        break;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_71820/func_15045880.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_71820/func_15045AE4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_71820/func_15045D48.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_71820/func_15045F8C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_71820/func_150461D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_71820/func_15046460.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_71820/func_150466F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_71820/func_1504697C.s")

s32 func_150470B0(s32, s32, s32);
s32 func_150466F8(s32, u16, s32, s32);

s32 func_15046C00(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    switch (func_150470B0(arg0, arg2, arg3)) {
    case 0:
        return func_150466F8(arg0, (u16)arg1, arg2, arg3);
    case 1:
        return 0;
    case 2:
        return 1;
    default:
        break;
    }
}

s32 func_1504697C(s32, u16, s32, s32);

s32 func_15046C80(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    switch (func_15047004(arg0, arg2, arg3)) {
    case 0:
        return func_1504697C(arg0, (u16)arg1, arg2, arg3);
    case 1:
        return 0;
    case 2:
        return 1;
    default:
        break;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_71820/func_15046D00.s")

s32 func_15046D00(s32, u16, s32, s32);

s32 func_15046F84(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    switch (func_15047004(arg0, arg2, arg3)) {
    case 0:
        return func_15046D00(arg0, (u16)arg1, arg2, arg3);
    case 1:
        return 0;
    case 2:
        return 1;
    default:
        break;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_71820/func_15047004.s")

extern s32 func_150A3FC4(f32, f32, s32, s32, s32);

s32 func_150470B0(s32 a0, s32 a1, s32 a2) {
    f32 sp24;

    if (*(u8 *)(a2 + 0x1C) & 0x4) {
        if (func_150A3FC4(*(f32 *)a0, *(f32 *)(a0 + 8), 0, a2 + 4, (s32)&sp24)) {
            if (sp24 <= *(f32 *)&a1) {
                if (*(f32 *)(a0 + 4) <= sp24) {
                    *(f32 *)a2 = sp24;
                    *(u8 *)(a2 + 0x1C) |= 0x2;
                    return 2;
                }
            }
            return 1;
        }
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_71820/func_1504715C.s")

struct conker150472C0_sub
{
  u8 unk0[0x10];
  u16 unk10;
};
struct conker150472C0_dst
{
  f32 unk0;
  struct conker150472C0_sub unk4;
  u8 pad16[2];
  s32 unk18;
  u8 unk1C;
  u8 unk1D;
  u8 pad1E[2];
  s32 unk20;
};
struct conker150472C0_src
{
  u8 pad0[0xC];
  f32 unkC;
  u8 pad10[0x34];
  struct conker150472C0_sub unk44;
  u8 pad56[3];
  u8 unk59;
  u8 pad5A[2];
  s32 unk5C;
  s32 unk60;
};
void func_150472C0(struct conker150472C0_dst *arg0, struct conker150472C0_src *arg1)
{
  s32 one;
  s32 temp_v0;
  s32 temp_v1;
  s32 temp_a2;
  u8 temp_t2;
  one = 1;
  arg0->unk0 = arg1->unkC;
  arg0->unk4 = (0, arg1->unk44);
  arg0->unk18 = arg1->unk60;
  temp_v0 = arg1->unk59;
  temp_v1 = (1 == (temp_v0 ^ 0)) ? (2) : (0);
  temp_t2 = 1;
  temp_a2 = (one == temp_v0) ? (one) : (0);
  temp_v0 = (one == temp_v0) ? (4) : (0);
  arg0->unk1C = (temp_v0 | temp_a2) | temp_v1;
  if (arg1->unk59 == one)
  {
    arg0->unk1D = temp_t2;
  }
  else
  {
    arg0->unk1D = 0;
  }
  arg0->unk20 = arg1->unk5C;
}


void func_15047390(f32 mf[4][4], f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, f32 arg8, f32 arg9) {
    f32 temp_f0;
    f32 temp_f20;
    f32 temp_f22;
    f32 temp_f24;
    f32 temp_f26;
    f32 temp_f28;
    f32 temp_f30;
    f32 temp_f18;

    guMtxIdentF(mf);

    temp_f26 = arg4 - arg1;
    temp_f28 = arg5 - arg2;
    temp_f30 = arg6 - arg3;
    temp_f18 = sqrtf((temp_f26 * temp_f26) + (temp_f28 * temp_f28) + (temp_f30 * temp_f30));
    if (temp_f18 == 0.0f) {
        temp_f18 = D_80098D60;
    }
    temp_f0 = -1.0f / temp_f18;
    temp_f26 *= temp_f0;
    temp_f28 *= temp_f0;
    temp_f30 *= temp_f0;

    temp_f20 = (arg8 * temp_f30) - (arg9 * temp_f28);
    temp_f22 = (arg9 * temp_f26) - (arg7 * temp_f30);
    temp_f24 = (arg7 * temp_f28) - (arg8 * temp_f26);
    temp_f18 = sqrtf((temp_f20 * temp_f20) + (temp_f22 * temp_f22) + (temp_f24 * temp_f24));
    if (temp_f18 == 0.0f) {
        temp_f18 = D_80098D64;
    }
    temp_f0 = 1.0f / temp_f18;
    temp_f20 *= temp_f0;
    temp_f22 *= temp_f0;
    temp_f24 *= temp_f0;

    arg7 = (temp_f28 * temp_f24) - (temp_f30 * temp_f22);
    arg8 = (temp_f30 * temp_f20) - (temp_f26 * temp_f24);
    arg9 = (temp_f26 * temp_f22) - (temp_f28 * temp_f20);
    temp_f18 = sqrtf((arg7 * arg7) + (arg8 * arg8) + (arg9 * arg9));
    if (temp_f18 == 0.0f) {
        temp_f18 = D_80098D68;
    }
    temp_f0 = 1.0f / temp_f18;
    arg7 *= temp_f0;
    arg8 *= temp_f0;
    arg9 *= temp_f0;

    mf[0][0] = temp_f20;
    mf[1][0] = temp_f22;
    mf[2][0] = temp_f24;
    mf[3][0] = -((arg1 * temp_f20) + (arg2 * temp_f22) + (arg3 * temp_f24));
    mf[0][1] = arg7;
    mf[1][1] = arg8;
    mf[2][1] = arg9;
    mf[3][1] = -((arg1 * arg7) + (arg2 * arg8) + (arg3 * arg9));
    mf[0][2] = temp_f26;
    mf[1][2] = temp_f28;
    mf[2][2] = temp_f30;
    mf[3][2] = -((arg1 * temp_f26) + (arg2 * temp_f28) + (arg3 * temp_f30));
    mf[3][3] = 1.0f;
    mf[0][3] = 0.0f;
    mf[1][3] = 0.0f;
    mf[2][3] = 0.0f;
}

void func_15047688(Mtx *arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, f32 arg8, f32 arg9) {
    f32 sp30[4][4];

    func_15047390(&sp30, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9);
    guMtxF2L(&sp30, arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_71820/func_15047700.s")

void func_15047700(f32 mf[4][4], s32, f32, f32, f32, f32, f32, f32, f32, f32, f32);

void func_15047B80(Mtx *arg0, s32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, f32 arg8, f32 arg9, f32 arg10) {
    f32 sp38[4][4];

    func_15047700(&sp38, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10);
    guMtxF2L(&sp38, arg0);
}
