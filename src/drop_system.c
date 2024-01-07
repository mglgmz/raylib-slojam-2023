#include "drop_system.h"
#include "utils.h"
#include "text.h"
#include "player.h"
#include "particles.h"

#define POWERUP_FADE_DURATION 3.0f
#define DROP_MARGIN 5.0f

void InitDropSystem(void)
{
    EntityList_Init(&drops, 10);
    powerUpSound = LoadSound("resources/sounds/effects/Flashpoint001d.wav");
    SetSoundVolume(powerUpSound, 0.4f);
}

void RenderDropSystem(void)
{
    if (drops.used > 0)
    {
        for (int i = 0; i < drops.used; i++)
        {
            Entity powerUpDrop = drops.array[i];
            PowerUp powerUp = availablePowerUps[powerUpDrop.id];

            Color color = powerUpDrop.ttl > POWERUP_FADE_DURATION ? COLOR_B : Fade(COLOR_B, powerUpDrop.ttl / POWERUP_FADE_DURATION);

            DrawRectangleLinesEx((Rectangle) { powerUpDrop.x - 3, powerUpDrop.y - 1, 10, 10 }, 1, color);
            Text_DrawText(powerUp.display, powerUpDrop.x, powerUpDrop.y, 10, color);
        }
    }
}

void UpdateDropSystem(void)
{
    Player *player = GetPlayer();
    Vector2 playerPosition = (Vector2){ player->x, player->y };
    for(int i = drops.used - 1; i >= 0; i--) {
        Entity* drop = &drops.array[i];
        drop->ttl -= GetFrameTime();
        if(drop->ttl <= 0.0f)
            EntityList_Delete(&drops, i);
        else {
            if(CheckCollisionPointRec(playerPosition, (Rectangle) { drop->x - 3, drop->y - 1, 10, 10 })) {
                PowerUp powerUp = availablePowerUps[drop->id];
                AddPlayerPowerUp(powerUp.id);
                PlaySound(powerUpSound);
                EntityList_Delete(&drops, i);
            }
        }
    }
}

void RollDrop(int type, int size, float x, float y)
{
    if (type == ASTEROID && size > 4)
    {
        float roll = GetRandomFloat();
        if (roll < 0.35f)
        {
            int drop = GetRandomValue(0, AVAILABLE_POWERUPS - 1);
            PowerUp powerUp = availablePowerUps[drop];

            float dropX = x;
            float dropY = y;

            if(dropX < DROP_MARGIN) dropX = DROP_MARGIN;
            else if(dropX > (gameWidth - DROP_MARGIN)) dropX = gameWidth - DROP_MARGIN;

            if(dropY < DROP_MARGIN) dropY = DROP_MARGIN;
            else if(dropY > (gameHeight - DROP_MARGIN)) dropY = gameHeight - DROP_MARGIN;

            Entity powerUpDrop = {
                .x = dropX,
                .y = dropY,
                .id = drop,
                .ttl = powerUp.duration
            };

            EntityList_Add(&drops, &powerUpDrop);
        }
    }
}

void ReleaseDropSystem(void)
{
    UnloadSound(powerUpSound);
    EntityList_Free(&drops);
}
