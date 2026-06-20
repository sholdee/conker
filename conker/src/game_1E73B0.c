#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_1E73B0/func_151B9F00.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E73B0/func_151BA084.s")

typedef struct {
    s32 unk0;
    u8  unk4;
} SubA_151BA468;

typedef struct {
    u8  pad[0x3B];
    u8  unk3B;
} SomeObj_151BA468;

typedef struct {
    u8  pad[0x50];
    s32 unk50;
} Base_151BA468;

typedef struct {
    s32 unk0;
    union {
        s32 w4;
        u8  b4;
    } u4;
    u8  unk8;
    u8  unk9;
} ArgB_151BA468;

void func_151BA468(struct260 *arg0, s32 arg1, u8 arg2) {
    SubA_151BA468 *temp_v0 = (SubA_151BA468 *)((u8 *)arg0 + ((Base_151BA468 *)arg0)->unk50 + 0xF8);
    ArgB_151BA468 *b = (ArgB_151BA468 *)arg1;
    s32 b0 = temp_v0->unk0;
    SomeObj_151BA468 *o = (SomeObj_151BA468 *)b0;

    if (arg2 == 0) {
        if ((b0 == b->unk0) || (b->u4.b4 == o->unk3B)) {
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

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E73B0/func_151BA518.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E73B0/func_151BB044.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E73B0/func_151BB0E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E73B0/func_151BB61C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E73B0/func_151BBA9C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E73B0/func_151BBEE4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E73B0/func_151BBFBC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E73B0/func_151BC074.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E73B0/func_151BC104.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E73B0/func_151BC370.s")

s32 func_151BC580(s32 *arg0) {
    s32 *p = (s32 *)arg0[0x10];
    if (*p == 0) {
        return 0;
    }
    return 1;
}

typedef struct {
    s32 unk0;
    u8  unk4;
} SubA_151BC5A4;

typedef struct {
    s32 unk0;
    union {
        s32 w4;
        u8  b4;
    } u4;
    u8  unk8;
    u8  unk9;
} ArgB_151BC5A4;

void func_151BC5A4(struct260 *arg0, s32 arg1, u8 arg2) {
    SubA_151BC5A4 *temp_v0 = (SubA_151BC5A4 *)((u8 *)arg0 + 0x40);
    ArgB_151BC5A4 *b = (ArgB_151BC5A4 *)arg1;
    s32 b0 = temp_v0->unk0;

    if (arg2 == 0) {
        if ((b0 == b->unk0) || (temp_v0->unk4 == b->u4.b4)) {
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

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E73B0/func_151BC64C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E73B0/func_151BC794.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E73B0/func_151BCA90.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E73B0/func_151BD21C.s")

s32 func_151BD2BC(s32 *arg0) {
    s32 *p = (s32 *)arg0[0xA];
    if (*p == 0) {
        return 0;
    }
    if (*((u8 *)arg0 + 0x2C) != *((u8 *)p + 0x3B)) {
        return 0;
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E73B0/func_151BD2F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E73B0/func_151BD42C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E73B0/func_151BD43C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E73B0/func_151BD750.s")

extern void func_1513170C(void);

struct S151BD79C_sub {
    s32 unk0;
    u8 unk4;
    u8 pad5[0xF];
    f32 unk14;
    f32 unk18;
    f32 unk1C;
};

struct S151BD79C {
    u8 pad0[0x4C];
    f32 unk4C;
    f32 unk50;
    f32 unk54;
    u8 padB0[0xB0 - 0x58];
    struct S151BD79C_sub *unkB0;
};

void func_151BD79C(struct S151BD79C *arg0) {
    struct S151BD79C_sub *v0 = arg0->unkB0;
    if (v0->unk0 != 0 && v0->unk4 != 0xFF) {
        arg0->unk4C = v0->unk14;
        arg0->unk50 = v0->unk18;
        arg0->unk54 = v0->unk1C;
    }
    func_1513170C();
}

void func_151BD7F4(s32 arg0) {
    s32 sp18[2];
    sp18[0] = arg0;
    *((u8 *)&sp18 + 4) = *((u8 *)arg0 + 0x3B);
    func_151494E0((s32)&sp18, 0x3B);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E73B0/func_151BD828.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E73B0/func_151BDD8C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E73B0/func_151BE0AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E73B0/func_151BE138.s")

extern void func_151BE138(struct260 *arg0);

void func_151BE1B8(struct260 *arg0) {
    func_151BE138(arg0);
    func_1514933C(arg0);
}

extern void func_15149368(struct260 *arg0);

void func_151BE1E4(struct260 *arg0) {
    func_151BE138(arg0);
    func_15149368(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E73B0/func_151BE210.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E73B0/func_151BE4B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E73B0/func_151BE558.s")

void func_151BE604(s32 arg0, s32 arg1, u8 arg2) {
    func_15169850(arg1, arg2, arg0 + 0x110, arg0 + 0x114, arg0);
}

struct Sub151BE644 {
    u8  pad0[0x5];
    u8  unk5;
    u8  pad6[0x4A];
    s32 unk50;
};

void func_151BE644(struct210 *arg0) {
    struct Sub151BE644 *v0 = (struct Sub151BE644 *)((u8 *)arg0 + 0x110);
    if (*(s32 *)((u8 *)arg0 + 0x160) != 0) {
        s32 v1 = v0->unk50 + 0x28;
        *(s32 *)(v1 + (v0->unk5 << 2) + 8) = 0;
    }
}

void func_151BE674(struct210 *arg0) {
    func_151BE644(arg0);
    func_1513CA6C(arg0);
}

void func_151BE6A0(struct210 *arg0) {
    func_151BE644(arg0);
    func_1513CAA0(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E73B0/func_151BE6CC.s")

void func_151BE788(s32 arg0, s32 arg1, u8 arg2) {
    func_15169850(arg1, arg2, arg0 + 0x180, arg0 + 0x184, arg0);
}

typedef struct {
    u8 pad0[0x10];
    s32 unk10;
} BE7C8_elem;

typedef struct {
    u8 pad0[0x8];
    s32 *unk8;
    u8 unkC;
} BE7C8_sub;

void func_151BE7C8(struct210 *arg0) {
    BE7C8_sub *sub = (BE7C8_sub *)((u8 *)arg0 + 0x170);
    if (sub->unk8 != NULL) {
        s32 *arr = (s32 *)((u8 *)sub->unk8 + 0x28);
        ((BE7C8_elem *)&arr[sub->unkC])->unk10 = 0;
    }
}

extern void func_151BE7C8(struct210 *);
extern void func_151411A4(struct210 *);

void func_151BE7F8(struct210 *arg0) {
    func_151BE7C8(arg0);
    func_151411A4(arg0);
}

void func_151BE824(struct210 *arg0) {
    func_151BE7C8(arg0);
    func_151411C4(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E73B0/func_151BE850.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E73B0/func_151BEB20.s")

s32 func_151BEC94(s32 arg0, s32 arg1, s32 arg2, s32 arg3, u8 *arg4) {
    *arg4 = 1;
    return arg0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E73B0/func_151BECB8.s")

s32 func_151BEE94(u8 *arg0) {
    if (*(u8 *)(arg0 + 0x127) == 0xFF) {
        return 0;
    }
    if (*(s32 *)arg0 == 0) {
        return 0;
    }
    if (*(u8 *)(arg0 + 4) == 0xFF) {
        return 0;
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E73B0/func_151BEEE0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E73B0/func_151BF0C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E73B0/func_151BF340.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E73B0/func_151BF81C.s")

void func_151BFB2C(struct260 *arg0) {
    s32 i;
    s32 v;
    s32 *p = (s32 *)((u8 *)arg0 + 0x28);

    if (p[0] != 0) {
        func_1516972C((struct102 *)p[0]);
    }
    for (i = 0; i < 2; i = (u8)(i + 1)) {
        v = p[i + 1];
        if (v != 0) {
            func_1516972C((struct102 *)v);
        }
    }
}

void func_151BFBA4(struct260 *arg0) {
    func_151BFB2C(arg0);
    func_1514933C(arg0);
}

void func_151BFBD0(struct260 *arg0) {
    func_151BFB2C(arg0);
    func_15149368(arg0);
}

void func_151BFBFC(struct102 *arg0, s32 arg1, u8 arg2) {
    if (arg2 == 0x57) {
        func_1516972C(arg0);
    }
}
