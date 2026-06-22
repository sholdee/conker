#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern void func_151D5D60();

struct Foo150DB2D8 {
    char pad0[0x2C];
    f32 unk2C;
    f32 unk30;
    f32 unk34;
    f32 unk38;
    f32 unk3C;
    f32 unk40;
    char pad44[0x4];
    f32 unk48;
    char pad4C[0x74];
    char unkC0[0x40];
    s16 *unk100[1];
};


#pragma GLOBAL_ASM("asm/nonmatchings/game_108320/func_150DAE70.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_108320/func_150DB114.s")

s16 *func_150DB2D8(struct Foo150DB2D8 *arg0, s16 arg1) {
    s16 *var_v0;
    s16 *ret;
    f32 temp_f2;
    f32 temp_f12;
    u8 sp37;

    func_151D5D60(arg0->unk100, arg1, 0x40, &var_v0, &sp37);
    ret = var_v0;
    if (var_v0) {
        if (sp37) {
            memcpy(arg0->unk100[arg1], arg0->unkC0, 0x40);
            memcpy(arg0->unk100[arg1] + 0x20, arg0->unkC0, 0x40);
        }
    } else {
        return 0;
    }

    temp_f2 = arg0->unk2C * arg0->unk40;
    temp_f12 = -arg0->unk2C * arg0->unk48;

    var_v0[0] = arg0->unk34 + temp_f2;
    var_v0[1] = arg0->unk38 + arg0->unk30;
    var_v0[2] = arg0->unk3C + temp_f12;
    var_v0[3] = 0;
    var_v0[8] = arg0->unk34 + temp_f2;
    var_v0[9] = arg0->unk38 - arg0->unk30;
    var_v0[10] = arg0->unk3C + temp_f12;
    var_v0[11] = 0;
    var_v0[16] = arg0->unk34 - temp_f2;
    var_v0[17] = arg0->unk38 - arg0->unk30;
    var_v0[18] = arg0->unk3C - temp_f12;
    var_v0[19] = 0;
    var_v0[24] = arg0->unk34 - temp_f2;
    var_v0[25] = arg0->unk38 + arg0->unk30;
    var_v0[26] = arg0->unk3C - temp_f12;
    var_v0[27] = 0;

    return ret;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_108320/func_150DB518.s")

s32 func_150DB630(void *arg0) {
    f32 temp_f0;
    s32 ret;

    ret = 1;
    if (255.0f < **(f32 * volatile *)((u8 *)arg0 + 0x120)) {
        *(u8 *)((u8 *)arg0 + 0x5C) = 0xFF;
    } else {
        temp_f0 = **(f32 * volatile *)((u8 *)arg0 + 0x120);
        if (temp_f0 < 0.0f) {
            *(u8 *)((u8 *)arg0 + 0x5C) = 0;
        } else {
            *(u8 *)((u8 *)arg0 + 0x5C) = (u32)temp_f0;
        }
    }
    return ret;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_108320/func_150DB714.s")
