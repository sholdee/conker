#include <ultra64.h>
#include "functions.h"
#include "variables.h"


void func_15100180(s32 arg0) {
    struct {
        s32 unk0;
        u8 unk4;
    } sp18;

    sp18.unk0 = arg0;
    sp18.unk4 = *(u8 *)(arg0 + 0x3B);
    func_151494E0((s32)&sp18, 0x48);
}

void func_151001B4(struct127 *arg0) {
    struct {
        struct127 *unk0;
        u8 unk4;
        u16 unk6;
    } sp38;
    struct260 *temp_v0;

    sp38.unk0 = arg0;
    sp38.unk4 = arg0->unique_id;
    sp38.unk6 = 0;

    temp_v0 = func_15149130(0x12C, -1, 0x4E, -1, 0, 0x3B, (struct37 *)0x8, 0xFF, 1);
    if (temp_v0 != NULL) {
        memcpy((void *)((s32)temp_v0 + 0x28), &sp38, 8);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_12D630/func_15100230.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_12D630/func_151002BC.s")
