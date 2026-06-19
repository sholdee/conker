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

Node15178B98 *func_15178C34(u8 arg0, s32 arg1, s32 arg2, s32 arg3, s16 arg4) {
    Node15178B98 *node;

    node = func_15178B98(arg0);
    if (node != NULL) {
        node->unk10 = (arg1 << 16) | (arg2 & 0xFFFF);
        node->unk14 = arg3 << 16;
        node->unk30 = arg4;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1A5440/func_15178C9C.s")

typedef struct Node15178DA4 {
    char pad0[0x8];
    struct Node15178DA4 *unk8;
    char padC[0x8];
    struct Node15178DA4 *unk14;
    char pad18[0x16];
    u16 unk2E;
} Node15178DA4;

extern Node15178DA4 *D_800DCF3C;

void func_15178DA4(Node15178DA4 *arg0) {
    Node15178DA4 *next;
    Node15178DA4 *node;

    node = D_800DCF3C;
    func_100111C8(arg0->unk2E);
    if (node != NULL) {
        do {
            next = node->unk8;
            if (arg0 == node->unk14) {
                func_1516972C((struct102 *)node);
            }
            node = next;
        } while (next != NULL);
    }
    func_15169824((struct102 *)arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1A5440/func_15178E14.s")
