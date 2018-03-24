//#include "GameObject.h"
#include "Wall.h"
#include "Tank.h"
#include "Missile.h"

Gdiplus::Rect& GameObject::getRect()
{
  return objectRect;
}

Gdiplus::Rect& GameObject::getMask()
{
  return objectMask;
}

GameObject& GameObject::createGameObject(GameObjectType type)
{
  switch (type) {
  case WALL: {
  //  wall = new Wall();
    Wall wall;
    return wall;
  }
  case TANK: {
    Tank* tank = new Tank();
    //Tank tank;
    return *tank;
  }
  case MISSILE: {
    Missile missile;
    return missile;
  }
  default:
    break;
  }

}
