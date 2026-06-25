#include <ultra64.h>
#include "functions.h"
#include "variables.h"


extern u8 D_800DD432;
extern u8 D_800DD433;
extern u8 D_800DD434;
extern u16 D_800DD436;
extern s32 D_800DD440;
extern u8 D_800DD446;
extern f32 sqrtf(f32);
void func_1516865C(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
s32 func_15168800(void *arg0, s32 arg1, s32 arg2, s32 arg3);

typedef struct {
    u8 pad0[0x9C];
    s16 unk9C;
    s16 unk9E;
    s16 unkA0;
    u8 padA2[0x12];
    u8 unkB4;
} struct15179CB0;

void func_15178EB0(void) {
    D_800DD434 = 0;
    D_800DD446 = 0;
    D_800DD444 = 0x258;
    D_800DD432 = 0xF0;
    D_800DD433 = 0x14;
    D_800DD436 = 0;
    D_800DD440 = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1A6360/func_15178EFC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1A6360/func_15179008.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1A6360/func_151794C8.s")

void func_15179600(s32 arg0, s32 arg1) {
    typedef struct {
        union {
            void *align;
            u8 bytes[0x80];
        } pad0;
        s32 unk80;
        s16 unk84;
        u8 pad86[4];
        s16 unk8A;
        s16 unk8C;
        s16 unk8E;
        s16 unk90;
        s16 unk92;
        s16 unk94;
        s16 unk96;
        u16 unk98;
        s16 pad9A;
        s16 unk9C;
        s16 unk9E;
        s8 unkA0;
        s8 unkA1;
        s8 unkA2;
        u8 padA3[5];
    } EffectSpawnPacket15179600;

    s32 spF4;
    s32 spF0;
    s32 spEC;
    s32 spE8;
    s32 spE4;
    s32 spE0;
    s32 rand;
    s32 ret;
    s32 pad[2];
    EffectSpawnPacket15179600 packet;

    packet.unkA0 = 0x11;
    packet.unk8A = 0x33;
    packet.unkA2 = 1;
    packet.unk98 = 0;
    func_1516865C(&packet, 0xFF, 0xFF, 0xFF, 0x50);

    spE8 = (s32)D_800DBFF0->unk2F8;
    spE4 = (s32)D_800DBFF0->unk2FC;
    spE0 = (s32)D_800DBFF0->unk300;

    spF4 = (func_150ADA20() % 500) + spE8;
    spEC = (func_150ADA20() % 500) + spE0;
    if (arg0 == 0) {
        spF0 = spE4 + 0x1F4;
    } else {
        spF0 = (func_150ADA20() % 500) + spE4;
    }

    rand = func_150ADA20() % 10U;
    packet.unk9C = 0;
    packet.unk9E = 0;
    packet.unk8E = spF0;
    packet.unk8C = spF4;
    packet.unk90 = spEC;
    packet.unk92 = 4;
    packet.unk94 = rand + 0x23;
    packet.unk98 = 0x8C00;
    packet.unkA1 = rand + 0xA;
    packet.unk80 = arg1;
    packet.unk84 = *(s16 *)&D_800DD436;

    ret = func_15168800(&packet, 0xFF, 0, spF0);
    if (ret != 0) {
        ((s32 *)D_800DD440)[(s16)D_800DD436] = ret;
        D_800DD436 = (s16)D_800DD436 + 1;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1A6360/func_151797B0.s")

extern u16 D_800DD436;
extern s32 D_800DD440;
void func_15179AB8(void)
{
  s32 i;
  s32 off;
  s32 **p;
  int new_var;
  s32 *obj;
  i = ((s16) D_800DD436) - 1;
  new_var = 4;
  if (i < 0)
  {
    return;
  }
  off = i * new_var;
  p = (s32 **) (((u8 *) D_800DD440) + off);
  do
  {
    obj = *p;
    if (obj != 0)
    {
      if (!(obj[36] & 0x2))
      {
        obj[36] |= 0x2;
        return;
      }
    }
    off -= new_var;
    p--;
  }
  while (off >= 0);
}


#pragma GLOBAL_ASM("asm/nonmatchings/game_1A6360/func_15179B14.s")

void func_15179CB0(struct15179CB0 *arg0)
{
    f32 temp_f2;
    f32 temp_f12;
    f32 temp_f0;

    temp_f2 = (f32)arg0->unkA0 - D_800DBFF0->unk300;
    temp_f12 = (f32)arg0->unk9C - D_800DBFF0->unk2F8;
    temp_f0 = sqrtf((temp_f2 * temp_f2) + (temp_f12 * temp_f12));
    arg0->unkB4 = (u32)(255.0f - ((160.0f * temp_f0) / 1000.0f));
}
