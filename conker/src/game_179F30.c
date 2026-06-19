#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_179F30/func_1514CA80.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_179F30/func_1514D15C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_179F30/func_1514D310.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_179F30/func_1514D3B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_179F30/func_1514D4B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_179F30/func_1514D564.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_179F30/func_1514D64C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_179F30/func_1514D96C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_179F30/func_1514D978.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_179F30/func_1514D9F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_179F30/func_1514DA38.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_179F30/func_1514DAA4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_179F30/func_1514DB18.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_179F30/func_1514DB58.s")

extern s32 D_800BE9F0;
void func_151B2060(void);

void func_1514DB64(void) {
    if (D_800BE9F0 == 0x14) {
        func_151B2060();
    }
}

void func_1514F194(void);

void func_1514DB98(void) {
    func_1514F194();
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_179F30/func_1514DBB8.s")

void func_1514DC38(struct127 *arg0) {
    func_1500EE18(arg0, 0xFF, 1);
}

void func_151D0F60(void *, s32, s32, s32);

void func_1514DC5C(void *arg0) {
    func_151D0F60(arg0, 0, 0xFF, 1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_179F30/func_1514DC84.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_179F30/func_1514DC98.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_179F30/func_1514DCAC.s")

struct struct1514DCF4 {
    u8 pad[0x31C];
    struct127 *unk31C;
};

void func_1514DCF4(struct struct1514DCF4 *arg0) {
    if (arg0->unk31C != NULL) {
        *(u8 *)((u8 *)arg0->unk31C + 0x94) = 1;
    }
    func_15083568((struct127 *)arg0, 0x17, 1.0f, 0);
}

void func_1514DCAC(void);

void func_1514DD2C(void) {
    func_1514DCAC();
}

void func_1514DD4C(void) {
    func_1514DCAC();
}

void func_1514DD6C(void) {
    func_1514DCAC();
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_179F30/func_1514DD8C.s")

void func_1514DDAC(void) {
    func_1514DCAC();
}

void func_1514DDCC(void) {
    func_1514DCAC();
}

void func_1514DDEC(void) {
    func_1514DCAC();
}

void func_1514DE0C(void) {
    func_1514DCAC();
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_179F30/func_1514DE2C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_179F30/func_1514DE38.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_179F30/func_1514DE44.s")

void func_1514DE50(void) {
    if (((u8 *)D_800D2E4C)[0x11] & 8) {
        func_1514DCAC();
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_179F30/func_1514DE88.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_179F30/func_1514DE94.s")

s32 func_15083FB0(s32);

void func_1514DFD0(u8 *arg0) {
    arg0[0x65] = func_15083FB0(9) + 1;
    arg0[0x101] |= 0x34;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_179F30/func_1514E00C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_179F30/func_1514E194.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_179F30/func_1514E31C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_179F30/func_1514E508.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_179F30/func_1514E5B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_179F30/func_1514E668.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_179F30/func_1514E718.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_179F30/func_1514E7C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_179F30/func_1514E824.s")

void func_1514E830(struct102 *arg0) {
    func_1516972C(arg0);
}

void func_1518E308(void *);

void func_1514E850(void *arg0) {
    func_1518E308(arg0);
    func_1516972C(arg0);
}

void func_1514E87C(void) {
    func_1515F10C();
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_179F30/func_1514E89C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_179F30/func_1514E920.s")

void func_1514E920(void);

void func_1514E9DC(void) {
    func_1514E920();
}

void func_1514E89C(void);

void func_1514E9FC(void) {
    func_1514E89C();
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_179F30/func_1514EA1C.s")

void func_1514EB6C(void) {
    func_1514E89C();
}

s32 func_1514EB8C(s32 arg0, s32 arg1, s32 arg2) {
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_179F30/func_1514EBA4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_179F30/func_1514EC1C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_179F30/func_1514ECE0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_179F30/func_1514ED3C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_179F30/func_1514ED8C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_179F30/func_1514EDF0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_179F30/func_1514EE70.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_179F30/func_1514EECC.s")

void func_1514F110(void) {
    func_1514F194();
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_179F30/func_1514F130.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_179F30/func_1514F194.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_179F30/func_1514F308.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_179F30/func_1514F3CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_179F30/func_1514F44C.s")

extern void func_151D74B0(s32, s32, s32, s32, s32);

void func_1514F4A8(s32 arg0) {
    func_151D74B0(arg0, 1, -1, 0xFF, 1);
}

void func_1514F4D8(s32 arg0) {
    func_151D74B0(arg0, 2, 1, 0xFF, 1);
}

void func_1514F508(s32 arg0) {
    func_151D74B0(arg0, 3, 0, 0xFF, 1);
}

void func_1514F538(s32 arg0) {
    func_151D74B0(arg0, 4, -1, 0xFF, 1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_179F30/func_1514F568.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_179F30/func_1514F590.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_179F30/func_1514F5CC.s")
