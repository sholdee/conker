#include <ultra64.h>

#include "functions.h"
#include "variables.h"

void func_151A9390(s32 arg0, s32 arg1, struct134 *arg2, s32 arg3, f32 arg4, f32 arg5, s32 arg6, s32 arg7, s32 arg8);
extern void (*D_80082F28[])(struct16 *, f32);
extern f32 D_80096650;
extern f32 D_80096648;
extern f32 D_8009664C;
extern f32 D_80096680;
extern f32 D_80096684;
extern u8 D_800C35E8;
extern void func_1510F800(s32);

typedef struct {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    s16 unk14;
    s16 unk16;
    f32 unk18;
    f32 unk1C;
    f32 unk20;
    f32 unk24;
    f32 unk28;
    f32 unk2C;
    u8 unk30;
    u8 unk31;
    u8 unk32;
    u8 unk33;
    u8 unk34;
    u8 pad35[3];
} Struct150139ACEntry;

typedef struct {
    struct16 *unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    f32 unk14;
    f32 unk18;
    f32 unk1C;
    f32 unk20;
    s16 unk24;
    s16 unk26;
    f32 unk28;
    f32 unk2C;
    f32 unk30;
    f32 unk34;
    f32 unk38;
    f32 unk3C;
    u8 unk40;
    u8 unk41;
    u8 unk42;
    u8 pad43;
    u16 unk44;
    u8 pad46[2];
    f32 unk48;
    u8 pad4C[0x14];
    s32 unk60;
    u8 unk64;
    u8 unk65;
    u8 pad66[2];
    s32 unk68;
    s32 unk6C;
} Struct150139ACLocal;

extern Struct150139ACEntry D_80095FA0[];


void func_15012FE0(void) {
    D_800BE570 = 0;
    D_800BE574 = 0;
    D_800BE575 = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_40490/func_15013000.s")
// requires jump table
#pragma GLOBAL_ASM("asm/nonmatchings/game_40490/func_150130B4.s")

s32 func_1501370C(struct16 *arg0) {
    u8 idx = arg0->unk17;
    void (*func)(void) = D_80082EA0[idx];

    if (func != NULL) {
        func();
    }
    return 1;
}

s32 func_1501374C(struct16 *arg0) {
    arg0->unk16 |= 4;
    func_1515D088(arg0);
    return 1;
}

// fat struct definition:
#pragma GLOBAL_ASM("asm/nonmatchings/game_40490/func_15013778.s")

s32 func_1501396C(struct16 *arg0) {
    u8 idx = arg0->unk17;
    void (*func)(void) = D_80082ECC[idx];

    if (func != NULL) {
        func();
    }
    return 1;
}

// another struct
s32 func_150139AC(struct16 *arg0, s32 idx) {
    Struct150139ACLocal tmp;
    Struct150139ACEntry *entry;
    struct260 *temp_v0;

    idx = *(s32 *)&arg0->unk18;
    arg0->unk16 |= 4;
    tmp.unk0 = arg0;
    tmp.unkC = 0.0f;

    switch (arg0->unk15 & 3) {
    default:
        tmp.unk4 = 1.0f;
        tmp.unk10 = 1000.0f;
        break;
    case 2:
        tmp.unk4 = (f32)(((s16 *)arg0)[5] * ((s16 *)arg0)[3]) * 4.0f;
        tmp.unk10 = (f32)(((s16 *)arg0)[4] + ((s16 *)arg0)[1]);
        break;
    case 0:
    case 1:
        tmp.unk4 = (f32)(((s16 *)arg0)[3] * ((s16 *)arg0)[3]) * D_80096648;
        tmp.unk10 = (f32)(((s16 *)arg0)[4] + ((s16 *)arg0)[1]);
        break;
    }

    entry = &D_80095FA0[idx];
    tmp.unk14 = entry->unk4;
    tmp.unk18 = entry->unk8;
    tmp.unk1C = entry->unkC;
    tmp.unk20 = entry->unk10;
    tmp.unk28 = entry->unk18;
    tmp.unk2C = entry->unk1C;
    tmp.unk60 = 0;
    tmp.unk64 = 0;
    tmp.unk65 = 0;
    tmp.unk68 = 0;
    tmp.unk24 = entry->unk14;
    tmp.unk26 = entry->unk16;
    tmp.unk30 = entry->unk20;
    tmp.unk34 = entry->unk24;
    tmp.unk38 = entry->unk28;
    tmp.unk3C = entry->unk2C;
    tmp.unk8 = entry->unk0;
    tmp.unk40 = entry->unk30;
    tmp.unk41 = entry->unk31;
    tmp.unk42 = entry->unk32;
    tmp.unk48 = D_8009664C;

    if (entry->unk34 != 0) {
        func_1510F800(0);
        tmp.unk6C = func_1510FD20((s32)((s16 *)arg0)[0], (s32)((s16 *)arg0)[2]);
    } else {
        tmp.unk6C = 0;
    }

    if (entry->unk33 != 0) {
        tmp.unk44 = func_1000FA64(0x4D, ((s16 *)arg0)[0], ((s16 *)arg0)[1], ((s16 *)arg0)[2], 0x5DC0, 0x3E8, 0x12C, 0, NULL, 0, 0, 0);
    } else {
        tmp.unk44 = 0;
    }

    temp_v0 = func_151491F4(0x12C, -1, 6, 0, 0xA, 0x70, 0xFF, 0);
    if (temp_v0 != NULL) {
        memcpy((u8 *)temp_v0 + 0x28, &tmp, sizeof(tmp));
    }
    return 1;
}

s32 func_15013C38(struct16 *arg0) {
    s32 idx;
    f32 temp_f;
    void (*func)(struct16 *, f32);

    arg0->unk16 |= 4;
    idx = *(s32 *)&arg0->unk18;

    if ((((u8 *)D_800D2E4C)[0x11] & 4) && (D_800BE9F0 == 0x13)) {
        return 1;
    }

    if (D_800C35EA == 1) {
        if ((D_800C35E8 == 0xF) || (D_800C35E8 == 0x10) || (D_800C35E8 == 0x11)) {
            return 1;
        }
    }

    if (idx >= 6) {
        return 1;
    }

    func = D_80082F28[idx];
    if (func != NULL) {
        temp_f = (f32)arg0->unk1C * D_80096650;
        func(arg0, temp_f);
    }

    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_40490/func_15013D38.s")
// #NON-MATCHING: looks close but think its wrong
// s32 func_151BE850(struct17 *arg0, s32 arg1, u8 arg2, u8 arg3, u8 arg4, u8 arg5, u8 arg6);
// s32 func_15013D38(struct47 *arg0) {
//     s32 tmp1;
//     s32 tmp2;
//     s32 tmp3;
//     s32 tmp4;
//     struct17 *tmp;
//
//     arg0->unk16 |= 4;
//
//     tmp->unk0 = arg0->unk0;
//     tmp->unk4 = arg0->unk2;
//     tmp->unk8 = arg0->unk4;
//
//     tmp4 = 1;
//     tmp1 = arg0->unk18;
//     if (tmp1) {
//         tmp4 = tmp1;
//     }
//
//     tmp2 = arg0->unk10;
//     tmp3 = arg0->unk1F;
//
//     func_151BE850(tmp, tmp2, tmp4, tmp3, 0xff, 1, 1);
//     return 1;
// }

#pragma GLOBAL_ASM("asm/nonmatchings/game_40490/func_15013DE8.s")

s32 func_15013F9C(s32 arg0) {
    func_151CD2C0(arg0, 0xFF, 1);
    return 1;
}

s32 func_15013FC4(struct133 *arg0) {
    u8 idx = arg0->unk1B;
    void (*func)(void) = D_80082F40[idx];

    if (func != NULL) {
        func();
    }
    return 1;
}

s32 func_15014004(struct134 *arg0) {
    s32 temp_v1 = arg0->unk1C;
    if (temp_v1 < 0) {
        return 1;
    }
    if (temp_v1 >= 6) {
        return 1;
    }
    D_800E0900[temp_v1] = arg0;
    return 1;
}

s32 func_15014040(struct134 *arg0) {
    s32 temp_v0 = arg0->unk18;
    arg0->unk16 |= 4;
    if (temp_v0 == 0) {
        D_800D9A20 = arg0;
    } else if (temp_v0 == 1) {
        D_800D9A24 = arg0;
    }
    return 1;
}

s32 func_1501407C(s32 arg0) {
    D_800D987C = (u8)0;
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_40490/func_15014094.s")
// NON-MATCHING: kinda right idea, but not executed correctly
// void func_15014094(struct134 *arg0) {
//     struct135 tmp;
//
//     tmp.unk0 = arg0;
//     // tmp.unk4 = tmp.unk0;
//     tmp.unk0->unk16 |= 4;
//     // tmp.unkC = tmp.unk0;
//     // arg0 = tmp.unk0;
//     tmp.unk10 = func_15144598(tmp.unk4); //, tmp.unk0);
//     tmp.unk14 = 0.0f;
//     func_1510F800(0);
//     tmp.unk18 = func_1510FD20(arg0->unk0, arg0->unk4, arg0);
//     tmp.unk1C = 0;
//     tmp.unk8 = func_15149130(0x12C, -1, 0x21, -1, 0, 0, 0x34, 0xFF, 1);
//     if (tmp.unk8 != 0) {
//         memcpy(tmp.unk8 + 0x28, &tmp, 0x34);
//     }
// }

s32 func_15014144(struct134 *arg0) {
    s32 flags;
    s32 bit8;
    s32 bit4;
    s32 bit2;
    s32 bit1;
    s32 bit16;

    flags = arg0->unk18;

    if (flags & 8) {
        bit8 = 8;
    } else {
        bit8 = 0;
    }

    if (flags & 4) {
        bit4 = 4;
    } else {
        bit4 = 0;
    }

    if (flags & 2) {
        bit2 = 0;
    } else {
        bit2 = 2;
    }

    if (flags & 1) {
        bit1 = 1;
    } else {
        bit1 = 0;
    }

    if (flags & 0x10) {
        bit16 = 0x10;
    } else {
        bit16 = 0;
    }

    func_151A9390((u8)(bit16 | bit1 | bit2 | bit4 | bit8), *((u8 *)arg0 + 0x1F), arg0, 0, *(f32 *)&D_8009667C, 100.0f, -1, 0xFF, 1);
    return 1;
}

s32 func_15014220(struct16 *arg0) {
    struct {
        f32 unk0;
        struct16 *unk4;
        u8 unk8;
    } tmp;
    struct260 *temp_v0;

    arg0->unk16 |= 4;
    tmp.unk8 = 1;
    tmp.unk4 = arg0;
    tmp.unk0 = 0.0f;

    temp_v0 = func_15149130(0x12C, -1, 0x26, -1, 0, 0x24, (struct37 *)0xC, 0xFF, 0);
    if (temp_v0 != NULL) {
        memcpy((u8 *)temp_v0 + 0x28, &tmp, 0xC);
    }
    return 1;
}

s32 func_150142AC(struct134 *arg0) {
    s32 idx;

    idx = ((u8 *)arg0)[0x1B];
    arg0->unk16 |= 4;
    if ((idx < 0) || (idx >= 3)) {
        return 1;
    }
    D_800D9AA0[idx] = arg0;
    return 1;
}

s32 func_150142EC(struct134 *arg0) {
    struct {
        struct134 *unk0;
        f32 unk4;
        f32 unk8;
        f32 unkC;
        f32 unk10;
        f32 unk14;
    } tmp;
    struct260 *temp_v0_2;
    f32 temp_f4;
    f32 temp_f6;
    f32 temp_f2;
    f32 temp_f8;
    register f32 temp_f0;

    arg0->unk16 |= 4;
    if (D_80082FA0 >= 2) {
        return 1;
    }

    if ((((u8 *)D_800D2E4C)[0x11] & 4) && (D_800BE9F0 == 0x13)) {
        return 1;
    }

    temp_f4 = (f32)(arg0->unk1C & 0xFFFFU) * D_80096680;
    temp_f6 = (f32)(((u32)arg0->unk1C >> 16) & 0xFFFFU) * D_80096680;
    temp_f2 = (f32)(arg0->unk20 & 0xFFFFU) * D_80096680;
    temp_f8 = (f32)(((u32)arg0->unk20 >> 16) & 0xFFFFU) * D_80096680;

    temp_f0 = func_1514462C((s32)arg0);

    tmp.unk0 = arg0;
    tmp.unk4 = (temp_f4 * temp_f0) * D_80096684;
    tmp.unk8 = (temp_f6 * temp_f0) * D_80096684;
    tmp.unkC = temp_f2;
    tmp.unk10 = temp_f8;
    tmp.unk14 = 0.0f;

    temp_v0_2 = func_15149130(0x12C, -1, 0x29, -1, 0, 0, (struct37 *)0x18, 0xFF, 0);
    if (temp_v0_2 != NULL) {
        memcpy((u8 *)temp_v0_2 + 0x28, &tmp, 0x18);
    }
    return 1;
}
#pragma GLOBAL_ASM("asm/nonmatchings/game_40490/func_150144B8.s")
#pragma GLOBAL_ASM("asm/nonmatchings/game_40490/func_1501474C.s")
#pragma GLOBAL_ASM("asm/nonmatchings/game_40490/func_15014B60.s")

s32 func_15014F6C(struct134 *arg0) {
    struct {
        struct134 *unk0;
        s32 unk4;
        s32 unk8;
        s32 unkC;
        f32 mtx[4][4];
        u8 unk50;
        u8 unk51;
    } tmp;
    struct260 *temp_v0;
    s32 flag;

    arg0->unk16 |= 4;
    tmp.unk51 = arg0->unk20;
    if (arg0->unk1C & 1) {
        flag = 1;
    } else {
        flag = 0;
    }
    tmp.unk50 = flag;
    tmp.unk0 = arg0;
    tmp.unk4 = arg0->unk18 & 0xFFFF;
    tmp.unk8 = ((u32)arg0->unk18 >> 16) & 0xFFFF;
    tmp.unkC = ((u32)func_150ADA20() % (u32)(tmp.unk8 + 1)) + tmp.unk4;
    func_150A8050(tmp.mtx, *(f32 *)&arg0->unkC, *(f32 *)&arg0->unk10, 0);

    tmp.mtx[3][0] = (f32)arg0->unk0;
    tmp.mtx[3][1] = (f32)(s16)arg0->unk2;
    tmp.mtx[3][2] = (f32)arg0->unk4;

    temp_v0 = func_15149130(0x12C, -1, 0x31, -1, 0, 0x2A, (struct37 *)0x54, 0xFF, 0);
    if (temp_v0 != NULL) {
        memcpy((u8 *)temp_v0 + 0x28, &tmp, 0x54);
    }
    return 1;
}

s32 func_150150A4(void) {
    struct17 *temp_v0 = func_1515F1B0();
    if (temp_v0 == NULL) {
        return 1;
    }

    func_1515F25C(&D_800DCDC4, temp_v0);
    D_800DCD90 += temp_v0->unk8;
    return 1;
}

s32 func_15015104(struct134 *arg0) {
    struct {
        struct134 *unk0;
        u8 unk4;
        u8 pad5[3];
        s32 unk8;
        u8 unkC;
        u8 padD[3];
        s32 unk10;
    } tmp;
    struct260 *temp_v0;
    s32 temp_v1;
    s32 temp_t0;
    s32 temp_v0_2;

    *(u8 *)&arg0->unk14 = 1;
    tmp.unk0 = arg0;
    tmp.unk4 = arg0->unk1C;

    func_1510F800(0);
    tmp.unk8 = func_1510FD20(arg0->unk0, arg0->unk4);

    temp_v1 = arg0->unk20;
    if (temp_v1 != 0) {
        temp_t0 = 1;
    } else {
        temp_t0 = 0;
    }
    if (temp_v1 != 0) {
        temp_v0_2 = 2;
    } else {
        temp_v0_2 = 0;
    }
    tmp.unkC = temp_v0_2 | temp_t0;
    tmp.unk10 = 0;

    temp_v0 = func_15149130(0x12C, -1, -1, -1, 0, 0x2C, (struct37 *)0x14, 0xFF, 0);
    if (temp_v0 != NULL) {
        memcpy((u8 *)temp_v0 + 0x28, &tmp, 0x14);
    }
    return 1;
}
extern f32 D_800966B4;

s32 func_150151D4(struct134 *arg0) {
    struct {
        struct134 *unk0;
        f32 unk4;
        s16 unk8;
        f32 unkC;
        f32 unk10;
        f32 unk14;
        f32 unk18;
        f32 unk1C;
        f32 unk20;
        u8 pad24[0x14];
        s32 unk38;
        s8 unk3C;
        s8 unk3D;
        s32 unk40;
        s32 unk44;
    } tmp;
    struct260 *temp_v0;

    arg0->unk16 |= 4;
    *(u8 *)&arg0->unk14 = 1;

    tmp.unk0 = arg0;
    tmp.unk4 = 0.0f;
    tmp.unk8 = -1;
    tmp.unkC = (f32)arg0->unk0;
    tmp.unk10 = (f32)(s16)arg0->unk2;
    tmp.unk14 = (f32)arg0->unk4;
    tmp.unk18 = (f32)(s16)arg0->unk6;
    tmp.unk1C = (f32)(s16)arg0->unk8;
    tmp.unk20 = D_800966B4;
    tmp.unk40 = 0;
    tmp.unk3D = 0;
    tmp.unk3C = 0;
    tmp.unk38 = 0;

    func_1510F800(0);
    tmp.unk44 = func_1510FD20(arg0->unk0, arg0->unk4);

    temp_v0 = func_15149130(0x12C, -1, 0x3C, -1, 0, 0x2D, (struct37 *)0x48, 0xFF, 0);
    if (temp_v0 != NULL) {
        memcpy((u8 *)temp_v0 + 0x28, &tmp, 0x48);
    }
    return 1;
}

s32 func_15015300(struct134 *arg0) {
    void (*func)(void);
    s32 idx = arg0->unk1C;

    if ((idx < 0) || (idx >= 2)) {
        return 1;
    }

    func = D_80082F70[idx];
    if (func != NULL) {
        func();
    }

    return 1;
}


#pragma GLOBAL_ASM("asm/nonmatchings/game_40490/func_15015354.s")
s32 func_15015644(struct134 *arg0) {
    struct {
        struct134 *unk0;
        f32 unk4;
        s32 unk8;
        s8 unkC;
    } tmp;
    struct260 *temp_v0;

    arg0->unk16 |= 4;
    *(u8 *)&arg0->unk14 = 1;

    tmp.unk0 = arg0;
    tmp.unk4 = func_15144598(arg0);
    func_1510F800(0);
    tmp.unk8 = func_1510FD20(arg0->unk0, arg0->unk4);
    tmp.unkC = 0;

    temp_v0 = func_15149130(0x12C, -1, 0x44, -1, 0, 0x2F, (struct37 *)0x10, 0xFF, 0);
    if (temp_v0 != NULL) {
        memcpy((u8 *)temp_v0 + 0x28, &tmp, 0x10);
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_40490/func_150156F4.s")
