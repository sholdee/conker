#include <ultra64.h>
#include "functions.h"
#include "variables.h"


extern s32 func_15147A80(void *, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);

struct Struct15147DA0_cpy { s32 unk0[8]; };

s32 func_15147DA0(void *arg0, void *arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5,
                  s32 arg6, s32 arg7, s32 arg8, s32 arg9, s32 arg10, s32 *arg11,
                  s32 arg12, u8 arg13, s32 arg14) {
    s32 v1;
    u8 *temp;

    *(s32 *)((u8 *)arg0 + 0x10) = 1;
    v1 = func_15147A80(arg0, (s32)arg2 + 0x48, 0x14, 1, 0, 1, arg9, arg10,
                       arg12, arg13, arg14);
    if (v1 == 0) {
        return 0;
    }
    temp = (u8 *)*(s32 *)((u8 *)v1 + 0x98);
    memcpy(temp, arg1, 0x20);
    temp[0x20] = arg3;
    temp[0x21] = arg4;
    temp[0x22] = arg5;
    temp[0x23] = arg6;
    temp[0x24] = arg7;
    temp[0x25] = arg8;
    *(struct Struct15147DA0_cpy *)(temp + 0x28) = *(struct Struct15147DA0_cpy *)arg11;
    return v1;
}


#pragma GLOBAL_ASM("asm/nonmatchings/game_175250/func_15147EB8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_175250/func_1514803C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_175250/func_151488C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_175250/func_15148AF4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_175250/func_15148BA4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_175250/func_15148DE0.s")

s32 func_15148EF8(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    u8 *temp = (u8 *)*(s32 *)((u8 *)arg0 + 0x98);
    temp[0x20] = 4;
    return 1;
}

void func_15148F1C(s32 arg0, f32 arg1, f32 arg2, f32 arg3, s32 arg4, s32 arg5,
                   s32 arg6, f32 arg7, s16 arg8, f32 arg9, f32 arg10, u8 arg11) {
    f32 temp_f2;
    struct { f32 x; f32 y; f32 z; s16 unk0C; s16 unk0E; s32 unk10; u8 pad14; u8 unk15; } sp9C;
    f32 temp_f0;
    struct { f32 unk00; f32 unk04; f32 unk08; f32 unk0C; f32 unk10; u8 pad14[4]; u8 unk18; u8 unk19; u8 unk1A; u8 unk1B; } sp7C;
    f32 sp78;
    f32 sp74;
    f32 sp70;
    u8 temp_v0;
    struct { s32 unk00; s32 unk04; s32 unk08; s32 unk0C; s32 unk10; s32 unk14; s32 unk18; u8 unk1C; u8 unk1D; } sp4C;

    sp78 = func_151423D8((u8)arg6);
    sp74 = func_151423D8((u8)(arg6 - 0x40));
    sp70 = func_151423D8((u8)arg5);
    temp_f2 = func_151423D8((u8)(arg5 - 0x40));

    sp9C.unk10 = 1;
    sp9C.unk0E = 1;
    sp7C.unk1A = 0xFF;
    sp7C.unk18 = 8;
    temp_v0 = *(((u8 *)&arg0) + 3);
    sp7C.unk19 = temp_v0;
    if (temp_v0 == 0xA) {
        sp7C.unk18 = 0x28;
    }

    temp_f0 = arg7 * sp78;
    sp9C.x = arg1;
    sp9C.y = arg2;
    sp9C.z = arg3;
    sp7C.unk00 = arg9;
    sp7C.unk10 = arg10;
    sp7C.unk04 = temp_f0 * temp_f2;
    sp7C.unk08 = -arg7 * sp74;
    sp7C.unk0C = temp_f0 * sp70;
    sp7C.unk1B = 0xFF;
    sp9C.unk15 = arg4 + 3;
    sp9C.unk0C = arg8;

    sp4C.unk00 = 0;
    sp4C.unk04 = 1;
    sp4C.unk08 = 0x160600;
    sp4C.unk0C = 3;
    sp4C.unk10 = 0x10;
    sp4C.unk14 = 0x80;
    sp4C.unk18 = 0x20;
    sp4C.unk1C = 0;
    sp4C.unk1D = 9;
    func_15147DA0(&sp9C, &sp7C, 0, 1, 0, 0, 0, 0, 0, 0, 0, (s32 *)&sp4C, 0, arg11, 1);
}

s32 func_151490C8(void *arg0) {
    u8 *v0 = (u8 *)*(s32 *)((u8 *)arg0 + 0x98);
    s32 v1 = *(s16 *)((u8 *)arg0 + 0x1C) << 3;

    if (v1 >= 0x100) {
        v1 = 0xFF;
    }
    v0[0x1B] = v1;
    if ((v1 & 0xFF) < 0) {
        return 0;
    }
    return 1;
}

void func_151478F4(void);

void func_15149104(void) {
    func_151478F4();
}
