#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_F5800/func_150C8350.s")

extern void func_150C8350(void);

void func_150C84F4(s32 arg0) {
    if (arg0 == 0) {
        func_150C8350();
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_F5800/func_150C851C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_F5800/func_150C8600.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_F5800/func_150C8730.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_F5800/func_150C88D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_F5800/func_150C8A68.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_F5800/func_150C8DB8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_F5800/func_150C99B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_F5800/func_150C9BDC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_F5800/func_150C9DC4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_F5800/func_150CA07C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_F5800/func_150CA150.s")

typedef struct {
    f32 unk0;
    f32 unk4;
    s32 unk8;
} Struct150CA930;

extern void func_1514C678(f32, f32, s32, f32, s32, s32, s32, s32, s32, f32, s32, s32);

void func_150CA930(Struct150CA930 *arg0) {
    s16 temp;

    temp = (func_150ADA20() % 21U) + 10;
    func_1514C678(arg0->unk0, arg0->unk4, arg0->unk8,
                  (func_150ADA68() * 59.0f) + 170.0f,
                  0, 0xFF, temp, 0x13, 0, 0.0f, 0, 0xFF);
}

typedef struct {
    char pad1C[0x1C];
    s16 unk1C;
    char pad1E[0x28 - 0x1E];
    u8 unk28;
} Struct150CA9D0;

s32 func_150CA9D0(Struct150CA9D0 *arg0) {
    s32 v1;
    if (arg0->unk1C < 0x20) {
        v1 = arg0->unk1C << 3;
        if (v1 < arg0->unk28) {
            arg0->unk28 = v1;
        }
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_F5800/func_150CAA04.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_F5800/func_150CAC28.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_F5800/func_150CADD0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_F5800/func_150CB008.s")
