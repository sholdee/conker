#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void func_1518E308(void *);
extern f32 D_800A8004;
extern f32 D_800A7B68;
extern f32 D_800A7B6C;
extern f32 D_800A7B70;
extern struct225 *func_151602C0(Header *, Header2 *, s32, s32, s32, s32, u8, u8, s32, u8, s32);

#pragma GLOBAL_ASM("asm/nonmatchings/game_1BA1D0/func_1518CD20.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1BA1D0/func_1518D1C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1BA1D0/func_1518D6E0.s")

struct Struct1518E298Inner {
    s32 unk0;
    u8 pad4[0x10];
    f32 unk14;
    f32 unk18;
    f32 unk1C;
};

struct Struct1518E298 {
    u8 pad0[2];
    s16 unk2;
    s16 unk4;
    s16 unk6;
    u8 pad8[0x14];
    struct Struct1518E298Inner *unk1C;
};

s32 func_1518E298(struct Struct1518E298 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    struct Struct1518E298Inner *temp_v1;

    temp_v1 = arg0->unk1C;
    if (temp_v1 != 0) {
        if (temp_v1->unk0 != 0) {
            arg0->unk2 = temp_v1->unk14;
            arg0->unk4 = temp_v1->unk18;
            arg0->unk6 = temp_v1->unk1C;
            return 0;
        }
    }

    return 1;
}

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

void func_1518E524(u8 *arg0, u8 *arg1, u8 *arg2, u8 *arg3, u8 *arg4, u8 *arg5, s16 *arg6) {
    s32 temp;

    *arg1 = 2;
    if (func_150ADA20() & 1) {
        *arg1 |= 1;
    }

    temp = func_150ADA20() & 1;
    switch (temp) {
    case 0:
        *arg0 = 0x13;
        break;
    case 1:
        *arg0 = 0x14;
        break;
    }

    *arg2 = 0;
    *arg3 = 0;
    *arg4 = 0;
    *arg5 = 0xFF;
    *arg6 = 0x301;
}

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


struct Struct1518F108 {
    char pad1C[0x1C];
    s16 unk1C;
    char pad1E[0xE];
    f32 unk2C;
    f32 unk30;
    char pad34[0x28];
    u8 unk5C;
    char pad5D[0xF7];
    f32 unk154;
    s16 unk158;
    s16 unk15A;
};

s32 func_1518F108(struct Struct1518F108 *arg0) {
    arg0->unk30 = arg0->unk30 - arg0->unk30 * arg0->unk154;
    arg0->unk2C = arg0->unk2C - arg0->unk2C * arg0->unk154;
    if (arg0->unk1C < arg0->unk158) {
        arg0->unk5C = arg0->unk1C * arg0->unk15A;
    }
    return 1;
}

s32 func_1518F15C(void *arg0) {
    f32 temp;

    temp = *(f32 *)((char *)arg0 + 0x30);
    *(f32 *)((char *)arg0 + 0x30) = temp - *(f32 *)((char *)arg0 + 0x154) * *(f32 *)((char *)arg0 + 0x30);
    if (*(s16 *)((char *)arg0 + 0x1C) < *(s16 *)((char *)arg0 + 0x158)) {
        *(u8 *)((char *)arg0 + 0x5C) = *(s16 *)((char *)arg0 + 0x15A) * *(s16 *)((char *)arg0 + 0x1C);
    }
    return 1;
}

struct Struct1518F1A0Obj {
    char pad0[0x24];
    s32 unk24;
    char pad28[0x4];
    f32 unk2C;
    f32 unk30;
};

struct Struct1518F1A0Sub {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    f32 unk14;
    f32 unk18;
    s16 unk1C;
    s16 unk1E;
    f32 unk20;
    f32 unk24;
    f32 unk28;
    s16 unk2C;
};

s32 func_1518F1A0(struct Struct1518F1A0Obj *arg0) {
    struct Struct1518F1A0Sub *sub;
    s32 temp_v1;

    sub = (struct Struct1518F1A0Sub *)((u8 *)arg0 + 0x110);
    sub->unk1E -= D_800BE9E4;
    if (sub->unk1E < 0) {
        sub->unk1E = (u32) func_150ADA20() % 6;
        if (func_150ADA20() & 3) {
            sub->unk18 = (func_150ADA68() * (sub->unkC - sub->unk10)) + sub->unk10;
        } else {
            sub->unk18 = (func_150ADA68() * (sub->unk14 - sub->unkC)) + sub->unkC;
        }
    }
    arg0->unk30 = arg0->unk30 + ((sub->unk18 - arg0->unk30) * D_800A7B68);
    sub->unk1C -= D_800BE9E4;
    if (sub->unk1C < 0) {
        sub->unk1C = (u32) func_150ADA20() % 0x11;
        sub->unk8 = (func_150ADA68() * (sub->unk0 - sub->unk4)) + sub->unk4;
    }
    arg0->unk2C = arg0->unk2C + ((sub->unk8 - arg0->unk2C) * D_800A7B6C);
    sub->unk2C -= D_800BE9E4;
    if (sub->unk2C < 0) {
        sub->unk2C = (u32) func_150ADA20() % 0xF;
        sub->unk28 = (func_150ADA68() * (sub->unk20 - sub->unk24)) + sub->unk24;
    }
    temp_v1 = arg0->unk24;
    arg0->unk24 += (s32)((sub->unk28 - (f32) temp_v1) * D_800A7B70);
    return 1;
}

extern f32 func_150ADA68(void);
extern f32 D_800A7B74;
extern f32 D_800A7B78;

struct Struct1518F384 {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    char pad14[0x4];
    f32 unk18;
    s16 unk1C;
    s16 unk1E;
};

s32 func_1518F384(void *arg0) {
    struct Struct1518F384 *p;

    p = (struct Struct1518F384 *)((char *)arg0 + 0x110);
    if (p->unk1C == 0) {
        p->unk8 = func_150ADA68() * (p->unk0 - p->unk4) + p->unk4;
        p->unk1C = 1;
        p = (struct Struct1518F384 *)((char *)arg0 + 0x110);
    }
    if (p->unk1E == 0) {
        p->unk18 = func_150ADA68() * (p->unkC - p->unk10) + p->unk10;
        p->unk1E = 1;
    }
    *(f32 *)((char *)arg0 + 0x30) += (p->unk18 - *(f32 *)((char *)arg0 + 0x30)) * D_800A7B74;
    *(f32 *)((char *)arg0 + 0x2C) += (p->unk8 - *(f32 *)((char *)arg0 + 0x2C)) * D_800A7B78;
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1BA1D0/func_1518F45C.s")

struct Struct1518F49C {
    s32 unk0;
    u8 unk4;
};

void func_1518F49C(void *arg0, struct Struct1518F49C *arg1, u8 arg2) {
    func_15169850((s32)arg1, arg2, (s32)arg0 + 0x18, (s32)arg0 + 0x1C, (s32)arg0);
    if (arg2 == 0x49) {
        s32 a = *(s32 *)((char *)arg0 + 0x18);
        s32 b = arg1->unk0;
        u8 c = *(u8 *)((char *)arg0 + 0x1C);
        u8 d = arg1->unk4;
        if (a == b || c == d) {
            func_1516972C(arg0);
        }
    }
}

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

extern f32 func_150ADA68(void);
extern f32 D_800BE9A4;
extern s32 (*D_8008D67C[])(void *);
extern void func_1518F8E0(void *);

struct Obj7C4 { f32 unk0; f32 unk4; f32 unk8; char pad[0x4C]; s8 unk58; };

s32 func_1518F7C4(void *arg0) {
    struct Obj7C4 *p;

    p = (struct Obj7C4 *)((char *)arg0 + 0x30);
    p->unk0 += (p->unk4 + func_150ADA68() * p->unk8) * D_800BE9A4;
    func_1518F8E0(arg0);
    if (p->unk58 != -1) {
        return D_8008D67C[p->unk58](arg0);
    }
    return 1;
}

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

struct Struct1519021CArg1 {
    u8 pad0[0x14];
    f32 unk14;
    f32 unk18;
    f32 unk1C;
    u8 pad20[0x1B];
    u8 unk3B;
};

struct Struct1519021CData {
    struct Struct1519021CArg1 *unk0;
    u8 unk4;
    u8 pad5[3];
};

struct Struct1519021CLocal {
    s32 unk0;
    f32 unk4[8];
    struct Struct1519021CData unk24;
    Header unk2C;
    s32 pad34;
};

struct225 *func_1519021C(s32 arg0, struct Struct1519021CArg1 *arg1, u8 arg2, s16 arg3, u8 arg4, s32 arg5) {
    struct Struct1519021CLocal sp58;
    Header2 header2;
    struct225 *temp_v0;

    if (arg2 >= 0x18) {
        return 0;
    }

    sp58.unk4[0] = D_800A67C0[arg2];
    sp58.unk4[1] = D_800A6760[arg2];
    sp58.unk4[2] = D_800A6820[arg2];
    sp58.unk4[3] = 1.0f;
    sp58.unk4[5] = 5.0f;
    sp58.unk4[4] = 0.0f;
    sp58.unk4[7] = 0.0f;
    sp58.unk4[6] = D_800A8004;
    sp58.unk0 = arg0;

    sp58.unk2C.unk0 = ((arg3 == -1) ? 0 : 1) | 2;
    sp58.unk2C.unk1 = 0x12;
    if (arg3 == -1) {
        sp58.unk2C.unk2 = 0x12C;
    } else {
        sp58.unk2C.unk2 = arg3;
    }
    sp58.unk2C.unk4 = 0x25;

    sp58.unk24.unk0 = arg1;
    sp58.unk24.unk4 = arg1->unk3B;

    header2.unk0 = arg1->unk14;
    header2.unk4 = arg1->unk18;
    header2.unk8 = arg1->unk1C;

    temp_v0 = func_151602C0(&sp58.unk2C, &header2, 0, 0xFF, 0xD1, 0, 0xFF, 0, 0x30, arg4, arg5);
    if (temp_v0 != 0) {
        memcpy((s32)temp_v0 + 0x18, &sp58.unk24, sizeof(sp58.unk24));
        memcpy((s32)temp_v0 + 0x20, sp58.unk4, sizeof(sp58.unk4));
        memcpy((s32)temp_v0 + 0x40, &sp58.unk0, sizeof(sp58.unk0));
    }
    return temp_v0;
}

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

extern s32 func_1505D024(void *, s32, u16, s32);

struct Struct151905BC {
    u8  pad0[0x10];
    u8  *unk10;
    u8  pad14[0x7C];
    s32 unk90;
    s32 unk94;
    struct127 *unk98;
};

s32 func_151905BC(struct Struct151905BC *arg0) {
    s32 *p;
    u8 *temp;

    arg0->unk94 += D_800BE9E4;
    p = &arg0->unk90;
    while (p[1] >= p[0]) {
        func_1505D024(arg0->unk10, 0x60021, 0, (struct127 *)p[2] - D_800CC2D0);
        p[1] -= p[0];
    }
    temp = *(u8 **)(arg0->unk10 + 0x31C);
    if (temp != NULL) {
        if (temp[0x84] == 0) {
            *(s16 *)(temp + 0x46) = 0x3E8;
        }
    }
    return 1;
}

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

struct OscillatorMotionState {
    u8 pad_0x0[0x21];
    u8 field_0x21;
    u8 field_0x22;
    s8 field_0x23;
    s8 field_0x24;
    u8 pad_0x25[0x3];
    f32 field_0x28;
    f32 field_0x2C;
    f32 field_0x30;
    f32 field_0x34;
};

struct OscillatorObject {
    u8 pad_0x0[0x2C];
    f32 field_0x2C;
    f32 field_0x30;
    u8 pad_0x34[0xDC];
    struct OscillatorMotionState field_0x110;
};

s32 func_15190F9C(struct OscillatorObject *arg0) {
    struct OscillatorObject *p = arg0;
    struct OscillatorMotionState *f = &arg0->field_0x110;
    f32 r1;
    f32 r2;

    f->field_0x21 = f->field_0x21 + f->field_0x23 * D_800BE9E4;
    f->field_0x22 = f->field_0x22 + f->field_0x24 * D_800BE9E4;
    r1 = func_151423D8((u8)(f->field_0x21 - 0x40));
    r2 = func_151423D8((u8)(f->field_0x22 - 0x40));
    p->field_0x2C += (f->field_0x28 + f->field_0x30 * r1 - p->field_0x2C) * 0.5f;
    p->field_0x30 += (f->field_0x2C + f->field_0x34 * r2 - p->field_0x30) * 0.5f;
    return 1;
}

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
