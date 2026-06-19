#include <ultra64.h>
#include "functions.h"
#include "variables.h"


typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
} GameC9EC0Struct;

extern GameC9EC0Struct D_80087430[];

s32 func_1509CA10(s32 arg0) {
    return D_80087430[arg0].unk0;
}

typedef struct {
    u16 unk0;
    u16 unk2;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
} GameC9EC0StructB;

extern GameC9EC0StructB D_80087438[];

s32 func_1509CA30(s32 arg0) {
    return D_80087438[arg0].unk0;
}

extern GameC9EC0StructB D_8008743A[];

s32 func_1509CA50(s32 arg0) {
    return D_8008743A[arg0].unk0 & 0xFFF;
}

extern GameC9EC0Struct D_80087434[];

s32 func_1509CA78(s32 arg0) {
    return D_80087434[arg0].unk0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_C9EC0/func_1509CA98.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_C9EC0/func_1509CB68.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_C9EC0/func_1509CBD4.s")

void func_1509CCB4(void);

void func_1509CC94(void) {
    func_1509CCB4();
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_C9EC0/func_1509CCB4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_C9EC0/func_1509CCF4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_C9EC0/func_1509CDDC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_C9EC0/func_1509CE64.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_C9EC0/func_1509CF28.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_C9EC0/func_1509D054.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_C9EC0/func_1509D08C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_C9EC0/func_1509D180.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_C9EC0/func_1509D780.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_C9EC0/func_1509D8FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_C9EC0/func_1509DBBC.s")
