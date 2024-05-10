#ifndef VIEWER_HH
#define VIEWER_HH

#include <SDL2/SDL.h>

class Viewer{
public:
  Viewer();
  ~Viewer();

  void OpenRender();
  void CloseRender();

  SDL_Renderer* GetRenderer(){return renderer;};

private:
  SDL_Renderer* renderer;
  SDL_Window* window;
};

#endif