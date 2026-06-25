#include <ultra64.h>
#include "functions.h"
#include "variables.h"

typedef struct {
    u8 pad0[0x14];
    s16 unk14;
    u8 pad16;
    u8 unk17;
} struct_8008D050;

extern void *allocate_memory(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern struct_8008D050 D_8008D050[];
extern u8 D_800DDE54[];
extern u8 *D_800DDE60[];


void func_15008E00(void) {
    D_800DDE50 = (u8)0;
}

void func_15008E10(s32 arg0) {
    s32 i;
    f32 temp;
    struct_8008D050 *entry;

    D_800DDE54[D_800DDE50] = arg0;
    D_800DDE60[D_800DDE50] = allocate_memory(0x1E0, 1, 0, 0);

    for (i = 0; i != 0x1E0; i += 0x30) {
        *(f32 *)(D_800DDE60[D_800DDE50] + i) = 0.0f;
        temp = *(f32 *)(D_800DDE60[D_800DDE50] + i);
        *(f32 *)(D_800DDE60[D_800DDE50] + i + 4) = temp;
        *(f32 *)(D_800DDE60[D_800DDE50] + i + 8) = temp;
        *(f32 *)(D_800DDE60[D_800DDE50] + i + 0xC) = 0.0f;
        temp = *(f32 *)(D_800DDE60[D_800DDE50] + i + 0xC);
        *(f32 *)(D_800DDE60[D_800DDE50] + i + 0x10) = temp;
        *(f32 *)(D_800DDE60[D_800DDE50] + i + 0x14) = temp;
        *(f32 *)(D_800DDE60[D_800DDE50] + i + 0x18) = 0.0f;
        temp = *(f32 *)(D_800DDE60[D_800DDE50] + i + 0x18);
        *(f32 *)(D_800DDE60[D_800DDE50] + i + 0x1C) = temp;
        *(f32 *)(D_800DDE60[D_800DDE50] + i + 0x20) = temp;
        *(f32 *)(D_800DDE60[D_800DDE50] + i + 0x24) = 0.0f;
        temp = *(f32 *)(D_800DDE60[D_800DDE50] + i + 0x24);
        *(f32 *)(D_800DDE60[D_800DDE50] + i + 0x28) = temp;
        *(f32 *)(D_800DDE60[D_800DDE50] + i + 0x2C) = temp;
    }

    entry = &D_8008D050[arg0];
    *(f32 *)(D_800DDE60[D_800DDE50] + 0x1DC) = entry->unk14;
    entry->unk17 = 0;
    D_800DDE50++;
}
