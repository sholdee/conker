#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_EEB10/func_150C1660.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_EEB10/func_150C16C0.s")

typedef struct {
    char pad[0x1B];
    u8 unk1B;
} SubStruct_150C1978;

typedef struct {
    char pad[0x1C];
    s16 unk1C;
    char pad2[0x98 - 0x1E];
    SubStruct_150C1978 *unk98;
} Struct_150C1978;

s32 func_150C1978(Struct_150C1978 *a0) {
    SubStruct_150C1978 *p = a0->unk98;
    s32 v1 = a0->unk1C << 3;
    if (v1 >= 0x100) {
        v1 = 0xFF;
    }
    p->unk1B = v1;
    if ((v1 & 0xFF) < 0) {
        return 0;
    }
    return 1;
}
