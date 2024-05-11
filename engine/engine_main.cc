#include "main.hh"

DevMain devMain;

#ifdef __EMSCRIPTEN__
#include "emscripten.h"
#endif

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

int main(int argc, char* argv[])
{
  devMain.Init();

  #ifdef __EMSCRIPTEN__
  emscripten_set_main_loop(mainloop, 0, 1);
  #else
  while (1){mainloop();}
  #endif

  devMain.DeInit();
  return 0;
}