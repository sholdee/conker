#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_6B320/func_1503DE70.s")

void func_1503DF0C(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    D_800C6660[arg0].unk4 |= arg2;
    D_800C6660[arg0].unk8 |= arg3;
    D_800C6660[arg0].pad[2] = arg1;
    D_800C6660[arg0].unkF = 2;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_6B320/func_1503DF48.s")

struct e1f4_s { s32 f; s8 pad[12]; };
extern struct e1f4_s D_800C6664[];
extern struct e1f4_s D_800C6668[];

s32 func_1503E1F4(s32 arg0, s32 arg1) {
    if (arg0 < 0x20) {
        if (D_800C6664[arg1].f & (1 << arg0)) {
            return 1;
        }
    } else {
        if (D_800C6668[arg1].f & (1 << arg0)) {
            return 1;
        }
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_6B320/func_1503E260.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_6B320/func_1503E3C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_6B320/func_1503E5F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_6B320/func_1503E82C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_6B320/func_1503EA54.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_6B320/func_1503EB78.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_6B320/func_1503ECA0.s")

void func_1503EEB8(void) {
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_6B320/func_1503EEC0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_6B320/func_1503EF4C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_6B320/func_1503EFC4.s")

extern void func_1503EB78(void *arg0, f32 arg1, f32 arg2, s32 arg3);

void func_1503F078(void *arg0, s32 arg1) {
    func_1503EB78(arg0, 2.0f, 2.0f, 0);
}

extern void func_1503EB78(void *arg0, f32 arg1, f32 arg2, s32 arg3);

void func_1503F0AC(void *arg0, s32 arg1) {
    func_1503EB78(arg0, 1.0f, 2.0f, 1);
}

void func_1503F0D8(void *arg0, s32 arg1) {
    func_1503EB78(arg0, 2.06f, 3.0f, 1);
}

extern s8 D_800CC364[];

void func_1503F108(s32 arg0) {
    struct106 *p = &D_800C6660[arg0];
    (*(s16 *)((s32)p + 0xC)) = 0x8C;
    *(s32 *)&D_800CC364[arg0 * 812] = 6;
    *(f32 *)(p->unk0 + 0x1EC) = 10.0f;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_6B320/func_1503F16C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_6B320/func_1503F2B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_6B320/func_1503F404.s")
