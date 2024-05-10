#include <SDL2/SDL.h>
#include "player.hh"
#include "inputs.hh"

#include "main.hh"

#ifdef __EMSCRIPTEN__
#include "emscripten.h"
#endif

DevMain devMain;
InputSingleton* inputs;


void init(){
  devMain.Init();

  #ifdef __EMSCRIPTEN__
  std::cout << "found emscripten!" << std::endl;
  #else
  std::cout << "couldn't find emscripten" << std::endl;
  #endif

  inputs = InputSingleton::GetInstance();
}

void mainloop(){
  inputs->Update();

  if(inputs->quit){
    #ifdef __EMSCRIPTEN__
    emscripten_cancel_main_loop();
    #endif
  }

  devMain.Update();
}



int main(int argc, char* argv[])
{
  init();

  #ifdef __EMSCRIPTEN__
  emscripten_set_main_loop(mainloop, 0, 1);
  #endif

  return 0;
}