#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void func_1513470C(struct102 *arg0);


#pragma GLOBAL_ASM("asm/nonmatchings/game_F3BA0/func_150C66F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_F3BA0/func_150C673C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_F3BA0/func_150C682C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_F3BA0/func_150C6870.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_F3BA0/func_150C68C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_F3BA0/func_150C6A08.s")

typedef struct {
    char pad[0x5C];
    u8 unk5C;
} Func150C6D1CArg;

s32 func_150C6D1C(Func150C6D1CArg* arg) {
    s32 ret = 1;
    if (arg->unk5C == 0) {
        ret = 0;
    }
    arg->unk5C = 0;
    return ret;
}

typedef struct {
    char pad[0x18];
    s32 unk18;
} Func150C6D40Inner;

typedef struct {
    char pad[0x58];
    Func150C6D40Inner inner58;
} Func150C6D40Sub;

typedef struct {
    char pad[0x58];
    Func150C6D40Sub* unk58;
} Func150C6D40Arg;

void func_150C6D40(Func150C6D40Arg* arg0) {
    Func150C6D40Inner* inner = &arg0->unk58->inner58;
    inner->unk18 = 0;
    func_151346EC((struct102*)arg0);
}

void func_150C6D68(Func150C6D40Arg* arg0) {
    Func150C6D40Inner* inner = &arg0->unk58->inner58;
    inner->unk18 = 0;
    func_1513470C((struct102*)arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_F3BA0/func_150C6D90.s")
