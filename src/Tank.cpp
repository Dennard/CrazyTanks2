#include "Tank.h"

Tank::Tank()
{
  getMask().Height = SIZE;
  getRect().Height = SIZE / 2;
  getMask().Width = SIZE;
  getRect().Width = SIZE / 2;
}

Tank::~Tank()
{
}

Gdiplus::Rect & Tank::getCannon()
{
  return cannonRect;
}

void Tank::moveBackward()
{

}

void Tank::moveForward()
{

}

void Tank::turnLeft()
{

}

void Tank::turnRight()
{

}

bool Tank::isCollisionCausedForward(std::vector<GameObject*>& wallVect,
  std::vector<GameObject*>& tankVect)
{
  Gdiplus::Rect forwardRect(getRect().X,
    getRect().Y - 3,
    getRect().Height,
    getRect().Width);
  for (int i = 0; i < wallVect.size(); i++) {
    if (forwardRect.IntersectsWith(wallVect[i]->getRect()))
      return true;
  }
  for (int i = 0; i < tankVect.size(); i++) {
    if (forwardRect.IntersectsWith(tankVect[i]->getRect()))
      return true;
  }
  return false;
}

bool Tank::isCollisionCausedBackward(std::vector<GameObject*>& wallVect,
  std::vector<GameObject*>& tankVect)
{
  Gdiplus::Rect forwardRect(getRect().X,
    getRect().Y + 3,
    getRect().Height,
    getRect().Width);
  for (int i = 0; i < wallVect.size(); i++) {
    if (forwardRect.IntersectsWith(wallVect[i]->getRect()))
      return true;
  }
  for (int i = 0; i < tankVect.size(); i++) {
    if (forwardRect.IntersectsWith(tankVect[i]->getRect()))
      return true;
  }
  return false;
}

bool Tank::isCollisionCausedLeft(std::vector<GameObject*>& wallVect,
  std::vector<GameObject*>& tankVect)
{
  Gdiplus::Rect forwardRect(getRect().X - 3,
    getRect().Y,
    getRect().Height,
    getRect().Width);
  for (int i = 0; i < wallVect.size(); i++) {
    if (forwardRect.IntersectsWith(wallVect[i]->getRect()))
      return true;
  }
  for (int i = 0; i < tankVect.size(); i++) {
    if (forwardRect.IntersectsWith(tankVect[i]->getRect()))
      return true;
  }
  return false;
}

bool Tank::isCollisionCausedRight(std::vector<GameObject*>& wallVect,
  std::vector<GameObject*>& tankVect)
{
  Gdiplus::Rect forwardRect(getRect().X + 3,
    getRect().Y,
    getRect().Height,
    getRect().Width);
  for (int i = 0; i < wallVect.size(); i++) {
    if (forwardRect.IntersectsWith(wallVect[i]->getRect()))
      return true;
  }
  for (int i = 0; i < tankVect.size(); i++) {
    if (forwardRect.IntersectsWith(tankVect[i]->getRect()))
      return true;
  }
  return false;
}
