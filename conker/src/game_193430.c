#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern void *func_15167A68(s32, s32, s32, s32, s32, s32);
extern void func_1517E05C(s32, s32, s32);
extern f32 D_800A6C94;

void func_15165F80(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8) {
    s32 i;
    u8 *temp_v0;
    f32 angle;
    u8 *ptr;

    temp_v0 = func_15167A68(4, arg8, 0xA8, 1, (u8)arg7, 1);
    if (temp_v0 != NULL) {
        if (arg0 == -1) {
            {
                s32 j;

                j = 0;
                do {
                    j += 0x40;
                    *(s16 *)(temp_v0 + j - 0x2E) = arg2;
                    *(s16 *)(temp_v0 + j - 0x1E) = arg2;
                    *(s16 *)(temp_v0 + j - 0xE) = arg2;
                    *(s16 *)(temp_v0 + j + 0x2) = arg2;
                    *(s16 *)(temp_v0 + j - 0x2A) = 0;
                    *(s16 *)(temp_v0 + j - 0x1A) = 0;
                    *(s16 *)(temp_v0 + j - 0xA) = 0;
                    *(s16 *)(temp_v0 + j + 0x6) = 0;
                } while (j != 0x80);
            }
            temp_v0[0x95] = 0;
        } else {
            angle = (f32)arg0 * D_800A6C94;
            temp_v0[0x91] = (s32)(sinf(angle) * 127.0f);
            temp_v0[0x90] = (s32)(-cosf(angle) * 127.0f);
            temp_v0[0x95] = 1;
        }

        i = 0;
        ptr = temp_v0;
        do {
            i++;
            ptr += 0x40;
            *(s16 *)(ptr - 0x28) = 0x2000;
            *(s16 *)(ptr - 0x26) = 0x2000;
            *(s16 *)(ptr - 0x18) = 0x2800;
            *(s16 *)(ptr - 0x16) = 0x2000;
            *(s16 *)(ptr - 0x8) = 0x2800;
            *(s16 *)(ptr - 0x6) = 0x2800;
            *(s16 *)(ptr + 0x8) = 0x2000;
            *(s16 *)(ptr + 0xA) = 0x2800;
        } while (i != 2);

        *(s16 *)(temp_v0 + 0x9A) = arg2;
        *(s16 *)(temp_v0 + 0x9E) = 1;
        temp_v0[0x92] = arg5;
        temp_v0[0x93] = arg5;
        *(s16 *)(temp_v0 + 0x98) = arg1;
        *(s16 *)(temp_v0 + 0x9C) = arg3;
        *(s16 *)(temp_v0 + 0x96) = arg4;
        temp_v0[0x94] = arg6;
        func_1517E05C(arg1, arg2, arg3);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_193430/func_15166118.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_193430/func_15166204.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_193430/func_15166268.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_193430/func_151668B8.s")
