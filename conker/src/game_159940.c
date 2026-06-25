#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_159940/func_1512C490.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_159940/func_1512D070.s")

extern s32 D_800DC280[];
extern s32 D_800DC290[];
s32 func_1502B5C8(s32 *, s32, s32, s32);

typedef struct Game159940Object {
    char pad_0[0x84D];
    u8 field_0x84D;
    u8 field_0x84E;
    char pad_0x84F[0x1];
    s32 field_0x850;
} Game159940Object;

void func_1512D238(void) {
    u32 sp3C;
    s32 i;

    for (i = 0; i < 4; i++) {
        D_800DC280[i] = func_1502B5C8((s32 *)&sp3C, 2, 0x1B, i);
        D_800DC290[i] = sp3C / 0x18;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_159940/func_1512D2E4.s")

void func_1512D2F8(Game159940Object *arg0) {
    u8 temp;

    switch (arg0->field_0x84D) {
    case 1:
        arg0->field_0x84E = 0;
        arg0->field_0x84D = 2;
        break;
    case 2:
        temp = arg0->field_0x84E + D_800BE9E4;
        arg0->field_0x84E = temp;
        if ((s32)(temp & 0xFF) >= D_800DC290[arg0->field_0x850]) {
            arg0->field_0x84D = 0;
        }
        break;
    }
}

void func_1512D368(s32 arg0) {
    arg0 = arg0;
}
