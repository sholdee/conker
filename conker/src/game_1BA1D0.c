#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void func_1518E308(void *);

#pragma GLOBAL_ASM("asm/nonmatchings/game_1BA1D0/func_1518CD20.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1BA1D0/func_1518D1C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1BA1D0/func_1518D6E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1BA1D0/func_1518E298.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1BA1D0/func_1518E308.s")

void func_1518E37C(void *arg0, u8 arg1) {
    if (arg1 != *(u8 *)((char *)arg0 + 0x22)) {
        func_1518E308(arg0);
        *(u8 *)((char *)arg0 + 0x22) = arg1;
    }
}

extern void *func_15167A68(s32, s32, s32, s32, s32, s32);

struct Struct1518E3C4 {
    u8 pad0[0x10];
    s32 unk10;
    s32 unk14;
    u8 pad18[0xC];
    f32 unk24;
    s32 unk28;
    u8 unk2C;
    u8 unk2D;
    u8 pad2E[0x2];
    s32 unk30;
    f32 unk34;
    f32 unk38;
    f32 unk3C;
    f32 unk40;
};

void *func_1518E3C4(void *arg0, s32 arg1) {
    struct Struct1518E3C4 *temp_v1;
    struct Struct1518E3C4 *sp24;

    if (*(u8 *)(*(s32 *)arg0 + 4) == 0x96) {
        return NULL;
    }
    temp_v1 = (struct Struct1518E3C4 *)func_15167A68(0x21, 1, 0x9EC, 1, (u8)arg1, 1);
    if (temp_v1 == 0) {
        return NULL;
    }
    sp24 = temp_v1;
    memcpy((s32)temp_v1 + 0x18, arg0, 0xC);
    sp24->unk28 = 0;
    sp24->unk2C = 8;
    sp24->unk2D = 4;
    sp24->unk30 = 0;
    sp24->unk10 = 1;
    sp24->unk14 = 0;
    sp24->unk24 = 0.0f;
    sp24->unk38 = 0.0f;
    sp24->unk3C = 0.0f;
    sp24->unk40 = 0.0f;
    sp24->unk34 = 1.0f;
    bzero((s32)sp24 + 0x48, 0x960);
    return sp24;
}

extern void func_1518E308(void *);
extern void func_1514EDF0(void *, s32);

void func_1518E4A0(void *arg0) {
    func_1518E308(arg0);
    func_1514EDF0(arg0, *(s32 *)((char *)arg0 + 0x18));
}

void func_1518E4CC(void *arg0) {
    func_1518E4A0(arg0);
    func_15169804(arg0);
}

void func_1518E4F8(void *arg0) {
    func_1518E4A0(arg0);
    func_15169824(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1BA1D0/func_1518E524.s")

extern u8 func_150ADA20(void);
extern void func_151429E0(u8, s32, s32, s32);

void func_1518E5D8(u8 *arg0, u8 *arg1, s32 arg2, s32 arg3, s32 arg4, u8 *arg5, s16 *arg6) {
    s32 temp;

    if (func_150ADA20() & 1) {
        *arg1 |= 1;
    }
    *arg0 = 0x16;
    if (func_150ADA20() & 1) {
        temp = 3;
    } else {
        temp = 4;
    }
    func_151429E0(temp, arg2, arg3, arg4);
    *arg5 = 0xC8;
    *arg6 = 0x401;
}

extern s32 func_1518D1C0(s32, s32, s32, s32, u8, u8, void *);
extern u8 D_800A7460[];

s32 func_1518E66C(void *arg0) {
    func_1518D1C0(*(s32 *)((char *)arg0 + 0x18), 3, 0, 0, *(u8 *)((char *)arg0 + 0xC), *(u8 *)((char *)arg0 + 1), D_800A7460);
    *(s16 *)((char *)arg0 + 0x1E) = 0x80;
    *(s8 *)((char *)arg0 + 0x21) = -1;
    return 0;
}

extern u8 D_800A749C[];

s32 func_1518E6D4(void *arg0) {
    func_1518D1C0(*(s32 *)((char *)arg0 + 0x18), 4, 0, 0, *(u8 *)((char *)arg0 + 0xC), *(u8 *)((char *)arg0 + 1), D_800A749C);
    *(s16 *)((char *)arg0 + 0x1E) = 0x80;
    *(s8 *)((char *)arg0 + 0x21) = -1;
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1BA1D0/func_1518E73C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1BA1D0/func_1518EB10.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1BA1D0/func_1518EF54.s")

extern f32 D_800BE9A4;
s32 func_1518F058(f32 *arg0)
{
  f32 t0;
  f32 t1;
  f32 t2;
  int new_var;
  arg0[0x50] = arg0[0x54] * arg0[0x50];
  arg0[0x51] += arg0[0x53] * D_800BE9A4;
  new_var = arg0 && arg0;
  arg0[0x52] = arg0[0x54] * arg0[0x52];
  t0 = arg0[0x50] * D_800BE9A4;
  t1 = arg0[0x51] * D_800BE9A4;
  t2 = arg0[0x52] * D_800BE9A4;
  arg0[0xD] = arg0[0xD] + t0;
  arg0[0xE] = arg0[0xE] + t1;
  arg0[0xF] = arg0[0xF] + t2;
  arg0[0x10] = arg0[0x10] + t0;
  if (new_var && arg0)
  {
  }
  arg0[0x11] = arg0[0x11] + t1;
  arg0[0x12] = arg0[0x12] + t2;
  return 1;
}


#pragma GLOBAL_ASM("asm/nonmatchings/game_1BA1D0/func_1518F108.s")

s32 func_1518F15C(void *arg0) {
    f32 temp;

    temp = *(f32 *)((char *)arg0 + 0x30);
    *(f32 *)((char *)arg0 + 0x30) = temp - *(f32 *)((char *)arg0 + 0x154) * *(f32 *)((char *)arg0 + 0x30);
    if (*(s16 *)((char *)arg0 + 0x1C) < *(s16 *)((char *)arg0 + 0x158)) {
        *(u8 *)((char *)arg0 + 0x5C) = *(s16 *)((char *)arg0 + 0x15A) * *(s16 *)((char *)arg0 + 0x1C);
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1BA1D0/func_1518F1A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1BA1D0/func_1518F384.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1BA1D0/func_1518F45C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1BA1D0/func_1518F49C.s")

extern s32 func_1518FDC4(void *, u8 *, u8);
extern s32 func_1518F5D0(void *, void *, s16, s8, s8, s8, u8, s32, u8, s32);
extern s32 D_8008D630[];

s32 func_1518F51C(void *arg0, u8 arg1, s32 arg2, s32 arg3, s8 arg4, s8 arg5, u8 arg6, s32 arg7, u8 arg8, s32 arg9) {
    u8 dummy[4];
    u8 sp33;

    if (arg0 == 0) {
        return 0;
    }
    if (func_1518FDC4(arg0, &sp33, arg1) == 0) {
        return 0;
    }
    return func_1518F5D0(arg0, (void *)(D_8008D630[sp33] + arg1 * 0x50), (s16)arg2, (s8)arg3, arg4, arg5, arg6, arg7, arg8, arg9);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1BA1D0/func_1518F5D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1BA1D0/func_1518F7C4.s")

extern void (*D_8008D680[])(void);

void func_1518F858(void *arg0) {
    if (*(volatile s8 *)((char *)arg0 + 0x89) == -1) {
        return;
    }
    D_8008D680[*(s8 *)((char *)arg0 + 0x89)]();
}

extern f32 func_150ADA68(void);
extern void func_1518F8E0(void *);

struct Vec898 { f32 unk0; f32 unk4; f32 unk8; f32 unkC; f32 unk10; };
struct Obj898 { char pad[0x30]; struct Vec898 vec; };

void func_1518F89C(struct Obj898 *arg0) {
    struct Vec898 *p;

    p = &arg0->vec;
    p->unk0 = func_150ADA68() * p->unk10 + p->unkC;
    func_1518F8E0(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1BA1D0/func_1518F8E0.s")

extern void func_1514BE20(void *);

struct Vec3i { s32 x, y, z; };

s32 func_1518FC04(void *arg0, struct Vec3i *arg1) {
    struct { s32 pad[13]; struct Vec3i v; } *temp;
    temp = ((void **)arg0)[0xB];
    temp->v = *arg1;
    func_1514BE20(temp);
    return 1;
}

extern void func_1514BF50(void *);

struct Vec3i2 { s32 x, y, z; };

s32 func_1518FC44(void *arg0, struct Vec3i2 *arg1) {
    struct { s32 pad[13]; struct Vec3i2 v; } *temp;
    temp = *(void **)((char *)arg0 + 0x2C);
    temp->v = *arg1;
    func_1514BF50(temp);
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1BA1D0/func_1518FC84.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1BA1D0/func_1518FDC4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1BA1D0/func_1519003C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1BA1D0/func_1519021C.s")

extern void func_15163DEC(void *, void *);
extern s32 func_15163F50(void *, void *);

void func_151903D0(void *arg0) {
    func_15163DEC(arg0, (char *)arg0 + 0x20);
    func_15163F50(arg0, (char *)arg0 + 0x18);
}

void func_15190400(struct102 *arg0, void *arg1, u8 arg2) {
    s32 a, b;
    u8 c, d;
    if (arg2 == 0) {
        a = *(s32 *)((u8 *)arg0 + 0x18);
        b = *(s32 *)arg1;
        c = *(u8 *)((u8 *)arg0 + 0x1C);
        d = *(u8 *)((u8 *)arg1 + 0x4);
        if (a == b || c == d) {
            func_1516972C(arg0);
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1BA1D0/func_15190454.s")

extern void func_15190454(void *);
extern void func_151617C4(void *);

void func_15190464(void *arg0) {
    func_15190454(arg0);
    func_151617C4(arg0);
}

extern void func_151617E4(void *);

void func_15190490(void *arg0) {
    func_15190454(arg0);
    func_151617E4(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1BA1D0/func_151904BC.s")

struct tmp15190518 {
    s32 unk0;
    s8  unk4;
};

void func_15190518(void *arg0) {
    struct tmp15190518 tmp;

    tmp.unk0 = (s32)arg0;
    tmp.unk4 = *(u8 *)((char *)arg0 + 0x3B);

    func_1516944C(0x3E, (s32)&tmp, 0x2A);
}

extern void func_151D33FC(void *, s32);
extern void (*D_8008D684[])(void *, s32, u8);

void func_15190550(void *arg0, s32 arg1, u8 arg2) {
    void (*fn)(void *, s32, u8);

    if (arg2 == 0x2A) {
        func_151D33FC(arg0, arg1);
    }
    fn = D_8008D684[*(u8 *)((char *)arg0 + 0x8A)];
    if (fn != NULL) {
        fn(arg0, arg1, arg2);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1BA1D0/func_151905BC.s")

void func_151906C4(void *arg0) {
    u8 *temp;
    temp = *(u8 **)(*(u8 **)((u8 *)arg0 + 0x10) + 0x31C);
    if (temp != NULL) {
        temp[0x1AC] = 0;
    }
}

void func_151906E0(void *arg0, s32 *arg1, u8 arg2) {
    s32 *ptr;
    s32 temp;

    ptr = (s32 *)((char *)arg0 + 0x90);
    if (arg2 == 0x2D) {
        temp = arg1[0];
        if (temp == ptr[2]) {
            ptr[2] = arg1[1];
        } else if (arg1[1] == ptr[2]) {
            ptr[2] = temp;
        }
    }
}

extern void func_151D343C(void *, s32);
extern void func_1518F45C(void *, s32);

struct tmp1519072C {
    s32 unk0;
    s8  unk4;
};

void func_1519072C(void *arg0) {
    struct tmp1519072C tmp;
    struct tmp1519072C *p;
    struct tmp1519072C **pp;

    tmp.unk0 = (s32)arg0;
    tmp.unk4 = *(u8 *)((char *)arg0 + 0x3B);
    pp = &p;
    p = &tmp;

    func_151D343C(*pp, 0x2A);
    func_1518F45C(*pp, 0x49);
}

extern void func_15191B8C(s32, u8);
extern u8 func_151D8E20(void);

struct Struct15190770Local {
    s32 unk0;
    u8 unk4;
    u8 pad5[0x3];
};

void *func_15190770(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    void *temp_s0;
    struct Struct15190770Local sp2C;
    void *sp38;

    sp2C.unk0 = *(s32 *)arg0;
    sp2C.unk4 = *(u8 *)(*(s32 *)arg0 + 0x3B);
    sp38 = arg0;
    func_15191B8C((s32)&sp2C, 0xE);
    temp_s0 = func_15167A68(0x20, arg3, arg1 + 0x300, 1, (u8)arg2, 1);
    if (temp_s0 == 0) {
        return NULL;
    }
    memcpy((s32)temp_s0 + 0x10, sp38, 0xC);
    *(void **)((s32)temp_s0 + 0x24) = (void *)((s32)temp_s0 + 0x30);
    *(void **)((s32)temp_s0 + 0x28) = (void *)((s32)temp_s0 + 0x300);
    *(s32 *)((s32)temp_s0 + 0x20) = 0;
    *(f32 *)((s32)temp_s0 + 0x1C) = 0.0f;
    bzero((s32)temp_s0 + 0x30, 0x2D0);
    *(u8 *)((s32)temp_s0 + 0x2C) = func_151D8E20();
    return temp_s0;
}

extern void func_15191400(void *);

void func_15190840(void *arg0) {
    func_15191400(arg0);
    func_15169804(arg0);
}

void func_1519086C(void *arg0) {
    func_15191400(arg0);
    func_15169824(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1BA1D0/func_15190898.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1BA1D0/func_15190F9C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1BA1D0/func_1519108C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1BA1D0/func_15191400.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1BA1D0/func_15191520.s")

s32 func_1519187C(void *arg0)
{
  s16 v0;
  s32 v1;
  v0 = *((s16 *) (((u8 *) arg0) + 0x1C));
  if (v0 < (*((s16 *) (((0, (u8 *) arg0)) + 0x124))))
  {
    v1 = v0;
    v1 *= *((s16 *) (((u8 *) arg0) + 0x126));
    if (v1 < (*((u8 *) (((u8 *) arg0) + 0x5C))))
    {
      *((u8 *) (((u8 *) arg0) + 0x5C)) = v1;
    }
  }
  return 1;
}


#pragma GLOBAL_ASM("asm/nonmatchings/game_1BA1D0/func_151918BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1BA1D0/func_15191980.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1BA1D0/func_15191A84.s")

extern s32 D_800A8010;

void func_15191B8C(s32 arg0, u8 arg1) {
    s32 sp1C;

    sp1C = D_800A8010;
    func_151494E0(arg0, arg1);
    func_15169260((s32)&sp1C, 1, arg0, arg1);
}
