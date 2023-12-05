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