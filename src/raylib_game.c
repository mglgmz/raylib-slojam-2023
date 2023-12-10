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
    #define CUSTOM_MODAL_DIALOGS            // Force custom modal dialogs usage
    #include <emscripten/emscripten.h>      // Emscripten library - LLVM to JavaScript compiler
#endif

#include <stdio.h>                          // Required for: printf()
#include <stdlib.h>                         // Required for: 
#include <string.h>                         // Required for: 
#include "player.h"
#include "space.h"
#include "simulation.h"
#include "game_ui.h"

#define SUPPORT_LOG_INFO
#if defined(SUPPORT_LOG_INFO)
    #define LOG(...) printf(__VA_ARGS__)
#else
    #define LOG(...)
#endif

// typedef enum { 
//     SCREEN_LOGO = 0, 
//     SCREEN_TITLE, 
//     SCREEN_GAMEPLAY, 
//     SCREEN_ENDING
// } GameScreen;

static const int screenWidth = 1280;
static const int screenHeight = 960;

static RenderTexture2D target = { 0 };  // Render texture to render our game
static RenderTexture2D uiTarget = { 0 };

static void UpdateDrawFrame(void);      // Update and Draw one frame

int main(void)
{
#if !defined(_DEBUG)
    SetTraceLogLevel(LOG_NONE); 
#endif

    InitWindow(screenWidth, screenHeight, "raylib gamejam template");
    
    // TODO: Load resources / Initialize variables at this point
    InitPlayer();
    InitSpace();
    // Render texture to draw full screen, enables screen scaling
    // NOTE: If screen is scaled, mouse input should be scaled proportionally
    target = LoadRenderTexture(gameWidth, gameHeight);
    uiTarget = LoadRenderTexture(screenWidth, screenHeight);

    //SetTextureFilter(target.texture, TEXTURE_FILTER_ANISOTROPIC_4X);

#if defined(PLATFORM_WEB)
    emscripten_set_main_loop(UpdateDrawFrame, 60, 1);
#else
    SetTargetFPS(60);     // Set our game frames-per-second
    while (!WindowShouldClose())    // Detect window close button
    {
        UpdateDrawFrame();
    }
#endif
    ReleaseSpace();
    ReleasePlayer();
    UnloadRenderTexture(target);
    CloseWindow();
    return 0;
}


void UpdateDrawFrame(void)
{

    UpdatePlayer();
    UpdateSimulation();

    UpdateUI();

    BeginTextureMode(target);
        ClearBackground(RAYWHITE);
        
        DrawRectangle(0, 0, screenWidth, screenHeight, BLACK);
        
        RenderPlayer();
        RenderSpace();

    EndTextureMode();

    BeginTextureMode(uiTarget);
        ClearBackground(BLANK);

        RenderUI();
    EndTextureMode();
    
    BeginDrawing();
        ClearBackground(RAYWHITE);
        
        // Draw render texture to screen, scaled if required
        DrawTexturePro(target.texture, (Rectangle){ 0, 0, (float)target.texture.width, -(float)target.texture.height }, (Rectangle){ 0, 0, (float)screenWidth, (float)screenHeight }, (Vector2){ 0, 0 }, 0.0f, WHITE);
        DrawTexturePro(uiTarget.texture, (Rectangle){ 0, 0, (float)uiTarget.texture.width, -(float)uiTarget.texture.height }, (Rectangle){ 0, 0, (float)screenWidth, (float)screenHeight }, (Vector2){ 0, 0 }, 0.0f, WHITE);
        
    EndDrawing(); 
}