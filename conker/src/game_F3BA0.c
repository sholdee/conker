#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void func_1513470C(struct102 *arg0);


#pragma GLOBAL_ASM("asm/nonmatchings/game_F3BA0/func_150C66F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_F3BA0/func_150C673C.s")

extern s32 func_1513F6C0(void *arg0, s32 arg1, s32 arg2);

s32 func_150C682C(u8 *arg0) {
    s32 *temp = (s32 *)((*(u8 **)((u8 *)arg0 + 0xB0)) + 0x58);
    temp[5] = 0;
    *(s32 *)((u8 *)arg0 + 0x18) |= 2;
    *(u8 **)((u8 *)arg0 + 0xB0) = 0;
    func_1513F6C0(arg0, 0, 0);
    return 0;
}

s32 func_150C68C4(s32 arg0);

void func_150C6870(u8 *arg0) {
    s32 temp = *(s32 *)((u8 *)arg0 + 0x18);
    if (*(s32 *)((u8 *)arg0 + 0x70) != 0) {
        u8 *p = *(u8 **)((u8 *)arg0 + 0x70) + 0x58;
        p[4] = 1;
    } else {
        *(s32 *)((u8 *)arg0 + 0x70) = func_150C68C4(temp);
    }
}

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
