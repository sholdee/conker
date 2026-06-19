#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_1BA1D0/func_1518CD20.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1BA1D0/func_1518D1C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1BA1D0/func_1518D6E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1BA1D0/func_1518E298.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1BA1D0/func_1518E308.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1BA1D0/func_1518E37C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1BA1D0/func_1518E3C4.s")

extern void func_1518E308(void *);
extern void func_1514EDF0(void *, s32);

void func_1518E4A0(void *arg0) {
    func_1518E308(arg0);
    func_1514EDF0(arg0, *(s32 *)((char *)arg0 + 0x18));
}

void func_1518E4CC(void *arg0) {
    func_1518E4A0(arg0);
    func_15169804(arg0);
}

void func_1518E4F8(void *arg0) {
    func_1518E4A0(arg0);
    func_15169824(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1BA1D0/func_1518E524.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1BA1D0/func_1518E5D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1BA1D0/func_1518E66C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1BA1D0/func_1518E6D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1BA1D0/func_1518E73C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1BA1D0/func_1518EB10.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1BA1D0/func_1518EF54.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1BA1D0/func_1518F058.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1BA1D0/func_1518F108.s")

s32 func_1518F15C(void *arg0) {
    f32 temp;

    temp = *(f32 *)((char *)arg0 + 0x30);
    *(f32 *)((char *)arg0 + 0x30) = temp - *(f32 *)((char *)arg0 + 0x154) * *(f32 *)((char *)arg0 + 0x30);
    if (*(s16 *)((char *)arg0 + 0x1C) < *(s16 *)((char *)arg0 + 0x158)) {
        *(u8 *)((char *)arg0 + 0x5C) = *(s16 *)((char *)arg0 + 0x15A) * *(s16 *)((char *)arg0 + 0x1C);
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1BA1D0/func_1518F1A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1BA1D0/func_1518F384.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1BA1D0/func_1518F45C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1BA1D0/func_1518F49C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1BA1D0/func_1518F51C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1BA1D0/func_1518F5D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1BA1D0/func_1518F7C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1BA1D0/func_1518F858.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1BA1D0/func_1518F89C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1BA1D0/func_1518F8E0.s")

extern void func_1514BE20(void *);

struct Vec3i { s32 x, y, z; };

s32 func_1518FC04(void *arg0, struct Vec3i *arg1) {
    struct { s32 pad[13]; struct Vec3i v; } *temp;
    temp = ((void **)arg0)[0xB];
    temp->v = *arg1;
    func_1514BE20(temp);
    return 1;
}

extern void func_1514BF50(void *);

struct Vec3i2 { s32 x, y, z; };

s32 func_1518FC44(void *arg0, struct Vec3i2 *arg1) {
    struct { s32 pad[13]; struct Vec3i2 v; } *temp;
    temp = *(void **)((char *)arg0 + 0x2C);
    temp->v = *arg1;
    func_1514BF50(temp);
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1BA1D0/func_1518FC84.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1BA1D0/func_1518FDC4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1BA1D0/func_1519003C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1BA1D0/func_1519021C.s")

extern void func_15163DEC(void *, void *);
extern s32 func_15163F50(void *, void *);

void func_151903D0(void *arg0) {
    func_15163DEC(arg0, (char *)arg0 + 0x20);
    func_15163F50(arg0, (char *)arg0 + 0x18);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1BA1D0/func_15190400.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1BA1D0/func_15190454.s")

extern void func_15190454(void *);
extern void func_151617C4(void *);

void func_15190464(void *arg0) {
    func_15190454(arg0);
    func_151617C4(arg0);
}

extern void func_151617E4(void *);

void func_15190490(void *arg0) {
    func_15190454(arg0);
    func_151617E4(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1BA1D0/func_151904BC.s")

struct tmp15190518 {
    s32 unk0;
    s8  unk4;
};

void func_15190518(void *arg0) {
    struct tmp15190518 tmp;

    tmp.unk0 = (s32)arg0;
    tmp.unk4 = *(u8 *)((char *)arg0 + 0x3B);

    func_1516944C(0x3E, (s32)&tmp, 0x2A);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1BA1D0/func_15190550.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1BA1D0/func_151905BC.s")

void func_151906C4(void *arg0) {
    u8 *temp;
    temp = *(u8 **)(*(u8 **)((u8 *)arg0 + 0x10) + 0x31C);
    if (temp != NULL) {
        temp[0x1AC] = 0;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1BA1D0/func_151906E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1BA1D0/func_1519072C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1BA1D0/func_15190770.s")

extern void func_15191400(void *);

void func_15190840(void *arg0) {
    func_15191400(arg0);
    func_15169804(arg0);
}

void func_1519086C(void *arg0) {
    func_15191400(arg0);
    func_15169824(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1BA1D0/func_15190898.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1BA1D0/func_15190F9C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1BA1D0/func_1519108C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1BA1D0/func_15191400.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1BA1D0/func_15191520.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1BA1D0/func_1519187C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1BA1D0/func_151918BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1BA1D0/func_15191980.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1BA1D0/func_15191A84.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1BA1D0/func_15191B8C.s")
