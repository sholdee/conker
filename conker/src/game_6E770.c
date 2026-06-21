#include <ultra64.h>
#include "functions.h"
#include "variables.h"


extern u8 D_80084930;
extern u8 D_800848D0[];
extern u8 D_80085930;
extern u8 D_80085931;
extern u8 D_80085932;
extern u8 D_80085933[];

#define WGFX(pkt, a, b)             \
{                                   \
    Gfx *_g = (Gfx *)(pkt);         \
    _g->words.w0 = (u32)(a);        \
    _g->words.w1 = (u32)(b);        \
}

Gfx *func_150412C0(Gfx *gfx) {
    WGFX(gfx++, 0xD7000002, 0xFFFFFFFF);
    WGFX(gfx++, 0xE7000000, 0x00000000);
    WGFX(gfx++, 0xFCFFFFFF, 0xFFFCF279);
    WGFX(gfx++, 0xEF002C0F, 0x0055204C);
    WGFX(gfx++, 0xFD90003F, &D_80084930);
    WGFX(gfx++, 0xFD900000, &D_80084930);
    WGFX(gfx++, 0xF5900000, 0x07000000);
    WGFX(gfx++, 0xE6000000, 0x00000000);
    WGFX(gfx++, 0xF3000000, 0x077FF200);
    WGFX(gfx++, 0xE7000000, 0x00000000);
    WGFX(gfx++, 0xF5800800, 0x00000000);
    WGFX(gfx++, 0xF2000000, 0x000FC1FC);
    return gfx;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_6E770/func_150413FC.s")

s32 func_15041480(u8 arg0) {
    s32 i;

    for (i = 0; ; ) {
        if (arg0 == D_800848D0[i]) {
            return i;
        }
        if (arg0 == D_800848D0[i + 1]) {
            return i + 1;
        }
        if (arg0 == D_800848D0[i + 2]) {
            return i + 2;
        }
        if (arg0 == D_800848D0[i + 3]) {
            return i + 3;
        }
        i += 4;
        if (i != 0x50) {
            continue;
        }
        break;
    }

    return i;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_6E770/func_15041508.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_6E770/func_150415E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_6E770/func_150417AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_6E770/func_150428D4.s")

s32 func_15042C40(u8 arg0) {
    s32 i;
    u8 c;
    u8 *ptr;
    s32 original;

    original = arg0;
    if ((original >= 0x61) && (original < 0x7B)) {
        c = original - 0x20;
    } else {
        c = original;
    }

    if (original == 0x20) {
        return 0x60;
    }

    i = 3;
    if (D_80085930 == c) {
        return 0;
    }
    if (D_80085931 == c) {
        return 1;
    }
    if (D_80085932 == c) {
        return 2;
    }

    ptr = D_80085933;
    for (i = 3; ; ) {
        if (c == ptr[0]) {
            return i;
        }
        if (c == ptr[1]) {
            return i + 1;
        }
        if (c == ptr[2]) {
            return i + 2;
        }
        if (c == ptr[3]) {
            return i + 3;
        }
        i += 4;
        ptr += 4;
        if (i != 0x5F) {
            continue;
        }
        break;
    }

    return original;
}
