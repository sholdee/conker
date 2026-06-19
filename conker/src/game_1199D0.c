#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_1199D0/func_150EC520.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1199D0/func_150EC6B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1199D0/func_150ECA68.s")

void func_150ECB4C(s32 arg0, s32 arg1, u8 arg2) {
    func_15169850(arg1, arg2, arg0 + 0x28, arg0 + 0x2C, arg0);
}

struct S150ECB8C_inner;
extern void func_1502EA98(struct S150ECB8C_inner*, u8, u8, u8, u8, s32, u8);

struct S150ECB8C_inner {
    s32 unk0;
    u8 pad[0x37];
    u8 unk3B;
};

struct S150ECB8C {
    struct S150ECB8C_inner* unk0;
    u8 unk4;
    u8 unk5;
    u8 unk6;
    u8 unk7;
    u8 unk8;
    u8 unk9;
};

void func_150ECB8C(s32 arg0) {
    struct S150ECB8C* p = (struct S150ECB8C*)(arg0 + 0x28);
    struct S150ECB8C_inner* ptr = p->unk0;

    if ((ptr->unk0 == 0) || (ptr->unk3B != p->unk4)) {
        *(s16*)(arg0 + 0xE) = -1;
    } else {
        func_1502EA98(ptr, p->unk5, p->unk6, p->unk7, p->unk8, 0, p->unk9);
    }
}

extern void func_151C9AC0(s32, u8, s32);
extern void func_150ECA68(s32, s32, s32, s32, u8, u8, s16, s32, s32);

void func_150ECC00(s32 arg0, u8 arg1, s32 arg2) {
    func_151C9AC0(arg0, arg1, arg2);
    func_150ECA68(arg0, 0, 0xFF, 0, 0xFF, 4, -1, arg1, arg2);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1199D0/func_150ECC70.s")
