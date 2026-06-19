#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_1A5440/func_15177F90.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1A5440/func_15178268.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1A5440/func_15178750.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1A5440/func_151787AC.s")

typedef struct Node15178B98 {
    char pad0[0x8];
    struct Node15178B98 *unk8;
    char padC[0x4];
    s32 unk10;
    s32 unk14;
    char pad18[0x18];
    s16 unk30;
    char pad32[0x2];
    u8 unk34;
} Node15178B98;

extern Node15178B98 *D_800DCF38;

Node15178B98 *func_15178B98(u8 arg0) {
    Node15178B98 *node;

    for (node = D_800DCF38; node != NULL; node = node->unk8) {
        if (node->unk34 == arg0) {
            return node;
        }
    }
    return NULL;
}

Node15178B98 *func_15178BE4(u8 arg0, s32 arg1, s16 arg2) {
    Node15178B98 *node;

    node = func_15178B98(arg0);
    if (node != NULL) {
        node->unk10 = arg1;
        node->unk14 = 0x80000000;
        node->unk30 = arg2;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1A5440/func_15178C34.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1A5440/func_15178C9C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1A5440/func_15178DA4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1A5440/func_15178E14.s")
