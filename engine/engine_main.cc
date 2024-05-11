#include "main.hh"

#ifdef __EMSCRIPTEN__
#include "emscripten.h"
#endif

DevMain devMain;


int init(){
  return devMain.Init();
}

void mainloop(){
  devMain.Update();

  if (devMain.Quit()){
    #ifdef __EMSCRIPTEN__
    emscripten_cancel_main_loop();
    #else
    exit(0);
    #endif
  }

}

int deinit(){
  return devMain.DeInit();
}


int main(int argc, char* argv[])
{
  int initCode = init();
  std::cout << "Initialized with code: " << initCode << std::endl;

  #ifdef __EMSCRIPTEN__
  emscripten_set_main_loop(mainloop, 0, 1);
  #else
  while(1){mainloop();};
  #endif

  int deinitCode = devMain.DeInit();
  std::cout << "DeInitialized with code: " << deinitCode << std::endl;

  return 0;
}