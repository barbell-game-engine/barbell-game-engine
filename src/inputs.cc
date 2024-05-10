#include "inputs.hh"
#include <SDL2/SDL.h>
#include <iostream>

InputSingleton* InputSingleton::instance = nullptr;

InputSingleton* InputSingleton::GetInstance(){
  if (!instance){
    instance = new InputSingleton();
  }
  return instance;
}

void InputSingleton::Update(){
  SDL_Event event;

  while (SDL_PollEvent(&event)){
    switch (event.type){
      case SDL_QUIT:
        quit = true;
        break;
      case SDL_KEYDOWN:
        if (event.key.keysym.sym == SDLK_w){
          w_down = true;
        }
        if (event.key.keysym.sym == SDLK_a){
          a_down = true;
        }
        if (event.key.keysym.sym == SDLK_s){
          s_down = true;
        }
        if (event.key.keysym.sym == SDLK_d){
          d_down = true;
        }
        break;
      case SDL_KEYUP:
        if (event.key.keysym.sym == SDLK_w){
          w_down = false;
        }
        if (event.key.keysym.sym == SDLK_a){
          a_down = false;
        }
        if (event.key.keysym.sym == SDLK_s){
          s_down = false;
        }
        if (event.key.keysym.sym == SDLK_d){
          d_down = false;
        }
        break;
      default:
        break;
    }
  }
}