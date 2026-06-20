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

void func_15137F30(f32 *a0, f32 *a1, f32 *a2, f32 *a3, f32 arg4, void *arg5, f32 *out6C, f32 *out60, f32 *out54, f32 *out50, s16 *out4E, u8 *out4D, f32 *out48);
void func_151D9014(f32 *a0, f32 *a1, s32 a2, f32 a3, s16 sp10, u8 sp14, f32 sp18, s32 sp1C, f32 sp20, f32 sp24, s32 sp28, s32 sp2C, s32 sp30, s32 sp34, u8 sp38, u8 sp3C);

void func_151C5E74(f32 *a0, f32 *a1, f32 *a2, f32 *a3, f32 arg4, u8 *arg5) {
    f32 sp6C[3];
    f32 sp60[3];
    f32 sp54[3];
    f32 sp50;
    s16 sp4E;
    u8 sp4D;
    f32 sp48;

    func_15137F30(a0, a1, a2, a3, arg4, arg5, sp6C, sp60, sp54, &sp50, &sp4E, &sp4D, &sp48);
    func_151D9014(sp6C, sp54, 1, sp50, sp4E, sp4D, sp48, 0, 1.0f, 1.0f, 1, 0, 1, 0, arg5[0xC], arg5[1]);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1F2730/func_151C5F44.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1F2730/func_151C61A0.s")

s32 func_151C6290(u8 *arg0, s32 arg1, s32 arg2) {
    if (arg0[4] == 0x5A || arg0[4] == 0x74 || arg0[4] == 0x7A) {
        return 0;
    }
    return 1;
}
