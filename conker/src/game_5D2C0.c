#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern f32 D_80097B68;

#pragma GLOBAL_ASM("asm/nonmatchings/game_5D2C0/func_1502FE10.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_5D2C0/func_1502FFD8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_5D2C0/func_15030158.s")

s32 func_15030310(void *arg0, s32 arg1, s32 arg2);

s32 func_150302F0(void *arg0, s32 arg1) {
    return func_15030310(arg0, arg1, 0xFF);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_5D2C0/func_15030310.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_5D2C0/func_150303E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_5D2C0/func_15030468.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_5D2C0/func_15030AF4.s")

extern void *allocate_memory(s32 size, s32 arg1, s32 arg2, s32 arg3);
void func_15030D54(void *arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6)
{
  f32 *temp;
  temp = allocate_memory(0x18, 1, 0, 2);
  *((f32 **) (((u8 *) arg0) + 0x44)) = temp;
  if (temp)
  {
    temp[((0, (*((s32 *) (((u8 *) arg0) + 0x34))) == 0)) * 0] = arg1;
    *((f32 *) ((*((s32 *) (((u8 *) arg0) + 0x44))) + 0x4)) = arg2;
    *((f32 *) ((*((s32 *) (((u8 *) arg0) + 0x44))) + 0x8)) = arg3;
    *((f32 *) ((*((s32 *) (((u8 *) arg0) + 0x44))) + 0xC)) = arg4;
    *((f32 *) ((*((s32 *) (((u8 *) arg0) + 0x44))) + 0x10)) = arg5;
    temp = ((u8 *) arg0) + 0x44;
    *((f32 *) ((*((s32 *) temp)) + 0x14)) = arg6;
    if (0, (*((s32 *) (((u8 *) arg0) + 0x34))) == 0)
    {
      *((void **) (((u8 *) arg0) + 0x34)) = allocate_memory(0x80, 1, 2, 2);
    }
  }
}


#pragma GLOBAL_ASM("asm/nonmatchings/game_5D2C0/func_15030E08.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_5D2C0/func_15030F94.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_5D2C0/func_15031070.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_5D2C0/func_150311C4.s")

void func_1503192C(struct127 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    struct126 *temp;
    temp = func_1503195C(arg0, arg1, arg3);
    if (temp != 0) {
        *((u8 *)temp + 3) = arg2;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_5D2C0/func_1503195C.s")

struct S150319CC {
    u8 unk0;
    u8 pad1[5];
    u8 unk6;
    u8 pad7[0x4D];
    struct S150319CC *unk54;
};
struct S150319CC *func_150319CC(s32 arg0, u8 *arg1) {
    struct S150319CC *var;
    struct S150319CC *next;
    u8 key;

    if (arg1 != 0) {
        var = (struct S150319CC *)D_800C3EE0;
        if (var != 0) {
            key = arg1[0x3B];
            do {
                next = var->unk54;
                if ((var->unk0 == key) && (var->unk6 == arg0)) {
                    return var;
                }
                var = next;
            } while (next != 0);
        }
    }
    var = (struct S150319CC *)D_800C3EE0;
    if (var != 0) {
        do {
            next = var->unk54;
            if (var->unk6 == arg0) {
                return var;
            }
            var = next;
        } while (next != 0);
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_5D2C0/func_15031A50.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_5D2C0/func_15031C14.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_5D2C0/func_15031E2C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_5D2C0/func_15031E7C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_5D2C0/func_15031FC8.s")

void func_1503F5B8(s32 arg0, s32 arg1, s32 arg2, f32 arg3, f32 arg4, s32 arg5);

s32 func_150331B8(s32 arg0, s32 arg1) {
    s32 ptr;
    s32 temp;

    ptr = *(s32 *)(arg1 + 0x2D0);
    temp = *(s32 *)(arg0 + 0x48);
    if (temp == 0) {
        return 0;
    }
    if ((*(s32 *)(arg1 + 0x2E4) & 0xFF) != 0xFF) {
        func_1503F5B8(temp, 0, *(s32 *)(arg1 + 0x2E4) & 0xFF, 1.0f, 0.0f, 1);
    }
    if (ptr != 0) {
        *(f32 *)(*(s32 *)(arg0 + 0x48) + 8) = *(f32 *)(ptr + 8);
        temp = *(s32 *)(arg0 + 0x48);
        if (*(f32 *)(temp + 0x18) <= *(f32 *)(temp + 8)) {
            *(f32 *)(temp + 8) = *(f32 *)(temp + 0x18) - 1.0f;
        }
    }
    return 0;
}


s32 func_1503327C(s32 arg0, s32 arg1) {
    s32 ptr;

    ptr = *(s32 *)(arg0 + 0x48);
    if (ptr == 0) {
        return 0;
    }
    if ((*(u16 *)(ptr + 4) & 0x8000) != 0x8000) {
        func_1503F5B8(ptr, 0, 0, 1.0f, 0.0f, 1);
        ptr = *(s32 *)(arg0 + 0x48);
    }
    if (*(f32 *)(ptr + 0x18) - 1.0f <= *(f32 *)(ptr + 8)) {
        return 1;
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_5D2C0/func_15033328.s")

s32 func_150333A8(u8 *arg0, u8 *arg1) {
    s32 temp;

    if (D_800C35EA == 1) {
        return 0;
    }
    if (arg1[0xAD] != 0) {
        temp = *(s32 *)(arg1 + 0x31C);
        if (temp != 0) {
            *(u8 *)(temp + 0x11A) = 0;
        }
        return 1;
    }
    if ((*(f32 *)(arg1 + 0x118) != D_80097B68) && (*(f32 *)(arg1 + 0x18) < *(f32 *)(arg1 + 0x118) + 300.0f)) {
        arg0[3] = 0;
    } else {
        arg0[3] = 0xFF;
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_5D2C0/func_15033440.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_5D2C0/func_150334B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_5D2C0/func_150335C8.s")

s32 func_1503378C(u8 *arg0, s16 *arg1) {
    u16 temp = (u16)arg1[0x42];
    if (arg0[1] == 0x11) {
        if ((temp == 0x3E) || (temp == 0x3D) || (temp == 0x41) || (temp == 0xD9) || (temp == 0x138) || (temp == 0x139)) {
            return 0;
        }
    }
    return 1;
}

extern s32 D_800902FC[];

s32 func_150337E4(void *arg0, s32 arg1) {
    s32 *p = (s32 *)arg0;
    p[0xE] += D_800BE9E4;
    if (p[0xE] >= 0x10) {
        p[0xE] = 0;
        p[0xF] ^= 1;
    }
    *(s16 *)((u8 *)arg0 + 0x18) = D_800902FC[p[0xF]];
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_5D2C0/func_15033838.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_5D2C0/func_150339C8.s")

s32 func_15033BDC();

s32 func_15033AD8(u8 *arg0, u8 *arg1) {
    if (D_800BE616 != 0) {
        func_1508B20C(*(f32 *)(arg1 + 0x14), *(f32 *)(arg1 + 0x18), *(f32 *)(arg1 + 0x1C), 900.0f);
    }
    if (*(s32 *)(arg0 + 0x38) == 0) {
        if (*(s32 *)(arg0 + 0x3C) < 0x1E) {
            *(s32 *)(arg0 + 0x3C) += D_800BE9E4;
        } else {
            *(s32 *)(arg0 + 0x3C) = func_1000FA64(0x513,
                (s16)(s32)*(f32 *)(arg1 + 0x14),
                (s16)(s32)*(f32 *)(arg1 + 0x18),
                (s16)(s32)*(f32 *)(arg1 + 0x1C),
                0x7D00, 0x3E8, 0x1F4, (s32)func_15033BDC, arg0, (s32)arg1, 0, 0);
            *(s32 *)(arg0 + 0x38) = 0x513;
        }
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_5D2C0/func_15033BDC.s")

s32 func_15033E00(s32 arg0, u8 *arg1) {
    if (arg1[5] == 3) {
        return 1;
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_5D2C0/func_15033E28.s")

struct S15033E84 {
    u8 unk0;
    u8 pad[0x53];
    struct S15033E84 *unk54;
};
struct S15033E84 *func_15033E84(u8 *arg0) {
    struct S15033E84 *var;
    struct S15033E84 *next;
    u8 key;

    var = (struct S15033E84 *)D_800C3EE0;
    if (var != 0) {
        key = arg0[0x3B];
        do {
            next = var->unk54;
            if (var->unk0 == key) {
                return var;
            }
            var = next;
        } while (next != 0);
    }
    return 0;
}

void func_15033EC4(s32 arg0, s32 arg1) {
    struct S15033E84 *var;
    struct S15033E84 *next;
    s32 b;
    s32 key;

    b = arg0;
    var = (struct S15033E84 *)D_800C3EE0;
    if (var != 0) {
        do {
            next = var->unk54;
            key = var->unk0;
            if (b == key) {
                var->unk0 = arg1;
            } else if (arg1 == key) {
                var->unk0 = b;
            }
            var = next;
        } while (next != 0);
    }
}

s32 func_15033F0C(s32 arg0, u8 *arg1) {
    u8 *temp;

    if (D_800C35EA == 1) {
        return 0;
    }
    temp = *(u8 **)(arg1 + 0x31C);
    if (temp != 0) {
        if (temp[0x78] != 9) {
            if (temp[0x11A] != 3) {
                temp[0x11A] = 0;
                return 1;
            }
        }
    }
    return 0;
}

s32 func_15033F70(s32 arg0, u8 *arg1) {
    u8 *temp;

    if (D_800C35EA == 1) {
        return 0;
    }
    temp = *(u8 **)(arg1 + 0x31C);
    if (temp != 0) {
        if ((temp[0x78] != 0xC) && (temp[0x78] != 0x16)) {
            if (temp[0x11A] != 3) {
                temp[0x11A] = 0;
                return 1;
            }
        }
    }
    return 0;
}
