#ifndef SPACE_H
#define SPACE_H

#include <raylib.h>
#include "entity_list.h"
#include "utils.h"
#include "particles.h"
#include "renderer.h"

#define ASTEROID_VERTS 12

typedef struct AsteroidVertice {
    float x;
    float y;
} AsteroidVertice;

typedef struct Asteroid {
    float x;
    float y;
    float dx;
    float dy;
    float speed;
    int size;
    float rotation;
    float rotationSpeed;
    int active;
    int heavy;
    int health;
    AsteroidVertice vertices[ASTEROID_VERTS];
} Asteroid;

typedef struct AsteroidList {
    Asteroid *array;
    size_t size;
    size_t used;
} AsteroidList;

static AsteroidList asteroids;

void InitSpace();
void RenderSpace();
void ReleaseSpace();

void SpawnAsteroid(float x, float y, int size, float speed, float rotation);
void DespawnAsteroid(int index);

AsteroidList* GetAsteroids();

void OnAsteroidHit(Asteroid* asteroid, float hitX, float hitY);

#endif