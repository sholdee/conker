#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_176A00/func_15149550.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_176A00/func_15149838.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_176A00/func_15149A94.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_176A00/func_15149BF4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_176A00/func_15149C58.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_176A00/func_15149D18.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_176A00/func_15149EC4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_176A00/func_15149FD0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_176A00/func_1514A19C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_176A00/func_1514A380.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_176A00/func_1514A498.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_176A00/func_1514A4EC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_176A00/func_1514A594.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_176A00/func_1514A6A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_176A00/func_1514AB5C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_176A00/func_1514AD9C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_176A00/func_1514AF74.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_176A00/func_1514B034.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_176A00/func_1514B364.s")

struct Foo1514B844 {
    char pad1C[0x1C];
    s16 unk1C;
    char pad1E[0x7A];
    u8 *unk98;
};

s32 func_1514B844(struct Foo1514B844 *arg0) {
    u8 *p = arg0->unk98;
    s16 v = arg0->unk1C;
    if (v < 0x10) {
        s32 sh = v << 4;
        if (sh < p[0x1B]) {
            p[0x1B] = sh;
        }
    }
    return 1;
}

extern f32 D_800BE9A4;

struct Foo1514B87C {
    char pad2C[0x2C];
    f32 unk2C;
    f32 unk30;
    char pad34[0x18];
    f32 unk4C;
};

s32 func_1514B87C(struct Foo1514B87C *arg0) {
    f32 temp = arg0->unk4C * D_800BE9A4;
    arg0->unk2C = arg0->unk2C + temp;
    arg0->unk30 = arg0->unk30 + temp;
    return 1;
}

struct Foo1514B8B0 {
    char pad1C[0x1C];
    s16 unk1C;
    char pad1E[0x3E];
    u8 unk5C;
};

s32 func_1514B8B0(struct Foo1514B8B0 *arg0) {
    s32 v = arg0->unk1C;
    if (v < 0x10) {
        s32 sh = v << 4;
        if (sh < arg0->unk5C) {
            arg0->unk5C = sh;
        }
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_176A00/func_1514B8E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_176A00/func_1514BC08.s")

extern void func_1514BC08(void *, void *);

void func_1514BE00(u8 *arg0) {
    func_1514BC08(arg0, arg0 + 0x110);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_176A00/func_1514BE20.s")

void func_1514BF50(f32 *arg0) {
    arg0[0x10] = arg0[0xD];
    arg0[0x11] = arg0[0xE] + 100.0f;
    arg0[0x12] = arg0[0xF];
}

void func_1514BF7C(u8 *arg0) {
    func_1514BC08(arg0, arg0 + 0x110);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_176A00/func_1514BF9C.s")

extern void func_1514BF9C(void *);
extern void func_1514BE20(void *);

s32 func_1514C258(void *arg0) {
    func_1514BF9C(arg0);
    func_1514BE20(arg0);
    return 1;
}

s32 func_1514C288(void *arg0) {
    func_1514BF9C(arg0);
    func_1514BF50(arg0);
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_176A00/func_1514C2B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_176A00/func_1514C2F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_176A00/func_1514C470.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_176A00/func_1514C678.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_176A00/func_1514C858.s")
