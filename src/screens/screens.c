#include "screens.h"

void ChangeToScreen(GameScreen screen)
{
    ReleaseCurrentScreen();
    currentScreen = screen;
    InitCurrentScreen();
}

void TransitionToScreen(GameScreen screen)
{
    // TODO: Transitions!
    ChangeToScreen(screen);
}

void UpdateTransition()
{
}

void RenderTransition()
{
}

void InitCurrentScreen()
{
    switch (currentScreen)
    {
    case LOGO:
        InitLogoScreen();
        break;
    case MENU:
        InitMenuScreen();
        break;
    case OPTIONS:
        InitOptionsScreen();
        break;
    case GAMEPLAY:
        InitGameplayScreen();
        break;
    case SCORE:
        InitScoreScreen();
        break;
    }
}

void UpdateCurrentScreen()
{
    switch (currentScreen)
    {
    case LOGO:
        UpdateLogoScreen();
        break;
    case MENU:
        UpdateMenuScreen();
        break;
    case OPTIONS:
        UpdateOptionsScreen();
        break;
    case GAMEPLAY:
        UpdateGameplayScreen();
        break;
    case SCORE:
        UpdateScoreScreen();
        break;
    }
}

void ReleaseCurrentScreen()
{
    switch (currentScreen)
    {
    case LOGO:
        ReleaseLogoScreen();
        break;
    case MENU:
        ReleaseMenuScreen();
        break;
    case OPTIONS:
        ReleaseOptionsScreen();
        break;
    case GAMEPLAY:
        ReleaseGameplayScreen();
        break;
    case SCORE:
        ReleaseScoreScreen();
        break;
    }
}