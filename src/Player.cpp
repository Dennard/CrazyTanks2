#include "Player.h"

Player::Player()
{
  tankDirection = UP;
  getMask().Height = 60;
  getRect().Height = 30;
  getMask().Width = 60;
  getRect().Width = 30;
  getMask().X = X_POS;
  getRect().X = X_POS - 15;
  getMask().Y = Y_POS;
  getRect().Y = Y_POS - 15;
}

Player::~Player()
{

}

int Player::getHitPoints() const
{
  return hitPoints;
}
