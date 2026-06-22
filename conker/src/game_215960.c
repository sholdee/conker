#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern s32 D_800E0A74;
extern u8 D_800E0B96;
extern u8 D_800E0B97;
extern Gfx D_80090028;
extern u8 D_800917F8;
extern u8 D_80091804;
extern u8 D_80091810;
extern s32 (*D_8008FFF4[])(s32);
extern s32 D_80000300;
extern u8 D_800BE616;
extern u8 D_800BE740;
extern s8 D_8008FD90;
extern s8 D_800E0BD3;
extern s32 *D_800E0BD8;
s32 func_151ED1E0(s32);
void func_15042D94(s32, s32, s32, s32);
Gfx *func_151ED430(Gfx *, void *, s32, s32, s32, s32, f32, s32);
Gfx *func_15096934(Gfx *);

s32 func_151E84B0(s32 arg0) {
    s32 tmp;

    D_8003C8E0 = 0x9000001;
    tmp = 0;
    arg0 = func_151ED1E0(arg0);
    if (D_8008FFF4[D_800E0B94] != 0) {
        arg0 = D_8008FFF4[D_800E0B94](arg0);
    }

    if (D_80000300 != 0) {
        if ((D_800BE616 != 0) && (D_8008FD90 >= 2)) {
            if ((D_800BE740 & 0xF) == 0) {
                if (D_800E0BD3 == 1) {
                    tmp = 0x33;
                } else if (D_800E0BD3 == 2) {
                    tmp = 0x16;
                }
            }
        } else {
            if ((D_800BE740 & 1) == 0) {
                if (D_800E0BD3 == 1) {
                    tmp = 0x32;
                } else if (D_800E0BD3 == 2) {
                    tmp = 0x15;
                }
            }
        }
    }

    if (tmp != 0) {
        func_1504332C(0xFF, 0xFF, 0xFF, 0xFF);
        func_15042D94(0x94, 0xC8, 0x81, D_800E0BD8[tmp]);
    }

    D_8003C8E0 = 0;
    return arg0;
}

extern u8 D_800E0B94;
extern s32 (*D_8008FFC0[])(s32);
extern s32 D_8003C8E0;
extern s32 D_80090058;
extern s16 D_800E0C78;
extern u8 D_800BE9C0;
extern s32 D_800BE9C8[];
extern s32 D_800BEBA4;

s32 func_151E8620(s32 arg0) {
    s32 cond;
    s32 orig;
    s32 idx;

    idx = D_800E0B94;
    orig = arg0;
    D_8003C8E0 = 0x9000000;
    if (D_8008FFC0[idx] != 0) {
        arg0 = D_8008FFC0[idx](arg0);
    }
    if (D_800E0B94 != 0) {
        D_80090058 = 0;
        D_800E0C78 = 0;
    }
    D_8003C8E0 = 0;
    if (((arg0 - D_800BE9C8[D_800BE9C0]) >> 3) > D_800BEBA4) {
        cond = 1;
    } else {
        cond = 0;
    }
    if (cond) {
        return orig;
    }
    return arg0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_215960/func_151E86E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_215960/func_151E89A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_215960/func_151E966C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_215960/func_151E9D18.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_215960/func_151EA15C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_215960/func_151EADFC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_215960/func_151EB06C.s")

extern s16 D_8008FDCC;
s32 func_151EA15C(s32, s32, s32, s32);

s32 func_151EB930(s32 arg0) {
    if (D_8008FDCC != 0) {
        arg0 = func_151EA15C(arg0, 0x6A, D_8008FDCC, 0);
    }
    return arg0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_215960/func_151EB96C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_215960/func_151EBB50.s")

extern s32 D_800E0A90;
extern s32 *D_800E0BD8;
void func_15042D94(s32, s32, s32, s32);

s32 func_151EC178(s32 arg0) {
    s32 temp;
    if (D_800E0A90 >= 0x5DD) {
        temp = (D_800E0A90 - 0x5DC) << 3;
        if (temp >= 0x100) {
            temp = 0xFF;
        }
        func_1504332C(0xFF, 0xFF, 0xFF, temp);
        func_15042D94(0xDC, 0x130, 1, D_800E0BD8[0x1D0 / 4]);
    }
    return arg0;
}

Gfx *func_151EC1F0(Gfx *gfx) {
    s32 alpha;
    s32 temp;

    if (D_800BE9F0 == 0x21) {
        return gfx;
    }

    gSPDisplayList(gfx++, &D_80090028);
    temp = D_800E0A90;
    alpha = temp;
    if (alpha >= 0x12D) {
        temp = 0x1AC;
        alpha = temp - alpha;
        alpha <<= 1;
        if (alpha < 0) {
            alpha = 0;
        }
    } else {
        alpha = temp << 3;
        if (alpha >= 0x100) {
            alpha = 0xFF;
        }
    }

    if (alpha != 0) {
        gDPSetEnvColor(gfx++, 0xFF, 0xFF, 0xFF, alpha);
        gfx = func_151ED430(gfx, &D_800917F8, 0x92, 0x63, 5, 6, 1.0f, 0);
    }

    gDPSetEnvColor(gfx++, 0xFF, 0xFF, 0xFF, 0xFF);
    gfx = func_151ED430(gfx, &D_80091804, 0x92, 0xCB, 5, 2, 1.0f, 0);
    gDPSetCombine(gfx++, 0xFFD3FF, 0xFFA6FF7F);
    gDPSetEnvColor(gfx++, 0x20, 0xFF, 0x20, D_800E0B97);
    gfx = func_151ED430(gfx, &D_80091810, 0x92, 0xCB, 5, 2, 1.0f, 0);
    gfx = func_15096934(gfx);

    alpha = 0x1EA - D_800E0A74;
    if (alpha < 0) {
        alpha = 0;
    } else {
        alpha <<= 4;
        if (alpha >= 0x100) {
            alpha = 0xFF;
        }
    }
    alpha = 0xFF - alpha;
    D_800E0B96 = alpha;
    return gfx;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_215960/func_151EC3E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_215960/func_151EC648.s")

extern u8 D_800E0B97;
extern Gfx D_80090028;
extern u8 D_8009181C;
extern u8 D_80091828;
Gfx *func_151ED430(Gfx *, void *, s32, s32, s32, s32, f32, s32);
Gfx *func_15096934(Gfx *);

Gfx *func_151ED09C(Gfx *gfx) {
    s32 alpha;

    gSPDisplayList(gfx++, &D_80090028);
    alpha = D_800E0A90 << 2;
    if (alpha >= 0x100) {
        alpha = 0xFF;
    }
    gDPSetEnvColor(gfx++, 0xFF, 0xFF, 0xFF, alpha);
    gfx = func_151ED430(gfx, &D_8009181C, 0x92, 0x6C, 8, 3, 1.0f, 0);
    gDPPipeSync(gfx++);
    gDPSetCombine(gfx++, 0xFFD3FF, 0xFFA6FF7F);
    gDPSetEnvColor(gfx++, 0xFF, 0x80, 0x20, (D_800E0B97 * (alpha + 1)) >> 8);
    gfx = func_151ED430(gfx, &D_80091828, 0x92, 0x6C, 8, 3, 1.0f, 0);
    return func_15096934(gfx);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_215960/func_151ED1E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_215960/func_151ED29C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_215960/func_151ED430.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_215960/func_151ED90C.s")

typedef struct {
    s32 unk0;
    s32 *unk4[4];
    u8 unk14;
    u8 pad15[0xF];
    s32 unk24;
} GameStruct151EDB58;

extern void func_1503F7B8(s32);

void func_151EDB58(GameStruct151EDB58 *arg0) {
    s32 i;

    if (arg0 != 0) {
        func_1503F7B8(arg0->unk24);
        func_100043B4((s32 *)arg0, 4);
        for (i = 0; i < arg0->unk14; i++) {
            func_100043B4(arg0->unk4[i], 4);
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_215960/func_151EDBDC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_215960/func_151EDF4C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_215960/func_151EE184.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_215960/func_151EEBE8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_215960/func_151EEFF0.s")
