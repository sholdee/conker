#include <ultra64.h>
#include "functions.h"
#include "variables.h"


f32 func_150AD900(f32 *a, f32 *b) {
    return a[0] * b[0] + a[1] * b[1] + a[2] * b[2];
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_DADB0/func_150AD930.s")
