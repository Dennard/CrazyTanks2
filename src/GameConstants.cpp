#include "GameConstants.h"

GameConstants* GameConstants::p_instance = nullptr;

GameConstants & GameConstants::getInstance()
{
  if (!p_instance)
    p_instance = new GameConstants();
  return *p_instance;
}

const Gdiplus::Rect GameConstants::getMainFieldSize()
{
  return Gdiplus::Rect(0,0,600,700);
}

const Gdiplus::Rect GameConstants::getStatFieldSize()
{
  return Gdiplus::Rect(0,600,600,100);
}

const int GameConstants::getTankSize()
{
  return 30;
}

const int GameConstants::getPlayerStartingPosX()
{
  return 300;
}

const int GameConstants::getPlayerStartingPosY()
{
  return 500;
}
