#include "space.h"

#define INITIAL_ASTEROIDS 2 // Number of Asteroids Per Sector

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
        .active = 1};

    float rotSin = sinf(asteroid.rotation);
    float rotCos = cosf(asteroid.rotation);

    asteroid.dx = rotCos * asteroid.speed;
    asteroid.dy = rotSin * asteroid.speed;

    EntityList_Add(&asteroids, &asteroid);
}

void InitSpace()
{
    EntityList_Init(&asteroids, 2 * INITIAL_ASTEROIDS);

    // Up
    for (int i = 0; i < INITIAL_ASTEROIDS; i++)
    {
        SpawnAsteroid(
            GetRandomValue(0, gameWidth),
            -50,
            GetRandomAsteroidSize(),
            (float)GetRandomValue(3, 18),
            GetRandomValue(0, 360));
    }
    // Down
    for (int i = 0; i < INITIAL_ASTEROIDS; i++)
    {
        SpawnAsteroid(
            GetRandomValue(0, gameWidth),
            gameHeight + 50,
            GetRandomAsteroidSize(),
            (float)GetRandomValue(3, 18),
            GetRandomValue(0, 360));
    }
    for (int i = 0; i < INITIAL_ASTEROIDS; i++)
    {
        SpawnAsteroid(
            -50,
            GetRandomValue(0, gameHeight),
            GetRandomAsteroidSize(),
            (float)GetRandomValue(3, 18),
            GetRandomValue(0, 360));
    }
    for (int i = 0; i < INITIAL_ASTEROIDS; i++)
    {
        SpawnAsteroid(
            gameWidth + 50,
            GetRandomValue(0, gameHeight),
            GetRandomAsteroidSize(),
            (float)GetRandomValue(3, 18),
            GetRandomValue(0, 360));
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

EntityList *GetAsteroids()
{
    return &asteroids;
}

void OnAsteroidHit(Entity *asteroid)
{
    // Number of particles based on asteroid size???
    int particles = 8;
    for (int i = 0; i < 8; i++)
    {
        float direction = (float)((i * (360 / particles)) + GetRandomValue(-5, 5));
        float rotSin = sinf(direction);
        float rotCos = cosf(direction);
        float speed = ((float)GetRandomValue(10, 100));
        Entity particle = {0};
        particle.active = 1;
        particle.ttl = GetRandomFloat() * 0.4f;
        particle.color = RAYWHITE;
        particle.shape = PARTICLE_POINT;
        particle.dx = rotCos * speed;
        particle.dy = rotSin * speed;
        particle.x = asteroid->x;
        particle.y = asteroid->y;
        AddParticle(&particle);
    }
}