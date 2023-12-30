#ifndef RENDERER_H
#define RENDERER_H

#include <raylib.h>
#include "defs.h"
#include "screens/screens.h"

static RenderTexture2D renderTexture;
static RenderTexture2D uiTexture;
static Shader scanlinesShader;

void InitRenderer(void);
void ReleaseRenderer(void);

void RenderGame(void);
void UpdateRenderer(void);

void ShakeScreen(int strength);

RenderTexture2D GetRenderTexture(void);
RenderTexture2D GetUITexture(void);

#endif