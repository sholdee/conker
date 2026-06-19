#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_1CC440/func_1519EF90.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1CC440/func_1519F108.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1CC440/func_1519F168.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1CC440/func_1519F1C8.s")

s32 *func_1519F1C8(void *arg0, s32 arg1);

struct Sub1519F3B8 {
    s32 *unk0;
    s32 unk4;
    s32 *unk8;
    s32 unkC;
};

struct Obj1519F3B8 {
    u8 pad0[0x58];
    struct Sub1519F3B8 unk58;
};

void func_1519F3B8(struct Obj1519F3B8 *arg0) {
    struct Sub1519F3B8 *p = &arg0->unk58;
    p->unk0 = func_1519F1C8(arg0, 6);
    p->unk4 = 0;
    p->unk8 = func_1519F1C8(arg0, 7);
    p->unkC = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1CC440/func_1519F400.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1CC440/func_1519F48C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1CC440/func_1519F4F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1CC440/func_1519F7F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1CC440/func_1519FE6C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1CC440/func_151A084C.s")

struct Obj151A0928 {
    u8 pad0[0x28];
    s32 *unk28;
    u8 unk2C;
};

void func_151A0928(struct Obj151A0928 *arg0) {
    s32 *ptr = (s32 *)((u8 *)arg0->unk28 + 0x58);
    if (arg0->unk2C == 6) {
        ptr[1] = 0;
    } else {
        ptr[3] = 0;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1CC440/func_151A0950.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1CC440/func_151A09B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1CC440/func_151A0A10.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1CC440/func_151A0AF8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1CC440/func_151A0C0C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1CC440/func_151A0E40.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1CC440/func_151A0F28.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1CC440/func_151A1010.s")

void func_151A11CC(f32 arg0, f32 arg1, s32 arg2, s32 arg3) {
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1CC440/func_151A11E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1CC440/func_151A175C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1CC440/func_151A18DC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1CC440/func_151A1998.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1CC440/func_151A1E34.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1CC440/func_151A1EE8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1CC440/func_151A1FB4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1CC440/func_151A24A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1CC440/func_151A25E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1CC440/func_151A26EC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1CC440/func_151A2960.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1CC440/func_151A2A14.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1CC440/func_151A2AD4.s")

void func_151A2B84(f32 *in, s32 a1, s32 a2, s32 a3, f32 t, f32 *out) {
    f32 s = 1.0f - t;
    out[0] = in[0] * s;
    out[1] = in[1] * s;
    out[2] = in[2] * s;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1CC440/func_151A2BD0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1CC440/func_151A2C24.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1CC440/func_151A2F0C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1CC440/func_151A3150.s")
