#ifndef POWERUP_H
#define POWERUP_C

#define AVAILABLE_POWERUPS 8

typedef enum PowerUpIds {
    SPEED = 1,
    ROTATION_SPEED = 2,
    SPLIT_SHOT = 5,
    TRIPLE_SHOT = 6,
    CONE_SHOT = 7,
    RICOCHET = 10,
    BACK_SHOT = 11,
    // CLONES = 15,
    // SHIELD = 20,
    APOCALIPSIS = 30
} PowerUpIds;

typedef struct PowerUp {
    int id;
    const char* display;
} PowerUp;

extern PowerUp availablePowerUps[AVAILABLE_POWERUPS];

#endif