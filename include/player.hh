#include <iostream>
#include "inputs.hh"
#include <SDL2/SDL.h>

#ifndef PLAYER_HH
#define PLAYER_HH

class Player{
public:
  Player();

  void Update();
  void Render(SDL_Renderer* renderer);

  void UpdateRectPos();

private:
  int x;
  int y;
  int width;
  int height;

  int speed;

  InputSingleton* inputs;

  SDL_Rect* rect;
};

#endif