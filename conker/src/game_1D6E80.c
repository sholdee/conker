#include <ultra64.h>
#define func_10010F30 func_10010F30_void
#include "functions.h"
#undef func_10010F30
#include "variables.h"

extern s32 func_10010F30(s32, u16, u8, s16, u8);
extern s32 func_151EF610(void);
extern f32 D_800A8F88;
extern f32 D_800A8FEC;
extern s32 func_15045800(f32 *, s32, f32, s32);
extern s32 func_151ABE40(f32 *, s32, s32, s32, s32);
extern s32 func_10010FFC(s32, s32, s32, s32, s32, s32);
extern void func_151AA264(void *, s32);
extern void func_151ABE00(void *);
extern void *func_15190770(void *, s32, s32, s32);
extern void func_151346EC(u8 *);
extern void func_1513470C(u8 *);

typedef struct {
    u8 pad0[0x14];
    f32 unk14;
    f32 unk18;
    f32 unk1C;
    u8 pad20[0xF8];
    f32 unk118;
} struct_151A9EC0_inner;

typedef struct {
    u8 pad0;
    u8 unk1;
    u8 pad2[0xA];
    u8 unkC;
    u8 padD[0xB];
    struct_151A9EC0_inner *unk18;
    u8 pad1C[0x18];
    f32 unk34;
} struct_151A9EC0_arg;

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D6E80/func_151A99D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D6E80/func_151A9AA4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D6E80/func_151A9BA0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D6E80/func_151A9CA0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D6E80/func_151A9DC0.s")

void func_151A9EC0(u8 *arg0) {
    u8 *v1 = *((u8 **)(arg0 + 0x18));
    f32 sp30[3];
    s32 temp;

    goto dummy_label_151A9EC0; dummy_label_151A9EC0: ;
    sp30[0] = *((f32 *)(v1 + 0x14));
    if (D_800A8F88 < (*((f32 *)(v1 + 0x118)))) {
        sp30[1] = (*((f32 *)(v1 + 0x118))) + 100.0f;
    } else {
        sp30[1] = (*((f32 *)(v1 + 0x18))) + 150.0f;
    }
    sp30[2] = *((f32 *)(v1 + 0x1C));
    temp = (s32)(arg0 + 0x34);
    if (func_15045800(sp30, 0, sp30[1] - 300.0f, temp) != 0) {
        sp30[1] = *((f32 *)(arg0 + 0x34));
        func_151ABE40(sp30, temp, 2, arg0[0xC], arg0[0x1]);
        func_10010FFC(0, 8, 0x6978, 0, 0, (s32)v1);
    }
    func_151AA264(v1, temp);
    func_151ABE00(v1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D6E80/func_151A9FC8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D6E80/func_151AA09C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D6E80/func_151AA170.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D6E80/func_151AA17C.s")

extern void func_1519F400(void);

void func_151AA1D0(void) {
    func_1519F400();
}

void func_151AA1F0(void) {
    func_1519F400();
}

struct s_151AA210_arg {
    char pad0[0x18];
    s32 unk18;
    u8 unk1C;
};

struct s_151AA210_buf {
    s32 unk0;
    u8 unk4;
};

extern void func_15147D64(s32, s32);
extern void func_1519F3B8(struct s_151AA210_arg *);

void func_151AA210(struct s_151AA210_arg *arg0) {
    s32 temp;
    struct s_151AA210_buf sp1C;

    temp = arg0->unk18;
    sp1C.unk0 = temp;
    sp1C.unk4 = arg0->unk1C;
    temp = (s32)&sp1C;
    func_15147D64(temp, 0xA);
    func_151494E0(temp, 0xA);
    func_1519F3B8(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D6E80/func_151AA264.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D6E80/func_151AA30C.s")

typedef struct {
    /* 0x00 */ u8  unk0;
    /* 0x01 */ u8  pad1[0x3];
    /* 0x04 */ void *unk4;
    /* 0x08 */ u8  unk8;
    /* 0x09 */ u8  pad9[0x3];
    /* 0x0C */ f32 unkC;
    /* 0x10 */ f32 unk10;
    /* 0x14 */ f32 unk14;
    /* 0x18 */ f32 unk18;
    /* 0x1C */ f32 unk1C;
    /* 0x20 */ f32 unk20;
    /* 0x24 */ u8  unk24;
    /* 0x25 */ u8  pad25[0x1];
    /* 0x26 */ s16 unk26;
    /* 0x28 */ s16 unk28;
    /* 0x2A */ s16 unk2A;
    /* 0x2C */ s16 unk2C;
    /* 0x2E */ u8  unk2E;
    /* 0x2F */ u8  unk2F;
    /* 0x30 */ s8  unk30;
    /* 0x31 */ u8  pad31[0x3];
    /* 0x34 */ f32 unk34;
    /* 0x38 */ u8  unk38;
    /* 0x39 */ s8  unk39;
} struct_10E4_AA48C;

typedef struct {
    /* 0x00 */ s32 unk0;
    /* 0x04 */ u8  unk4;
    /* 0x05 */ u8  pad5[0x3];
    /* 0x08 */ s32 unk8;
    /* 0x0C */ s32 unkC;
    /* 0x10 */ f32 unk10;
    /* 0x14 */ f32 unk14;
} struct_AA48C_b;

extern f32 D_800A8FA4;
extern f32 D_800A8FA8;
extern void *func_15134DAC(struct_10E4_AA48C *, s32);

void *func_151AA48C(void *arg0, s32 arg1) {
    struct_10E4_AA48C sp34;
    void *temp_v0;
    struct_AA48C_b sp18;

    sp18.unk0 = arg1;
    sp18.unk4 = 1;
    sp34.unk0 = *((u8 *)arg0 + 0x3B);

    sp34.unk4 = arg0;
    sp34.unk8 = 0xF;
    sp34.unkC = -11.0f;
    sp34.unk10 = -2.0f;
    sp34.unk14 = 8.0f;
    sp34.unk18 = -11.0f;
    sp34.unk1C = -2.0f;
    sp34.unk20 = 20.0f;
    sp34.unk24 = 0;
    sp34.unk26 = 0x3C;
    sp34.unk28 = 0x3C;
    sp34.unk2A = 0x12C;
    sp34.unk2E = 1;
    sp34.unk2F = 0;
    sp34.unk30 = 1;
    sp34.unk34 = 0.5f;
    sp34.unk38 = 1;
    sp34.unk39 = 0;

    sp18.unk8 = 0;
    sp18.unkC = 0x11111;
    sp18.unk10 = D_800A8FA4;
    sp18.unk14 = D_800A8FA8;

    temp_v0 = func_15134DAC(&sp34, 0x18);
    if (temp_v0 != NULL) {
        memcpy((u8 *)temp_v0 + 0x80, &sp18, 0x18);
    }
    return temp_v0;
}

s32 func_151AA5A4(u8 *arg0) {
    *(s32 *)(arg0 + 0x88) = 0;
    if (func_150ADA20() & 1) {
        func_10010F88(0xA, 0x55F0, (s16)((func_151EF610() % 0x4B0) - 0x258), 0, 0,
                      (s32)*(f32 *)(arg0 + 0x58), (s32)*(f32 *)(arg0 + 0x5C),
                      (s32)*(f32 *)(arg0 + 0x60), 0x1F4, 0x9C4);
        return 1;
    }
    func_10010F88(0xB, 0x55F0, (s16)((func_151EF610() % 0x4B0) - 0x258), 0, 0,
                  (s32)*(f32 *)(arg0 + 0x58), (s32)*(f32 *)(arg0 + 0x5C),
                  (s32)*(f32 *)(arg0 + 0x60), 0x1F4, 0x9C4);
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D6E80/func_151AA6D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D6E80/func_151AAA4C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D6E80/func_151AAABC.s")

void func_151352EC(struct102 *arg0);

void func_151AAB50(struct102 *arg0) {
    s32 *p = (s32 *)(*(s32 *)((u8 *)arg0 + 0x80) + 0x58);
    p[5] = 0;
    func_151352EC(arg0);
}

void func_1513530C(struct102 *arg0);

void func_151AAB78(struct102 *arg0) {
    s32 *p = (s32 *)(*(s32 *)((u8 *)arg0 + 0x80) + 0x58);
    p[5] = 0;
    func_1513530C(arg0);
}

s32 func_151AABA0(u8 *arg0) {
    s32 ret = 1;
    if (arg0[0x84] == 0) {
        ret = 0;
    }
    arg0[0x84] = 0;
    return ret;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D6E80/func_151AABC4.s")

s32 func_151AADBC(s32 arg0) {
    u8 *p;
    s32 v1;

    p = *(u8 **)(arg0 + 0x98);
    v1 = *(s16 *)(arg0 + 0x1C) << 4;
    if (v1 >= 0x100) {
        v1 = 0xFF;
    }
    if (v1 < p[0x1B]) {
        p[0x1B] = v1;
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D6E80/func_151AADF8.s")

extern u8   func_150ADA20(void);
extern f32  func_150ADA68(void);

typedef struct {
    /* 0x00 */ u8  pad0[0x4];
    /* 0x04 */ u8  unk4;
    /* 0x05 */ u8  pad5[0x3];
    /* 0x08 */ f32 unk8;
    /* 0x0C */ f32 unkC;
    /* 0x10 */ f32 unk10;
    /* 0x14 */ s16 unk14;
    /* 0x16 */ s16 unk16;
    /* 0x18 */ s16 unk18;
    /* 0x1A */ u8  pad1A[0x2];
    /* 0x1C */ f32 unk1C;
} struct_AB090;

typedef struct {
    /* 0x00 */ u8  pad0[0x24];
    /* 0x24 */ s32 unk24;
    /* 0x28 */ u8  pad28[0x88];
    /* 0xB0 */ struct_AB090 unkB0;
} struct_AB090_root;

s32 func_151AB090(struct_AB090_root *arg0) {
    s8 ret = 1;
    struct_AB090 *v1 = &arg0->unkB0;

    if (*((u8 *)arg0 + 0xB4) == 0) {
        ret = 0;
    }
    v1->unk4 = 0;
    v1->unk14 -= D_800BE9E4;
    if (v1->unk14 < 0) {
        v1->unk14 = (func_150ADA20() % (u32)(v1->unk18 + 1)) + v1->unk16;
        v1->unk10 = func_150ADA68() * v1->unkC + v1->unk8;
    }
    arg0->unk24 += (s32)((v1->unk10 - (f32)arg0->unk24) * v1->unk1C);
    return ret;
}

extern s32 func_1513F6C0(void *arg0, s32 arg1, s32 arg2);

s32 func_151AB180(u8 *arg0) {
    s32 *temp = (s32 *)((*(u8 **)((u8 *)arg0 + 0xB0)) + 0x58);
    temp[6] = 0;
    *(s32 *)((u8 *)arg0 + 0x18) |= 2;
    *(u8 **)((u8 *)arg0 + 0xB0) = 0;
    func_1513F6C0(arg0, 0, 0);
    return 0;
}

void func_151AB1C4(u8 *arg0) {
    u8 *v1 = *((u8 **)(arg0 + 0x18));
    f32 sp30[3];
    s32 temp;

    goto dummy_label_151AB1C4; dummy_label_151AB1C4: ;
    sp30[0] = *((f32 *)(v1 + 0x14));
    if (D_800A8FEC < (*((f32 *)(v1 + 0x118)))) {
        sp30[1] = (*((f32 *)(v1 + 0x118))) + 100.0f;
    } else {
        sp30[1] = (*((f32 *)(v1 + 0x18))) + 150.0f;
    }
    sp30[2] = *((f32 *)(v1 + 0x1C));
    temp = (s32)(arg0 + 0x34);
    if (func_15045800(sp30, 0, sp30[1] - 300.0f, temp) != 0) {
        sp30[1] = *((f32 *)(arg0 + 0x34));
        func_151ABE40(sp30, temp, 3, arg0[0xC], arg0[0x1]);
        func_10010FFC(0, 0x11, 0x5208, 0, 0, (s32)v1);
    }
    func_151AA264(v1, temp);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D6E80/func_151AB2C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D6E80/func_151AB3A4.s")

typedef struct {
    u8 pad0[0x4];
    u8 unk4;
    u8 pad5;
    u16 unk6;
} Struct151AB6B8;

s32 func_151AB6B8(u8 *arg0) {
    u8 ret;
    Struct151AB6B8 *temp_v1;

    ret = 1;
    temp_v1 = (Struct151AB6B8 *)(arg0 + 0x58);
    if (*(u16 *)(arg0 + 0x5E) != 0) {
        if (D_800DBFF0->unk5F0 & 1) {
        } else {
            func_100111C8(temp_v1->unk6);
            temp_v1->unk6 = 0;
            goto done_sound;
        }
    }
    if (temp_v1->unk6 == 0) {
        if (D_800DBFF0->unk5F0 & 1) {
            temp_v1->unk6 = func_10010F30(0x355, 0x7D00, 0x40, 0, 0);
        }
    }

done_sound:
    if (temp_v1->unk4 == 0) {
        ret = 0;
    }
    temp_v1->unk4 = 0;
    return ret;
}

void func_151AB788(u8 *arg0) {
    union {
        s32 *v0;
        f64 align;
    } sp18;

    sp18.v0 = (s32 *)(*(s32 *)(arg0 + 0x58) + 0x58);
    if (*(u16 volatile *)(arg0 + 0x5E) != 0) {
        func_100111C8(*(u16 *)(arg0 + 0x5E));
    }
    sp18.v0[7] = 0;
    func_151346EC(arg0);
}

void func_151AB7D8(u8 *arg0) {
    union {
        s32 *v0;
        f64 align;
    } sp18;

    sp18.v0 = (s32 *)(*(s32 *)(arg0 + 0x58) + 0x58);
    if (*(u16 volatile *)(arg0 + 0x5E) != 0) {
        func_100111C8(*(u16 *)(arg0 + 0x5E));
    }
    sp18.v0[7] = 0;
    func_1513470C(arg0);
}

void func_151AB828(u8 *arg0) {
    u8 *a3;

    a3 = arg0;
    func_15141DA4(*(void **)(a3 + 0x18), 0, 4);
}

void func_151AB854(u8 *arg0) {
    u8 *v1;
    struct185 tmp;

    v1 = *(u8 **)(arg0 + 0x18);
    if ((v1[4] == 0) || (v1[4] == 1) || (v1[4] == 2) || (v1[4] == 3) || (v1[4] == 4) || (v1[4] == 0x96)) {
        tmp.unk0 = (struct127 *)v1;
        tmp.unk4 = v1[0x3B];
        tmp.unk6 = 0x12C;
        tmp.unk8 = 0;
        tmp.unk9 = 0;
        if (v1[4] == 0x96) {
            tmp.unkA = 3;
        } else {
            tmp.unkA = 0;
        }
        if (v1[0x127] != 0xFF) {
            *(s16 *)(*(u8 **)(v1 + 0x31C) + 0x66) = 0x1F4;
        }
        func_15190770(&tmp, 0, arg0[0xC], arg0[1]);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D6E80/func_151AB920.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D6E80/func_151AB930.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D6E80/func_151AB9C8.s")

typedef struct {
    s32 unk0;
    u8  unk4;
} SubA_151ABD54;

typedef struct {
    s32 unk0;
    union {
        s32 w4;
        u8  b4;
    } u4;
    u8  unk8;
    u8  unk9;
} ArgB_151ABD54;

void func_151ABD54(struct260 *arg0, s32 arg1, u8 arg2) {
    SubA_151ABD54 *temp_v0 = (SubA_151ABD54 *)((u8 *)arg0 + 0x28);
    ArgB_151ABD54 *b = (ArgB_151ABD54 *)arg1;

    if (arg2 == 0) {
        if ((b->unk0 == temp_v0->unk0) || (b->u4.b4 == temp_v0->unk4)) {
            func_1516972C((struct102 *)arg0);
        }
    } else if (arg2 == 0x2D) {
        if (temp_v0->unk0 == b->unk0) {
            temp_v0->unk0 = b->u4.w4;
            temp_v0->unk4 = b->unk9;
        } else if (temp_v0->unk0 == b->u4.w4) {
            temp_v0->unk0 = b->unk0;
            temp_v0->unk4 = b->unk8;
        }
    }
}

struct tmp151ABE00 {
    s32 unk0;
    s8  unk4;
};

void func_151ABE00(void *arg0) {
    struct tmp151ABE00 tmp;

    tmp.unk0 = (s32)arg0;
    tmp.unk4 = *(u8 *)((char *)arg0 + 0x3B);

    func_1516944C(0x20, (s32)&tmp, 0xC);
}
