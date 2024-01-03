#include "player.h"
#include "utils.h"
#include <raylib.h>


#define P_SIDE 4.0f
#define HALF_P_SIDE P_SIDE / 2.0f
#define P_HEIGHT_OFF (P_SIDE * sqrt(3) / 2) / 2

#define SHOOT_BUTTON KEY_SPACE

static Player player = {
    .x = 200,
    .y = 100,
    .visible = true,

    .rotation = 0,
    .rotationSpeedLevel = 0,

    .speedLevel = 0,
    .velocity = 0,

    .maxLife = 1,
    .currentLife = 1
};

int directionX;
int directionY;
static Sound shootSound;

void InitPlayer(void) {
    player.currentLife = player.maxLife;
    player.velocityX = 0;
    player.velocityY = 0;
    player.x = 200;
    player.y = 100;
    player.speedLevel = 0;
    player.rotationSpeedLevel = 0;

    EntityList_Init(&bullets, 100);

    shootSound = LoadSound("resources/sounds/effects/flaunch.wav");
    SetSoundVolume(shootSound, 0.3f);
    SetSoundPitch(shootSound, 1.5f);

    player.powerUps = 0;
}

void UpdatePlayer(void) {
    if(player.currentLife <= 0) return;

    float dt = GetFrameTime();

    if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A))
        player.rotation -= rotationSpeedByLevel[player.rotationSpeedLevel] * dt;
    else if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D))
        player.rotation += rotationSpeedByLevel[player.rotationSpeedLevel] * dt;

    NormalizeAngle(&player.rotation);
        
    if (IsKeyDown(KEY_UP) || IsKeyDown(KEY_W))
        player.velocity = speedByLevel[player.speedLevel];
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
    WrapPosition(&player.x, &player.y, 0);

    directionX = rotCos * 2 + player.x;
    directionY = rotSin * 2 + player.y;

    if(IsKeyReleased(SHOOT_BUTTON)) {
        Entity bullet = { 0 };
        bullet.id = 1;     
        bullet.x = directionX;
        bullet.y = directionY;
        bullet.dx = rotCos * BULLET_SPEED;
        bullet.dy = rotSin * BULLET_SPEED;
        bullet.size = 1;
        bullet.speed = BULLET_SPEED;
        bullet.rotation = player.rotation;
        bullet.active = 1;
        EntityList_Add(&bullets, &bullet);
        PlaySound(shootSound);

        if(player.powerUps & CONE_SHOT) {
            float coneShotSpread = PI / 7;
            Entity bullet2 = { 0 };
            bullet2.id = 1;      
            bullet2.x = directionX;
            bullet2.y = directionY;
            bullet2.dx = cosf(player.rotation + coneShotSpread) * BULLET_SPEED;
            bullet2.dy = sinf(player.rotation + coneShotSpread) * BULLET_SPEED;
            bullet2.size = 1;
            bullet2.speed = BULLET_SPEED;
            bullet2.rotation = player.rotation + coneShotSpread;
            bullet2.active = 1;
            EntityList_Add(&bullets, &bullet2);

            Entity bullet3 = { 0 };
            bullet3.id = 1;         
            bullet3.x = directionX;
            bullet3.y = directionY;
            bullet3.dx = cosf(player.rotation - coneShotSpread) * BULLET_SPEED;
            bullet3.dy = sinf(player.rotation - coneShotSpread) * BULLET_SPEED;
            bullet3.size = 1;
            bullet3.speed = BULLET_SPEED;
            bullet3.rotation = player.rotation - coneShotSpread;
            bullet3.active = 1;
            EntityList_Add(&bullets, &bullet3);
        }

        if(player.powerUps & TRIPLE_SHOT) {
            float splitShotSpread = 2 * PI / 3;

            Entity bullet2 = { 0 }; 
            bullet2.id = 1;        
            bullet2.x = player.x;
            bullet2.y = player.y;
            bullet2.dx = cosf(player.rotation + splitShotSpread) * BULLET_SPEED;
            bullet2.dy = sinf(player.rotation + splitShotSpread) * BULLET_SPEED;
            bullet2.size = 1;
            bullet2.speed = BULLET_SPEED;
            bullet2.rotation = player.rotation;
            bullet2.active = 1;
            EntityList_Add(&bullets, &bullet2);

            Entity bullet3 = { 0 };
            bullet3.id = 1;        
            bullet3.x = player.x;
            bullet3.y = player.y;
            bullet3.dx = cosf(player.rotation - splitShotSpread) * BULLET_SPEED;
            bullet3.dy = sinf(player.rotation - splitShotSpread) * BULLET_SPEED;
            bullet3.size = 1;
            bullet3.speed = BULLET_SPEED;
            bullet3.rotation = player.rotation;
            bullet3.active = 1;
            EntityList_Add(&bullets, &bullet3);
        }
    
        if(player.powerUps & BACK_SHOT) {
            float backShotAngle = PI;
            Entity bullet2 = { 0 };
            bullet2.id = 1;         
            bullet2.x = player.x;
            bullet2.y = player.y;
            bullet2.dx = cosf(player.rotation + backShotAngle) * BULLET_SPEED;
            bullet2.dy = sinf(player.rotation + backShotAngle) * BULLET_SPEED;
            bullet2.size = 1;
            bullet2.speed = BULLET_SPEED;
            bullet2.rotation = player.rotation + backShotAngle;
            bullet2.active = 1;
            EntityList_Add(&bullets, &bullet2);
        }
    }
}

void AddBullet(Entity bullet) {
    EntityList_Add(&bullets, &bullet);
}

void HitPlayer(Player *player, int damage) {
    player->currentLife -= damage;
}

void AddPlayerPowerUp(int id) {
    player.powerUps |= id;

    if(id == SPEED) {
        player.speedLevel++;
        if(player.speedLevel >= SPEED_LEVELS) player.speedLevel = SPEED_LEVELS - 1;
    } else if(id == ROTATION_SPEED) {
        player.rotationSpeedLevel++;
        if(player.rotationSpeedLevel >= ROTATION_SPEED_LEVELS) player.rotationSpeedLevel = ROTATION_SPEED_LEVELS - 1;
    } else if(id == APOCALIPSIS) {
        player.apocaplipsis = 1;
    }
}

void RenderPlayer(void) {
    if(player.currentLife <= 0) return;
    // TODO: render death animation
     
    DrawPolyLines((Vector2) { player.x, player.y }, 3, P_SIDE, RadiansToDegrees(player.rotation), COLOR_B);
    DrawPoly((Vector2) { directionX, directionY }, 3, HALF_P_SIDE , RadiansToDegrees(player.rotation), COLOR_B);

    for (int i = 0; i < bullets.used; i++)
    {
        Entity *bullet = &bullets.array[i];
        DrawPoly((Vector2) { bullet->x, bullet->y }, 4, bullet->size, bullet->rotation, COLOR_B);
    }
}

void ReleasePlayer(void) {
    EntityList_Free(&bullets);
    UnloadSound(shootSound);
}

EntityList* GetBullets() {
    return &bullets;
}

Player* GetPlayer() {
    return &player;
}