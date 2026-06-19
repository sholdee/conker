#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_FA360/func_150CCEB0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_FA360/func_150CD17C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_FA360/func_150CD59C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_FA360/func_150CD7F8.s")

struct Inner150CDB6C {
    s32 unk0;
    f32 unk4;
};
extern u8* D_80088870;
extern f32 D_800A07A4;

void func_150CDB6C(s32 arg0) {
    struct Inner150CDB6C* q;
    if (arg0 >= 0 && arg0 < 0x100) {
        if (D_80088870 != NULL) {
            q = (struct Inner150CDB6C*)(D_80088870 + 0x28);
            q->unk4 = (f32)arg0 * D_800A07A4;
        }
    }
}
