#include <ultra64.h>
#define func_15083568 func_15083568_orig
#define func_1514D3B0 func_1514D3B0_orig
#include "functions.h"
#undef func_15083568
#undef func_1514D3B0
#include "variables.h"

struct St1514DE94 {
    char pad0[0x38];
    s32 unk38;
};
struct St1514DE94 *func_15083568(struct127 *, s32, f32, s32);

typedef struct struct_1514EBA4 {
    char pad0[0x10];
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s16 unk1C;
} struct_1514EBA4;

extern struct_1514EBA4 *func_15167A68(s32, s32, s32, s32, s32, s32);


#pragma GLOBAL_ASM("asm/nonmatchings/game_179F30/func_1514CA80.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_179F30/func_1514D15C.s")

typedef struct Node1514D310 {
    char pad0[0x10];
    s32 unk10;
    struct Node1514D310 *unk14;
    char pad18[0x4];
    s16 unk1C;
} Node1514D310;

typedef struct Cont1514D310 {
    char pad0[0x2F4];
    Node1514D310 *unk2F4;
} Cont1514D310;

typedef struct Struct8008ABE8 {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
} Struct8008ABE8;

extern void (*D_8008AB58[])(s32);
extern s32 (*D_8008AB64[])(s32, s32, s32);
extern Struct8008ABE8 *D_8008ABE8[];
s32 func_1514D4B8(s16, s16);

s32 func_1514D310(Cont1514D310 *arg0) {
    Node1514D310 *node;
    Node1514D310 *next;

    node = arg0->unk2F4;
    while (node != 0) {
        next = node->unk14;
        if (D_8008ABE8[node->unk1C]->unk2 != -1) {
            D_8008AB58[D_8008ABE8[node->unk1C]->unk2](node->unk10);
        }
        func_1516972C((struct102 *) node);
        node = next;
    }
    return 1;
}

s32 func_1514D3B0(Cont1514D310 *arg0, s16 arg1, s32 arg2, s32 arg3) {
    Node1514D310 *node;
    s32 result;

    node = arg0->unk2F4;
    result = 0;
    if (node != 0) {
        do {
            if ((arg1 == node->unk1C) || (func_1514D4B8(D_8008ABE8[arg1]->unk4, node->unk1C) != 0)) {
                if (D_8008ABE8[node->unk1C]->unk0 != -1) {
                    if (D_8008AB64[D_8008ABE8[node->unk1C]->unk0](node->unk10, arg2, arg3) != 0) {
                        result = 1;
                    } else {
                        result = 0;
                    }
                }
            }
            node = node->unk14;
        } while (node != 0);
    }
    return result;
}

s32 func_1514D4B8(s16 arg0, s16 arg1) {
    if (arg0 == -1) {
        return 0;
    }
    if (arg0 == arg1) {
        return 1;
    }

    if (func_1514D4B8(D_8008ABE8[arg0]->unk6, arg1) != 0) {
        return 1;
    }
    if (func_1514D4B8(D_8008ABE8[arg0]->unk4, arg1) != 0) {
        return 1;
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_179F30/func_1514D564.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_179F30/func_1514D64C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_179F30/func_1514D96C.s")

s32 func_15158BD0(s32, s32, s32);
s32 func_1514EC1C(s32, s32, s16);

void func_1514D978(s32 arg0) {
    struct {
        s32 unk0;
        s32 unk4;
        s32 unk8;
        s32 unkC;
        f32 unk10;
        s32 unk14;
        s32 unk18;
        s32 unk1C;
    } sp20;
    s32 v0;

    sp20.unk0 = 0;
    sp20.unk4 = 0;
    sp20.unk8 = 0;
    sp20.unkC = 0;
    sp20.unk14 = 0;
    sp20.unk18 = 0;
    sp20.unk1C = 0;
    sp20.unk10 = 12.0f;

    v0 = func_15158BD0(arg0, 1, 0x20);
    if (v0 != 0) {
        memcpy((void *)(v0 + 0x58), &sp20, 0x20);
        func_1514EC1C(v0, arg0, 0x13);
    }
}

s32 func_151ACA60(s32, f32, s32);
s32 func_1514EC1C(s32, s32, s16);

void func_1514D9F4(s32 arg0) {
    s32 v0;
    func_1514D978(arg0);
    v0 = func_151ACA60(arg0, 20.0f, 0);
    func_1514EC1C(v0, arg0, 0x14);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_179F30/func_1514DA38.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_179F30/func_1514DAA4.s")

s32 func_15158BD0(s32, s32, s32);
s32 func_1514EC1C(s32, s32, s16);

void func_1514DB18(s32 arg0) {
    s32 v0 = func_15158BD0(arg0, 1, 0);
    if (v0 != 0) {
        func_1514EC1C(v0, arg0, 0x13);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_179F30/func_1514DB58.s")

extern s32 D_800BE9F0;
void func_151B2060(void);

void func_1514DB64(void) {
    if (D_800BE9F0 == 0x14) {
        func_151B2060();
    }
}

void func_1514F194(void);

void func_1514DB98(void) {
    func_1514F194();
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_179F30/func_1514DBB8.s")

void func_1514DC38(struct127 *arg0) {
    func_1500EE18(arg0, 0xFF, 1);
}

void func_151D0F60(void *, s32, s32, s32);

void func_1514DC5C(void *arg0) {
    func_151D0F60(arg0, 0, 0xFF, 1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_179F30/func_1514DC84.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_179F30/func_1514DC98.s")

void func_1514DCAC(arg0)
struct127 *arg0;
{
    *(s32 *)((u8 *)arg0 + 0x9C) = 0x6000;
    func_15083568(arg0, 0x23, 1.0f, 0);
    func_15083568(arg0, 0x44, 1.0f, 0);
}

struct struct1514DCF4 {
    u8 pad[0x31C];
    struct127 *unk31C;
};

void func_1514DCF4(struct struct1514DCF4 *arg0) {
    if (arg0->unk31C != NULL) {
        *(u8 *)((u8 *)arg0->unk31C + 0x94) = 1;
    }
    func_15083568((struct127 *)arg0, 0x17, 1.0f, 0);
}

void func_1514DD2C(void) {
    func_1514DCAC();
}

void func_1514DD4C(void) {
    func_1514DCAC();
}

void func_1514DD6C(void) {
    func_1514DCAC();
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_179F30/func_1514DD8C.s")

void func_1514DDAC(void) {
    func_1514DCAC();
}

void func_1514DDCC(void) {
    func_1514DCAC();
}

void func_1514DDEC(void) {
    func_1514DCAC();
}

void func_1514DE0C(void) {
    func_1514DCAC();
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_179F30/func_1514DE2C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_179F30/func_1514DE38.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_179F30/func_1514DE44.s")

void func_1514DE50(void) {
    if (((u8 *)D_800D2E4C)[0x11] & 8) {
        func_1514DCAC();
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_179F30/func_1514DE88.s")

void func_15160CDC(s32, s32, void *, void *, f32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
s32 func_15160A58(s32, s32, void *, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern f32 D_800A5E04;
extern u8 D_800A58AC;
extern u8 D_800A58B8;
extern u8 D_800A58C4;
extern u8 D_800BE9B4;

void func_1514DE94(s32 arg0) {
    struct St1514DE94 *temp;

    func_15160CDC(arg0, 0xC, &D_800A58AC, &D_800A58B8, D_800A5E04, 2, 0x12C,
                  0xFF, 0xFF, 0xFF, 0xFF, 0, 1, 1, 0xFF, 1);
    temp = func_15083568((struct127 *)arg0, 0x3C, 1.0f, 0);
    if (D_800BE9B4 == 0) {
        temp->unk38 = 0x960;
    }
    func_1514EC1C(func_15160A58(arg0, 0, &D_800A58C4, 2, 0x12C, 0xB, 0xFF, 0xFF, 0xFF, 2, 0, -1, 0, 0, 0xFF, 1), arg0, 0x19);
}

s32 func_15083FB0(s32);

void func_1514DFD0(u8 *arg0) {
    arg0[0x65] = func_15083FB0(9) + 1;
    arg0[0x101] |= 0x34;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_179F30/func_1514E00C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_179F30/func_1514E194.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_179F30/func_1514E31C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_179F30/func_1514E508.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_179F30/func_1514E5B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_179F30/func_1514E668.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_179F30/func_1514E718.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_179F30/func_1514E7C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_179F30/func_1514E824.s")

void func_1514E830(struct102 *arg0) {
    func_1516972C(arg0);
}

void func_1518E308(void *);

void func_1514E850(void *arg0) {
    func_1518E308(arg0);
    func_1516972C(arg0);
}

void func_1514E87C(void) {
    func_1515F10C();
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_179F30/func_1514E89C.s")

s32 func_1514E89C();

s32 func_1514E920(arg0, arg1, arg2)
s32 arg0;
s32 arg1;
s32 arg2;
{
    u8 *sub;
    s32 flags;
    u8 *ptr;

    sub = (u8 *) arg0 + 0x110;
    switch (arg1) {
    case 0:
        flags = *(s32 *) (arg0 + 0x10);
        if (flags & 1) {
            *(s32 *) (arg0 + 0x10) = flags & ~1;
            ptr = *(u8 **) (sub + 0x44);
            if (ptr != 0) {
                ptr[0x30] = 0;
            }
        } else {
            *(s32 *) (arg0 + 0x10) = flags | 1;
        }
        break;
    case 2:
        *(s32 *) (arg0 + 0x10) = *(s32 *) (arg0 + 0x10) & ~1;
        ptr = *(u8 **) (sub + 0x44);
        if (ptr != 0) {
            ptr[0x30] = 0;
        }
        break;
    case 1:
        *(s32 *) (arg0 + 0x10) = *(s32 *) (arg0 + 0x10) | 1;
        break;
    default:
        return func_1514E89C(arg0, arg1, arg2);
    }
    return 1;
}

s32 func_1514E920();

void func_1514E9DC(void) {
    func_1514E920();
}

s32 func_1514E89C();

void func_1514E9FC(void) {
    func_1514E89C();
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_179F30/func_1514EA1C.s")

void func_1514EB6C(void) {
    func_1514E89C();
}

s32 func_1514EB8C(s32 arg0, s32 arg1, s32 arg2) {
    return 1;
}

struct_1514EBA4 *func_1514EBA4(s32 arg0, s16 arg1, s32 arg2) {
    struct_1514EBA4 *ret;

    ret = func_15167A68(0x24, 1, arg2 + 0x20, 1, 0xFF, 1);
    if (ret == 0) {
        return NULL;
    }
    ret->unk10 = arg0;
    ret->unk14 = 0;
    ret->unk18 = 0;
    ret->unk1C = arg1;
    return ret;
}

s32 func_1514EC1C(s32 arg0, s32 arg1, s16 arg2) {
    s32 result;
    struct_1514EBA4 *ret;

    result = 0;
    if (arg0 != 0) {
        ret = func_1514EBA4(arg0, arg2, 0);
        result = (s32) ret;
        if (ret != 0) {
            ret->unk14 = (s32) ((Cont1514D310 *) arg1)->unk2F4;
            ((Cont1514D310 *) arg1)->unk2F4 = (Node1514D310 *) ret;
            ret->unk18 = 0;
            if (ret->unk14 != 0) {
                ((struct_1514EBA4 *) ret->unk14)->unk18 = (s32) ret;
            }
        } else if (D_8008ABE8[arg2]->unk2 != -1) {
            D_8008AB58[D_8008ABE8[arg2]->unk2](arg0);
        } else {
            func_1516972C((struct102 *) arg0);
        }
    }
    return result;
}

typedef struct Node1514ECE0 {
    char pad0[0x14];
    struct Node1514ECE0 *unk14;
    char pad18[0x4];
    s16 unk1C;
} Node1514ECE0;

s32 func_1514ECE0(Node1514ECE0 *arg0, s16 arg1, s32 *arg2) {
    s32 found;
    Node1514ECE0 *node;
    Node1514ECE0 *next;

    found = 0;
    node = arg0;
    if (node != 0) {
        do {
            next = node->unk14;
            if (arg1 == node->unk1C) {
                found = 1;
            } else {
                node = next;
            }
        } while (node != 0 && found == 0);
    }

    if (arg2 != 0) {
        *arg2 = (s32) node;
    }
    return found;
}

typedef struct Node1514ED3C {
    char pad0[0x10];
    s32 key;
    struct Node1514ED3C *next;
} Node1514ED3C;

s32 func_1514ED3C(Node1514ED3C *node, s32 key, s32 *out) {
    s32 found = 0;
    Node1514ED3C *cur = node;
    Node1514ED3C *next;
    if (cur != 0) {
        do {
            next = cur->next;
            if (key == cur->key) {
                found = 1;
            } else {
                cur = next;
            }
        } while (cur != 0 && found == 0);
    }
    if (out != 0) {
        *out = (s32) cur;
    }
    return found;
}

typedef struct Node1514ED8C {
    char pad0[0x10];
    s32 unk10;
    struct Node1514ED8C *unk14;
    struct Node1514ED8C *unk18;
} Node1514ED8C;

typedef struct Cont1514ED8C {
    char pad0[0x2F4];
    Node1514ED8C *unk2F4;
} Cont1514ED8C;

s32 func_1514ED8C(Node1514ED8C *node, Cont1514ED8C *cont) {
    s32 ret;
    if (node == cont->unk2F4) {
        cont->unk2F4 = node->unk14;
    }
    if (node->unk14 != 0) {
        node->unk14->unk18 = node->unk18;
    }
    if (node->unk18 != 0) {
        node->unk18->unk14 = node->unk14;
    }
    ret = node->unk10;
    func_1516972C((struct102 *) node);
    return ret;
}

void func_1514EDF0(s32 key, Cont1514ED8C *cont) {
    Node1514ED8C *node;
    s32 ret;
    s32 out;
    u8 found;

    node = cont->unk2F4;
    out = 0;
    do {
        ret = func_1514ED3C((Node1514ED3C *) node, key, &out);
        found = ret;
        if (ret) {
            node = ((Node1514ED8C *) out)->unk14;
            func_1514ED8C((Node1514ED8C *) out, cont);
        }
    } while (found != 0);
}

struct Struct1514EE70 {
    s32 unk0;
    u8 unk4;
    u8 unk5;
    u16 unk6;
};

s32 func_1515BE50(struct Struct1514EE70 *, s32, s32, s32);

void func_1514EE70(u8 *arg0) {
    struct Struct1514EE70 sp20;
    s32 v0;

    sp20.unk0 = (s32) arg0;
    sp20.unk4 = arg0[0x3B];
    sp20.unk5 = 0;
    sp20.unk6 = 0x12C;
    v0 = func_1515BE50(&sp20, 0, 0xFF, 1);
    func_1514EC1C(v0, (s32) arg0, 0x16);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_179F30/func_1514EECC.s")

void func_1514F110(void) {
    func_1514F194();
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_179F30/func_1514F130.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_179F30/func_1514F194.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_179F30/func_1514F308.s")

void func_1514F3CC(struct127 *arg0) {
    struct {
        struct127 *unk0;
        u8 unk4;
        f32 unk8;
    } sp34;
    struct260 *temp_v0;

    sp34.unk0 = arg0;
    sp34.unk4 = arg0->unique_id;
    sp34.unk8 = 0.0f;

    temp_v0 = func_15149130(0x12C, -1, 0x3A, -1, 0, 0x2B, (struct37 *)0xC, 0xFF, 1);
    if (temp_v0 != NULL) {
        memcpy((void *)((s32)temp_v0 + 0x28), &sp34, 0xC);
    }
}

extern s32 D_800A5988;
s32 func_1518D1C0(s32, s32, s32, s32, s32, s32, s32 *);

void func_1514F44C(s32 arg0) {
    s32 v0;

    v0 = func_1518D1C0(arg0, 5, 0, 1, 0xFF, 1, &D_800A5988);
    func_1514EC1C(v0, arg0, 0xD);
}

extern void func_151D74B0(s32, s32, s32, s32, s32);

void func_1514F4A8(s32 arg0) {
    func_151D74B0(arg0, 1, -1, 0xFF, 1);
}

void func_1514F4D8(s32 arg0) {
    func_151D74B0(arg0, 2, 1, 0xFF, 1);
}

void func_1514F508(s32 arg0) {
    func_151D74B0(arg0, 3, 0, 0xFF, 1);
}

void func_1514F538(s32 arg0) {
    func_151D74B0(arg0, 4, -1, 0xFF, 1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_179F30/func_1514F568.s")

void func_1501175C(struct127 *arg0, u8 arg1, s32 arg2);

void func_1514F590(struct127 *arg0) {
    func_1501175C(arg0, 0xFF, 1);
    func_15011A78(arg0, 0xFF, 1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_179F30/func_1514F5CC.s")
