#include <ultra64.h>

#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_168A90/func_1513B5E0.s")
extern s32 (*D_80089C18[])(struct102 *);
extern s32 (*D_80089C28[])(struct102 *, s16);

#define WGFX168A90(pkt, a, b)       \
{                                   \
    Gfx *_g = (Gfx *)(pkt);         \
    _g->words.w0 = (u32)(a);        \
    _g->words.w1 = (u32)(b);        \
}

void func_1513B798(struct102 *arg0) {
    s32 idx;
    u8 done = 0;

    if (*((u8 *)arg0 + 0x10) & 1) {
        *(s16 *)((u8 *)arg0 + 0x14) -= D_800BE9E4;
        if (*(s16 *)((u8 *)arg0 + 0x14) < 0) {
            done = 1;
        }
    }
    if (!done) {
        idx = *(s8 *)((u8 *)arg0 + 0x11);
        if (idx != -1) {
            if (D_80089C18[idx](arg0) == 0) {
                done = 1;
            }
        }
    }
    if (done) {
        func_1516972C(arg0);
    }
}
Gfx *func_1513B83C(Gfx *arg0, struct102 *arg1, s16 arg2) {
    s32 idx;
    u8 *ptr;

    ptr = (u8 *)arg1;
    if ((ptr[0x10] & 2) && !(ptr[0x49] & (1 << arg2))) {
        return arg0;
    }

    idx = *(s8 *)(ptr + 0x12);
    if (idx != -1) {
        if (D_80089C28[idx](arg1, arg2) == 0) {
            return arg0;
        }
    }

    WGFX168A90(arg0++, 0xDA380003, (s32)ptr + (D_800BE9C0 << 6) + 0x78);
    WGFX168A90(arg0++, 0xDB060004, *(u32 *)((s32)ptr + (D_800BE9C0 << 4) + (arg2 << 2) + 0x58));
    WGFX168A90(arg0++, 0xDE000000, *(u32 *)(ptr + 0x54));

    return arg0;
}

s32 func_1513B968(s32 arg0, s32 arg1) {
    // FIXME: &arg0->unk_120[D_800BE9C0]
    func_150A7B80(arg0 + 120 + (D_800BE9C0 << 6));
    return 1;
}

void func_1513B9A8(struct132 *arg0) {
    func_100043B4(arg0->unk4C, 4);
    func_15169804(arg0);
}

void func_1513B9DC(struct132 *arg0) {
    func_100043B4(arg0->unk4C, 4);
    func_15169824(arg0);
}

void func_1513BA10(struct132 *arg0) {
    D_80089C44[arg0->unk48]();
}

void func_1513BA44(struct132 *arg0) {
    D_80089C54[arg0->unk48]();
}

void func_15109064(struct132 *, s32, u8);
void func_151BA468(struct132 *, s32, u8);

void func_1513BA78(struct132 *arg0, s32 arg1, u8 arg2) {
    switch (arg0->unk48) {
    case 1:
        func_15109064(arg0, arg1, arg2);
        break;
    case 2:
        func_151BA468(arg0, arg1, arg2);
        break;
    }
}

s32 func_1513BAD4(s32 arg0, s32 arg1) {
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_168A90/func_1513BAE8.s")
#pragma GLOBAL_ASM("asm/nonmatchings/game_168A90/func_1513BBFC.s")
#pragma GLOBAL_ASM("asm/nonmatchings/game_168A90/func_1513BEB0.s")
