
#include "screens.h"
#include "../entity_list.h"
#include "../defs.h"
#include "../text.h"
#include "../game_music.h"
#include "../renderer.h"
#include "../score.h"

RenderTexture2D menuTexture = { 0 };
static Music music;
static Sound clickSound;

void InitMenuScreen() {
    menuTexture = GetRenderTexture();
    PlayMusic("asteroids");
    UpdateMusicVolume(0.3f);
    UpdateMusicPitch(1.0f);
    clickSound = LoadSound("resources/sounds/effects/Flashpoint001d.wav");
} 

void UpdateMenuScreen() {
    if(IsKeyReleased(KEY_ENTER)) {
        PlaySound(clickSound);
        ChangeToScreen(GAMEPLAY);
    }

    BeginTextureMode(menuTexture);
        ClearBackground(COLOR_A);
        char* text = "Press ENTER to play";
        int fontSize = 12;
        int textSize = MeasureText(text, fontSize);
        Text_DrawText(text, gameWidth / 2 - textSize / 2, gameHeight / 2 - fontSize / 2, fontSize, COLOR_B);

        const char *lastScoreText = TextFormat("Last: %i", GetLastScore());
        fontSize = 8;
        textSize = MeasureText(lastScoreText, fontSize);
        Text_DrawText(lastScoreText, gameWidth / 2 - textSize / 2, gameHeight / 2 - fontSize / 2 + 20, fontSize, COLOR_B);

        const char *highScoreText = TextFormat("Hi: %i", GetLastScore());
        textSize = MeasureText(highScoreText, fontSize);
        Text_DrawText(highScoreText, gameWidth / 2 - textSize / 2, gameHeight / 2 - fontSize / 2 + 30, fontSize, COLOR_B_HI);

    EndTextureMode();
}

void ReleaseMenuScreen() {
    
}
