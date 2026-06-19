#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_17CAF0/func_1514F640.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_17CAF0/func_1514F6E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_17CAF0/func_1514F808.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_17CAF0/func_1514F8F8.s")

struct Vec3F { f32 x; f32 y; f32 z; };
struct Arg1514FB98 { u8 pad[0xC]; f32 unkC; u8 unk10[0x4]; };
extern s32 func_15146078(struct Arg1514FB98 *, struct Vec3F *, struct Vec3F *);
extern void func_1514F8F8(void *, struct Arg1514FB98 *, struct Vec3F *, struct Vec3F *, f32, u8, s32);

void func_1514FB98(struct Arg1514FB98 *arg0, u8 arg1, s32 arg2) {
    struct Vec3F sp34;
    struct Vec3F sp28;

    if (func_15146078(arg0, &sp34, &sp28) != 0) {
        func_1514F8F8((u8 *)arg0 + 0x10, arg0, &sp34, &sp28, arg0->unkC, arg1, arg2);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_17CAF0/func_1514FBFC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_17CAF0/func_1514FCE8.s")

struct Local1514FEFC { u8 unk0[0x2C]; };
extern void func_1514F640(void *, struct Local1514FEFC *);
extern void func_1514FF44(struct Local1514FEFC *, s32, s32, u8, s32);

void func_1514FEFC(void *arg0, s32 arg1, s32 arg2, u8 arg3, s32 arg4) {
    struct Local1514FEFC sp24;

    func_1514F640(arg0, &sp24);
    func_1514FF44(&sp24, arg1, arg2, arg3, arg4);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_17CAF0/func_1514FF44.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_17CAF0/func_15150178.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_17CAF0/func_15150400.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_17CAF0/func_1515080C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_17CAF0/func_15150D1C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_17CAF0/func_15150F90.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_17CAF0/func_151511FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_17CAF0/func_15151670.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_17CAF0/func_15151A38.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_17CAF0/func_15151D6C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_17CAF0/func_15152190.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_17CAF0/func_15152520.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_17CAF0/func_15152874.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_17CAF0/func_15152ABC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_17CAF0/func_15152B38.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_17CAF0/func_15152F70.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_17CAF0/func_15153298.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_17CAF0/func_15153634.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_17CAF0/func_151539B4.s")

extern void func_15153CCC(struct Local1514FEFC *, s32, s32, u8, s32);

void func_15153C84(void *arg0, s32 arg1, s32 arg2, u8 arg3, s32 arg4) {
    struct Local1514FEFC sp24;

    func_1514F640(arg0, &sp24);
    func_15153CCC(&sp24, arg1, arg2, arg3, arg4);
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_17CAF0/func_15153CCC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_17CAF0/func_15153F18.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_17CAF0/func_151541B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_17CAF0/func_1515452C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_17CAF0/func_15154684.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_17CAF0/func_15154884.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_17CAF0/func_15154A88.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_17CAF0/func_15154C90.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_17CAF0/func_15154D80.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_17CAF0/func_1515548C.s")

struct Local15155564 { u8 pad[0x2A]; u8 unk2A; };
extern void (*D_8008AD04[])(struct Local15155564 *, s32, u8);

void func_15155564(struct Local15155564 *arg0, s32 arg1, u8 arg2) {
    if (D_8008AD04[arg0->unk2A] != NULL) {
        D_8008AD04[arg0->unk2A](arg0, arg1, arg2);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_17CAF0/func_151555AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_17CAF0/func_1515572C.s")
