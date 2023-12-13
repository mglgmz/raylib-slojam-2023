#ifndef GAME_UI_H
#define GAME_UI_H

#include <raylib.h>
#include "player.h"
#include "space.h"
#include "particles.h"

static Font defaultFont;

void InitUI();
void ReleaseUI();

void UpdateUI();
void RenderUI();

#endif