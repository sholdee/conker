#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_200930/func_151D3480.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_200930/func_151D3D50.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_200930/func_151D3E04.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_200930/func_151D3E6C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_200930/func_151D3F14.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_200930/func_151D3FF4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_200930/func_151D40D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_200930/func_151D42E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_200930/func_151D4408.s")

struct S151D4668 {
    void *unk0;
    u8 unk4;
};

void func_151D4668(void *arg0) {
    struct S151D4668 sp18;
    sp18.unk0 = arg0;
    sp18.unk4 = *((u8 *)arg0 + 0x3B);
    func_151494E0((s32)&sp18, 0x3C);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_200930/func_151D469C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_200930/func_151D4794.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_200930/func_151D4C38.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_200930/func_151D4D04.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_200930/func_151D4D58.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_200930/func_151D4DAC.s")

void func_151D5148(void *arg0) {
    s16 *p = *(s16 **)((u8 *)arg0 + 0x31C);
    if (p[0x24 / 2] > 0) {
        p[0x24 / 2]--;
        p = *(s16 **)((u8 *)arg0 + 0x31C);
    }
    p[0x1AA / 2]++;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_200930/func_151D5174.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_200930/func_151D5334.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_200930/func_151D5404.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_200930/func_151D5514.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_200930/func_151D5648.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_200930/func_151D5714.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_200930/func_151D57F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_200930/func_151D5A18.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_200930/func_151D5B6C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_200930/func_151D5D60.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_200930/func_151D5E30.s")
