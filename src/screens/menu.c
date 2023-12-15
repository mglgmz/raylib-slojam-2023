
#include "screens.h"
#include "../entity_list.h"

void InitMenuScreen() {
} 

void UpdateMenuScreen() {
    if(IsKeyReleased(KEY_ENTER))
        ChangeToScreen(GAMEPLAY);
}

void RenderMenuScreen() {
    ClearBackground(BLACK);
    char* text = "Press ENTER to play";
    int fontSize = 24;
    int textSize = MeasureText(text, fontSize);
    DrawText(text, GetScreenWidth() / 2 - textSize / 2, GetScreenHeight() / 2 - fontSize / 2, fontSize, RAYWHITE);

}

void ReleaseMenuScreen() {
  
}
