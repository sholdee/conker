#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern s32 D_8008CA4C;
s32 func_15167D84(void *, s32, s32, s32, s32, s32);

typedef struct {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    s16 unkC;
    s16 unkE;
    s16 unk10;
    u8 unk12;
    u8 unk13;
    u8 unk14;
    u8 pad15;
    s16 unk16;
    s16 unk18;
    s16 unk1A;
    s16 unk1C;
    s16 unk1E;
    s16 unk20;
    s16 unk22;
    s16 unk24;
    s16 unk26;
    u8 unk28;
    u8 unk29;
    u8 unk2A;
    u8 unk2B;
    u8 unk2C;
    u8 unk2D;
    u8 unk2E;
    u8 unk2F;
    s8 unk30;
    u8 unk31;
} Obj1518CA80;

typedef struct {
    s32 unk00;
    s32 unk04;
    s32 unk08;
    s16 unk0C;
    s16 unk0E;
    s16 unk10;
    s16 unk12;
    s16 unk14;
    s16 unk16;
    s16 unk18;
    s16 unk1A;
    u8 unk1C;
    u8 unk1D;
    u8 unk1E;
    s8 unk1F;
    s16 unk20;
    s16 unk22;
    s16 unk24;
    s16 unk26;
    s16 unk28;
    s8 unk2A;
    u8 unk2B;
    s8 unk2C;
    s8 unk2D;
    s8 unk2E;
    u8 unk2F;
    s8 unk30;
    s8 unk31;
    s8 unk32;
    s16 unk34;
} Struct1518CA80;

void func_1518CA80(Obj1518CA80 *arg0, u8 arg1)
{
    Struct1518CA80 sp30;
    u8 temp_v1;

    temp_v1 = arg0->unk2E;
    sp30.unk2C = (arg0->unk28 * temp_v1) >> 8;
    sp30.unk2D = (arg0->unk29 * temp_v1) >> 8;
    sp30.unk2E = (arg0->unk2A * temp_v1) >> 8;
    sp30.unk30 = (arg0->unk2B * temp_v1) >> 8;
    sp30.unk31 = (arg0->unk2C * temp_v1) >> 8;
    sp30.unk32 = (arg0->unk2D * temp_v1) >> 8;
    sp30.unk28 = arg0->unk26;
    sp30.unk2F = arg0->unk2F;
    sp30.unk2A = arg0->unk30;
    sp30.unk0C = 0;
    sp30.unk00 = D_8008CA4C;
    sp30.unk0E = 0x100;

    if (arg1 == 1) {
        sp30.unk10 = (s32)arg0->unk0;
        sp30.unk12 = (s32)arg0->unk4;
        sp30.unk14 = (s32)arg0->unk8;
        sp30.unk1C = ((s32)(arg0->unk0 * 256.0f)) & 0xFF;
        sp30.unk1E = ((s32)(arg0->unk4 * 256.0f)) & 0xFF;
        sp30.unk1D = ((s32)(arg0->unk8 * 256.0f)) & 0xFF;
    } else {
        sp30.unk10 = arg0->unkC;
        sp30.unk12 = arg0->unkE;
        sp30.unk14 = arg0->unk10;
        sp30.unk1C = arg0->unk12;
        sp30.unk1E = arg0->unk14;
        sp30.unk1D = arg0->unk13;
    }

    sp30.unk16 = arg0->unk1E;
    sp30.unk18 = arg0->unk20;
    sp30.unk20 = arg0->unk22;
    sp30.unk22 = arg0->unk24;
    sp30.unk1F = 9;
    sp30.unk34 = 1;
    sp30.unk24 = arg0->unk16;
    sp30.unk26 = arg0->unk18;
    sp30.unk04 = arg0->unk1A << 16;
    sp30.unk04 += arg0->unk1C;
    sp30.unk2B = arg0->unk31;
    sp30.unk1A = 0;
    sp30.unk08 = 0;
    func_15167D84(&sp30, 0, 0, -1, 0xFF, 1);
}

extern void (*D_8008D5D0[])(void);
void func_1518CCA8(u8 *arg0)
{
  s32 temp_t1;
  s32 temp_t4;
  temp_t1 = *((s32 *) (arg0 + 0x14));
  *((s16 *) (arg0 + 0x34)) = (*((s16 *) (arg0 + 0x34))) + ((temp_t1 & 0xFFFF0000) >> 0x10);
  *((s16 *) (arg0 + 0x36)) = (*((s16 *) (arg0 + 0x36))) + (temp_t1 & 0xFFFFu);
  if ((*((s16 *) (arg0 + 0x38))) == 0)
  {
    temp_t4 = arg0[0x3B] & 0xF;
    if (temp_t4 != 0)
    {
      D_8008D5D0[temp_t4]();
    }
  }
}
