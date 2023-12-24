#include "screens.h"
#include "../defs.h"

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

static RenderTexture2D logoTexture = {0};
static Shader logoShader;

void InitLogoScreen()
{
    logoShader = LoadShader(0, TextFormat("resources/shaders/glsl%i/scanlines.fs", GLSL_VERSION));
    logoTexture = LoadRenderTexture(gameWidth, gameHeight);
    finishScreen = 0;
    framesCounter = 0;
    lettersCount = 0;

    logoPositionX = gameWidth / 2 - 60;
    logoPositionY = gameHeight / 2 - 60;

    topSideRecWidth = 16;
    leftSideRecHeight = 16;
    bottomSideRecWidth = 16;
    rightSideRecHeight = 16;

    state = 0;
    alpha = 1.0f;
}
static int maxLogoSize = 120;
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

        if (topSideRecWidth == maxLogoSize)
            state = 2;
    }
    else if (state == 2) // State 2: Bars animation logic: bottom and right
    {
        bottomSideRecWidth += 8;
        rightSideRecHeight += 8;

        if (bottomSideRecWidth == maxLogoSize)
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
            TransitionToScreen(MENU);
    }
    int baseSize = 4;
    BeginTextureMode(logoTexture);
        ClearBackground(COLOR_A);
        if (state == 0) // Draw blinking top-left square corner
        {
            if ((framesCounter / 10) % 2)
                DrawRectangle(logoPositionX, logoPositionY, baseSize, baseSize, COLOR_B);
        }
        else if (state == 1) // Draw bars animation: top and left
        {
            DrawRectangle(logoPositionX, logoPositionY, topSideRecWidth, baseSize, COLOR_B);
            DrawRectangle(logoPositionX, logoPositionY, baseSize, leftSideRecHeight, COLOR_B);
        }
        else if (state == 2) // Draw bars animation: bottom and right
        {
            DrawRectangle(logoPositionX, logoPositionY, topSideRecWidth, baseSize, COLOR_B);
            DrawRectangle(logoPositionX, logoPositionY, baseSize, leftSideRecHeight, COLOR_B);

            DrawRectangle(logoPositionX + maxLogoSize - baseSize / 2, logoPositionY, baseSize, rightSideRecHeight, COLOR_B);
            DrawRectangle(logoPositionX, logoPositionY + maxLogoSize - baseSize / 2, bottomSideRecWidth, baseSize, COLOR_B);
        }
        else if (state == 3) // Draw "raylib" text-write animation + "powered by"
        {
            DrawRectangle(logoPositionX, logoPositionY, topSideRecWidth, baseSize, Fade(COLOR_B, alpha));
            DrawRectangle(logoPositionX, logoPositionY + baseSize, baseSize, leftSideRecHeight - baseSize / 2, Fade(COLOR_B, alpha));

            DrawRectangle(logoPositionX + maxLogoSize,logoPositionY, baseSize, maxLogoSize + baseSize/2, Fade(COLOR_B, alpha));
            DrawRectangle(logoPositionX, logoPositionY + maxLogoSize - baseSize / 2, bottomSideRecWidth, baseSize, Fade(COLOR_B, alpha));

            // DrawRectangle(GetScreenWidth() / 2 - 112, GetScreenHeight() / 2 - 112, 224, 224, Fade(COLOR_A, alpha));

            DrawText(TextSubtext("raylib", 0, lettersCount), 166, 156, 16, Fade(COLOR_B, alpha));

            if (framesCounter > 20)
                DrawText("powered by", logoPositionX, logoPositionY - 15, 12, Fade(COLOR_B, alpha));
        }
        else if (state == 4 || state == 5)
        {
            char *text = "mglgmz";
            int textSize = MeasureText(text, 24);
            Text_DrawText(text, (gameWidth / 2) - (textSize / 2), gameHeight / 2 - 12, 24, Fade(COLOR_C, alpha));
            Text_DrawText("presents", (gameWidth / 2) - 25, gameHeight / 2 + 12, 12, Fade(COLOR_B, alpha));
        }
        else if (state == 6 || state == 7)
        {
            char *text = "ASTEROIDS";
            int size = 36;
            int textSize = MeasureText(text, size);
            Text_DrawText(text, (gameWidth / 2) - (textSize / 2), gameHeight / 2 - (size / 2), size, Fade(COLOR_B, alpha));
        }
    EndTextureMode();
}

void RenderLogoScreen()
{
    

    DrawTexturePro(logoTexture.texture, (Rectangle){0, 0, (float)logoTexture.texture.width, -(float)logoTexture.texture.height}, (Rectangle){0, 0, (float)screenWidth, (float)screenHeight}, (Vector2){0, 0}, 0.0f, WHITE);
}

void ReleaseLogoScreen()
{
}