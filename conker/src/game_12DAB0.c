#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_12DAB0/func_15100600.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_12DAB0/func_15101090.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_12DAB0/func_15101148.s")

void func_151011E8(struct210 *arg0) {
    s32 temp = *(s32 *)((s32)arg0 + 0x124) + 0x110;
    *(s32 *)(temp + 0x28) = 0;
    func_1513CA6C(arg0);
}

void func_15101210(struct210 *arg0) {
    s32 temp = *(s32 *)((s32)arg0 + 0x124) + 0x110;
    *(s32 *)(temp + 0x28) = 0;
    func_1513CAA0(arg0);
}

void func_151617C4(struct210 *arg0);

void func_15101238(struct210 *arg0) {
    s32 temp = *(s32 *)((s32)arg0 + 0x18) + 0x110;
    *(s32 *)(temp + 0x2C) = 0;
    func_151617C4(arg0);
}

void func_151617E4(struct210 *arg0);

void func_15101260(struct210 *arg0) {
    s32 temp = *(s32 *)((s32)arg0 + 0x18) + 0x110;
    *(s32 *)(temp + 0x2C) = 0;
    func_151617E4(arg0);
}

void func_1513173C(struct210 *);

void func_15101288(struct210 *arg0) {
    s32 temp = *(s32 *)((s32)arg0 + 0xD0) + 0x110;
    *(s32 *)(temp + 0x24) = 0;
    func_1513173C(arg0);
}

void func_1513175C(struct210 *);

void func_151012B0(struct210 *arg0) {
    s32 temp = *(s32 *)((s32)arg0 + 0xD0) + 0x110;
    *(s32 *)(temp + 0x24) = 0;
    func_1513175C(arg0);
}

void func_151012D8(struct210 *arg0) {
    s32 temp = *(s32 *)((s32)arg0 + 0x170) + 0x110;
    *(s32 *)(temp + 0x30) = 0;
    func_151411A4(arg0);
}

void func_15101300(struct210 *arg0) {
    s32 temp = *(s32 *)((s32)arg0 + 0x170) + 0x110;
    *(s32 *)(temp + 0x30) = 0;
    func_151411C4(arg0);
}

void func_15101328(struct210 *arg0) {
    s32 temp = *(s32 *)((s32)arg0 + 0xA8) + 0x110;
    *(s32 *)(temp + 0x34) = 0;
    func_1513173C(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_12DAB0/func_15101350.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_12DAB0/func_15101378.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_12DAB0/func_151019C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_12DAB0/func_15101F50.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_12DAB0/func_151022AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_12DAB0/func_151025F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_12DAB0/func_151026BC.s")

void func_151027E8(struct210 *arg0) {
    s8 sp18[5];

    *(struct210 **)&sp18[0] = arg0;
    sp18[4] = *(u8 *)((s32)arg0 + 0x3B);
    func_151403A8(&sp18, 0x1A);
}

s32 func_1510281C(struct210 *arg0, s16 arg1) {
    s32 *p = (s32 *)(*(s32 *)((s32)arg0 + 0xD0) + 0x110);
    s32 v1;

    if (arg1 != *(u8 *)((s32)p + 0x22)) {
        goto tail;
    }
    v1 = *p;
    if (v1 != 0) {
        if (*(u8 *)(*(s32 *)(v1 + 0x31C) + 0x197) == 0) {
            goto tail;
        }
    }
    return 0;
tail:
    if (!(*(u8 *)((s32)arg0 + 0xD4) & 1)) {
        return 0;
    }
    return 1;
}

s32 func_15102884(struct210 *arg0, s32 arg1) {
    if (!(*(u8 *)((s32)arg0 + 0xAC) & 1)) {
        return 0;
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_12DAB0/func_151028AC.s")
