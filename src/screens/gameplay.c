#include "screens.h"
#include "../player.h"
#include "../space.h"
#include "../simulation.h"
#include "../defs.h"

static RenderTexture2D target = {0}; // Render texture to render our game

void InitGameplayScreen()
{
    InitPlayer();
    InitSpace();
    target = LoadRenderTexture(gameWidth, gameHeight);
}

void UpdateGameplayScreen()
{
    UpdatePlayer();
    UpdateSimulation();

    BeginTextureMode(target);
        ClearBackground(RAYWHITE);

        DrawRectangle(0, 0, screenWidth, screenHeight, BLACK);

        RenderPlayer();
        RenderSpace();

    EndTextureMode();
}

void RenderGameplayScreen()
{
    DrawTexturePro(target.texture, (Rectangle){0, 0, (float)target.texture.width, -(float)target.texture.height}, (Rectangle){0, 0, (float)screenWidth, (float)screenHeight}, (Vector2){0, 0}, 0.0f, WHITE);
}

void ReleaseGameplayScreen()
{
    ReleaseSpace();
    ReleasePlayer();
    UnloadRenderTexture(target);
}