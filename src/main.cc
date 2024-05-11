// entrypoint for writing your own logic

#include "main.hh"

int DevMain::Init() {
  // put your initialization logic here
  viewer = new Viewer();
  audio = new AudioPlayer();
  player = new Player();

  return 0;
}

int DevMain::Update() {
  // put your update logic here
  std::cout << "Updating" << std::endl;
  player->Update();

  audio->Update();

  viewer->OpenRender();
  player->Render(viewer->GetRenderer());
  viewer->CloseRender();

  return 0;

  SDL_Delay(16);
}


int DevMain::DeInit(){
  delete player;
  delete audio;
  delete viewer;

  SDL_Quit();

  return 0;
}