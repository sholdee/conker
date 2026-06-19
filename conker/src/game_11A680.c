#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_11A680/func_150ED1D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_11A680/func_150ED234.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_11A680/func_150ED298.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_11A680/func_150ED578.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_11A680/func_150ED638.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_11A680/func_150ED748.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_11A680/func_150EEC84.s")

extern void func_151045E0(void *, s32, f32);
extern void func_15052590(void);

void func_150EEDA8(u8 *arg0) {
    if (arg0[5] != 3) {
        func_151045E0(arg0, 0xF, 250.0f);
        arg0[5] = 3;
        *(s16 *)(arg0 + 0xE4) = 0;
        arg0[0x125] = 0xFF;
    }
    func_15052590();
}
