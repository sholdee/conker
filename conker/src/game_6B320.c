#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern s32 func_1503EF4C(s32 arg0, s32 arg1, s32 arg2);
extern void func_1503E260(s32 arg0);
extern void func_1503ECA0(s32 arg0);
extern struct106 D_800C666C[];
extern s8 *D_80084454[];
extern u8 D_800C666E[];
extern f32 sqrtf(f32);
extern void func_150499A0(f32 arg0[4][4], f32 arg1[4][4]);
extern void func_150A7A48(f32 arg0[4][4], f32 arg1[4][4], f32 arg2[4][4]);
extern void func_1503E5F8();

struct func_1503E3C4_s {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    f32 unk14;
    f32 unk18;
    f32 unk1C;
    f32 unk20;
    f32 unk24;
    f32 unk28;
    f32 unk2C;
    f32 unk30;
    f32 unk34;
    f32 unk38;
    f32 unk3C;
    f32 unk40;
    f32 unk44;
    f32 unk48;
    f32 unk4C;
    f32 unk50;
    u8 pad54[0x14];
};

struct func_1503E3C4_mtx {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    f32 unk14;
    f32 unk18;
    f32 unk1C;
    f32 unk20;
    f32 unk24;
    f32 unk28;
    f32 unk2C;
    f32 unk30;
    f32 unk34;
    f32 unk38;
    f32 unk3C;
};


#pragma GLOBAL_ASM("asm/nonmatchings/game_6B320/func_1503DE70.s")

void func_1503DF0C(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    D_800C6660[arg0].unk4 |= arg2;
    D_800C6660[arg0].unk8 |= arg3;
    D_800C6660[arg0].pad[2] = arg1;
    D_800C6660[arg0].unkF = 2;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_6B320/func_1503DF48.s")

struct e1f4_s { s32 f; s8 pad[12]; };
extern struct e1f4_s D_800C6664[];
extern struct e1f4_s D_800C6668[];

s32 func_1503E1F4(s32 arg0, s32 arg1) {
    if (arg0 < 0x20) {
        if (D_800C6664[arg1].f & (1 << arg0)) {
            return 1;
        }
    } else {
        if (D_800C6668[arg1].f & (1 << arg0)) {
            return 1;
        }
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_6B320/func_1503E260.s")

void func_1503E3C4(s32 arg0, s32 arg1, s32 arg2, struct func_1503E3C4_s *arg3, s32 arg4) {
    struct func_1503E3C4_mtx sp94;
    struct func_1503E3C4_mtx sp54;
    struct127 *obj;
    s32 idx;
    f32 len;
    f32 dx;
    f32 dy;
    f32 dz;

    obj = &D_800CC2D0[arg0];
    bcopy((void *)((u8 *)obj->unk1D4 + ((arg1 + arg2) << 6)), (u8 *)&sp94 - 4, 0x40);
    if (arg4 != 0) {
        idx = -1;
    } else {
        idx = D_80084454[D_800C666E[arg0 * 0x10]][arg1];
    }
    if (idx != -1) {
        func_150499A0((f32 (*)[4])((u8 *)obj->unk1D4 + (idx << 6)), (f32 (*)[4])((u8 *)&sp54 - 4));
        ((f32 *)((u8 *)&sp94 - 4))[7] = 0.0f;
        ((f32 *)((u8 *)&sp94 - 4))[3] = 0.0f;
        ((f32 *)((u8 *)&sp94 - 4))[11] = 0.0f;
        ((f32 *)((u8 *)&sp94 - 4))[15] = 1.0f;
        func_150A7A48((f32 (*)[4])((u8 *)&sp94 - 4), (f32 (*)[4])((u8 *)&sp54 - 4), (f32 (*)[4])((u8 *)&sp94 - 4));
    }
    func_1503E5F8((u8 *)&sp94 - 4, &arg3->unk0, &arg3->unk4, &arg3->unk8, &arg3->unkC, &arg3->unk10, &arg3->unk14, &arg3->unk18, &arg3->unk1C, &arg3->unk20);
    arg3->unk24 = arg3->unk0;
    arg3->unk28 = arg3->unk4;
    arg3->unk2C = arg3->unk8;
    arg3->unk30 = arg3->unkC;
    arg3->unk34 = arg3->unk10;
    arg3->unk38 = arg3->unk14;
    arg3->unk3C = arg3->unk18;
    arg3->unk40 = arg3->unk1C;
    arg3->unk44 = arg3->unk20;

    dx = arg3->unk0 - obj->x_position;
    dy = (arg3->unk28 - obj->y_position) - 30.0f;
    dz = arg3->unk2C - obj->z_position;
    len = sqrtf((dx * dx) + (dy * dy) + (dz * dz));
    if (len == 0.0f) {
        len = 1.0f;
    }
    len = 1.0f / len;
    arg3->unk48 = dx * len;
    arg3->unk4C = dy * len;
    arg3->unk50 = dz * len;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_6B320/func_1503E5F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_6B320/func_1503E82C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_6B320/func_1503EA54.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_6B320/func_1503EB78.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_6B320/func_1503ECA0.s")

void func_1503EEB8(void) {
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_6B320/func_1503EEC0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_6B320/func_1503EF4C.s")

extern u8 D_80098914[];

void func_1503EFC4(s32 arg0) {
    struct106 *p = &D_800C6660[arg0];
    s32 i;
    s32 off;
    s32 count;

    *(s16 *)((s32)p + 0xC) = 0x78;
    count = D_80098914[*(u8 *)((s32)p + 0xE)];
    i = 0;
    off = 0;
    for (; i < count; i++, off += 0x68) {
        *(f32 *)(p->unk0 + off + 0x4C) = (f32)((s32)((u32)func_150ADA20() % 0x14) - 5);
    }
}

extern void func_1503EB78(void *arg0, f32 arg1, f32 arg2, s32 arg3);

void func_1503F078(void *arg0, s32 arg1) {
    func_1503EB78(arg0, 2.0f, 2.0f, 0);
}

extern void func_1503EB78(void *arg0, f32 arg1, f32 arg2, s32 arg3);

void func_1503F0AC(void *arg0, s32 arg1) {
    func_1503EB78(arg0, 1.0f, 2.0f, 1);
}

void func_1503F0D8(void *arg0, s32 arg1) {
    func_1503EB78(arg0, 2.06f, 3.0f, 1);
}

extern s8 D_800CC364[];

void func_1503F108(s32 arg0) {
    struct106 *p = &D_800C6660[arg0];
    (*(s16 *)((s32)p + 0xC)) = 0x8C;
    *(s32 *)&D_800CC364[arg0 * 812] = 6;
    *(f32 *)(p->unk0 + 0x1EC) = 10.0f;
}

void func_1503F16C(s32 arg0) {
    struct106 *p;

    p = &D_800C666C[arg0];
    (*(s16 *)p) = 0x12C;
    if (func_1503EF4C(2, 0, arg0)) {
        D_800CC2D0[arg0].unk94 |= 0x40;
        D_800CC2D0[arg0].unk94 &= ~0x200;
    }
    if (func_1503EF4C(2, 1, arg0)) {
        D_800CC2D0[arg0].unk94 |= 0x80;
        D_800CC2D0[arg0].unk94 &= ~0x100;
    }
    if (func_1503EF4C(2, 2, arg0)) {
        D_800CC2D0[arg0].unk94 &= ~0x400;
    }
}

struct func_1503F2B0_s {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s16 unkC;
    s8 padE[2];
};

void func_1503F2B0(s32 arg0) {
    struct func_1503F2B0_s *p;

    func_1503ECA0(arg0);
    p = (struct func_1503F2B0_s *)&D_800C6660[arg0];
    p->unkC -= D_800BE9E4;
    if (p->unkC > 0) {
        return;
    }
    func_1503E260(arg0);
    if (func_1503EF4C(2, 0, arg0)) {
        D_800CC2D0[arg0].unk94 |= 8;
    }
    if (func_1503EF4C(2, 1, arg0)) {
        D_800CC2D0[arg0].unk94 |= 4;
    }
    if (func_1503EF4C(2, 2, arg0)) {
        D_800CC2D0[arg0].unk94 |= 2;
    }
}

extern u8 D_800C3E90;
extern void func_1503E5F8();

void func_1503F404(Mtx *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8, s32 arg9) {
    f32 sp30[4][4];

    if (D_800C3E90) {
        guMtxL2F(sp30, arg0);
    } else {
        memcpy(sp30, arg0, 0x40);
    }
    func_1503E5F8(sp30, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9);
}
