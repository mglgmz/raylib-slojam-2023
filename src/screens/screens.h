#ifndef SCREENS_H
#define SCREENS_H


typedef enum GameScreen { 
    UNKNOWN = -1, 
    LOGO = 0, 
    TITLE, 
    OPTIONS, 
    GAMEPLAY, 
    ENDING 
} GameScreen;

// management
void ChangeToScreen(GameScreen screen);
void TransitionToScreen(GameScreen screen);
void UpdateTransition();
void RenderTransition();

extern GameScreen currentScreen;

// logo
void InitLogoScreen();
void UpdateLogoScreen();
void RenderLogoScreen();
void ReleaseLogoScreen();

// intro
void InitIntroScreen();
void UpdateIntroScreen();
void RenderIntroScreen();
void ReleaseIntroScreen();

// gameplay
void InitGameplayScreen();
void UpdateGameplayScreen();
void RenderGameplayScreen();
void ReleaseGameplayScreen();

// menu
void InitMenuScreen();
void UpdateMenuScreen();
void RenderGameplayScreen();
void ReleaseGameplayScreen();

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