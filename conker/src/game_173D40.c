#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_173D40/func_15146890.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_173D40/func_15146970.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_173D40/func_15146A98.s")

void func_15146BF8(s32, s32, s32, s32);

void func_15146BB8(s32 arg0, s32 arg1, s32 arg2) {
    func_15146BF8(arg0, arg1, arg2, 0);
}

void func_15146BD8(s32 arg0, s32 arg1, s32 arg2) {
    func_15146BF8(arg0, arg1, arg2, 1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_173D40/func_15146BF8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_173D40/func_15146D60.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_173D40/func_15146E84.s")

typedef struct {
    f32 unk0;
    f32 unk4;
    s32 unk8;
} Struct15147040;

extern void func_15146890(Struct15147040 *, s32, s32, u8);
extern void func_1514C678(f32, f32, s32, f32, s32, s32, s32, s32, s32, f32, s32, s32);

void func_15147040(s32 arg0, s32 arg1, s32 arg2) {
    Struct15147040 sp44;
    s16 temp;

    if (*(s32 *)(arg0 + 0x1D4) != 0) {
        func_15146890(&sp44, arg0, 0, (u8)arg1);
        temp = (func_150ADA20() % 11U) + 5;
        func_1514C678(sp44.unk0, sp44.unk4, sp44.unk8,
                      func_150ADA68() * 11.0f,
                      0, 0xFF, temp, 0x16, 0, 0.0f, 0, 0xFF);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_173D40/func_151470FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_173D40/func_15147318.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_173D40/func_15147478.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_173D40/func_151475D8.s")
