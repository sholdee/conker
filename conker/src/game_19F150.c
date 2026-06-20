#include <ultra64.h>
#include "functions.h"
#include "variables.h"


struct Obj15171CA0 {
    char pad0[0x16];
    s16 unk16;
    char pad18[0x26 - 0x18];
    s16 unk26;
    char pad28[0x36 - 0x28];
    s16 unk36;
    char pad38[0x46 - 0x38];
    s16 unk46;
    char pad48[0x50 - 0x48];
    s16 unk50;
    s16 unk52;
    s16 unk54;
    s16 unk56;
    u8  unk58;
    u8  unk59;
};

extern struct Obj15171CA0 *func_15167A68(s32, s32, s32, s32, s32, s32);

struct Obj15171CA0 *func_15171CA0(s16 arg0, u16 arg1, u8 arg2, s32 arg3, s32 arg4, s32 arg5, u8 arg6, s32 arg7) {
    struct Obj15171CA0 *ret = func_15167A68(arg5 == 0 ? 0xF : 0x43, arg7, 0x60, 1, arg6, 1);
    if (ret == 0) {
        return NULL;
    }
    ret->unk50 = arg0;
    ret->unk52 = 0;
    ret->unk54 = arg4;
    ret->unk56 = arg1;
    ret->unk58 = arg2;
    ret->unk59 = arg3;
    ret->unk16 = 0;
    ret->unk26 = 0;
    ret->unk36 = 0;
    ret->unk46 = 0;
    return ret;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_19F150/func_15171D4C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_19F150/func_15171F04.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_19F150/func_15171FC0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_19F150/func_151720C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_19F150/func_151725FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_19F150/func_15172B20.s")
