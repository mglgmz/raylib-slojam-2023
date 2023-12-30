#ifndef LEVEL_SYSTEM_H
#define LEVEL_SYSTEM_H

#include "raylib.h"
#include "defs.h"
#include "space.h"

#define MAX_LEVELS 3

typedef struct LevelDefinition
{
    char* levelName;
    int minNumberOfAsteroids;
    int maxNumberOfAsteroids;
    int minAsteroidSize;
    int maxAsteroidSize;
    int minNumberOfEnemies;
    int maxNumberOfEnemies;
    float levelModifier;
} LevelDefinition;

static const int maxLevels = MAX_LEVELS;
static int levelIteration = 0;
static LevelDefinition levels[MAX_LEVELS] = {
    { "", 4, 4, 1, 2, 0, 0, 0.0f }, 
    { "Alpha", 4, 6, 1, 3, 0, 0, 0.0f }, 
    { "Beta", 8, 12, 2, 3, 0, 0, 1.0f }, 
};

static int currentLevel = 0;

void InitLevelSystem(void);
void ReleaseLevelSystem(void);

void LoadCurrentLevel(void);

void UpdateLevelSystem(void);
void RenderLevelSystem(void);

LevelDefinition GetCurrentLevel(void);
const char* GetCurrentLevelName(void);

#endif