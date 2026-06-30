#include <ultra64.h>
#include "functions.h"
#include "variables.h"


extern f32 D_800BE9A4;
typedef struct 
{
  u8 pad0[0x24];
  s32 unk24;
  f32 unk28;
} struct_1512D390_69C;
extern f32 D_800A36E0;
void func_1508EF80(struct17 *arg0, struct17 *arg1, f32 arg2, struct17 *arg3);
void func_1512D390(struct108 *arg0)
{
  struct_1512D390_69C *temp_v0;
  struct17 *temp_a0;
  f32 temp_f0;
  f32 var_f2;
  u16 flags;
  flags = *arg0->unk36C;
  temp_v0 = (struct_1512D390_69C *) (((s32) arg0) + 0x69C);
  if (((flags & 3) != 0) && ((arg0->unk84 << 10) >= 0))
  {
    if (arg0->unk698 != 0)
    {
      return;
    }
    if (flags & 1)
    {
      arg0->unk6B0 = 1;
    }
    else
    {
      arg0->unk6B0 = -1;
    }
    var_f2 = -10.0f;
    temp_v0->unk24++;
    temp_v0->unk28 += (((f32) arg0->unk6B0) * 0.5f) * D_800BE9A4;
    temp_f0 = temp_v0->unk28;
    if (temp_f0 < (-10.0f))
    {
      temp_v0->unk28 = var_f2;
    }
    else
    {
      if (10.0f < temp_f0)
      {
        var_f2 = 10.0f;
      }
      else
      {
        var_f2 = temp_f0;
      }
      temp_v0->unk28 = var_f2;
    }
    if (arg0->unk2C & 0x400)
    {
      temp_v0->unk24 = 20;
      return;
    }
    temp_a0 = (struct17 *) (&arg0->unk2F8);
    func_1508EF80(temp_a0, (struct17 *) (&arg0->unk2A4), (temp_v0->unk28 * D_800BE9A4) / 2.5f, temp_a0);
  }
  else
  {
    ;
    if (temp_v0->unk28 != 0.0f)
    {
      temp_a0 = (struct17 *) (&arg0->unk2F8);
      temp_v0->unk28 = temp_v0->unk28 - ((temp_v0->unk28 * D_800A36E0) * D_800BE9A4);
      func_1508EF80(temp_a0, (struct17 *) (&arg0->unk2A4), (temp_v0->unk28 * D_800BE9A4) / 2.5f, temp_a0);
    }
  }
}

