#include "level_system.h"
#include "text.h"

#define NEXT_LEVEL_DELAY 2.0f;
static float loadingNextLevelTs = -1.0f;
int loadingNewLevel = 1;
float textSpeed = gameWidth / NEXT_LEVEL_DELAY;
float textX = 0.0f;
void InitLevelSystem(void)
{
    // nothing to do here yet
    loadingNewLevel = 1;
    loadingNextLevelTs = -1.0f;
    currentLevel = 0;
    levelIteration = 0;
}

void UpdateLevelSystem(void)
{
    if (CountKillablesLeft() == 0 && !loadingNewLevel)
    {
        // next level loading
        if (loadingNextLevelTs < 0.0f)
        {
            int newLevel = (currentLevel + 1);
            if(newLevel >= maxLevels) newLevel = maxLevels - 1;
            if (newLevel != currentLevel)
            {
                levelIteration = 0;
            }
            else
            {
                levelIteration++;
            }
            currentLevel = newLevel;
            loadingNextLevelTs = NEXT_LEVEL_DELAY;
            loadingNewLevel = 1;
            textX = gameWidth;
        }
    }
    else if (loadingNewLevel)
    {
        loadingNextLevelTs -= GetFrameTime();
        if (loadingNextLevelTs < 0.0f)
        {
            loadingNewLevel = 0;
            LoadCurrentLevel();
        }
    }
}
int GetRandomAsteroidSize(int min, int max)
{
    int sizeExp = GetRandomValue(min, max);
    int size = ASTEROID_BASE_SIZE;
    for (int i = 1; i <= sizeExp; i++)
        size *= 2;
    return size;
}

int CountKillablesLeft(void) {
    AsteroidList *asteroids = GetAsteroids();
    return asteroids->used;
}

void LoadCurrentLevel(void) {
    LevelDefinition level = GetCurrentLevel();
    int asteroidsPerSector = GetRandomValue(level.minNumberOfAsteroids, level.maxNumberOfAsteroids);
    int minAsteroidSpeed = level.minAsteroidSpeed;
    int maxAsteroidSpeed = level.maxAsteroidSpeed;
   
    if(levelIteration > 0 && level.levelModifier > 0.0f){
        float levelAdjustFactor = (level.levelModifier * (float)levelIteration);
        if(levelAdjustFactor < 1.0f) levelAdjustFactor = 1.0f; // prevent reducing difficulty
        asteroidsPerSector = asteroidsPerSector * levelAdjustFactor;
        minAsteroidSpeed = minAsteroidSpeed * levelAdjustFactor;
        maxAsteroidSpeed = maxAsteroidSpeed * levelAdjustFactor;
    }

    for (int i = 0; i < asteroidsPerSector; i++)
    {
        int size = GetRandomAsteroidSize(level.minAsteroidSize, level.maxAsteroidSize);
        SpawnAsteroid(
            (float)GetRandomValue(0, gameWidth),
            (float)(0 - size),
            size,
            (float)GetRandomValue(minAsteroidSpeed, maxAsteroidSpeed),
            GetRandomRadsBetween(RADS_45, RADS_135));
    }
    for (int i = 0; i < asteroidsPerSector; i++)
    {
        int size = GetRandomAsteroidSize(level.minAsteroidSize, level.maxAsteroidSize);
        SpawnAsteroid(
            (float)GetRandomValue(0, gameWidth),
            (float)(gameHeight + size),
            size,
            (float)GetRandomValue(minAsteroidSpeed, maxAsteroidSpeed),
            GetRandomRadsBetween(RADS_225, RADS_315));
    }
    for (int i = 0; i < asteroidsPerSector; i++)
    {
        int size = GetRandomAsteroidSize(level.minAsteroidSize, level.maxAsteroidSize);
        SpawnAsteroid(
            (float) (0 - size),
            (float)GetRandomValue(0, gameHeight),
            size,
            (float)GetRandomValue(minAsteroidSpeed, maxAsteroidSpeed),
            GetRandomRadsBetween(RADS_315, RADS_405));
    }
    for (int i = 0; i < asteroidsPerSector; i++)
    {
        int size = GetRandomAsteroidSize(level.minAsteroidSize, level.maxAsteroidSize);
        SpawnAsteroid(
            (float)(gameWidth + size),
            (float) GetRandomValue(0, gameHeight),
            size,
           (float)GetRandomValue(minAsteroidSpeed, maxAsteroidSpeed),
            GetRandomRadsBetween(RADS_135, RADS_225));
    }
}

void RenderLevelSystem(void) {
    if(loadingNextLevelTs > 0.0f) {
        const char* currentLevelName = GetCurrentLevelName();
        Text_DrawText(currentLevelName, textX, gameHeight - 14, 14, COLOR_B);
        textX -= textSpeed * GetFrameTime();
    }
}

void ReleaseLevelSystem(void)
{
    // nothing to do here yet
}

LevelDefinition GetCurrentLevel(void)
{
    return levels[currentLevel];
}

const char* GetCurrentLevelName(void)
{
    char* currentLevelName = levels[currentLevel].levelName;
    return TextFormat("%s %i", currentLevelName, levelIteration);
}