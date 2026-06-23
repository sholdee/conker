#include <ultra64.h>
#include "functions.h"
#include "variables.h"

typedef struct {
    s32 unk0;
    s32 unk4;
    u8 unk8;
    u8 unk9;
    u16 unkA;
} Elem15024130;

extern Elem15024130 *D_800C3D50;
extern void func_1502A8A0(s32, u8, u16, s32, s32);


void func_150238D0(void) {
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_50D80/func_150238D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_50D80/func_15023BB0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_50D80/func_15023DE0.s")

void func_15024130(s32 arg0, s32 arg1) {
    s32 i;
    s32 off;
    Elem15024130 *e;

    i = 0;
    if (arg0 > 0) {
        off = 0; do {
            e = (Elem15024130 *)((u8 *)D_800C3D50 + off);
            func_1502A8A0(e->unk0, e->unk8, e->unkA, e->unk4, arg1);
            i++;
            off += 0xC;
        } while (i != arg0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_50D80/func_150241B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_50D80/func_150242F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_50D80/func_1502460C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_50D80/func_150265CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_50D80/func_15029BB8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_50D80/func_1502A8A0.s")
