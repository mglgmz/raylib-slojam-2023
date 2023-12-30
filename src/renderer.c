#include "renderer.h"

void InitRenderer(void)
{
    renderTexture = LoadRenderTexture(gameWidth, gameHeight);
    uiTexture = LoadRenderTexture(screenWidth, screenHeight);
    scanlinesShader = LoadShader(0, TextFormat("resources/shaders/glsl%i/scanlines.fs", GLSL_VERSION));
}

static float shakeDuration = 0.0f;
static float targetX = 0.0f;
static float targetY = 0.0f;
static int shakeStrength = 10;

void RenderGame(void)
{
    BeginDrawing();
        ClearBackground(COLOR_A);
        BeginShaderMode(scanlinesShader);
            DrawTexturePro(renderTexture.texture, 
            (Rectangle){0, 0, (float)renderTexture.texture.width, -(float)renderTexture.texture.height}, 
            (Rectangle){targetX, targetY, (float)screenWidth, (float)screenHeight}, (Vector2){0, 0}, 0.0f, WHITE);
        EndShaderMode();
        DrawTexturePro(uiTexture.texture, (Rectangle){0, 0, (float)uiTexture.texture.width, -(float)uiTexture.texture.height}, (Rectangle){0, 0, (float)screenWidth, (float)screenHeight}, (Vector2){0, 0}, 0.0f, WHITE);
    EndDrawing();
}

void UpdateRenderer(void) {
    shakeDuration -= GetFrameTime();
    if(shakeDuration > 0.0f) {
        targetX =  cosf(GetTime() * 90) * (float)shakeStrength;
        targetY = sinf(GetTime() * 180) * (float)shakeStrength;

    } else {
        targetX = 0.0f;
        targetY = 0.0f;
    }

}

void ShakeScreen(int strength) {
    shakeStrength = strength;
    shakeDuration = 0.15f;
    //TODO: calculate duration based on strength
}

RenderTexture2D GetRenderTexture() {
    return renderTexture;
}

RenderTexture2D GetUITexture() {
    return uiTexture;
}

void ReleaseRenderer(void)
{
    UnloadShader(scanlinesShader);
    UnloadRenderTexture(renderTexture);
    UnloadRenderTexture(uiTexture);
}
