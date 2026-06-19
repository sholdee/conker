#include <ultra64.h>
#include "functions.h"
#include "variables.h"


extern f32 D_800A08B0;
extern f32 D_800A08B4;
extern f32 D_800A08B8;
extern void func_15059C84(s32);

struct Obj150D13A0 {
    u8 pad0[0x3C];
    f32 unk3C;
    u8 pad40[0xB8 - 0x40];
    f32 unkB8;
    f32 unkBC;
    f32 unkC0;
    f32 unkC4;
    u8 padC8[0x148 - 0xC8];
    f32 unk148;
};

void func_150D13A0(s32 arg0) {
    struct Obj150D13A0 *temp = (struct Obj150D13A0 *)arg0;

    temp->unkB8 = temp->unkB8 + temp->unkBC;
    temp->unkBC = temp->unkBC * D_800A08B0;
    temp->unk3C = temp->unk3C * D_800A08B4;
    temp->unkC4 = temp->unkC4 + temp->unk148;
    temp->unk148 = temp->unk148 * D_800A08B8;
    func_15059C84(arg0);
}

extern s32 func_151149AC(u32);

struct Obj150D1410 {
    u8 pad0[0x6E];
    u8 unk6E;
};

void func_150D1410(s32 arg0) {
    struct Obj150D1410 *temp;

    temp = (struct Obj150D1410 *)func_151149AC(0xF9);
    if (temp != 0) {
        if (((arg0 - (s32)&D_800CC2D0[0]) / 0x32C) == 0) {
            temp->unk6E = 1;
        } else {
            temp->unk6E = 0;
        }
    }
}

struct Obj150D146C {
    u8 pad0[0x6E];
    u8 unk6E;
};

void func_150D146C(s32 arg0) {
    struct Obj150D146C *temp;

    temp = (struct Obj150D146C *)func_151149AC(0xF9);
    if (temp != 0) {
        temp->unk6E = 1;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_FE850/func_150D149C.s")
