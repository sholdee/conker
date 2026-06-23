#include <ultra64.h>
#include "functions.h"
#include "variables.h"


void func_15179008(s32);
extern f32 D_800A26B0;
extern f32 D_800A26B4;
extern f32 D_800A26B8;
extern void func_15114D24(s32, s32, s32, s16, s32, s32);

typedef struct {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    f32 unk14;
    f32 unk18;
    f32 unk1C;
    f32 unk20;
    f32 unk24;
    f32 unk28;
    f32 unk2C;
    f32 unk30;
    f32 unk34;
    f32 unk38;
} struct_func_1510AEE0;

typedef struct {
    f32 field_0x00;
    u8 pad_0x04[0x5C];
    f32 field_0x60;
    u8 pad_0x64[0x18];
    s32 field_0x7C;
    f32 field_0x80;
} OscillatorState;

void func_1510AA20(s32 arg0) {
    func_15179008(0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_137ED0/func_1510AA44.s")

void func_1510ADD8(OscillatorState *arg0) {
    f32 temp;

    arg0->field_0x80 += (D_800A26B0 * D_800BE9E4) / 60.0f;
    temp = cosf(arg0->field_0x80) * 10.0f;
    arg0->field_0x60 = arg0->field_0x00 - temp;
    arg0->field_0x00 = temp;
    if (arg0->field_0x7C == 0) {
        if (D_800A26B4 <= arg0->field_0x80) {
            arg0->field_0x7C = 1;
            func_15114D24((s32)arg0, 0x4CA, 0x2EE0, 0xC8, 0x3E8, 4);
        }
    } else {
        temp = D_800A26B8;
        if (temp <= arg0->field_0x80) {
            arg0->field_0x80 -= temp;
            arg0->field_0x7C = 0;
            func_15114D24((s32)arg0, 0x4CB, 0x2EE0, 0xC8, 0x3E8, 4);
        }
    }
}

s32 func_1510AEE0(struct_func_1510AEE0 *arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, f32 *arg8, f32 *arg9) {
    f32 temp_f2;
    f32 temp_f16;
    f32 temp_f18;
    f32 sp0[1];

    temp_f2 = -(arg0->unk38 + ((arg0->unk8 * arg1) + (arg0->unk18 * arg2) + (arg0->unk28 * arg3)));
    if (temp_f2 < arg4) {
        return 1;
    }
    if (arg5 < temp_f2) {
        return 1;
    }

    temp_f16 = arg0->unk30 + ((arg0->unk0 * arg1) + (arg0->unk10 * arg2) + (arg0->unk20 * arg3));
    temp_f16 = fabsf(temp_f16) * arg6;
    if (temp_f2 < temp_f16) {
        return 1;
    }

    temp_f18 = arg0->unk34 + ((arg0->unk4 * arg1) + (arg0->unk14 * arg2) + (arg0->unk24 * arg3));
    sp0[0] = fabsf(temp_f18) * arg7;
    if (temp_f2 < sp0[0]) {
        return 1;
    }

    if (arg8 != 0) {
        *arg8 = 1.0f - (temp_f16 / temp_f2);
    }
    if (arg9 != 0) {
        *arg9 = 1.0f - (sp0[0] / temp_f2);
    }
    return 0;
}
