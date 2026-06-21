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

#pragma GLOBAL_ASM("asm/nonmatchings/game_1A6360/func_15179600.s")

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
