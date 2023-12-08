#include "space.h"
#include <stdio.h>
#define INITIAL_ASTEROIDS 10

void InitSpace()
{
    printf("asd");
    EntityList_Init(&asteroids, 2 * INITIAL_ASTEROIDS);
    for (int i = 0; i < INITIAL_ASTEROIDS; i++)
    {
        Entity asteroid = {
            .x = GetRandomValue(0, gameWidth),
            .y = GetRandomValue(0, gameHeight),
            .dx = 0,
            .dy = 0,
            .size = GetRandomValue(5, 25),
            .shape = 1,
            .speed = (float)GetRandomValue(3, 18),
            .rotation = GetRandomValue(0, 360) // direction
        };

        float rotSin = sinf(asteroid.rotation);
        float rotCos = cosf(asteroid.rotation);

        asteroid.dx = rotCos * asteroid.speed;
        asteroid.dy = rotSin * asteroid.speed;

        EntityList_Add(&asteroids, &asteroid);
    }
}

void UpdateSpace()
{
    float dt = GetFrameTime();
    for (int i = 0; i < INITIAL_ASTEROIDS; i++)
    {
        Entity *asteroid = &asteroids.array[i];

        asteroid->x += asteroid->dx * dt;
        asteroid->y += asteroid->dy * dt;

         WrapPosition(&asteroid->x, &asteroid->y);
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