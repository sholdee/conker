#include <ultra64.h>
#include "functions.h"
#include "variables.h"


void func_1507EB80(u8 *buf, s32 *count, u8 c) {
    if (*count + 1 < 40) {
        buf[*count] = c;
        *count = *count + 1;
    }
}

extern u8 *D_80086C24[];
extern u8 D_8009BBF0[];

void func_1507EBB8(s32 arg0, s32 *arg1, s32 arg2) {
    u8 *dst = D_80086C24[arg2];
    s32 len = D_8009BBF0[arg2];
    if (*arg1 + len < 40) {
        bcopy(dst, (u8 *)arg0 + *arg1, len);
        *arg1 += len;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_AC030/func_1507EC38.s")

void func_1507EEB8(s32 arg0, void *arg1);

void func_1507EE58(s32 arg0, void *arg1) {
    func_1507EEB8(*((u8*)&arg0 + 3), arg1);
    if (*((u8*)&arg0 + 3) == 0x11) {
        func_1507EEB8(0x12, arg1);
    } else if (*((u8*)&arg0 + 3) == 0x12) {
        func_1507EEB8(0x11, arg1);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_AC030/func_1507EEB8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_AC030/func_1507EEF4.s")

void func_1507EFA0(s32 c, u8 *arg1) {
    s32 i = 4;
    u8 *p = arg1 + 4;
    do {
        if (*p == c) {
            *p = 0;
            return;
        }
        i--;
        p--;
    } while (i >= 0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_AC030/func_1507EFD0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_AC030/func_1507F454.s")

s32 func_1507F4C0(s32 arg0) {
    s32 pad;
    s32 base;
    u32 mod;

    if (arg0 == 0) {
        base = 0xB4;
        mod = 0x3C;
    } else if (D_800BE9F0 == 0x31) {
        return 0;
    } else if (arg0 == 1) {
        base = 0x3C;
        mod = 0x3C;
    } else {
        base = 0;
        mod = 0x1E;
    }

    return func_150ADA20() % mod + base;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_AC030/func_1507F54C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_AC030/func_1507F640.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_AC030/func_1507FC2C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_AC030/func_1507FEA0.s")

void func_15191B8C(s32 arg0, u8 arg1);

void func_1507FF94(s32 arg0) {
    struct {
        s32 unk0;
        u8 unk4;
    } sp20;

    sp20.unk0 = arg0;
    sp20.unk4 = *(u8 *)(arg0 + 0x3B);
    func_15191B8C((s32)&sp20, 0xD);
    func_151494E0((s32)&sp20, 0xD);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_AC030/func_1507FFD8.s")
