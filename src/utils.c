#include "utils.h"

#define RANDOM_FLOAT_MAX_INT 1000

void NormalizeAngle(float *angle)
{
    *angle = remainder(*angle, TWO_PI);
    if (*angle < 0)
    {
        *angle = TWO_PI + *angle;
    }
}

float RadiansToDegrees(float radians)
{
    return radians * (180 / PI);
}

int WrapPosition(float *x, float *y)
{
    int positionWrapped = 0;
    if (*x < 0.0f)
    {
        *x += (float)gameWidth;
        positionWrapped += 1;
    }
    if (*x >= (float)gameWidth)
    {
        *x -= (float)gameWidth;
        positionWrapped += 1;
    }
    if (*y < 0.0f)
    {
        *y += (float)gameHeight;
        positionWrapped += 1;
    }
    if (*y >= (float)gameHeight)
    {
        *y -= (float)gameHeight;
        positionWrapped += 1;
    }
    return positionWrapped;
}

float GetDistance(float x1, float y1, float x2, float y2)
{
    return sqrt(((x2 - x1) * (x2 - x1)) + ((y2 - y1) * (y2 - y1)));
}

bool IsPointInsideCircle(float pointX, float pointY, float circleX, float circleY, float circleRadius)
{
    return GetDistance(pointX, pointY, circleX, circleY) <= circleRadius;
}

float GetRandomFloat()
{
    return (float)GetRandomValue(0, RANDOM_FLOAT_MAX_INT) / (float)RANDOM_FLOAT_MAX_INT;
}