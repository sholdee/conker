#include <ultra64.h>
#define func_15169260 func_15169260_s32
#include "functions.h"
#undef func_15169260
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_135D00/func_15108850.s")

extern f32 D_800BE9A4;
extern f32 D_800A2470;
extern f32 D_800A2474;
extern f32 D_800A2478;
extern f32 D_800A247C;
extern f32 D_800A2480;
extern f32 D_800A2484;
extern f32 D_800A2488;
extern f32 D_800A248C;
f32 sinf(f32);
f32 func_15144B68(f32);
struct Arg0_15108AB4;
void func_15108B80(struct Arg0_15108AB4 *);

struct Arg0_15108BC0;
void func_15108BC0(struct Arg0_15108BC0 *arg0);

struct Data_151090DC {
    s32 unk0;
    s32 unk4;
};
extern struct Data_151090DC D_80088C58;
void func_15169260(struct Data_151090DC *, s32, s32, u8);

struct Arg0_15108AB4 {
    u8 pad[0x50];
    s32 off;
};

s32 func_15108AB4(struct Arg0_15108AB4 *arg0) {
    u8 *v0 = (((u8 *)arg0) + arg0->off) + 0xF8;

    *(f32 *)(v0 + 0x8) = *(f32 *)(v0 + 0x8) + D_800A2470 * D_800BE9A4;
    *(f32 *)(v0 + 0xC) = *(f32 *)(v0 + 0xC) + D_800A2474 * D_800BE9A4;
    *(f32 *)(v0 + 0x8) = func_15144B68(*(f32 *)(v0 + 0x8));
    *(f32 *)(v0 + 0xC) = func_15144B68(*(f32 *)(v0 + 0xC));
    *(f32 *)(v0 + 0x0) = sinf(*(f32 *)(v0 + 0x8)) * D_800A2478;
    *(f32 *)(v0 + 0x4) = sinf(*(f32 *)(v0 + 0xC)) * D_800A247C;
    func_15108B80(arg0);
    func_15108BC0((struct Arg0_15108BC0 *)arg0);
    return 1;
}

void func_15108B80(struct Arg0_15108AB4 *arg0) {
    s32 *p;

    p = (s32*)((u8*)arg0 + arg0->off);
    if ((p = (s32*)((u8*)p + 0xF8), 0x3E7) == p[0x14/4]) {
    } else {
        if ((p[0x1C/4] -= D_800BE9E4) < 0) {
            p[0x14/4] = 0x3E7;
        }
    }
}

struct Arg0_15108BC0 {
    u8 pad[0x50];
    s32 off;
};

void func_15108BC0(struct Arg0_15108BC0 *arg0) {
    u8 *v0 = (u8 *)arg0 + arg0->off;
    s32 v1 = *(s32 *)(v0 + 0x10C);

    v0 += 0xF8;
    if (v1 == 0x3E7) {
        *(f32 *)(v0 + 0x10) = 226.0f;
        return;
    }
    if (D_800C35EA == 1) {
        struct233 **tmp = &D_800C3958;
        struct233 *e = *tmp + v1;
        *(f32 *)(v0 + 0x10) = e->unk4;
    } else {
        *(f32 *)(v0 + 0x10) = 226.0f;
    }
}

s32 func_15108C38(struct Arg0_15108AB4 *arg0) {
    u8 *v0 = (((u8 *)arg0) + arg0->off) + 0xF8;

    *(f32 *)(v0 + 0x8) = *(f32 *)(v0 + 0x8) + D_800A2480 * D_800BE9A4;
    *(f32 *)(v0 + 0xC) = *(f32 *)(v0 + 0xC) + D_800A2484 * D_800BE9A4;
    *(f32 *)(v0 + 0x8) = func_15144B68(*(f32 *)(v0 + 0x8));
    *(f32 *)(v0 + 0xC) = func_15144B68(*(f32 *)(v0 + 0xC));
    *(f32 *)(v0 + 0x0) = sinf(*(f32 *)(v0 + 0x8)) * D_800A2488;
    *(f32 *)(v0 + 0x4) = sinf(*(f32 *)(v0 + 0xC)) * D_800A248C;
    func_15108B80(arg0);
    func_15108BC0((struct Arg0_15108BC0 *)arg0);
    if (*(u8 *)(v0 + 0x20) != 0) {
        *(u8 *)((u8 *)arg0 + 0x12) = 4;
    } else {
        *(u8 *)((u8 *)arg0 + 0x12) = 2;
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_135D00/func_15108D24.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_135D00/func_15108E10.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_135D00/func_15108FFC.s")

struct Arg0_15109064
{
  u8 pad[0x50];
  s32 off;
};
void func_15109064(struct Arg0_15109064 *arg0, s32 *arg1, u8 arg2)
{
  u8 *v0 = (((u8 *) arg0) + arg0->off) + 0xF8;
  u8 *new_var;
  switch (arg2)
  {
    case 0x1D:
      *((s32 *) (v0 + 0x14)) = arg1[0];
      *((u8 *) (v0 + 0x18)) = *((u8 *) (((u8 *) arg1) + 0x8));
      *((s32 *) (v0 + 0x1C)) = arg1[1];
 goto dummy_label_480240; dummy_label_480240: ;
      break;

    case 0x1E:
      if ((*((u8 *) (new_var = v0 + 0x20))) != 0)
    {
      *((u8 *) new_var) = 0;
    }
    else
    {
      *((u8 *) (v0 + 0x20)) = 1;
    }
      break;

  }

}


void func_151090DC(void) {
    struct Data_151090DC sp18;

    sp18 = D_80088C58;
    func_15169260(&sp18, 2, 0, 0x1E);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_135D00/func_15109120.s")
