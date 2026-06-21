#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern void (*D_8008FC70[])(void *, s16, void *);
extern void *func_151D8868(void *arg0, s32 arg1, s32 arg2, s32 arg3);

#pragma GLOBAL_ASM("asm/nonmatchings/game_200930/func_151D3480.s")

struct Sub151D3D50 {
    s16 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
};

struct Vec151D3D50 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
};

s32 func_151D3D50(void *arg0) {
    struct Sub151D3D50 *p = (struct Sub151D3D50 *)((u8 *)arg0 + 0x170);
    if (p->unk0 > 0) {
        p->unk4 = p->unk4 + p->unk8 * D_800BE9A4;
        p->unk4 = func_15144B68(p->unk4);
        *(f32 *)((u8 *)arg0 + 0x24) = *(f32 *)((u8 *)arg0 + 0x54) + sinf(p->unk4) * p->unkC;
        p->unk0 = p->unk0 - D_800BE9E4;
    } else {
        *(struct Vec151D3D50 *)((u8 *)arg0 + 0x20) = *(struct Vec151D3D50 *)((u8 *)arg0 + 0x50);
    }
    return 1;
}

void func_15143134(void *, s32, s32);

void func_151D3E04(s32 *arg0, f32 *arg1, void *arg2, u8 arg3, f32 arg4) {
    if (arg0[0x1D4 / 4] != 0) {
        func_15143134(arg2, (s32)arg1, arg0[0x1D4 / 4] + (arg3 << 6));
    } else {
        arg1[0] = *(f32 *)((u8 *)arg0 + 0x14);
        arg1[1] = *(f32 *)((u8 *)arg0 + 0x18) + arg4;
        arg1[2] = *(f32 *)((u8 *)arg0 + 0x1C);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_200930/func_151D3E6C.s")

void func_151D3F14(f32 *arg0, u8 arg1, s32 arg2) {
    Header header;
    Header2 header2;

    header.unk0 = 3;
    header.unk1 = -1;
    header.unk2 = (func_150ADA20() % 3U) + 4;
    header.unk4 = 0;

    header2.unk0 = (s32) arg0[0];
    header2.unk4 = (s32) arg0[1];
    header2.unk8 = (s32) arg0[2];

    func_151602C0(&header, &header2, (func_150ADA20() % 13U) + 0x14, 0xFF, 0xE8, 0xAB, 0xFF, 0, 0, arg1, arg2);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_200930/func_151D3FF4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_200930/func_151D40D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_200930/func_151D42E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_200930/func_151D4408.s")

struct S151D4668 {
    void *unk0;
    u8 unk4;
};

void func_151D4668(void *arg0) {
    struct S151D4668 sp18;
    sp18.unk0 = arg0;
    sp18.unk4 = *((u8 *)arg0 + 0x3B);
    func_151494E0((s32)&sp18, 0x3C);
}

struct S151D469C {
    void *unk0;
    u8 unk4;
    u8 pad5;
    s16 unk6;
    u8 unk8;
    u8 pad9[3];
    f32 unkC;
    u8 unk10;
    u8 pad11[3];
    u8 unk14[0xC];
};

void func_151D469C(void *arg0, s32 a1, s32 a2, s32 a3, s32 a4) {
    struct S151D469C sp38;
    struct260 *temp_v0;

    sp38.unk0 = arg0;
    sp38.unk4 = *((u8 *)arg0 + 0x3B);
    sp38.unk8 = *((u8 *)&a1 + 3);
    sp38.unkC = 0.0f;
    sp38.unk6 = -1;
    sp38.unk10 = 0;

    if (sp38.unk8 == 6) {
        sp38.unk6 = 0x82;
    }

    if (*(s32 *)((u8 *)arg0 + 0x1D4) != 0) {
        if ((*((u8 *)arg0 + 0x74) & 0xF) != 0xF) {
            D_8008FC70[*((u8 *)((s16 *)&a1 + 1) + 1)](arg0, sp38.unk6, &sp38.unk14);
            sp38.unk10 |= 1;
        }
    }

    temp_v0 = func_15149130((s16)a2, -1, 0x41, -1, 1, 0x35, (struct37 *)0x20, *((u8 *)&a3 + 3), a4);
    if (temp_v0 != NULL) {
        memcpy((void *)((s32)temp_v0 + 0x28), &sp38, 0x20);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_200930/func_151D4794.s")

void func_151D4C38(void *arg0, struct S151D469C *arg1, u8 arg2) {
    struct S151D469C *p;

    p = (struct S151D469C *)((u8 *)arg0 + 0x28);
    if (arg2 == 0x3C) {
        if ((arg1->unk0 == p->unk0) || (arg1->unk4 == p->unk4)) {
            func_1516972C((struct102 *)arg0);
        }
    } else if (arg2 == 4) {
        if ((arg1->unk0 == p->unk0) || (arg1->unk4 == p->unk4)) {
            p->unk10 = p->unk10 & ~1;
        }
block_151D4C38:
        ;
    } else {
        func_15149514((s32)arg1, arg2, (s32)p, (s32)&p->unk4, (s32)arg0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_200930/func_151D4D04.s")

void func_151D469C(void *arg0, s32 a1, s32 a2, s32 a3, s32 a4);

void func_151D4D58(void *arg0) {
    func_151D469C(arg0, 0, 0x50, 0xFF, 1);
    func_151D469C(arg0, 1, 0x50, 0xFF, 1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_200930/func_151D4DAC.s")

void func_151D5148(void *arg0) {
    s16 *p = *(s16 **)((u8 *)arg0 + 0x31C);
    if (p[0x24 / 2] > 0) {
        p[0x24 / 2]--;
        p = *(s16 **)((u8 *)arg0 + 0x31C);
    }
    p[0x1AA / 2]++;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_200930/func_151D5174.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_200930/func_151D5334.s")

struct S151D5404_30 {
    u8 unk0;
    u8 pad1;
    s16 unk2;
    u8 unk4;
    u8 unk5;
    u8 unk6;
    u8 pad7;
};

struct S151D5404_38 {
    struct17 unk0;
    f32 unkC;
    f32 unk10;
    f32 unk14;
    u8 unk18;
    u8 pad19[7];
};

void func_151D5404(struct17 *arg0, f32 arg1, f32 arg2, f32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7) {
    struct S151D5404_38 sp38;
    struct S151D5404_30 sp30;
    void *temp_v0;
    s32 i;

    sp38.unk0 = *arg0;
    sp38.unkC = arg1;
    sp38.unk10 = arg2;
    sp38.unk14 = arg3;
    sp30.unk0 = 1;
    sp30.unk2 = (func_150ADA20() % (u32)((s16)arg5 + 1)) + (s16)arg4;
    sp30.unk4 = 0;
    sp30.unk6 = 0;

    for (i = 0; i < D_80082FA0 + 1; i++) {
        sp30.unk5 = 1 << i;
        sp38.unk18 = i;
        temp_v0 = func_151D8868(&sp30, 0x1C, 0xFF, 0);
        if (temp_v0 != NULL) {
            memcpy((u8 *)temp_v0 + 0x18, &sp38, 0x1C);
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_200930/func_151D5514.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_200930/func_151D5648.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_200930/func_151D5714.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_200930/func_151D57F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_200930/func_151D5A18.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_200930/func_151D5B6C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_200930/func_151D5D60.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_200930/func_151D5E30.s")
