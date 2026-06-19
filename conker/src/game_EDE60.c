#include <ultra64.h>
#include "functions.h"
#include "variables.h"


void func_150C09B0(s32 arg0, s32 arg1, s32 arg2) {
    func_15169850(arg1, (u8)arg2, arg0 + 0x20, arg0 + 0x24, arg0);
}

extern void func_150C0A48(struct102 *);

void func_150C09F0(struct102 *arg0) {
    func_150C0A48(arg0);
    func_15169804(arg0);
}

extern void func_15169824(struct102 *);

void func_150C0A1C(struct102 *arg0) {
    func_150C0A48(arg0);
    func_15169824(arg0);
}

struct sub150C0A48 {
    struct102 *unk0;
    s16        unk4;
};

struct s150C0A48 {
    u8 pad0[0x40];
    struct sub150C0A48 *unk40;
    s16 unk44;
};

void func_150C0A48(struct102 *arg0x) {
    struct s150C0A48 *arg0 = (struct s150C0A48 *)arg0x;
    s16 i;

    i = arg0->unk44;
    while (i != -1) {
        func_1516972C(arg0->unk40[i].unk0);
        i = arg0->unk40[i].unk4;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_EDE60/func_150C0AC0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_EDE60/func_150C0C38.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_EDE60/func_150C1198.s")
