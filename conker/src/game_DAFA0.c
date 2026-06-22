#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern void func_151D5D60();
extern void func_15142914(f32 mtx[4][4], f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, f32 arg8);
extern void func_150A7960(f32 *arg0, f32 arg1, f32 arg2, f32 arg3, f32 *arg4, f32 *arg5, f32 *arg6);

struct Foo150AE36CInner {
    char pad0[0x18];
    f32 unk18;
    f32 unk1C;
    f32 unk20;
    f32 unk24;
    f32 unk28;
    char pad2C[0xC];
    f32 unk38;
    f32 unk3C;
    f32 unk40;
};

struct Foo150AE36C {
    char pad0[0x2C];
    f32 unk2C;
    f32 unk30;
    f32 unk34;
    f32 unk38;
    f32 unk3C;
    char pad40[0x80];
    char unkC0[0x40];
    s16 *unk100[0x18];
    struct Foo150AE36CInner *unk160;
};


#pragma GLOBAL_ASM("asm/nonmatchings/game_DAFA0/func_150ADAF0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_DAFA0/func_150AE280.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_DAFA0/func_150AE35C.s")

s16 *func_150AE36C(struct Foo150AE36C *arg0, s16 arg1) {
    s16 *var_v0;
    s16 *ret;
    f32 temp_f2;
    f32 temp_f12;
    f32 sp94;
    f32 sp90;
    f32 sp8C;
    f32 pad84[2];
    f32 mtx[4][4];
    u8 sp43;

    func_151D5D60(arg0->unk100, arg1, 0x40, &var_v0, &sp43);
    ret = var_v0;
    if (var_v0) {
        if (sp43) {
            memcpy(arg0->unk100[arg1], arg0->unkC0, 0x40);
            memcpy(arg0->unk100[arg1] + 0x20, arg0->unkC0, 0x40);
        }
    } else {
        return 0;
    }

    func_15142914(mtx, arg0->unk160->unk18, arg0->unk160->unk1C, arg0->unk160->unk20, arg0->unk160->unk24, arg0->unk160->unk28, arg0->unk160->unk38, arg0->unk160->unk3C, arg0->unk160->unk40);
    func_150A7960(mtx[0], arg0->unk34, arg0->unk38, arg0->unk3C, &sp8C, &sp90, &sp94);

    temp_f2 = D_800DD1E8[arg1] * arg0->unk2C;
    temp_f12 = D_800DD1D8[arg1] * arg0->unk2C;

    var_v0[3] = 0;
    var_v0[0xB] = 0;
    var_v0[0x13] = 0;
    var_v0[0x1B] = 0;
    var_v0[0] = var_v0[0x18] = sp8C + temp_f2;
    var_v0[1] = var_v0[9] = sp90;
    var_v0[2] = var_v0[0x1A] = sp94 - temp_f12;
    var_v0[8] = var_v0[0x10] = sp8C - temp_f2;
    var_v0[0x11] = var_v0[0x19] = sp90 + arg0->unk30;
    var_v0[0xA] = var_v0[0x12] = sp94 + temp_f12;

    return ret;
}
