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
    15,
    25,
    35,
    45,
    55,
    70
};
#define ROTATION_SPEED_LEVELS 6
static float rotationSpeedByLevel[ROTATION_SPEED_LEVELS] = {
     70 * DEG2RAD,
     85 * DEG2RAD,
    105 * DEG2RAD,
    130 * DEG2RAD,
    160 * DEG2RAD,
    200 * DEG2RAD
};

#define RICOCHET_LEVELS 3

#define ENERGY_LEVELS 6
static float maxEnergyByLevel[ENERGY_LEVELS] = {
    120.0f,
    150.0f,
    190.0f,
    240.0f,
    280.0f,
    300.0f
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