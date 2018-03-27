#ifndef TANK_H
#define TANK_H

#include "Wall.h"
#include "GameConstants.h"

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

  void moveBackward(std::vector<std::shared_ptr<Wall>> wallVect,
                    std::vector<std::shared_ptr<Tank>> tankVect);

  void moveForward(std::vector<std::shared_ptr<Wall>> wallVect,
                   std::vector<std::shared_ptr<Tank>> tankVect);
  void turnLeft();
  void turnRight();

  bool isCollisionCausedForward(std::vector<std::shared_ptr<Wall>> wallVect,
                                std::vector<std::shared_ptr<Tank>> tankVect);

  bool isCollisionCausedBackward(std::vector<std::shared_ptr<Wall>> wallVect,
                                 std::vector<std::shared_ptr<Tank>> tankVect);

  bool isCollisionCausedLeft(std::vector<std::shared_ptr<Wall>> wallVect,
                             std::vector<std::shared_ptr<Tank>> tankVect);

  bool isCollisionCausedRight(std::vector<std::shared_ptr<Wall>> wallVect,
                              std::vector<std::shared_ptr<Tank>> tankVect);

protected:
  Gdiplus::Rect cannonRect;
private:
  
};



#endif