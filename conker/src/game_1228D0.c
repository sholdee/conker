#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_1228D0/func_150F5420.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1228D0/func_150F5590.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1228D0/func_150F55C8.s")

void func_15179008(s32);

void func_150F568C(s32 arg0) {
    func_15179008(0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1228D0/func_150F56B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1228D0/func_150F5A54.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1228D0/func_150F5C08.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1228D0/func_150F5C98.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1228D0/func_150F6138.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1228D0/func_150F6178.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1228D0/func_150F631C.s")

void func_150F631C(struct260 *arg0);

void func_150F6368(struct260 *arg0) {
    func_150F631C(arg0);
    func_1514933C(arg0);
}

void func_15149368(struct260 *arg0);

void func_150F6394(struct260 *arg0) {
    func_150F631C(arg0);
    func_15149368(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1228D0/func_150F63C0.s")

struct Sub150F6400 {
    s32 pad[2];
    s32 unk8;
};

void func_150F6400(u8 *arg0) {
    struct Sub150F6400 *p;

    if (*(s32 *)(arg0 + 0x160) != 0) {
        p = (struct Sub150F6400 *)(*(u8 **)(arg0 + 0x160) + 0x28);
        p->unk8 = 0;
    }
}

void func_150F6420(u8 *arg0) {
    func_150F6400(arg0);
    func_1513CA6C((struct210 *)arg0);
}

void func_150F644C(u8 *arg0) {
    func_150F6400(arg0);
    func_1513CAA0((struct210 *)arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1228D0/func_150F6478.s")

void func_150F6478(struct210 *);

void func_150F6484(struct210 *arg0) {
    func_150F6478(arg0);
    func_151411A4(arg0);
}

void func_151411C4(struct210 *);

void func_150F64B0(struct210 *arg0) {
    func_150F6478(arg0);
    func_151411C4(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1228D0/func_150F64DC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1228D0/func_150F6850.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1228D0/func_150F6890.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1228D0/func_150F695C.s")
