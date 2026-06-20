#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_CDE80/func_150A09D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_CDE80/func_150A0D14.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_CDE80/func_150A0D8C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_CDE80/func_150A1040.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_CDE80/func_150A104C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_CDE80/func_150A11C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_CDE80/func_150A1DA0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_CDE80/func_150A23E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_CDE80/func_150A24C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_CDE80/func_150A25D4.s")

s32 func_150A1DA0(u8 *arg0, struct178 *arg1, s32 arg2);
void func_15172E7C(u8 *arg0, s32 arg1, s32 arg2);

void func_150A278C(u8 *arg0) {
    struct178 *base;
    s32 i;

    if (arg0[0x65] != 0) {
        return;
    }
    for (i = 0; i < (u32)D_800D3094; i++) {
        struct178 *p;
        base = (struct178 *)*(s32 *)&D_800D3098;
        if (8 == (s32)base[i].unk6[0xF] >> 2) {
            if (func_150A1DA0(arg0, &base[i], 0) == 0) {
                p = (struct178 *)*(s32 *)&D_800D3098 + i;
                func_15172E7C(arg0, p->unk6[0x11], *(s32 *)&p->unk6[0x12]);
            }
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_CDE80/func_150A2864.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_CDE80/func_150A2940.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_CDE80/func_150A29C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_CDE80/func_150A2AEC.s")

extern u64 D_800D30F0[][3];

s32 func_150A2CA4(u32 arg0) {
    s32 i;

    arg0 &= 0xFFF;
    if ((u32)D_800D3094 < arg0) {
        return -1;
    }
    for (i = 0; i != 0x10; i++) {
        if (*(u16 *)((u8 *)&D_800D2138 + 0x208) & (1 << i)) {
            if ((D_800D30F0[i][arg0 >> 6] >> (arg0 & 0x3F)) & 1) {
                return i;
            }
        }
    }
    return -1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_CDE80/func_150A2D84.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_CDE80/func_150A2E4C.s")

s32 func_150A2E4C(struct178 *arg0, f32 x, f32 y, f32 z);

s32 func_150A2EE4(s32 a0, s32 a1) {
    struct178 *base;
    s32 ret;

    a1 &= 0xFFF;
    if ((u32)D_800D3094 < (u32)a1) {
        return 1;
    }
    base = (struct178 *)*(s32 *)&D_800D3098;
    ret = 0;
    if ((base[a1].unk6[0xF] & 3) == 3) {
        return func_150A2E4C(base + a1, D_800CC2D0[a0].x_position, D_800CC2D0[a0].y_position, D_800CC2D0[a0].z_position);
    }
    return ret;
}

s32 func_150A2FA4(s32 a0, s32 a1) {
    struct178 *base;
    struct108 *p;
    s32 ret;

    p = &D_800DBFF0[a0];
    a1 &= 0xFFF;
    if ((u32)D_800D3094 < (u32)a1) {
        return 1;
    }
    ret = 0;
    if (((base = (struct178 *)*(s32 *)&D_800D3098)[a1].unk6[0xF] & 3) == 3) {
        return func_150A2E4C(base + a1, p->unk2F8, p->unk2FC, p->unk300);
    }
    return ret;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_CDE80/func_150A3058.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_CDE80/func_150A3194.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_CDE80/func_150A32B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_CDE80/func_150A3330.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_CDE80/func_150A3398.s")

void func_150A3444(s32 a0, s16 a1, s16 a2, s16 a3) {
    ((struct178 *)*(s32 *)&D_800D3098)[a0].unk0 = a1;
    *(s16 *)&((struct178 *)*(s32 *)&D_800D3098)[a0].pad2 = a2;
    ((struct178 *)*(s32 *)&D_800D3098)[a0].unk4 = a3;
}

s32 func_150A3504(void);

s32 func_150A34B0(u8 *arg0) {
    s32 ret;

    if (arg0[0x14] == 1) {
        return 0;
    }

    ret = 0;
    if (!(arg0[0x15] & 3)) {
        return func_150A3504();
    }
    return ret;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_CDE80/func_150A3504.s")
