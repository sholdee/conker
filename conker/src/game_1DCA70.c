#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_1DCA70/func_151AF5C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1DCA70/func_151AF6C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1DCA70/func_151AF6D4.s")

s32 func_151AFBD4(void *arg0) {
    s32 v0 = *(s16 *)((u8 *)arg0 + 0x1C);
    s32 v1;
    if (v0 < 0x20) {
        v1 = v0 * 8;
        if (v1 < *(u8 *)((u8 *)arg0 + 0x28)) {
            *(u8 *)((u8 *)arg0 + 0x28) = v1;
        }
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1DCA70/func_151AFC08.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1DCA70/func_151AFC88.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1DCA70/func_151AFEA4.s")
