#include "space.h"

#define INITIAL_ASTEROIDS 2 // Number of Asteroids Per Sector

// Asteroid List Management
void AsteroidList_Init(AsteroidList *list, int inicialCapacity);
void AsteroidList_Add(AsteroidList *list, Asteroid *entity);
void AsteroidList_Delete(AsteroidList *list, int index);
void AsteroidList_Free(AsteroidList *list);

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
    Asteroid asteroid = {
        .x = x,
        .y = y,
        .dx = 0,
        .dy = 0,
        .size = size,
        .speed = speed,
        .rotation = rotation, // direction
        .active = 1
    };

    float rotSin = sinf(asteroid.rotation);
    float rotCos = cosf(asteroid.rotation);

    asteroid.dx = rotCos * asteroid.speed;
    asteroid.dy = rotSin * asteroid.speed;

    AsteroidList_Add(&asteroids, &asteroid);
}

void DespawnAsteroid(int index) {
    AsteroidList_Delete(&asteroids, index);
}

void InitSpace()
{
    AsteroidList_Init(&asteroids, 2 * INITIAL_ASTEROIDS);

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
        Asteroid asteroid = asteroids.array[i];
        DrawCircleLines(asteroid.x, asteroid.y, asteroid.size, COLOR_B);
    }
}

void ReleaseSpace()
{
    AsteroidList_Free(&asteroids);
}

AsteroidList *GetAsteroids()
{
    return &asteroids;
}

void OnAsteroidHit(Asteroid *asteroid, float hitX, float hitY)
{
    // Number of particles based on asteroid size???
    int particles = 8;
    for (int i = 0; i < particles; i++)
    {
        float direction = (float)((i * (360 / particles)) + GetRandomValue(-5, 5));
        float rotSin = sinf(direction);
        float rotCos = cosf(direction);
        float speed = ((float)GetRandomValue(10, 100));
        Entity particle = {0};
        particle.active = 1;
        particle.ttl = GetRandomFloat() * 0.4f;
        particle.color = COLOR_B;
        particle.shape = PARTICLE_POINT;
        particle.dx = rotCos * speed;
        particle.dy = rotSin * speed;
        particle.x = hitX;
        particle.y = hitY;
        AddParticle(&particle);
    }
}

// Asteroid List Management
void AsteroidList_Init(AsteroidList *list, int initialCapacity) {
    Asteroid *asteroids;
    asteroids = malloc(sizeof(Asteroid) * initialCapacity);
    if (asteroids == NULL)
    {
        TraceLog(LOG_ERROR, "Unable to allocate memory");
        free(asteroids);
        exit(0);
    }
    else
    {
        list->array = asteroids;
        list->size = initialCapacity;
        list->used = 0;
    }
}

void AsteroidList_Add(AsteroidList *list, Asteroid *entity) {
    Asteroid *asteroids;
    list->used += 1;

    if (list->used >= list->size)
    {
        list->size = list->size * 2;
        asteroids = (Asteroid *)realloc(list->array, list->size * sizeof(Asteroid));
        if (asteroids == NULL)
        {
            TraceLog(LOG_ERROR, "Unable to allocate memory");
            free(asteroids);
            exit(0);
        }
        list->array = asteroids;
    }
    list->array[list->used - 1] = *entity;
}

void AsteroidList_Delete(AsteroidList *list, int index) {
    int i;
    for (i = index; i < list->size; i++)
    {
        list->array[i] = list->array[i + 1];
    }
    list->used -= 1;
}

void AsteroidList_Free(AsteroidList *list) {
    free(list->array);
    //list->array = NULL;
    list->size = 0;
}