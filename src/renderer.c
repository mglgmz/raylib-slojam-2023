#include "renderer.h"

void InitRenderer(void)
{
    renderTexture = LoadRenderTexture(gameWidth, gameHeight);
    uiTexture = LoadRenderTexture(screenWidth, screenHeight);
    scanlinesShader = LoadShader(0, TextFormat("resources/shaders/glsl%i/scanlines.fs", GLSL_VERSION));
}

void RenderGame(void)
{
    BeginDrawing();
        ClearBackground(COLOR_A);
        BeginShaderMode(scanlinesShader);
            DrawTexturePro(renderTexture.texture, (Rectangle){0, 0, (float)renderTexture.texture.width, -(float)renderTexture.texture.height}, (Rectangle){0, 0, (float)screenWidth, (float)screenHeight}, (Vector2){0, 0}, 0.0f, WHITE);
        EndShaderMode();
        DrawTexturePro(uiTexture.texture, (Rectangle){0, 0, (float)uiTexture.texture.width, -(float)uiTexture.texture.height}, (Rectangle){0, 0, (float)screenWidth, (float)screenHeight}, (Vector2){0, 0}, 0.0f, WHITE);
    EndDrawing();
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
