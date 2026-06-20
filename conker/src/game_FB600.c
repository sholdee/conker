#include <ultra64.h>
#include "functions.h"
#include "variables.h"


extern void *func_1515FF74(void *, s32, u8, s32);
extern f32 D_800A07FC;
struct Sub150CE150
{
  s8 unk0;
  s8 unk1;
  s8 unk2;
  s8 pad3;
  s16 unk4;
  s8 unk6;
  s8 pad7;
};
struct Buf150CE150
{
  void *unk0;
  u8 unk4;
  s8 pad5;
  s8 pad6;
  s8 pad7;
  f32 unk8;
  f32 unkC;
  s32 unk10;
  s8 unk14;
  char pad15[0x8F0 - 0x15];
};
void *func_150CE150(void *arg0, s16 arg1, u8 arg2, s32 arg3)
{
  struct Sub150CE150 sp910;
  struct Buf150CE150 sp20;
  void *temp_v0;
  if (arg0 == 0)
  {
    return 0;
    return temp_v0;
  }
  sp20.unk8 = D_800A07FC;
  sp910.unk0 = 1;
  sp910.unk1 = 1;
  sp910.unk2 = 0;
  sp910.unk4 = arg1;
  sp910.unk6 = 2;
  sp20.unk10 = 0x2710;
  sp20.unk14 = 0;
  sp20.unkC = D_800A07FC;
  sp20.unk0 = arg0;
  sp20.unk4 = *((u8 *) (((s32) arg0) + 0x3B));
  temp_v0 = func_1515FF74(&sp910, 0x8F0, arg2, arg3);
  if (temp_v0 != 0)
  {
    temp_v0 = memcpy((void *) (((s32) temp_v0) + 0x18), &sp20, 0x8F0);
  }
}


#pragma GLOBAL_ASM("asm/nonmatchings/game_FB600/func_150CE200.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_FB600/func_150CE450.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_FB600/func_150CE694.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_FB600/func_150CE740.s")
