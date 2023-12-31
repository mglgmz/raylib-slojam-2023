#include "text.h"
#include <stddef.h>
void InitText() {
    defaultFont = LoadFont("resources/fonts/perfect_dos_vga_437/dos_vga_437.ttf");
}

void ReleaseText() {
    UnloadFont(defaultFont);
}

void Text_DrawText(const char *text, int posX, int posY, int fontSize, Color color) {
    if(text ==  NULL) return;
    int defaultFontSize = 10;   // Default Font chars height in pixel
    if (fontSize < defaultFontSize) fontSize = defaultFontSize;
    int spacing = fontSize/defaultFontSize;
    DrawTextEx(defaultFont, text, (Vector2){ posX, posY}, fontSize, spacing, color);
}