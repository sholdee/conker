#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_126F60/func_150F9AB0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_126F60/func_150F9BB0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_126F60/func_150FA1B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_126F60/func_150FA468.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_126F60/func_150FA520.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_126F60/func_150FAA40.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_126F60/func_150FAAEC.s")

void func_150FACE4(struct102 *arg0, s32 arg1, u8 arg2) {
    switch (arg2) {
        case 0x4E:
        case 0x4F:
            func_1516972C(arg0);
            break;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_126F60/func_150FAD28.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_126F60/func_150FAD78.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_126F60/func_150FADC8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_126F60/func_150FAE18.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_126F60/func_150FB188.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_126F60/func_150FB1E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_126F60/func_150FB240.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_126F60/func_150FB29C.s")

extern void func_150FB240(u8 *arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4);

s32 func_150FB2E0(void *arg0) {
    func_150FB240((u8 *)arg0 + 0x2E, *(s16 *)((u8 *)arg0 + 0x22), *(s16 *)((u8 *)arg0 + 0x70), *(s16 *)((u8 *)arg0 + 0x26), *(s16 *)((u8 *)arg0 + 0x28));
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_126F60/func_150FB324.s")
