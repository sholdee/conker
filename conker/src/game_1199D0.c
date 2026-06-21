#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_1199D0/func_150EC520.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1199D0/func_150EC6B0.s")

void func_150ECA68(void *arg0, u8 arg1, u8 arg2, u8 arg3, u8 arg4, u8 arg5, s16 arg6, u8 arg7, s32 arg8) {
    struct {
        void *unk0;
        u8 unk4;
        u8 unk5;
        u8 unk6;
        u8 unk7;
        u8 unk8;
        u8 unk9;
    } sp3C;
    struct260 *temp_v0;

    sp3C.unk0 = arg0;
    sp3C.unk4 = *((u8 *)arg0 + 0x3B);
    sp3C.unk8 = arg4;
    sp3C.unk9 = arg5;
    sp3C.unk5 = arg1;
    sp3C.unk6 = arg2;
    sp3C.unk7 = arg3;

    temp_v0 = func_15149130((arg6 == -1) ? 0x12C : arg6, -1, 0x5D, -1, (arg6 == -1) ? 0 : 1, 0x45, (struct37 *)0xC, arg7, arg8);
    if (temp_v0 != NULL) {
        memcpy((void *)((s32)temp_v0 + 0x28), &sp3C, 0xC);
    }
}

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
extern void func_150ECA68(void *, u8, u8, u8, u8, u8, s16, u8, s32);

void func_150ECC00(s32 arg0, u8 arg1, s32 arg2) {
    func_151C9AC0(arg0, arg1, arg2);
    func_150ECA68(arg0, 0, 0xFF, 0, 0xFF, 4, -1, arg1, arg2);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1199D0/func_150ECC70.s")
