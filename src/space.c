#include "space.h"
#include <stdio.h>
#define INITIAL_ASTEROIDS 10

void InitSpace() {
    printf("asd");
    EntityList_Init(&asteroids, 2 * INITIAL_ASTEROIDS);
    for(int i =0; i< INITIAL_ASTEROIDS; i++) {
        Entity asteroid= {
            .x = GetRandomValue(0, gameWidth),
            .y = GetRandomValue(0, gameHeight),
            .dx = 0,
            .dy = 0,
            .size = GetRandomValue(5, 25),
            .shape = 1,
            .speed = (float) GetRandomValue(1,12),
            .rotation = GetRandomValue(0, 360) // direction
        };
        EntityList_Add(&asteroids, &asteroid);
    }
}

void UpdateSpace() {

}

void RenderSpace() {
    for(int i =0; i< asteroids.used; i++) {
        Entity asteroid = asteroids.array[i];
        DrawCircleLines(asteroid.x, asteroid.y, asteroid.size, ASTEROID_BASE_COLOR);
    }
}

void ReleaseSpace() {
    EntityList_Free(&asteroids);
}