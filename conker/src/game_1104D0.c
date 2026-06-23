#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern f32 D_800A1050;
extern f32 D_800A1054;
extern void func_1505D1C4(f32, f32, f32, s32, s32, s32, s32, s32);
void func_151C3B0C(s32, f32, f32, f32, f32, s32, s32, s32);

#pragma GLOBAL_ASM("asm/nonmatchings/game_1104D0/func_150E3020.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1104D0/func_150E3208.s")

extern u8 *func_150E3020(s32, s32, s32, s32, s32, s32, s32, f32, s32, f32, f32, f32, s32, s16);

s32 func_150E32D0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, f32 arg5) {
    u8 *temp;

    temp = func_150E3020(arg0, arg1, arg2, 0, 0, 0, arg4, arg5, arg3, 0.0f, 0.0f, 0.0f, 0, -99);
    if (temp != 0) {
        return temp[0x48] + 1;
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1104D0/func_150E3340.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1104D0/func_150E33CC.s")

extern void func_150E33CC(void);

s32 func_150E3414(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, f32 arg8) {
    u8 *temp;

    temp = func_150E3020(arg3, arg4, arg5, 0, 0, 0, arg7, arg8, arg6, (f32)arg0, (f32)arg1, (f32)arg2, 0, -99);
    if (temp != 0) {
        *(s16 *)(temp + 0x4A) = func_1000FA64(0x2D0, (s16)arg0, (s16)arg1, (s16)arg2, 0x5DC0, 0x1770, 0x3E8, (s32)func_150E33CC, 0, 0, 0, 0);
        return temp[0x48] + 1;
    }
    return 0;
}

void func_150E3514(u8 *arg0) {
    s32 temp;
    s32 *slot;
    u16 id;

    temp = arg0[0x48];
    if (temp >= 0) {
        slot = &D_800D99D0[temp];
        if (*slot == (s32)arg0) {
            *slot = 0;
        }
    }

    id = *(u16 *)(arg0 + 0x4A);
    if (id != 0) {
        func_100111C8(id);
        *(u16 *)(arg0 + 0x4A) = 0;
        func_10010F88(0x2D7, 0x5DC0, 0, 0, 0,
                      (s32)*(f32 *)(arg0 + 0x28),
                      (s32)*(f32 *)(arg0 + 0x2C),
                      (s32)*(f32 *)(arg0 + 0x30),
                      0x3E8, 0x1770);
    }

    func_1516972C((struct102 *)arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1104D0/func_150E35DC.s")

void func_150E36BC(s32 arg0, s32 *arg1, s32 *arg2, s32 *arg3) {
    u8 *temp;

    arg0 -= 1;
    if ((arg0 >= 0) && (arg0 < 8)) {
        temp = (u8 *)D_800D99D0[arg0];
        if (temp != 0) {
            if (temp[0] == 0x27) {
                *arg1 = (s32)*(f32 *)(temp + 0x10);
                *arg2 = (s32)*(f32 *)(temp + 0x14);
                *arg3 = (s32)*(f32 *)(temp + 0x18);
            }
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1104D0/func_150E3738.s")

void func_150E4010(u8 *arg0) {
    u8 *temp;

    temp = arg0 + 0x110;
    if (*(s32 *)(arg0 + 0x1B4) != 0) {
        func_1505D1C4(*(f32 *)(temp + 0x30), *(f32 *)(temp + 0x34), *(f32 *)(temp + 0x38),
                      *(s32 *)(temp + 0xA4) | 0x60000, -1,
                      ((u16)(u32)(func_150484A0(*(f32 *)(temp + 0x60), *(f32 *)(temp + 0x64)) * D_800A1050) - 0x4000) | 1, 0, 0);
    }
}

void func_150E411C(s32 arg0) {
    func_151C3B0C(arg0, 0.352000028f, 0.701000035f, 0.566000044f, D_800A1054, 0xFF, 0xFF, 0xFF);
}

extern f32 D_800BE9A4;

s32 func_150E4174(u8 *arg0) {
    *(f32 *)(arg0 + 0x2C) += *(f32 *)(arg0 + 0x4C) * D_800BE9A4;
    *(f32 *)(arg0 + 0x30) += *(f32 *)(arg0 + 0x54) * D_800BE9A4;
    return 1;
}
