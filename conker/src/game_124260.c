#include <ultra64.h>
#include "functions.h"
#include "variables.h"


void func_150F6DB0(s32 arg0) {
    struct {
        s32 unk0;
        u8 unk4;
    } sp18;

    sp18.unk0 = arg0;
    sp18.unk4 = *(u8 *)(arg0 + 0x3B);
    func_151494E0((s32)&sp18, 0x3E);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_124260/func_150F6DE4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_124260/func_150F706C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_124260/func_150F7310.s")

extern void func_1514EDF0(struct260 *, s32);

void func_150F739C(struct260 *arg0) {
    s32 i;
    s32 v;
    s32 *p = (s32 *)((u8 *)arg0 + 0x28);

    for (i = 0; i < 2; i = (u8)(i + 1)) {
        v = p[i + 2];
        if (v != 0) {
            func_1516972C((struct102 *)v);
        }
    }
    func_1514EDF0(arg0, p[0]);
}

void func_150F739C(struct260 *arg0);

void func_150F740C(struct260 *arg0) {
    func_150F739C(arg0);
    func_1514933C(arg0);
}

void func_15149368(struct260 *arg0);

void func_150F7438(struct260 *arg0) {
    func_150F739C(arg0);
    func_15149368(arg0);
}
