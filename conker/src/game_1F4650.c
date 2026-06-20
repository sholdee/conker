#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_1F4650/func_151C71A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1F4650/func_151C756C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1F4650/func_151C7E98.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1F4650/func_151C82D0.s")

void func_151C8674(s32 arg0, s32 arg1) {
    struct {
        s32 unk0;
        s32 unk4;
    } sp18;
    if (arg0 != 0) {
        sp18.unk0 = arg0;
        sp18.unk4 = arg1;
        func_151403A8((s32)&sp18, 0x20);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1F4650/func_151C86AC.s")

s32 func_151C87AC(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s16 *arg6) {
    void *temp = *(void **)((s32)arg0 + 0x18);
    if (!(*(u8 *)((s32)temp + 0x86) & 0x2)) {
        *arg6 = 0;
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1F4650/func_151C87E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1F4650/func_151C899C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1F4650/func_151C8FCC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1F4650/func_151C9198.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1F4650/func_151C94D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1F4650/func_151C95D8.s")

s32 func_151C96DC(void *arg0, s32 arg1) {
    s32 temp = *(s32 *)((s32)arg0 + 0x170) + 0x110;
    if (*(u8 *)(temp + 0x86) & 0x2) {
        return 1;
    }
    return 0;
}

void func_151C970C(s32 arg0, s32 arg1) {
    struct {
        s32 unk0;
        u8 unk4;
    } sp18;
    sp18.unk0 = arg1;
    sp18.unk4 = arg0;
    func_151403A8((s32)&sp18, 0x3A);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1F4650/func_151C9740.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1F4650/func_151C9AC0.s")

s32 func_151C9B30(void *arg0) {
    s32 temp = *(s32 *)((s32)arg0 + 0x18);
    if (*(u8 *)(temp + 0x6F) == 0) {
        *(u8 *)(*(s32 *)((s32)arg0 + 0x14) + 0x9) = 0;
    } else {
        *(u8 *)(*(s32 *)((s32)arg0 + 0x14) + 0x9) = 1;
    }
    return 1;
}

s32 func_151C9B64(void *arg0, u8 *arg1) {
    s32 temp = *(s32 *)((s32)arg0 + 0x188);
    if (*(u8 *)(temp + 0x6F) == 0) {
        *arg1 = 1;
    } else {
        *(s32 *)((s32)arg0 + 0x58) &= ~0x2;
        *arg1 = 0;
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1F4650/func_151C9BA0.s")

void func_150BDE90(void *, u8, s32);
void func_151C9F38(void *, s32, u8, s8, u8);
void func_151CC524(void *, s32, s32, s32, u8, u8);
void func_151CC840(void *, s32, s32, s32, u8, u8);
void func_151CCF08(void *, u8, s8, u8);
void func_151CB5FC(void *, s32, u8, s8, u8);

void func_151C9DE8(void *arg0, u8 arg1, s8 arg2, u8 arg3, s32 arg4) {
    func_151C9F38(arg0, 4, arg1, arg2, arg3);
    func_151CC524(arg0, 0, 0x32, 0xFF, arg1, arg3);
    func_151CC840(arg0, 0, 0x32, 0xFF, arg1, arg3);
    func_151CCF08(arg0, arg1, arg2, arg3);
    func_150BDE90(arg0, arg3, arg4);
    func_151CB5FC(arg0, 2, arg1, arg2, arg3);
    if (D_800BE9F0 == 0x27) {
        D_8008CD00 = 1;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1F4650/func_151C9ED4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1F4650/func_151C9F38.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1F4650/func_151CA6A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1F4650/func_151CAACC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1F4650/func_151CAB78.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1F4650/func_151CAD28.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1F4650/func_151CB110.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1F4650/func_151CB49C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1F4650/func_151CB510.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1F4650/func_151CB5FC.s")

void func_151CB918(void *arg0, void *arg1, u8 arg2) {
    s32 base = (s32)arg0 + 0x70;
    if (arg2 == 0x37) {
        if (*(u8 *)arg1 == *(u8 *)(base + 0xE)) {
            if (*(s32 *)((s32)arg1 + 0x4) == *(s32 *)base) {
                *(f32 *)(base + 0x10) = 0.0f;
                *(u8 *)(base + 0xC) |= 0x1;
                *(f32 *)(base + 0x14) = 0.0f;
            }
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1F4650/func_151CB970.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1F4650/func_151CBB6C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1F4650/func_151CBBE0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1F4650/func_151CBC60.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1F4650/func_151CC1D4.s")

extern void func_1515572C(void *, s32);

void func_151CC290(s32 arg0) {
    s32 sp1C;

    sp1C = arg0;
    func_1515572C(&sp1C, 0x46);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1F4650/func_151CC2BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1F4650/func_151CC524.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1F4650/func_151CC77C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1F4650/func_151CC840.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1F4650/func_151CCD1C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1F4650/func_151CCE94.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1F4650/func_151CCF08.s")

extern f32 func_151CC1D4(void *);

void func_151CD224(void *arg0) {
    s32 base = (s32)arg0 + 0x70;
    f32 ret = func_151CC1D4(arg0);
    f32 temp = (1.0f - *(f32 *)(base + 0x20) * (ret - *(f32 *)(base + 0x18))) * 75.0f;
    if (*(u8 *)(base + 0xD) == 5) {
        *(f32 *)((s32)arg0 + 0x14) = 92.0f + temp;
    } else if (*(u8 *)(base + 0xD) == 4) {
        *(f32 *)((s32)arg0 + 0x14) = -92.0f - temp;
    }
}
