#include <ultra64.h>
#include "functions.h"
#include "variables.h"


extern void (*D_8008D5C0[])(s32);
extern s32 D_800BE9E4;
void func_1516972C(struct102 *arg0);

struct Child1518AA10 {
    u8  pad0[0x10];
    s32 unk10;
    s32 unk14;
    struct Child1518AA10 *unk18;
    u8  unk1C;
};

struct Obj1518AA10 {
    u8  pad0[0x10];
    s32 unk10;
    struct Child1518AA10 *unk14;
    u8  pad18[0x1C - 0x18];
    s32 unk1C;
    u8  pad20[0x22 - 0x20];
    s16 unk22;
    u8  unk24;
};

void func_1518AA10(struct Obj1518AA10 *arg0) {
    struct Obj1518AA10 *obj;
    struct Child1518AA10 *child;

    obj = arg0;
    if (obj->unk1C != 0) {
        if (obj->unk22 < 0) {
            child = obj->unk14;
            if (child->unk18 == 0) {
                obj->unk10 = 0;
                obj->unk14 = 0;
            } else {
                child->unk18->unk14 = 0;
                obj->unk14 = child->unk18;
            }
            if (child->unk1C != 0) {
                D_8008D5C0[child->unk1C](child->unk10);
            }
            func_1516972C((struct102 *)child);
            obj->unk1C -= 1;
        } else if (obj->unk24 & 1) {
            obj->unk22 -= D_800BE9E4;
        }
    }
}

s32 func_15167A68(s32, s32, s32, s32, s32, s32);

typedef struct struct_1518AB60 struct_1518AB60;

typedef struct {
    u8  pad0[0x10];
    struct_1518AB60 *unk10;
    struct_1518AB60 *unk14;
    s32 unk18;
    s32 unk1C;
    s16 unk20;
    s16 unk22;
    u8  unk24;
} struct_1518AADC;

struct_1518AADC *func_1518AADC(s32 arg0, s16 arg1, u8 arg2) {
    struct_1518AADC *ret;

    ret = func_15167A68(0x1D, 0, 0x28, 1, 0xFF, 1);
    if (ret == 0) {
        return NULL;
    }
    ret->unk1C = 0;
    ret->unk18 = arg0;
    ret->unk22 = arg1;
    ret->unk20 = arg1;
    ret->unk10 = 0;
    ret->unk14 = 0;
    ret->unk24 = arg2;
    return ret;
}

struct struct_1518AB60 {
    u8  pad0[0x10];
    s32 unk10;
    struct_1518AB60 *unk14;
    struct_1518AB60 *unk18;
    u8  unk1C;
};

struct_1518AB60 *func_1518AB60(s32 arg0, u8 arg1) {
    struct_1518AB60 *ret;

    ret = func_15167A68(0x1E, 0, 0x20, 1, 0xFF, 1);
    if (ret == 0) {
        return NULL;
    }
    ret->unk10 = arg0;
    ret->unk1C = arg1;
    ret->unk14 = 0;
    ret->unk18 = 0;
    return ret;
}

s32 func_1518ABD0(struct_1518AADC *arg0, s32 arg1, u8 arg2) {
    struct_1518AB60 *child;
    struct_1518AADC *obj;

    obj = arg0;
    if (obj == 0) {
        if (arg2 != 0) {
            D_8008D5C0[arg2](arg1);
        }
        return 0;
    }

    child = func_1518AB60(arg1, arg2);
    if (child == 0) {
        if (arg2 != 0) {
            D_8008D5C0[arg2](arg1);
        }
        return 0;
    }

    child->unk14 = obj->unk10;
    if (child->unk14 != 0) {
        child->unk14->unk18 = child;
    } else {
        obj->unk14 = child;
    }
    obj->unk10 = child;
    child->unk18 = 0;

    obj->unk22 = obj->unk20;
    obj->unk1C += 1;
    if (obj->unk18 < obj->unk1C) {
        child = obj->unk14;
        obj->unk1C -= 1;
        if (child->unk18 == 0) {
            obj->unk10 = 0;
            obj->unk14 = 0;
        } else {
            child->unk18->unk14 = 0;
            obj->unk14 = child->unk18;
        }
        if (child->unk1C != 0) {
            D_8008D5C0[child->unk1C](child->unk10);
        }
        func_1516972C((struct102 *)child);
    }

    return 1;
}
