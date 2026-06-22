#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern s32 D_80090324[];
extern s32 func_1510D0EC(s32, s32, s32, s32);

#define WGFX2(pkt, a, b)            \
{                                   \
    Gfx *_g = (Gfx *)(pkt);         \
    _g->words.w0 = (u32)(a);        \
    _g->words.w1 = (u32)(b);        \
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_12D7F0/func_15100340.s")

Gfx *func_15100464(Gfx *arg0) {
    s32 sp58[4];
    s32 *scratch;
    s32 three;
    s32 idx;
    s32 data;
    u8 *states;

    scratch = sp58;
    three = 3;
    idx = D_800DD405 >> 2;

    data = func_1510D0EC(D_80090324[idx % three], (s32)scratch, three, 0);
    WGFX2(arg0++, 0xDB060008, data);

    data = func_1510D0EC(D_80090324[(idx + 1) % three], (s32)scratch, three, 0);
    WGFX2(arg0++, 0xDB06000C, data);

    states = D_800BE500;
    idx = 0x10;
    do {
        data = func_1510D0EC(D_80090324[states[0] + 3], (s32)scratch, 3, 0);
        WGFX2(arg0++, 0xDB060000 | (idx & 0xFFFF), data);
        idx += 4;
        states++;
    } while (idx != 0x24);

    return arg0;
}
