#include "game_music.h"

void InitGameMusic(void)
{
    // InitAudioDevice();
    // LoadMusic("asteroids");
}

void UpdateGameMusic(void)
{
    //UpdateMusicStream(music);
}

void LoadMusic(char *musicName)
{
    // if (musicName == currentMusicName)
    //     return;
    // CloseMusic(currentMusicName);
    // currentMusicName = musicName;
    // music = LoadMusicStream(TextFormat("resources/sounds/music/%s.ogg", musicName));
    // music.looping = true;
}

void PlayMusic(char *musicName)
{
    // if (musicName != currentMusicName);
    //     LoadMusic(musicName);
    // if(!IsMusicStreamPlaying(music))
    //     PlayMusicStream(music);
}

void PauseMusic(void)
{
    paused = true;
    //PauseMusicStream(music);
}

void ResumeMusic(void)
{
    if (!paused)
        return;
    //ResumeMusicStream(music);
    paused = false;
}

void StopMusic(void)
{
    StopMusicStream(music);
}

void CloseMusic(char *musicName)
{
    if (musicName == currentMusicName)
        return;
    //UnloadMusicStream(music);
}

void UpdateMusicVolume(float newVolume)
{
    //SetMusicVolume(music, newVolume);
}

void UpdateMusicPitch(float newPitch)
{
    //SetMusicPitch(music, newPitch);
}

void ReleaseGameMusic(void)
{
    //UnloadMusicStream(music);
    CloseAudioDevice();
}