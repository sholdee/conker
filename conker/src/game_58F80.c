#include <ultra64.h>
#include "functions.h"
#include "variables.h"


extern u16 D_800C4ED0[];
typedef struct {
    u8 unk0;
    u8 pad1[0xF];
} D_800C666FEntry;

extern D_800C666FEntry D_800C666F[];
extern void *allocate_memory(s32, s32, s32, s32);
extern void func_1502C608(s32);
extern void func_1502DF38(s32, s32);
extern void func_1502E4C4(s32);
extern void func_1502EAFC(struct127 *);
extern void func_1502EEF4(s32);
extern void func_1502F264(s32);
extern void func_1502FBE8(struct127 *);
extern void func_150345E4(s32);
extern void func_1503A08C(struct127 *);
extern void func_1503A830(struct127 *);
extern void func_1503DF48(s32);
extern void func_150A4B04(struct127 *);
extern void func_1517AD00(s32, s32, s32);

#pragma GLOBAL_ASM("asm/nonmatchings/game_58F80/func_1502BAD0.s")

void func_1502BD84(struct127 *arg0, s32 arg1) {
    arg0->unk1D4 = NULL;
    if (arg0->unk5 == 5) {
        func_1502DF38(arg1, 1);
        return;
    }
    if (arg0->id == 0xFF) {
        return;
    }
    if (arg0->unk5 == 3) {
        return;
    }
    if (arg0->unk5 == 2) {
        func_1502C608(arg1);
        return;
    }
    if (arg0->unk1C9 != 0) {
        func_1502FBE8(arg0);
    }
    func_1502E4C4(arg1);
    func_1502DF38(arg1, 0);
    func_1503A08C(arg0);
    if (arg0->unk1D4 == NULL) {
        arg0->unk1FC = 2;
    } else {
        func_150345E4(arg1);
        func_1503A830(arg0);
    }
    if (D_800C666F[arg1].unk0 != 0) {
        func_1503DF48(arg1);
    }
    if (arg0->interaction_state != 0) {
        func_1502EEF4(arg1);
        func_1502F264(arg1);
        if (*(u8 *)((u8 *)arg0 + 0xA4) != 0) {
            func_1502EAFC(arg0);
        }
        if ((arg0->unkF8 & 0x4000) != 0) {
            func_150A4B04(arg0);
        }
        if (*(s32 *)((u8 *)arg0 + 0x260) != 0) {
            func_1517AD00(*(u8 *)((u8 *)arg0 + 0x134), *(u8 *)((u8 *)arg0 + 0x135), arg1);
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_58F80/func_1502BEE4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_58F80/func_1502C1A4.s")

extern s32 D_800C3E88;
extern s32 D_800C3E8C;
extern u16 D_800C3E7A;

void func_1502C380(void) {
    D_800C3E8C = D_800C3E88 = (&D_800C3E80)[D_800BE9C0];
    D_800C3E7A = 0;
}

extern u8 D_800CC406[];

s32 func_1502C3BC(s32 arg0) {
    s32 temp = D_800CC406[arg0 * 0x32C];

    if (temp >= 0x46) {
        temp = 0xB;
    }
    return temp;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_58F80/func_1502C408.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_58F80/func_1502C608.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_58F80/func_1502C6E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_58F80/func_1502C974.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_58F80/func_1502CC34.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_58F80/func_1502CCFC.s")

void func_1502D54C(s32 arg0, s32 *arg1) {
    u8 *temp_v0;

    temp_v0 = (u8 *)&D_800CC2D0[arg0];
    if ((temp_v0[0x66] & 0xC) == 4) {
        arg1[0] = (temp_v0[0x1E0] + temp_v0[0x1DD]) / 2;
        arg1[1] = (temp_v0[0x1E1] + temp_v0[0x1DE]) / 2;
        arg1[2] = (temp_v0[0x1E2] + temp_v0[0x1DF]) / 2;
        arg1[0] = 0xFF - arg1[0];
        arg1[1] = 0xFF - arg1[1];
        arg1[2] = 0xFF - arg1[2];
        return;
    }
    arg1[2] = 0xFF;
    arg1[1] = 0xFF;
    arg1[0] = 0xFF;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_58F80/func_1502D630.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_58F80/func_1502D824.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_58F80/func_1502DB20.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_58F80/func_1502DB84.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_58F80/func_1502DF38.s")

extern u8 D_800C3E90;
extern void func_150A9984(s32, s32);

void func_1502E474(void) {
    if (D_800C3E7A != 0) {
        func_150A9984((&D_800C3E80)[D_800BE9C0], D_800C3E7A);
    }
    D_800C3E90 = 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_58F80/func_1502E4C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_58F80/func_1502E9FC.s")

void func_1502EA0C(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    arg0[0xA4] = 4;
    arg0[0xA5] = 0;
    arg0[0xA6] = arg5;
    *(u32 *)(arg0 + 0xA0) = (arg4 << 24) | (arg1 << 16) | (arg2 << 8) | arg3;
    arg0[0xA7] = 0xFF;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_58F80/func_1502EA50.s")

void func_1502EA60(u8 *arg0, s32 arg1) {
    arg0[0xA4] = 2;
    arg0[0xA5] = 0xFF;
    arg0[0xA6] = arg1;
}

void func_1502EA7C(u8 *arg0, s32 arg1) {
    arg0[0xA4] = 3;
    arg0[0xA5] = 0xFF;
    arg0[0xA6] = arg1;
}

void func_1502EA98(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    if (arg0[0xA4] != 6 && arg0[0xA4] != 7) {
        if (arg5 != 0) {
            arg0[0xA5] = 0xFF;
        } else {
            arg0[0xA5] = 0;
        }
        *(u32 *)(arg0 + 0xA0) = (arg4 << 24) | (arg1 << 16) | (arg2 << 8) | arg3;
        arg0[0xA6] = arg6;
    }
    arg0[0xA4] = 6;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_58F80/func_1502EAFC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_58F80/func_1502EC34.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_58F80/func_1502EE8C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_58F80/func_1502EEF4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_58F80/func_1502F01C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_58F80/func_1502F264.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_58F80/func_1502F3C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_58F80/func_1502F490.s")

void func_1502F948(u8 *arg0) {
    s32 idx;
    void *temp;

    if ((*(u32 *)(arg0 + 0xF8) & 0x4000) && (*(void **)(arg0 + 0x264) != 0) && (*(void **)(arg0 + 0x1D4) != 0)) {
        idx = arg0[4];
        if (*(void **)(arg0 + 0x1D8) == 0) {
            temp = allocate_memory(D_800C4ED0[idx] << 6, 1, 1, 2);
            *(void **)(arg0 + 0x1D8) = temp;
            if (temp == 0) {
                return;
            }
        }
        bcopy(*(void **)(arg0 + 0x1D4), *(void **)(arg0 + 0x1D8), D_800C4ED0[idx] << 6);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_58F80/func_1502F9FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_58F80/func_1502FBE8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_58F80/func_1502FD70.s")
