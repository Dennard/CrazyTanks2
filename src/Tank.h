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
  bool isCollisionCausedForward(std::vector<GameObject*>& wallVect, 
                                std::vector<GameObject*>& tankVect);
  bool isCollisionCausedBackward(std::vector<GameObject*>& wallVect,
                                 std::vector<GameObject*>& tankVect);
  bool isCollisionCausedLeft(std::vector<GameObject*>& wallVect,
                             std::vector<GameObject*>& tankVect);
  bool isCollisionCausedRight(std::vector<GameObject*>& wallVect,
                              std::vector<GameObject*>& tankVect);
protected:
  Gdiplus::Rect cannonRect;
  const int SIZE = 60;
private:
};



#endif