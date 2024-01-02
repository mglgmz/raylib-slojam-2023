#ifndef PARTICLES_H
#define PARTICLES_H

#include <stdlib.h>
#include <raylib.h>
#include "entity_list.h"
#include "utils.h"

static EntityList particles;

typedef enum ParticleTypes {
    PARTICLE_POINT = 1,
    // TEXT = 2
} ParticleTypes;

void InitParticles();
void UpdateParticles();
void RenderParticles();
void ReleaseParticles();

void AddParticle(Entity* particle);

EntityList* GetParticles();

#endif