#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_1B0740/func_15183290.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1B0740/func_151838B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1B0740/func_15183974.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1B0740/func_151839F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1B0740/func_15183ACC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1B0740/func_15183BA4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1B0740/func_15183C28.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1B0740/func_15183D28.s")

typedef struct {
    char pad[0x57];
    u8 unk57;
} Struct15184118;

typedef struct {
    char pad[0x31C];
    Struct15184118 *unk31C;
} Obj15184118;

s32 func_15184118(Obj15184118 *a0) {
    if (a0->unk31C != 0) {
        if (a0->unk31C->unk57 != 0) {
            return 1;
        }
    }
    return 0;
}
