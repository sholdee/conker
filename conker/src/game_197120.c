#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_197120/func_15169C70.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_197120/func_1516A3F4.s")

struct Struct1516A538 {
    u8 pad0;
    u8 unk1;
    u8 padb[0xA];
    u8 unkC;
    u8 padd[0x7];
    s16 unk14;
    u8 pad16[0x2];
    s16 unk18;
    s16 unk1A;
    s16 unk1C;
    u8 pad1e[0x7];
    u8 unk25;
};

extern u8 func_150ADA20(void);
extern void func_15171D4C(f32, f32, f32, s32, s32, s32, f32, s32, s32, s32, s32, s32, s32, s32);

void func_1516A538(struct Struct1516A538 *arg0) {
    u32 b;
    u32 a;
    s32 c;

    if (arg0->unk14 >= 0x300) {
        a = (u32)func_150ADA20() % 3;
        c = arg0->unk25;
        b = (u32)func_150ADA20() % 0x168;
        func_15171D4C(
            (f32)(s32)arg0->unk18,
            (f32)((s32)arg0->unk1A - 0xA),
            (f32)(s32)arg0->unk1C,
            0x64,
            0,
            a + 0x20,
            (f32)(u32)b,
            0,
            (c * 25) / 255 + 0x19,
            0,
            0x100,
            0,
            arg0->unkC,
            arg0->unk1);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_197120/func_1516A648.s")
