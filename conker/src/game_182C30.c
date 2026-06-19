#include <ultra64.h>
#include "functions.h"
#include "variables.h"


extern void *func_15167A68(s32, s32, s32, s32, s32, s32);
void func_1518C900(s32);

void *func_15155780(s32 arg0, s32 arg1) {
    u8 *temp_v0;

    temp_v0 = (u8 *)func_15167A68(0x50, 0, 0xA0, 1, arg1, 1);
    if (temp_v0 == 0) {
        return temp_v0;
    }
    temp_v0[0x10] = arg0;
    *(f32 *)(temp_v0 + 0x98) = 0.0f;
    temp_v0[0x11] = 0;
    *(s32 *)(temp_v0 + 0x14) = 0;
    func_1518C900(0xA6);
    return temp_v0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_182C30/func_151557FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_182C30/func_1515589C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_182C30/func_15155CFC.s")

void func_1515F10C(struct226 *arg0, struct225 *arg1);
void func_1518CA04(s32 arg0);

void func_15155EF8(struct225 *arg0) {
    if (arg0->unk14 != NULL) {
        func_1515F10C(arg0->unk14, arg0);
    }
    func_15169804((struct102 *)arg0);
    func_1518CA04(0xA6);
}

extern u8 *func_15155FD4(u8 arg0);

void func_15155F3C(void) {
    u8 *temp_v0 = func_15155FD4(D_800C3E78);
    if (temp_v0 != NULL) {
        if (temp_v0[0x11] == 2) {
            temp_v0[0x11] = 0;
        } else if (temp_v0[0x11] == 3) {
            temp_v0[0x11] = 2;
        }
    }
}


void func_15155F90(void) {
    u8 *temp_v0 = func_15155FD4(D_800C3E78);
    if (temp_v0 != NULL) {
        if (temp_v0[0x11] == 3) {
            temp_v0[0x11] = 1;
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_182C30/func_15155FD4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_182C30/func_15156028.s")
