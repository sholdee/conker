#include <ultra64.h>

#include "functions.h"
#include "variables.h"

#include "macros.h"

extern void *allocate_memory(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern void func_10004074(void *arg0);
extern s32 func_10006240(void *arg0, void *arg1, u32 arg2);

void func_1502AAF0(void) {
}

void func_1502AAF8(s32 arg0) {
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_57FA0/func_1502AB04.s")
#pragma GLOBAL_ASM("asm/nonmatchings/game_57FA0/func_1502AC88.s")
#pragma GLOBAL_ASM("asm/nonmatchings/game_57FA0/func_1502AF04.s")
extern u8 D_AB1950;
s32 func_1502AC88(u8 *arg0, s32 arg1, s32 *arg2);

s32 func_1502B020(s32 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    u8 *offset;
    s32 *tmp;
    s32 n;
    s32 sp38;

    sp38 = 1;
    offset = &D_AB1950;
    tmp = &arg1 + 1;

    for (; arg1 != 0; arg1--) {
        tmp = (s32 *)(((s32)tmp + 3) & -4) + 1;
        n = *(tmp - 1);
        if (sp38 != 0) {
            offset += func_1502AC88(offset, n, &sp38);
        }
        sp38 = sp38 & 0xFFFFFFF;
    }

    if (arg0 != 0) {
        *arg0 = sp38 & 0xFFFFFFF;
    }

    if (sp38 == 0) {
        return 0;
    } else {
        return (s32)offset;
    }
}
#pragma GLOBAL_ASM("asm/nonmatchings/game_57FA0/func_1502B110.s")
s32 func_1502B224(s32 arg0, void *arg1, u32 arg2, u32 arg3) {
    u32 size;
    void *buf;
    s32 expected;

    size = ((arg2 & 0x0FFFFFFF) + 1) & ~1;
    if (arg3 != 0) {
        if (arg3 < size) {
            size = arg3;
        }
    }

    if ((arg2 & 0x70000000) == 0x10000000) {
        buf = allocate_memory(size, 1, 2, 2);
        if (buf == 0) {
            return 0;
        }

        func_10004514(arg0, buf, (size + 0xF) & ~0xF, 1);
        expected = *(s32 *)buf & 0x7FFFFFFF;
        if ((size = func_10006240(buf, arg1, D_8003809C)) == expected) {
        } else {
            D_8003C8E0 = 0x0C000036;
            func_150AD770();
        }
        func_10004074(buf);
        return size;
    }

    func_10004514(arg0, arg1, (size + 0xF) & ~0xF, 1);
    return size;
}
#pragma GLOBAL_ASM("asm/nonmatchings/game_57FA0/func_1502B350.s")
#pragma GLOBAL_ASM("asm/nonmatchings/game_57FA0/func_1502B4A8.s")
extern u8 D_AB1950;
s32 func_1502AC88(u8 *arg0, s32 arg1, s32 *arg2);
s32 func_1502B350(u8 *arg0, s32 arg1, s32 *arg2);

s32 func_1502B5C8(s32 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 *more;
    u8 *offset;
    s32 *tmp;
    s32 sp40;
    s32 ret;
    s32 sp38;
    s32 n;

    more = &sp40;
    if (arg0 != 0) {
        more = arg0;
    }

    *more = 1;
    offset = &D_AB1950;
    tmp = &arg1 + 1;

    if (arg1 != 0) {
        do {
            tmp = (s32 *)(((s32)tmp + 3) & -4) + 1;
            n = *(tmp - 1);
            if (*more != 0) {
                offset += func_1502AC88(offset, n, &sp38);
            }
            *more = sp38 & 0xFFFFFFF;
        } while (--arg1 != 0);
    }

    if (*more != 0) {
        ret = func_1502B350(offset, sp38, more);
    } else {
        ret = 0;
    }

    return ret;
}
s32 func_1502B4A8(s32 *arg0, s32 arg1);

s32 func_1502B6BC(s32 *arg0, s32 arg1, s32 *arg2, s32 arg3) {
    s32 *more;
    u8 *offset;
    s32 *tmp;
    s32 sp44;
    s32 ret;
    s32 sp38;
    s32 n;

    more = &sp44 + 1;
    if (arg0 != 0) {
        more = arg0;
    }

    *more = 1;
    offset = &D_AB1950;
    tmp = &arg3 + 1;

    if (arg3 != 0) {
        do {
            tmp = (s32 *)(((s32)tmp + 3) & -4) + 1;
            n = *(tmp - 1);
            if (*more != 0) {
                offset += func_1502AC88(offset, n, &sp38);
            }
            *more = sp38 & 0xFFFFFFF;
        } while (--arg3 != 0);
    }

    if (*more != 0) {
        ret = func_1502B350(offset, sp38, more);
        if (*more != 0 && ret != 0) {
            arg1 = func_1502B4A8(ret, arg1);
        } else {
            arg1 = 0;
        }
        if (arg2 != 0) {
            *arg2 = arg1;
        }
    } else {
        ret = 0;
    }

    return ret;
}
s32 func_1502B7F0(s32 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    u8 *offset;
    s32 *tmp;
    s32 n;
    s32 sp38;
    s32 sp34;

    sp38 = 1;
    offset = &D_AB1950;
    tmp = &arg1 + 1;

    for (; arg1 != 0; arg1--) {
        tmp = (s32 *)(((s32)tmp + 3) & -4) + 1;
        n = *(tmp - 1);
        if (sp38 != 0) {
            offset += func_1502AC88(offset, n, &sp34);
        }
        sp38 = sp34 & 0xFFFFFFF;
    }

    if (sp38 != 0) {
        *arg0 = func_1502B350(offset, sp34, &sp38);
    } else {
        *arg0 = 0;
    }

    return sp38;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_57FA0/func_1502B8E0.s")

s32 func_1502B9B4(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    u8 *offset;
    s32 *tmp;
    s32 n;
    s32 more;
    s32 stack0;
    s32 pad[3];
    s32 stack2[2];
    s32 stack1[2];
    s32 pad0;

    more = 1;
    offset = &D_AB1950;
    tmp = &arg0 + 1;

    for (; arg0 != 0; arg0--) {
        tmp = (s32 *)(((s32)tmp + 3) & -4) + 1;
        n = *(tmp - 1);
        if (more != 0) {
            offset += func_1502AC88(offset, n, &stack0);
        }
        more = stack0 & 0xFFFFFFF;
    }

    if (more != 0) {
        more = ((stack0 & 0xFFFFFFF) + 1) & -2;
        if ((stack0 & 0x70000000) == 0x10000000) {
            tmp = stack1;
            if (((s32)stack1 & 8) != 0) {
                tmp = stack2;
            }
            func_10004514((s32)offset, tmp, 0x10, 1);
            more = tmp[0];
        }
    }

    return more;
}
// NON-MATCHING: maybe 50% there?
// s32 func_1502B9B4(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
//
//     s32 stack2[2];
//     s32 stack1[2];
//     s32 stack0[5];
//
//     s32 more;
//     s32 offset;
//     s32 *tmp;
//     s32 i;
//
//     more = 1;
//     offset = &D_00AB1950;
//     tmp = &arg1;
//
//     for (i = arg0; i != 0; i--) {
//         tmp = ALIGN4(tmp) + 4;
//         if (more != 0) {
//             offset += func_1502AC88(offset, tmp - 4, &stack0);
//         }
//         more = *stack0 & 0xFFFFFFF;
//     }
//
//     if (more != 0) {
//         more = ALIGN2(stack0[0] & 0xFFFFFFF);
//         if ((*stack0 & 0x70000000) == 0x10000000) {
//             if (((s32) &stack1 & 8) != 0) {
//                 *stack1 = &stack2;
//             }
//             func_10004514(offset, stack1, 0x10, 1); // decompress?
//             more = *stack1;
//         }
//     }
//
//     return more;
// }
