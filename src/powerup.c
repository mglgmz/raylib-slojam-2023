#include "powerup.h"

PowerUp availablePowerUps[AVAILABLE_POWERUPS] = {
    { SPEED,            "A" },
    { ROTATION_SPEED,   "B" },
    { SPLIT_SHOT,       "C" },
    { TRIPLE_SHOT,      "D" },
    { CONE_SHOT,        "E" },
    { RICOCHET,         "F" },
    { BACK_SHOT,        "G" },
    { APOCALIPSIS,      "Z" }
};

PowerUp* GetAvailablePowerUps(void) {
    return availablePowerUps;
}