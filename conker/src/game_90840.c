#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern s16 D_800CC2B2;
s16 func_15063390(struct127 *arg0);
void func_15143134(void *, f32 *, s32);
void func_1506AC8C(struct127 *, s32, void *);

struct func_15063B64_sp28 {
    struct127 *unk0;
    f32 unk4[3];
    s32 unk10;
    volatile s32 unk14;
};

#pragma GLOBAL_ASM("asm/nonmatchings/game_90840/func_15063390.s")

void func_15063404(struct127 *arg0) {
    struct127 *temp = &D_800CC2D0[arg0 - D_800CC2D0];
    temp->unk31C->unk78 = 0x9;
    func_15083568(arg0, 0x1D, 1.0f, 0);
    func_15083568(arg0, 0x1E, 1.0f, 0);
    arg0->disable_jump = 0x14;
    arg0->disable_run = 0;
    arg0->unk83 = 0;
    *(s16 *)((u8 *)temp->unk31C + 0x24) = 0x3C;
    temp->unk31C->unk11A = 2;
    func_1505E650(arg0, 0x7F, 1.0f, 0.0f, 0.0f, 0.0f, 0);
}

void func_150836CC(struct127 *arg0, s32 arg1);

void func_150634E4(struct127 *arg0) {
    D_800CC2D0[arg0 - D_800CC2D0].unk31C->unk78 = 0;
    D_800CC2D0[arg0 - D_800CC2D0].unk31C->unk11A = 0;
    func_150836CC(arg0, 0x1D);
    func_150836CC(arg0, 0x1E);
    arg0->disable_jump = 0;
    arg0->disable_run = 0;
    arg0->unk83 = 0;
}

void func_15063570(struct127 *arg0) {
    D_800CC2D0[arg0 - D_800CC2D0].unk31C->unk78 = 0x3B;
    D_800CC2D0[arg0 - D_800CC2D0].unk31C->unk11A = 2;
    func_15083568(arg0, 0x89, 1.0f, 0);
    arg0->disable_jump = 0x14;
    arg0->disable_run = 0;
    arg0->unk83 = 0;
    func_1505E650(arg0, 0x221, 1.0f, 0.0f, 0.0f, 0.0f, 0);
}

struct s15063628 {
    u8  pad0[0xB0];
    s32 unkB0;
    u8  padB4[0x130 - 0xB4];
    f32 unk130;
    f32 unk134;
    f32 unk138;
    f32 unk13C;
    f32 unk140;
    s32 unk144;
};

void func_15081690(s32, f32, f32, s32, f32, f32, f32, s32, f32, s32, s32, s32, s32, s32, s32);
void func_150636A4(struct127 *arg0);

void func_15063628(struct127 *arg0, f32 arg1) {
    struct s15063628 *p = (struct s15063628 *)arg0->unk31C;

    func_15081690(arg0, p->unk13C, p->unk140, p->unk144,
                  p->unk130, p->unk134, p->unk138, (s32)&p->unkB0,
                  arg1, 0, 0, 0, -1, 0, 0);
    func_150636A4(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_90840/func_150636A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_90840/func_150636F0.s")

s32 func_150639BC(struct127 *arg0) {
    D_800CC2B2 = arg0->unk7A - arg0->unk31C->unk12 - func_15063390(arg0);
    if (D_800CC2B2 > 0x3E80) {
        D_800CC2B2 = 0x3E80;
    }
    if (D_800CC2B2 < -0x3E80) {
        D_800CC2B2 = -0x3E80;
    }
    return D_800CC2B2;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_90840/func_15063A38.s")

void func_15063B64(struct127 *arg0) {
    struct func_15063B64_sp28 sp28;

    if ((arg0->id == 0x75) || (arg0->id == 0xB1)) {
        sp28.unk14 = 0x64;
    } else {
        sp28.unk14 = 0x2C;
    }

    if (func_1503195C(arg0, sp28.unk14, 0) != 0) {
        if (arg0->unk1D4 != 0) {
            func_15143134(0, sp28.unk4, (s32)arg0->unk1D4 + 0x100);
        } else {
            sp28.unk4[0] = arg0->x_position;
            sp28.unk4[1] = arg0->y_position;
            sp28.unk4[2] = arg0->z_position;
        }

        sp28.unk10 = ((s32)arg0 - (s32)D_800CC2D0) / (s32)sizeof(struct127) + 1;
        sp28.unk0 = arg0;
        func_1506AC8C(arg0, 0xB, &sp28);
        func_150836CC(arg0, sp28.unk14);

        if (arg0->unk31C->grenade_count != 0) {
            arg0->unk31C->grenade_count--;
        }
        arg0->unk31C->unk11A = 0;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_90840/func_15063C60.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_90840/func_15063E84.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_90840/func_15063FA0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_90840/func_150641D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_90840/func_150642AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_90840/func_150649A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_90840/func_15064A14.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_90840/func_15064B94.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_90840/func_15065A5C.s")
