#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_1E5FF0/func_151B8B40.s")

extern f32 func_15144B68(f32);
extern void func_151D9450(void*, void*);

struct Foo151B8BE0 {
    char pad44[0x44];
    f32 unk44;
    char pad48[0x10];
    f32 unk58;
    f32 unk5C;
    f32 unk60;
    f32 unk64;
};

void func_151B8BE0(struct Foo151B8BE0 *arg0, void *arg1) {
    arg0->unk44 = sinf(arg0->unk58) * arg0->unk64 + arg0->unk5C;
    arg0->unk58 = arg0->unk58 + arg0->unk60 * D_800BE9A4;
    arg0->unk58 = func_15144B68(arg0->unk58);
    func_151D9450(arg0, arg1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E5FF0/func_151B8C54.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E5FF0/func_151B8CFC.s")
