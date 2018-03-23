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
  GameObject* p = nullptr;
  switch (type) {
  case WALL:
    p = new Wall();
    break;
  case TANK:
    p = new Tank();
    break;
  case MISSILE:
    p = new Missile();
    break;
  }
  return p;
}
