#ifndef PLAYER_H
#define PLAYER_H

#include "utils.h"
#include "entity_list.h"
#include "powerup.h"

#define BULLET_SPEED 70

static EntityList bullets;

#define SPEED_LEVELS 5
static float speedByLevel[SPEED_LEVELS] = {
    20,
    30,
    40,
    50,
    60
};
#define ROTATION_SPEED_LEVELS 5
static float rotationSpeedByLevel[ROTATION_SPEED_LEVELS] = {
     80 * DEG2RAD,
    100 * DEG2RAD,
    120 * DEG2RAD,
    150 * DEG2RAD,
    210 * DEG2RAD
};

typedef struct
{
    float x;
    float y;
    bool visible;

    float rotation;

    float acceleration;
    float velocity;

    int speedLevel;
    int rotationSpeedLevel;

    float velocityX;
    float velocityY;

    int currentLife;
    int maxLife;

    int powerUps;
    int apocaplipsis;
    int ricochetLevel;
} Player;

void InitPlayer(void);
void UpdatePlayer(void);
void RenderPlayer(void);
void ReleasePlayer(void);

void HitPlayer(Player *player, int damage);

void AddPlayerPowerUp(int id);

EntityList *GetBullets();

void OnBulletHit(Entity *bullet);

Player *GetPlayer();

#endif