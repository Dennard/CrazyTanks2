#ifndef TANK_H
#define TANK_H

#include "GameObject.h"

enum Directions {
  UP,
  DOWN,
  LEFT,
  RIGHT
};

class Tank : public GameObject {
public:
  Tank();
  ~Tank();
  Directions tankDirection;
  Gdiplus::Rect& getCannon();
  void moveBackward();
  void moveForward();
  void turnLeft();
  void turnRight();
private:
  Gdiplus::Rect cannonRect;
};



#endif