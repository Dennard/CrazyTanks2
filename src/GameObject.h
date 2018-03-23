#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <vector>

#include <objidl.h>
#include <gdiplus.h>
#include <windows.h>

#pragma comment(lib, "gdiplus.lib")

enum GameObjectType {
  WALL,
  TANK,
  MISSILE
};

class GameObject {
public:
  Gdiplus::Rect& getRect();
  Gdiplus::Rect& getMask();
  std::vector<Gdiplus::Rect> parts;
  static GameObject* createGameObject(GameObjectType type);
protected:
  Gdiplus::Rect objectRect;
  Gdiplus::Rect objectMask;
private:


};

#endif 