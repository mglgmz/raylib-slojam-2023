#ifndef SCREENS_H
#define SCREENS_H

#include "raylib.h"
#include "../text.h"
#include "../defs.h"

typedef enum GameScreen { 
    UNKNOWN = -1, 
    LOGO = 0, 
    MENU, 
    OPTIONS, 
    GAMEPLAY, 
    SCORE 
} GameScreen;

// management
void ChangeToScreen(GameScreen screen);
void TransitionToScreen(GameScreen screen);
void UpdateTransition();
void RenderTransition();

void InitCurrentScreen();
void UpdateCurrentScreen();
void ReleaseCurrentScreen();

static GameScreen currentScreen = DEFAULT_SCREEN;

void InitIntroScreen();
void UpdateIntroScreen();
void ReleaseIntroScreen();

// logo
void InitLogoScreen();
void UpdateLogoScreen();
void ReleaseLogoScreen();

// gameplay
void InitGameplayScreen();
void UpdateGameplayScreen();
void ReleaseGameplayScreen();

// menu
void InitMenuScreen();
void UpdateMenuScreen();
void ReleaseMenuScreen();

// options
void InitOptionsScreen();
void UpdateOptionsScreen();
void ReleaseOptionsScreen();

// score
void InitScoreScreen();
void UpdateScoreScreen();
void ReleaseScoreScreen();

#endif