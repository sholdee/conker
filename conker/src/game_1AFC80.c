#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern u8 D_800DDE54[];
extern u8 D_8008D058[];

#pragma GLOBAL_ASM("asm/nonmatchings/game_1AFC80/func_151827D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1AFC80/func_15182C5C.s")

f32 func_15182F58(s32 arg0, s32 arg1) {
    f32 var_f0;
    f32 var_f2;

    var_f0 = 0.0f;
    var_f2 = *(f32 *) &D_8008D058[D_800DDE54[arg1] * 0x18] * (f32) (arg0 * 0x28);
    if (var_f2 < var_f0) {
        var_f2 = var_f0;
    } else {
        var_f0 = 39.0f;
        if (var_f0 < var_f2) {
            var_f2 = var_f0;
        }
    }
    return var_f2;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1AFC80/func_15182FDC.s")
