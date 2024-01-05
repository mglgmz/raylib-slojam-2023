#include "level_system.h"
#include "text.h"

void InitLevelSystem(void)
{
    int current = 0;
    float baseInterval = 6.0f;
    float secondInterval = 11.0f;
    float baseFactor = 1.05f;

    // TOP
    spawners[current++] = (AsteroidSpawner) {
        .minX = 0,
        .maxX = gameWidth,
        .minY = 0,
        .maxY = 0,
        .minSpawns = 1,
        .maxSpawns = 2,
        .offsetDirection = -1,
        .offsetCoord = 'y',
        .minAsteroidDirection = RADS_45,
        .maxAsteroidDirection = RADS_135,
        .minSize = 1,
        .maxSize = 3,
        .minAsteroidSpeed = 3,
        .maxAsteroidSpeed = 10,
        .interval = baseInterval,
        .ts = 3.0f,
        .factor = baseFactor,
        .intervalReduction = 0.15f,
        .upgradeTime = 20.0f,
        .upgradeTs = 0.0f,
        .time = 0.0f
    };
    spawners[current++] = (AsteroidSpawner) {
        .minX = 0,
        .maxX = gameWidth,
        .minY = 0,
        .maxY = 0,
        .minSpawns = 1,
        .maxSpawns = 2,
        .offsetDirection = -1,
        .offsetCoord = 'y',
        .minAsteroidDirection = RADS_45,
        .maxAsteroidDirection = RADS_135,
        .minSize = 2,
        .maxSize = 3,
        .minAsteroidSpeed = 3,
        .maxAsteroidSpeed = 10,
        .interval = secondInterval,
        .ts = 3.0f,
        .factor = 1.10f,
        .intervalReduction = 0.15f,
        .upgradeTime = 20.0f,
        .upgradeTs = 0.0f,
        .time = 90.0f
    };
    
    spawners[current++] = (AsteroidSpawner) {
        .minX = 0,
        .maxX = gameWidth,
        .minY = gameHeight,
        .maxY = gameHeight,
        .minSpawns = 1,
        .maxSpawns = 2,
        .offsetDirection = 1,
        .offsetCoord = 'y',
        .minAsteroidDirection = RADS_225,
        .maxAsteroidDirection = RADS_315,
        .minSize = 1,
        .maxSize = 3,
        .minAsteroidSpeed = 3,
        .maxAsteroidSpeed = 10,
        .interval = baseInterval,
        .ts = 3.0f,
        .factor = baseFactor,
        .intervalReduction = 0.15f,
        .upgradeTime = 20.0f,
        .upgradeTs = 0.0f,
        .time = 0.0f
    };
    spawners[current++] = (AsteroidSpawner) {
        .minX = 0,
        .maxX = gameWidth,
        .minY = gameHeight,
        .maxY = gameHeight,
        .minSpawns = 1,
        .maxSpawns = 2,
        .offsetDirection = 1,
        .offsetCoord = 'y',
        .minAsteroidDirection = RADS_225,
        .maxAsteroidDirection = RADS_315,
        .minSize = 2,
        .maxSize = 3,
        .minAsteroidSpeed = 3,
        .maxAsteroidSpeed = 10,
        .interval = secondInterval,
        .ts = 3.0f,
        .factor = 1.10f,
        .intervalReduction = 0.15f,
        .upgradeTime = 20.0f,
        .upgradeTs = 0.0f,
        .time = 90.0f
    };

    spawners[current++] = (AsteroidSpawner) {
        .minX = 0,
        .maxX = 0,
        .minY = 0,
        .maxY = gameHeight,
        .minSpawns = 1,
        .maxSpawns = 2,
        .offsetDirection = -1,
        .offsetCoord = 'x',
        .minAsteroidDirection = RADS_315,
        .maxAsteroidDirection = RADS_405,
        .minSize = 1,
        .maxSize = 3,
        .minAsteroidSpeed = 3,
        .maxAsteroidSpeed = 10,
        .interval = baseInterval,
        .ts = 3.0f,
        .factor = baseFactor,
        .intervalReduction = 0.15f,
        .upgradeTime = 20.0f,
        .upgradeTs = 0.0f,
        .time = 0.0f
    };
    spawners[current++] = (AsteroidSpawner) {
        .minX = 0,
        .maxX = 0,
        .minY = 0,
        .maxY = gameHeight,
        .minSpawns = 1,
        .maxSpawns = 2,
        .offsetDirection = -1,
        .offsetCoord = 'x',
        .minAsteroidDirection = RADS_315,
        .maxAsteroidDirection = RADS_405,
        .minSize = 2,
        .maxSize = 3,
        .minAsteroidSpeed = 3,
        .maxAsteroidSpeed = 10,
        .interval = secondInterval,
        .ts = 3.0f,
        .factor = 1.10f,
        .intervalReduction = 0.15f,
        .upgradeTime = 20.0f,
        .upgradeTs = 0.0f,
        .time = 90.0f
    };

    spawners[current++] = (AsteroidSpawner) {
        .minX = gameWidth,
        .maxX = gameWidth,
        .minY = 0,
        .maxY = gameHeight,
        .minSpawns = 1,
        .maxSpawns = 2,
        .offsetDirection = 1,
        .offsetCoord = 'x',
        .minAsteroidDirection = RADS_135,
        .maxAsteroidDirection = RADS_225,
        .minSize = 1,
        .maxSize = 3,
        .minAsteroidSpeed = 3,
        .maxAsteroidSpeed = 10,
        .interval = baseInterval,
        .ts = 3.0f,
        .factor = baseFactor,
        .intervalReduction = 0.15f,
        .upgradeTime = 20.0f,
        .upgradeTs = 0.0f,
        .time = 0.0f
    };
    spawners[current++] = (AsteroidSpawner) {
        .minX = gameWidth,
        .maxX = gameWidth,
        .minY = 0,
        .maxY = gameHeight,
        .minSpawns = 1,
        .maxSpawns = 2,
        .offsetDirection = 1,
        .offsetCoord = 'x',
        .minAsteroidDirection = RADS_135,
        .maxAsteroidDirection = RADS_225,
        .minSize = 2,
        .maxSize = 3,
        .minAsteroidSpeed = 3,
        .maxAsteroidSpeed = 10,
        .interval = secondInterval,
        .ts = 3.0f,
        .factor = 1.10f,
        .intervalReduction = 0.15f,
        .upgradeTime = 20.0f,
        .upgradeTs = 0.0f,
        .time = 90.0f
    };

}

int GetCoordinate(int minValue, int maxValue) {
    if(minValue == maxValue) return maxValue;
    return GetRandomValue(minValue, maxValue);
}

int GetRandomAsteroidSize(int min, int max)
{
    int sizeExp = GetRandomValue(min, max);
    int size = ASTEROID_BASE_SIZE;
    for (int i = 1; i <= sizeExp; i++)
        size *= 2;
    return size;
}

void UpdateLevelSystem(void)
{
    for(int i = 0; i < ACTIVE_SPAWNERS; i++) {
        AsteroidSpawner *spawner = &spawners[i];

        if(spawner->time > 0.0f) {
            spawner->time -= GetFrameTime();
            continue;
        }

        spawner->ts += GetFrameTime();
        if(spawner->ts >= spawner->interval) {
            int spawns = GetRandomValue(spawner->minSpawns, spawner->maxSpawns);
            TraceLog(LOG_INFO, "Spawning Asteroids");
            for(int j = 0; j < spawns; j++) {
                int size = GetRandomAsteroidSize(spawner->minSize, spawner->maxSize);
                float x = GetCoordinate(spawner->minX, spawner->maxX);
                float y = GetCoordinate(spawner->minY, spawner->maxY);

                if(spawner->offsetCoord == 'x') {
                    x += (float)(size * spawner->offsetDirection);
                } else {
                    y += (float)(size * spawner->offsetDirection);
                }

                SpawnAsteroid(
                    x,
                    y,
                    size,
                    (float)GetRandomValue(spawner->minAsteroidSpeed, spawner->maxAsteroidSpeed),
                    GetRandomRadsBetween(spawner->minAsteroidDirection, spawner->maxAsteroidDirection)
                );
            }
            spawner->ts = 0.0f;
        }

        spawner->upgradeTs += GetFrameTime();

        if(spawner->upgradeTime > 0.0f && spawner->upgradeTs >= spawner->upgradeTime) {
            TraceLog(LOG_INFO, "Upgrade Spawner");
            spawner->minAsteroidSpeed = spawner->minAsteroidSpeed * spawner->factor;
            spawner->maxAsteroidSpeed = spawner->maxAsteroidSpeed * spawner->factor;
            spawner->factor *= spawner->factor;

            spawner->interval = spawner->interval - spawner->intervalReduction;
            spawner->upgradeTs = 0.0f;
        }

    }
}

void ReleaseLevelSystem(void)
{
    // nothing to do here yet
}
