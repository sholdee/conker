#include <ultra64.h>
#include "functions.h"
#include "variables.h"

typedef struct {
    u8 pad0[0x18];
    s32 unk18;
    s32 unk1C;
    u8 pad20[0x48];
    s32 unk68;
    s32 unk6C;
    s32 unk70;
    s32 unk74;
    s32 unk78;
    f32 unk7C[4][4];
    f32 unkBC[4][4];
    s32 unkFC;
    u8 unk100;
    u8 pad101[0x3];
    s32 unk104[4];
    s32 unk114;
    s32 unk118;
} struct15157010;

extern struct15157010 *func_15167A68(s32, s32, s32, s32, s32, s32);
extern void func_1503F62C(s32, s32, s32 *, s32 *, s32 *, s32 *, s32 *);
extern void func_1503F5B8(s32, s32, s32, f32, f32, s32);
extern void guMtxIdentF(float mf[4][4]);
extern s32 func_1515D480(s32);
extern s32 func_1515D440(void);


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

struct15157010 *func_15157010(u8 *arg0, s32 arg1, f32 arg2, s32 arg3, s32 arg4, s32 arg5, u8 arg6, s32 arg7) {
    struct15157010 *temp_v0;
    f32 (*mtx1)[4];
    f32 (*mtx2)[4];
    s32 phi_v0;
    s32 i;

    phi_v0 = 0x36;
    if (arg0[0] & 0x80) {
        phi_v0 = 0x5B;
    } else if (arg0[0] & 0x10) {
        phi_v0 = 0x4C;
    }
    temp_v0 = func_15167A68(phi_v0, arg7, arg5 + 0x120, 1, arg6, 1);
    if (temp_v0 == 0) {
        return NULL;
    }
    memcpy(&temp_v0->pad0[0x10], arg0, 0x58);
    func_1503F62C(temp_v0->unk18, temp_v0->unk1C, &temp_v0->unk6C, &temp_v0->unk70, &temp_v0->unk74, &temp_v0->unk78, &temp_v0->unk68);
    mtx1 = temp_v0->unk7C;
    guMtxIdentF(mtx1);
    mtx2 = temp_v0->unkBC;
    guMtxIdentF(mtx2);
    *(f32 (**) [4]) (temp_v0->unk68 + 0x3E0) = mtx1;
    *(f32 (**) [4]) (temp_v0->unk68 + 0x3E4) = mtx2;
    func_1503F5B8(temp_v0->unk68, 1, arg1, arg2, 0.0f, 0);
    temp_v0->unkFC = arg3;
    temp_v0->unk118 = arg4;
    temp_v0->unk100 = 0;
    for (i = 0; i < 4; i++) {
        temp_v0->unk104[i] = 0;
    }

    temp_v0->unk114 = 0;
    if (arg3) {
        for (i = 0; i <= D_80082FA0; i++) {
            temp_v0->unk104[i] = func_1515D480(arg3);
        }
        temp_v0->unk114 = func_1515D440();
    }
    return temp_v0;
}

void func_100043B4(s32 *arg0, u32 arg1);
extern s32 D_80082FA0;
void func_151571C4(void *arg0)
{
  s32 i;
  s32 *p;
  for (i = 0, p = (s32 *) arg0; i <= D_80082FA0; i++, p++)
  {
    if (p[0x41] != 0)
    {
      func_100043B4((s32 *) p[0x41], 4);
    }
  }

  p = (s32 *) ((s32 *) arg0)[0x45];
  if (((s32 *) arg0)[0x45] != 0)
  {
    func_100043B4(p, 4);
  }
}

extern void func_151571C4(void *);


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

s32 func_15157918(u8 *arg0) {
    f32 *arg1;

    arg1 = (f32 *)(arg0 + 0x120);
    func_150A8050((f32 (*)[4])(arg0 + 0x7C + (D_800BE9C0 << 6)), arg1[0], arg1[1], arg1[2]);
    ((f32 (*)[4])(arg0 + 0x7C + (D_800BE9C0 << 6)))[3][0] = *(f32 *)(arg0 + 0x54);
    ((f32 (*)[4])(arg0 + 0x7C + (D_800BE9C0 << 6)))[3][1] = *(f32 *)(arg0 + 0x58);
    ((f32 (*)[4])(arg0 + 0x7C + (D_800BE9C0 << 6)))[3][2] = *(f32 *)(arg0 + 0x5C);
    ((f32 (*)[4])(arg0 + 0x7C + (D_800BE9C0 << 6)))[0][0] *= arg1[3];
    ((f32 (*)[4])(arg0 + 0x7C + (D_800BE9C0 << 6)))[0][1] *= arg1[3];
    ((f32 (*)[4])(arg0 + 0x7C + (D_800BE9C0 << 6)))[0][2] *= arg1[3];
    ((f32 (*)[4])(arg0 + 0x7C + (D_800BE9C0 << 6)))[1][0] *= arg1[3];
    ((f32 (*)[4])(arg0 + 0x7C + (D_800BE9C0 << 6)))[1][1] *= arg1[3];
    ((f32 (*)[4])(arg0 + 0x7C + (D_800BE9C0 << 6)))[1][2] *= arg1[3];
    ((f32 (*)[4])(arg0 + 0x7C + (D_800BE9C0 << 6)))[2][0] *= arg1[3];
    ((f32 (*)[4])(arg0 + 0x7C + (D_800BE9C0 << 6)))[2][1] *= arg1[3];
    ((f32 (*)[4])(arg0 + 0x7C + (D_800BE9C0 << 6)))[2][2] *= arg1[3];
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_183640/func_15157AA8.s")

void func_15157D88(s32 arg0, s32 arg1, u8 arg2) {
    func_15169850(arg1, arg2, arg0 + 0x4C, arg0 + 0x50, arg0);
}

extern void func_15157DEC(u8 *, f32 *);

s32 func_15157DC8(void *arg0) {
    func_15157DEC(arg0, (void *)((u8 *)arg0 + 0x120));
    return 1;
}

void func_15157DEC(u8 *arg0, f32 *arg1) {
    func_150A8050((f32 (*)[4])(arg0 + 0x7C + (D_800BE9C0 << 6)), arg1[0], arg1[1], arg1[2]);
    ((f32 (*)[4])(arg0 + 0x7C + (D_800BE9C0 << 6)))[3][0] = *(f32 *)(arg0 + 0x54);
    ((f32 (*)[4])(arg0 + 0x7C + (D_800BE9C0 << 6)))[3][1] = *(f32 *)(arg0 + 0x58);
    ((f32 (*)[4])(arg0 + 0x7C + (D_800BE9C0 << 6)))[3][2] = *(f32 *)(arg0 + 0x5C);
    ((f32 (*)[4])(arg0 + 0x7C + (D_800BE9C0 << 6)))[0][0] *= arg1[3];
    ((f32 (*)[4])(arg0 + 0x7C + (D_800BE9C0 << 6)))[0][1] *= arg1[3];
    ((f32 (*)[4])(arg0 + 0x7C + (D_800BE9C0 << 6)))[0][2] *= arg1[3];
    ((f32 (*)[4])(arg0 + 0x7C + (D_800BE9C0 << 6)))[1][0] *= arg1[4];
    ((f32 (*)[4])(arg0 + 0x7C + (D_800BE9C0 << 6)))[1][1] *= arg1[4];
    ((f32 (*)[4])(arg0 + 0x7C + (D_800BE9C0 << 6)))[1][2] *= arg1[4];
    ((f32 (*)[4])(arg0 + 0x7C + (D_800BE9C0 << 6)))[2][0] *= arg1[3];
    ((f32 (*)[4])(arg0 + 0x7C + (D_800BE9C0 << 6)))[2][1] *= arg1[3];
    ((f32 (*)[4])(arg0 + 0x7C + (D_800BE9C0 << 6)))[2][2] *= arg1[3];
}

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
