
#include "screens.h"
#include "../entity_list.h"
#include "../defs.h"
#include "../text.h"
#include "../game_music.h"
#include "../renderer.h"

RenderTexture2D menuTexture = { 0 };
static Music music;
static Sound clickSound;

void InitMenuScreen() {
    menuTexture = GetRenderTexture();
    PlayMusic("asteroids");
    UpdateMusicVolume(0.2f);
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
    EndTextureMode();
}

void ReleaseMenuScreen() {
    
}
