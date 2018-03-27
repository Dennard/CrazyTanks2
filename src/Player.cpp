#include "Player.h"

Player* Player::p_instance = nullptr;

Player::Player()
{
  tankDirection = UP;

  getMask().Height = GameConstants::getTankSize() * 2;
  getRect().Height = GameConstants::getTankSize();
  getMask().Width = GameConstants::getTankSize() * 2;
  getRect().Width = GameConstants::getTankSize();

  getMask().X = GameConstants::getPlayerStartingPosX() + 15;
  getRect().X = GameConstants::getPlayerStartingPosX();
  getMask().Y = GameConstants::getPlayerStartingPosY() + 15;
  getRect().Y = GameConstants::getPlayerStartingPosY();

  getCannon().X = getRect().X + 10;
  getCannon().Y = getRect().Y;

  getCannon().Height = getRect().Height - 10;
  getCannon().Width = getRect().Width - 20;
}

Player::~Player()
{

}

Player& Player::getInstance()
{
  if (!p_instance)
    p_instance = new Player();
  return *p_instance;
}

int Player::getHitPoints() const
{
  return hitPoints;
}
