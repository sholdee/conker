#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern u8 D_800DCDE0[0x60];


#pragma GLOBAL_ASM("asm/nonmatchings/game_191C30/func_15164780.s")

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
