#include "drop_system.h"
#include "utils.h"
#include "text.h"

void InitDropSystem(void)
{
    EntityList_Init(&drops, 10);
}

void RenderDropSystem(void)
{
    if (drops.used > 0)
    {
        for (int i = 0; i < drops.used; i++)
        {
            Entity powerUpDrop = drops.array[i];
            PowerUp powerUp = availablePowerUps[powerUpDrop.id];

            DrawRectangleLines(powerUpDrop.x-3, powerUpDrop.y, 10, 10, COLOR_B);
            Text_DrawText(powerUp.display, powerUpDrop.x, powerUpDrop.y, 10, COLOR_B);
        }
    }
}

void UpdateDropSystem(void)
{
}

void RollDrop(int type, int size, float x, float y)
{
    if (type == ASTEROID && size > 4)
    {
        float roll = GetRandomFloat();
        if (roll < 0.35f)
        {
            int drop = GetRandomValue(0, AVAILABLE_POWERUPS);
            PowerUp powerUp = availablePowerUps[drop];

            Entity powerUpDrop = {
                .x = x,
                .y = y,
                .id = drop,
                .ttl = 5.0f};

            EntityList_Add(&drops, &powerUpDrop);
        }
    }
}

void ApplyDrop(int id)
{
}

void ReleaseDropSystem(void)
{
    EntityList_Free(&drops);
}
