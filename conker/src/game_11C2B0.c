#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_11C2B0/func_150EEE00.s")

void func_150EEF40(struct210 *arg0, u8 arg1) {
    s8 sp18[6];

    *(struct210 **)&sp18[0] = arg0;
    sp18[4] = *(u8 *)((s32)arg0 + 0x3B);
    sp18[5] = arg1;
    func_151403A8(&sp18, 0x43);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_11C2B0/func_150EEF80.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_11C2B0/func_150EF38C.s")

s32 func_150EF784(u8 *arg0, s32 arg1, s32 arg2) {
    if (arg0[4] == 0x28) {
        return 1;
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_11C2B0/func_150EF7B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_11C2B0/func_150EF860.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_11C2B0/func_150EF910.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_11C2B0/func_150EFA4C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_11C2B0/func_150EFB80.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_11C2B0/func_150EFEC8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_11C2B0/func_150F00EC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_11C2B0/func_150F0198.s")

struct func150F02A0_sub {
    u8 pad0[0x8];
    u8 *unk8;
    u8 unkC;
};
struct func150F02A0_arg {
    u8 pad0[0x60];
    struct func150F02A0_sub *unk60;
};

void func_150F02A0(struct func150F02A0_arg *arg0);

void func_150F0260(struct func150F02A0_arg *arg0) {
    func_150F02A0(arg0);
}

void func_150F0280(struct func150F02A0_arg *arg0) {
    func_150F02A0(arg0);
}

void func_150F02A0(struct func150F02A0_arg *arg0) {
    struct func150F02A0_sub *temp = arg0->unk60;
    u8 *base = temp->unk8;
    *(s32*)(base + temp->unkC * 4 + 0x12C) = 0;
}

void func_150F0318(struct260 *arg0);

void func_150F02C0(struct260 *arg0) {
    func_150F0318(arg0);
    func_1514933C(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_11C2B0/func_150F02EC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_11C2B0/func_150F0318.s")

void func_150F0380(struct210 *arg0);

void func_150F0328(struct210 *arg0) {
    func_150F0380(arg0);
    func_151411A4(arg0);
}

void func_151411C4(struct210 *arg0);

void func_150F0354(struct210 *arg0) {
    func_150F0380(arg0);
    func_151411C4(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_11C2B0/func_150F0380.s")

void func_150F03E8(struct210 *arg0);
void func_151617C4(struct210 *arg0);

void func_150F0390(struct210 *arg0) {
    func_150F03E8(arg0);
    func_151617C4(arg0);
}

void func_151617E4(struct210 *arg0);

void func_150F03BC(struct210 *arg0) {
    func_150F03E8(arg0);
    func_151617E4(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_11C2B0/func_150F03E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_11C2B0/func_150F03F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_11C2B0/func_150F07E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_11C2B0/func_150F088C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_11C2B0/func_150F0938.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_11C2B0/func_150F0A24.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_11C2B0/func_150F0BEC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_11C2B0/func_150F0E48.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_11C2B0/func_150F1020.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_11C2B0/func_150F10D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_11C2B0/func_150F1170.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_11C2B0/func_150F15F8.s")

struct func150F1684_sub {
    s32 unk0;
    u8 unk4;
};

void func_150F1684(struct func150F1684_sub *arg0, struct func150F1684_sub *arg1, u8 arg2) {
    struct func150F1684_sub *temp = (struct func150F1684_sub *)((s32)arg0 + 0x18);
    s32 word;

    if (arg2 == 0x43) {
        word = arg1->unk0;
        if ((temp->unk0 == word) || (arg1->unk4 == temp->unk4)) {
            func_1516972C((struct102 *)arg0);
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_11C2B0/func_150F16DC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_11C2B0/func_150F1A00.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_11C2B0/func_150F1B48.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_11C2B0/func_150F1CB0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_11C2B0/func_150F1D10.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_11C2B0/func_150F20F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_11C2B0/func_150F2230.s")
