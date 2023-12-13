#include "particles.h"

#define PARTICLES_INITIAL_CAPACITY 100

void InitParticles()
{
    EntityList_Init(&particles, PARTICLES_INITIAL_CAPACITY);
}

void AddParticle(Entity *particle)
{
    EntityList_Add(&particles, particle);
}

void UpdateParticles()
{
    float dt = GetFrameTime();
    for (int i = particles.used - 1; i >= 0; i--)
    {
        Entity *particle = &particles.array[i];
        if (!particle->active)
        {
            EntityList_Delete(&particles, i);
            continue;
        }
        particle->ttl -= dt;
        if (particle->ttl <= 0.0f)
        {
            particle->active = 0;
            continue;
        }

        // TODO: dynamic dx/dy, angular velocity, rotation velocity
        particle->x += particle->dx * dt;
        particle->y += particle->dy * dt;

        if (WrapPosition(&particle->x, &particle->y))
        {
            particle->active = false;
        }
    }
}

void RenderParticles()
{
    for (int i = 0; i < particles.used; i++)
    {
        Entity *particle = &particles.array[i];
        if (!particle->active)
            continue;

        switch (particle->shape)
        {
        case (int)PARTICLE_POINT:
            DrawPixel(particle->x, particle->y, particle->color);
            break;
        }
    }
}

void ReleaseParticles()
{
    EntityList_Free(&particles);
}



EntityList* GetParticles() {
    return &particles;
}