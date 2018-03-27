#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <vector>
#include <memory>

#include <objidl.h>
#include <gdiplus.h>
#include <windows.h>

#pragma comment(lib, "gdiplus.lib")

class GameObject {
public:

  Gdiplus::Rect& getRect();
  Gdiplus::Rect& getMask();

protected:

  Gdiplus::Rect objectRect;
  Gdiplus::Rect objectMask;

};

#endif 