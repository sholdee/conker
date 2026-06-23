#include <ultra64.h>
#include "functions.h"
#include "variables.h"

typedef struct {
    u16 field_0x0;
    u16 field_0x2;
    u16 field_0x4;
    u16 field_0x6;
    u16 field_0x8;
    u16 field_0xa;
    u16 field_0xc;
    u16 field_0xe;
} Struct1508108C;

extern u16 D_8009BD30;
extern u16 D_8009BD34;
extern u16 D_8009BD38;
extern Struct1508108C D_8009BD3C[];


#pragma GLOBAL_ASM("asm/nonmatchings/game_AE1D0/func_15080D20.s")

s32 func_1508108C(Struct1508108C *arg0) {
    s32 temp_v0;
    s32 var_v1;
    s32 var_a1;

    if ((temp_v0 = ((u8 *)arg0)[4]) == D_8009BD30) {
        return 0;
    }
    if (temp_v0 == D_8009BD34) {
        return 1;
    }
    arg0 = D_8009BD3C;
    var_v1 = 3;
    if (temp_v0 == D_8009BD38) {
        return 2;
    }
    var_a1 = 0x17;

loop:
    if (temp_v0 == arg0->field_0x0) {
        return var_v1;
    }
    if (temp_v0 == arg0->field_0x4) {
        return var_v1 + 1;
    }
    if (temp_v0 == arg0->field_0x8) {
        return var_v1 + 2;
    }
    if (temp_v0 == arg0->field_0xc) {
        return var_v1 + 3;
    }
    var_v1 += 4;
    arg0++;
    if (var_v1 != var_a1) {
        goto loop;
    }

    return -1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_AE1D0/func_1508114C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_AE1D0/func_15081574.s")
