#ifndef  UTILS_H
#define UTILS_H

#include "defs.h"

void NormalizeAngle(float* angle);
float RadiansToDegrees(float radians);
int WrapPosition(float* x, float* y);

float GetDistance(float x1, float y1, float x2, float y2);
bool IsPointInsideCircle(float pofloatX, float pofloatY, float circleX, float circleY, float circleRadius);

float GetRandomFloat();

#endif // ! UTILS_H
