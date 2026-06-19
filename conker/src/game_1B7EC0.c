#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_1B7EC0/func_1518AA10.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1B7EC0/func_1518AADC.s")

s32 func_15167A68(s32, s32, s32, s32, s32, s32);

typedef struct {
    u8  pad0[0x10];
    s32 unk10;
    s32 unk14;
    s32 unk18;
    u8  unk1C;
} struct_1518AB60;

struct_1518AB60 *func_1518AB60(s32 arg0, u8 arg1) {
    struct_1518AB60 *ret;

    ret = func_15167A68(0x1E, 0, 0x20, 1, 0xFF, 1);
    if (ret == 0) {
        return NULL;
    }
    ret->unk10 = arg0;
    ret->unk1C = arg1;
    ret->unk14 = 0;
    ret->unk18 = 0;
    return ret;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1B7EC0/func_1518ABD0.s")
