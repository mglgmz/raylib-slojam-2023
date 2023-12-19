#ifndef DEFINITIONS_H
#define DEFINITIONS_H

#include "raylib.h"
#include <stdint.h>
#include <math.h>

static const int screenWidth = 1280;
static const int screenHeight = 960;

static const int gameWidth = 320;
static const int gameHeight = 240;

#define CLEAR_COLOR BLACK

#define PLAYER_COLOR RED

#define ASTEROID_BASE_COLOR GOLD
#define ASTEROID_BASE_SIZE 4

#define TWO_PI 6.28318530

#if defined(PLATFORM_DESKTOP)
    #define GLSL_VERSION            330
#else   // PLATFORM_ANDROID, PLATFORM_WEB
    #define GLSL_VERSION            100
#endif

#endif