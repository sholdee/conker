#include <ultra64.h>
#include "functions.h"
#include "variables.h"


s32 func_15167A68(s32, s32, s32, s32, s32, s32);
extern s32 func_1510D0EC(s32, s32, s32, s32);
extern u8 D_A48[];

#define WGFX151D2830(pkt, a, b)    \
{                                   \
    Gfx *_g = (Gfx *)(pkt);         \
    _g->words.w0 = (u32)(a);        \
    _g->words.w1 = (u32)(b);        \
}

struct Obj151D26C0 {
    u8  pad0[0xE];
    s16 unkE;
    s16 unk10;
    s16 unk12;
    s16 unk14;
    s8  unk16;
};

struct Obj151D26C0 *func_151D26C0(s16 arg0) {
    struct Obj151D26C0 *ret;

    ret = func_15167A68(0x3C, 1, 0x18, 0, 0xFF, 1);
    ret->unk14 = 0;
    ret->unk12 = 0;
    ret->unkE = 0;
    ret->unk16 = 1;
    ret->unk10 = arg0;
    return ret;
}

struct SomeNode {
    char pad0[0x8];
    struct SomeNode *unk8;
    char padC[0x4];
    s16 unk10;
    char pad12[0x4];
    s8 unk16;
};

extern struct SomeNode *D_800DD0E0;

void func_151D2718(s16 arg0) {
    struct SomeNode *node;

    for (node = D_800DD0E0; node != NULL; node = node->unk8) {
        if (arg0 == node->unk10) {
            node->unk16 = -2;
        }
    }
}

void func_151D275C(struct Obj151D26C0 *arg0) {
    s32 temp_v0;
    s32 temp_t5;

    temp_t5 = 0x80;
    arg0->unkE += (u32)D_800BE9E4 * (temp_v0 = arg0->unk16);

    if ((temp_v0 > 0) && (arg0->unkE >= 0xED)) {
        arg0->unk14 = (0x128 - arg0->unkE) << 2;
        if (arg0->unk14 < 0) {
            arg0->unk14 = 0;
        }
    } else {
        arg0->unk14 = (*(volatile s16 *)&arg0->unkE) * 2;
    }

    if (arg0->unk14 >= 0x80) {
        arg0->unk14 = temp_t5;
    }

    arg0->unk12++;
    if (arg0->unk12 >= 0x100) {
        arg0->unk12 -= 0x100;
    }

    if ((arg0->unkE >= 0x12D) || (arg0->unkE < 0)) {
        func_1516972C((struct102 *)arg0);
    }
}

Gfx *func_151D2830(Gfx *gfx, struct Obj151D26C0 *arg1, s16 arg2) {
    s32 temp_v0;

    if ((arg2 != arg1->unk10) || (arg1->unk14 == 0)) {
        return gfx;
    }

    WGFX151D2830(gfx++, 0xD7000002, 0xFFFFFFFF);
    WGFX151D2830(gfx++, 0xE7000000, 0);
    WGFX151D2830(gfx++, 0xFC12D225, 0xFFA7FFFF);
    WGFX151D2830(gfx++, 0xEF002C3F, 0x00504244);

    temp_v0 = func_1510D0EC((s32)D_A48, 0, 3, 0);

    WGFX151D2830(gfx++, 0xFD700000, temp_v0);
    WGFX151D2830(gfx++, 0xF5700000, 0x07018060);
    WGFX151D2830(gfx++, 0xE6000000, 0);
    WGFX151D2830(gfx++, 0xF3000000, 0x077FF000);
    WGFX151D2830(gfx++, 0xE7000000, 0);
    WGFX151D2830(gfx++, 0xF5681000, 0x00018060);
    WGFX151D2830(gfx++, 0xF2000000, 0x000FC0FC);
    WGFX151D2830(gfx++, 0xFB000000, (arg1->unk14 & 0xFF) | 0x00FF0000);
    gSPTextureRectangle(gfx++, 0, 0, 0x500, 0x3C0, 0, arg1->unk12 << 3, 0x400, 0x400, 0x400);
    WGFX151D2830(gfx++, 0xE7000000, 0);
    WGFX151D2830(gfx++, 0xFB000000, ((arg1->unk14 >> 1) & 0xFF) | 0xFF000000);
    gSPTextureRectangle(gfx++, 0, 0, 0x500, 0x3C0, 0, arg1->unk12 << 3, 0, 0x200, 0x200);

    return gfx;
}
