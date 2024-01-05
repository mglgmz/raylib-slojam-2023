#include "space.h"
#include "text.h"

// Asteroid List Management
void AsteroidList_Init(AsteroidList *list, int inicialCapacity);
void AsteroidList_Add(AsteroidList *list, Asteroid *entity);
void AsteroidList_Delete(AsteroidList *list, int index);
void AsteroidList_Free(AsteroidList *list);

#define ASTEROID_ROTATION_SPEED 40 * (PI / 180)

void SpawnAsteroid(float x, float y, int size, float speed, float rotation)
{
    Asteroid asteroid = {
        .x = x,
        .y = y,
        .dx = 0,
        .dy = 0,
        .size = size,
        .speed = speed,
        .rotation = rotation, // GetRandomFloat() * TWO_PI, // direction
        .rotationSpeed = ASTEROID_ROTATION_SPEED * GetRandomFloat(),
        .active = 1};

    float rotSin = sinf(asteroid.rotation);
    float rotCos = cosf(asteroid.rotation);

    asteroid.dx = rotCos * asteroid.speed;
    asteroid.dy = rotSin * asteroid.speed;
    asteroid.health = 1;

    for (int i = 0; i < ASTEROID_VERTS; i++)
    {
        float verticeRadius = GetRandomFloat() * 0.5f + 0.7f;
        float angle = ((float)i / (float)ASTEROID_VERTS) * TWO_PI;
        asteroid.vertices[i].x = verticeRadius * cosf(angle);
        asteroid.vertices[i].y = verticeRadius * sinf(angle);
    }

    AsteroidList_Add(&asteroids, &asteroid);
}

void DespawnAsteroid(int index)
{
    AsteroidList_Delete(&asteroids, index);
}

void InitSpace()
{
    AsteroidList_Init(&asteroids, 12);
}

void RenderSpace()
{
    AsteroidVertice drawVertices[ASTEROID_VERTS];

    for (int i = 0; i < asteroids.used; i++)
    {

        Asteroid asteroid = asteroids.array[i];
        for (int v = 0; v < ASTEROID_VERTS; v++)
        {
            drawVertices[v] = (AsteroidVertice){asteroid.vertices[v].x, asteroid.vertices[v].y};
            // rotation
            drawVertices[v].x = asteroid.vertices[v].x * cosf(asteroid.rotation) - asteroid.vertices[v].y * sinf(asteroid.rotation);
            drawVertices[v].y = asteroid.vertices[v].x * sinf(asteroid.rotation) + asteroid.vertices[v].y * cosf(asteroid.rotation);

            // scale: can this be done on intialization?
            drawVertices[v].x = drawVertices[v].x * asteroid.size;
            drawVertices[v].y = drawVertices[v].y * asteroid.size;
            // translation
            drawVertices[v].x = drawVertices[v].x + asteroid.x;
            drawVertices[v].y = drawVertices[v].y + asteroid.y;
        }

        for (int v = 0; v < ASTEROID_VERTS + 1; v++)
        {
            int j = (v + 1);

            DrawLine(
                drawVertices[v % ASTEROID_VERTS].x, drawVertices[v % ASTEROID_VERTS].y,
                drawVertices[j % ASTEROID_VERTS].x, drawVertices[j % ASTEROID_VERTS].y,
                COLOR_B);
            if (asteroid.heavy)
                DrawTriangle(
                    (Vector2){asteroid.x, asteroid.y},
                    (Vector2){drawVertices[j % ASTEROID_VERTS].x, drawVertices[j % ASTEROID_VERTS].y},
                    (Vector2){drawVertices[v % ASTEROID_VERTS].x, drawVertices[v % ASTEROID_VERTS].y},
                    COLOR_B);
        }
        // colliders, TODO: make a way to turn all colliders drawing globally
        // DrawCircleLines(asteroid.x, asteroid.y, asteroid.size, MAGENTA);
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
    if (asteroid->size > ASTEROID_BASE_SIZE)
    {
        if (asteroid->size > 8)
            ShakeScreen(asteroid->size);
        float halfSize = asteroid->size / 2;
        // spawn new asteroids
        SpawnAsteroid(
            asteroid->x + GetRandomValue(-halfSize, halfSize),
            asteroid->y + GetRandomValue(-halfSize, halfSize),
            asteroid->size / 2,
            asteroid->speed,
            GetRandomRads());
        SpawnAsteroid(
            asteroid->x + GetRandomValue(-halfSize, halfSize),
            asteroid->y + GetRandomValue(-halfSize, halfSize),
            asteroid->size / 2,
            asteroid->speed,
            GetRandomRads());
    }

    asteroid->active = 0;

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
void AsteroidList_Init(AsteroidList *list, int initialCapacity)
{
    Asteroid *asteroids;
    asteroids = malloc(sizeof(Asteroid) * initialCapacity);
    if (asteroids == NULL)
    {
        TraceLog(LOG_ERROR, "AsteroidList_Init Unable to allocate memory");
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

void AsteroidList_Add(AsteroidList *list, Asteroid *entity)
{
    Asteroid *asteroids;
    list->used += 1;

    if (list->used >= list->size)
    {
        list->size = list->size * 2;
        asteroids = (Asteroid *)realloc(list->array, list->size * sizeof(Asteroid));
        if (asteroids == NULL)
        {
            TraceLog(LOG_ERROR, "AsteroidList_Add Unable to allocate memory");
            free(asteroids);
            exit(0);
        }
        list->array = asteroids;
    }
    list->array[list->used - 1] = *entity;
}

void AsteroidList_Delete(AsteroidList *list, int index)
{
    int i;
    for (i = index; i < list->size; i++)
    {
        list->array[i] = list->array[i + 1];
    }
    list->used -= 1;
}

void AsteroidList_Free(AsteroidList *list)
{
    free(list->array);
    // list->array = NULL;
    list->size = 0;
}