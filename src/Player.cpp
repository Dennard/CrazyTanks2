#include "Player.h"

Player::Player()
{
  getMask().Height = SIZE;
  getRect().Height = SIZE / 2;
  getMask().Width = SIZE;
  getRect().Width = SIZE / 2;
  getMask().X = X_POS;
  getRect().X = X_POS - 15;
  getMask().Y = Y_POS;
  getRect().Y = Y_POS - 15;
}

Player::~Player()
{

}
