#include "screens.h"

// RAYLIB LOGO
// raylib logo from: https://github.com/raysan5/raylib-game-template/blob/main/src/screen_logo.c
static int framesCounter = 0;
static int finishScreen = 0;

static int logoPositionX = 0;
static int logoPositionY = 0;

static int lettersCount = 0;

static int topSideRecWidth = 0;
static int leftSideRecHeight = 0;

static int bottomSideRecWidth = 0;
static int rightSideRecHeight = 0;

static int state = 0;      // Logo animation states
static float alpha = 1.0f; // Useful for fading

void InitLogoScreen()
{
    finishScreen = 0;
    framesCounter = 0;
    lettersCount = 0;

    logoPositionX = GetScreenWidth() / 2 - 128;
    logoPositionY = GetScreenHeight() / 2 - 128;

    topSideRecWidth = 16;
    leftSideRecHeight = 16;
    bottomSideRecWidth = 16;
    rightSideRecHeight = 16;

    state = 0;
    alpha = 1.0f;
}

void UpdateLogoScreen()
{
    if(IsKeyReleased(KEY_ENTER)) state++;
    if (state == 0) // State 0: Top-left square corner blink logic
    {
        framesCounter++;

        if (framesCounter == 40)
        {
            state = 1;
            framesCounter = 0; // Reset counter... will be used later...
        }
    }
    else if (state == 1) // State 1: Bars animation logic: top and left
    {
        topSideRecWidth += 8;
        leftSideRecHeight += 8;

        if (topSideRecWidth == 256)
            state = 2;
    }
    else if (state == 2) // State 2: Bars animation logic: bottom and right
    {
        bottomSideRecWidth += 8;
        rightSideRecHeight += 8;

        if (bottomSideRecWidth == 256)
            state = 3;
    }
    else if (state == 3) // State 3: "raylib" text-write animation logic
    {
        framesCounter++;

        if (lettersCount < 10)
        {
            if (framesCounter / 12) // Every 12 frames, one more letter!
            {
                lettersCount++;
                framesCounter = 0;
            }
        }
        else // When all letters have appeared, just fade out everything
        {
            if (framesCounter > 100)
            {
                alpha -= 0.05f;

                if (alpha <= 0.0f)
                {
                    alpha = 0.0f;
                    state = 4;
                    framesCounter = 0;
                }
            }
        }
    }
    else if (state == 4)
    {
        framesCounter++;
        if (alpha < 1.0f)
        {
            alpha += 0.08f;
            framesCounter = 0;
        }
        else
        {
            if (framesCounter > 100)
            {
                state = 5;
                framesCounter = 0;
            }
        }
    }
    else if (state == 5)
    {
        if (alpha > 0.0f)
            alpha -= 0.10f;
        framesCounter++;
        if (framesCounter > 45)
        {
            state = 6;
            framesCounter = 0;
        }
    }
    else if (state == 6)
    {
        framesCounter++;
        if (alpha < 1.0f)
            alpha += 0.15f;
        if (framesCounter >= 90)
        {
            state = 7;
            framesCounter = 0;
        }
    }
    else if (state == 7)
    {
        framesCounter++;
        alpha -= 0.7f;
        if (framesCounter >= 90)
            TransitionToScreen(GAMEPLAY); // TODO: MENU
    }
}

void RenderLogoScreen()
{
    ClearBackground(BLACK);
    if (state == 0) // Draw blinking top-left square corner
    {
        if ((framesCounter / 10) % 2)
            DrawRectangle(logoPositionX, logoPositionY, 16, 16, RAYWHITE);
    }
    else if (state == 1) // Draw bars animation: top and left
    {
        DrawRectangle(logoPositionX, logoPositionY, topSideRecWidth, 16, RAYWHITE);
        DrawRectangle(logoPositionX, logoPositionY, 16, leftSideRecHeight, RAYWHITE);
    }
    else if (state == 2) // Draw bars animation: bottom and right
    {
        DrawRectangle(logoPositionX, logoPositionY, topSideRecWidth, 16, RAYWHITE);
        DrawRectangle(logoPositionX, logoPositionY, 16, leftSideRecHeight, RAYWHITE);

        DrawRectangle(logoPositionX + 240, logoPositionY, 16, rightSideRecHeight, RAYWHITE);
        DrawRectangle(logoPositionX, logoPositionY + 240, bottomSideRecWidth, 16, RAYWHITE);
    }
    else if (state == 3) // Draw "raylib" text-write animation + "powered by"
    {
        DrawRectangle(logoPositionX, logoPositionY, topSideRecWidth, 16, Fade(RAYWHITE, alpha));
        DrawRectangle(logoPositionX, logoPositionY + 16, 16, leftSideRecHeight - 32, Fade(RAYWHITE, alpha));

        DrawRectangle(logoPositionX + 240, logoPositionY + 16, 16, rightSideRecHeight - 32, Fade(RAYWHITE, alpha));
        DrawRectangle(logoPositionX, logoPositionY + 240, bottomSideRecWidth, 16, Fade(RAYWHITE, alpha));

        DrawRectangle(GetScreenWidth() / 2 - 112, GetScreenHeight() / 2 - 112, 224, 224, Fade(BLACK, alpha));

        DrawText(TextSubtext("raylib", 0, lettersCount), GetScreenWidth() / 2 - 44, GetScreenHeight() / 2 + 48, 50, Fade(RAYWHITE, alpha));

        if (framesCounter > 20)
            DrawText("powered by", logoPositionX, logoPositionY - 27, 20, Fade(RAYWHITE, alpha));
    }
    else if (state == 4 || state == 5)
    {
        char *text = "mglgmz";
        int textSize = MeasureText(text, 70);
        DrawText(text, (GetScreenWidth() / 2) - (textSize / 2), GetScreenHeight() / 2 - 35, 70, Fade(GOLD, alpha));
        DrawText("presents", (GetScreenWidth() / 2) - 35, GetScreenHeight() / 2 + 47, 20, Fade(RAYWHITE, alpha));
    }
    else if (state == 6 || state == 7)
    {
        char *text = "ASTEROIDS";
        int size = 90;
        int textSize = MeasureText(text, size);
        DrawText(text, (GetScreenWidth() / 2) - (textSize / 2), GetScreenHeight() / 2 - (size / 2), size, Fade(RAYWHITE, alpha));
    }
}

void ReleaseLogoScreen()
{
}