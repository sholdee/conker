#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_1ED0F0/func_151BFC40.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1ED0F0/func_151BFDA0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1ED0F0/func_151BFE84.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1ED0F0/func_151C0098.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1ED0F0/func_151C02E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1ED0F0/func_151C0360.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1ED0F0/func_151C0418.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1ED0F0/func_151C04F8.s")

void func_151D5334(void *, f32, f32, f32, s32, u8, s32);

void func_151C05A4(void *arg0, u8 arg1, s32 arg2) {
    func_151D5334(arg0, 800.0f, 2000.0f, 0.0005f, 5, arg1, arg2);
}

void func_151C05F0(void *arg0, u8 arg1, s32 arg2) {
    func_151D5404(arg0, 800.0f, 2000.0f, 0.0005f, 0xF, 0x14, arg1, arg2);
}

void func_150E83AC(void *, s16, u8, s32);

void func_151C0644(void *arg0, u8 arg1, s32 arg2) {
    func_150E83AC(arg0, (s16)((u32)func_150ADA20() % 0x3E + 0x78), arg1, arg2);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1ED0F0/func_151C0698.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1ED0F0/func_151C110C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1ED0F0/func_151C1180.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1ED0F0/func_151C1570.s")

void func_151C1570(void *);
void func_15132570(void *);

void func_151C15FC(void *arg0) {
    func_151C1570(arg0);
    func_15132570(arg0);
}

void func_1513259C(void *);

void func_151C1628(void *arg0) {
    func_151C1570(arg0);
    func_1513259C(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1ED0F0/func_151C1654.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1ED0F0/func_151C1798.s")

void func_151C1814(s32 *arg0, s32 *arg1, u8 arg2) {
    s32 *v0 = (s32 *)((u8 *)arg0 + 0x170);
    if (arg2 == 0x2D) {
        if (arg1[0] == v0[0x1B]) {
            v0[0x1B] = arg1[1];
        } else if (arg1[1] == v0[0x1B]) {
            v0[0x1B] = arg1[0];
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1ED0F0/func_151C1860.s")

s32 func_151C02E4(s32, s32, s32, s32 *);

typedef struct {
    s32 unk0;
    s32 unk4[1];
} Struct151C1940;

s32 func_151C1940(s32 arg0, s32 arg1, Struct151C1940 *arg2) {
    return func_151C02E4(arg0, arg1, arg2->unk0, arg2->unk4);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1ED0F0/func_151C196C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1ED0F0/func_151C1D5C.s")

struct sp18_151C1FB8 {
    /* 0x0 */ u8 unk0;
    /* 0x1 */ u8 unk1;
    /* 0x2 */ s16 unk2;
    /* 0x4 */ u8 unk4;
    /* 0x5 */ u8 unk5;
    /* 0x6 */ s8 unk6;
    /* 0x7 */ u8 unk7;
};

extern void func_151D8868(void *, s32, s32, s32);

void func_151C1FB8(struct127 *arg0) {
    struct sp18_151C1FB8 sp18;

    if (arg0->camera != 0) {
        sp18.unk0 = 1;
        sp18.unk2 = (func_150ADA20() & 7) + 0xD;
        sp18.unk5 = 1 << arg0->camera->unk23D;
        sp18.unk4 = (func_150ADA20() % 3U) + 6;
        sp18.unk6 = -1;
        func_151D8868(&sp18, 0, 0xFF, 1);
    }
}
