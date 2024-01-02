#ifndef DROP_SYSTEM_H
#define DROP_SYSTEM_H

#include <raylib.h>
#include "defs.h"
#include "entity_list.h"
#include "level_system.h"
#include "powerup.h"


typedef enum LootType {
    ASTEROID = 1, 
    ENEMY = 5
} LootType;

// static const PowerUpTableEntry asteroidsLootTable[AVAILABLE_POWERUPS] = {
// {}
// };

// static const PowerUpTableEntry enemyLootTable[AVAILABLE_POWERUPS] = {
// {}
// };

static Sound powerUpSound;
static EntityList drops;

void InitDropSystem(void);
void ReleaseDropSystem(void);
void RenderDropSystem(void);
void UpdateDropSystem(void);

void RollDrop(int type, int size, float x, float y);

#endif