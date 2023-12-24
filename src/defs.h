#ifndef DEFINITIONS_H
#define DEFINITIONS_H

#include "raylib.h"
#include <stdint.h>
#include <math.h>

static const int screenWidth = 1280;
static const int screenHeight = 960;

static const int gameWidth = 320;
static const int gameHeight = 240;

#define COLOR_A (Color){ 0x14, 0x13, 0x0f, 0xff }
#define COLOR_B (Color){ 0x74, 0xfe, 0xca, 0xff }
#define COLOR_C (Color){ 0x74, 0xfe, 0xca, 0xff }

// #define ASTEROID_BASE_COLOR GOLD
#define ASTEROID_BASE_SIZE 4

#define TWO_PI 6.28318530

#if defined(PLATFORM_DESKTOP)
    #define GLSL_VERSION            330
#else   // PLATFORM_ANDROID, PLATFORM_WEB
    #define GLSL_VERSION            100
#endif

#if defined(DEBUGGER)
    #define DEFAULT_SCREEN MENU
#else
    #define DEFAULT_SCREEN LOGO
#endif

#endif