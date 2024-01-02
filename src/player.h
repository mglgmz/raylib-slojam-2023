#ifndef PLAYER_H
#define PLAYER_H

#include "utils.h"
#include "entity_list.h"
#include "powerup.h"

static EntityList bullets;
static int powerUps;

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

void HitPlayer(Player* player, int damage);

void AddPlayerPowerUp(int id);

EntityList* GetBullets();
Player* GetPlayer();

#endif