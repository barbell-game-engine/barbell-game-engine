#ifndef DEV_MAIN_HH
#define DEV_MAIN_HH

#include "viewer.hh"
#include "player.hh"
#include "audio.hh"

class DevMain {
public:
  int Init();
  int Update();
  bool Quit();
  int DeInit();

  Viewer* viewer;
  Player* player;
  AudioPlayer* audio;
};


#endif