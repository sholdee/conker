#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern f32 D_800AA97C;
extern f32 D_800AA980;
extern f32 D_800AA984;
extern f32 D_800AA988;
extern f32 D_800AA98C;

typedef struct {
    /* 0x00 */ s32 unk00;
    /* 0x04 */ s32 unk04;
    /* 0x08 */ u8  pad08[0xC];
    /* 0x14 */ f32 unk14;
    /* 0x18 */ f32 unk18;
    /* 0x1C */ f32 unk1C;
    /* 0x20 */ f32 unk20;
    /* 0x24 */ f32 unk24;
    /* 0x28 */ f32 unk28;
    /* 0x2C */ s32 unk2C;
    /* 0x30 */ s32 unk30;
    /* 0x34 */ f32 unk34;
    /* 0x38 */ f32 unk38;
    /* 0x3C */ f32 unk3C;
    /* 0x40 */ f32 unk40;
    /* 0x44 */ s16 unk44;
    /* 0x46 */ s16 unk46;
    /* 0x48 */ s16 unk48;
    /* 0x4A */ s16 unk4A;
    /* 0x4C */ s16 unk4C;
    /* 0x4E */ s16 unk4E;
    /* 0x50 */ s8  unk50;
} Struct151BFC40;

void func_151BFC40(void *arg0, f32 *arg1) {
    Struct151BFC40 *temp = arg0;

    temp->unk00 = 3;
    temp->unk04 = 4 >> ((D_80082FA0 >= 2) ? 1 : 0);
    arg1[0] = 494.0f;
    temp->unk14 = D_800AA97C;
    temp->unk18 = D_800AA980;
    temp->unk1C = 45.0f;
    temp->unk20 = 53.0f;
    temp->unk24 = 203.0f;
    temp->unk28 = 414.0f;
    temp->unk2C = 7;
    temp->unk30 = 3 >> ((D_80082FA0 >= 2 || D_8008FD8C >= 8) ? 1 : 0);
    temp->unk34 = 15.0f;
    temp->unk38 = D_800AA984;
    temp->unk3C = D_800AA988;
    temp->unk40 = D_800AA98C;
    temp->unk44 = 25;
    temp->unk46 = 15;
    temp->unk48 = 100;
    temp->unk4A = 100;
    temp->unk4C = 12;
    temp->unk4E = 20;

    if (D_80082FA0 < 2) {
        if (D_8008FD8C < 8) {
            goto zero;
        }
    }

    temp->unk50 = -1;
    return;

zero:
    temp->unk50 = 0;
}

struct Vec3F151BFDA0 { f32 x; f32 y; f32 z; };
struct Local151BFDA0 {
    struct Vec3F151BFDA0 unk0;  /* 0x00 (sp 0x24) */
    f32 unkC;                   /* 0x0C (sp 0x30) */
    u8 unk10[0x8];              /* 0x10 (sp 0x34) */
    struct Vec3F151BFDA0 unk18; /* 0x18 (sp 0x3C) */
    u8 unk24[0x40];             /* 0x24 (sp 0x48) */
};
void func_151C0418(f32 *, u8, s32);
void func_151C04F8(f32 *, u8, s32);
void func_151C05A4(void *, u8, s32);
void func_151C05F0(void *, u8, s32);
void func_151BFC40(void *, f32 *);
void func_1514FB98(void *, u8, s32);

void func_151BFDA0(struct Vec3F151BFDA0 *arg0, struct Vec3F151BFDA0 *arg1, u8 arg2, u8 arg3, s32 arg4) {
    struct Local151BFDA0 sp24;

    func_151C0418((f32 *)arg0, arg3, arg4);
    func_151C04F8((f32 *)arg0, arg3, arg4);
    func_151C05A4(arg0, arg3, arg4);
    func_151C05F0(arg0, arg3, arg4);
    if (arg2 != 0) {
        sp24.unk0.x = -arg1->x;
        sp24.unk0.y = -arg1->y;
        sp24.unk0.z = -arg1->z;
        func_151BFC40(&sp24.unk10, &sp24.unkC);
        sp24.unk18 = *arg0;
        func_1514FB98(&sp24, arg3, arg4);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1ED0F0/func_151BFE84.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1ED0F0/func_151C0098.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1ED0F0/func_151C02E4.s")

void func_150E7FEC(f32, s32, void *, void *, s32, s32, s32, s32, s32, s32, s32, s32);

void func_151C0360(void *arg0, void *arg1, s32 arg2, s32 arg3) {
    union { u32 w; f64 _a; } r1;
    f32 sp3C;
    u32 r2;

    sp3C = func_150ADA68();
    r1.w = func_150ADA20();
    r2 = func_150ADA20();
    func_150E7FEC(sp3C * 75.0f + 75.0f, (u8)((r1.w % 56U) + 200), arg0, arg1,
                  ((u32)r2 % 205U) + 299, 1, 1, 0, 0, 0, (u8)arg2, 0);
}

void func_151602C0(Header *, Header2 *, s32, s32, s32, s32, s32, s32, s32, u8, s32);

void func_151C0418(f32 *arg0, u8 arg1, s32 arg2) {
    Header header;
    Header2 header2;

    header.unk0 = 3;
    header.unk1 = -1;
    header.unk2 = (func_150ADA20() % 0xBU) + 0x14;
    header.unk4 = 0;

    header2.unk0 = (s32) arg0[0];
    header2.unk4 = (s32) arg0[1];
    header2.unk8 = (s32) arg0[2];

    func_151602C0(&header, &header2, (func_150ADA20() % 0x79U) + 0x3C, 0xFF, 0xFF, 0xFF, 0xFF, 0, 0, arg1, arg2);
}

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

typedef struct {
    u8 pad0[0x38];
    f32 unk38;
    f32 unk3C;
    f32 unk40;
} Struct151C110CInner;

typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
    u8 pad8[0x10];
    Struct151C110CInner *unk18;
} Struct151C110C;

s32 func_151C110C(Struct151C110C *arg0, s32 arg1, void **arg2, s32 arg3, s32 arg4, s32 arg5, s16 *arg6) {
    Struct151C110CInner *temp_v1;
    s16 *temp_t3;

    temp_v1 = arg0->unk18;
    temp_t3 = arg6;
    if (temp_v1 != NULL) {
        if (*arg2 != NULL) {
            arg0->unk2 = temp_v1->unk38;
            arg0->unk4 = temp_v1->unk3C;
            arg0->unk6 = temp_v1->unk40;
            return 0;
        }
    }

    *temp_t3 = 0;
    return 0;
}

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

void func_151D40D4(struct Vec3F151BFDA0 *, s32, s32, s32, s32, s32, s32, s32);
void func_151D42E8(struct Vec3F151BFDA0 *, s32, s32, s32, s32);

void func_151C1654(struct Vec3F151BFDA0 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    void (*callback)(s32, s32, s32);
    u8 temp;

    callback = (void (*)(s32, s32, s32)) D_800E0934;
    if (callback != NULL) {
        callback((s32)arg0->x, (s32)arg0->y, (s32)arg0->z);
    }

    temp = (u8)arg3;
    if (temp != 0) {
        switch (temp) {
        case 1:
            func_151D42E8(arg0, arg1, arg2, arg4, 0x24);
            return;
        case 2:
            func_151D42E8(arg0, arg1, arg2, arg4, 0x25);
            return;
        case 3:
            func_151D40D4(arg0, arg1, arg2, 0, arg4, 0x16, 0x26, 0);
            return;
        }
    }

    func_151D40D4(arg0, arg1, arg2, 0, arg4, 0x16, 0x15, 0);
}

void func_15143134(void *, s32, s32);
struct S800AA958 { s32 unk0; s32 unk4; s32 unk8; };
extern u8 D_800AA954[];
extern struct S800AA958 D_800AA958[];

void func_151C1798(u8 *arg0, s32 arg1) {
    s32 index;

    switch (arg0[4]) {
    case 0x77:
        index = 1;
        break;
    case 0x28:
        index = 2;
        break;
    default:
        index = 0;
        break;
    }
    func_15143134(&D_800AA958[index], arg1,
                  *(s32 *)(arg0 + 0x1D4) + (D_800AA954[index] << 6));
}

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
