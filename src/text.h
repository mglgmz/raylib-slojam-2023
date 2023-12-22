#ifndef TEXT_H
#define TEXT_H

#include <raylib.h>

static Font defaultFont;

void InitText();
void ReleaseText();

void Text_DrawText(const char *text, int posX, int posY, int fontSize, Color color); 

#endif