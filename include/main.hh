#ifndef DEV_MAIN_HH
#define DEV_MAIN_HH

#include "viewer.hh"
#include "player.hh"
#include "audio.hh"
#include "inputs.hh"

class DevMain {
public:
  int Init();
  int Update();
  int DeInit();

  Viewer* viewer;
  Player* player;
  AudioPlayer* audio;
};


#endif