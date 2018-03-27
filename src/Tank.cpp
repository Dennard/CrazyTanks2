#include "Tank.h"
#include "Wall.h"

Tank::Tank()
{
  tankDirection = DOWN;
  getMask().Height = 60;
  getRect().Height = 30;
  getMask().Width = 60;
  getRect().Width = 30;
}

Tank::~Tank()
{

}

Gdiplus::Rect & Tank::getCannon()
{
  return cannonRect;
}

void Tank::moveBackward(std::vector<std::shared_ptr<Wall>> wallVect,
                        std::vector<std::shared_ptr<Tank>> tankVect)
{
  if (tankDirection == UP) {
    if (isCollisionCausedForward(wallVect, tankVect) == false) {
      getRect().Y += 1;
      getMask().Y += 1;
      getCannon().Y += 1;
    }
  }
  if (tankDirection == DOWN) {
    if (isCollisionCausedBackward(wallVect, tankVect) == false) {
      getRect().Y -= 1;
      getMask().Y -= 1;
      getCannon().Y -= 1;
    }
  }
  if (tankDirection == RIGHT) {
    if (isCollisionCausedLeft(wallVect, tankVect) == false) {
      getRect().X -= 1;
      getMask().X -= 1;
      getCannon().X -= 1;
    }
  }
  if (tankDirection == LEFT) {
    if (isCollisionCausedRight(wallVect, tankVect) == false) {
      getRect().X += 1;
      getMask().X += 1;
      getCannon().X += 1;
    }
  }
}

void Tank::moveForward(std::vector<std::shared_ptr<Wall>> wallVect,
                       std::vector<std::shared_ptr<Tank>> tankVect)
{
  if (tankDirection == UP) {
    if (isCollisionCausedForward(wallVect, tankVect) == false) {
      getRect().Y -= 1;
      getMask().Y -= 1;
      getCannon().Y -= 1;
    }
  }
  if (tankDirection == DOWN) {
    if (isCollisionCausedBackward(wallVect, tankVect) == false) {
      getRect().Y += 1;
      getMask().Y += 1;
      getCannon().Y += 1;
    }
  }
  if (tankDirection == RIGHT) {
    if (isCollisionCausedRight(wallVect, tankVect) == false) {
      getRect().X += 1;
      getMask().X += 1;
      getCannon().X += 1;
    }
  }
  if (tankDirection == LEFT) {
    if (isCollisionCausedLeft(wallVect, tankVect) == false) {
      getRect().X -= 1;
      getMask().X -= 1;
      getCannon().X -= 1;
    }
  }
}

void Tank::turnLeft()
{
  switch (tankDirection) {
  case UP: 
      getCannon().X = getRect().X;
      getCannon().Y = getRect().Y + 10;
      getCannon().Height = getRect().Height - 10;
      getCannon().Width = getRect().Width - 20;
      tankDirection = LEFT;
      break;
  case LEFT:
      getCannon().X = getRect().X + 10;
      getCannon().Y = getRect().Y;
      getCannon().Height = getRect().Height - 20;
      getCannon().Width = getRect().Width - 10;
      tankDirection = DOWN;
      break;
  case DOWN:
      getCannon().X = getRect().X;
      getCannon().Y = getRect().Y + 10;
      getCannon().Height = getRect().Height - 10;
      getCannon().Width = getRect().Width - 20;
      tankDirection = RIGHT;
      break;
  case RIGHT:
      getCannon().X = getRect().X + 10;
      getCannon().Y = getRect().Y + 10;
      getCannon().Height = getRect().Height - 20;
      getCannon().Width = getRect().Width - 10;
      tankDirection = UP;
      break;
  default:
    break;
  }
}

void Tank::turnRight()
{
  switch (tankDirection) {
  case UP:
      getCannon().X = getRect().X;
      getCannon().Y = getRect().Y + 10;
      getCannon().Height = getRect().Height - 10;
      getCannon().Width = getRect().Width - 20;
      tankDirection = RIGHT;
      break;
  case LEFT:
      getCannon().X = getRect().X + 10;
      getCannon().Y = getRect().Y + 10;
      getCannon().Height = getRect().Height - 20;
      getCannon().Width = getRect().Width - 10;
      tankDirection = UP;
      break;
  case DOWN:
      getCannon().X = getRect().X + 10;
      getCannon().Y = getRect().Y + 10;
      getCannon().Height = getRect().Height - 10;
      getCannon().Width = getRect().Width - 20;
      tankDirection = LEFT;
      break;
  case RIGHT:
      getCannon().X = getRect().X - 10;
      getCannon().Y = getRect().Y;
      getCannon().Height = getRect().Height - 20;
      getCannon().Width = getRect().Width - 10;
      tankDirection = DOWN;
      break;
  }
}

bool Tank::isCollisionCausedForward(std::vector<std::shared_ptr<Wall>> wallVect,
                                    std::vector<std::shared_ptr<Tank>> tankVect)
{
  Gdiplus::Rect forwardRect(getRect().X,
                            getRect().Y - 2,
                            getRect().Height,
                            getRect().Width);
  for (int i = 0; i < wallVect.size(); i++) {
    if (forwardRect.IntersectsWith(wallVect[i]->getRect()) == true) 
      return true;
  }
  for (int i = 0; i < tankVect.size(); i++) {
    if (forwardRect.IntersectsWith(tankVect[i]->getRect()) == true)
      return true;
  }
  if (forwardRect.Y <= 20 ||
    forwardRect.Y >= 555 ||
    forwardRect.X >= 555 ||
    forwardRect.X <= 20)
    return true;
  return false;
}

bool Tank::isCollisionCausedBackward(std::vector<std::shared_ptr<Wall>> wallVect,
                                     std::vector<std::shared_ptr<Tank>> tankVect)
{
  Gdiplus::Rect forwardRect(getRect().X,
                            getRect().Y + 2,
                            getRect().Height,
                            getRect().Width);
  for (int i = 0; i < wallVect.size(); i++) {
    if (forwardRect.IntersectsWith(wallVect[i]->getRect()) == true)
      return true;
  }
  for (int i = 0; i < tankVect.size(); i++) {
    if (forwardRect.IntersectsWith(tankVect[i]->getRect()) == true)
      return true;
  }
  if (forwardRect.Y <= 20 ||
    forwardRect.Y >= 555 ||
    forwardRect.X >= 555 ||
    forwardRect.X <= 20)
    return true;
  return false;
}

bool Tank::isCollisionCausedLeft(std::vector<std::shared_ptr<Wall>> wallVect,
                                 std::vector<std::shared_ptr<Tank>> tankVect)
{
  Gdiplus::Rect forwardRect(getRect().X - 2,
    getRect().Y,
    getRect().Height,
    getRect().Width);
  for (int i = 0; i < wallVect.size(); i++) {
    if (forwardRect.IntersectsWith(wallVect[i]->getRect()) == true)
      return true;
  }
  for (int i = 0; i < tankVect.size(); i++) {
    if (forwardRect.IntersectsWith(tankVect[i]->getRect()) == true)
      return true;
  }
  if (forwardRect.Y <= 20 ||
    forwardRect.Y >= 555 ||
    forwardRect.X >= 555 ||
    forwardRect.X <= 20)
    return true;
  return false;
}

bool Tank::isCollisionCausedRight(std::vector<std::shared_ptr<Wall>> wallVect,
                                  std::vector<std::shared_ptr<Tank>> tankVect)
{
  Gdiplus::Rect forwardRect(getRect().X + 2,
    getRect().Y,
    getRect().Height,
    getRect().Width);
  for (int i = 0; i < wallVect.size(); i++) {
    if (forwardRect.IntersectsWith(wallVect[i]->getRect()) == true)
      return true;
  }
  for (int i = 0; i < tankVect.size(); i++) {
    if (forwardRect.IntersectsWith(tankVect[i]->getRect()) == true)
      return true;
  }
  if (forwardRect.Y <= 20 ||
    forwardRect.Y >= 555 ||
    forwardRect.X >= 555 ||
    forwardRect.X <= 20)
    return true;
  return false;
}
