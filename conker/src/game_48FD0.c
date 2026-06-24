#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern u8 D_80084060[];
extern OSTimer D_800BE6E0;
extern f32 D_80096960;

s64 __ll_mul(u64 arg0, s32 arg1, s32 arg2);
u64 __ull_div(u64 arg0, u64 arg1);
void func_1501C0F0(u8 arg0, f32 arg1, f32 arg2);

void func_1501BB20(void) {
    if (D_80084064 != 0) {
        osSetTimer(&D_800BE6E0, __ull_div(__ll_mul(25ULL, *(s32 *)&D_8002BD10, D_8002BD14), 1000000ULL), 0, &D_8003B218, (OSMesg)6);
        D_80084064 = 0;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_48FD0/func_1501BBB8.s")

void func_1501C010(u8 arg0, u8 arg1) {
    f32 temp_f0;
    f32 temp_f12;
    f32 temp_f2;
    u32 temp_v0;

    temp_v0 = arg1;
    if (arg1 >= 9) {
        arg1 = 8;
        temp_v0 = 8;
    }
    if (temp_v0 == 8) {
        temp_f2 = 20.0f;
        temp_f12 = 0.0f;
    } else if (temp_v0 == 0) {
        temp_f2 = 0.0f;
        temp_f12 = 99.0f;
    } else {
        temp_f0 = ((f32)(u32)arg1 - 1.0f) * D_80096960 * 5.0f;
        temp_f2 = temp_f0 + 2.0f;
        temp_f12 = 7.0f - temp_f0;
    }
    func_1501C0F0(arg0, temp_f2, temp_f12);
}

void func_1501C0F0(u8 arg0, f32 arg1, f32 arg2) {
    u8 temp = D_80084060[arg0];

    if (temp < 4) {
        if (D_800BE944[temp] != 0) {
            D_800BE93C[temp] = 1;
            D_800BE950[temp] = 0.0f;
            D_800BE960[temp] = arg1;
            D_800BE970[temp] = arg2;
            D_800BE980[temp] = arg1 + arg2;
        }
    }
}

void func_1501C17C(u8 arg0) {
    u8 temp = D_80084060[arg0];
    if (temp < 4) {
        D_800BE93C[temp] = 0;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_48FD0/func_1501C1B0.s")

void func_1501C53C(void) {
    u8 i;
    for (i = 0; i < 4; i++) {
        func_1501C17C(i);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_48FD0/func_1501C57C.s")
