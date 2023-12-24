
#include "screens.h"
#include "../entity_list.h"
#include "../defs.h"
#include "../text.h"

RenderTexture2D menuTexture = { 0 };

void InitMenuScreen() {
    menuTexture = LoadRenderTexture(gameWidth, gameHeight);
} 

void UpdateMenuScreen() {
    if(IsKeyReleased(KEY_ENTER))
        ChangeToScreen(GAMEPLAY);

    BeginTextureMode(menuTexture);
        ClearBackground(COLOR_A);
        char* text = "Press ENTER to play";
        int fontSize = 12;
        int textSize = MeasureText(text, fontSize);
        Text_DrawText(text, gameWidth / 2 - textSize / 2, gameHeight / 2 - fontSize / 2, fontSize, COLOR_B);
    EndTextureMode();
}

void RenderMenuScreen() {
    DrawTexturePro(menuTexture.texture, (Rectangle){0, 0, (float)menuTexture.texture.width, -(float)menuTexture.texture.height}, (Rectangle){0, 0, (float)screenWidth, (float)screenHeight}, (Vector2){0, 0}, 0.0f, WHITE);
}

void ReleaseMenuScreen() {
  UnloadRenderTexture(menuTexture);
}
