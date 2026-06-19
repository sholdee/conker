#include <ultra64.h>
#include "functions.h"
#include "variables.h"


extern u8 D_800D2DC0[];

void func_15096970(void) {
    bzero(D_800D2DC0, 0x6C);
    D_800D2DB4 = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_C3E20/func_150969A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_C3E20/func_15096A68.s")

extern u8 D_800C35EA;
extern s32 func_15096A68(s32);

void func_15096D08(void) {
    s32 i;
    u8 *p;

    i = 0;
    if (D_800C35EA != 1) {
        p = D_800D2DC0;
        while (1) {
            if (*p != 0) {
                if (func_15096A68(i) != 0) {
                    break;
                }
            }
            i++;
            p += 0x24;
            if (i == 3) {
                break;
            }
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_C3E20/func_15096D78.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_C3E20/func_1509759C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_C3E20/func_15097798.s")
