#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_1B6DB0/func_15189900.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1B6DB0/func_15189A00.s")

typedef struct {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
} Struct15189EBC_elem;

typedef struct {
    u8 unk0[0x1];
    u8 unk1;
    u8 pad2[0xA];
    u8 unkC;
    u8 padD[0x20];
    s8 unk2D;
    u8 pad2E[0x66];
    Struct15189EBC_elem *unk94;
    u8 *unk98;
} Struct15189EBC;

typedef struct {
    f32 unk0;
    u8 pad4[0x4];
    u8 unk8;
} Struct15189EBC_sub;

typedef struct {
    f32 unk0;
    u8 pad4[0x17];
    u8 unk1B;
    u8 pad1C[0x4];
    u8 unk20;
    u8 pad21[0x27];
    Struct15189EBC_sub unk48;
} Struct15189EBC_v1;

extern f64 D_800A73A8;
extern f32 D_800A73B0;
extern s32 func_151D8E20(void);
void func_151DBCBC(u8 arg0, f32 arg1, s16 arg2, s32 arg3, void *arg4, u8 arg5, s32 arg6);
f32 func_150ADA68(void);

s32 func_15189EBC(Struct15189EBC *arg0) {
    f64 tmp;
    Struct15189EBC_v1 *v1 = (Struct15189EBC_v1 *)arg0->unk98;
    Struct15189EBC_elem *base = arg0->unk94;
    struct17 sp34;

    if (base[arg0->unk2D].unk4 < v1->unk48.unk0) {
        tmp = func_150ADA68();
        if (tmp < D_800A73A8) {
            sp34.unk0 = base[arg0->unk2D].unk0;
            sp34.unk4 = v1->unk48.unk0;
            sp34.unk8 = base[arg0->unk2D].unk8;
            func_151DBCBC((u8)func_151D8E20(), v1->unk0 * 6.0f, v1->unk1B, 0, &sp34, arg0->unkC, arg0->unk1);
        }
        v1->unk20 = 4;
        v1->unk48.unk0 = D_800A73B0;
    }
    return 1;
}

s32 func_15189FD0(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 *p = &arg0;
    return 1;
}
