#include <ultra64.h>
#include "functions.h"
#include "variables.h"


void func_151749A0(s32 arg0, s32 arg1) {
    D_800DD406 += D_800BE9E4;
    if (arg0 < (u8)D_800DD406) {
        D_800DD405++;
        if ((u8)D_800DD405 >= arg1) {
            D_800DD405 = 0;
        }
        D_800DD406 = 0;
    }
}

extern void func_15195FF0(s32, s32);
extern void func_1510C8A8(void);
extern void func_1517DE5C(void);
extern void func_151880C0(void);
extern void (*D_8008CD04[])(s32);
extern u16 D_800CBD4E;

void func_151749F8(s32 arg0, s32 arg1) {
    u8 temp;

    func_15165F70();
    func_15195FF0(D_800B0E00[0], D_800B0E00[1]);
    func_1510C8A8();
    temp = *((u8*)D_800B0DF0 + 0xB);
    if (temp != 0) {
        D_8008CD04[temp](arg1);
    }
    if (D_800BE616 == 0) {
        func_1517DE5C();
        func_151880C0();
    }
    D_800CBD4E += D_800BE9E4 << 6;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1A1E50/func_15174AA4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1A1E50/func_15174B48.s")
