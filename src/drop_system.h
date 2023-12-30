#ifndef DROP_SYSTEM_H
#define DROP_SYSTEM_H

#include <raylib.h>
#include "defs.h"

void InitDropSystem(void);
void ReleaseDropSystem(void);

typedef enum LootType {
    ASTEROID = 1, 
    UFO
} LootType;

void RollDrop(int type, int size);

#endif