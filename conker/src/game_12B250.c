#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_12B250/func_150FDDA0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_12B250/func_150FDF38.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_12B250/func_150FE0B8.s")

extern u8 D_80088B80;
extern s32 D_800A1F70;
void func_151D3E04(s32, s32, s32*, s32, f32);

void func_150FE248(s32 arg0, s32 arg1, s32 arg2) {
    func_151D3E04(arg0, arg2, &D_800A1F70, D_80088B80, 0.0f);
}

extern u8 func_150ADA20(void);
extern void func_151D8868(void *arg0, s32 arg1, s32 arg2, s32 arg3);

struct sp18_150FE288 {
    /* 0x0 */ u8 unk0;
    /* 0x1 */ u8 unk1;
    /* 0x2 */ s16 unk2;
    /* 0x4 */ u8 unk4;
    /* 0x5 */ u8 unk5;
    /* 0x6 */ s8 unk6;
    /* 0x7 */ u8 unk7;
};

void func_150FE288(struct127 *arg0) {
    struct sp18_150FE288 sp18;

    if (arg0->camera != 0) {
        sp18.unk0 = 1;
        sp18.unk2 = (func_150ADA20() % 9U) + 0xF;
        sp18.unk5 = 1 << arg0->camera->unk23D;
        sp18.unk4 = (func_150ADA20() & 3) + 3;
        sp18.unk6 = -1;
        func_151D8868(&sp18, 0, 0xFF, 1);
    }
}
