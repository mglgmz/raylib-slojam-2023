#include "renderer.h"

void InitRenderer(void)
{
    renderTexture = LoadRenderTexture(gameWidth, gameHeight);
    scanlinesShader = LoadShader(0, TextFormat("resources/shaders/glsl%i/scanlines.fs", GLSL_VERSION));
}

void RenderGame(void)
{
    BeginDrawing();
        ClearBackground(COLOR_A);
        BeginShaderMode(scanlinesShader);
        RenderCurrentScreen();
        EndShaderMode();
    EndDrawing();
}

RenderTexture2D GetRenderTexture() {
    return renderTexture;
}

void ReleaseRenderer(void)
{
    UnloadShader(scanlinesShader);
    UnloadRenderTexture(renderTexture);
}
