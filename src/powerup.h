#ifndef POWERUP_H
#define POWERUP_H

#define AVAILABLE_POWERUPS 8

typedef enum PowerUpIds {
    SPEED =             2 << 0,
    ROTATION_SPEED =    2 << 1,
    BACK_THRUST =       2 << 2,
    TRIPLE_SHOT =       2 << 3,
    CONE_SHOT =         2 << 4,
    RICOCHET =          2 << 5,
    BACK_SHOT =         2 << 6,
    // CLONES =         2 << 7,
    ENERGY_UP =         2 << 8,
    APOCALIPSIS =       2 << 9
} PowerUpIds;

typedef struct PowerUp {
    int id;
    const char* display;
    float duration;
    const char* particle;
} PowerUp;

extern PowerUp availablePowerUps[AVAILABLE_POWERUPS];

#endif