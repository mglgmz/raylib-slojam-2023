#ifndef  UTILS_H
#define UTILS_H

#include "defs.h"

void NormalizeAngle(float* angle);
float RadiansToDegrees(float radians);

int WrapPosition(float* x, float* y, int size);

float GetDistance(float x1, float y1, float x2, float y2);

bool IsPointInsideCircle(float pofloatX, float pofloatY, float circleX, float circleY, float circleRadius);

float GetRandomFloat();
float GetRandomRadsBetween(float min, float max);
float GetRandomRads();

#define RADS_0 0.0f
#define RADS_45 (PI / 4)
#define RADS_90 (PI / 2)
#define RADS_135 (3 * PI / 4)
#define RADS_180 PI
#define RADS_225 (5 * PI / 4)
#define RADS_270 (3 * PI / 2)
#define RADS_315 (7 * PI / 4)
#define RADS_360 (2 * PI)
#define RADS_405 (9 * PI / 4)
#endif // ! UTILS_H
