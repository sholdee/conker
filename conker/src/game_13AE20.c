#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern void *func_15167A68(s32, s32, s32, s32, s32, s32);

void *func_1510D970(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 size[2];
    union { s32 w; f64 d; } flag;
    s32 i;

    size[0] = 0x128;
    flag.w = arg3 & 1;
    if (flag.w != 0) {
        size[0] = 0x13A;
    }

    arg3 = (s32)func_15167A68(0x4B, 0, size[0], 1, 0xFF, 1);
    if (arg3 != 0) {
        for (i = 0; i < 2; i++) {
            *(s16 *)((u8 *)arg3 + (i * 0x40) + 0x96) = 0;
            *(s16 *)((u8 *)arg3 + (i * 0x40) + 0x98) = 0x800;
            *(s16 *)((u8 *)arg3 + (i * 0x40) + 0x9A) = 0;
            *(s16 *)((u8 *)arg3 + (i * 0x40) + 0xA6) = 0;
            *(s16 *)((u8 *)arg3 + (i * 0x40) + 0xA8) = 0;
            *(s16 *)((u8 *)arg3 + (i * 0x40) + 0xAA) = 0;
            *(s16 *)((u8 *)arg3 + (i * 0x40) + 0xB6) = 0;
            *(s16 *)((u8 *)arg3 + (i * 0x40) + 0xB8) = 0;
            *(s16 *)((u8 *)arg3 + (i * 0x40) + 0xBA) = 0x800;
            *(s16 *)((u8 *)arg3 + (i * 0x40) + 0xC6) = 0;
            *(s16 *)((u8 *)arg3 + (i * 0x40) + 0xC8) = 0x800;
            *(s16 *)((u8 *)arg3 + (i * 0x40) + 0xCA) = 0x800;
        }

        *((u8 *)arg3 + 0x120) = arg0;
        *(s32 *)((u8 *)arg3 + 0x110) = arg1;
        *((u8 *)arg3 + 0x121) = arg2;
        *((u8 *)arg3 + 0x124) = arg4;

        if (flag.w != 0) {
            for (i = 0; i < 9; i++) {
                *(s16 *)((u8 *)arg3 + 0x128 + (i * 2)) = 0x7FFF;
            }
        }
    }

    return (void *)arg3;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_13AE20/func_1510DA84.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_13AE20/func_1510E120.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_13AE20/func_1510E388.s")

extern Mtx D_80089470;

Gfx *func_1510E634(Gfx *pkt, s32 arg1, s32 arg2) {
    gSPMatrix(pkt++, &D_80089470, G_MTX_LOAD);
    return pkt;
}
