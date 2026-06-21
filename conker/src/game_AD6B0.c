#include <ultra64.h>
#define func_100126E8 func_100126E8_void_proto
#include "functions.h"
#undef func_100126E8
#include "variables.h"

extern s32 func_100126E8(s32 arg0, s32 arg1);
extern void func_15080430(struct127 *arg0, s32 arg1, s32 arg2);
extern s32 func_1507E968(struct127 *arg0);
extern void func_1507E500(struct127 *arg0, s32 arg1, s32 arg2);
extern s32 D_800D1928;


#pragma GLOBAL_ASM("asm/nonmatchings/game_AD6B0/func_15080200.s")

void func_15080228(void) {
    u8 sp38[0x100];
    u8 *temp_s5;
    s32 temp_a2;

    temp_s5 = sp38;
    if (func_100126E8((s32) temp_s5, 0x100) != 0) {
        do {
            if (sp38[0] == 0x4C) {
                temp_a2 = sp38[4] & 0x7F;
                temp_a2 = ((sp38[5] & 0x7F) | (temp_a2 << 7));
                temp_a2 = ((temp_a2 << 7) | (sp38[6] & 0x7F));
                temp_a2 = ((temp_a2 << 7) | (sp38[7] & 0x7F));
                temp_a2 /= 0x16F;
                if (temp_a2 == 0) {
                    temp_a2 = 0x14;
                }
                func_15080430(&D_800CC2D0[D_800D18D0], sp38[3] - 1, temp_a2);
            }
        } while (func_100126E8((s32) temp_s5, 0x100) != 0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_AD6B0/func_15080348.s")

void func_15080430(struct127 *arg0, s32 arg1, s32 arg2) {
    s32 temp_v0;

    if (arg0 != 0) {
        if (func_1507E968(arg0) > 0) {
            if (arg1 == 0) {
                D_800D1928 = 0;
                *(u16 *)((u8 *)arg0 + 0x72) = 0x14;
                func_1507E500(arg0, 0, 0xA);
            } else {
                *(u16 *)((u8 *)arg0 + 0x72) = (u16)-2;
                if (arg1 == 1) {
                    D_800D1928 = 2;
                } else {
                    if (arg2 != 0) {
                        if (arg2 >= 0x15) {
                            arg2 = 0x14;
                        }
                        if (arg2 <= 0) {
                            arg2 = 1;
                        }
                    }
                    func_1507E500(arg0, arg1, arg2);
                }
            }
        } else {
            temp_v0 = arg1 != 0;
            D_800D1928 = temp_v0;
            if (temp_v0 == 0) {
                arg0->unk1FF = 0;
            }
        }
    }
}
