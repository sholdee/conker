#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_1E37D0/func_151B6320.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E37D0/func_151B6420.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E37D0/func_151B65D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E37D0/func_151B6928.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E37D0/func_151B70B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E37D0/func_151B7144.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E37D0/func_151B7328.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E37D0/func_151B7678.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E37D0/func_151B76CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E37D0/func_151B77F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E37D0/func_151B7998.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E37D0/func_151B7C38.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E37D0/func_151B82CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E37D0/func_151B8318.s")

void func_151B8370(void *arg0) {
    s32 v0 = *(s32 *)((u8 *)arg0 + 0x98);
    struct102 *v = *(struct102 **)v0;
    if (v != 0) {
        func_1516972C(v);
    }
}

extern void func_151B8370(void *);
extern void func_151478F4(void *);

void func_151B83A0(void *arg0) {
    func_151B8370(arg0);
    func_151478F4(arg0);
}

extern void func_15147928(void *);

void func_151B83CC(void *arg0) {
    func_151B8370(arg0);
    func_15147928(arg0);
}
