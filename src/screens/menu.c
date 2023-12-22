
#include "screens.h"
#include "../entity_list.h"
#include "../defs.h"
#include "../text.h"

void InitMenuScreen() {
} 

void UpdateMenuScreen() {
    if(IsKeyReleased(KEY_ENTER))
        ChangeToScreen(GAMEPLAY);
}

void RenderMenuScreen() {
    ClearBackground(COLOR_A);
    char* text = "Press ENTER to play";
    int fontSize = 24;
    int textSize = MeasureText(text, fontSize);
    Text_DrawText(text, GetScreenWidth() / 2 - textSize / 2, GetScreenHeight() / 2 - fontSize / 2, fontSize, COLOR_B);

}

void ReleaseMenuScreen() {
  
}
