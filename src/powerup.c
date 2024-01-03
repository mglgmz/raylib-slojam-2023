#include "powerup.h"

PowerUp availablePowerUps[AVAILABLE_POWERUPS] = {
    { SPEED,            "A", 10.0f, "Speed Up!" },
    { ROTATION_SPEED,   "B", 10.0f, "Rotation Up!" },
    { RESERVED,         "C", 5.0f, "Reserved" },
    { TRIPLE_SHOT,      "D", 8.0f, "Triple Shot" },
    { CONE_SHOT,        "E", 9.0f, "Cone Shot" },
    { RICOCHET,         "F", 8.0f, "Ricochet" },
    { BACK_SHOT,        "G", 8.0f, "Back Shot" },
    { APOCALIPSIS,      "Z", 3.5f, "" }
};

PowerUp* GetAvailablePowerUps(void) {
    return availablePowerUps;
}