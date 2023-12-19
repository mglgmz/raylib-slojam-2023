#include "player.h"
#include "utils.h"
#include <raylib.h>

#define ROTATION_SPEED 80 * (PI / 180)
#define MOVEMENT_SPEED 20
#define BULLET_SPEED 70
#define P_SIDE 4.0f
#define HALF_P_SIDE P_SIDE / 2.0f
#define P_HEIGHT_OFF (P_SIDE * sqrt(3) / 2) / 2

#define SHOOT_BUTTON KEY_SPACE

static Player player = {
    .x = 200,
    .y = 100,
    .visible = true,

    .rotation = 0,
    .rotationSpeed = ROTATION_SPEED,

    .speed = MOVEMENT_SPEED,
    .velocity = 0,

    .maxLife = 2,
    .currentLife = 2
};

int directionX;
int directionY;

void InitPlayer(void) {
    player.currentLife = player.maxLife;
    player.velocityX = 0;
    player.velocityY = 0;
    player.x = 200;
    player.y = 100;

    EntityList_Init(&bullets, 100);
}

void UpdatePlayer(void) {
    if(player.currentLife <= 0) return;

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

    // TODO: TURBO THRUST

    //TODO: move to simulation
    player.x += player.velocityX * dt;
    player.y += player.velocityY * dt;
    WrapPosition(&player.x, &player.y);

    directionX = rotCos * 2 + player.x;
    directionY = rotSin * 2 + player.y;

    if(IsKeyReleased(SHOOT_BUTTON)) {
        Entity bullet = { 0 };       
        bullet.x = directionX;
        bullet.y = directionY;
        bullet.dx = rotCos * BULLET_SPEED;
        bullet.dy = rotSin * BULLET_SPEED;
        bullet.size = 1;
        bullet.speed = BULLET_SPEED;
        bullet.rotation = player.rotation;
        bullet.active = 1;
        EntityList_Add(&bullets, &bullet);
    }
}

void HitPlayer(Player *player, int damage) {
    player->currentLife -= damage;
}

void RenderPlayer(void) {
    if(player.currentLife <= 0) return;
    // TODO: render death animation
     
    DrawPolyLines((Vector2) { player.x, player.y }, 3, P_SIDE, RadiansToDegrees(player.rotation), PLAYER_COLOR);
    DrawPoly((Vector2) { directionX, directionY }, 3, HALF_P_SIDE , RadiansToDegrees(player.rotation), RAYWHITE);

    for (int i = 0; i < bullets.used; i++)
    {
        Entity *bullet = &bullets.array[i];
        DrawPoly((Vector2) { bullet->x, bullet->y }, 4, bullet->size, bullet->rotation, PLAYER_COLOR);
    }
}

void ReleasePlayer(void) {
    EntityList_Free(&bullets);
}

EntityList* GetBullets() {
    return &bullets;
}

Player* GetPlayer() {
    return &player;
}