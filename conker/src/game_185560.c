#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_185560/func_151580B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_185560/func_151581D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_185560/func_15158224.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_185560/func_151582C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_185560/func_1515858C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_185560/func_15158684.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_185560/func_15158920.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_185560/func_15158A20.s")

void func_15158A20(struct102 *);

void func_15158AA4(struct102 *arg0) {
    func_15158A20(arg0);
    func_15169804(arg0);
}

void func_15169824(struct102 *);

void func_15158AD0(struct102 *arg0) {
    func_15158A20(arg0);
    func_15169824(arg0);
}

typedef struct {
    u8 pad0[0x14];
    s16 unk14;
    u8 pad16[0x25];
    u8 unk3B;
    u8 pad3C[0xBC];
    s16 unkF8;
    u8 padFA[0x2];
    s32 unkFC;
} Struct15158AFC;

s32 func_15158AFC(Struct15158AFC *arg0) {
    s32 temp;

    if (arg0->unk14 < arg0->unkF8) {
        temp = arg0->unk14 * arg0->unkFC;
        if (temp < arg0->unk3B) {
            arg0->unk3B = temp;
        }
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_185560/func_15158B3C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_185560/func_15158BD0.s")

void func_1514EDF0(struct102 *, s32);

void func_15158CD4(struct102 *arg0) {
    func_1514EDF0(arg0, *(s32 *)((u8 *)arg0 + 0x18));
    func_15169804(arg0);
}

void func_15158D00(struct102 *arg0) {
    func_1514EDF0(arg0, *(s32 *)((u8 *)arg0 + 0x18));
    func_15169824(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_185560/func_15158D2C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_185560/func_15158FA4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_185560/func_15159084.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_185560/func_15159120.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_185560/func_15159184.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_185560/func_15159230.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_185560/func_151592B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_185560/func_15159370.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_185560/func_1515942C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_185560/func_15159594.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_185560/func_151596BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_185560/func_15159890.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_185560/func_15159BB0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_185560/func_15159C08.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_185560/func_1515A11C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_185560/func_1515A238.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_185560/func_1515A60C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_185560/func_1515A78C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_185560/func_1515A920.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_185560/func_1515A974.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_185560/func_1515AA84.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_185560/func_1515AB88.s")
