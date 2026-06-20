#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_A9260/func_1507BDB0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_A9260/func_1507C22C.s")

void func_1507C324(void *arg0, void *arg1) {
    s32 *p0 = *(s32 **)((u8 *)arg0 + 0x2D0);
    s32 *p1 = *(s32 **)((u8 *)arg1 + 0x2D0);
    f32 temp;

    if (p0 != 0 && p1 != 0) {
        *(f32 *)((u8 *)p0 + 0x8) = *(f32 *)((u8 *)p1 + 0x8);
        temp = *(f32 *)((u8 *)p0 + 0x18) - 1.0f;
        if (temp <= *(f32 *)((u8 *)p0 + 0x8)) {
            *(f32 *)((u8 *)p0 + 0x8) = temp;
        }
    }
}

void func_1507C3E0(struct127 *arg0, s16 *arg1, s16 *arg2, s16 *arg3);

void func_1507C370(void) {
    s32 i;
    struct127 *obj = D_800CC2D0;

    for (i = 0; i < D_8008FD8C; i++, obj++) {
        struct126 *p = obj->unk31C;
        if (p != NULL) {
            func_1507C3E0(obj, (s16 *)((u8 *)p + 0x114), (s16 *)((u8 *)p + 0x116), (s16 *)((u8 *)p + 0x118));
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_A9260/func_1507C3E0.s")
