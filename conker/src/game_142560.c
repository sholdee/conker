#include <ultra64.h>
#define func_15048A40 func_15048A40_void_unused
#include "functions.h"
#undef func_15048A40
#include "variables.h"
extern f32 func_15048A40(u8);


#pragma GLOBAL_ASM("asm/nonmatchings/game_142560/func_151150B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_142560/func_151150BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_142560/func_1511515C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_142560/func_151151FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_142560/func_1511529C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_142560/func_151152A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_142560/func_15115368.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_142560/func_151155C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_142560/func_1511575C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_142560/func_15115E0C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_142560/func_15115EDC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_142560/func_15115F68.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_142560/func_15116058.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_142560/func_15116110.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_142560/func_1511617C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_142560/func_151162D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_142560/func_151163C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_142560/func_1511650C.s")

struct Obj15116888 {
    u8 pad0[0x14];
    f32 unk14;
    u8 pad18[0x4];
    f32 unk1C;
    u8 pad20[0x1C];
    f32 unk3C;
    u8 pad40[0x36];
    u16 unk76;
};

struct Vec15116888 {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    u8 padC[0x4];
};

s32 func_150490A8(struct17 *arg0);

s32 func_15116888(s32 arg0, s32 arg1, s32 arg2, struct Obj15116888 *arg3) {
    s32 a;
    s32 b;
    s32 c;
    s32 d;
    f32 r;
    struct Vec15116888 sp1C;

    a = (s32)arg3->unk14;
    b = (s32)arg3->unk1C;
    sp1C.unk0 = (f32)(a - arg0);
    sp1C.unk8 = (f32)(b - arg1);

    c = func_150490A8((struct17 *)&sp1C);
    d = (s32)arg3->unk76 >> 8;
    d = 0x40 - d;
    d = d - c;
    r = func_15048A40((u8)d);
    r = arg3->unk3C * r;
    return (s32)r;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_142560/func_15116924.s")

void func_15116930(u8 *arg0, u8 *arg1) {
    s32 temp;
    if (arg0[0x4F] & 0x4) {
        if (!(arg0[0x73] & 0x3) && !(arg0[0x73] & 0x4)) {
            if (((u8 **)arg1)[0x31C / 4][0x57] == 1) {
                arg0[0x73] &= 0xFFFC;
                arg0[0x73] |= 0x2;
            }
        }
    }
}

extern void func_151169B4(u8 *arg0);

void func_15116984(u8 *arg0) {
    if (arg0[0x73] & 0x2) {
        func_151169B4(arg0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_142560/func_151169B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_142560/func_15116BAC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_142560/func_15116D7C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_142560/func_15116EA4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_142560/func_151172D8.s")

struct Obj151174A0 {
    char pad0[0x8];
    f32 unk8;
};

extern f32 func_151172D8(struct Obj151174A0 *, f32);

void func_151174A0(struct Obj151174A0 *arg0) {
    arg0->unk8 = func_151172D8(arg0, arg0->unk8);
}

struct Obj151174C8 {
    char pad0[0x4];
    f32 unk4;
};

void func_151174C8(struct Obj151174C8 *arg0) {
    arg0->unk4 = func_151172D8((struct Obj151174A0 *)arg0, arg0->unk4);
}

struct Obj151174F0 {
    f32 unk0;
};

void func_151174F0(struct Obj151174F0 *arg0) {
    arg0->unk0 = func_151172D8((struct Obj151174A0 *)arg0, arg0->unk0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_142560/func_15117518.s")

extern f32 func_15117518(struct Obj151174F0 *, f32);

void func_15117770(struct Obj151174F0 *arg0) {
    arg0->unk0 = func_15117518(arg0, arg0->unk0);
}

struct Obj15117798 {
    f32 unk0;
    f32 unk4;
    f32 unk8;
};

void func_15117798(struct Obj15117798 *arg0) {
    arg0->unk8 = func_15117518((struct Obj151174F0 *)arg0, arg0->unk8);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_142560/func_151177C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_142560/func_151179BC.s")

void func_15117D3C(u8 *arg0, u8 *arg1) {
    s32 temp = *(s32 *)(arg0 + 0x3C) & 0xFFFF;
    if (((s32 *)arg1)[0] == 1) {
        if (arg0[0x4F] & 0x4) {
            if (!(arg0[0x73] & 0x3) && !(arg0[0x73] & 0x4)) {
                if (temp == 0 || ((u8 **)arg1)[0x31C / 4][0x57] == 1) {
                    arg0[0x73] &= 0xFFFC;
                    arg0[0x73] |= 0x2;
                }
            }
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_142560/func_15117DA4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_142560/func_15117F3C.s")

s32 func_151189AC(void *arg0, s32 arg1);

s32 func_1511896C(void *arg0) {
    return func_151189AC(arg0, 0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_142560/func_1511898C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_142560/func_151189AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_142560/func_15118F24.s")

struct Obj151193AC_0 {
    char pad0[0x73];
    u8 unk73;
};

struct Obj151193AC_1 {
    s32 unk0;
    char pad4[0x61];
    u8 unk65;
};

void func_151193AC(struct Obj151193AC_0 *arg0, struct Obj151193AC_1 *arg1) {
    if (arg1->unk0 == 1) {
        if (arg1->unk65 == 0) {
            if (!(arg0->unk73 & 0x3) && !(arg0->unk73 & 0x4)) {
                arg0->unk73 &= 0xFFFC;
                arg0->unk73 |= 0x2;
            }
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_142560/func_151193F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_142560/func_151194D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_142560/func_151196D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_142560/func_15119938.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_142560/func_15119FC0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_142560/func_1511A410.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_142560/func_1511A494.s")

extern void func_15116110(void *);
extern void func_1511A494(void *, void *, void *);

void func_1511A6FC(s32 *arg0) {
    if (arg0[0xF] != 0) {
        func_15116110(arg0);
    }
    func_1511A494(arg0, (u8 *)arg0 + 0x80, (u8 *)arg0 + 0x84);
}

extern u8 D_800C35EA;
extern struct131 *D_800DBEF4;
extern s32 func_15022B08(s32, s32);
extern void func_151162D4(void *);

void func_1511A738(struct131 *arg0) {
    if (D_800C35EA == 1) {
        if (func_15022B08(arg0 - D_800DBEF4, 0) != 0) {
            *(s32 *)((u8 *)arg0 + 0x7C) = 0;
            *(f32 *)((u8 *)arg0 + 0x18) = 0.0f;
        }
    }
    func_151162D4(arg0);
    func_1511A494(arg0, (u8 *)arg0 + 0x80, (u8 *)arg0 + 0x84);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_142560/func_1511A7C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_142560/func_1511A838.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_142560/func_1511AF30.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_142560/func_1511B07C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_142560/func_1511B51C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_142560/func_1511B7D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_142560/func_1511BA24.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_142560/func_1511BB04.s")

struct Obj1511BDF4 {
    u8  pad0[0x3F];
    u8  unk3F;
    u8  pad40[0x40];
    struct127 *unk80;
};

extern void func_1511BB04(struct Obj1511BDF4 *, f32, f32, f32, f32);

void func_1511BDF4(struct Obj1511BDF4 *arg0) {
    struct127 *temp;
    struct127 *sp;

    temp = arg0->unk80;
    if (temp != 0) {
        sp = temp;
    } else {
        sp = func_15083E90(arg0->unk3F);
    }
    if (sp != 0) {
        func_1511BB04(arg0, sp->x_position, sp->z_position, 1.0f, 1.0f);
    }
}

struct Obj1511BE5C {
    u8  pad0[0x4];
    f32 unk4;
    u8  pad8[0x8];
    s16 unk10;
    s16 unk12;
    s16 unk14;
};

extern f32 D_800A31E0;

void func_1511BE5C(struct Obj1511BE5C *arg0) {
    arg0->unk4 = func_150484A0((f32)arg0->unk10 - D_800DBFF0->unk2F8, (f32)arg0->unk14 - D_800DBFF0->unk300) * D_800A31E0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_142560/func_1511BEBC.s")

void func_1511C540(void) {
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_142560/func_1511C548.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_142560/func_1511C638.s")

extern f32 D_800A31F4;

void func_1511CB2C(s32 arg0, f32 *arg1) {
    *arg1 = D_800A31F4;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_142560/func_1511CB44.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_142560/func_1511D394.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_142560/func_1511D7BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_142560/func_1511D9E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_142560/func_1511DBC4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_142560/func_1511DD98.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_142560/func_1511DF6C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_142560/func_1511E780.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_142560/func_1511EC50.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_142560/func_1511ED84.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_142560/func_1511EF40.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_142560/func_1511F31C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_142560/func_1511F3E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_142560/func_1511F4D0.s")

void func_1511F768(s32 *arg0, s32 arg1) {
    if (arg0[0x20] == 0) {
        arg0[0x20] = 1;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_142560/func_1511F788.s")

extern s32 func_151149AC(u32);

void func_1511F92C(s16 *arg0) {
    s16 *temp_v0;

    temp_v0 = (s16 *)func_151149AC(*(u8 *)((u8 *)arg0 + 0x3F));
    if (temp_v0 != NULL) {
        arg0[8] = temp_v0[8];
        arg0[9] = temp_v0[9];
        arg0[0xA] = temp_v0[0xA];
    }
}
