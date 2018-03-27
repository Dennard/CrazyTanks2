#include "Player.h"
#include "GameConstants.h"

Player* Player::p_instance = nullptr;

Player::Player()
{
  tankDirection = UP;

  getMask().Height = GameConstants::getInstance().getTankSize() * 2;
  getRect().Height = GameConstants::getInstance().getTankSize();
  getMask().Width = GameConstants::getInstance().getTankSize() * 2;
  getRect().Width = GameConstants::getInstance().getTankSize();

  getMask().X = GameConstants::getInstance().getPlayerStartingPosX() + 15;
  getRect().X = GameConstants::getInstance().getPlayerStartingPosX();
  getMask().Y = GameConstants::getInstance().getPlayerStartingPosY() + 15;
  getRect().Y = GameConstants::getInstance().getPlayerStartingPosY();

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
