#include "utils.h"

void NormalizeAngle(float* angle) {
    *angle = remainder(*angle, TWO_PI);
    if (*angle < 0) {
        *angle = TWO_PI + *angle;
    }
}

float RadiansToDegrees(float radians) {
    return radians * (180 / PI);
}

void WrapPosition(float* x, float* y) {
    if (*x < 0.0f)	*x += (float) gameWidth;
    if (*x >= (float) gameWidth)	*x -= (float)gameWidth;
    if (*y < 0.0f) *y += (float) gameHeight;
    if (*y >= (float)gameHeight) *y -=(float)gameHeight;
}