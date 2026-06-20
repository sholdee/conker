#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_1C1150/func_15193CA0.s")

extern void func_15193CA0(s32, s32, s32, s32);

void func_151942B0(s32 arg0, s32 arg1, s32 arg2) {
    func_15193CA0(arg1, 0, 0xFF, 1);
}

void func_151942E8(s32 arg0, s32 arg1, s32 arg2) {
    func_15193CA0(arg1, 1, 0xFF, 1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C1150/func_15194320.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C1150/func_15194394.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C1150/func_15194408.s")

extern void func_150C7020(s32, s32, s32, s32);
extern void func_15194408(s32, s32);

void func_15194588(s32 arg0, s32 arg1, s32 arg2) {
    func_150C7020(arg0, 0x1F4, 0xFF, 1);
    func_15194408(arg0, arg1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C1150/func_151945CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C1150/func_15194794.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C1150/func_15194810.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C1150/func_151949E0.s")

extern void func_15104170(s32);

void func_151949F4(arg0, arg1) s32 arg0; struct127 *arg1; {
    if (D_8008FD90 == 1) {
        if (arg1->unk127 == 0) {
            if (D_800E9D00 & 0x8) {
                if (arg1->unk31C->unk1A0 == 0) {
                    func_15104170(arg0);
                    arg1->unk31C->unk1A0 = 0x4B0;
                }
            }
        }
    }
}

extern void func_1507DE4C(s32);
extern void func_15138BC0(s32, s32, s32);

void func_15194A68(s32 arg0, s32 arg1, s32 arg2) {
    func_1507DE4C(arg1);
    func_15138BC0(arg1, 0xFF, 1);
    func_151949F4(0, arg0, arg1);
}

void func_15194AB4(struct127* arg0) {
    s32 sp_a1;

    arg0->unk9C |= 0xFFFE;
    sp_a1 = -1;
    switch (arg0->id) {
    case 0x75:
        sp_a1 = 0x73;
        break;
    case 0x80:
        sp_a1 = 0x72;
        break;
    }
    if (sp_a1 != -1) {
        func_15083568(arg0, sp_a1, 1.0f, 0);
    }
}

extern s32 func_15134070(struct127*);
extern void func_15138120(struct127*, s32, s32);
extern void func_15136C3C(struct127*, s32, s32, s32, s32, s32, s32, s32);

void func_15194B1C(struct127* arg0) {
    s32 temp;

    temp = func_15134070(arg0);
    if (temp != 0x63) {
        func_15138120(arg0, temp, 0);
    }
    func_15136C3C(arg0, 1, 1, 1, 1, 1, 0xFF, 1);
    func_15194AB4(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C1150/func_15194B94.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C1150/func_15194BF0.s")

s32 func_15194FF4(s32, s32, s32, s32);

s32 func_15194D80(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    return func_15194FF4(arg0, arg1, 0, arg3);
}

s32 func_15194DA4(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    return func_15194FF4(arg0, arg1, 1, arg3);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C1150/func_15194DC8.s")

extern void func_150B06B0(s32, s32, s32, s32);

void func_15194E54(s32 arg0, s32 arg1, s32 arg2) {
    if ((*(u8 *)(arg1 + 4) == 0x3E) || (*(u8 *)(arg1 + 4) == 0xA6)) {
        func_150B06B0(arg1, arg0, 0xFF, 1);
    }
}

extern void func_15182670(s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_15194BF0(s32, struct127*, u8*);

void func_15194EA8(s32 arg0, struct127* arg1, s32 arg2) {
    u8 sp37;
    u32 temp1;
    u32 temp0;

    sp37 = 0;
    if (arg1->camera != 0) {
        temp0 = func_150ADA20();
        temp1 = func_150ADA20();
        func_15182670(0xFF, 0xFF, 0xFF, 0xFF, temp1 % 0xB + 0x23, arg1->camera->unk23D, 0xFF, 1);
        if (temp0) { }
    }
    func_15194BF0(arg0, arg1, &sp37);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C1150/func_15194F48.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C1150/func_15194FF4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C1150/func_151951E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C1150/func_15195528.s")

void func_151B01B8(s32, s32);
void func_151B09BC(s32, s32, s32, s32, s32);

void func_15195650(s32 arg0, s32 arg1, s32 arg2) {
    func_151B01B8(arg0, arg1);
    func_151B09BC(arg0, arg1, 0x3E8, 0xFF, 0);
}

extern void func_15145A50(struct127 *arg0);
extern void func_1507CD64(struct127 *arg0, s32 arg1);

void func_15195698(struct127 *arg0, struct127 *arg1, s32 arg2) {
    if (arg1->health == 0) {
        if (arg1->unk127 != 0xFF) {
            func_15136C3C(arg1, 1, 1, 1, 1, 0, 0xFF, 1);
            func_15145A50(arg1);
            func_1507CD64(arg1, 6);
        }
    }
    if (arg0->id == 0x47) {
        arg0->health = 0;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1C1150/func_15195738.s")
