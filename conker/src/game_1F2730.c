#include <ultra64.h>
#include "functions.h"
#include "variables.h"

struct225 *func_151602C0(Header *header, Header2 *header2, s32 arg2, s32 arg3, s32 arg4, s32 arg5, u8 arg6, u8 arg7, s32 offset, u8 arg9, s32 argA);

#pragma GLOBAL_ASM("asm/nonmatchings/game_1F2730/func_151C5280.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1F2730/func_151C5588.s")

void func_151C56A4(f32 *arg0, u8 arg1, s32 arg2) {
    Header header;
    Header2 header2;

    header.unk0 = 3;
    header.unk1 = -1;
    header.unk2 = (func_150ADA20() % 3U) + 3;
    header.unk4 = 0;

    header2.unk0 = (s32) arg0[0];
    header2.unk4 = (s32) arg0[1];
    header2.unk8 = (s32) arg0[2];

    func_151602C0(&header, &header2, (func_150ADA20() & 1) + 6, 0xFF, 0xE8, 0xAB, 0xFF, 0, 0, arg1, arg2);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1F2730/func_151C577C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1F2730/func_151C5E74.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1F2730/func_151C5F44.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1F2730/func_151C61A0.s")

s32 func_151C6290(u8 *arg0, s32 arg1, s32 arg2) {
    if (arg0[4] == 0x5A || arg0[4] == 0x74 || arg0[4] == 0x7A) {
        return 0;
    }
    return 1;
}
