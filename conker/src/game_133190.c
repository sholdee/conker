#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_133190/func_15105CE0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_133190/func_1510608C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_133190/func_151061E0.s")

struct S151061EC {
    u8 pad0[0x48];
    s32 idx;
    u8 pad4C[0x88 - 0x4C];
    u8 elems[1][0x34];
};

void *func_151061EC(struct S151061EC *arg0) {
    s32 i = arg0->idx;
    return &arg0->elems[i];
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_133190/func_15106214.s")

f32 func_151064B4(f32 arg0) {
    f32 t = 1.0f - arg0;
    return t * t * t;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_133190/func_151064DC.s")

f32 func_15106510(f32 arg0) {
    return 3.0f * arg0 * arg0 * (1.0f - arg0);
}

f32 func_15106540(f32 arg0) {
    return arg0 * arg0 * arg0;
}

f32 func_15106558(f32 arg0) {
    f32 t = 1.0f - arg0;
    return -3.0f * t * t;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_133190/func_15106584.s")

f32 func_151065BC(f32 arg0) {
    return -9.0f * arg0 * arg0 + 6.0f * arg0;
}

f32 func_151065EC(f32 arg0) {
    return 3.0f * arg0 * arg0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_133190/func_15106610.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_133190/func_151067B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_133190/func_15106E78.s")

void func_15106E78(struct102 *arg0);

void func_15106EF8(struct102 *arg0) {
    func_15106E78(arg0);
    func_15169804(arg0);
}

void func_15169824(struct102 *arg0);

void func_15106F24(struct102 *arg0) {
    func_15106E78(arg0);
    func_15169824(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_133190/func_15106F50.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_133190/func_15106F98.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_133190/func_151070F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_133190/func_151072BC.s")

struct S15107604 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
};

void func_15107604(s32 **arg0) {
    s32 **q = (s32 **)arg0[0x18];
    struct S15107604 *p = (struct S15107604 *)((u8 *)q[0] + 0x28);
    p->unk8 = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_133190/func_1510761C.s")

void func_1510761C(struct260 *arg0);

void func_1510764C(struct260 *arg0) {
    func_1510761C(arg0);
    func_1514933C(arg0);
}

void func_15149368(struct260 *arg0);

void func_15107678(struct260 *arg0) {
    func_1510761C(arg0);
    func_15149368(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_133190/func_151076A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_133190/func_15107700.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_133190/func_151078E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_133190/func_15107924.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_133190/func_15107A20.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_133190/func_15107AE0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_133190/func_15107B78.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_133190/func_15107C1C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_133190/func_15107E48.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_133190/func_15107F54.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_133190/func_15107F98.s")
