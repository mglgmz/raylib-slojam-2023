#ifndef SPACE_H
#define SPACE_H

#include "entity_list.h"
#include "utils.h"
#include <raylib.h>

static EntityList asteroids;

void InitSpace();
void UpdateSpace();
void RenderSpace();

void ReleaseSpace();

void SpawnAsteroid(float x, float y, int size, float speed, int rotation);

EntityList* GetAsteroids();

#endif