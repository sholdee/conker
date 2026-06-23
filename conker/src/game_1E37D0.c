#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern void func_150A7960(f32 *, f32, f32, f32, f32 *, f32 *, f32 *);

typedef struct {
    u8 pad0[0x18];
    f32 unk18;
    f32 unk1C;
    f32 unk20;
    f32 unk24;
    f32 unk28;
    u8 pad2C[0x38 - 0x2C];
    f32 unk38;
    f32 unk3C;
    f32 unk40;
} struct151B76CCObj;

typedef struct {
    u8 pad0[4];
    struct151B76CCObj **unk4;
} struct151B76CCList;

typedef struct {
    u8 pad0[0x98];
    struct151B76CCList *unk98;
} struct151B76CCArg0;

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E37D0/func_151B6320.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E37D0/func_151B6420.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E37D0/func_151B65D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E37D0/func_151B6928.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E37D0/func_151B70B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E37D0/func_151B7144.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E37D0/func_151B7328.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E37D0/func_151B7678.s")

s32 func_151B76CC(struct151B76CCArg0 *arg0, f32 *arg1) {
    struct151B76CCList *list;
    struct151B76CCObj **objPtr;
    struct151B76CCObj *obj;
    f32 mtx[4][4];

    list = arg0->unk98;
    objPtr = list->unk4;
    obj = *objPtr;
    func_150A8050(mtx, obj->unk20, obj->unk24, obj->unk28);
    mtx[3][0] = obj->unk38;
    mtx[3][1] = obj->unk3C;
    mtx[3][2] = obj->unk40;
    mtx[0][0] *= obj->unk18;
    mtx[0][1] *= obj->unk18;
    mtx[0][2] *= obj->unk18;
    mtx[1][0] *= obj->unk1C;
    mtx[1][1] *= obj->unk1C;
    mtx[1][2] *= obj->unk1C;
    mtx[2][0] *= obj->unk18;
    mtx[2][1] *= obj->unk18;
    mtx[2][2] *= obj->unk18;
    func_150A7960(mtx[0], 0.0f, 0.0f, -250.0f, arg1, arg1 + 1, arg1 + 2);
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E37D0/func_151B77F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E37D0/func_151B7998.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_1E37D0/func_151B7C38.s")

extern void (*D_8008FB98[])(void *, s32, u8);

void func_151B82CC(void *arg0, s32 arg1, u8 arg2) {
    void *v0 = *(void **)((u8 *)arg0 + 0x98);
    void (*f)(void *, s32, u8) = D_8008FB98[*(u8 *)((u8 *)v0 + 0x8)];
    if (f != 0) {
        f(arg0, arg1, arg2);
    }
}

struct S151B8318 {
    s32 unk0;
    u8 unk4;
};

struct T151B8318 {
    s32 unk0;
    struct S151B8318 *unk4;
};

void func_151B8318(struct102 *arg0, struct S151B8318 *arg1, u8 arg2) {
    int new_var;
    struct T151B8318 *v0 = *(struct T151B8318 **)((u8 *)arg0 + 0x98);
    struct S151B8318 *v1 = v0->unk4;

    if (arg2 == 0) {
        if ((v1->unk0 == (new_var = arg1->unk0)) || (arg1->unk4 == v1->unk4)) {
            func_1516972C(arg0);
        }
    }
}

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
