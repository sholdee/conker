#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_1AB530/func_1517E080.s")

typedef struct Node_1517E134 {
    char pad0[0x24];
    struct Node_1517E134 *next;
} Node_1517E134;

extern void func_10004074(void);

void func_1517E134(Node_1517E134 *arg0) {
    Node_1517E134 *cur;
    Node_1517E134 *prev;

    cur = (Node_1517E134 *)D_800DDD64;
    if (arg0 == cur) {
        D_800DDD64 = (s32)arg0->next;
    } else {
        prev = cur;
        if (cur != NULL) {
            cur = cur->next;
            while (arg0 != cur) {
                prev = cur;
                if (cur == NULL) {
                    break;
                }
                cur = cur->next;
            }
        }
        if (prev != NULL) {
            prev->next = arg0->next;
        } else {
            return;
        }
    }
    func_10004074();
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1AB530/func_1517E1AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1AB530/func_1517E28C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1AB530/func_1517E4A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1AB530/func_1517EA4C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1AB530/func_1517EAAC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1AB530/func_1517EC1C.s")
