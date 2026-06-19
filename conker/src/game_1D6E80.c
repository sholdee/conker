#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_1D6E80/func_151A99D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D6E80/func_151A9AA4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D6E80/func_151A9BA0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D6E80/func_151A9CA0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D6E80/func_151A9DC0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D6E80/func_151A9EC0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D6E80/func_151A9FC8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D6E80/func_151AA09C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D6E80/func_151AA170.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D6E80/func_151AA17C.s")

extern void func_1519F400(void);

void func_151AA1D0(void) {
    func_1519F400();
}

void func_151AA1F0(void) {
    func_1519F400();
}

struct s_151AA210_arg {
    char pad0[0x18];
    s32 unk18;
    u8 unk1C;
};

struct s_151AA210_buf {
    s32 unk0;
    u8 unk4;
};

extern void func_15147D64(s32, s32);
extern void func_1519F3B8(struct s_151AA210_arg *);

void func_151AA210(struct s_151AA210_arg *arg0) {
    s32 temp;
    struct s_151AA210_buf sp1C;

    temp = arg0->unk18;
    sp1C.unk0 = temp;
    sp1C.unk4 = arg0->unk1C;
    temp = (s32)&sp1C;
    func_15147D64(temp, 0xA);
    func_151494E0(temp, 0xA);
    func_1519F3B8(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D6E80/func_151AA264.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D6E80/func_151AA30C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D6E80/func_151AA48C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D6E80/func_151AA5A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D6E80/func_151AA6D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D6E80/func_151AAA4C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D6E80/func_151AAABC.s")

void func_151352EC(struct102 *arg0);

void func_151AAB50(struct102 *arg0) {
    s32 *p = (s32 *)(*(s32 *)((u8 *)arg0 + 0x80) + 0x58);
    p[5] = 0;
    func_151352EC(arg0);
}

void func_1513530C(struct102 *arg0);

void func_151AAB78(struct102 *arg0) {
    s32 *p = (s32 *)(*(s32 *)((u8 *)arg0 + 0x80) + 0x58);
    p[5] = 0;
    func_1513530C(arg0);
}

s32 func_151AABA0(u8 *arg0) {
    s32 ret = 1;
    if (arg0[0x84] == 0) {
        ret = 0;
    }
    arg0[0x84] = 0;
    return ret;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D6E80/func_151AABC4.s")

s32 func_151AADBC(s32 arg0) {
    u8 *p;
    s32 v1;

    p = *(u8 **)(arg0 + 0x98);
    v1 = *(s16 *)(arg0 + 0x1C) << 4;
    if (v1 >= 0x100) {
        v1 = 0xFF;
    }
    if (v1 < p[0x1B]) {
        p[0x1B] = v1;
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D6E80/func_151AADF8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D6E80/func_151AB090.s")

extern s32 func_1513F6C0(void *arg0, s32 arg1, s32 arg2);

s32 func_151AB180(u8 *arg0) {
    s32 *temp = (s32 *)((*(u8 **)((u8 *)arg0 + 0xB0)) + 0x58);
    temp[6] = 0;
    *(s32 *)((u8 *)arg0 + 0x18) |= 2;
    *(u8 **)((u8 *)arg0 + 0xB0) = 0;
    func_1513F6C0(arg0, 0, 0);
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D6E80/func_151AB1C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D6E80/func_151AB2C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D6E80/func_151AB3A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D6E80/func_151AB6B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D6E80/func_151AB788.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D6E80/func_151AB7D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D6E80/func_151AB828.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D6E80/func_151AB854.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D6E80/func_151AB920.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D6E80/func_151AB930.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D6E80/func_151AB9C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D6E80/func_151ABD54.s")

struct tmp151ABE00 {
    s32 unk0;
    s8  unk4;
};

void func_151ABE00(void *arg0) {
    struct tmp151ABE00 tmp;

    tmp.unk0 = (s32)arg0;
    tmp.unk4 = *(u8 *)((char *)arg0 + 0x3B);

    func_1516944C(0x20, (s32)&tmp, 0xC);
}
