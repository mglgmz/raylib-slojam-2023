#include "game_ui.h"

static int debugInfoEnabled = 0;
void InitUI()
{
    defaultFont = GetFontDefault();
}

void UpdateUI()
{
    if (IsKeyReleased(KEY_F1))
        if (debugInfoEnabled == 0)
            debugInfoEnabled = 1;
        else
            debugInfoEnabled = 0;
}

void RenderUI()
{
    // Render UI
    if (debugInfoEnabled == 1)
    {
        DrawFPS(10,5);
        Player *player = GetPlayer();
        DrawText(TextFormat("Speed: %f", player->speed), 10, 30, 14, YELLOW);
        DrawText(TextFormat("Rotat: %f", player->rotation), 10, 50, 14, YELLOW);

        EntityList* bullets = GetBullets();
        DrawText(TextFormat("Bullets: %d", bullets->used), 10, 70, 14, PINK);

        EntityList* asteroids = GetAsteroids();
        DrawText(TextFormat("Asteroids: %d", asteroids->used), 10, 90, 14, LIME);
    }
}

void ReleaseUI()
{
    UnloadFont(defaultFont);
}