#include <ultra64.h>
#define func_1502B7F0 func_1502B7F0__proto
#include "functions.h"
#undef func_1502B7F0
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_13D350/func_1510FEA0.s")

extern s32 D_800BE628;
void func_150A7A48(f32 a[4][4], f32 b[4][4], f32 c[4][4]);
void func_151102CC(f32 a0[4][4], f32 a1, f32 a2, f32 a3);

void func_151102CC(f32 arg0[4][4], f32 arg1, f32 arg2, f32 arg3) {
    f32 sp28[4][4];

    func_150A8050(arg0, 0.0f, arg2, 0.0f);
    func_150A8050(sp28, arg1, 0.0f, 0.0f);
    func_150A7A48(arg0, sp28, arg0);
    func_150A8050(sp28, 0.0f, 0.0f, arg3);
    func_150A7A48(arg0, sp28, arg0);
}

void func_15110360(s32 arg0, f32 arg1[4][4], f32 arg2, f32 arg3, f32 arg4) {
    func_151102CC(arg1, arg2, arg3, arg4);
    func_150A7A48(arg1, (f32 (*)[4])((u8 *)((struct259 *)D_800BE628 + arg0) + 0xBC), arg1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_13D350/func_151103C8.s")

Gfx *func_1501A680(Gfx *arg0);
Gfx *func_1501A6CC(Gfx *arg0, s32 a, s32 b, s32 c, s32 d);

Gfx *func_15110544(Gfx *gfx, s32 a, s32 b, s32 c, s32 d, u8 r, u8 g, u8 bl) {
    s32 color;

    gDPPipeSync(gfx++);
    gDPSetOtherMode(gfx++, 0x302C0F, 4);
    gfx = func_1501A680(gfx);
    color = GPACK_RGBA5551(r, g, bl, 1);
    gDPSetFillColor(gfx++, (color << 16) | color);
    gfx = func_1501A6CC(gfx, a, b, c, d);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_13D350/func_15110600.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_13D350/func_151106A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_13D350/func_151108C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_13D350/func_15110CFC.s")

extern s32 *D_800DBE80;
extern s32 *D_800891BC[];
s32 func_1502B7F0();
void func_10004074();
void func_1510D694(s32);
void func_15111858(void);

void func_1511172C(s32 arg0) {
    s32 i;
    struct104 *var_v0;
    struct104 * volatile *var_s3;
    s32 **var_s0;

    var_s3 = (struct104 * volatile *)&D_800B0DF0;
    if (arg0 == 1) {
        var_s3 = (struct104 * volatile *)&D_800B0DF0;
        (*var_s3)->unk8 = 1;
        var_s0 = &D_800DBE80;
        if (D_800DBE80 != 0) {
            s32 *temp_v0;

            temp_v0 = D_800DBE80;
            func_10004074(temp_v0);
        }
        func_15111858();
        return;
    }

    var_v0 = *var_s3;
    if (arg0 != var_v0->unk9) {
        if (var_v0->unk8 == 4) {
            if (D_80038080 != 0) {
                for (i = 0; i != 0x168; i++) {
                    func_1510D694(D_800891BC[(*var_s3)->unk9][0] + i);
                }
            }
            var_s0 = &D_800DBE80;
            func_10004074(*var_s0);
            (*var_s3)->unk9 = arg0;
            func_1502B7F0(var_s0, 2, 0xD, (*var_s3)->unk9);
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_13D350/func_15111858.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_13D350/func_15111AF4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_13D350/func_15112520.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_13D350/func_15112A80.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_13D350/func_15113180.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_13D350/func_15113218.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_13D350/func_151135C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_13D350/func_151137D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_13D350/func_15113C88.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_13D350/func_15113E54.s")

extern s32 *D_800DBF94;

s32 func_15114050(struct131 *arg0, s32 arg1) {
    if (((u8 *)arg0)[0x4F] & 0x80) {
        if (arg1 == -1) {
            return 1;
        }
        if (D_800DBF94[arg0 - D_800DBEF4] & (1 << arg1)) {
            return 1;
        }
    }
    return 0;
}

s32 func_151140C4(struct131 *arg0) {
    s32 i;

    i = 0;
    if (((u8 *)arg0)[0x4F] & 0x80) {
        for (; i != 32; i++) {
            if (D_800DBF94[arg0 - D_800DBEF4] & (1 << i)) {
                return i;
            }
        }
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_13D350/func_15114188.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_13D350/func_15114348.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_13D350/func_1511473C.s")

void func_150A7A48(f32 a[4][4], f32 b[4][4], f32 c[4][4]);

struct Struct151148A8 {
    f32 unk0;
    f32 unk4;
    f32 unk8;
};

void func_151148A8(f32 arg0[4][4], struct Struct151148A8 *arg1) {
    f32 sp18[4][4];

    func_150A8050(arg0, 0.0f, arg1->unk4, 0.0f);
    func_150A8050(sp18, arg1->unk0, 0.0f, arg1->unk8);
    func_150A7A48(sp18, arg0, arg0);
}

struct Struct1511490C {
    char pad0[0x10];
    s16 unk10;
    s16 unk12;
    s16 unk14;
    char pad16[2];
    f32 unk18;
    char pad1C[0x10];
    s32 unk2C;
    s32 unk30;
    s32 unk34;
};

void func_150A7CB0(f32 mtx[4][4], s32 x, s32 y, s32 z);

void func_1511490C(f32 arg0[4][4], struct Struct1511490C *arg1) {
    f32 sp20[4][4];

    func_151148A8(arg0, arg1);
    arg0[3][0] = arg1->unk10;
    arg0[3][1] = arg1->unk12 + arg1->unk18;
    arg0[3][2] = arg1->unk14;
    func_150A7CB0(sp20, arg1->unk2C, arg1->unk30, arg1->unk34);
    func_150A7A48(sp20, arg0, arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_13D350/func_151149AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_13D350/func_15114A1C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_13D350/func_15114B94.s")

s32 func_15114CC4(void *a0, s32 a1, s32 *a2, s32 a3) {
    s16 *v1 = *(s16 **)((u8 *)a0 + 0x18);

    if (v1 != 0 && (*a2 != 0 || *(s32 *)((u8 *)a0 + 0x1C) == 0)) {
        *(s32 *)((u8 *)a0 + 0x1C) = 1;
        *(s16 *)((u8 *)a0 + 0x2) = v1[8];
        *(s16 *)((u8 *)a0 + 0x4) = v1[9];
        *(s16 *)((u8 *)a0 + 0x6) = v1[10];
        return 0;
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_13D350/func_15114D24.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_13D350/func_15114F04.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_13D350/func_15114F44.s")
