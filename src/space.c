#include "space.h"

#define INITIAL_ASTEROIDS 5

int GetRandomAsteroidSize()
{
    int sizeExp = GetRandomValue(1, 3);
    int size = ASTEROID_BASE_SIZE;
    for (int i = 1; i <= sizeExp; i++)
        size *= 2;
    return size;
}

void SpawnAsteroid(float x, float y, int size, float speed, int rotation)
{
    Entity asteroid = {
        .x = x,
        .y = y,
        .dx = 0,
        .dy = 0,
        .size = size,
        .shape = 1,
        .speed = speed,
        .rotation = rotation, // direction
        .active = 1
    };

    float rotSin = sinf(asteroid.rotation);
    float rotCos = cosf(asteroid.rotation);

    asteroid.dx = rotCos * asteroid.speed;
    asteroid.dy = rotSin * asteroid.speed;

    EntityList_Add(&asteroids, &asteroid);
}

void InitSpace()
{
    EntityList_Init(&asteroids, 2 * INITIAL_ASTEROIDS);
    for (int i = 0; i < INITIAL_ASTEROIDS; i++)
    {
        SpawnAsteroid(
            GetRandomValue(0, gameWidth),
            GetRandomValue(0, gameHeight),
            GetRandomAsteroidSize(),
            (float)GetRandomValue(3, 18),
             GetRandomValue(0, 360)
        );
    }
}

void RenderSpace()
{
    for (int i = 0; i < asteroids.used; i++)
    {
        Entity asteroid = asteroids.array[i];
        DrawCircleLines(asteroid.x, asteroid.y, asteroid.size, ASTEROID_BASE_COLOR);
    }
}

void ReleaseSpace()
{
    EntityList_Free(&asteroids);
}

EntityList* GetAsteroids() {
    return &asteroids;
}