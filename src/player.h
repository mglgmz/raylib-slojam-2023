#ifndef PLAYER_H
#define PLAYER_H

#include "utils.h"
#include "entity_list.h"

static EntityList bullets;

typedef struct {
    float x;
    float y;
    bool visible;

    float rotation;
    float rotationSpeed;

    float speed;
    float acceleration;
    float velocity;

    float velocityX;
    float velocityY;
    
    int currentLife;
    int maxLife;
} Player;

void InitPlayer(void);
void UpdatePlayer(void);
void RenderPlayer(void);
void ReleasePlayer(void);

EntityList* GetBullets();
Player* GetPlayer();

#endif