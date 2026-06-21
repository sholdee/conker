#include <ultra64.h>

#include "functions.h"
#include "variables.h"

extern s32 func_15084D70(s32, s32, s32, s16*, f32*, u8*, u8*, s32*, s32*, s32, s32*);
extern void func_15022190(s16, s16, s16, f32);
extern void func_1501D348(s32, s32, s32, s32, s32);


void func_1507C8E0(struct127 *arg0, s32 arg1) {
    arg0->unk31C->unk120 = (u8)2;
    arg0->unk31C->unk124 = arg1;
}

// "goto" hell
#pragma GLOBAL_ASM("asm/nonmatchings/game_A9D90/func_1507C8FC.s")

void func_1507CD0C(struct127 *arg0) {
    s32 temp_lo = ((s32)arg0 - (s32)&D_800CC2D0) / (s32)sizeof(struct127);

    arg0->unk31C->unk120 = 3;

    if (temp_lo <= D_80082FA0) {
        func_15181D70(temp_lo);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_A9D90/func_1507CD64.s")
void func_1509BFB0(s32 num, s32, s32, ...);
extern struct127 D_800CC40F[];

void func_1507D158(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 temp = *(u8*)&D_800CC40F[arg0];
    func_1509BFB0(3, temp | 0x2000, arg1, arg2, arg3, arg4);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_A9D90/func_1507D1D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_A9D90/func_1507D4F8.s")
// NON-MATCHING: pretty far away!
// void func_1507D4F8(s16 arg0) { // struct126 *
//     // ?32 sp24;
//     struct127 *temp_a0;
//
//     if ((D_8008FDBC & 1) == 0) {
//         func_15085710(arg0, 4, 1);
//     }
//     // sp24 = (?32) arg0;
//     if (func_150859AC(arg0, 3) != 0) {
//         func_15085710(arg0, 5, D_8008726C); //temp_ret =
//         temp_a0 = &D_800CC2D0[arg0];
//         temp_a0->unkB2 = (u16)0;
//         if (D_800BE616 == 0) {
//             D_800D18A8 = (u8)1;
//             if (((D_800D2E4C->unk19 & 4) != 0) || (D_8008FDA8 < 0)) {
//                 func_1501C730(2, D_800BE3DF, D_800BE3E0, 0, 0);
//                 return;
//             }
//             func_1501C730(1, 0x22, 0, 0, 0);
//             return;
//         }
//         if (D_800E0C20 != 0) {
//             temp_a0->unk31C->unk120 = (u8)0xA;
//             return; // temp_ret;
//         }
//         func_1507D1D8(temp_a0);
//         return;
//     }
//     if (D_800BE616 == 0) {
//         D_800D2E43 = (u8)1;
//         func_1509C3A0();
//         D_800D18A8 = (u8)1;
//         func_15085710(arg0, 5, D_8008726C);
//         func_15085710(arg0, 2, D_80087260);
//         func_1501C730(1, 0x18, 0, 0, 0);
//     } else {
//         D_800D18A0 = (u16) (D_800D18A0 | (1 << (s32) arg0));
//     }
//     // temp_a0 = &D_800CC2D0[arg0];
//     if (temp_a0->unk31C->unk84 == 0) {
//         D_8008FD94 -= 1; //(s8) (D_8008FD94 - 1);
//     }
//     temp_a0->unk31C->unk120 = (u8)0xA;
//     D_800BE618 -= 1; //(s8) (D_800BE618 - 1);
//     //return temp_a0_2->unk31C;
// }

#pragma GLOBAL_ASM("asm/nonmatchings/game_A9D90/func_1507D754.s")

void func_1507DB44(s32 arg0, s32 arg1) {
    func_1503DE70(arg0, arg1, -1);
}

void func_1507DB64(void) {
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_A9D90/func_1507DB6C.s")

void func_1507DE4C(struct127 *arg0) {

    if (arg0->interaction_state == 1) {
        func_150836CC(arg0, 0x44);
        func_150836CC(arg0, 0x23);
        arg0->unk9C |= 0xF000;
        func_150836CC(arg0, 0x44);
        func_150836CC(arg0, 0x23);
        return;
    }

    switch(arg0->id) {
        case 0x9F:
        case 0xa0:
            arg0->unk9C |= 0xF000;
            break;
        case 0x5A:
        case 0x74:
        case 0x7A:
            arg0->unk9C |= 0xFF8;
            break;
    }
}


#pragma GLOBAL_ASM("asm/nonmatchings/game_A9D90/func_1507DF10.s")
void func_1507DFE4(s32 arg0, s32 arg1) {
    s32 temp;
    s16 sp5C[3];
    f32 sp50[3];
    u8 sp4F;
    u8 sp4E;
    s32 sp48;
    s32 sp44;
    f32 temp_f0;
    s32 sp3C;
    s32 sp38;

    if (D_800C35EA != 1) {
        func_15084D70(0, arg0, 1, sp5C, sp50, &sp4F, &sp4E, &sp44, &sp48, 1, &sp38);
        temp_f0 = ((f32)(sp4E - 0x40) * 1.40625f) + 180.0f;
        if (sp38 == 0) {
            sp3C = 1;
        } else if (sp38 == 1) {
            sp3C = 3;
        } else {
            return;
        }
        func_15022190(sp5C[0], sp5C[1], sp5C[2], temp_f0);
        temp = D_800BE9F0;
        D_800BE9F0 = 0x25;
        D_800C3671 = 1;
        func_1501D348(0x25, sp3C, 0, 0, 0);
        D_800C3670 = 1;
        D_800BE9F0 = temp;
    }
}
extern s32 func_15084D70(s32, s32, s32, s16*, f32*, u8*, u8*, s32*, s32*, s32, s32*);


s32 func_1507E114(s32 arg0) {
    s32 sp5C;
    s16 sp54[3];
    f32 sp48[3];
    s32 sp44;
    u8 sp43;
    u8 sp42;
    s32 sp3C;
    s32 temp;

    if (D_800D18A8 == 0) {
        return 0;
    }
    temp = (s32)D_800BE9F4;
    if (temp == 0x22 || temp == 0x18) {
        return 0;
    }
    *(s32*)&D_800BE9F4 = (s8)D_800BE3DF;
    func_15084D70(0, (u8)D_800BE3E0, 1, sp54, sp48, &sp43, &sp42, &sp44, &sp3C, 1, &sp5C);
    return sp5C + 1;
}
#pragma GLOBAL_ASM("asm/nonmatchings/game_A9D90/func_1507E1D0.s")
