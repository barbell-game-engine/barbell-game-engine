#include <SDL2/SDL.h>
#include "player.hh"
#include "inputs.hh"

#include "main.hh"

DevMain devMain;
InputSingleton* inputs;

#ifdef __EMSCRIPTEN__
#include "emscripten.h"
#endif

void mainloop(){
  devMain.Update();
    
  inputs->Update();
  if (inputs->quit){
    exit(0);
  }
}

int main(int argc, char* argv[])
{
  devMain = DevMain();
  devMain.Init();

  inputs = InputSingleton::GetInstance();

  #ifdef __EMSCRIPTEN__
  emscripten_set_main_loop(mainloop, 0, 1);
  #else
  while (1){mainloop();}
  #endif

  devMain.DeInit();
  return 0;
}