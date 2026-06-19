#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_1B5CC0/func_15188810.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1B5CC0/func_1518894C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1B5CC0/func_15188A58.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/game_1B5CC0/func_15188AD0.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/game_1B5CC0/func_151898C0.s")
