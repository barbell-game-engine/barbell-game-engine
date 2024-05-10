// entrypoint for writing your own logic

#include "main.hh"

int DevMain::Init() {
  // put your initialization logic here
  player = new Player();
  viewer = new Viewer();
  audio = new AudioPlayer();
  return 0;
}

int DevMain::Update() {
  // put your update logic here
  player->Update();

  audio->Update();

  viewer->OpenRender();
  player->Render(viewer->GetRenderer());
  viewer->CloseRender();
  return 0;
}