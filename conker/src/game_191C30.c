#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern u8 D_800DCDE0[0x60];

struct Obj15164780 {
    u8 pad0[0x10];
    u8 unk10[0x38];
    f32 unk48;
    f32 unk4C;
    f32 unk50;
    f32 unk54;
    f32 unk58;
    f32 unk5C;
    u8 unk60;
    u8 unk61;
    u8 unk62;
    u8 unk63;
    u8 unk64;
    u8 unk65;
};

extern void *func_15167A68(s32, s32, s32, s32, u8, s32);

void *func_15164780(struct127 *arg0, s32 arg1, u8 arg2, s32 arg3) {
    void *temp_v1;
    struct108 *temp_v0;

    temp_v0 = &D_800DBFF0[arg0->unk6];
    temp_v1 = temp_v0->unk3D0;
    if (temp_v1 != 0) {
        temp_v0 = (struct108 *) ((struct127 *) temp_v1)->unk31C;
        if ((temp_v0 != 0) && (((struct126 *) temp_v0)->unk198 != 0)) {
            return NULL;
        }
    }
    temp_v1 = func_15167A68(0x39, arg3, arg1 + 0x68, 1, arg2, 1);
    if (temp_v1 == 0) {
        return NULL;
    }
    memcpy((s32)temp_v1 + 0x10, arg0, 0x38);
    ((struct Obj15164780 *) temp_v1)->unk60 = 1;
    ((struct Obj15164780 *) temp_v1)->unk61 = 1;
    ((struct Obj15164780 *) temp_v1)->unk62 = 1;
    ((struct Obj15164780 *) temp_v1)->unk63 = 1;
    ((struct Obj15164780 *) temp_v1)->unk64 = 1;
    ((struct Obj15164780 *) temp_v1)->unk65 = 1;
    ((struct Obj15164780 *) temp_v1)->unk48 = 0.0f;
    ((struct Obj15164780 *) temp_v1)->unk4C = 0.0f;
    ((struct Obj15164780 *) temp_v1)->unk50 = 0.0f;
    ((struct Obj15164780 *) temp_v1)->unk54 = 0.0f;
    ((struct Obj15164780 *) temp_v1)->unk58 = 0.0f;
    ((struct Obj15164780 *) temp_v1)->unk5C = 0.0f;
    return temp_v1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_191C30/func_15164888.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_191C30/func_1516489C.s")

void func_15164EE4(void) {
    bzero(D_800DCDE0, 0x60);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_191C30/func_15164F0C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_191C30/func_15165628.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_191C30/func_151658DC.s")

f32 func_15165BB0(s32 *arg0, struct17 *arg1, f32 arg2, f32 arg3, f32 arg4);

void func_15165B80(s32 *arg0) {
    func_15165BB0(arg0, (struct17 *)((s32)arg0 + 0x108), *(f32 *)&arg0[0x45], *(f32 *)&arg0[0x46], *(f32 *)((s32)arg0 + 0x11C));
}

extern struct17 *func_15144B34(s32);
extern f32 func_15143E64(struct17 *);

f32 func_15165BB0(s32 *arg0, struct17 *arg1, f32 arg2, f32 arg3, f32 arg4) {
    f32 ret;
    struct17 sp20;
    struct17 *p;
    f32 dist;

    p = func_15144B34(*(u8 *)((s32)arg0 + 0x16));
    sp20.unk0 = arg1->unk0 - p->unk0;
    sp20.unk4 = arg1->unk4 - p->unk4;
    sp20.unk8 = arg1->unk8 - p->unk8;
    dist = func_15143E64(&sp20);
    if (dist < arg2) {
        ret = 1.0f;
    } else if (arg2 + arg3 < dist) {
        ret = 0.0f;
    } else {
        ret = 1.0f - (dist - arg2) * arg4;
    }
    return ret;
}
