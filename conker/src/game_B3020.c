#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_B3020/func_15085B70.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_B3020/func_15085BE8.s")

extern f32 D_800D2360[];
extern u8 D_800D237C[];

u8 func_15085DA8(f32 arg0) {
    s32 i = 0;

    while (D_800D2360[i] <= arg0) {
        i++;
    }
    return D_800D237C[i];
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_B3020/func_15085DF8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_B3020/func_15086098.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_B3020/func_15086364.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_B3020/func_15086BD0.s")

extern void func_150A3194(s32, s32, s32, s32, s32);

typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
    s16 unk8;
    s16 unkA;
    s16 unkC;
    s16 unkE;
} B3020Struct;

extern B3020Struct *D_800D2350;

void func_15086C70(s32 arg0) {
    s16 temp = D_800D2350[arg0].unk4;
    func_150A3194(3, 0xB, D_800D2350[arg0].unk0, D_800D2350[arg0].unk2, temp);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_B3020/func_15086CBC.s")

extern s16 D_80087290;

s32 func_15086D48(s32 arg0) {
    s32 i;

    for (i = 0; i < D_80087290; i++) {
        if (arg0 == ((u8 *)D_800D2350)[i * 16 + 7]) {
            return i;
        }
    }
    return 0xFF;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_B3020/func_15086D94.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_B3020/func_150870D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_B3020/func_15087350.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_B3020/func_15087CC0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_B3020/func_15087DCC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_B3020/func_15087E54.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_B3020/func_15087EF0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_B3020/func_15087FC4.s")

extern u8 *D_800872A0;

struct Struct15087FEC {
    char pad0[4];
    f32 unk4;
    char pad8[0x84 - 8];
};

void func_15087FEC(s32 arg0, s32 arg1) {
    struct Struct15087FEC *p;
    if (D_800872A0 == 0) {
        return;
    }
    p = (struct Struct15087FEC *)(arg0 * sizeof(struct Struct15087FEC) + (s32)D_800872A0);
    p->unk4 = (f32)arg1 * (1.0f / 256.0f);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_B3020/func_1508802C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_B3020/func_150880F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_B3020/func_150881CC.s")

struct Struct15088218 {
    char pad0[8];
    f32 unk8;
    char padC[0x24 - 0xC];
    s16 unk24;
    char pad26[0x84 - 0x26];
};

s32 func_15088218(s32 arg0) {
    struct Struct15088218 *p;
    s32 v;
    if (D_800872A0 == 0) {
        return 0;
    }
    p = (struct Struct15088218 *)(arg0 * sizeof(struct Struct15088218) + (s32)D_800872A0);
    v = p->unk24;
    return (v << 4) + (s32)(p->unk8 * 16.0f);
}

struct Struct15088270 {
    char pad0[0x14];
    f32 unk14;
    char pad18[0x84 - 0x18];
};

s32 func_15088270(s32 arg0) {
    struct Struct15088270 *p;
    if (D_800872A0 == 0) {
        return 0;
    }
    p = (struct Struct15088270 *)(arg0 * sizeof(struct Struct15088270) + (s32)D_800872A0);
    return (s32)p->unk14;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_B3020/func_150882B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_B3020/func_150882E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_B3020/func_150883B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_B3020/func_1508855C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_B3020/func_150885EC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_B3020/func_1508868C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_B3020/func_15088780.s")

extern u8 *D_800872A0;

s32 func_150887F8(void) {
    u8 *p = D_800872A0;
    if (p == 0) {
        return 0;
    }
    return p[0x46] == 0xFF;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_B3020/func_15088824.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_B3020/func_150888A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_B3020/func_15088A08.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_B3020/func_15088D58.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_B3020/func_15088F30.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_B3020/func_1508907C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_B3020/func_150891E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_B3020/func_150896EC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_B3020/func_15089BB0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_B3020/func_15089BC0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_B3020/func_15089F9C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_B3020/func_1508A1BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_B3020/func_1508A6FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_B3020/func_1508B194.s")

extern s8 D_8008FD90;
extern s16 *D_8008FDD4;

void func_1508B1D4(s32 arg0) {
    if (arg0 < D_8008FD90) {
        *(s16 *)((u8 *)D_8008FDD4 + arg0 * 12 + 0x70) = 0;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_B3020/func_1508B20C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_B3020/func_1508B2A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_B3020/func_1508B3F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_B3020/func_1508B9BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_B3020/func_1508BC20.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_B3020/func_1508BF14.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_B3020/func_1508C194.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_B3020/func_1508C1A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_B3020/func_1508C5B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_B3020/func_1508C9CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_B3020/func_1508CA88.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_B3020/func_1508CAD8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_B3020/func_1508D850.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_B3020/func_1508DA1C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_B3020/func_1508DAEC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_B3020/func_1508DC24.s")

void func_1508E6C8(void) {
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_B3020/func_1508E6D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_B3020/func_1508E780.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_B3020/func_1508E89C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_B3020/func_1508EB90.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_B3020/func_1508EBF8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_B3020/func_1508EC5C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_B3020/func_1508ECC0.s")

typedef struct {
    s16 unk0;
    s16 unk2;
    s32 unk4;
    s32 unk8[4];
} Struct1508EDBC;

void func_1508EDBC(s32 arg0) {
    if (arg0 < D_80087380) {
        ((Struct1508EDBC *)D_800D23C0)[arg0].unk2 = 0;
        ((Struct1508EDBC *)D_800D23C0)[arg0].unk4 = 0;
        ((Struct1508EDBC *)D_800D23C0)[arg0].unk0 = 0;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_B3020/func_1508EE0C.s")
