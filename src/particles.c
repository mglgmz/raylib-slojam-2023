#include "particles.h"

#define PARTICLES_INITIAL_CAPACITY 100

void InitParticles() {
    EntityList_Init(&particles, PARTICLES_INITIAL_CAPACITY);
}

void AddParticle(Entity* particle) {
    EntityList_Add(&particles, particle);
}

void UpdateParticles() {
    float dt = GetFrameTime();
    for(int i = particles.used; i >= 0; i--) {
        Entity* particle = &particles.array[i];
        if(!particle->active) {
            EntityList_Delete(&particles, i);
            continue;
        }
        
        particle->ttl -= dt;
        if(particle->ttl <= 0.0f) {
            particle->active = 0;
        }
    }
}

void RenderParticles() {

}

void ReleaseParticles() {
    EntityList_Free(&particles);
}