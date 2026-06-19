#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_1D0840/func_151A3390.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D0840/func_151A3504.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D0840/func_151A361C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D0840/func_151A37C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D0840/func_151A3BE4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D0840/func_151A4590.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D0840/func_151A4638.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D0840/func_151A483C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D0840/func_151A4900.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D0840/func_151A499C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D0840/func_151A4A38.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D0840/func_151A4CE0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D0840/func_151A4D88.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D0840/func_151A4E34.s")

void func_151A4E9C(void *arg0)
{
  u8 *p;
  u8 v;
  int new_var;
  *((u8 *) (((u8 *) arg0) + 0x30)) = 0;
  *((u16 *) (((u8 *) arg0) + 0x1E)) &= 0xFFFD;
 new_var = 0xFFu; do { p = *((u8 **) (((u8 *) arg0) + 0x98)); v = (p[0x30] & new_var) | 1; *(p + 0x30) = v; *((volatile u8 *) (p + 0x30)) = v | 4; } while (0);
}


#pragma GLOBAL_ASM("asm/nonmatchings/game_1D0840/func_151A4ECC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D0840/func_151A4F7C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D0840/func_151A4FD0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D0840/func_151A5070.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D0840/func_151A5130.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D0840/func_151A5170.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D0840/func_151A55D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D0840/func_151A561C.s")
