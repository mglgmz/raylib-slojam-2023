#ifndef PLAYER_H
#define PLAYER_H

#include "utils.h"

typedef struct {
    float x;
    float y;
    bool visible;

    float rotation;
    float rotationSpeed;

    float speed;
    float velocity;
} player_t;

void UpdatePlayer(void);
void RenderPlayer(void);

#endif