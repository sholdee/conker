#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern s16 D_800DC204[];
extern s16 D_800DC206[];

#pragma GLOBAL_ASM("asm/nonmatchings/game_157840/func_1512A390.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_157840/func_1512ABF8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_157840/func_1512AD54.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_157840/func_1512B100.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_157840/func_1512B1B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_157840/func_1512B53C.s")

struct Struct1512B5FC {
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 unk3;
    s32 unk4;
    s32 unk8;
};

void func_1512B5FC(struct Struct1512B5FC *arg0, s32 arg1, s32 arg2) {
    arg0->unk2 = arg0->unk1;
    if (arg0->unk4 < arg1) {
        arg0->unk1 = 0;
    } else {
        arg0->unk1 = 1;
    }
    arg0->unk8 = arg2;
    arg0->unk4 = arg1;
}

s32 func_1512B630(struct108 *arg0, struct Struct1512B5FC *arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    s32 temp;

    if (arg5 == 0) {
        temp = *(s16 *)((u8 *)D_800DC204 + (arg0->unk23D * 0x20) + (arg0->unk1B4 * 8));
    } else {
        temp = *(s16 *)((u8 *)D_800DC206 + (arg0->unk23D * 0x20) + (arg0->unk1B4 * 8));
    }

    if (arg0->unk84 & 0x8000) {
        temp = (s16)(temp << 1);
    }

    if ((temp < arg2) && (arg3 < arg4)) {
        arg1->unk0 = 2;
        func_1512B5FC(arg1, arg3, arg2);
        return 1;
    }

    if ((temp < arg2) && (arg4 < arg3)) {
        arg1->unk0 = 1;
        func_1512B5FC(arg1, arg3, arg2);
        return 1;
    }

    arg1->unk1 = 0;
    arg1->unk0 = 0;
    arg1->unk8 = 0xFFFC;
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_157840/func_1512B730.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_157840/func_1512BB10.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_157840/func_1512C068.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_157840/func_1512C150.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_157840/func_1512C200.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_157840/func_1512C20C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_157840/func_1512C47C.s")
