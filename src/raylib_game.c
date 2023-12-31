/*******************************************************************************************
 *
 *   raylib gamejam template
 *
 *   Template originally created with raylib 4.5-dev, last time updated with raylib 5.0
 *
 *   Template licensed under an unmodified zlib/libpng license, which is an OSI-certified,
 *   BSD-like license that allows static linking with closed source software
 *
 *   Copyright (c) 2022-2023 Ramon Santamaria (@raysan5)
 *
 ********************************************************************************************/

#include "defs.h"
#include <raylib.h>

#if defined(PLATFORM_WEB)
#define CUSTOM_MODAL_DIALOGS       // Force custom modal dialogs usage
#include <emscripten/emscripten.h> // Emscripten library - LLVM to JavaScript compiler
#endif

#include <stdio.h>  // Required for: printf()
#include <stdlib.h> // Required for:
#include <string.h>
#include "text.h"
#include "renderer.h"
#include "game_music.h"
#include "screens/screens.h"

#define SUPPORT_LOG_INFO
#if defined(SUPPORT_LOG_INFO)
#define LOG(...) printf(__VA_ARGS__)
#else
#define LOG(...)
#endif

static void UpdateDrawFrame(void); // Update and Draw one frame
static Shader scanlinesShader;

int main(void)
{
#if !defined(_DEBUG)
    SetTraceLogLevel(LOG_NONE);
#endif

    InitWindow(screenWidth, screenHeight, "AS73ROIDS");
    InitGameMusic();
    InitRenderer();
    InitText();
    InitCurrentScreen();
#if defined(PLATFORM_WEB)
    emscripten_set_main_loop(UpdateDrawFrame, 60, 1);
#else
    SetTargetFPS(60);            // Set our game frames-per-second
    while (!WindowShouldClose()) // Detect window close button
    {
        UpdateDrawFrame();
    }
#endif
    ReleaseCurrentScreen();
    ReleaseText();
    ReleaseGameMusic();
    ReleaseRenderer();
    CloseAudioDevice();
    CloseWindow();
    return 0;
}

void UpdateDrawFrame(void)
{
    UpdateRenderer();
    UpdateCurrentScreen();
    UpdateGameMusic();
    RenderGame();
}