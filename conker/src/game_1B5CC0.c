#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_1B5CC0/func_15188810.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1B5CC0/func_1518894C.s")

typedef struct Node15188A58 {
    char pad0[12];
    struct Node15188A58 *unkC;
} Node15188A58;

void func_15188A58(Node15188A58 *arg0, Node15188A58 **arg1) {
    Node15188A58 *node;

    arg0->unkC = 0;
    if (*arg1 != 0) {
        node = *arg1;
        while (node->unkC != 0) {
            node = node->unkC;
        }
        node->unkC = arg0;
    } else {
        *arg1 = arg0;
    }
}

typedef struct Node15188A9C {
    char pad0[6];
    s16 unk6;
    char pad8[4];
    struct Node15188A9C *unkC;
    s32 unk10;
} Node15188A9C;

void func_15188A9C(s32 arg0) {
    Node15188A9C *node;

    node = (Node15188A9C *)D_800DF7C8[0];
    while (node != 0) {
        if (arg0 == node->unk10) {
            node->unk6 = 0;
        }
        node = node->unkC;
    }
}

typedef struct Node15188AD0 {
    char pad0[8];
    s32 *unk8;
    struct Node15188AD0 *unkC;
    s32 unk10;
} Node15188AD0;

extern void func_10004074(Node15188AD0 *arg0);

void func_15188AD0(s32 arg0) {
    Node15188AD0 *node;
    Node15188AD0 *prev;
    Node15188AD0 *next;

    prev = 0;
    node = (Node15188AD0 *)D_800DF7C8[0];
    while (node != 0) {
        next = node->unkC;
        if (arg0 == node->unk10) {
            if (prev == 0) {
                D_800DF7C8[0] = (s32)next;
            } else {
                prev->unkC = next;
            }
            func_100043B4(node->unk8, 2);
            func_10004074(node);
        } else {
            prev = node;
        }
        node = next;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1B5CC0/func_15188B74.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1B5CC0/func_15188D00.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1B5CC0/func_15188E48.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1B5CC0/func_15188F84.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1B5CC0/func_15189118.s")

void func_151895A4(s32 *arg0) {
    func_100043B4((s32 *)arg0[2], 2);
}

void func_151895CC(s32 *arg0) {
    func_100043B4((s32 *)arg0[2], 2);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1B5CC0/func_151895F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1B5CC0/func_151897A4.s")

typedef struct Node151898C0 {
    char pad0[12];
    struct Node151898C0 *unkC;
    s32 unk10;
    s32 unk14;
} Node151898C0;

void func_151898C0(s32 arg0, s32 arg1) {
    Node151898C0 *node;

    node = (Node151898C0 *)D_800DF7C8[0];
    while (node != 0) {
        if (arg0 == node->unk10) {
            node->unk14 = arg1;
            return;
        }
        node = node->unkC;
    }
}
