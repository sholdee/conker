#include <ultra64.h>
#include "functions.h"
#include "variables.h"


extern void func_15147D64(u8 *arg0, s32 arg1);
extern void func_1519E3BC(void *arg0, s16 arg1, u8 arg2, u8 arg3);
extern s32 func_1519D030(void *arg0, s32 arg1, s16 arg2, u8 arg3, u8 arg4, u8 arg5);
extern s32 func_1514ED3C(s32 arg0, s32 arg1, s32 *arg2);
extern s32 func_1514EC1C(s32 arg0, s32 arg1, s16 arg2);
extern s32 D_800E0920;

typedef struct Obj1519E464 {
    s32 unk0;
    u8 pad4[0x37];
    u8 unk3B;
    u8 pad3C[0x48];
    u16 unk84;
    u8 pad86[0x14E];
    s32 unk1D4;
    u8 pad1D8[0x11C];
    s32 unk2F4;
} Obj1519E464;

typedef struct Sub1519E464 {
    Obj1519E464 *unk0;
    u8 unk4;
    u8 pad5[3];
    s32 unk8;
} Sub1519E464;

typedef struct Arg1519E464 {
    u8 unk0;
    u8 unk1;
    u8 pad2[0xA];
    u8 unkC;
    u8 unkD;
    s16 unkE;
    u8 pad10[0x18];
    Sub1519E464 unk28;
} Arg1519E464;

void func_1519CF70(u8 arg0) {
    u8 sp1C[4];

    sp1C[0] = arg0;
    func_15147D64(sp1C, 6);
}

struct s_1519CFA0 {
    char pad0[0x1E];
    u16 unk1E;
    char pad20[0x10];
    u8 unk30;
    char pad31[0x67];
    u8 *unk98;
};

void func_1519CFA0(struct s_1519CFA0 *arg0) {
    u8 *temp;

    arg0->unk30 = 0;
    temp = arg0->unk98;
    arg0->unk1E &= 0xFFFD;
    temp[6] |= 1;
    temp[6] |= 4;
}

extern void func_1514EDF0(struct260 *, s32);
extern void func_151478F4(struct s_1519CFA0 *);

void func_1519CFD0(struct s_1519CFA0 *arg0) {
    s32 *temp;

    temp = (s32 *)arg0->unk98;
    func_1514EDF0((struct260 *)arg0, *temp);
    func_151478F4(arg0);
}

extern void func_15147928(struct s_1519CFA0 *);

void func_1519D000(struct s_1519CFA0 *arg0) {
    s32 *temp;

    temp = (s32 *)arg0->unk98;
    func_1514EDF0((struct260 *)arg0, *temp);
    func_15147928(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1CA420/func_1519D030.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1CA420/func_1519D240.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1CA420/func_1519D454.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1CA420/func_1519D9F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1CA420/func_1519E1F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1CA420/func_1519E304.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1CA420/func_1519E3BC.s")

void func_1519E464(Arg1519E464 *arg0) {
    Sub1519E464 *sub;
    u8 invalid;
    s32 temp_v0;

    invalid = 0;
    sub = &arg0->unk28;
    if (arg0->unk28.unk0->unk0 == 0) {
        invalid = 1;
    }
    if (sub->unk0->unk3B == sub->unk4) {
    } else {
        invalid = 1;
    }
    if (invalid == 0) {
        if (sub->unk0->unk1D4 != 0) {
            invalid = 1;
            temp_v0 = func_1519D030(sub->unk0, sub->unk8, arg0->unkE, arg0->unkD & 1, arg0->unkC, arg0->unk1);
            if (temp_v0 != 0) {
                if (func_1514ED3C(sub->unk0->unk2F4, (s32)arg0, 0) != 0) {
                    func_1514EC1C(temp_v0, (s32)sub->unk0, 0x10);
                }
            }
        }
    }
    if (invalid != 0) {
        arg0->unkE = -1;
        arg0->unkD |= 1;
    }
}

typedef struct {
    s32 unk0;
    u8  unk4;
} SubA_1519E570;

typedef struct {
    s32 unk0;
    union {
        s32 w4;
        u8  b4;
    } u4;
    u8  unk8;
    u8  unk9;
} ArgB_1519E570;

void func_1519E570(struct260 *arg0, s32 arg1, u8 arg2) {
    SubA_1519E570 *temp_v0 = (SubA_1519E570 *)((u8 *)arg0 + 0x28);
    ArgB_1519E570 *b = (ArgB_1519E570 *)arg1;

    if (arg2 == 0) {
        if ((b->unk0 == temp_v0->unk0) || (b->u4.b4 == temp_v0->unk4)) {
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

void func_1519E61C(struct102 *arg0, s32 arg1, u8 arg2) {
    if (arg2 == 0 || arg2 == 9) {
        func_1516972C(arg0);
    }
}

extern void func_1519CF70(u8);

void func_1519E65C(s32 arg0) {
    func_1519CF70(3);
    func_1519CF70(4);
}

void func_1519E688(void) {
    func_1519CF70(3);
    func_1519CF70(4);
    func_15147D64(0, 9);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1CA420/func_1519E6BC.s")

void func_1519E754(Arg1519E464 *arg0) {
    Sub1519E464 *sub;
    u8 invalid;

    invalid = 0;
    sub = &arg0->unk28;
    if (arg0->unk28.unk0->unk0 == 0) {
        invalid = 1;
    }
    if (sub->unk0->unk3B != sub->unk4) {
        invalid = 1;
    }
    if (invalid == 0) {
        sub->unk8 += D_800BE9E4;
        if (sub->unk0->unk84 != 0x7C) {
            invalid = 1;
            if (sub->unk8 >= 0xC9) {
                func_1519E3BC(sub->unk0, 0x12C, arg0->unkC, arg0->unk1);
            }
        }
    }
    if (invalid != 0) {
        D_800E0920 = 0;
        arg0->unkE = -1;
        arg0->unkD |= 1;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1CA420/func_1519E818.s")

extern void func_1514EDF0(struct260 *, s32);

void func_1519E8CC(struct260 *arg0) {
    func_1514EDF0(arg0, *(s32 *)((u8 *)arg0 + 0x28));
    func_1514933C(arg0);
}

void func_1519E8F8(struct260 *arg0) {
    func_1514EDF0(arg0, *(s32 *)((u8 *)arg0 + 0x28));
    func_15149368(arg0);
}

void func_1519E924(struct260 *arg0) {
    D_800E0920 = 0;
    func_1514933C(arg0);
}

void func_1519E948(struct260 *arg0) {
    D_800E0920 = 0;
    func_15149368(arg0);
}
