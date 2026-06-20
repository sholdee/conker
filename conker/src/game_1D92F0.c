#include <ultra64.h>
#include "functions.h"
#include "variables.h"


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

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D92F0/func_151AC810.s")

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


#pragma GLOBAL_ASM("asm/nonmatchings/game_1D92F0/func_151AE6B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D92F0/func_151AE7B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D92F0/func_151AE890.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D92F0/func_151AF338.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D92F0/func_151AF388.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D92F0/func_151AF4D0.s")
