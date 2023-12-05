#include "player.h"

#define ROTATION_SPEED 90 * (PI / 180)
#define MOVEMENT_SPEED 80

#define P_SIDE 20
#define HALF_P_SIDE P_SIDE / 2
#define P_HEIGHT_OFF (P_SIDE * sqrt(3) / 2) / 2

static player_t player = {
    .x = 200,
    .y = 100,
    .visible = true,

    .rotation = 0,
    .rotationSpeed = ROTATION_SPEED,

    .speed = MOVEMENT_SPEED,
    .velocity = 0,
};


void UpdatePlayer(void) {

    if (IsKeyDown(KEY_LEFT))
        player.rotation -= player.rotationSpeed * GetFrameTime();
    else if (IsKeyDown(KEY_RIGHT))
        player.rotation += player.rotationSpeed * GetFrameTime();

    NormalizeAngle(&player.rotation);
        
    if (IsKeyDown(KEY_UP))
        player.velocity = player.speed * GetFrameTime();
    else
        player.velocity = 0;

    player.x += cos(player.rotation) * player.velocity;
    player.y += sin(player.rotation) * player.velocity;
}


void RenderPlayer(void) {
    
    DrawPoly((Vector2) { player.x, player.y }, 3, P_SIDE, RadiansToDegrees(player.rotation), PLAYER_COLOR);

}