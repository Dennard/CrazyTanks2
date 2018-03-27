
#include "Wall.h"
#include "Tank.h"

Gdiplus::Rect& GameObject::getRect()
{
  return objectRect;
}

Gdiplus::Rect& GameObject::getMask()
{
  return objectMask;
}
