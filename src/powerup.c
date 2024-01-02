#include "powerup.h"

PowerUp availablePowerUps[AVAILABLE_POWERUPS] = {
    { SPEED,            "A", 7.0f },
    { ROTATION_SPEED,   "B", 7.0f },
    { SPLIT_SHOT,       "C", 5.0f },
    { TRIPLE_SHOT,      "D", 5.0f },
    { CONE_SHOT,        "E", 5.0f },
    { RICOCHET,         "F", 5.0f },
    { BACK_SHOT,        "G", 5.0f },
    { APOCALIPSIS,      "Z", 3.0f }
};

PowerUp* GetAvailablePowerUps(void) {
    return availablePowerUps;
}