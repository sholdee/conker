#include <ultra64.h>
#include "functions.h"
#include "variables.h"

typedef struct {
    u8 pad0[0x94];
    s32 unk94;
    u8 pad98[0x13C];
    s32 unk1D4;
} struct_150EEE00_arg0;

extern u8 D_800A1638[];
extern u8 D_800A163C[];
extern f32 D_800A15F0[][3];

void *func_150EEF80(struct_150EEE00_arg0 *, u8, u8, s32);
void func_15143134(void *, void *, s32);
void func_151602C0(Header *, Header2 *, s32, s32, s32, s32, s32, s32, s32, u8, s32);
void func_150F0A24(f32 *);

void func_150EEE00(struct_150EEE00_arg0 *arg0, u8 arg1) {
    f32 sp54[3];
    Header sp4C;
    Header2 sp40;
    s32 temp_v1;

    if (D_800A163C[arg1] & arg0->unk94) {
        return;
    }

    func_150EEF80(arg0, arg1, 0xFF, 1);
    temp_v1 = arg0->unk1D4;
    if (temp_v1 != 0) {
        func_15143134(D_800A15F0[arg1], sp54, temp_v1 + (D_800A1638[arg1] << 6));
        sp4C.unk0 = 3;
        sp4C.unk1 = -1;
        sp4C.unk2 = (func_150ADA20() % 3U) + 4;
        sp4C.unk4 = 0;
        sp40.unk0 = (s32) sp54[0];
        sp40.unk4 = (s32) sp54[1];
        sp40.unk8 = (s32) sp54[2];
        func_151602C0(&sp4C, &sp40, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0, 0, 0xFF, 1);
        func_150F0A24(sp54);
    }
}

void func_150EEF40(struct210 *arg0, u8 arg1) {
    s8 sp18[6];

    *(struct210 **)&sp18[0] = arg0;
    sp18[4] = *(u8 *)((s32)arg0 + 0x3B);
    sp18[5] = arg1;
    func_151403A8(&sp18, 0x43);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_11C2B0/func_150EEF80.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_11C2B0/func_150EF38C.s")

s32 func_150EF784(u8 *arg0, s32 arg1, s32 arg2) {
    if (arg0[4] == 0x28) {
        return 1;
    }
    return 0;
}

void func_150EF7B0(u8 *arg0) {
    s32 i;
    s32 v;
    s32 *p = (s32 *)(arg0 + 0x110);

    for (i = 0; i != 8; i += 4) {
        v = *(s32 *)((u8 *)p + i + 0x1C);
        if (v != 0) {
            func_1516972C((struct102 *)v);
        }
    }
    v = p[9];
    if (v != 0) {
        func_1516972C((struct102 *)v);
    }
    v = p[10];
    if (v != 0) {
        func_1516972C((struct102 *)v);
    }
    v = p[11];
    if (v != 0) {
        func_1516972C((struct102 *)v);
    }
    func_1513CA6C(arg0);
}

void func_150EF860(u8 *arg0) {
    s32 i;
    s32 v;
    s32 *p = (s32 *)(arg0 + 0x110);

    for (i = 0; i != 8; i += 4) {
        v = *(s32 *)((u8 *)p + i + 0x1C);
        if (v != 0) {
            func_1516979C((struct102 *)v);
        }
    }
    v = p[9];
    if (v != 0) {
        func_1516979C((struct102 *)v);
    }
    v = p[10];
    if (v != 0) {
        func_1516979C((struct102 *)v);
    }
    v = p[11];
    if (v != 0) {
        func_1516979C((struct102 *)v);
    }
    func_1513CAA0((struct210 *)arg0);
}

typedef struct {
    s32 unk0;
    union {
        s32 w4;
        struct {
            u8 b4;
            u8 b5;
            u8 b6;
            u8 b7;
        } b;
    } u4;
    u8 unk8;
    u8 unk9;
} ArgB_150EF910;

typedef struct {
    s32 unk0;
    u8 unk4;
    u8 pad5[3];
    s32 unk8;
    u8 unkC;
    u8 unkD;
} SubA_150EF910;

void func_150EF910(void *arg0, s32 arg1, u8 arg2) {
    ArgB_150EF910 *b = (ArgB_150EF910 *)arg1;
    SubA_150EF910 *a = (SubA_150EF910 *)((u8 *)arg0 + 0x110);
    s32 bu0;
    s32 bu0b;
    s32 au0;
    u8 au4;
    u8 bu4;

    if (arg2 == 0) {
        au0 = a->unk0;
        bu0 = b->unk0;
        au4 = a->unk4;
        bu4 = b->u4.b.b4;
        if ((au0 == bu0) || (au4 == bu4)) {
            func_1516972C((struct102 *)arg0);
        }
    } else if (arg2 == 0x2D) {
        if (a->unk0 == b->unk0) {
            a->unk0 = b->u4.w4;
            a->unk4 = b->unk9;
        } else if (a->unk0 == b->u4.w4) {
            a->unk0 = b->unk0;
            a->unk4 = b->unk8;
        }
        if (a->unk8 == b->unk0) {
            a->unk8 = b->u4.w4;
            a->unkC = b->unk9;
        } else {
            if (a->unk8 == b->u4.w4) {
                a->unk8 = b->unk0;
                a->unkC = b->unk8;
            }
        block2_end: ;
        }
    } else if (arg2 == 0x43) {
        if ((a->unk0 == b->unk0) || (a->unk4 == b->u4.b.b4)) {
            if (a->unkD == b->u4.b.b5) {
                func_1516972C((struct102 *)arg0);
            }
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_11C2B0/func_150EFA4C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_11C2B0/func_150EFB80.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_11C2B0/func_150EFEC8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_11C2B0/func_150F00EC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_11C2B0/func_150F0198.s")

struct func150F02A0_sub {
    u8 pad0[0x8];
    u8 *unk8;
    u8 unkC;
};
struct func150F02A0_arg {
    u8 pad0[0x60];
    struct func150F02A0_sub *unk60;
};

void func_150F02A0(struct func150F02A0_arg *arg0);

void func_150F0260(struct func150F02A0_arg *arg0) {
    func_150F02A0(arg0);
}

void func_150F0280(struct func150F02A0_arg *arg0) {
    func_150F02A0(arg0);
}

void func_150F02A0(struct func150F02A0_arg *arg0) {
    struct func150F02A0_sub *temp = arg0->unk60;
    u8 *base = temp->unk8;
    *(s32*)(base + temp->unkC * 4 + 0x12C) = 0;
}

void func_150F0318(struct260 *arg0);

void func_150F02C0(struct260 *arg0) {
    func_150F0318(arg0);
    func_1514933C(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_11C2B0/func_150F02EC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_11C2B0/func_150F0318.s")

void func_150F0380(struct210 *arg0);

void func_150F0328(struct210 *arg0) {
    func_150F0380(arg0);
    func_151411A4(arg0);
}

void func_151411C4(struct210 *arg0);

void func_150F0354(struct210 *arg0) {
    func_150F0380(arg0);
    func_151411C4(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_11C2B0/func_150F0380.s")

void func_150F03E8(struct210 *arg0);
void func_151617C4(struct210 *arg0);

void func_150F0390(struct210 *arg0) {
    func_150F03E8(arg0);
    func_151617C4(arg0);
}

void func_151617E4(struct210 *arg0);

void func_150F03BC(struct210 *arg0) {
    func_150F03E8(arg0);
    func_151617E4(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_11C2B0/func_150F03E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_11C2B0/func_150F03F8.s")

typedef struct {
    s32 unk0;
    u8  unk4;
} SubA_F07E4;

typedef struct {
    s32 unk0;
    union {
        s32 w4;
        u8  b4;
    } u4;
    u8  unk8;
    u8  unk9;
} ArgB_F07E4;

void func_150F07E4(struct260 *arg0, s32 arg1, u8 arg2) {
    SubA_F07E4 *temp_v0 = *(SubA_F07E4 **)((u8 *)arg0 + 0x60);
    ArgB_F07E4 *b = (ArgB_F07E4 *)arg1;
    s32 b0;

    if (arg2 == 0) {
        b0 = b->unk0;
        if ((b0 == temp_v0->unk0) || (b->u4.b4 == temp_v0->unk4)) {
            func_1516972C((struct102 *)arg0);
        }
    } else if (arg2 == 0x2D) {
        if (temp_v0->unk0 == b->unk0) {
            temp_v0->unk0 = b->u4.w4;
            temp_v0->unk4 = b->unk9;
        } else if (temp_v0->unk0 == b->u4.w4) {
            temp_v0->unk0 = b->unk0;
            temp_v0->unk4 = b->unk8;
        }
    }
}

typedef struct {
    s32 unk0;
    u8  unk4;
} SubA_F088C;

typedef struct {
    s32 unk0;
    union {
        s32 w4;
        u8  b4;
    } u4;
    u8  unk8;
    u8  unk9;
} ArgB_F088C;

void func_150F088C(struct260 *arg0, s32 arg1, u8 arg2) {
    SubA_F088C *temp_v0 = (SubA_F088C *)((u8 *)arg0 + 0x170);
    ArgB_F088C *b = (ArgB_F088C *)arg1;
    s32 b0;

    if (arg2 == 0) {
        b0 = b->unk0;
        if ((b0 == temp_v0->unk0) || (b->u4.b4 == temp_v0->unk4)) {
            func_1516972C((struct102 *)arg0);
        }
    } else if (arg2 == 0x2D) {
        if (temp_v0->unk0 == b->unk0) {
            temp_v0->unk0 = b->u4.w4;
            temp_v0->unk4 = b->unk9;
        } else if (temp_v0->unk0 == b->u4.w4) {
            temp_v0->unk0 = b->unk0;
            temp_v0->unk4 = b->unk8;
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_11C2B0/func_150F0938.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_11C2B0/func_150F0A24.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_11C2B0/func_150F0BEC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_11C2B0/func_150F0E48.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_11C2B0/func_150F1020.s")

void func_150F10D4(struct210 *arg0) {
    s8 sp40[0x18];
    struct260 *temp_v0;

    *(struct210 **)&sp40[0] = arg0;
    sp40[4] = *(u8 *)((s32)arg0 + 0x3B);
    *(f32 *)&sp40[8] = 0.0f;
    *(f32 *)&sp40[0xC] = *(f32 *)((s32)arg0 + 0x14);
    *(f32 *)&sp40[0x10] = *(f32 *)((s32)arg0 + 0x18);
    *(f32 *)&sp40[0x14] = *(f32 *)((s32)arg0 + 0x1C);

    temp_v0 = func_15149130(0x12C, -1, 0x4C, -1, 0, 0x3A, (struct37 *)0x18, 0xFF, 1);
    if (temp_v0 != NULL) {
        memcpy((void *)((s32)temp_v0 + 0x28), &sp40, 0x18);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_11C2B0/func_150F1170.s")

void func_150F15F8(s32 arg0, s32 arg1, u8 arg2) {
    s32 *p = &arg0;
    s32 q;
    s32 b0;

    if (arg2 == 0x43) {
        b0 = *(s32 *)arg1;
        q = *p + 0x28;
        if ((b0 == *(s32 *)q) || (*(u8 *)(q + 4) == *(u8 *)(*(s32 *)&arg1 + 4))) {
            func_1516972C((struct102 *)*p);
        }
    } else {
        q = *p + 0x28;
        func_15149514(arg1, arg2, q, q + 4, *p);
    }
}

struct func150F1684_sub {
    s32 unk0;
    u8 unk4;
};

void func_150F1684(struct func150F1684_sub *arg0, struct func150F1684_sub *arg1, u8 arg2) {
    struct func150F1684_sub *temp = (struct func150F1684_sub *)((s32)arg0 + 0x18);
    s32 word;

    if (arg2 == 0x43) {
        word = arg1->unk0;
        if ((temp->unk0 == word) || (arg1->unk4 == temp->unk4)) {
            func_1516972C((struct102 *)arg0);
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_11C2B0/func_150F16DC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_11C2B0/func_150F1A00.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_11C2B0/func_150F1B48.s")

void func_150F1CB0(u8 *arg0) {
    if (*(u16 *)(arg0 + 0x84) == 0x14) {
        arg0[0x68] = 0x1B;
    } else {
        arg0[0x68] = 0xC;
    }
    arg0[0x69] = 0x13;
    if ((*(s32 *)(arg0 + 0x2E4) & 0x3) == 0x3) {
        arg0[0x69] = 0x14;
    }
    if ((*(s32 *)(arg0 + 0x2E4) & 0xC) == 0xC) {
        arg0[0x69] = 0x17;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_11C2B0/func_150F1D10.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_11C2B0/func_150F20F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_11C2B0/func_150F2230.s")
