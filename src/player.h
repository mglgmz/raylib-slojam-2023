#ifndef PLAYER_H
#define PLAYER_H

#include "utils.h"
#include "entity_list.h"
#include "powerup.h"

#define BULLET_SPEED 70
#define MOVEMENT_ENERGY_FACTOR 2.0f
#define ENERGY_PER_SECOND 2.0f
#define SHOOT_COST 2.5f;

static EntityList bullets;

#define SPEED_LEVELS 6
static float speedByLevel[SPEED_LEVELS] = {
    25,
    35,
    45,
    55,
    65,
    80
};
#define ROTATION_SPEED_LEVELS 6
static float rotationSpeedByLevel[ROTATION_SPEED_LEVELS] = {
     50 * DEG2RAD,
     80 * DEG2RAD,
    115 * DEG2RAD,
    150 * DEG2RAD,
    210 * DEG2RAD,
    220 * DEG2RAD
};

#define RICOCHET_LEVELS 3

#define ENERGY_LEVELS 6
static int maxEnergyByLevel[ENERGY_LEVELS] = {
    120,
    150,
    190,
    240,
    280,
    300
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

    float energy;
    int energyLevel;

    float shootCost;
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