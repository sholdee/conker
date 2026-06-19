#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_1D4E00/func_151A7950.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D4E00/func_151A7A90.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D4E00/func_151A7D6C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D4E00/func_151A8340.s")

extern void func_151D5E30(void *);

void func_151A8560(void *arg0) {
    func_151D5E30((void *)((u8 *)arg0 + 0x6C));
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D4E00/func_151A8584.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D4E00/func_151A85D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D4E00/func_151A8624.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D4E00/func_151A87F8.s")

extern void (*D_8008F964[])(u8 *, s32, u8);

void func_151A8A20(u8 *arg0, s32 arg1, u8 arg2) {
    s32 idx;

    idx = arg0[0x5C];
    if (idx >= 3) {
        idx = 0;
    }
    if (D_8008F964[idx] != NULL) {
        D_8008F964[idx](arg0, arg1, arg2);
    }
}

typedef struct {
    s32 unk0;
    u8  unk4;
} SubA_151A8A78;

typedef struct {
    s32 unk0;
    union {
        s32 w4;
        u8  b4;
    } u4;
    u8  unk8;
    u8  unk9;
} ArgB_151A8A78;

void func_151A8A78(void *arg0, s32 arg1, u8 arg2) {
    SubA_151A8A78 *temp_v0 = *(SubA_151A8A78 **)((u8 *)arg0 + 0x60);
    ArgB_151A8A78 *b = (ArgB_151A8A78 *)arg1;
    s32 b0;

    if (arg2 == 0) {
        b0 = b->unk0;
        if ((b0 == temp_v0->unk0) || (temp_v0->unk4 == b->u4.b4)) {
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

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D4E00/func_151A8B20.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D4E00/func_151A8CEC.s")

extern void func_151432BC(void *, f32 *, f32 *, f32 *, f32 *);

void func_151A8F1C(void *arg0, f32 *arg1, f32 *arg2, f32 *arg3) {
    func_151432BC(*(void **)((u8 *)arg0 + 0x2C), arg1, arg1 + 2, arg2, arg3);
    arg1[1] = arg2[0];
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D4E00/func_151A8F6C.s")

void func_151A931C(u8 *, s32, u8);

void func_151A9024(u8 *arg0, s32 arg1, u8 arg2) {
    if (arg0[0x4C] == 1) {
        func_151A931C(arg0, arg1, arg2);
    }
}

extern void (*D_8008F984[])(void);
s32 func_151A9060(u8 *arg0)
{
  s32 new_var;
  s32 idx;
  arg0[0x16] |= 0x4;
  new_var = *((s32 *) (arg0 + 0x18));
  idx = new_var & 0xFFFFFFFFu;
  new_var = idx < 0;
  if (new_var || (idx >= 8))
  {
    return 1;
  }
  if (D_8008F984[idx])
  {
    D_8008F984[idx]();
  }
  return 1;
}


#pragma GLOBAL_ASM("asm/nonmatchings/game_1D4E00/func_151A90C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D4E00/func_151A91AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D4E00/func_151A931C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D4E00/func_151A9390.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D4E00/func_151A9634.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D4E00/func_151A9834.s")
