#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_E5E90/func_150B89E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_E5E90/func_150B8F44.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_E5E90/func_150B9560.s")

s32 func_150B95FC(void *arg0) {
    s16 v0 = *(s16*)((u8*)arg0 + 0x1C);
    if (v0 < 0x20) {
        *(u8*)((u8*)arg0 + 0x5C) = v0 << 3;
    }
    return 1;
}

s32 func_150B961C(void *arg0) {
    s16 v0 = *(s16*)((u8*)arg0 + 0x1C);
    if (v0 < 0x40) {
        *(u8*)((u8*)arg0 + 0x28) = v0 << 2;
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_E5E90/func_150B963C.s")

struct Struct150B9D14 {
    char pad0[0x18];
    s32 unk18;
    s32 unk1C;
    f32 unk20;
    f32 unk24;
    f32 unk28;
    s32 unk2C;
    f32 unk30;
    f32 unk34;
    f32 unk38;
    f32 unk3C;
    f32 unk40;
};

extern void func_15142600(s32, s32, s32, s32, f32, f32, f32, f32, f32, f32, f32, f32);

s32 func_150B9D14(s32 arg0, struct Struct150B9D14 *arg1) {
    func_15142600(arg0, arg1->unk18, arg1->unk1C, arg1->unk2C,
                  arg1->unk30, arg1->unk34, arg1->unk38, arg1->unk3C,
                  arg1->unk40, arg1->unk20, arg1->unk24, arg1->unk28);
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_E5E90/func_150B9D8C.s")
