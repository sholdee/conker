#include <ultra64.h>
#include "functions.h"
#include "variables.h"

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
} struct_func_150D2450_sub;

typedef struct {
    u8 pad0[0x28];
    struct_func_150D2450_sub unk28;
} struct_func_150D2450_arg;

void func_150D2450(struct_func_150D2450_arg *arg0) {
    struct_func_150D2450_sub *temp_s0;
    f32 pad;
    f32 temp_f[2];

    temp_s0 = &arg0->unk28;
    temp_f[0] = sinf(temp_s0->unk18);
    temp_f[1] = sinf(temp_s0->unk1C);

    func_1515D4D4(
        (u8)(temp_s0->unk0 + (temp_f[0] * temp_s0->unkC)),
        (u8)(temp_s0->unk4 + (temp_f[1] * temp_s0->unk10)),
        (u8)((sinf(temp_s0->unk20) * temp_s0->unk14) + temp_s0->unk8),
        0);

    temp_s0->unk18 = func_15144B68(temp_s0->unk18 + (temp_s0->unk24 * D_800BE9A4));
    temp_s0->unk1C = func_15144B68(temp_s0->unk1C + (temp_s0->unk28 * D_800BE9A4));
    temp_s0->unk20 = func_15144B68(temp_s0->unk20 + (temp_s0->unk2C * D_800BE9A4));
}
