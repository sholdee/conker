#include <ultra64.h>
#include "functions.h"
#include "variables.h"


extern f32 func_15144B68(f32);

struct Foo151B8B40 {
    char pad20[0x20];
    f32 unk20;
    char pad24[0x4];
    f32 unk28;
    char pad2C[0x10];
    f32 unk3C;
    f32 unk40;
    f32 unk44;
    f32 unk48;
    f32 unk4C;
    f32 unk50;
    char pad54[0x4];
    f32 unk58;
    f32 unk5C;
};

s32 func_151B8B40(struct Foo151B8B40 *arg0) {
    arg0->unk3C = sinf(arg0->unk44) * arg0->unk5C + arg0->unk48;
    arg0->unk44 = arg0->unk44 + arg0->unk4C * D_800BE9A4;
    arg0->unk44 = func_15144B68(arg0->unk44);
    arg0->unk20 = arg0->unk20 + arg0->unk50 * D_800BE9A4;
    arg0->unk28 = arg0->unk28 + arg0->unk58 * D_800BE9A4;
    return 1;
}

extern void func_151D9450(void*, void*);

struct Foo151B8BE0 {
    char pad44[0x44];
    f32 unk44;
    char pad48[0x10];
    f32 unk58;
    f32 unk5C;
    f32 unk60;
    f32 unk64;
};

void func_151B8BE0(struct Foo151B8BE0 *arg0, void *arg1) {
    arg0->unk44 = sinf(arg0->unk58) * arg0->unk64 + arg0->unk5C;
    arg0->unk58 = arg0->unk58 + arg0->unk60 * D_800BE9A4;
    arg0->unk58 = func_15144B68(arg0->unk58);
    func_151D9450(arg0, arg1);
}

struct Foo151B8C54 {
    char pad58[0x58];
    f32 unk58;
};

struct Bar151B8C54 {
    f32 unk0;
    char pad4[0x4];
    f32 unk8;
    char padC[0x4];
    f32 unk10;
    f32 unk14;
    f32 unk18;
    f32 unk1C;
    char pad20[0x4];
    f32 unk24;
    f32 unk28;
};

s32 func_151B8C54(struct Foo151B8C54 *arg0) {
    struct Bar151B8C54 *v1 = (struct Bar151B8C54 *)((char *)arg0 + 0x120);
    arg0->unk58 = sinf(v1->unk10) * v1->unk28 + v1->unk14;
    v1->unk10 = v1->unk10 + v1->unk18 * D_800BE9A4;
    v1->unk10 = func_15144B68(v1->unk10);
    v1->unk0 += v1->unk1C * (&D_800BE9A4)[0];
    v1->unk8 += v1->unk24 * (&D_800BE9A4)[0];
    return 1;
}

struct Foo151B8CFC {
    char pad38[0x38];
    f32 unk38;
    char pad3C[0x4];
    f32 unk40;
    char pad44[0x4];
    f32 unk48;
};

struct Bar151B8CFC {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    char pad14[0x4];
    f32 unk18;
};

s32 func_151B8CFC(struct Foo151B8CFC *arg0) {
    struct Bar151B8CFC *v1 = (struct Bar151B8CFC *)((char *)arg0 + 0x110);
    arg0->unk38 = sinf(v1->unk8) * v1->unk4 + v1->unk0;
    v1->unk8 = v1->unk8 + v1->unkC * D_800BE9A4;
    v1->unk8 = func_15144B68(v1->unk8);
    arg0->unk40 += v1->unk10 * (&D_800BE9A4)[0];
    arg0->unk48 += v1->unk18 * (&D_800BE9A4)[0];
    return 1;
}
