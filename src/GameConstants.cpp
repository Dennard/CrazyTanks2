#include "GameConstants.h"

const Gdiplus::Rect GameConstants::getMainFieldRect()
{
  return Gdiplus::Rect(0, 0, 600, 700);
}

const Gdiplus::Rect GameConstants::getStatFieldRect()
{
  return Gdiplus::Rect(0, 600, 600, 100);
}

const Gdiplus::Rect GameConstants::getDownBorderRect()
{
  return Gdiplus::Rect(0, 580, 600, 20);
}

const Gdiplus::Rect GameConstants::getUpperBorderRect()
{
  return Gdiplus::Rect(0, 0, 600, 20);
}

const Gdiplus::Rect GameConstants::getLeftBorderRect()
{
  return Gdiplus::Rect(0, 20, 20, 560);
}

const Gdiplus::Rect GameConstants::getRightBorderRect()
{
  return Gdiplus::Rect(580, 20, 20, 560);
}

Gdiplus::SolidBrush* GameConstants::getWhiteBrush()
{
  static Gdiplus::SolidBrush* whitebrush = new Gdiplus::SolidBrush(Gdiplus::Color(255, 255, 255));
  return whitebrush;
}

Gdiplus::SolidBrush* GameConstants::getBlackBrush()
{
  static Gdiplus::SolidBrush* blackbrush = new Gdiplus::SolidBrush(Gdiplus::Color(0, 0, 0));
  return blackbrush;
}

Gdiplus::SolidBrush* GameConstants::getRedBrush()
{
  static Gdiplus::SolidBrush* redbrush = new Gdiplus::SolidBrush(Gdiplus::Color(255, 0, 0));
  return redbrush;
}

Gdiplus::SolidBrush* GameConstants::getBlueBrush()
{
  static Gdiplus::SolidBrush* bluebrush = new Gdiplus::SolidBrush(Gdiplus::Color(0, 0, 255));
  return bluebrush;
}

Gdiplus::SolidBrush * GameConstants::getTranspBrush()
{
  static Gdiplus::SolidBrush* transpbrush = new Gdiplus::SolidBrush(Gdiplus::Color(100,0, 0, 0));
  return transpbrush;
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

GameConstants::GameConstants()
{

}

GameConstants::GameConstants(const GameConstants &)
{

}

GameConstants::~GameConstants()
{

}
