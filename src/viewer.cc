#include "viewer.hh"

Viewer::Viewer(){
  const int WIDTH = 640;
  const int HEIGHT = 480;

  SDL_Init(SDL_INIT_VIDEO);
  window = SDL_CreateWindow("SDL2 Test", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
}

Viewer::~Viewer(){
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
}

void Viewer::OpenRender(){
  // Set render color to black
  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
  SDL_RenderClear(renderer);
}

void Viewer::CloseRender(){
  // display on viewer
  SDL_RenderPresent(renderer);
}