#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_FF0E0/func_150D1C30.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_FF0E0/func_150D1F6C.s")

void func_150D2054(struct260 *arg0) {
    s32 i;
    s32 *p;
    void *ptr;

    p = (s32 *)((u8 *)arg0 + 0x28);
    i = 0;
    do {
        ptr = (void *)p[i + 9];
        if (ptr != NULL) {
            func_1516972C((struct102 *)ptr);
        }
        i++;
        i = (u8)i;
    } while (i < 6);
}

extern void func_150D2054(struct260 *);

void func_150D20B0(struct260 *arg0) {
    func_150D2054(arg0);
    func_15149368(arg0);
}

void func_150D20DC(struct260 *arg0) {
    func_150D2054(arg0);
    func_1514933C(arg0);
}
