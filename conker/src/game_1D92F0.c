#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern f32 D_800A9D84;
extern f32 D_800A9D88;
extern void func_151D5D60();
void func_151AE984(f32 *, f32, f32, f32, s32, u8);
void func_151AEAB4(f32 *, s32, u8);
void func_15143134(f32 *, f32 *, s32);
void func_15135DD0(f32 *, f32 *, f32, u8, s32);
void func_151AF388(f32 *, f32, f32, f32, s32);

typedef struct {
    /* 0x00 */ u8 unk0;
    /* 0x01 */ u8 pad1[3];
    /* 0x04 */ f32 unk4[3];
    /* 0x10 */ f32 unk10[3];
} struct_AF4D0;

extern struct_AF4D0 D_800A9DF0[];
extern f32 D_800AA0E4;

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D92F0/func_151ABE40.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D92F0/func_151AC078.s")

s32 func_151AC3CC(s16 *arg0) {
    u8 *ptr = *(u8 **)((u8 *)arg0 + 0x98);
    s32 val = arg0[0x1C / 2] << 3;
    if (val >= 0x100) {
        val = 0xFF;
    }
    if (val < ptr[0x1B]) {
        ptr[0x1B] = val;
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D92F0/func_151AC408.s")

u8 func_151D8E20(void);

typedef struct {
    /* 0x00 */ f32 unk0;
    /* 0x04 */ f32 unk4;
    /* 0x08 */ f32 unk8;
    /* 0x0C */ f32 unkC;
    /* 0x10 */ f32 unk10;
} struct_AC550;

s32 func_151AC550(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, f32 arg4, s32 arg5) {
    u8 *ptr = *(u8 **)(arg0 + 0x98);
    struct_AC550 *arr = *(struct_AC550 **)(arg0 + 0x94);
    f32 sp34[3];

    sp34[0] = arr[*(s8 *)(arg0 + 0x2D)].unk0;
    sp34[1] = arg4;
    sp34[2] = arr[*(s8 *)(arg0 + 0x2D)].unk8;
    func_151DBCBC(func_151D8E20(), *(f32 *)ptr * 7.0f, ptr[0x1B], arg5, sp34, arg0[0xC], arg0[0x1]);
    ptr[0x20] = 4;
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D92F0/func_151AC61C.s")

struct Foo151AC810 {
    char pad0[0x2C];
    f32 unk2C;
    f32 unk30;
    f32 unk34;
    f32 unk38;
    f32 unk3C;
    char pad40[0xC];
    f32 unk4C;
    f32 unk50;
    char pad54[0x6C];
    char unkC0[0x40];
    s16 *unk100[1];
};

s16 *func_151AC810(struct Foo151AC810 *arg0, s16 arg1) {
    s16 *var_v0;
    s16 *ret;
    f32 temp_f0;
    f32 temp_f14;
    f32 temp_f2;
    f32 temp_f12;
    u8 sp37;

    func_151D5D60(arg0->unk100, arg1, 0x40, &var_v0, &sp37);
    ret = var_v0;
    if (var_v0) {
        if (sp37) {
            memcpy(arg0->unk100[arg1], arg0->unkC0, 0x40);
            memcpy(arg0->unk100[arg1] + 0x20, arg0->unkC0, 0x40);
        }
    } else {
        return 0;
    }

    temp_f0 = arg0->unk2C * arg0->unk4C;
    temp_f14 = arg0->unk30 * arg0->unk50;
    temp_f2 = D_800DD1D8[arg1] * temp_f0;
    temp_f12 = D_800DD1E8[arg1] * temp_f0;

    var_v0[3] = 0;
    var_v0[0xB] = 0;
    var_v0[0x13] = 0;
    var_v0[0x1B] = 0;
    var_v0[0] = var_v0[0x18] = arg0->unk34 + temp_f12;
    var_v0[1] = var_v0[9] = arg0->unk38;
    var_v0[2] = var_v0[0x1A] = arg0->unk3C - temp_f2;
    var_v0[8] = var_v0[0x10] = arg0->unk34 - temp_f12;
    var_v0[0x11] = var_v0[0x19] = arg0->unk38 + temp_f14;
    var_v0[0xA] = var_v0[0x12] = arg0->unk3C + temp_f2;

    return ret;
}

extern f32 D_800BE9A4;

s32 func_151AC9EC(u8 *arg0) {
    f32 temp = *(f32 *)(arg0 + 0x4C) * D_800BE9A4;
    *(f32 *)(arg0 + 0x2C) += temp;
    *(f32 *)(arg0 + 0x30) += temp;
    return 1;
}

s32 func_151ACA20(s16 *arg0) {
    s32 val = 0xFF;
    if (arg0[0x1C / 2] < 0x10) {
        val = (s16)(arg0[0x1C / 2] << 4);
    }
    if (val < ((u8 *)arg0)[0x5C]) {
        ((u8 *)arg0)[0x5C] = val;
    }
    return 1;
}

extern u8 *func_15167A68(s32, s32, s32, s32, s32, s32);
s32 func_151ACB38(u8 *arg0, u8 *arg1);

s32 func_151ACA60(u8 *arg0, f32 arg1, s32 arg2) {
    u8 *temp;

    if (arg0 == 0) {
        return 0;
    }
    temp = func_15167A68(0x30, 0, arg2 + 0x30, 1, 0xFF, 1);
    if (temp == 0) {
        return 0;
    }
    if (func_151ACB38(arg0, temp + 0x18) == 0) {
        func_1516979C((struct102 *)temp);
        return 0;
    }
    *(s32 *)(temp + 0x1C) = (s32)arg0;
    *(u8 *)(temp + 0x20) = arg0[0x3B];
    *(s32 *)(temp + 0x24) = (struct127 *)arg0 - D_800CC2D0;
    *(f32 *)(temp + 0x28) = arg1;
    *(s32 *)(temp + 0x10) = 1;
    *(s32 *)(temp + 0x14) = 0;
    return (s32)temp;
}

s32 func_151ACB38(u8 *arg0, u8 *arg1) {
    s32 ret = 0;
    if (arg0[0x3B] == 1) {
        arg1[0] = 1;
        ret = 1;
    }
    return ret;
}

s32 func_151AE3A8(u8 *arg0);
s32 func_151ACB60(u8 *arg0)
{
  s32 new_var;
  s32 v0 = *((s32 *) ((*((s32 *) ((*((s32 *) (arg0 + 0x1C))) + 0x31C))) + 0x9C));
  if (v0 != 0)
  {
    new_var = func_151AE3A8(arg0);
    if (arg0)
    {
    }
    return new_var;
  }
}


void func_151ACB94(s32 arg0, s32 arg1, u8 arg2) {
    func_15169850(arg1, arg2, arg0 + 0x1C, arg0 + 0x20, arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D92F0/func_151ACBD4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D92F0/func_151AD174.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D92F0/func_151AD92C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D92F0/func_151AE06C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D92F0/func_151AE0E4.s")

extern f32 D_800A9294;

void func_151AE264(u8 *arg0) {
    f32 temp = *(f32 *)(arg0 + 0x3C) * D_800A9294;
    u8 *v0 = *(u8 **)(*(s32 *)(arg0 + 0x31C) + 0x9C);
    *(f32 *)(v0 + 0x4C) = temp;
    *(s8 *)(v0 + 0x50) = *(u16 *)(arg0 + 0x76) >> 8;
    *(s8 *)(v0 + 0x51) = *(u8 *)(*(s32 *)(arg0 + 0x31C) + 0xAE);
    *(s16 *)(v0 + 0x52) = 0x14;
    *(s32 *)(v0 + 0x44) = 0;
    *(s8 *)(*(s32 *)(arg0 + 0x31C) + 0x98) = 0;
    *(s32 *)(*(s32 *)(arg0 + 0x31C) + 0x9C) = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D92F0/func_151AE2BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D92F0/func_151AE3A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D92F0/func_151AE590.s")

void func_151AE640(s32 *arg0, s32 *arg1, u8 arg2)
{
  s32 *ptr = arg0;
  s32 temp;
  if (arg2 == ((unsigned short) 0))
  {
    temp = arg1[0];
    if (temp == ptr[0x11])
    {
      ptr[0x11] = 0;
    }
 dummy_label_988571: ;
  }
  else
    if (arg2 == 0x2D)
  {
    temp = arg1[0];
    if (temp == ptr[0x11])
    {
      ptr[0x11] = arg1[1];
    }
    else
      if (arg1[1] == ptr[0x11])
    {
      ptr[0x11] = temp;
    }
  }
}


extern f32 D_800A9D70;
s32 func_15045800(f32 *arg0, s32 arg1, f32 arg2, s32 arg3);
s32 func_151ABE40(f32 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
s32 func_10010FFC(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);
void func_151AE6B0(u8 *arg0)
{
  u8 *v1 = *((u8 **) (arg0 + 0x18));
  f32 sp30[3];
  s32 temp;
 goto dummy_label_19982; dummy_label_19982: ;
  sp30[0] = *((f32 *) (v1 + 0x14));
  if (D_800A9D70 < (*((f32 *) (v1 + 0x118))))
  {
    sp30[1] = (*((f32 *) (v1 + 0x118))) + 100.0f;
  }
  else
  {
    sp30[1] = (*((f32 *) (v1 + 0x18))) + 150.0f;
  }
  sp30[2] = *((f32 *) (v1 + 0x1C));
  temp = (s32) (arg0 + 0x34);
  if (func_15045800(sp30, 0, sp30[1] - 300.0f, temp) != 0)
  {
    sp30[1] = *((f32 *) (arg0 + 0x34));
    func_151ABE40(sp30, temp, 5, arg0[0xC], arg0[0x1]);
    func_10010FFC(0, 0x11, 0x5208, 0, 0, (s32) v1);
  }
}


#pragma GLOBAL_ASM("asm/nonmatchings/game_1D92F0/func_151AE7B0.s")

void func_151AE890(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, u8 *arg6) {
    f32 sp2C[3];
    register f32 temp_f0;

    sp2C[0] = arg0;
    sp2C[1] = arg1;
    sp2C[2] = arg2;
    temp_f0 = func_150ADA68();
    if (temp_f0 < D_800A9D84) {
        return;
    }
    if (temp_f0 < 0.25f) {
        register s32 temp_a1;

        temp_f0 = func_150ADA68();
        temp_a1 = (0.0f < temp_f0) ? 1 : 0;
        func_151AEAB4(sp2C, temp_a1, arg6[0xC]);
    } else {
        register s32 temp_v0;

        temp_f0 = func_150ADA68();
        temp_v0 = (D_800A9D88 < temp_f0) ? 1 : 0;
        func_151AE984(sp2C, arg3, arg4, arg5, temp_v0, arg6[0xC]);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D92F0/func_151AE984.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D92F0/func_151AEAB4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D92F0/func_151AECA0.s")

typedef struct {
    /* 0x00 */ s32 unk0;
    /* 0x04 */ s32 unk4;
    /* 0x08 */ u8  unk8;
    /* 0x09 */ u8  pad9[0x3];
    /* 0x0C */ struct102 *unkC;
    /* 0x10 */ u8  unk10;
    /* 0x11 */ u8  pad11[0x3];
    /* 0x14 */ f32 unk14;
    /* 0x18 */ f32 unk18;
    /* 0x1C */ f32 unk1C;
    /* 0x20 */ f32 unk20;
    /* 0x24 */ f32 unk24;
    /* 0x28 */ s16 unk28;
    /* 0x2A */ u8  unk2A;
    /* 0x2B */ u8  unk2B;
    /* 0x2C */ s8  unk2C;
    /* 0x2D */ u8  unk2D;
} struct_AF270;

extern f32 D_800A9DCC;
extern f32 D_800A9DD0;
void func_1516962C(s32, struct102 *, s32);
void *func_1513418C(struct_AF270 *, s32, u8, s32);

void *func_151AF270(struct102 *arg0, s32 arg1, s32 arg2) {
    void *result;
    struct_AF270 sp1C;

    if (arg0 == 0) {
        return 0;
    }
    func_1516962C(0x28, arg0, 0x16);
    sp1C.unk0 = 0;
    sp1C.unk4 = 0;
    sp1C.unk8 = *((u8 *)arg0 + 0x3B);
    sp1C.unkC = arg0;
    sp1C.unk10 = 1;
    sp1C.unk14 = 0.0f;
    sp1C.unk18 = 0.0f;
    sp1C.unk1C = 0.0f;
    sp1C.unk20 = D_800A9DCC;
    sp1C.unk24 = D_800A9DD0;
    sp1C.unk2A = 6;
    sp1C.unk28 = 0x140;
    sp1C.unk2B = 0xA;
    sp1C.unk2C = -1;
    sp1C.unk2D = 9;
    result = func_1513418C(&sp1C, 0, (u8)arg1, arg2);
    return result;
}

void func_151AF338(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, void *arg6) {
    f32 sp24[3];

    sp24[0] = arg0;
    sp24[1] = arg1;
    sp24[2] = arg2;
    func_151AF388(sp24, arg3, arg4, arg5, *(u8 *)((s32)arg6 + 0xC));
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D92F0/func_151AF388.s")

void func_151AF4D0(u8 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    f32 sp44[3];
    f32 sp38[3];
    s32 temp_a2;
    struct_AF4D0 *temp_v0;
    s32 temp_v1;

    if (arg0 != 0) {
        temp_v1 = *(s32 *)(arg0 + 0x1D4);
        if (temp_v1 != 0) {
            if ((arg0[0x74] & 0xF) != 0xF) {
                temp_v0 = &D_800A9DF0[(u8)arg1];
                temp_a2 = temp_v1;
                temp_a2 += temp_v0->unk0 << 6;
                func_15143134(temp_v0->unk4, sp44, temp_a2);
                func_15143134(temp_v0->unk10, sp38, temp_a2);
                func_15135DD0(sp44, sp38, ((func_150ADA68() * 170.0f) + 71.0f) * D_800AA0E4, (u8)arg2, arg3);
            }
        }
    }
}
