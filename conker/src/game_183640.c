#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_183640/func_15156190.s")

extern void func_15156190(void *arg0, u8 arg1, s32 arg2, s32 arg3, s32 arg4);

void func_15156388(void *arg0, u8 arg1, s32 arg2) {
    func_15156190(arg0, arg1, arg2, 0xFF, 0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_183640/func_151563B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_183640/func_151564F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_183640/func_151568F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_183640/func_15156B54.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_183640/func_15156D24.s")

extern void func_151D5E30(void *);

void func_15156F94(void *arg0) {
    func_151D5E30((void *)((u8 *)arg0 + 0x88));
}

void func_15156FB8(struct102 *arg0) {
    func_15156F94(arg0);
    func_15169804(arg0);
}

void func_15156FE4(struct102 *arg0) {
    func_15156F94(arg0);
    func_15169824(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_183640/func_15157010.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_183640/func_151571C4.s")

extern void func_151571C4(void *);
extern void func_1518CA04(void *);
extern void func_1503F7B8(void *);

void func_15157248(u8 *arg0) {
    func_151571C4(arg0);
    func_1518CA04(*(void **)(arg0 + 0x18));
    func_1503F7B8(*(void **)(arg0 + 0x68));
    func_15169804(arg0);
}

void func_1515728C(u8 *arg0) {
    func_151571C4(arg0);
    func_1518CA04(*(void **)(arg0 + 0x18));
    func_1503F7B8(*(void **)(arg0 + 0x68));
    func_15169824(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_183640/func_151572D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_183640/func_15157420.s")

extern u8 D_800BE9C0;
extern void guMtxIdentF(float mf[4][4]);

s32 func_15157860(u8 *arg0) {
    guMtxIdentF((float (*)[4])(arg0 + 0x7C + (D_800BE9C0 << 6)));
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_183640/func_15157898.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_183640/func_15157918.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_183640/func_15157AA8.s")

void func_15157D88(s32 arg0, s32 arg1, u8 arg2) {
    func_15169850(arg1, arg2, arg0 + 0x4C, arg0 + 0x50, arg0);
}

extern void func_15157DEC(void *, void *);

s32 func_15157DC8(void *arg0) {
    func_15157DEC(arg0, (void *)((u8 *)arg0 + 0x120));
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_183640/func_15157DEC.s")

extern Mtx D_80089470;

Gfx *func_15157F80(Gfx *pkt, s32 arg1, s32 arg2, s32 arg3, u8 *arg4) {
    gSPMatrix(pkt++, &D_80089470, G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_NOPUSH);
    gSPMatrix(pkt++, &((Mtx *)D_800DCC10)[arg2], G_MTX_PROJECTION | G_MTX_LOAD | G_MTX_NOPUSH);
    *arg4 = 1;
    return pkt;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_183640/func_15157FE8.s")

extern s32 D_800A6060;

void func_15158078(s32 arg0, u8 arg1) {
    func_15169260((s32)&D_800A6060, 3, arg0, arg1);
}
