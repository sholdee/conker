#include <ultra64.h>
#define func_15169260 func_15169260_s32_decl
#include "functions.h"
#undef func_15169260
#include "variables.h"

struct Vec3F { f32 x; f32 y; f32 z; };
struct Local1514F6E8 { u8 unk0; u8 pad1[3]; struct Vec3F unk4; struct Vec3F unk10; struct Vec3F unk1C; f32 unk28; };
struct Arg1514FB98 { u8 pad[0xC]; f32 unkC; u8 unk10[0x4]; };
struct Arg1514FBFC { struct Vec3F unk0; struct Vec3F unkC; f32 unk18; f32 unk1C; f32 unk20; u8 unk24[0x4]; };
extern s32 func_15146078(struct Arg1514FB98 *, struct Vec3F *, struct Vec3F *);
extern s32 func_15144E80(struct Vec3F *, struct Vec3F *, struct Vec3F *, struct Vec3F *);
extern f32 func_15144A74(struct Vec3F *, struct Vec3F *);
extern s32 func_15145128(struct Vec3F *, struct Vec3F *, f32 *, f32 *);
extern void func_1514F8F8(void *, void *, struct Vec3F *, struct Vec3F *, f32, u8, s32);
extern f32 D_800A601C;
extern f32 D_800A6020;
extern f32 D_800A6024;
extern f32 D_800A6028;
extern f32 D_800A602C;
extern f32 D_800A6004;
extern f32 D_800A6008;
extern f32 D_800A600C;
extern f32 D_800A6010;
extern f32 D_800A6014;
extern f32 D_800A6018;
extern void *func_15132A4C(void *, s32, s32, s32, u8, s32);
extern s32 func_150AC9C0(f32, f32, f32, f32, f32, f32, void *, s32, f32 *, f32 *, f32 *, f32 *, s32 *, s32, f32);
extern s32 func_15145C90(s32);

struct Local1515572CData {
    s32 unk0;
    s32 unk4;
};

extern struct Local1515572CData D_800A6038;
extern void func_15169260(struct Local1515572CData *, s32, s32, u8);

struct Local15152874Header {
    s32 unk0;
    s32 unk4;
    s32 unk8;
};

struct Local15152874Arg {
    s32 unk0;
    s32 unk4;
    struct Local15152874Header unk8;
    s16 unk14;
    s16 unk16;
    s16 unk18;
    s16 unk1A;
    f32 unk1C;
    f32 unk20;
    f32 unk24;
    f32 unk28;
    f32 unk2C;
    s8 unk30;
    u8 pad31;
    s16 unk32;
    s16 unk34;
    u8 pad36[2];
    f32 unk38;
    f32 unk3C;
    f32 unk40;
    f32 unk44;
    f32 unk48;
};

struct Local15152874Spawn {
    struct Local15152874Header unk0;
    f32 unkC;
    f32 unk10;
    f32 unk14;
    f32 unk18;
    f32 unk1C;
    u8 unk20;
    u8 unk21;
    u8 unk22;
    u8 unk23;
    s32 unk24;
    f32 unk28;
    f32 unk2C;
    f32 unk30;
    s32 pad34;
};

struct Local15150D1CArg {
    s32 unk0;
    s32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    s16 unk14;
    s16 unk16;
    s16 unk18;
    s16 unk1A;
    f32 unk1C;
    f32 unk20;
    f32 unk24;
    s16 unk28;
    s16 unk2A;
    u8 unk2C;
};

struct Local151539B4Header {
    s32 unk0;
    s32 unk4;
    s32 unk8;
};

struct Local151539B4Arg {
    s16 unk0;
    s16 unk2;
    struct Local151539B4Header unk4;
    s16 unk10;
    s16 unk12;
    s16 unk14;
    s16 unk16;
    f32 unk18;
    f32 unk1C;
    f32 unk20;
    f32 unk24;
    u8 unk28;
    u8 unk29;
    u8 unk2A;
    u8 unk2B;
    u8 unk2C;
    u8 unk2D;
    u8 unk2E;
    u8 unk2F;
    u8 unk30;
    u8 pad31;
    s16 unk32;
    s16 unk34;
    u16 unk36;
    f32 unk38;
    f32 unk3C;
    u8 unk40;
    u8 unk41;
    s16 unk42;
    s16 unk44;
    u8 unk46;
};

struct Local151539B4Spawn {
    struct Local151539B4Header unk0;
    f32 unkC;
    f32 unk10;
    f32 unk14;
    f32 unk18;
    f32 unk1C;
    u8 unk20;
    u8 unk21;
    u8 unk22;
    u8 unk23;
    u8 unk24;
    u8 unk25;
    u8 unk26;
    u8 unk27;
    u8 unk28;
    u8 pad29;
    s16 unk2A;
    u16 unk2C;
    u8 pad2E[2];
    f32 unk30;
    u8 unk34;
    u8 pad35;
    s16 unk36;
    s16 unk38;
    u8 pad3A[2];
};

extern void func_15143794(s32, s32, f32, f32 *);
extern void func_150CCEB0(struct Local15152874Spawn *, u8, u8);
extern void (*D_8008AC60[])(u8 *);
extern s32 (*D_8008ACC8[])(void *);
extern void func_15156190(void *, u8, s32, u8, s32);


struct Local1514FEFC;

void func_1514F640(void *arg0, struct Local1514FEFC *arg1) {
    *(u8 *)arg1 = 2;
    *(f32 *)((u8 *)arg1 + 0x28) = *(f32 *)((u8 *)arg0 + 0x20);
    if (func_15144E80((struct Vec3F *)((u8 *)arg0 + 0xC), (struct Vec3F *)((u8 *)arg1 + 0x10), (struct Vec3F *)((u8 *)arg1 + 0x1C), (struct Vec3F *)((u8 *)arg1 + 4)) != 0) {
        if (func_15144A74((struct Vec3F *)((u8 *)arg1 + 4), (struct Vec3F *)arg0) < 0.0f) {
            *(f32 *)((u8 *)arg1 + 4) = -*(f32 *)((u8 *)arg1 + 4);
            *(f32 *)((u8 *)arg1 + 8) = -*(f32 *)((u8 *)arg1 + 8);
            *(f32 *)((u8 *)arg1 + 0xC) = -*(f32 *)((u8 *)arg1 + 0xC);
        }
    }
}

s32 func_1514F6E8(struct Local1514F6E8 *arg0) {
    if (!(arg0->unk0 & 1)) {
        if (func_15145128(&arg0->unk4, &arg0->unk4, NULL, NULL) == 0) {
            return 0;
        }
        arg0->unk4.x *= 1000.0f;
        arg0->unk4.y *= 1000.0f;
        arg0->unk4.z *= 1000.0f;
        arg0->unk0 |= 1;
    }
    if (!(arg0->unk0 & 2)) {
        if (func_15146078((struct Arg1514FB98 *)&arg0->unk4, &arg0->unk10, &arg0->unk1C) == 0) {
            return 0;
        }
        arg0->unk0 |= 6;
    }
    if (!(arg0->unk0 & 4)) {
        if (func_15145128(&arg0->unk10, &arg0->unk10, NULL, NULL) == 0) {
            return 0;
        }
        if (func_15145128(&arg0->unk1C, &arg0->unk1C, NULL, NULL) == 0) {
            return 0;
        }
        arg0->unk0 |= 4;
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_17CAF0/func_1514F808.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_17CAF0/func_1514F8F8.s")

void func_1514FB98(struct Arg1514FB98 *arg0, u8 arg1, s32 arg2) {
    struct Vec3F sp34;
    struct Vec3F sp28;

    if (func_15146078(arg0, &sp34, &sp28) != 0) {
        func_1514F8F8((u8 *)arg0 + 0x10, arg0, &sp34, &sp28, arg0->unkC, arg1, arg2);
    }
}

void func_1514FBFC(struct Arg1514FBFC *arg0, u8 arg1, s32 arg2) {
    struct Vec3F sp5C;
    f32 sp58;
    f32 sp54;
    struct Vec3F sp48;
    f32 sp44;
    f32 sp40;
    struct Vec3F sp34;
    f32 sp30;
    f32 sp2C;

    if (func_15144E80(&arg0->unkC, &sp5C, &sp48, &sp34) != 0) {
        func_15145128(&sp5C, &sp5C, &sp58, &sp54);
        func_15145128(&sp48, &sp48, &sp44, &sp40);
        func_15145128(&sp34, &sp34, &sp30, &sp2C);
        if (func_15144A74(&sp34, &arg0->unk0) < 0.0f) {
            sp34.x = -sp34.x;
            sp34.y = -sp34.y;
            sp34.z = -sp34.z;
        }
        func_1514F8F8(arg0->unk24, &sp34, &sp5C, &sp48, arg0->unk20, arg1, arg2);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_17CAF0/func_1514FCE8.s")

struct Local1514FEFC { u8 unk0[0x2C]; };
extern void func_1514F640(void *, struct Local1514FEFC *);
extern void func_1514FF44(struct Local1514FEFC *, s32, s32, u8, s32);

void func_1514FEFC(void *arg0, s32 arg1, s32 arg2, u8 arg3, s32 arg4) {
    struct Local1514FEFC sp24;

    func_1514F640(arg0, &sp24);
    func_1514FF44(&sp24, arg1, arg2, arg3, arg4);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_17CAF0/func_1514FF44.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_17CAF0/func_15150178.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_17CAF0/func_15150400.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_17CAF0/func_1515080C.s")

void func_15150D1C(struct Local15150D1CArg *arg0, u8 arg1, s32 arg2) {
    void *spACPtr;
    struct17 spC0;
    u8 spAC[0x14];
    struct17 spA0;
    f32 sp9C;
    s32 sp98;
    s32 count;
    s32 rand0;
    s32 rand1;
    f32 randf;

    count = (func_150ADA20() % (u32)(arg0->unk4 + 1)) + arg0->unk0;
    spACPtr = spAC;

    if (count != 0) {
        do {
            rand0 = func_150ADA20();
            rand1 = func_150ADA20();
            func_15143794((s16)((rand0 % (u32)(arg0->unk16 + 1)) + arg0->unk14),
                          (s16)((rand1 % (u32)(arg0->unk1A + 1)) + arg0->unk18),
                          100.0f,
                          &spC0.unk0);

            if ((func_150AC9C0(arg0->unk8, arg0->unkC, arg0->unk10,
                               spC0.unk0, spC0.unk4, spC0.unk8,
                               0, (s32)spACPtr,
                               &spA0.unk0, &spA0.unk4, &spA0.unk8,
                               &sp9C, &sp98, 0, 0.0f) != 0)
                    && (func_15145C90(sp98) != 0)
                    && (sp9C < arg0->unk1C)) {
                rand0 = (randf = func_150ADA68(), func_150ADA20());
                rand1 = func_150ADA20();
                func_151D9B8C(arg0->unk2C,
                              ((randf = randf) * arg0->unk24) + arg0->unk20,
                              (u8)((rand0 % 156U) + 0x64),
                              (s32)spACPtr,
                              &spA0,
                              (rand1 % (u32)(arg0->unk2A + 1)) + arg0->unk28,
                              1, 1, 1, arg1, arg2);
            }
            count--;
        } while (count != 0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_17CAF0/func_15150F90.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_17CAF0/func_151511FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_17CAF0/func_15151670.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_17CAF0/func_15151A38.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_17CAF0/func_15151D6C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_17CAF0/func_15152190.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_17CAF0/func_15152520.s")

void func_15152874(struct Local15152874Arg *arg0, u8 arg1, s32 arg2) {
    struct Local15152874Spawn sp58;
    s32 count;
    s32 rand0;
    s32 rand1;

    count = (func_150ADA20() % (u32)(arg0->unk4 + 1)) + arg0->unk0;
    sp58.unk0 = arg0->unk8;
    sp58.unk18 = arg0->unk24;
    sp58.unk30 = arg0->unk48;

    if (count != 0) {
        do {
            rand0 = func_150ADA20();
            rand1 = func_150ADA20();
            func_15143794((s16)((rand0 % (u32)(arg0->unk16 + 1)) + arg0->unk14),
                          (s16)((rand1 % (u32)(arg0->unk1A + 1)) + arg0->unk18),
                          (func_150ADA68() * arg0->unk20) + arg0->unk1C,
                          &sp58.unkC);

            sp58.unk1C = (func_150ADA68() * arg0->unk2C) + arg0->unk28;
            sp58.unk24 = (func_150ADA20() % (u32)(arg0->unk34 + 1)) + arg0->unk32;
            sp58.unk28 = (func_150ADA68() * arg0->unk40) + arg0->unk38;
            sp58.unk2C = (func_150ADA68() * arg0->unk44) + arg0->unk3C;

            if (arg0->unk30 != -1) {
                D_8008AC60[arg0->unk30]((u8 *)&sp58 + 0x20);
            } else {
                sp58.unk20 = 0xFF;
                sp58.unk21 = 0xFF;
                sp58.unk22 = 0xFF;
                sp58.unk23 = 0xFF;
            }

            func_150CCEB0(&sp58, arg1, arg2);
            count--;
        } while (count != 0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_17CAF0/func_15152ABC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_17CAF0/func_15152B38.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_17CAF0/func_15152F70.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_17CAF0/func_15153298.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_17CAF0/func_15153634.s")

void func_151539B4(struct Local151539B4Arg *arg0, u8 arg1) {
    struct Local151539B4Spawn sp7C;
    s32 count;
    s16 randS1;
    s16 randS2;
    f32 temp_f20;
    f32 temp_f22;
    f32 temp_f24;
    f32 temp_f2;
    f32 temp_f0;

    count = (func_150ADA20() % (u32)(arg0->unk2 + 1)) + arg0->unk0;
    sp7C.unk0 = arg0->unk4;
    sp7C.unk20 = arg0->unk28;
    sp7C.unk21 = arg0->unk29;
    sp7C.unk22 = arg0->unk2A;
    sp7C.unk23 = arg0->unk2B;
    sp7C.unk24 = arg0->unk2C;
    sp7C.unk25 = arg0->unk2D;
    sp7C.unk26 = arg0->unk2E;
    sp7C.unk27 = arg0->unk2F;
    sp7C.unk28 = arg0->unk30;
    sp7C.unk2C = arg0->unk36;
    sp7C.unk36 = arg0->unk42;
    sp7C.unk38 = arg0->unk44;

    if (count != 0) {
        do {
            randS1 = (func_150ADA20() % (u32)(arg0->unk14 + 1)) + arg0->unk10;
            randS2 = (func_150ADA20() % (u32)(arg0->unk16 + 1)) + arg0->unk12;
            temp_f20 = func_151423D8((u8)randS2);
            temp_f22 = func_151423D8((u8)(randS2 - 0x40));
            temp_f24 = func_151423D8((u8)randS1);
            temp_f2 = 10.0f * temp_f20;
            temp_f0 = func_151423D8((u8)(randS1 - 0x40));
            sp7C.unkC = temp_f2 * temp_f0;
            sp7C.unk10 = -10.0f * temp_f22;
            sp7C.unk14 = temp_f2 * temp_f24;
            sp7C.unk18 = (func_150ADA68() * arg0->unk1C) + arg0->unk18;
            sp7C.unk1C = (func_150ADA68() * arg0->unk24) + arg0->unk20;
            sp7C.unk2A = (func_150ADA20() % (u32)(arg0->unk34 + 1)) + arg0->unk32;
            sp7C.unk30 = (func_150ADA68() * arg0->unk3C) + arg0->unk38;
            sp7C.unk34 = (func_150ADA20() % (u32)(arg0->unk41 + 1)) + arg0->unk40;
            func_15156190(&sp7C, arg0->unk46, 0, arg1, 0);
            count--;
        } while (count != 0);
    }
}

extern void func_15153CCC(struct Local1514FEFC *, s32, s32, u8, s32);

void func_15153C84(void *arg0, s32 arg1, s32 arg2, u8 arg3, s32 arg4) {
    struct Local1514FEFC sp24;

    func_1514F640(arg0, &sp24);
    func_15153CCC(&sp24, arg1, arg2, arg3, arg4);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_17CAF0/func_15153CCC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_17CAF0/func_15153F18.s")

void *func_151541B8(struct Vec3F *arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, u8 arg5, s32 arg6) {
    void *ret;
    s32 flag;
    struct {
        f32 unk00;
        f32 unk04;
        f32 unk08;
        f32 unk0C;
        f32 unk10;
        f32 unk14;
        f32 unk18;
        f32 unk1C;
        f32 unk20;
        f32 unk24;
        struct Vec3F unk28;
        f32 unk34;
        f32 unk38;
        f32 unk3C;
        f32 unk40;
        f32 unk44;
        f32 unk48;
        f32 unk4C;
        s32 unk50;
        s16 unk54;
        s16 unk56;
        u8 unk58;
        u8 pad59[3];
        s32 unk5C;
        u8 unk60;
        u8 unk61;
        u8 unk62;
        u8 unk63;
        u8 unk64;
        u8 unk65;
        u8 unk66;
        u8 unk67;
        u8 unk68;
        u8 pad69;
        u8 unk6A;
        u8 pad6B;
        s32 unk6C;
        u8 unk70;
        u8 pad71;
        s16 unk72;
        s16 unk74;
        u8 pad76[2];
    } sp40;
    struct {
        s32 pad00;
        s32 pad04;
        f32 unk08;
        f32 unk0C;
        f32 unk10;
        f32 unk14;
        f32 unk18;
        u8 unk1C;
        u8 pad1D[3];
    } sp28;

    if (arg1 <= 0.0f) {
        return 0;
    }

    sp28.unk08 = 0.0f;
    sp28.unk0C = arg1;
    sp28.unk10 = arg2;
    sp28.unk14 = arg3;
    sp28.unk18 = arg3 / (arg1 * arg1);
    if (arg4 != 0) {
        flag = 1;
    } else {
        flag = 0;
    }
    sp28.unk1C = flag;

    sp40.unk08 = 0.0f;
    sp40.unk0C = arg4;
    sp40.unk00 = 1.0f;
    sp40.unk04 = 1.0f;
    if (arg4 != 0) {
        sp40.unk10 = 0.0f;
    } else {
        sp40.unk10 = func_150ADA68() * 360.0f;
    }
    sp40.unk14 = func_150ADA68() * 360.0f;
    if (arg4 != 0) {
        sp40.unk18 = 0.0f;
    } else {
        sp40.unk18 = func_150ADA68() * 360.0f;
    }
    sp40.unk1C = 1.0f;
    sp40.unk20 = 1.0f;
    sp40.unk24 = 1.0f;
    sp40.unk28 = *arg0;
    sp40.unk34 = 0.0f;
    sp40.unk38 = 0.0f;
    sp40.unk3C = 0.0f;
    if (arg4 != 0) {
        sp40.unk40 = 0.0f;
    } else {
        sp40.unk40 = (func_150ADA68() * D_800A6004) + D_800A6008;
    }
    if (arg4 != 0) {
        sp40.unk44 = (func_150ADA68() * D_800A600C) + D_800A6010;
    } else {
        sp40.unk44 = 0.0f;
    }
    if (arg4 != 0) {
        sp40.unk48 = 0.0f;
    } else {
        sp40.unk48 = (func_150ADA68() * D_800A6014) + D_800A6018;
    }
    sp40.unk4C = 0.0f;
    sp40.unk50 = 0x100140;
    sp40.unk56 = 0x54;
    sp40.unk58 = 0;
    sp40.unk5C = 0;
    sp40.unk60 = arg3;
    sp40.unk61 = 0xF;
    sp40.unk62 = 0;
    sp40.unk63 = 0;
    sp40.unk64 = 0;
    sp40.unk65 = 0;
    sp40.unk66 = 0;
    sp40.unk67 = 0;
    sp40.unk68 = 2;
    sp40.unk6A = 0;
    sp40.unk6C = 0;
    sp40.unk70 = 0;
    sp40.unk72 = 1;
    sp40.unk74 = 0xFF;
    sp40.unk54 = 0x12C;

    ret = func_15132A4C(&sp40, 0, 0, 0x18, arg5, arg6);
    if (ret != 0) {
        memcpy((u8 *)ret + 0x170, &sp28.unk08, 0x18);
    }
    return ret;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_17CAF0/func_1515452C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_17CAF0/func_15154684.s")

void *func_15154884(struct Vec3F *arg0, f32 arg1, f32 arg2, f32 arg3, u8 arg4, s32 arg5) {
    void *ret;
    struct {
        f32 unk00;
        f32 unk04;
        f32 unk08;
        f32 unk0C;
        f32 unk10;
        f32 unk14;
        f32 unk18;
        f32 unk1C;
        f32 unk20;
        f32 unk24;
        struct Vec3F unk28;
        f32 unk34;
        f32 unk38;
        f32 unk3C;
        f32 unk40;
        f32 unk44;
        f32 unk48;
        f32 unk4C;
        s32 unk50;
        s16 unk54;
        s16 unk56;
        u8 unk58;
        u8 pad59[3];
        s32 unk5C;
        u8 unk60;
        u8 unk61;
        u8 unk62;
        u8 unk63;
        u8 unk64;
        u8 unk65;
        u8 unk66;
        u8 unk67;
        u8 unk68;
        u8 pad69;
        u8 unk6A;
        u8 pad6B;
        s32 unk6C;
        u8 unk70;
        u8 pad71;
        s16 unk72;
        s16 unk74;
        u8 pad76[6];
    } sp40;
    struct {
        s32 pad00;
        f32 unk04;
        f32 unk08;
        f32 unk0C;
        f32 unk10;
        f32 unk14;
    } sp28;

    if (arg1 <= 0.0f) {
        return 0;
    }

    sp28.unk04 = arg1;
    sp28.unk08 = arg2;
    sp28.unk10 = 0.0f;
    sp40.unk08 = 0.0f;
    sp40.unk0C = 0.0f;
    sp40.unk00 = 1.0f;
    sp40.unk04 = 1.0f;
    sp28.unk0C = arg3;
    sp28.unk14 = D_800A601C / arg1;
    sp40.unk10 = func_150ADA68() * 360.0f;
    sp40.unk14 = func_150ADA68() * 360.0f;
    sp40.unk18 = func_150ADA68() * 360.0f;
    sp40.unk1C = 1.0f;
    sp40.unk20 = 1.0f;
    sp40.unk24 = 1.0f;
    sp40.unk28 = *arg0;
    sp40.unk34 = 0.0f;
    sp40.unk38 = 0.0f;
    sp40.unk3C = 0.0f;
    sp40.unk40 = (func_150ADA68() * D_800A6020) + D_800A6024;
    sp40.unk44 = 0.0f;
    sp40.unk48 = (func_150ADA68() * D_800A6028) + D_800A602C;
    sp40.unk4C = 0.0f;
    sp40.unk50 = 0x140;
    sp40.unk56 = 0x55;
    sp40.unk58 = 0;
    sp40.unk5C = 0;
    sp40.unk60 = 0xFF;
    sp40.unk61 = 0x12;
    sp40.unk62 = 0;
    sp40.unk63 = 0;
    sp40.unk64 = 0;
    sp40.unk65 = 0;
    sp40.unk66 = 0;
    sp40.unk67 = 0;
    sp40.unk68 = 2;
    sp40.unk6A = 0;
    sp40.unk6C = 0;
    sp40.unk70 = 0;
    sp40.unk72 = 1;
    sp40.unk74 = 0xFF;
    sp40.unk54 = 0x12C;

    ret = func_15132A4C(&sp40, 0, 0, 0x14, arg4, arg5);
    if (ret != 0) {
        memcpy((u8 *)ret + 0x170, &sp28.unk04, 0x14);
    }
    return ret;
}

s32 func_15154A88(void *arg0) {
    typedef struct {
        f32 unk0;
        f32 unk4;
        f32 unk8;
        f32 unkC;
        f32 unk10;
    } Struct15154A88;
    register Struct15154A88 *temp_v1;
    f32 temp_f0;
    f32 temp_f2;

    temp_v1 = (Struct15154A88 *)((s32)arg0 + 0x170);
    temp_f0 = sinf(*(f32 *)((s32)arg0 + 0x17C));
    temp_f2 = temp_v1->unk4 * temp_f0;
    *(f32 *)((s32)arg0 + 0x1C) = temp_f2;
    *(f32 *)((s32)arg0 + 0x18) = temp_f2;
    *(u8 *)((s32)arg0 + 0x70) = (f32)(u8)(u32)temp_v1->unk8 * temp_f0;
    temp_v1->unk0 -= (&D_800BE9A4)[0];
    if (temp_v1->unk0 <= 0.0f) {
        return 0;
    }

    temp_v1->unkC += temp_v1->unk10 * (&D_800BE9A4)[0];
    *(f32 *)((s32)arg0 + 0x20) += *(f32 *)((s32)arg0 + 0x50) * (&D_800BE9A4)[0];
    *(f32 *)((s32)arg0 + 0x24) += *(f32 *)((s32)arg0 + 0x54) * (&D_800BE9A4)[0];
    *(f32 *)((s32)arg0 + 0x28) += *(f32 *)((s32)arg0 + 0x58) * (&D_800BE9A4)[0];
    return 1;
}

typedef struct {
    u8 pad0[0x22];
    s16 unk22;
    u16 unk24;
    s16 unk26;
    s16 unk28;
    u8 pad2A[0x4];
    u8 unk2E;
    u8 pad2F[0x39];
    u8 unk68;
} Struct15154C90;

void func_15154C90(Struct15154C90 *arg0) {
    s32 temp;
    s8 failed;

    failed = 0;
    if (arg0->unk24 & 1) {
        arg0->unk22 -= D_800BE9E4;
        if (arg0->unk22 < 0) {
            failed = 1;
        }
    }
    temp = arg0->unk68 & 0xF;
    if (temp != 0) {
        if (failed == 0) {
            s32 ret;

            ret = D_8008ACC8[temp](arg0);
            if (ret == 0) {
                failed = 1;
            }
        }
    }
    if (arg0->unk24 & 8) {
        s16 temp_v1;

        temp_v1 = arg0->unk22;
        if (temp_v1 < arg0->unk26) {
            temp = (s16)(temp_v1 * (u32)arg0->unk28);
            if (temp < arg0->unk2E) {
                arg0->unk2E = temp;
            }
        }
    }
    if (failed) {
        func_1516972C((struct102 *) arg0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_17CAF0/func_15154D80.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_17CAF0/func_1515548C.s")

struct Local15155564 { u8 pad[0x2A]; u8 unk2A; };
extern void (*D_8008AD04[])(struct Local15155564 *, s32, u8);

void func_15155564(struct Local15155564 *arg0, s32 arg1, u8 arg2) {
    if (D_8008AD04[arg0->unk2A] != NULL) {
        D_8008AD04[arg0->unk2A](arg0, arg1, arg2);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_17CAF0/func_151555AC.s")

void func_1515572C(s32 arg0, u8 arg1) {
    struct Local1515572CData sp18;

    sp18 = D_800A6038;
    func_15169260(&sp18, 2, arg0, arg1);
}
