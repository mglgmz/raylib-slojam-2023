#include "screens.h"
#include "../player.h"
#include "../space.h"
#include "../simulation.h"
#include "../defs.h"
#include "../particles.h"
#include "../game_ui.h"

static RenderTexture2D target = {0}; // Render texture to render our game
static Player *player;

float deathTs = -1.0f;
float alpha = 0.3f;

static Shader gamplayShader;

void InitGameplayScreen()
{
    InitParticles();
    InitPlayer();
    InitSpace();
    InitUI();
    target = LoadRenderTexture(gameWidth, gameHeight);

    player = GetPlayer();
    deathTs = -1.0f;
    alpha = 0.3f;
    gamplayShader = LoadShader(0, TextFormat("resources/shaders/glsl%i/bloom.fs", GLSL_VERSION));
}

void UpdateGameplayScreen()
{
    if (player->currentLife > 0)
    {
        UpdatePlayer();
    }
    else
    {
        if (deathTs < 0.0f)
        {
            deathTs = GetTime();
        }
        else if (GetTime() - deathTs > 1.1f)
        {
            alpha += 0.02f;
        }

        if (GetTime() - deathTs > 3.5f)
            ChangeToScreen(MENU);
    }
    UpdateSimulation();
    UpdateParticles();
    UpdateUI();
    BeginTextureMode(target);
        ClearBackground(COLOR_A);
        
        RenderPlayer();
        RenderSpace();
        RenderParticles();

        if (deathTs > 0 && GetTime() - deathTs > 1.1f)
        {
            DrawRectangle(0, 0, target.texture.width, target.texture.height, Fade(BLACK, 0.8f));
            if (deathTs > 0.5f)
            {

                char *text = "YOU DIED";
                int fontSize = 30;
                int size = MeasureText(text, fontSize);
                DrawText(text, target.texture.width / 2 - size / 2, target.texture.height / 2 - (fontSize / 2), fontSize, Fade(RED, alpha));
            }
        }
    EndTextureMode();
}

void RenderGameplayScreen()
{
    BeginShaderMode(gamplayShader);
        DrawTexturePro(target.texture, (Rectangle){0, 0, (float)target.texture.width, -(float)target.texture.height}, (Rectangle){0, 0, (float)screenWidth, (float)screenHeight}, (Vector2){0, 0}, 0.0f, WHITE);
    EndShaderMode();
    RenderUI();
}

void ReleaseGameplayScreen()
{
    UnloadShader(gamplayShader);
    ReleaseSpace();
    ReleasePlayer();
    UnloadRenderTexture(target);
}