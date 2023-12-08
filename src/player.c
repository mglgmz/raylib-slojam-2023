#include "player.h"
#include "utils.h"
#include <raylib.h>

#define ROTATION_SPEED 80 * (PI / 180)
#define MOVEMENT_SPEED 25

#define P_SIDE 4.0f
#define HALF_P_SIDE P_SIDE / 2.0f
#define P_HEIGHT_OFF (P_SIDE * sqrt(3) / 2) / 2

static player_t player = {
    .x = 200,
    .y = 100,
    .visible = true,

    .rotation = 0,
    .rotationSpeed = ROTATION_SPEED,

    .speed = MOVEMENT_SPEED,
    .velocity = 0
};

int directionX;
int directionY;

void UpdatePlayer(void) {
    float dt = GetFrameTime();

    if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A))
        player.rotation -= player.rotationSpeed * dt;
    else if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D))
        player.rotation += player.rotationSpeed * dt;

    NormalizeAngle(&player.rotation);
        
    if (IsKeyDown(KEY_UP) || IsKeyDown(KEY_W))
        player.velocity = player.speed;
    else
        player.velocity = 0;

    float rotSin = sinf(player.rotation);
    float rotCos = cosf(player.rotation);

    player.velocityX += rotCos * player.velocity * dt;
    player.velocityY += rotSin * player.velocity * dt;

    player.x += player.velocityX * dt;
    player.y += player.velocityY * dt;

    WrapPosition(&player.x, &player.y);

    directionX = rotCos * 2 + player.x;
    directionY = rotSin * 2 + player.y;
}

void RenderPlayer(void) {
    
    DrawPolyLines((Vector2) { player.x, player.y }, 3, P_SIDE, RadiansToDegrees(player.rotation), PLAYER_COLOR);
    DrawPoly((Vector2) { directionX, directionY }, 3, HALF_P_SIDE , RadiansToDegrees(player.rotation), SKYBLUE);
}