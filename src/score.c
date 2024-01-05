#include "score.h"

static int lastScore;
static int currentScore;
static int highScore;

void ResetScore(void) {
    if ( currentScore > 0 ) lastScore = currentScore;
    if ( currentScore > highScore ) highScore = currentScore; 
    currentScore = 0;
}

void UpdateScore(void) {

}

void AddScore(int score) {
    currentScore += score;
}

int GetHighScore(void) {
    return highScore;
}

int GetLastScore(void) {
    return lastScore;
}

int GetCurrentScore(void) {
    return currentScore;
}