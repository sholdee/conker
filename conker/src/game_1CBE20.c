#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_1CBE20/func_1519E970.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1CBE20/func_1519EA04.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1CBE20/func_1519EA78.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1CBE20/func_1519EB8C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1CBE20/func_1519ED24.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1CBE20/func_1519ED84.s")

struct Sub1519EF04 {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    f32 unk14;
    f32 unk18;
    f32 unk1C;
};

struct Obj1519EF04 {
    char pad0[0x2C];
    f32 unk2C;
    f32 unk30;
    f32 unk34;
    f32 unk38;
    f32 unk3C;
    f32 unk40;
    f32 unk44;
    f32 unk48;
    char pad4C[0x110 - 0x4C];
    struct Sub1519EF04 *unk110;
};

s32 func_1519EF04(struct Obj1519EF04 *a0) {
    struct Sub1519EF04 *v1 = a0->unk110;

    a0->unk2C = v1->unk18 * 10.0f;
    a0->unk30 = v1->unk1C * 10.0f;
    a0->unk40 = v1->unkC;
    a0->unk44 = v1->unk10;
    a0->unk48 = v1->unk14;
    a0->unk34 = v1->unk0;
    a0->unk38 = v1->unk4;
    a0->unk3C = v1->unk8;
    return 1;
}
