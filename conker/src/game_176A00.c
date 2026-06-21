#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern f32 D_800A578C;
extern f32 D_800A5790;
extern void func_1513F680();


#pragma GLOBAL_ASM("asm/nonmatchings/game_176A00/func_15149550.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_176A00/func_15149838.s")

struct Foo15149A94Inner {
    char pad0[0x8];
    f32 unk8;
    char padC[0x14];
    f32 unk20;
    char pad24[0x20];
    f32 unk44;
};

struct Foo15149A94 {
    char pad1C[0x1C];
    s16 unk1C;
    char pad1E[0xE];
    f32 unk2C;
    f32 unk30;
    char pad34[0x24];
    s32 unk58;
    char pad5C[0x14];
    u8 unk70;
    u8 unk71;
    u8 unk72;
    u8 unk73;
    u8 unk74;
    char pad75[0x9B];
    struct Foo15149A94Inner unk110;
    u8 unk158;
};

s32 func_15149A94(u8 *arg0) {
    struct Foo15149A94Inner *temp_v0;
    s32 var_v1;
    s32 flags;

    flags = *(u8 *)(arg0 + 0x74);
    var_v1 = 1;
    temp_v0 = (struct Foo15149A94Inner *)(arg0 + 0x110);
    if (!(flags & 2)) {
        *(f32 *)(arg0 + 0x2C) += (temp_v0->unk8 - *(f32 *)(arg0 + 0x2C)) * temp_v0->unk44;
        if ((temp_v0->unk8 * D_800A578C) < *(f32 *)(arg0 + 0x2C)) {
            *(u8 *)(arg0 + 0x74) |= 2;
            flags = *(u8 *)(arg0 + 0x74);
        } else {
            var_v1 = 0;
            flags = *(u8 *)(arg0 + 0x74);
        }
    }
    if (!(flags & 8)) {
        *(f32 *)(arg0 + 0x30) += (temp_v0->unk20 - *(f32 *)(arg0 + 0x30)) * temp_v0->unk44;
        if ((temp_v0->unk20 * D_800A5790) < *(f32 *)(arg0 + 0x30)) {
            *(u8 *)(arg0 + 0x74) |= 8;
        } else {
            var_v1 = 0;
        }
    }
    if (var_v1) {
        func_1513F680(arg0, *(u8 *)(arg0 + 0x70), 0xD, *(u8 *)(arg0 + 0x72), *(u8 *)(arg0 + 0x73));
    }
    if (*(s16 *)(arg0 + 0x1C) < 5) {
        func_1513F680(arg0, *(u8 *)(arg0 + 0x70), *(u8 *)(arg0 + 0x158), *(u8 *)(arg0 + 0x72), *(u8 *)(arg0 + 0x73));
        *(s16 *)(arg0 + 0x1C) = 0x64;
        *(s32 *)(arg0 + 0x58) &= -2;
    }
    return 1;
}

struct Foo15149BF4 {
    char pad0[0x2C];
    f32 unk2C;
    f32 unk30;
    char pad34[0x11C];
    f32 unk150;
};

s32 func_15149BF4(struct Foo15149BF4 *arg0) {
    s32 ret;

    arg0->unk2C = arg0->unk2C - (arg0->unk2C * arg0->unk150);
    arg0->unk30 = arg0->unk30 - (arg0->unk30 * arg0->unk150);
    if (arg0->unk2C < 2.0f) {
        goto ret0;
    }
    ret = 1;
    if (arg0->unk30 < 2.0f) {
        ret0:
        return 0;
    }
    return ret;
}

extern f32 D_800BE9A4;
s32 func_15149C58(f32 *arg0) {
    arg0[11] -= arg0[11] * arg0[84];
    arg0[12] -= arg0[12] * arg0[84];
    arg0[20] += arg0[19] * D_800BE9A4;
    arg0[14] += arg0[20] * D_800BE9A4;
    if (arg0[87] < arg0[14]) {
        return 0;
    }
    if ((arg0[11] < 4.0f) || (arg0[12] < 4.0f)) {
        return 0;
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_176A00/func_15149D18.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_176A00/func_15149EC4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_176A00/func_15149FD0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_176A00/func_1514A19C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_176A00/func_1514A380.s")

struct Foo1514A498 {
    char pad1C[0x1C];
    s16 unk1C;
    char pad1E[0xE];
    f32 unk2C;
    f32 unk30;
    char pad34[0x28];
    u8 unk5C;
    char pad5D[0xE7];
    f32 unk144;
    char pad148[0xE];
    s16 unk156;
    s16 unk158;
};

s32 func_1514A498(struct Foo1514A498 *arg0) {
    arg0->unk30 = arg0->unk30 - arg0->unk30 * arg0->unk144;
    arg0->unk2C = arg0->unk2C - arg0->unk2C * arg0->unk144;
    if (arg0->unk1C < arg0->unk156) {
        arg0->unk5C = arg0->unk1C * arg0->unk158;
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_176A00/func_1514A4EC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_176A00/func_1514A594.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_176A00/func_1514A6A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_176A00/func_1514AB5C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_176A00/func_1514AD9C.s")

extern f32 D_800BE9A4;
s32 func_1514AF74(f32 *arg0) {
    arg0[11] -= arg0[11] * arg0[84];
    arg0[12] -= arg0[12] * arg0[84];
    arg0[14] += (arg0[20] * D_800BE9A4) + (((0.5f * arg0[19]) * D_800BE9A4) * D_800BE9A4);
    arg0[20] += arg0[19] * D_800BE9A4;
    if ((arg0[11] < 10.0f) || (arg0[12] < 10.0f)) {
        return 0;
    }
    return 1;
}

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

struct Foo1514C2B8 {
    char pad1C[0x1C];
    s16 unk1C;
    char pad1E[0x3A];
    s32 unk58;
    char pad5C[0x15];
    u8 unk71;
    u8 unk72;
    char pad73[0xE1];
    f32 unk154;
    char pad158[0x8];
    f32 unk160;
    s16 unk164;
};

s32 func_1514C2B8(struct Foo1514C2B8 *arg0) {
    arg0->unk72 = 0;
    arg0->unk71 = 0x24;
    arg0->unk1C = arg0->unk164;
    arg0->unk58 |= 0x08000000;
    arg0->unk154 = arg0->unk160;
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_176A00/func_1514C2F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_176A00/func_1514C470.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_176A00/func_1514C678.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_176A00/func_1514C858.s")
