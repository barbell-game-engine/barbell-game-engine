#include "main.hh"

#ifdef __EMSCRIPTEN__
#include "emscripten.h"
#endif

DevMain devMain;
int initCode;
int updateCode;
int deinitCode;

int Init(){
  devMain = DevMain();
  initCode = devMain.Init();

  return initCode;
}

int MainLoop(){
  updateCode = devMain.Update();

  if (devMain.Quit()){
    #ifdef __EMSCRIPTEN__
    emscripten_cancel_main_loop();
    #else
    exit(0);
    #endif
  }

  return updateCode;
}


int main(){
  #ifdef __EMSCRIPTEN__
  emscripten_set_main_loop(MainLoop, 0, 1);
  #else
  while(1){MainLoop();};
  #endif

  deinitCode = devMain.DeInit();

  return deinitCode;
}