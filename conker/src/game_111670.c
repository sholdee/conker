#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_111670/func_150E41C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_111670/func_150E42F8.s")

extern void func_150E41C0(void);
extern void func_150E42F8(s32);

void func_150E4514(s32 arg0) {
    func_150E41C0();
    func_150E42F8(arg0 / 0x1E);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_111670/func_150E4550.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_111670/func_150E4928.s")

void func_150E4CBC(struct42 *arg0) {
    s32 temp_v0;
    s32 temp_t0;
    s32 temp_a1;

    temp_v0 = arg0->unk90;
    if (temp_v0 < 9) {
        arg0->unkA4 = (s32)((f32)(((temp_v0 * 0x5A) / 9) * arg0->unk96) * 0.00390625f);
    } else {
        arg0->unkA4 = (s32)((f32)((0x5A - (((temp_v0 * 0x5A) - 0x32A) / 0x258)) * arg0->unk96) * 0.00390625f);
        temp_t0 = D_800BE9E4 * 17;
        temp_a1 = *(u8 *)((u8 *)arg0 + 0xB4);
        if (temp_t0 < temp_a1) {
            *(u8 *)((u8 *)arg0 + 0xB4) = temp_a1 - temp_t0;
            temp_v0 = arg0->unk90;
        } else {
            *(s16 *)((u8 *)arg0 + 0x98) = -1;
            temp_v0 = arg0->unk90;
        }
    }
    arg0->unkA2 = (s32)((f32)arg0->unk94 * 14.0f) >> 8;
    if (temp_v0 >= 0x261) {
        *(s16 *)((u8 *)arg0 + 0x98) = -1;
        temp_v0 = arg0->unk90;
    }
    arg0->unk90 = temp_v0 + D_800BE9E4;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_111670/func_150E4E04.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_111670/func_150E5558.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_111670/func_150E5810.s")
