#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern void func_1514C2F0(f32 arg0, f32 arg1, f32 arg2, f32 arg3,
                          u8 arg4, s8 arg5, s16 arg6, u8 arg7,
                          s32 arg8, f32 arg9, s32 arg10, u8 arg11);

void func_150C1660(f32 arg0, f32 arg1, f32 arg2, u8 arg3) {
    func_1514C2F0(arg0, arg1, arg2, 80.0f, 0, 3, 0x19, 2, 0, 0.0f, 0, arg3);
}

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
