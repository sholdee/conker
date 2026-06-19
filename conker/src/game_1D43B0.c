#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_1D43B0/func_151A6F00.s")

struct S151A73EC {
    s32 unk0;
    void *unk4;
};
s32 func_151A73EC(void *arg0) {
    struct S151A73EC *p = (struct S151A73EC *)((u8 *)arg0 + 0x170);
    if (*(s16 *)((u8 *)arg0 + 0x64) < 0x20) {
        if (p->unk4 != 0) {
            func_1516972C((struct102 *)p->unk4);
            p->unk4 = 0;
        }
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D43B0/func_151A743C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D43B0/func_151A7610.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D43B0/func_151A77C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D43B0/func_151A787C.s")

struct S151A7908 {
    s32 unk0;
    void *unk4;
};
void func_151A7908(void *arg0) {
    struct S151A7908 *p = (struct S151A7908 *)((u8 *)arg0 + 0x170);
    if (p->unk4 != 0) {
        func_1516972C((struct102 *)p->unk4);
        p->unk4 = 0;
    }
}
