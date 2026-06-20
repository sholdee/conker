#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void func_1519CDB0(s32, f32, s32);

s32 func_15195DD4(s32, s32, s32, s32, s32, s32, s32);

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C2C60/func_151957B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C2C60/func_1519582C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C2C60/func_15195868.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C2C60/func_15195984.s")

s16 func_15195A84(s16 arg0, s32 arg1, s32 arg2, s32 arg3) {
    return arg0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C2C60/func_15195AA8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C2C60/func_15195D00.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C2C60/func_15195DD4.s")

s32 func_15195FB0(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    return func_15195DD4(*(s32 *)(arg0 + 0x1C), arg1, arg2, arg3, arg4, arg5, arg6);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C2C60/func_15195FF0.s")

void func_15196318(u8 *arg0, s32 arg1, s32 arg2) {
    if (arg0 != 0) {
        arg0[0x12] = arg1;
        arg0[0x13] = arg2;
    }
}

extern void (*D_8008F898[])(void *);
extern void (*D_8008F88C[])(void *);
void func_151478F4(void *);

void func_15196330(void *arg0) {
    s8 *temp;

    temp = *(s8 **)((u8 *)arg0 + 0x98);
    if (temp[0x65] != -1) {
        D_8008F898[temp[0x65]](arg0);
    }
    if (temp[0x62] != -1) {
        D_8008F88C[temp[0x62]](arg0);
    }
    func_151478F4(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C2C60/func_151963B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C2C60/func_15196438.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C2C60/func_15196748.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C2C60/func_15196B4C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C2C60/func_15197148.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C2C60/func_151979F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C2C60/func_15197A0C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C2C60/func_15197A68.s")

struct ConkerStruct15197A7C {
    s32 unk0;
    u8 unk4;
};

extern void func_15147D64(struct ConkerStruct15197A7C *, s32);

void func_15197A7C(u8 *arg0) {
    struct ConkerStruct15197A7C sp18;

    if (arg0 != 0) {
        sp18.unk0 = (s32) arg0;
        sp18.unk4 = arg0[0x3B];
        func_15147D64(&sp18, 8);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C2C60/func_15197AB4.s")

typedef struct {
    char pad0[0x1C];
    s16 unk1C;
    char pad1E[0x2C - 0x1E];
    f32 unk2C;
    f32 unk30;
    char pad34[0x5C - 0x34];
    u8 unk5C;
    char pad5D[0x164 - 0x5D];
    f32 unk164;
    s16 unk168;
    s16 unk16A;
} Struct15197BBC;

s32 func_15197BBC(Struct15197BBC *arg0) {
    s16 temp;

    temp = arg0->unk1C;
    arg0->unk30 = arg0->unk30 - (arg0->unk30 * arg0->unk164);
    arg0->unk2C = arg0->unk2C - (arg0->unk2C * arg0->unk164);
    if (temp < arg0->unk168) {
        arg0->unk5C = temp * arg0->unk16A;
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C2C60/func_15197C10.s")

typedef struct {
    s32 unk0;
    u8 unk4;
} SubA_15198054;

typedef struct {
    s32 unk0;
    union {
        u8 b4;
        s32 w4;
    } u4;
    u8 unk8;
    u8 unk9;
} ArgB_15198054;

void func_151993B4();

void func_15198054(void *arg0, s32 arg1, u8 arg2) {
    SubA_15198054 *temp_v1 = *(SubA_15198054 **)((u8 *)arg0 + 0x98);
    ArgB_15198054 *b = (ArgB_15198054 *)arg1;

    if (arg2 == 0 || arg2 == 2 || arg2 == 8) {
        if ((b->unk0 == temp_v1->unk0) || (b->u4.b4 == temp_v1->unk4)) {
            func_151993B4(arg0);
        }
    } else if (arg2 == 0x2D) {
        if (temp_v1->unk0 == b->unk0) {
            temp_v1->unk0 = b->u4.w4;
            temp_v1->unk4 = b->unk9;
        } else if (temp_v1->unk0 == b->u4.w4) {
            temp_v1->unk0 = b->unk0;
            temp_v1->unk4 = b->unk8;
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C2C60/func_15198110.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C2C60/func_15198570.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C2C60/func_151987CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C2C60/func_1519897C.s")

void func_15198C60(void) {
    func_10010F30(0x1AA, 0x7FFF, 0x40, 0, 0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C2C60/func_15198C90.s")

void func_15198D40(s8 *arg0) {
    u8 *temp = *(u8 **)(arg0 + 0x98);
    if (arg0[0x2C] != 0) {
        u16 val = *(u16 *)(temp + 0x66);
        if (val != 0) {
            func_100111C8(val);
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C2C60/func_15198D7C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C2C60/func_15198D88.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C2C60/func_151990AC.s")

struct ConkerStruct151993B4 {
    char pad0[0x1E];
    u16 unk1E;
    char pad20[0x10];
    u8 unk30;
    char pad31[0x67];
    u8 *unk98;
};

void func_151993B4(struct ConkerStruct151993B4 *arg0) {
    u8 *p;
    p = arg0->unk98;
    arg0->unk30 = 0;
    arg0->unk1E &= 0xFFFD;
    p[6] |= 1;
    p[6] |= 4;
}

extern u8 D_800A8A9C[];

void func_151993E4(u8 *arg0) {
    u8 *q;
    u8 *p;
    s32 i;
    s32 found;

    q = *(u8 **)(arg0 + 0x98);
    p = *(u8 **)q;
    i = 0;
    found = 0;
    do {
        if (p[0x3B] == D_800A8A9C[i]) {
            found = 1;
        } else {
            i++;
        }
    } while (!found && i < 6);

    if (found) {
        ((u8 *)D_800E0900[i])[0x14] = 0;
    }
}

void func_1519944C(u8 *arg0) {
    u8 *q;
    u8 *p;
    s32 i;
    s32 found;

    q = *(u8 **)(arg0 + 0x98);
    p = *(u8 **)q;
    i = 0;
    found = 0;
    do {
        if (p[0x3B] == D_800A8A9C[i]) {
            found = 1;
        } else {
            i++;
        }
    } while (!found && i < 6);

    if (found) {
        ((u8 *)D_800E0900[i])[0x14] = 1;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C2C60/func_151994B8.s")

void func_15199834(u8 *arg0) {
    struct ConkerStruct15197A7C sp18;

    if (arg0 != 0) {
        sp18.unk0 = (s32) arg0;
        sp18.unk4 = arg0[0x3B];
        func_15147D64(&sp18, 0x26);
    }
}

void func_1516972C();

void func_1519986C(void *arg0, s32 arg1, u8 arg2) {
    SubA_15198054 *temp_v1 = *(SubA_15198054 **)((u8 *)arg0 + 0x98);
    ArgB_15198054 *b = (ArgB_15198054 *)arg1;

    if (arg2 == 0 || arg2 == 2 || arg2 == 0x26) {
        if ((b->unk0 == temp_v1->unk0) || (b->u4.b4 == temp_v1->unk4)) {
            func_1516972C(arg0);
        }
    } else if (arg2 == 0x2D) {
        if (temp_v1->unk0 == b->unk0) {
            temp_v1->unk0 = b->u4.w4;
            temp_v1->unk4 = b->unk9;
        } else if (temp_v1->unk0 == b->u4.w4) {
            temp_v1->unk0 = b->unk0;
            temp_v1->unk4 = b->unk8;
        }
    }
}

void func_15199980(void *);
void func_151478F4(void *);

void func_15199928(void *arg0) {
    func_15199980(arg0);
    func_151478F4(arg0);
}

void func_15147928(void *);

void func_15199954(void *arg0) {
    func_15199980(arg0);
    func_15147928(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C2C60/func_15199980.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C2C60/func_15199A10.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C2C60/func_15199C34.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C2C60/func_1519A9A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C2C60/func_1519B4B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C2C60/func_1519BE1C.s")

void func_1519BEB8(u8 *arg0) {
    u8 *q;
    u8 *p;
    s32 i;
    s32 found;

    q = *(u8 **)(arg0 + 0x98);
    p = *(u8 **)q;
    i = 0;
    found = 0;
    do {
        if (p[0x3B] == D_800A8A9C[i]) {
            found = 1;
        } else {
            i++;
        }
    } while (!found && i < 6);

    if (found) {
        ((u8 *)D_800E0900[i])[0x14] = 0;
    }
}

void func_1519BF20(u8 *arg0) {
    u8 *q;
    u8 *p;
    s32 i;
    s32 found;

    q = *(u8 **)(arg0 + 0x98);
    p = *(u8 **)q;
    i = 0;
    found = 0;
    do {
        if (p[0x3B] == D_800A8A9C[i]) {
            found = 1;
        } else {
            i++;
        }
    } while (!found && i < 6);

    if (found) {
        ((u8 *)D_800E0900[i])[0x14] = 1;
    }
}

void func_1519BF8C(void) {
    func_10010F30(0x1AA, 0x7FFF, 0x40, 0, 0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C2C60/func_1519BFBC.s")

void func_1519C06C(u8 *arg0) {
    u8 *temp = *(u8 **)(arg0 + 0x98);
    u16 val = *(u16 *)(temp + 0x130);
    if (val != 0) {
        func_100111C8(val);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C2C60/func_1519C09C.s")

void func_1519C258(s32);
void func_151617C4(s32);

void func_1519C200(s32 arg0) {
    func_1519C258(arg0);
    func_151617C4(arg0);
}

void func_151617E4(s32);

void func_1519C22C(s32 arg0) {
    func_1519C258(arg0);
    func_151617E4(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C2C60/func_1519C258.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C2C60/func_1519C26C.s")

typedef struct {
    char pad0[0x24];
    f32 unk24;
    s16 unk28;
    s16 unk2A;
} C4E4Sub;

typedef struct {
    char pad0[0x1C];
    s16 unk1C;
    char pad1E[0x2C - 0x1E];
    f32 unk2C;
    f32 unk30;
    char pad34[0x5C - 0x34];
    u8 unk5C;
} C4E4Struct;

s32 func_1519C4E4(C4E4Struct *arg0) {
    s32 i;
    C4E4Sub *p = (C4E4Sub *)((char *)arg0 + 0x110);

    for (i = D_800BE9E4; i > 0; i--) {
        arg0->unk2C = arg0->unk2C - arg0->unk2C * p->unk24;
        arg0->unk30 = arg0->unk30 - arg0->unk30 * p->unk24;
    }
    if (arg0->unk1C < p->unk28) {
        s32 a1 = arg0->unk1C * p->unk2A;
        if (a1 < arg0->unk5C) {
            arg0->unk5C = a1;
        }
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C2C60/func_1519C56C.s")

struct ConkerStruct1519C910_inner {
    char pad0[0x84];
    u16 unk84;
};

struct ConkerStruct1519C910 {
    struct ConkerStruct1519C910_inner *unk0;
    char pad4[0x154];
    s32 unk158;
    s32 unk15C;
};

struct ConkerStruct1519C910Outer {
    char pad0[0x98];
    struct ConkerStruct1519C910 *unk98;
};

s32 func_1519C910(struct ConkerStruct1519C910Outer *arg0) {
    struct ConkerStruct1519C910 *p = arg0->unk98;
    struct ConkerStruct1519C910_inner *q = p->unk0;
    u16 v = q->unk84;

    if (v != p->unk158) {
        if (v != p->unk15C) {
            return 0;
        }
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C2C60/func_1519C948.s")

s32 func_1519C970(s32 arg0) {
    func_1519CDB0(arg0, 0.5f, 0x1D);
    return 0;
}

s32 func_1519C998(s32 arg0) {
    func_1519CDB0(arg0, 0.2f, 0x1D);
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C2C60/func_1519C9C4.s")

struct Sub1519CD64 {
    s32 unk0;
    u8 unk4;
    u8 pad5[0x36];
    u8 unk3B;
};

struct Obj1519CD64 {
    u8 padD[0xD];
    u8 unkD;
    s16 unkE;
    u8 pad10[0x18];
    struct Sub1519CD64 *unk28;
    u8 unk2C;
};

void func_1519CD64(struct Obj1519CD64 *a0) {
    struct Sub1519CD64 *v0 = a0->unk28;

    if (v0->unk0 != 0 && v0->unk4 != 0xFF && v0->unk3B == a0->unk2C) {
        return;
    }
    a0->unkE = -1;
    a0->unkD |= 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C2C60/func_1519CDB0.s")
