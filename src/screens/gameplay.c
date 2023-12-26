#include "screens.h"
#include "../player.h"
#include "../space.h"
#include "../simulation.h"
#include "../defs.h"
#include "../particles.h"
#include "../game_ui.h"
#include "../game_music.h"

static RenderTexture2D target = {0}; // Render texture to render our game
static Player *player;

float deathTs = -1.0f;
float alpha = 0.3f;

static int gamePaused = 0;
float gameTs;

static void UpdatePause();
static void RenderPauseOverlay();
static void PrepareRender();

static Music music;

void InitGameplayScreen()
{
    InitParticles();
    InitPlayer();
    InitSpace();
    InitSimulation();
    InitUI();
    target = LoadRenderTexture(gameWidth, gameHeight);

    player = GetPlayer();
    deathTs = -1.0f;
    alpha = 0.3f;

    PlayMusic("asteroids");
    UpdateMusicVolume(0.5f);
}

void UpdateGameplayScreen()
{
    if(gamePaused) {
        UpdatePause();
        RenderPauseOverlay();
        return;
    }

    gameTs += GetFrameTime();

    if(deathTs < 0.0f && IsKeyPressed(KEY_ENTER)) {
        gamePaused = 1;
        return;
    }

    if (player->currentLife > 0)
    {
        UpdatePlayer();
    }
    else
    {
        UpdateMusicPitch(0.85f);
        if (deathTs < 0.0f)
        {
            deathTs = gameTs;
        }
        else if (gameTs - deathTs > 1.1f)
        {
            alpha += 0.02f;
        }

        if (gameTs - deathTs > 3.5f)
            ChangeToScreen(MENU);
    }
    UpdateSimulation();
    UpdateParticles();
    UpdateUI();
    
    PrepareRender();
}

void PrepareRender() {
    BeginTextureMode(target);
        ClearBackground(COLOR_A);
        
        RenderPlayer();
        RenderSpace();
        RenderParticles();

        if (deathTs > 0 && gameTs - deathTs > 1.1f)
        {
            DrawRectangle(0, 0, target.texture.width, target.texture.height, Fade(COLOR_A, 0.8f));
            if (deathTs > 0.5f)
            {

                char *text = "YOU DIED";
                int fontSize = 30;
                int size = MeasureText(text, fontSize);
                Text_DrawText(text, target.texture.width / 2 - size / 2, target.texture.height / 2 - (fontSize / 2), fontSize, Fade(COLOR_B, alpha));
            }
        }
    EndTextureMode();
}

void RenderGameplayScreen()
{
    DrawTexturePro(target.texture, (Rectangle){0, 0, (float)target.texture.width, -(float)target.texture.height}, (Rectangle){0, 0, (float)screenWidth, (float)screenHeight}, (Vector2){0, 0}, 0.0f, WHITE);
    RenderUI();
}

void UpdatePause() {
     if(IsKeyPressed(KEY_ENTER)) {
        gamePaused = 0;
        return;
    }
}

void RenderPauseOverlay() {
    BeginTextureMode(target);
        ClearBackground(COLOR_A);
        char *text = "Paused";
        int fontSize = 24;
        int size = MeasureText(text, fontSize);
        Text_DrawText(text, target.texture.width / 2 - size / 2, target.texture.height / 2 - (fontSize / 2), fontSize, Fade(COLOR_B, alpha));
    EndTextureMode();
}

void ReleaseGameplayScreen()
{
    ReleaseSpace();
    ReleasePlayer();
    ReleaseSimulation();
    UnloadRenderTexture(target);
}