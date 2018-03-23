#ifndef PLAYER_H
#define PLAYER_H

#include "Tank.h"

class Player :public Tank {
public:
  Player();
  ~Player();
private:
  const int X_POS = 300;
  const int Y_POS = 520;
  int hitPoints;
};



#endif