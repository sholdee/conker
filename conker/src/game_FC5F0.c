#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_FC5F0/func_150CF140.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_FC5F0/func_150CF484.s")

extern void func_151CF898(struct127 *, f32, f32);

void func_150CF530(s32 arg0) {
    func_151CF898(&D_800CC2D0[0], D_800CC2D0[0].y_position + 300.0f, -10000.0f);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_FC5F0/func_150CF578.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_FC5F0/func_150CF5E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_FC5F0/func_150CF680.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_FC5F0/func_150CF800.s")

struct sub150CFBEC {
    u8 unk0;
    u8 pad[3];
    f32 unk4;
    f32 unk8;
    f32 unkC;
};

struct par150CFBEC {
    char pad10[0x10];
    f32 unk10;
    char pad14[0x70 - 0x14];
    struct sub150CFBEC unk70;
};

void func_150CFBEC(struct par150CFBEC *arg0, f32 *arg1, u8 arg2) {
    struct sub150CFBEC *temp = &arg0->unk70;

    if (arg2 == 0x52) {
        temp->unk0 |= 1;
        temp->unk4 = 0.0f;
        temp->unk8 = arg0->unk10;
        temp->unkC = arg1[0] - arg0->unk10;
    }
}

extern void func_1515572C(f32 *, s32);

void func_150CFC38(f32 arg0) {
    f32 sp1C;

    sp1C = arg0;
    func_1515572C(&sp1C, 0x52);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_FC5F0/func_150CFC60.s")

unsigned char *func_150CFD20(unsigned char *arg0) {
    if (*arg0 != 0xBD && *arg0 != 0) {
        do {
            arg0++;
        } while (*arg0 != 0xBD && *arg0 != 0);
    }
    return arg0;
}

unsigned char *func_150CFD5C(unsigned char *arg0) {
    if (*arg0 != 0) {
        do {
            arg0++;
        } while (*arg0 != 0);
    }
    return arg0;
}

extern unsigned char *func_150CFD20(unsigned char *);

s32 func_150CFD84(unsigned char *arg0, unsigned char **arg1) {
    unsigned char *temp;

    temp = func_150CFD20(arg0);
    *arg1 = temp;
    return temp - arg0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_FC5F0/func_150CFDB8.s")

struct inner150CFE3C {
    char pad0[0x14];
    u8 unk14;
    u8 unk15;
    char pad16[0x18 - 0x16];
    u8 *unk18[1];
};

struct flat150CFE3C {
    char pad0[0x34];
    u8 *unk34;
    char pad38[0x3C - 0x38];
    u8 unk3C;
    u8 unk3D;
    char pad3E[0x40 - 0x3E];
    u8 *unk40[1];
};

union par150CFE3C {
    struct flat150CFE3C flat;
    struct {
        char pad0[0x28];
        struct inner150CFE3C inner;
    } sub;
};

void func_150CFE3C(union par150CFE3C *arg0) {
    struct inner150CFE3C *inner;

    inner = &arg0->sub.inner;
    memcpy(arg0->flat.unk40[arg0->flat.unk3D], arg0->flat.unk34, arg0->flat.unk3C);
    inner->unk18[inner->unk15][inner->unk14] = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_FC5F0/func_150CFE98.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_FC5F0/func_150CFF10.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_FC5F0/func_150D0034.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_FC5F0/func_150D00C0.s")

extern void *func_150CFF10(u8, s32, s16, s32, s32, s32, u8, void *);

struct frame150D0134 {
    u8 unk0;
    u8 pad[7];
};

void func_150D0134(u8 arg0, s32 arg1, s16 arg2, u8 arg3, void *arg4) {
    struct frame150D0134 sp30;
    void *ret;

    sp30.unk0 = 0;
    ret = func_150CFF10(arg0, arg1, arg2, 8, 0, 0, arg3, arg4);
    if (ret != 0) {
        memcpy(*(void **)((u8 *)ret + 0x48), &sp30.unk0, 1);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_FC5F0/func_150D01A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_FC5F0/func_150D02B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_FC5F0/func_150D032C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_FC5F0/func_150D04C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_FC5F0/func_150D0534.s")
