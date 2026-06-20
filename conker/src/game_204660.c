#include <ultra64.h>
#include "functions.h"
#include "variables.h"


struct260 *func_151D71B0(s16 arg0, u8 arg1, u8 arg2, f32 arg3, void *arg4, u8 arg5, s32 arg6) {
    struct260 *temp_v0;
    struct {
        s32 unk0;
        u8 unk4;
        u8 unk5;
        u8 pad6;
        u8 pad7;
        f32 unk8;
        f32 unkC;
        f32 unk10;
        f32 unk14;
    } sp34;

    sp34.unk0 = 0;
    sp34.unk4 = arg2;
    sp34.unk5 = 0;
    sp34.unk8 = 0.0f;
    sp34.unkC = 0.0f;
    sp34.unk10 = 0.0f;
    sp34.unk14 = arg3;

    temp_v0 = func_15149130(arg0, -1, 0x42, -1, arg1, 0x36, (struct37 *)((s32)arg4 + 0x18), arg5, arg6);
    if (temp_v0 != NULL) {
        memcpy((void *)((s32)temp_v0 + 0x28), &sp34, 0x18);
    }
    return temp_v0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_204660/func_151D7264.s")

extern void (*D_8008FCA4[])(s32 *, s32, u8);

void func_151D73A8(s32 *arg0, s32 arg1, u8 arg2) {
    if (D_8008FCA4[*(u8 *)((s32)arg0 + 0x2C)] != 0) {
        D_8008FCA4[*(volatile u8 *)((s32)arg0 + 0x2C)](arg0, arg1, arg2);
    }
}

void func_151D77C8();

void func_151D7404(void) {
    func_151D77C8();
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_204660/func_151D7424.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_204660/func_151D7450.s")

void func_151D747C(s32 arg0) {
    struct {
        s32 unk0;
        u8 unk4;
    } sp18;

    sp18.unk0 = arg0;
    sp18.unk4 = *(u8 *)(arg0 + 0x3B);
    func_151494E0((s32)&sp18, 0x3D);
}

void func_151D74B0(struct struct127 *arg0, u8 arg1, s8 arg2, u8 arg3, void *arg4) {
    struct {
        s32 unk0;
        u8 unk4;
        u8 unk5;
        u8 unk6;
    } sp30;
    struct260 *temp_v0;

    sp30.unk0 = (s32)arg0;
    sp30.unk4 = arg0->unique_id;
    sp30.unk5 = arg1;
    sp30.unk6 = arg2;

    temp_v0 = func_151D71B0(0x12C, 0, 0, 12.0f, (void *)8, arg3, (s32)arg4);
    if (temp_v0 != NULL) {
        memcpy((void *)((s32)temp_v0 + 0x40), &sp30, 8);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_204660/func_151D7538.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_204660/func_151D75C4.s")

s32 func_151D7724(s32 *arg0) {
    s32 *v0 = (s32 *)arg0[0x40 / 4];
    u8 *p = (u8 *)arg0 + 0x28;
    u16 type;

    if (!(v0[0x94 / 4] & 2)) {
        type = *(u16 *)((u8 *)v0 + 0x84);
        if (type != 4 && type != 0xA && type != 0xC) {
            goto done;
        }
    }
    p[5] &= ~1;
done:
    return 1;
}

s32 func_151D7770(s32 *arg0) {
    u8 *p = (u8 *)arg0 + 0x28;
    s32 *v = (s32 *)arg0[0x40 / 4];
    if (*(u16 *)((u8 *)v + 0x84) == 0) {
        p[5] &= ~1;
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_204660/func_151D779C.s")

void func_151D77C8(s32 *arg0) {
    s32 **p = (s32 **)((u8 *)arg0 + 0x28);

    if (*p != 0) {
        s32 *v1 = (s32 *)(*p)[0x98 / 4];
        *(u8 *)((u8 *)*p + 0x30) = 0;
        *(u16 *)((u8 *)*p + 0x1E) &= ~2;
        *(u16 *)((u8 *)*p + 0x1E) |= 8;
        *(u16 *)((u8 *)*p + 0x1E) |= 1;
        *(u16 *)((u8 *)*p + 0x1C) = 0x14;
        *v1 = 0;
        *p = 0;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_204660/func_151D7830.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_204660/func_151D792C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_204660/func_151D7A38.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_204660/func_151D7CD0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_204660/func_151D80C4.s")

extern f32 D_800AB2EC;
extern f32 D_800AB2F0;

void func_151D8718(f32 *arg0, f32 *arg1, f32 arg2) {
    f32 v = arg1[0];
    arg1[0] += D_800AB2EC * arg2;
    arg0[1] += v * arg2 + D_800AB2F0 * (arg2 * arg2);
}

void func_151D8764(s32 *arg0) {
    s32 *temp = (s32 *)arg0[0x98 / 4];
    s32 *temp2 = (s32 *)temp[0];
    if (temp2 != 0) {
        temp2[0x28 / 4] = 0;
    }
}

extern void func_151478F4(s32 *arg0);

void func_151D8780(s32 *arg0) {
    func_151D8764(arg0);
    func_151478F4(arg0);
}

extern void func_15147928(s32 *arg0);

void func_151D87AC(s32 *arg0) {
    func_151D8764(arg0);
    func_15147928(arg0);
}
