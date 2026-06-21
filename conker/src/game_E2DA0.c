#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern f32 D_8009FC98;
extern f32 D_8009FC9C;
void func_150B5A3C(f32 *arg0, u8 arg1, u8 arg2);
void func_150B60E0(s32 *arg0, s32 arg1);

typedef struct Obj150B5950 {
    s32 unk0;
    u8 pad4[0x10];
    f32 unk14;
    f32 unk18;
    f32 unk1C;
    u8 pad20[0x1B];
    u8 unk3B;
    u8 pad3C[0x198];
    s32 unk1D4;
} Obj150B5950;

typedef struct Arg150B5950 {
    u8 unk0;
    u8 unk1;
    u8 pad2[0xA];
    u8 unkC;
    u8 padD;
    s16 unkE;
    u8 pad10[0x18];
    Obj150B5950 *unk28;
    u8 unk2C;
} Arg150B5950;


u16 *func_150B58F0(u16 *arg0, s32 arg1) {
    if (D_800C35EA == 1) {
        return arg0;
    }
    arg0[0] = 0x1A;
    arg0[1] = *(u16 *)((u8 *)D_800CC34A + 812 * arg1);
    return arg0 + 2;
}

void func_150B5950(Arg150B5950 *arg0) {
    vertex *sp28p;
    vertex sp28;
    Obj150B5950 *obj;

    obj = arg0->unk28;
    sp28p = &sp28;
    if ((obj->unk0 == 0) || (obj->unk3B != arg0->unk2C)) {
        arg0->unkE = -1;
        return;
    }

    if (obj->unk1D4 != 0) {
        if (func_150ADA68() < D_8009FC98) {
            sp28.x = obj->unk14;
            sp28.y = obj->unk18;
            sp28.z = obj->unk1C;
            func_150B5A3C((f32 *)sp28p, arg0->unkC, arg0->unk1);
        }

        if (func_150ADA68() < D_8009FC9C) {
            func_150B60E0((s32 *)obj, (s32)sp28p);
            func_150B5A3C((f32 *)sp28p, arg0->unkC, arg0->unk1);
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_E2DA0/func_150B5A3C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_E2DA0/func_150B5C38.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_E2DA0/func_150B5E34.s")

void func_150B6000(f32 *arg0, u8 arg1, s32 arg2) {
    Header header;
    Header2 header2;

    header.unk0 = 3;
    header.unk1 = -1;
    header.unk2 = (func_150ADA20() % 9U) + 3;
    header.unk4 = 0;

    header2.unk0 = (s32) arg0[0];
    header2.unk4 = (s32) arg0[1];
    header2.unk8 = (s32) arg0[2];

    func_151602C0(&header, &header2, (func_150ADA20() % 0xC9U) + 0x37, 0xFF, 0xFF, 0xFF, 0xFF, 0, 0, arg1, arg2);
}

extern void func_15143134(void *, s32, s32);
extern s32 D_8009FC30;

void func_150B60E0(s32 *arg0, s32 arg1) {
    func_15143134(&D_8009FC30, arg1, arg0[0x1D4 / 4] + 0x140);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_E2DA0/func_150B6110.s")

void func_150B6450(struct102 *arg0, s32 arg1, u8 arg2) {
    if (arg2 == 0x4A) {
        func_1516972C(arg0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_E2DA0/func_150B648C.s")

struct inner150B66DC {
    u8 pad[0x68];
    u8 unk68;
};
struct sub150B66DC {
    u8 pad0[0x14];
    u8 *unk14;
    struct inner150B66DC *unk18;
};

s32 func_150B66DC(struct sub150B66DC *arg0) {
    struct inner150B66DC *p = arg0->unk18;
    switch (p->unk68 - 0xF) {
    case 0:
        arg0->unk14[9] = 1;
        break;
    case 1:
        arg0->unk14[9] = 0;
        arg0->unk14[0x2F] = 0x14;
        break;
    case 2:
    default:
        arg0->unk14[9] = 0;
        arg0->unk14[0x2F] = 0x28;
        break;
    }
    return 1;
}

extern void func_15182670(s32, s32, s32, s32, s32, s32, s32, s32);

void func_150B6754(u8 arg0, s32 arg1) {
    u32 temp1;
    u32 temp0;

    temp0 = func_150ADA20();
    temp1 = func_150ADA20();
    func_15182670(0xCC, 0xCC, 0xFF, (u8)(temp0 % 0x38 + 0xC8), temp1 % 0xB + 0xF, 0, arg0, arg1);
}
