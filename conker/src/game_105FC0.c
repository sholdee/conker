#include <ultra64.h>
#include "functions.h"
#include "variables.h"


void func_150D8B10(f32 *a0, f32 *a1) {
    a1[0] = a0[5];
    a1[1] = a0[6] + 20.0f;
    a1[2] = a0[7];
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_105FC0/func_150D8B3C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_105FC0/func_150D8B88.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_105FC0/func_150D8D84.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_105FC0/func_150D8E1C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_105FC0/func_150D8E4C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_105FC0/func_150D8FAC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_105FC0/func_150D942C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_105FC0/func_150D9C7C.s")

void func_150DA484(void *arg0) {
    u16 *temp = (u16 *)*(u32 *)((u8 *)arg0 + 0x98);
    if (temp[0x18] != 0) {
        func_100111C8(temp[0x18]);
    }
}

void func_150DA484(void *);
void func_151478F4(void *);

void func_150DA4B4(void *arg0) {
    func_150DA484(arg0);
    func_151478F4(arg0);
}

void func_15147928(void *);

void func_150DA4E0(void *arg0) {
    func_150DA484(arg0);
    func_15147928(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_105FC0/func_150DA50C.s")

struct s_150DA5EC {
    s32 unk0;
    u8 unk4;
    f32 unk8;
};

extern void func_15147D64(struct s_150DA5EC *, s32);

void func_150DA5EC(u8 *arg0, f32 arg1) {
    struct s_150DA5EC sp1C;

    sp1C.unk0 = (s32) arg0;
    sp1C.unk4 = arg0[0x3B];
    sp1C.unk8 = arg1;
    func_15147D64(&sp1C, 0x44);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_105FC0/func_150DA628.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_105FC0/func_150DA67C.s")
