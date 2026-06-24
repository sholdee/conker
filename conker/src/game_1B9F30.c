#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_1B9F30/func_1518CA80.s")

extern void (*D_8008D5D0[])(void);
void func_1518CCA8(u8 *arg0)
{
  s32 temp_t1;
  s32 temp_t4;
  temp_t1 = *((s32 *) (arg0 + 0x14));
  *((s16 *) (arg0 + 0x34)) = (*((s16 *) (arg0 + 0x34))) + ((temp_t1 & 0xFFFF0000) >> 0x10);
  *((s16 *) (arg0 + 0x36)) = (*((s16 *) (arg0 + 0x36))) + (temp_t1 & 0xFFFFu);
  if ((*((s16 *) (arg0 + 0x38))) == 0)
  {
    temp_t4 = arg0[0x3B] & 0xF;
    if (temp_t4 != 0)
    {
      D_8008D5D0[temp_t4]();
    }
  }
}

