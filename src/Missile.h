#ifndef MISSILE_H
#define MISSILE_H

#include "Tank.h"

class Missile :public GameObject {
public:
  Missile();
  Missile(Tank& tank, std::vector<std::shared_ptr<Missile>>& missVect);
  ~Missile();

  void move();

private:

  Directions missDirection;

};

#endif