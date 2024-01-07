#ifndef DEFINITIONS_H
#define DEFINITIONS_H

#include "raylib.h"
#include <stdint.h>
#include <math.h>

static const int screenWidth = 320 * 3;
static const int screenHeight = 240 * 3;

static const int gameWidth = 320;
static const int gameHeight = 240;

#define COLOR_A    (Color){ 0x14, 0x13, 0x0f, 0xff }
#define COLOR_B    (Color){ 0x74, 0xfe, 0xca, 0xff }
#define COLOR_B_HI (Color){ 0x94, 0xfe, 0xea, 0xff }
#define COLOR_C    (Color){ 0x74, 0xfe, 0xca, 0xff }

// #define ASTEROID_BASE_COLOR GOLD
#define ASTEROID_BASE_SIZE 4

#define TWO_PI 6.28318530

#if defined(PLATFORM_DESKTOP)
    #define GLSL_VERSION            330
#else   // PLATFORM_ANDROID, PLATFORM_WEB
    #define GLSL_VERSION            100
#endif

#if defined(DEBUGGER)
    #define DEFAULT_SCREEN GAMEPLAY
#else
    #define DEFAULT_SCREEN LOGO
#endif



#endif