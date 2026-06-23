#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern u8 D_800DF7D0[];
extern s16 *D_800DF9B8[];
extern s32 *D_800E0148[];
void func_1510D630(s16 *arg0);


#pragma GLOBAL_ASM("asm/nonmatchings/game_1B9DB0/func_1518C900.s")

void func_1518CA04(s32 arg0) {
    if (arg0 != 0x1E4) {
        if (D_800DF7D0[arg0] != 0) {
            if (--D_800DF7D0[arg0] == 0) {
                func_1510D630(D_800DF9B8[arg0]);
                func_100043B4(D_800E0148[arg0], 4);
            }
        }
    }
}
