#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_61D10/func_15034860.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_61D10/func_15034EB4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_61D10/func_15034F20.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_61D10/func_15034F30.s")

extern u8 D_800C3F00;
struct Foo
{
  u8 unk0[12];
};
extern struct Foo D_800C3F08[];
struct Foo *func_150356C8(void)
{
  int new_var;
  u8 temp = D_800C3F00;
  if (1)
  {
    if (temp == 15)
    {
      return 0;
    }
    temp = temp + 1;
    new_var = temp;
    D_800C3F00 = new_var;
  }
  return (struct Foo *) ((((u8 *) D_800C3F08) + (((u8) new_var) * 12)) - 12);
}


#pragma GLOBAL_ASM("asm/nonmatchings/game_61D10/func_15035714.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_61D10/func_15035808.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_61D10/func_15035D6C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_61D10/func_15035FE8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_61D10/func_15036148.s")
