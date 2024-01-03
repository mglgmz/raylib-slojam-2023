#include "powerup.h"

PowerUp availablePowerUps[AVAILABLE_POWERUPS] = {
    { SPEED,            "A", 7.0f, "Speed Up!" },
    { ROTATION_SPEED,   "B", 7.0f, "Rotation Up!" },
    { RESERVED,         "C", 5.0f, "Reserved" },
    { TRIPLE_SHOT,      "D", 5.0f, "Triple Shot" },
    { CONE_SHOT,        "E", 5.0f, "Cone Shot" },
    { RICOCHET,         "F", 5.0f, "Ricochet" },
    { BACK_SHOT,        "G", 5.0f, "Back Shot" },
    { APOCALIPSIS,      "Z", 3.0f, "" }
};

PowerUp* GetAvailablePowerUps(void) {
    return availablePowerUps;
}