#include <SDL2/SDL.h>
#include "player.hh"
#include "inputs.hh"

#include "main.hh"

DevMain devMain;
InputSingleton* inputs;


int main(int argc, char* argv[])
{
  devMain = DevMain();
  devMain.Init();

  inputs = InputSingleton::GetInstance();

  while (1){
    devMain.Update();
    
    inputs->Update();
    if (inputs->quit){
      exit(0);
    }
  }
  return 0;
}