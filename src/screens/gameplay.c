#include "screens.h"
#include "../player.h"
#include "../space.h"
#include "../simulation.h"
#include "../defs.h"
#include "../particles.h"
#include "../game_ui.h"
#include "../game_music.h"
#include "../renderer.h"
#include "../level_system.h"
#include "../drop_system.h"
#include "../score.h"

static RenderTexture2D target = {0}; // Render texture to render our game
static Player *player;

float deathTs = -1.0f;
float alpha = 0.3f;

static void PrepareRender();

static Music music;

void InitGameplayScreen()
{
    InitParticles();
    TraceLog(LOG_INFO, "After InitParticles");
    InitPlayer();
    TraceLog(LOG_INFO, "After InitPlayer");
    InitSpace();
    TraceLog(LOG_INFO, "After InitSpace");
    InitSimulation();
    TraceLog(LOG_INFO, "After InitSimulation");
    InitUI();
    TraceLog(LOG_INFO, "After InitUI");
    InitLevelSystem();
    TraceLog(LOG_INFO, "After InitLevelSystem");
    InitDropSystem();
    TraceLog(LOG_INFO, "After InitDropSystem");
    target = GetRenderTexture();
    TraceLog(LOG_INFO, "After GetRenderTexture");
    player = GetPlayer();
    TraceLog(LOG_INFO, "After GetPlayer");
    deathTs = -1.0f;
    alpha = 0.3f;

    UpdateMusicVolume(0.4f);
    TraceLog(LOG_INFO, "After UpdateMusicVolume");
    ResetScore();
    TraceLog(LOG_INFO, "After ResetScore");
}

void UpdateGameplayScreen()
{
    if (player->currentLife > 0)
    {
        UpdatePlayer();
    }
    else
    {
        UpdateMusicPitch(0.85f);
        if (deathTs < 0.0f)
        {
            deathTs = GetTime();
        }
        else if (GetTime() - deathTs > 1.1f)
        {
            alpha += 0.02f;
        }

        if (GetTime() - deathTs > 3.5f) {
            ChangeToScreen(MENU);
            return;
        }
    }
    UpdateSimulation();
    UpdateParticles();
    UpdateUI();
    
    UpdateLevelSystem();
    UpdateDropSystem();

    PrepareRender();
}

void PrepareRender() {
    BeginTextureMode(target);
        ClearBackground(COLOR_A);
        
        RenderPlayer();
        RenderSpace();
        RenderParticles();
        RenderDropSystem();

        Text_DrawText(TextFormat("%i", GetCurrentScore()), 2, 2, 8, COLOR_B_HI);
        
        if (deathTs > 0 && GetTime() - deathTs > 1.1f)
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

void ReleaseGameplayScreen()
{
    ReleaseSpace();
    ReleasePlayer();
    ReleaseSimulation();
    ReleaseLevelSystem();
}