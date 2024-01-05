#ifndef SCORE_H
#define SCORE_H

void ResetScore(void);
void UpdateScore(void);

void AddScore(int score);

int GetHighScore(void);
int GetLastScore(void);
int GetCurrentScore(void);

#endif