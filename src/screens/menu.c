
#include "screens.h"
#include "../entity_list.h"

void InitMenuScreen() {
} 

void UpdateMenuScreen() {
    if(IsKeyReleased(KEY_ENTER))
        ChangeToScreen(GAMEPLAY);
}

void RenderMenuScreen() {
    
}

void ReleaseMenuScreen() {
  
}
