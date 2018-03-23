#include "GameObject.h"
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

GameObject * GameObject::createGameObject(GameObjectType type)
{
  Tank* tank = nullptr;
  Wall* wall = nullptr;
  Missile* missile = nullptr;
  switch (type) {
  case WALL: {
    wall = new Wall();
    delete tank;
    delete missile;
    return wall;
  }
  case TANK: {
    tank = new Tank();
    delete wall;
    delete missile;
    return tank;
  }
  case MISSILE: {
    missile = new Missile();
    delete tank;
    delete wall;
    return missile;
  }
  }

}
