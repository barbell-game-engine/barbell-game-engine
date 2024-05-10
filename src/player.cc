#include "player.hh"

Player::Player(){
  std::cout << "Hello, Player!" << std::endl;

  x = 10;
  y = 10;
  width = 50;
  height = 25;
  speed = 10;

  inputs = InputSingleton::GetInstance();

  // init the rect
  rect = new SDL_Rect();
  UpdateRectPos();
}

void Player::Update(){
  if (inputs->s_down){
    y += speed;
  }
  if (inputs->w_down){
    y -= speed;
  }
  if (inputs->a_down){
    x -= speed;
  }
  if (inputs->d_down){
    x += speed;
  }

  UpdateRectPos();
}

void Player::Render(SDL_Renderer* renderer){
  // draw rect
  SDL_SetRenderDrawColor(renderer, 255, 150, 255, 2);
  SDL_RenderFillRect(renderer, rect);
  SDL_RenderDrawRect(renderer, rect);
}

void Player::UpdateRectPos(){
  rect->x = x;
  rect->y = y;
  rect->w = width;
  rect->h = height;
}