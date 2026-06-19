#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_FFBA0/func_150D26F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_FFBA0/func_150D278C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_FFBA0/func_150D2924.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_FFBA0/func_150D2D6C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_FFBA0/func_150D317C.s")

void func_150D278C(s32, void*, u8, u8);

struct S150D32FC {
    s32 unk0;
    u8 pad4[0xC];
    u8 unk10;
    u8 pad11[0x40];
    u8 unk51;
};

void func_150D32FC(u8 *arg0, u8 *arg1, u8 arg2) {
    struct S150D32FC *v0 = (struct S150D32FC *)(arg0 + 0x28);

    if (arg2 == 0x34 && arg1[0] == ((u8*)v0)[0x51]) {
        func_150D278C(v0->unk0, &v0->unk10, arg0[0xC], arg0[1]);
    }
}
