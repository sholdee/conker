#include <ultra64.h>
#include "functions.h"
#include "variables.h"


extern u8 D_800DD432;
extern u8 D_800DD433;
extern u8 D_800DD434;
extern u16 D_800DD436;
extern s32 D_800DD440;
extern u8 D_800DD446;

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

#pragma GLOBAL_ASM("asm/nonmatchings/game_1A6360/func_15179CB0.s")
