#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_1FFB70/func_151D26C0.s")

struct SomeNode {
    char pad0[0x8];
    struct SomeNode *unk8;
    char padC[0x4];
    s16 unk10;
    char pad12[0x4];
    s8 unk16;
};

extern struct SomeNode *D_800DD0E0;

void func_151D2718(s16 arg0) {
    struct SomeNode *node;

    for (node = D_800DD0E0; node != NULL; node = node->unk8) {
        if (arg0 == node->unk10) {
            node->unk16 = -2;
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1FFB70/func_151D275C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1FFB70/func_151D2830.s")
