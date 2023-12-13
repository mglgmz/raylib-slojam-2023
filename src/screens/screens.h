#ifndef SCREENS_H
#define SCREENS_H

#include "raylib.h"

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
void RenderCurrentScreen();
void ReleaseCurrentScreen();

static GameScreen currentScreen = GAMEPLAY;

void InitIntroScreen();
void UpdateIntroScreen();
void RenderIntroScreen();
void ReleaseIntroScreen();

// logo
void InitLogoScreen();
void UpdateLogoScreen();
void RenderLogoScreen();
void ReleaseLogoScreen();

// gameplay
void InitGameplayScreen();
void UpdateGameplayScreen();
void RenderGameplayScreen();
void ReleaseGameplayScreen();

// menu
void InitMenuScreen();
void UpdateMenuScreen();
void RenderMenuScreen();
void ReleaseMenuScreen();

// options
void InitOptionsScreen();
void UpdateOptionsScreen();
void RenderOptionsScreen();
void ReleaseOptionsScreen();

// score
void InitScoreScreen();
void UpdateScoreScreen();
void RenderScoreScreen();
void ReleaseScoreScreen();

#endif