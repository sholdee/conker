#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern u8 D_800DCDE0[0x60];


#pragma GLOBAL_ASM("asm/nonmatchings/game_191C30/func_15164780.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_191C30/func_15164888.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_191C30/func_1516489C.s")

void func_15164EE4(void) {
    bzero(D_800DCDE0, 0x60);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_191C30/func_15164F0C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_191C30/func_15165628.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_191C30/func_151658DC.s")

void func_15165BB0(s32 *arg0, s32 *arg1, s32 arg2, s32 arg3, f32 arg4);

void func_15165B80(s32 *arg0) {
    func_15165BB0(arg0, (s32 *)((s32)arg0 + 0x108), arg0[0x45], arg0[0x46], *(f32 *)((s32)arg0 + 0x11C));
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_191C30/func_15165BB0.s")
