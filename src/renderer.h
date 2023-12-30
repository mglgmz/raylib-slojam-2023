#ifndef RENDERER_H
#define RENDERER_H

#include <raylib.h>
#include "defs.h"
#include "screens/screens.h"

static RenderTexture2D renderTexture;
static RenderTexture2D uiTexture;
static Shader scanlinesShader;

void InitRenderer(void);
void RenderGame(void);
void ReleaseRenderer(void);

RenderTexture2D GetRenderTexture(void);
RenderTexture2D GetUITexture(void);

#endif