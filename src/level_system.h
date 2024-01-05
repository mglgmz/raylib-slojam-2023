#ifndef LEVEL_SYSTEM_H
#define LEVEL_SYSTEM_H

#include "raylib.h"
#include "defs.h"
#include "space.h"

#define MAX_LEVELS 3

typedef struct AsteroidSpawner {
    int minX;
    int maxX;
    int minY;
    int maxY;

    int offsetDirection;
    char offsetCoord;

    float minAsteroidDirection;
    float maxAsteroidDirection;

    int minSpawns;
    int maxSpawns;

    int minSize;
    int maxSize;
    int minAsteroidSpeed;
    int maxAsteroidSpeed;

    float interval;
    float ts;

    float factor;
    float intervalReduction;
    
    float upgradeTime;
    float upgradeTs;
    float time;

} AsteroidSpawner;

#define ACTIVE_SPAWNERS 8
static AsteroidSpawner spawners[ACTIVE_SPAWNERS];

void InitLevelSystem(void);
void ReleaseLevelSystem(void);

void UpdateLevelSystem(void);

#endif