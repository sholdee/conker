#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern s32 (*D_8008AE00[])(void *);

#pragma GLOBAL_ASM("asm/nonmatchings/game_185560/func_151580B0.s")

s32 func_151580B0(void *arg0, s32 arg1, s32 arg2, u8 arg3, s32 arg4, u8 arg5, s32 arg6);

s32 func_151581D8(void *arg0, u8 arg1, s32 arg2, u8 arg3, s32 arg4) {
    return func_151580B0(arg0, 0, 0, arg1, arg2, arg3, arg4);
}

typedef struct {
    u8 pad0[0x10];
    u8 unk10;
    u8 pad11;
    s8 unk12;
    u8 pad13;
    s16 unk14;
} Struct15158224;

void func_15158224(Struct15158224 *arg0) {
    s32 temp;
    u8 failed;

    failed = 0;
    if (arg0->unk10 & 1) {
        arg0->unk14 -= D_800BE9E4;
        if (arg0->unk14 < 0) {
            failed = 1;
        }
    }
    if (failed == 0) {
        temp = arg0->unk12;
        if (temp != -1) {
            if (D_8008AE00[temp](arg0) == 0) {
                failed = 1;
            }
        }
    }
    if (failed) {
        func_1516972C((struct102 *) arg0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_185560/func_151582C8.s")

extern void guMtxF2L(f32 mf[4][4], Mtx *m);

typedef struct {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
} SubF8;

typedef struct {
    u8 pad0[0x48];
    f32 unk48;
    f32 unk4C;
    f32 unk50;
    u8 pad54[0xF8 - 0x54];
    SubF8 subF8;
} Obj1515;

s32 func_1515858C(Mtx *arg0, Obj1515 *arg1) {
    SubF8 *p = &arg1->subF8;
    f32 sp24[4][4];

    func_150A8050(&sp24, p->unk0, p->unk4, p->unk8);
    sp24[3][0] = arg1->unk48;
    sp24[3][1] = arg1->unk4C;
    sp24[3][2] = arg1->unk50;
    sp24[0][0] *= p->unkC;
    sp24[0][1] *= p->unkC;
    sp24[0][2] *= p->unkC;
    sp24[1][0] *= p->unkC;
    sp24[1][1] *= p->unkC;
    sp24[1][2] *= p->unkC;
    sp24[2][0] *= p->unkC;
    sp24[2][1] *= p->unkC;
    sp24[2][2] *= p->unkC;
    guMtxF2L(&sp24, arg0);
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_185560/func_15158684.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_185560/func_15158920.s")

void func_15158A20(struct102 *arg0) {
    s32 i;
    u8 *p;
    s32 *temp;

    i = 0;
    if (D_80082FA0 >= 0) {
        p = (u8 *)arg0;
        do {
            if (*(s32 **)(p + 0xE0)) {
                temp = *(s32 **)(p + 0xE0);
                func_100043B4(temp, 4);
            }
            i++;
            p += 4;
        } while (i <= D_80082FA0);
    }
    if (*(s32 **)((u8 *)arg0 + 0xF0)) {
        temp = *(s32 **)((u8 *)arg0 + 0xF0);
        func_100043B4(temp, 4);
    }
}

void func_15158A20(struct102 *);

void func_15158AA4(struct102 *arg0) {
    func_15158A20(arg0);
    func_15169804(arg0);
}

void func_15169824(struct102 *);

void func_15158AD0(struct102 *arg0) {
    func_15158A20(arg0);
    func_15169824(arg0);
}

typedef struct {
    u8 pad0[0x14];
    s16 unk14;
    u8 pad16[0x25];
    u8 unk3B;
    u8 pad3C[0xBC];
    s16 unkF8;
    u8 padFA[0x2];
    s32 unkFC;
} Struct15158AFC;

s32 func_15158AFC(Struct15158AFC *arg0) {
    s32 temp;

    if (arg0->unk14 < arg0->unkF8) {
        temp = arg0->unk14 * arg0->unkFC;
        if (temp < arg0->unk3B) {
            arg0->unk3B = temp;
        }
    }
    return 1;
}

typedef struct 
{
  s32 unk0;
  s32 unk4;
  u8 unk8;
  u8 unk9;
} Struct15158B3Ca;
typedef struct 
{
  u8 pad0[0x40];
  s32 unk40;
  u8 unk44;
} Struct15158B3Cb;
void func_15158B3C(Struct15158B3Cb *a0, Struct15158B3Ca *a1, u8 a2)
{
  s32 v0;
  if (a2 == 0x2D)
  {
    v0 = a1->unk0;
    if (a0->unk40 == v0)
    {
      a0->unk40 = a1->unk4;
      a0->unk44 = a1->unk9;
    }
    else
    {
      if (a0->unk40 == a1->unk4)
      {
        a0->unk40 = v0;
        a0->unk44 = a1->unk8;
      }
 dummy_label_356969: ;
    }
  }
  else
    if (a2 == 0)
  {
    v0 = a1->unk0;
    if (a0->unk40 != v0)
    {
      if (a0->unk44 != (*(((u8 *) a1) + 4)))
      {
        return;
      }
    }
    a0->unk40 = 0;
    a0->unk44 = 0;
  }
}


#pragma GLOBAL_ASM("asm/nonmatchings/game_185560/func_15158BD0.s")

void func_1514EDF0(struct102 *, s32);

void func_15158CD4(struct102 *arg0) {
    func_1514EDF0(arg0, *(s32 *)((u8 *)arg0 + 0x18));
    func_15169804(arg0);
}

void func_15158D00(struct102 *arg0) {
    func_1514EDF0(arg0, *(s32 *)((u8 *)arg0 + 0x18));
    func_15169824(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_185560/func_15158D2C.s")

void func_1519F400(void *);

typedef struct {
    u8  pad0[0x18];
    s32 unk18;
    u8  unk1C;
} SubA_15158FA4;

typedef struct {
    s32 unk0;
    union {
        s32 w4;
        u8  b4;
    } u4;
    u8  unk8;
    u8  unk9;
} ArgB_15158FA4;

void func_15158FA4(void *arg0, s32 arg1, u8 arg2) {
    SubA_15158FA4 *a = (SubA_15158FA4 *)arg0;
    ArgB_15158FA4 *b = (ArgB_15158FA4 *)arg1;
    s32 t;

    if (arg2 == 0) {
        if ((b->unk0 == a->unk18) || (b->u4.b4 == a->unk1C)) {
            func_1516972C((struct102 *)arg0);
        }
    } else if (arg2 == 0x2D) {
        t = b->unk0;
        if (a->unk18 == t) {
            a->unk18 = b->u4.w4;
            a->unk1C = b->unk9;
        } else {
            if (a->unk18 == b->u4.w4) {
                a->unk18 = t;
                a->unk1C = b->unk8;
            }
        dummy_label_15158FA4: ;
        }
    } else if (arg2 == 0x4) {
        if ((b->unk0 == a->unk18) || (b->u4.b4 == a->unk1C)) {
            func_1519F400(arg0);
        }
    }
}

extern f32 D_800A63A0;

typedef struct {
    u8 pad0[0x18];
    f32 unk18;
    u8 pad1C[0xFC];
    f32 unk118;
    u8 pad11C[0x1B];
    u8 unk137;
    u8 pad138[0x4C];
    s32 unk184;
} Struct15159084;

s32 func_15159084(Struct15159084 *arg0, u8 arg1) {
    s32 ret;
    s32 flags;

    flags = arg0->unk184 & 0x1F;
    if ((arg1 == 2) || (arg1 == 3)) {
        ret = 0;
    } else {
        if ((D_800A63A0 == arg0->unk118) && ((flags & 0xA) == 0)) {
            ret = 1;
        } else if ((arg0->unk118 < arg0->unk18) || (arg0->unk137 != 0)) {
            ret = 1;
        } else {
            ret = 0;
        }
    }
    return ret;
}

typedef struct {
    u8 pad0[0x118];
    f32 unk118;
    u8 pad11C[0x64];
    f32 unk180;
} Struct15159120;

s32 func_15159120(Struct15159120 *arg0, u8 arg1) {
    s32 ret;

    if ((arg1 == 2) || (arg1 == 3)) {
        ret = 1;
    } else if (arg0->unk180 < (arg0->unk118 - 35.0f)) {
        ret = 1;
    } else {
        ret = 0;
    }
    return ret;
}

typedef struct {
    u8 pad0[0x18];
    f32 unk18;
    u8 pad1C[0xFC];
    f32 unk118;
} Struct15159184;

s32 func_15159184(Struct15159184 *arg0, u8 arg1) {
    s32 ret;

    if ((arg1 == 2) || (arg1 == 3)) {
        if (D_800C35EA != 1) {
            ret = 0;
        } else if ((arg0->unk118 - 75.0f) < arg0->unk18) {
            ret = 1;
        } else {
            ret = 0;
        }
    } else if ((arg0->unk118 - 75.0f) < arg0->unk18) {
        ret = 1;
    } else {
        ret = 0;
    }
    return ret;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_185560/func_15159230.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_185560/func_151592B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_185560/func_15159370.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_185560/func_1515942C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_185560/func_15159594.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_185560/func_151596BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_185560/func_15159890.s")

void func_15159890(f32 *, f32 *, s32, s32);

void func_15159BB0(f32 arg0, f32 arg1, f32 arg2, s32 arg3, s32 arg4, s32 arg5, u8 *arg6) {
    f32 sp24[3];
    f32 sp18[3];

    sp24[0] = arg0;
    sp24[1] = arg1;
    sp18[0] = 0.0f;
    sp18[1] = 0.0f;
    sp18[2] = 0.0f;
    sp24[2] = arg2;
    func_15159890(sp24, sp18, arg6[0xC], arg6[0x1]);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_185560/func_15159C08.s")

extern float sinf(float angle);
f32 func_151423D8(u8);
f32 func_15144B68(f32 arg0);
extern f32 D_800BE9A4;
extern s32 D_800BE9E4;
typedef struct 
{
  f32 unkA8;
  u8 unkAC;
  u8 unkAD;
  s8 unkAE;
  s8 unkAF;
  f32 unkB0;
  f32 unkB4;
  f32 unkB8;
  f32 unkBC;
  f32 unkC0;
  f32 unkC4;
  f32 unkC8;
} Sub1515A11C;
typedef struct 
{
  u8 pad0[0x38];
  f32 unk38;
  f32 unk3C;
  u8 pad40[0xC];
  f32 unk4C;
  f32 unk50;
  f32 unk54;
  u8 pad58[0x50];
  Sub1515A11C sub;
} Struct1515A11C;
extern f32 sinf(f32);
s32 func_1515A11C(Struct1515A11C *arg0, s32 arg1)
{
  Sub1515A11C *s0;
  f32 temp0;
  f32 temp1;
  s0 = &arg0->sub;
  arg0->sub.unkAC = arg0->sub.unkAC + (arg0->sub.unkAE * D_800BE9E4);
  arg0->sub.unkAD = arg0->sub.unkAD + (arg0->sub.unkAF * D_800BE9E4);
  temp0 = func_151423D8(arg0->sub.unkAC - 0x40);
  temp1 = func_151423D8(s0->unkAD - 0x40);
  arg0->unk38 = s0->unkA8 + (s0->unkB0 * temp0);
  arg0->unk3C = s0->unkA8 + (s0->unkB4 * temp1);
  if ((s0 && s0) && s0)
  {
  }
  s0->unkC4 = s0->unkC4 + (s0->unkC8 * D_800BE9A4);
  s0->unkC4 = func_15144B68(s0->unkC4);
  temp0 = sinf(s0->unkC4);
  arg0->unk4C = s0->unkB8 * temp0;
  arg0->unk50 = s0->unkBC * temp0;
  arg0->unk54 = s0->unkC0 * temp0;
  return 1;
}


#pragma GLOBAL_ASM("asm/nonmatchings/game_185560/func_1515A238.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_185560/func_1515A60C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_185560/func_1515A78C.s")

s32 func_1514ECE0(void *, s16, void *);

s32 func_1515A920(struct102 *arg0, s32 *arg1) {
    s32 *temp;
    s32 v;

    if (func_1514ECE0(*(void **)((u8 *)arg0 + 0x2F4), 0x13, &temp) == 0) {
        return 0;
    }
    v = *(s32 *)((u8 *)temp + 0x10);
    *arg1 = v + 0x34;
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_185560/func_1515A974.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_185560/func_1515AA84.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_185560/func_1515AB88.s")
