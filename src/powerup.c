#include "powerup.h"

PowerUp availablePowerUps[AVAILABLE_POWERUPS] = {
    { SPEED,            "A", 7.0f, "Speed Up!" },
    { ROTATION_SPEED,   "B", 7.0f, "Rotation Up!" },
    { SPLIT_SHOT,       "C", 5.0f, "Split Shot" },
    { TRIPLE_SHOT,      "D", 5.0f, "Triple Shot" },
    { CONE_SHOT,        "E", 5.0f, "Cone Shot" },
    { RICOCHET,         "F", 5.0f, "Ricochet" },
    { BACK_SHOT,        "G", 5.0f, "Back Shot" },
    { APOCALIPSIS,      "Z", 3.0f, "" }
};

PowerUp* GetAvailablePowerUps(void) {
    return availablePowerUps;
}