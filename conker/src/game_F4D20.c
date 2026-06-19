#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_F4D20/func_150C7870.s")

typedef struct {
    u8  pad00[0x3C];
    s32 unk3C;
    u8  pad40[0x33];
    u8  unk73;
    u8  pad74[0x16C];
    s32 unk1E0;
    u8  pad1E4[0x38];
    s32 unk21C;
} GameObj150C78E0;

typedef struct {
    u8  pad00[0x3C];
    s32 unk3C;
} SubObj150C78E0;

extern void func_151150BC(GameObj150C78E0 *);

void func_150C78E0(GameObj150C78E0 *arg0) {
    SubObj150C78E0 *temp;

    if (!(arg0->unk73 & 4)) {
        temp = (SubObj150C78E0 *)((u8 *)D_800DBEF4 + 0x1E0);
        arg0->unk3C = -(temp->unk3C & 0xFFFF0000) & 0xFFFF0000;
        func_151150BC(arg0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_F4D20/func_150C7930.s")

extern s32 func_15116110(GameObj150C78E0 *);

typedef struct {
    u8  pad00[0x13];
    s8  unk13;
} Obj7C;

typedef struct {
    u8  pad00[0x3C];
    s16 unk3C;
} SubObj7968;

typedef struct {
    u8  pad00[0x73];
    u8  unk73;
    u8  pad74[0x8];
    Obj7C *unk7C;
} GameObj150C7968;

void func_150C7968(GameObj150C7968 *arg0) {
    SubObj7968 *temp;
    Obj7C *obj;
    s32 t;

    func_15116110((GameObj150C78E0 *)arg0);
    if (!(arg0->unk73 & 4)) {
        temp = (SubObj7968 *)((u8 *)D_800DBEF4 + 0x1E0);
        obj = arg0->unk7C;
        t = temp->unk3C >> 4;
        if (obj != 0) {
            obj->unk13 = t;
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_F4D20/func_150C79BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_F4D20/func_150C7C90.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_F4D20/func_150C7D7C.s")
