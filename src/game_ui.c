#include "game_ui.h"

static int debugInfoEnabled = 0;
static RenderTexture2D uiTarget = {0};

void InitUI()
{
    defaultFont = GetFontDefault();
    uiTarget = LoadRenderTexture(screenWidth, screenHeight);
}

void UpdateUI()
{
    if (IsKeyReleased(KEY_F1))
        if (debugInfoEnabled == 0)
            debugInfoEnabled = 1;
        else
            debugInfoEnabled = 0;

     BeginTextureMode(uiTarget);
        ClearBackground(BLANK);

         // Render UI
        if (debugInfoEnabled == 1)
        {
            DrawFPS(10,5);
            Player *player = GetPlayer();
            DrawText(TextFormat("Speed: %f", player->speed), 10, 30, 14, YELLOW);
            DrawText(TextFormat("Rotat: %f", player->rotation), 10, 50, 14, YELLOW);

            EntityList* bullets = GetBullets();
            DrawText(TextFormat("Bullets: %d / %d", bullets->used, bullets->size), 10, 70, 14, PINK);

            EntityList* asteroids = GetAsteroids();
            DrawText(TextFormat("Asteroids: %d / %d", asteroids->used, asteroids->size), 10, 90, 14, LIME);

            EntityList* particles = GetParticles();
            DrawText(TextFormat("Particles: %d / %d", particles->used, particles->size), 10, 110, 14, RAYWHITE);
        }
    EndTextureMode();
}

void RenderUI()
{
    DrawTexturePro(uiTarget.texture, (Rectangle){0, 0, (float)uiTarget.texture.width, -(float)uiTarget.texture.height}, (Rectangle){0, 0, (float)screenWidth, (float)screenHeight}, (Vector2){0, 0}, 0.0f, WHITE);
}

void ReleaseUI()
{
    UnloadFont(defaultFont);
}