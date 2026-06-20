#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_138520/func_1510B070.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_138520/func_1510B128.s")

void func_1510B128(s32, f32, f32, f32, f32);

void func_1510B32C(s32 arg0, f32 arg1, f32 arg2, f32 arg3) {
    func_1510B128(arg0, arg1, arg2, arg3, 0.0f);
    D_800D9AC0[arg0].unk0 = arg3;
    D_800D9AC0[arg0].unk4 = arg1;
    D_800D9AC0[arg0].unk8 = arg2;
    D_800D9AF0 = 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_138520/func_1510B3B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_138520/func_1510B458.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_138520/func_1510B51C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_138520/func_1510B5F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_138520/func_1510B690.s")

extern s32 D_800BE628;
extern u8 D_800BE9C0;
extern struct10 *D_800DC2A0;
extern u8 D_80089470;

#define WGFX2(pkt, a, b)            \
{                                   \
    Gfx *_g = (Gfx *)(pkt);         \
    _g->words.w0 = (u32)(a);        \
    _g->words.w1 = (u32)(b);        \
}

Gfx *func_1510B7B4(Gfx *gfx, s32 idx) {
    WGFX2(gfx++, 0xE7000000, 0x00000000);
    WGFX2(gfx++, 0xF9000000, 0x00000001);
    WGFX2(gfx++, 0xDA380003, &D_80089470);
    WGFX2(gfx++, 0xDB0E0000, *(u16 *)((u8 *)((struct259 *)D_800BE628 + idx) + 0xB8));
    WGFX2(gfx++, 0xDB040004, 0x00000003);
    WGFX2(gfx++, 0xDB04000C, 0x00000003);
    WGFX2(gfx++, 0xDB040014, 0x0000FFFD);
    WGFX2(gfx++, 0xDB04001C, 0x0000FFFD);
    WGFX2(gfx++, 0xD9EFFFFF, 0x00000000);
    WGFX2(gfx++, 0xDA380007, (u8 *)&((struct259 *)D_800BE628)[idx].unkB8[(D_800BE9C0 << 6) + 0x48]);
    WGFX2(gfx++, 0xDA380005, ((s32 *)&D_800DC2A0)[D_800BE9C0] + (idx << 6));
    WGFX2(gfx++, 0xEF082C3F, 0x00552230);
    return gfx;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_138520/func_1510B958.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_138520/func_1510B9D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_138520/func_1510BF60.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_138520/func_1510C4AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_138520/func_1510C8A8.s")
