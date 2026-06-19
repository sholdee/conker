#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_AEB40/func_15081690.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_AEB40/func_15081C20.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_AEB40/func_15081E0C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_AEB40/func_15081E78.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_AEB40/func_150825C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_AEB40/func_1508295C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_AEB40/func_150829D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_AEB40/func_15082A44.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_AEB40/func_150832AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_AEB40/func_15083384.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_AEB40/func_15083568.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_AEB40/func_150836CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_AEB40/func_150837D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_AEB40/func_150838EC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_AEB40/func_150839B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_AEB40/func_15083AC8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_AEB40/func_15083DA0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_AEB40/func_15083E0C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_AEB40/func_15083E90.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_AEB40/func_15083FB0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_AEB40/func_15084000.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_AEB40/func_15084044.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_AEB40/func_1508434C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_AEB40/func_150843AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_AEB40/func_15084488.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_AEB40/func_15084558.s")

typedef struct {
    u8 pad[0x1C9];
    u8 unk1C9;
    u8 pad2[0x2C4 - 0x1CA];
    u8 *unk2C4;
} GameAEB40Struct;

u8 func_150849A0(GameAEB40Struct *a0) {
    s32 v1 = a0->unk1C9;
    if (v1 != 0) {
        return a0->unk2C4[v1 - 1];
    }
    return a0->unk2C4[0];
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_AEB40/func_150849CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_AEB40/func_15084A18.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_AEB40/func_15084C30.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_AEB40/func_15084CB0.s")
