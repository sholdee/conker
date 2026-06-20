#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_188F90/func_1515BAE0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_188F90/func_1515BBF0.s")

extern void *func_15167A68(s32, s32, s32, s32, s32, s32);

struct Struct1515BE50_src {
    u8 pad0[0x14];
    f32 unk14;
    f32 unk18;
    f32 unk1C;
};

struct Struct1515BE50_ret {
    u8 pad0[0x10];
    s32 unk10;
    s32 unk14;
    u8 pad18[0x8];
    f32 unk20;
    f32 unk24;
    f32 unk28;
    f32 unk2C;
    f32 unk30;
    f32 unk34;
    f32 unk38;
    f32 unk3C;
    f32 unk40;
    s32 unk44;
    s32 unk48;
};

s32 func_1515BE50(struct Struct1515BE50_src **arg0, s32 arg1, s32 arg2, s32 arg3) {
    struct Struct1515BE50_ret *temp_v0;
    struct Struct1515BE50_ret *sp2C;

    if (*arg0 == 0) {
        return 0;
    }
    temp_v0 = (struct Struct1515BE50_ret *)func_15167A68(0x32, arg3, arg1 + 0x50, 1, (u8)arg2, 1);
    if (temp_v0 == 0) {
        return 0;
    }
    sp2C = temp_v0;
    memcpy((s32)temp_v0 + 0x18, arg0, 8);
    sp2C->unk20 = (*arg0)->unk14;
    sp2C->unk24 = (*arg0)->unk18;
    sp2C->unk28 = (*arg0)->unk1C;
    sp2C->unk2C = (*arg0)->unk14;
    sp2C->unk30 = (*arg0)->unk18;
    sp2C->unk34 = (*arg0)->unk1C;
    sp2C->unk44 = 0;
    sp2C->unk48 = -1;
    sp2C->unk10 = 1;
    sp2C->unk14 = 0;
    sp2C->unk38 = 0.0f;
    sp2C->unk3C = 0.0f;
    sp2C->unk40 = 0.0f;
    return sp2C;
}

extern void func_1514EDF0(struct225 *, s32);

void func_1515BF50(struct225 *arg0) {
    func_1514EDF0(arg0, (s32)arg0->unk18);
    func_15169804((struct102 *)arg0);
}

void func_1515BF7C(struct225 *arg0) {
    func_1514EDF0(arg0, (s32)arg0->unk18);
    func_15169824((struct102 *)arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_188F90/func_1515BFA8.s")

void func_1515C0B8(s32 arg0, s32 arg1, u8 arg2) {
    func_15169850(arg1, arg2, arg0 + 0x18, arg0 + 0x1C, arg0);
}

s32 func_1514ECE0(void *, s16, void *);

s32 func_1515C0F8(struct102 *arg0, s32 *arg1) {
    s32 *temp;
    s32 v;

    if (arg0 == 0) {
        return 0;
    }
    if (func_1514ECE0(*(void **)((u8 *)arg0 + 0x2F4), 0x16, &temp) != 0) {
        v = *(s32 *)((u8 *)temp + 0x10);
        *arg1 = v + 0x38;
        return 1;
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_188F90/func_1515C158.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_188F90/func_1515C1A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_188F90/func_1515C244.s")
