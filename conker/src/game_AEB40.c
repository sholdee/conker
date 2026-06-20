#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_AEB40/func_15081690.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_AEB40/func_15081C20.s")

extern void func_1507DF10(struct127 *arg0, s32 arg1);

void func_15081E0C(struct127 *arg0, u16 arg1, u8 arg2) {
    if (D_800BE616 == 0) {
        if (arg0->health != 0) {
            arg0->health = 7;
        }
        if ((arg2 == 0) || (arg1 != 0xA)) {
            func_1507DF10(arg0, arg1);
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_AEB40/func_15081E78.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_AEB40/func_150825C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_AEB40/func_1508295C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_AEB40/func_150829D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_AEB40/func_15082A44.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_AEB40/func_150832AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_AEB40/func_15083384.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_AEB40/func_15083568.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_AEB40/func_150836CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_AEB40/func_150837D4.s")

extern s32 allocate_memory(s32, s32, s32, s32);

s32 func_150838EC(struct127 *arg0, u16 arg1, s32 arg2, f32 arg3) {
    s32 idx;

    idx = arg0->id;
    if (D_800D1588[idx] == 0) {
        return 0;
    }
    if (((u16 *)D_800C5A90)[idx] == 0) {
        return 0;
    }
    *(s32 *)((s32)arg0 + 0x2D0) = allocate_memory(0x3E0, 1, 2, 0);
    if (*(s32 *)((s32)arg0 + 0x2D0) == 0) {
        return 1;
    }
    bzero(*(s32 *)((s32)arg0 + 0x2D0), 0x40);
    func_1505E650(arg0, arg1, arg3, 0.0f, 0.0f, 0.0f, arg2);
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_AEB40/func_150839B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_AEB40/func_15083AC8.s")

extern u8 D_800D2100;

struct struct258b {
    u8 pad0[0x28];
    u8 unk28;
    u8 pad29[0x7];
};

s32 func_15083DA0(void) {
    s32 id;
    s32 i;

    id = 1;
    i = 0;
    while (i < (s32)D_800D2100) {
        if (id == ((struct struct258b *)D_800D20FC)[i].unk28) {
            id++;
            i = 0;
        }
        i++;
    }
    if (id >= 0x100) {
        id = 0xFF;
    }
    return id;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_AEB40/func_15083E0C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_AEB40/func_15083E90.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_AEB40/func_15083FB0.s")

extern struct127 *func_1505EEF4(void);

s32 func_15084000(void) {
    struct127 *temp = func_1505EEF4();

    if (temp != 0) {
        return temp - D_800CC2D0;
    }
    return -1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_AEB40/func_15084044.s")

extern void func_150843AC(void *arg0, s32 arg1);

void func_1508434C(u8 *arg0) {
    s32 count;
    s32 i;

    count = arg0[0x2C9];
    if (count == 0) {
        count = 1;
    }
    for (i = 0; i < count; i++) {
        func_150843AC(arg0, i);
    }
}

void func_100043B4(s32 *arg0, u32 arg1);
extern s32 D_800D19A0;
extern s32 D_800D1F80[187];
extern void func_150843AC(void *arg0, s32 arg1);
void func_150843AC(void *arg0, s32 arg1)
{
  unsigned char new_var;
  s32 *p;
  s32 i;
  u8 idx;
  if (((*((s32 *) ((((u8 *) arg0) + (arg1 * 8)) + 0x28C))) == 0) && ((*((s32 *) ((((u8 *) arg0) + (arg1 * 8)) + 0x290))) == 0))
  {
    return;
  }
  new_var = 8;
  idx = ((u8 *) (*((s32 *) (((u8 *) arg0) + 0x2C4))))[arg1];
  for (p = (s32 *) (((s8 *) arg0) + (arg1 << 3)), i = 0; i != new_var; p++, i += 4)
  {
    s32 cur = *((s32 *) (((u8 *) p) + 0x28C));
    if (cur != 0)
    {
      if (cur != (&D_800D19A0)[idx])
      {
        func_100043B4((s32 *) cur, 3);
      }
      else
      {
        ((u8 *) D_800D1F80)[idx] -= 1;
      }
      *((s32 *) (((u8 *) p) + 0x28C)) = 0;
    }
  }

}


#pragma GLOBAL_ASM("asm/nonmatchings/game_AEB40/func_15084488.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_AEB40/func_15084558.s")

typedef struct {
    u8 pad[0x1C9];
    u8 unk1C9;
    u8 pad2[0x2C4 - 0x1CA];
    u8 *unk2C4;
    u8 unk2C8;
} GameAEB40Struct;

u8 func_150849A0(GameAEB40Struct *a0) {
    s32 v1 = a0->unk1C9;
    if (v1 != 0) {
        return a0->unk2C4[v1 - 1];
    }
    return a0->unk2C4[0];
}

u8 func_150849CC(GameAEB40Struct *a0, s32 *a1) {
    s32 v1;
    s32 v0;
    v0 = a0->unk1C9;
    if (v0 != 0) {
        v1 = v0 - 1;
    } else {
        v0 = a0->unk2C8;
        if (v0 != 0) {
            v1 = v0 - 1;
        } else {
            v1 = 0;
        }
    }
    if (a1 != 0) {
        *a1 = v1;
    }
    return a0->unk2C4[v1];
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_AEB40/func_15084A18.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_AEB40/func_15084C30.s")


#pragma GLOBAL_ASM("asm/nonmatchings/game_AEB40/func_15084CB0.s")
