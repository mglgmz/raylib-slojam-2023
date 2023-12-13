#ifndef SPACE_H
#define SPACE_H

#include "entity_list.h"
#include "utils.h"
#include "particles.h"
#include <raylib.h>

static EntityList asteroids;

void InitSpace();
void RenderSpace();
void ReleaseSpace();

void SpawnAsteroid(float x, float y, int size, float speed, int rotation);
EntityList* GetAsteroids();

void OnAsteroidHit(Entity* asteroid);

#endif