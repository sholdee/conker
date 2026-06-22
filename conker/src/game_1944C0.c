#include <ultra64.h>

#include "functions.h"
#include "variables.h"

extern void (*D_8008CA20[])(struct102 *);
extern void (*D_8008C9C8[])(struct102 *);

struct Some15171F04 {
    u8 pad0[4];
    u8 unk4;
    u8 pad5;
    u16 unk6;
    u16 unk8;
};

extern struct Some15171F04 *D_8008CA4C[];

#pragma GLOBAL_ASM("asm/nonmatchings/game_1944C0/func_15167010.s")
// NON-MATCHING: not hugely far away
// void func_15167010(void) {
//     void (*func)(void);
//     s32 i;
//
//     for (i = 0; i < 24; i++)
//     {
//         func = D_8008B4A8[i].unk18;
//         if (func != NULL) {
//             func();
//         }
//     }
// }

#pragma GLOBAL_ASM("asm/nonmatchings/game_1944C0/func_1516706C.s")
#pragma GLOBAL_ASM("asm/nonmatchings/game_1944C0/func_151670C0.s")
#pragma GLOBAL_ASM("asm/nonmatchings/game_1944C0/func_151671E8.s")
#pragma GLOBAL_ASM("asm/nonmatchings/game_1944C0/func_15167310.s")
#pragma GLOBAL_ASM("asm/nonmatchings/game_1944C0/func_151674F8.s")
void func_15168A4C(s32 *arg0, s32 arg1);

s32 func_15167A68(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    s32 temp;

    temp = func_10003C6C(arg2, 1, arg3, 0, (u8)arg5);
    if (temp != 0) {
        *(u8 *)(temp + 1) = arg1;
        func_15168A4C((s32 *)temp, arg0);
        *(u8 *)(temp + 0xC) = *((u8 *)&arg4 + 3);
    }
    return temp;
}

void func_15167AD8(s32 arg0, s32 arg1, s32 arg2) {
    s32 temp;

    temp = func_15167A68(3, arg2, 0x28, 0, (u8)arg1, 1);
    if (temp != 0) {
        bcopy(arg0, (void *)(temp + 0x10), 0x18);
        *(u8 *)(temp + 0x23) = 0xFF;
    }
}
void func_15167B44(struct102 *arg0) {
    s32 temp_v0;
    s32 temp_v1;
    s32 temp_a1;
    s32 temp_a2;

    temp_v0 = *(u8 *)((u8 *)arg0 + 0x24);
    if (temp_v0 != 0) {
        D_8008CA20[temp_v0](arg0);
    }

    temp_v1 = *(s8 *)((u8 *)arg0 + 0x22);
    if (temp_v1 > 0) {
        temp_v0 = *(u8 *)((u8 *)arg0 + 0x23);
        if (temp_v1 < temp_v0) {
            *(u8 *)((u8 *)arg0 + 0x23) = temp_v0 - temp_v1;
        } else {
            *(s16 *)((u8 *)arg0 + 0x14) = *(u8 *)(*(s32 *)((u8 *)arg0 + 0x10) + 4) << 8;
        }
    } else if (temp_v1 < 0) {
        temp_a1 = -temp_v1;
        temp_a2 = *(s16 *)((u8 *)arg0 + 0x14);
        if ((temp_a2 / 0x100) >= (*(u8 *)(*(s32 *)((u8 *)arg0 + 0x10) + 4) - 1)) {
            temp_v0 = *(u8 *)((u8 *)arg0 + 0x23);
            if (temp_a1 < temp_v0) {
                *(u8 *)((u8 *)arg0 + 0x23) = temp_v0 - temp_a1;
                *(s16 *)((u8 *)arg0 + 0x14) = temp_a2 - *(s16 *)((u8 *)arg0 + 0x16);
            }
        }
    }

    *(s16 *)((u8 *)arg0 + 0x14) += *(s16 *)((u8 *)arg0 + 0x16);
    if ((*(s16 *)((u8 *)arg0 + 0x14) / 0x100) >= *(u8 *)(*(s32 *)((u8 *)arg0 + 0x10) + 4)) {
        func_1516972C(arg0);
    }
}
#pragma GLOBAL_ASM("asm/nonmatchings/game_1944C0/func_15167C58.s")
s32 func_15167D84(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    s32 temp;

    temp = func_15167A68((arg1 == 0) ? 5 : 0x42, arg5, arg2 + 0x50, 0, *((u8 *)&arg4 + 3), 1);
    if (temp == 0) {
        return temp;
    }
    bcopy(arg0, (void *)(temp + 0x10), 0x38);
    *(u8 *)(temp + 0x48) = *((s8 *)&arg3 + 3);
    return temp;
}
#pragma GLOBAL_ASM("asm/nonmatchings/game_1944C0/func_15167E0C.s")
#pragma GLOBAL_ASM("asm/nonmatchings/game_1944C0/func_15168118.s")
#pragma GLOBAL_ASM("asm/nonmatchings/game_1944C0/func_1516865C.s")
s32 func_15168800(s32 arg0, s32 arg1, s32 arg2) {
    s32 temp;

    temp = func_15167A68(0xE, arg2, 0xB8, 1, *((u8 *)&arg1 + 3), 1);
    if (temp == 0) {
        return 0;
    }
    bcopy(arg0, (void *)(temp + 0x10), 0xA8);
    return temp;
}
void func_15168870(s32 arg0) {
    s32 temp_v0;
    s32 temp_v1;
    u8 temp_a1;
    s16 temp_a2;
    void (*func)(struct102 *);

    temp_a2 = *(s16 *)(arg0 + 0x9A);
    if (temp_a2 != 0) {
        temp_a1 = D_8008CA4C[*(u8 *)(arg0 + 0xB0)]->unk4;
        temp_v1 = temp_a1;
        temp_v1 <<= 8;
        *(s16 *)(arg0 + 0x98) += temp_a2 * D_800BE9E4;
        temp_v0 = *(s16 *)(arg0 + 0x98);
        temp_v1 -= 1;
        if (temp_v1 < temp_v0) {
            if (*(u16 *)(arg0 + 0xA8) & 0x40) {
                *(s16 *)(arg0 + 0x98) = temp_v1 - (temp_v0 % temp_v1);
                *(s16 *)(arg0 + 0x9A) = -temp_a2;
            } else if (*(u16 *)(arg0 + 0xA8) & 4) {
                *(s16 *)(arg0 + 0x98) = -1;
            } else {
                do {
                    *(s16 *)(arg0 + 0x98) = temp_v0 - temp_v1;
                    temp_v0 = *(s16 *)(arg0 + 0x98);
                } while (temp_v1 < temp_v0);
            }
        } else if (temp_v0 < 0) {
            if (*(u16 *)(arg0 + 0xA8) & 0x40) {
                *(s16 *)(arg0 + 0x98) = -temp_v0 % temp_v1;
                *(s16 *)(arg0 + 0x9A) = -temp_a2;
            } else if (*(u16 *)(arg0 + 0xA8) & 4) {
                *(s16 *)(arg0 + 0x98) = -1;
            } else {
                do {
                    *(s16 *)(arg0 + 0x98) = temp_v0 + temp_v1;
                    temp_v0 = *(s16 *)(arg0 + 0x98);
                } while (temp_v0 < 0);
            }
        }
    }

    temp_v0 = *(s8 *)(arg0 + 0xB2);
    if (temp_v0 != -1) {
        func = D_8008C9C8[temp_v0];
        if (func != NULL) {
            func((struct102 *)arg0);
        }
    }

    if (*(s16 *)(arg0 + 0x98) == -1) {
        func_1516972C((struct102 *)arg0);
    }
}
void func_15168A2C(s32 arg0) {
    func_15168B10(arg0, 0);
}
extern u8 D_800DCE50[];

void func_15168A4C(s32 *arg0, s32 arg1) {
    s32 idx;
    s32 t;
    s32 *temp;

    idx = ((u8 *)arg0)[1];
    temp = (s32 *)(&D_800DCE50[(idx * 0x1A0) + (arg1 * 4)]);
    t = *temp & 0xFFFFFFFFFFFFFFFFu;
    arg0[2] = t;
    if (t != 0) {
        ((s32 *)t)[1] = (s32)arg0;
    }
    ((u8 *)arg0)[0] = (u8)arg1;
    arg0[1] = 0;
    *temp = (s32)arg0;
}
void func_15168A9C(struct12 *arg0) {
    s32 temp_v0 = *((u8 *)arg0 + 1);
    s32 temp_v1 = *(u8 *)arg0;
    u8 *temp_t9 = D_800DCE50;
    struct12 **temp_a1 = (struct12 **)&temp_t9[(temp_v0 * 0x1A0) + (temp_v1 * 4)];
    struct12 *temp_v0_2;

    if (arg0 == *temp_a1) {
        *temp_a1 = *(struct12 **)((s32)arg0 + 8);
    }
    temp_v0_2 = *(struct12 **)((s32)arg0 + 8);
    if (temp_v0_2 != NULL) {
        *(struct12 **)((s32)temp_v0_2 + 4) = *(struct12 **)((s32)arg0 + 4);
    }
    temp_v0_2 = *(struct12 **)((s32)arg0 + 4);
    if (temp_v0_2 != NULL) {
        *(struct12 **)((s32)temp_v0_2 + 8) = *(struct12 **)((s32)arg0 + 8);
    }
}
// void *func_15168A9C(struct12 *arg0) {
//     void *temp_a1;
//     void *temp_v0;
//     void *temp_v0_2;
//
//     temp_a1 = (arg0->unk1 * 0x1A0) + (arg0->unk0 * 4) + 0x800DCE50;
//     if (arg0 == *temp_a1) {
//         *temp_a1 = (void *) arg0->unk8;
//     }
//     temp_v0_2 = arg0->unk8;
//     if (temp_v0_2 != 0) {
//         temp_v0_2->unk4 = (void *) arg0->unk4;
//     }
//     temp_v0 = arg0->unk4;
//     if (temp_v0 != 0) {
//         temp_v0->unk8 = (void *) arg0->unk8;
//     }
//     return temp_v0;
// }


void func_15168B10(s32 arg0, s32 arg1) {
    func_15168A9C(arg0);
    func_15168A4C(arg0, arg1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1944C0/func_15168B44.s")
#pragma GLOBAL_ASM("asm/nonmatchings/game_1944C0/func_15168BAC.s")
s32 func_15167A68(s32, s32, s32, s32, s32, s32);

void func_15168BE4(s32 *arg0, s32 arg1, s32 arg2) {
    s32 temp;

    if (arg0[0x10] != 0) {
        temp = func_15167A68(0x10, arg2, 0xF0, 1, (u8)arg1, 1);
        if (temp != 0) {
            bcopy(arg0, (void *)(temp + 0x90), 0x60);
        }
    }
}
#pragma GLOBAL_ASM("asm/nonmatchings/game_1944C0/func_15168C4C.s")
void func_15168E34(s32 *arg0, s32 arg1) {
    s32 val = *arg0;
    if ((val & 0x0F000000) == 0) {
        *arg0 = val + arg1;
    }
}
#pragma GLOBAL_ASM("asm/nonmatchings/game_1944C0/func_15168E54.s")
#pragma GLOBAL_ASM("asm/nonmatchings/game_1944C0/func_15168F08.s")
void func_15168F84(s32 arg0, s32 *arg1, s32 *arg2) {
    if (arg0 == 0) {
        *arg1 = 0x1;
        *arg2 = 0x41;
    } else if (arg0 == 1) {
        *arg1 = 0x42;
        *arg2 = 0x4F;
    } else if (arg0 == 2) {
        *arg1 = 0x50;
        *arg2 = 0x58;
    } else if (arg0 == 3) {
        *arg1 = 0x59;
        *arg2 = 0x5C;
    } else if (arg0 == 5) {
        *arg1 = 0x61;
        *arg2 = 0x63;
    } else if (arg0 == 6) {
        *arg1 = 0x64;
        *arg2 = 0x65;
    } else {
        *arg1 = 0x5D;
        *arg2 = 0x60;
    }
}
#pragma GLOBAL_ASM("asm/nonmatchings/game_1944C0/func_15169040.s")
#pragma GLOBAL_ASM("asm/nonmatchings/game_1944C0/func_15169070.s")
#pragma GLOBAL_ASM("asm/nonmatchings/game_1944C0/func_15169260.s")
#pragma GLOBAL_ASM("asm/nonmatchings/game_1944C0/func_1516944C.s")
#pragma GLOBAL_ASM("asm/nonmatchings/game_1944C0/func_151695F0.s")
void func_1516962C(s32 arg0, struct127 *arg1, u8 arg2) {
    struct {
        s32 unk0;
        u8 unk4;
    } sp18;
    sp18.unk0 = (s32)arg1;
    sp18.unk4 = arg1->unique_id;
    func_1516944C(arg0, (s32)&sp18, arg2);
}
s32 func_15169668(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    D_800D2DAB = 1;
    return arg0;
}
void func_1516968C(struct102 *arg0, u8 *arg1, u8 arg2) {
    if (arg2 == 0xF || arg2 == 0x10) {
        if (arg1[0] == ((u8 *)arg0)[0xC]) {
            func_1516972C(arg0);
        }
    }
}

void func_151696DC(s32 arg0) {
    s8 i;

    for (i = 0; i < D_800DD190; i++) {
        if (arg0 == ((s32 *)D_800DD198)[i]) {
            ((s32 *)D_800DD198)[i] = *(s32 *)(arg0 + 0x8);
        }
    }
}

void func_1516972C(struct102 *arg0) {
    void (*func)(struct102 *arg0);
    func_151696DC(arg0);

    if (arg0->unk0 >= 2) {
        func = D_8008B4D0[arg0->unk0].unk0;
        if (func != NULL) {
            func(arg0);
            return;
        }
        func_15169804(arg0);
    }
}

void func_1516979C(struct102 *arg0) {
    void (*func)(struct102 *arg0);

    func_151696DC(arg0);
    func = D_8008B4D4[arg0->unk0].unk0;
    if (func != NULL) {
        func(arg0);
        return;
    }
    func_15169824(arg0);
}

void func_15169804(struct102 *arg0) {
    func_15168B10(arg0, 1);
}

void func_15169824(struct102 *arg0) {
    func_15168A9C(arg0);
    func_10004074(arg0);
}

void func_15169850(s32 arg0, u8 arg1, s32 arg2, s32 arg3, s32 arg4) {
    if (arg1 == 0) {
        if (*(s32 *)arg0 == *(s32 *)arg2 || *(u8 *)(arg0 + 4) == *(u8 *)arg3) {
            func_1516972C((struct102 *)arg4);
        }
    } else if (arg1 == 0x2D) {
        s32 v = *(s32 *)arg0;
        if (v == *(s32 *)arg2) {
            *(s32 *)arg2 = *(s32 *)(arg0 + 4);
            *(u8 *)arg3 = *(u8 *)(arg0 + 9);
        } else if (*(s32 *)(arg0 + 4) == *(s32 *)arg2) {
            *(s32 *)arg2 = v;
            *(u8 *)arg3 = *(u8 *)(arg0 + 8);
        }
    }
}
