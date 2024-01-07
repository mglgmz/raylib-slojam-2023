#include "powerup.h"

PowerUp availablePowerUps[AVAILABLE_POWERUPS] = {
    { SPEED,            "A", 15.0f,  "Speed Up!" },
    { ROTATION_SPEED,   "B", 12.0f,  "Rotation Up!" },
    { BACK_THRUST,      "C", 10.0f,  "Back" },
    { TRIPLE_SHOT,      "D", 10.0f,  "Triple Shot" },
    { CONE_SHOT,        "E", 11.0f,  "Cone Shot" },
    { RICOCHET,         "F", 12.0f,  "Ricochet" },
    { BACK_SHOT,        "G", 15.0f,  "Back Shot" },
    { ENERGY_UP,        "H", 12.0f,  "Energy Up" },
    { APOCALIPSIS,      "Z",  5.0f,  "" }
};

PowerUp* GetAvailablePowerUps(void) {
    return availablePowerUps;
}