#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void func_15143794(s32, s32, f32, f32 *);
s32 func_1510F8CC(s32);


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

struct Obj1519F400 {
    u8 pad0[0x58];
    s32 unk58;
    s32 unk5C;
    s32 unk60;
    s32 unk64;
};

void func_1519F48C();
void func_151A0928();

void func_1519F400(struct Obj1519F400 *arg0) {
    s32 *p;
    p = (s32 *)((u8 *)arg0 + 0x58);
    if (p[0] != 0) {
        func_1519F48C(p[0]);
    }
    if (p[2] != 0) {
        func_1519F48C(p[2]);
    }
    if (p[1] != 0) {
        func_151A0928(p[1]);
        func_1516972C((struct102 *)p[1]);
    }
    if (p[3] != 0) {
        func_151A0928(p[3]);
        func_1516972C((struct102 *)p[3]);
    }
}

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

void func_1519F48C(void);

struct Sub151A0950 {
    u8 pad0[0x18];
    s32 unk18;
    u8 unk1C;
};

struct Obj151A0950 {
    u8 pad0[0x98];
    struct Sub151A0950 **unk98;
};

struct Arg151A0950 {
    s32 unk0;
    u8 unk4;
};

void func_151A0950(struct Obj151A0950 *arg0, struct Arg151A0950 *arg1, u8 arg2) {
    struct Sub151A0950 *v0;
    struct Sub151A0950 **pp = arg0->unk98;
    s32 temp;
    if (arg2 == 10) {
        v0 = *pp;
        if (v0 != 0) {
            temp = v0->unk18;
            if (arg1->unk0 == temp || arg1->unk4 == v0->unk1C) {
                func_1519F48C();
            }
        }
    }
}

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

struct Obj151A0A10 {
    u8 pad0[0x14];
    f32 unk14;
    u8 pad18[0x1C - 0x18];
    f32 unk1C;
    u8 pad20[0x180 - 0x20];
    f32 unk180;
    s32 unk184;
};

struct Payload151A0A10 {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    u8 unkC;
    u8 padD[0x10 - 0xD];
    f32 unk10;
};

void func_151A0A10(struct Obj151A0A10 *arg0, s32 arg1, u8 arg2, s32 arg3) {
    struct260 *temp_v0;
    struct Payload151A0A10 sp38;

    if (arg0 != NULL) {
        sp38.unk0 = arg0->unk14;
        sp38.unk8 = arg0->unk1C;
        if (D_800C35EA != 1) {
            sp38.unk4 = arg0->unk180;
            sp38.unk10 = 0.0f;
            switch (func_1510F8CC(arg0->unk184)) {
            case 10:
                sp38.unkC = 0;
                break;
            case 15:
            case 17:
                sp38.unkC = 1;
                break;
            default:
                sp38.unkC = 0;
                break;
            }
            temp_v0 = func_151491F4((s16)arg1, -1, 1, 1, 0, 0x14, (u8)arg2, arg3);
            if (temp_v0 != NULL) {
                memcpy((u8 *)temp_v0 + 0x28, &sp38, 0x14);
            }
        }
    }
}

extern f32 D_800A8D10;
extern f32 D_800BE9A4;
extern f32 func_150ADA68(void);
void func_1514C678(f32, f32, s32, f32, s32, s32, s32, s32, s32, f32, s32, s32);

struct Sub151A0AF8 {
    f32 unk0;
    f32 unk4;
    s32 unk8;
    u8 unkC;
    u8 padD[0x10 - 0xD];
    f32 unk10;
};

struct Obj151A0AF8 {
    u8 pad0[0xC];
    u8 unkC;
    u8 padD[0x28 - 0xD];
    struct Sub151A0AF8 unk28;
};

void func_151A0AF8(struct Obj151A0AF8 *arg0) {
    struct Sub151A0AF8 *p;
    arg0->unk28.unk10 += D_800A8D10 * D_800BE9A4;
    if (1.0f < arg0->unk28.unk10) {
        p = &arg0->unk28;
        do {
            func_1514C678(p->unk0, p->unk4, p->unk8,
                          func_150ADA68() * 25.0f + 15.0f,
                          0, 0xFF, 5, 4, p->unkC, 0.0f, 0, arg0->unkC);
            p->unk10 -= 1.0f;
        } while (1.0f < p->unk10);
    }
}


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

struct Src151A1EE8 {
    u8 unk0;
    u8 unk1;
    u8 pad2[0xA];
    u8 unkC;
    u8 padD[0x1B];
    s32 unk28;
    s32 unk2C;
    s32 unk30;
    f32 unk34;
    f32 unk38;
    s16 unk3C;
    s16 unk3E;
    s16 unk40;
    s16 unk42;
    s16 unk44;
    s16 unk46;
    s16 unk48;
};

struct Blk3151A1EE8 {
    s32 a;
    s32 b;
    s32 c;
};

struct Dst151A1EE8 {
    struct Blk3151A1EE8 unk0;
    f32 unkC;
    f32 unk10;
    f32 unk14;
    union {
        struct {
            s16 unk18;
            s16 unk1A;
            s16 unk1C;
            s16 unk1E;
        } s;
        f64 _align;
    } u18;
    s16 unk20;
    s16 unk22;
};

void func_151A1EE8(struct Src151A1EE8 *arg0) {
    struct Dst151A1EE8 sp38;
    struct260 *temp_v0;

    sp38.unk0 = *(struct Blk3151A1EE8 *)&arg0->unk28;
    sp38.unkC = arg0->unk34;
    sp38.unk10 = 0.0f;
    sp38.unk14 = arg0->unk38;
    sp38.u18.s.unk18 = arg0->unk3E;
    sp38.u18.s.unk1A = arg0->unk40;
    sp38.u18.s.unk1C = arg0->unk42;
    sp38.u18.s.unk1E = arg0->unk44;
    sp38.unk20 = arg0->unk46;
    sp38.unk22 = arg0->unk48;

    temp_v0 = func_151491F4(arg0->unk3C, -1, 4, 1, 0, 0x24, arg0->unkC, arg0->unk1);
    if (temp_v0 != NULL) {
        memcpy((u8 *)temp_v0 + 0x28, &sp38, 0x24);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1CC440/func_151A1FB4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1CC440/func_151A24A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1CC440/func_151A25E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1CC440/func_151A26EC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1CC440/func_151A2960.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1CC440/func_151A2A14.s")

void func_151A2C24(s32, s32, s32, s32, f32, f32, f32, s32, f32, f32, f32, f32, s16, s16, s16, s16, s16, s16, s8, u8, s32, s32);

void func_151A2AD4(s32 a0, s32 a1, f32 a2, f32 a3, s32 p4, f32 p5, f32 p6, f32 p7, f32 p8, s16 p9, s16 p10, s16 p11, s16 p12, s16 p13, s16 p14, s8 p15, u8 p16, s32 p17) {
    func_151A2C24(a0, a1, 0, 0, 0.0f, a2, a3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15, p16, p17, 0);
}

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
