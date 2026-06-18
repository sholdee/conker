#include <ultra64.h>

#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/init_38E0/func_100038E0.s")
// CLOSE (2026-06-18): body below matches the first 4 instrs exactly (v0 reused
// for the D_80038070 store, driven by `return v`). Only the final store differs:
// IDO constant-propagates v and rematerializes 0xBC000C02 (lui+offset) instead
// of reusing v0. Permuter/CSE-steering candidate.
// s32 func_100038E0(void) {
//     s32 v = 0xBC000C02;
//     D_80038070 = v;
//     D_80038074 = 0x4040;
//     *(s16 *)v = 0x4040;
//     return v;
// }

s32 func_1000390C(void) {
    return 0;
}
