#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern f32 D_800A8F68;
extern f32 D_800A8F6C;
extern f32 D_800A8F58;
extern f32 D_800A8F5C;
extern f32 D_800A8F60;
extern f32 D_800A8F64;
extern f32 D_800A8DE0;
extern void (*D_8008FA60[])(f32 *, void *, s32, u8, s32);

void func_1514373C(f32, f32, f32 *, f32 *);
s32 func_15046C80(f32 *, s32, f32, void *);
void *func_151A7950(void *, s32, u8, s32);
s32 func_151A8B20(void *, s32, s32, s32, s32);


#pragma GLOBAL_ASM("asm/nonmatchings/game_1D4E00/func_151A7950.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D4E00/func_151A7A90.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D4E00/func_151A7D6C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D4E00/func_151A8340.s")

extern void func_151D5E30(void *);

void func_151A8560(void *arg0) {
    func_151D5E30((void *)((u8 *)arg0 + 0x6C));
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D4E00/func_151A8584.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D4E00/func_151A85D4.s")

typedef struct {
    u8 bytes[4];
} Unaligned4_151A8624;

typedef struct {
    f32 unk0;
    f32 unk4;
    f32 unk8;
} Vec3f_151A8624;

typedef struct {
    void *unk0;
    u8 unk4;
    u8 pad5[3];
    Header2 unk8;
    u8 unk14;
    u8 pad15[3];
    Header2 unk18;
    u8 unk24;
    u8 unk25;
    u8 pad26[2];
} Payload_151A8624;

typedef struct {
    s16 unk0;
    s16 unk2;
    f32 unk4;
    f32 unk8;
    u8 unkC;
    u8 padD[3];
    f32 unk10;
    Unaligned4_151A8624 unk14;
    f32 unk18;
    u8 unk1C;
    s8 unk1D;
    u8 pad1E[2];
    f32 unk20;
    f32 unk24;
    f32 unk28;
    f32 unk2C;
    f32 unk30;
    f32 unk34;
    f32 unk38;
    f32 unk3C;
    f32 unk40;
    f32 unk44;
    f32 unk48;
    u8 unk4C;
    u8 pad4D[3];
} Header_151A8624;

void *func_151A8624(u8 *arg0, Header2 *arg1, u8 arg2, s16 arg3,
                    f32 arg4, f32 arg5, Unaligned4_151A8624 *arg6,
                    f32 arg7, Vec3f_151A8624 *arg8, u8 arg9, u8 argA,
                    s8 argB, s32 argC, u8 argD, s32 argE) {
    void *temp_v0;
    Header_151A8624 header;
    Payload_151A8624 payload;
    u8 flag;

    if (arg0 == NULL) {
        return NULL;
    }
    if (arg9 >= 2) {
        arg9 = 0;
    }

    payload.unk8 = *arg1;
    payload.unk14 = arg2;
    payload.unk25 = 0;
    payload.unk0 = arg0;
    payload.unk4 = arg0[0x3B];
    payload.unk24 = argA;
    temp_v0 = &header;

    if (arg8 != NULL) {
        *(Vec3f_151A8624 *)&payload.unk18 = *arg8;
    } else {
        ((Vec3f_151A8624 *)&payload.unk18)->unk0 = 0.0f;
        ((Vec3f_151A8624 *)&payload.unk18)->unk4 = 0.0f;
        ((Vec3f_151A8624 *)&payload.unk18)->unk8 = 0.0f;
    }

    if (arg3 == -1) {
        header.unk0 = 0x12C;
    } else {
        header.unk0 = arg3;
    }
    header.unk2 = 9;
    header.unk4 = arg4;
    header.unk8 = arg5;
    if (arg3 == -1) {
        flag = 0;
    } else {
        flag = 1;
    }
    header.unkC = flag;
    header.unk10 = D_800A8DE0;
    header.unk14 = *arg6;
    header.unk18 = arg7;
    if ((arg9 != 0) && (arg9 == 1)) {
        header.unk1C = 1;
    } else {
        header.unk1C = 1;
    }
    header.unk20 = 0.0f;
    header.unk24 = 0.0f;
    header.unk28 = 0.0f;
    header.unk2C = 0.0f;
    header.unk30 = 0.0f;
    header.unk34 = 0.0f;
    header.unk38 = 0.0f;
    header.unk3C = 0.0f;
    header.unk40 = 0.0f;
    header.unk44 = 0.0f;
    header.unk1D = argB;
    header.unk4C = 2;
    header.unk48 = 1.0f;

    temp_v0 = func_151A7950(temp_v0, argC + 0x28, argD, argE);
    if (temp_v0 != NULL) {
        memcpy(*(void **)((u8 *)temp_v0 + 0x60), &payload, sizeof(payload));
    }
    return temp_v0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D4E00/func_151A87F8.s")

extern void (*D_8008F964[])(u8 *, s32, u8);

void func_151A8A20(u8 *arg0, s32 arg1, u8 arg2) {
    s32 idx;

    idx = arg0[0x5C];
    if (idx >= 3) {
        idx = 0;
    }
    if (D_8008F964[idx] != NULL) {
        D_8008F964[idx](arg0, arg1, arg2);
    }
}

typedef struct {
    s32 unk0;
    u8  unk4;
} SubA_151A8A78;

typedef struct {
    s32 unk0;
    union {
        s32 w4;
        u8  b4;
    } u4;
    u8  unk8;
    u8  unk9;
} ArgB_151A8A78;

void func_151A8A78(void *arg0, s32 arg1, u8 arg2) {
    SubA_151A8A78 *temp_v0 = *(SubA_151A8A78 **)((u8 *)arg0 + 0x60);
    ArgB_151A8A78 *b = (ArgB_151A8A78 *)arg1;
    s32 b0;

    if (arg2 == 0) {
        b0 = b->unk0;
        if ((b0 == temp_v0->unk0) || (temp_v0->unk4 == b->u4.b4)) {
            func_1516972C((struct102 *)arg0);
        }
    } else if (arg2 == 0x2D) {
        if (temp_v0->unk0 == b->unk0) {
            temp_v0->unk0 = b->u4.w4;
            temp_v0->unk4 = b->unk9;
        } else if (temp_v0->unk0 == b->u4.w4) {
            temp_v0->unk0 = b->unk0;
            temp_v0->unk4 = b->unk8;
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D4E00/func_151A8B20.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D4E00/func_151A8CEC.s")

extern void func_151432BC(void *, f32 *, f32 *, f32 *, f32 *);

void func_151A8F1C(void *arg0, f32 *arg1, f32 *arg2, f32 *arg3) {
    func_151432BC(*(void **)((u8 *)arg0 + 0x2C), arg1, arg1 + 2, arg2, arg3);
    arg1[1] = arg2[0];
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D4E00/func_151A8F6C.s")

void func_151A931C(u8 *, s32, u8);

void func_151A9024(u8 *arg0, s32 arg1, u8 arg2) {
    if (arg0[0x4C] == 1) {
        func_151A931C(arg0, arg1, arg2);
    }
}

extern void (*D_8008F984[])(void);
s32 func_151A9060(u8 *arg0)
{
  s32 new_var;
  s32 idx;
  arg0[0x16] |= 0x4;
  new_var = *((s32 *) (arg0 + 0x18));
  idx = new_var & 0xFFFFFFFFu;
  new_var = idx < 0;
  if (new_var || (idx >= 8))
  {
    return 1;
  }
  if (D_8008F984[idx])
  {
    D_8008F984[idx]();
  }
  return 1;
}


void func_151A90C0(s32 arg0, s32 arg1) {
    struct {
        s8 unk0;
        u8 pad1[3];
        s32 unk4;
        f32 unk8;
        f32 unkC;
        f32 unk10;
        f32 unk14;
        f32 unk18;
        f32 unk1C;
        f32 unk20;
        s8 unk24;
        s8 unk25;
        s8 unk26;
    } sp30;
    s32 sp28;
    f32 temp_f0;
    s32 temp_v0;

    sp30.unk0 = 2;
    sp30.unk4 = arg0;
    temp_f0 = (f32)(arg1 & 1);
    if (temp_f0) {
        sp30.unk8 = D_800A8F58;
    } else {
        sp30.unk8 = D_800A8F5C;
    }

    if (temp_f0) {
        sp30.unkC = D_800A8F60;
    } else {
        sp30.unkC = D_800A8F64;
    }

    temp_f0 = 0.0f;
    sp30.unk10 = temp_f0;
    sp30.unk14 = temp_f0;
    sp30.unk18 = temp_f0;
    sp30.unk1C = temp_f0;
    sp30.unk20 = temp_f0;
    sp30.unk24 = 1;
    sp30.unk25 = -1;
    sp30.unk26 = 0;
    ((s8 *)&sp28)[-4] = (s8)arg1;

    temp_v0 = func_151A8B20(&sp30, -1, 1, 0xFF, 0);
    if (temp_v0 != 0) {
        memcpy((void *)(temp_v0 + 0x80), ((s8 *)&sp28) - 4, 1);
    }
}

struct S6_151A91AC { s16 unk0; s16 unk2; s16 unk4; };
extern struct S6_151A91AC D_8008F9A4;

struct Loc_151A91AC {
    s32 unk0;
    s16 unk4;
    u8  unk6;
    u8  unk7;
    s32 unk8;
    s32 unkC;
    u8  unk10;
    u8  unk11;
    u8  unk12;
    u8  unk13;
    u8  unk14;
    u8  unk15;
    u8  unk16;
    u8  unk17;
    s32 unk18;
    s32 unk1C;
    s32 unk20;
    s32 unk24;
    s32 unk28;
};

void func_151A91AC(u8 *arg0, f32 *arg1, s32 arg2, s32 arg3) {
    struct Loc_151A91AC sp64;
    f32 fval;
    struct S6_151A91AC sp58;
    u32 idx;
    s32 r3;
    s32 r2;

    sp58 = D_8008F9A4;
    fval = func_150ADA68() * 50.0f + 50.0f;
    idx = (u32)func_150ADA20() % 3U;

    sp64.unk6 = (u8)((s16 *)&sp58)[idx];
    sp64.unk7 = 0;
    sp64.unk16 = 0;
    sp64.unk17 = 7;
    sp64.unk8 = 0;
    sp64.unkC = 0;
    sp64.unk0 = 0x1701;
    sp64.unk4 = 0x3C;
    sp64.unk10 = 0xA0;
    sp64.unk11 = 0xFF;
    sp64.unk12 = 0;
    sp64.unk13 = 0;
    sp64.unk14 = 0;
    sp64.unk15 = 0xFF;
    sp64.unk18 = 0x3B0002;

    r2 = func_150ADA20();
    r3 = func_150ADA20();
    func_1513C650((s32)&sp64, 1, 0, (s32)(arg0 + 0x58), arg1[0], arg1[1], arg1[2],
                  fval, fval, r2 & 0xFF,
                  (r3 & 1) + (func_150ADA20() & 1), 3, 0xFF, 0,
                  arg0[0xC], arg0[1]);
}

void func_151A931C(u8 *arg0, s32 arg1, u8 arg2) {
    u8 *ptr;

    if (arg2 == 0x17) {
        ptr = arg0 + 0x28;
        if (*(u8 *)arg1 != arg0[0x80]) {
            goto ret;
        }
        *ptr |= 1;
    ret:
        return;
    } else if (arg2 == 0x18) {
        ptr = arg0 + 0x28;
        if (*(u8 *)arg1 == arg0[0x80]) {
            *ptr &= ~1;
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D4E00/func_151A9390.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1D4E00/func_151A9634.s")

typedef struct {
    f32 unk0;
    u8 pad4[0x14];
    s32 unk18;
    u8 unk1C;
    u8 unk1D;
    u8 pad1E[2];
    s32 unk20;
} Struct151A9834;

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Vec3f151A9834;

void func_151A9834(f32 *arg0, f32 arg1, f32 arg2, Struct151A9834 *arg3,
                   s32 arg4, u8 arg5, s32 arg6, u8 arg7, s32 arg8) {
    Struct151A9834 sp8C;
    Vec3f151A9834 sp80;
    Vec3f151A9834 sp74;
    f32 temp_f22;
    f32 temp_f20;
    f32 temp_f0;

    if (arg3 == 0) {
        arg3 = &sp8C;
        sp8C.unk0 = D_800A8F68;
        sp8C.unk18 = 0;
        sp8C.unk1C = 7;
        sp8C.unk1D = 0;
        sp8C.unk20 = 0;
    }

    sp80.y = arg0[1];
    if (arg4 > 0) {
        temp_f22 = D_800A8F6C;
        do {
            temp_f20 = func_150ADA68();
            temp_f0 = func_150ADA68();
            func_1514373C((temp_f20 + temp_f20) * temp_f22, temp_f0 * arg2,
                          &sp80.x, &sp80.z);
            sp80.x += arg0[0];
            sp80.z += arg0[2];

            if (func_15046C80(&sp80.x, 0, arg1, arg3) != 0) {
                sp74.x = sp80.x;
                sp74.y = arg3->unk0;
                sp74.z = sp80.z;
                D_8008FA60[arg5](&sp74.x, arg3, arg6, arg7, arg8);
            }
            arg4--;
        } while (arg4 > 0);
    }
}
