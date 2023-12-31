#ifndef SIMULATION_H
#define SIMULATION_H

#include <raylib.h>
#include "space.h"
#include "player.h"
#include "entity_list.h"
#include "utils.h"
#include "renderer.h"

void InitSimulation(void);
void UpdateSimulation(void);
void ReleaseSimulation(void);

#endif