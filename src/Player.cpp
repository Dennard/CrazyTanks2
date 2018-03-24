#include "Player.h"

Player::Player()
{
  getMask().Height = TANK_SIZE;
  getRect().Height = TANK_SIZE / 2;
  getMask().Width = TANK_SIZE;
  getRect().Width = TANK_SIZE / 2;
  getMask().X = X_POS;
  getRect().X = X_POS - TANK_SIZE / 2;
  getMask().Y = Y_POS;
  getRect().Y = Y_POS - TANK_SIZE / 2;
}

Player::~Player()
{

}
