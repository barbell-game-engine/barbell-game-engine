#ifndef AUDIO_PLAYER_HH
#define AUDIO_PLAYER_HH

#include <SDL2/SDL.h>
#include "inputs.hh"


class AudioPlayer{
public:
  AudioPlayer();
  ~AudioPlayer();

  void PlaySound();
  void Update();

private:

  int InitAudio();

  SDL_AudioSpec wavSpec;
  Uint32 wavLength;
  Uint8* wavBuffer;
  SDL_AudioDeviceID audioDevice;
  InputSingleton* inputs;
  bool audioPlaying;

  int audioStatus;
};


#endif