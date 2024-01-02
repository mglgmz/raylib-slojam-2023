#include "game_ui.h"
#include "player.h"
#include "renderer.h"

static int debugInfoEnabled = 0;
static RenderTexture2D uiTarget = {0};
Player* player;

void InitUI()
{
    defaultFont = GetFontDefault();
    uiTarget = GetUITexture();
    player = GetPlayer();
}

void UpdateUI()
{
    if (IsKeyReleased(KEY_F1)) {
       debugInfoEnabled = debugInfoEnabled ? 0 : 1;
    }

    BeginTextureMode(uiTarget);
        ClearBackground(BLANK);

         // Render UI
        if (debugInfoEnabled == 1)
        {
            DrawFPS(10,5);

            EntityList* bullets = GetBullets();
            DrawText(TextFormat("Bullets: %d / %d", bullets->used, bullets->size), 10, 70, 14, PINK);

            AsteroidList* asteroids = GetAsteroids();
            DrawText(TextFormat("Asteroids: %d / %d", asteroids->used, asteroids->size), 10, 90, 14, LIME);

            EntityList* particles = GetParticles();
            DrawText(TextFormat("Particles: %d / %d", particles->used, particles->size), 10, 110, 14, RAYWHITE);

            DrawText(TextFormat("GL Version: %i", GLSL_VERSION), 10, 130, 14, RED);
        }
    EndTextureMode();
}

void ReleaseUI()
{
    UnloadFont(defaultFont);
}