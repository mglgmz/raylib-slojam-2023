#ifndef GAME_MUSIC_H
#define GAME_MUSIC_H

#include <raylib.h>

void InitGameMusic(void);
void ReleaseGameMusic(void);
void UpdateGameMusic(void);

// music management
static char* currentMusicName;
static Music music;
static bool paused;

void LoadMusic(char* musicName);
void PlayMusic(char* musicName);
void PauseMusic(void);
void StopMusic(void);
void ResumeMusic(void);
void CloseMusic(char* musicName);
void UpdateMusicVolume(float newVolume);
void UpdateMusicPitch(float newPitch);

#endif