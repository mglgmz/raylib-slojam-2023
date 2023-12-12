#ifndef PARTICLES_H
#define PARTICLES_H

#include <stdlib.h>
#include <raylib.h>
#include "entity_list.h"

static EntityList particles;

void InitParticles();
void UpdateParticles();
void RenderParticles();
void ReleaseParticles();

void AddParticle(Entity* particle);

#endif