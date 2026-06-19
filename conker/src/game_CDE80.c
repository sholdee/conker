#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_CDE80/func_150A09D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_CDE80/func_150A0D14.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_CDE80/func_150A0D8C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_CDE80/func_150A1040.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_CDE80/func_150A104C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_CDE80/func_150A11C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_CDE80/func_150A1DA0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_CDE80/func_150A23E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_CDE80/func_150A24C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_CDE80/func_150A25D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_CDE80/func_150A278C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_CDE80/func_150A2864.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_CDE80/func_150A2940.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_CDE80/func_150A29C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_CDE80/func_150A2AEC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_CDE80/func_150A2CA4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_CDE80/func_150A2D84.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_CDE80/func_150A2E4C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_CDE80/func_150A2EE4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_CDE80/func_150A2FA4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_CDE80/func_150A3058.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_CDE80/func_150A3194.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_CDE80/func_150A32B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_CDE80/func_150A3330.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_CDE80/func_150A3398.s")

void func_150A3444(s32 a0, s16 a1, s16 a2, s16 a3) {
    ((struct178 *)*(s32 *)&D_800D3098)[a0].unk0 = a1;
    *(s16 *)&((struct178 *)*(s32 *)&D_800D3098)[a0].pad2 = a2;
    ((struct178 *)*(s32 *)&D_800D3098)[a0].unk4 = a3;
}

s32 func_150A3504(void);

s32 func_150A34B0(u8 *arg0) {
    s32 ret;

    if (arg0[0x14] == 1) {
        return 0;
    }

    ret = 0;
    if (!(arg0[0x15] & 3)) {
        return func_150A3504();
    }
    return ret;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_CDE80/func_150A3504.s")
