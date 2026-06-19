#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void func_15143794(s32, s32, f32, f32 *);


#pragma GLOBAL_ASM("asm/nonmatchings/game_1CC440/func_1519EF90.s")

struct Sub1519F108 {
    u8 pad0[0x58];
    s32 unk58;
    s32 unk5C;
    s32 unk60;
};

struct Obj1519F108 {
    u8 pad0[0x20];
    s32 unk20;
    u8 pad24[0x74];
    struct Sub1519F108 **unk98;
};

void func_151478F4(struct Obj1519F108 *);

void func_1519F108(struct Obj1519F108 *arg0) {
    struct Sub1519F108 **pp = arg0->unk98;
    s32 *ptr;
    if (*pp != 0) {
        ptr = (s32 *)((u8 *)*pp + 0x58);
        if (arg0->unk20 == 6) {
            ptr[0] = 0;
        }
        if (arg0->unk20 == 7) {
            ptr[2] = 0;
        }
    }
    func_151478F4(arg0);
}

void func_15147928(struct Obj1519F108 *);

void func_1519F168(struct Obj1519F108 *arg0) {
    struct Sub1519F108 **pp = arg0->unk98;
    s32 *ptr;
    if (*pp != 0) {
        ptr = (s32 *)((u8 *)*pp + 0x58);
        if (arg0->unk20 == 6) {
            ptr[0] = 0;
        }
        if (arg0->unk20 == 7) {
            ptr[2] = 0;
        }
    }
    func_15147928(arg0);
}

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

struct Sub151A09B4 {
    u8 pad0[0x3B];
    u8 unk3B;
};

struct Mid151A09B4 {
    u8 pad0[0x18];
    struct Sub151A09B4 *unk18;
};

struct Obj151A09B4 {
    u8 pad0[0x28];
    struct Mid151A09B4 *unk28;
};

struct Arg151A09B4 {
    struct Sub151A09B4 *unk0;
    u8 unk4;
};

void func_151A09B4(struct Obj151A09B4 *arg0, struct Arg151A09B4 *arg1, u8 arg2) {
    struct Sub151A09B4 *v0 = arg0->unk28->unk18;
    if (arg2 == 0) {
        if (v0 == arg1->unk0 || arg1->unk4 == v0->unk3B) {
            func_151A0928((struct Obj151A0928 *)arg0);
            func_1516972C((struct102 *)arg0);
        }
    }
}

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

void func_151A2BD0(f32 *in, s32 a1, s32 a2, f32 a3, f32 t, f32 *out) {
    func_15143794((s16) a1, (s16) a2, (1.0f - t) * a3, out);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1CC440/func_151A2C24.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1CC440/func_151A2F0C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1CC440/func_151A3150.s")
