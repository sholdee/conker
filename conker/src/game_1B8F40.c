#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_1B8F40/func_1518BA90.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1B8F40/func_1518BBF4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1B8F40/func_1518BCD0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1B8F40/func_1518BD60.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1B8F40/func_1518C0B8.s")

s32 func_1518C540(void* arg0) {
    s32 v1;
    void* p;

    p = *(void**)((u8*)arg0 + 0x98);
    v1 = *(s16*)((u8*)arg0 + 0x1C) << 3;
    if (v1 >= 0x100) {
        v1 = 0xFF;
    }
    *(s8*)((u8*)p + 0x1B) = v1;
    if ((v1 & 0xFF) < 0) {
        return 0;
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1B8F40/func_1518C57C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1B8F40/func_1518C69C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1B8F40/func_1518C850.s")
