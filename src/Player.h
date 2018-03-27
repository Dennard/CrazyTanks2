#ifndef PLAYER_H
#define PLAYER_H

#include "Tank.h"

class Player :public Tank {
public:

  static Player& getInstance();

  int getHitPoints() const;

private:
  Player();
  Player(const Player&);
  ~Player();
  Player& operator=(const Player&);

  static Player* p_instance;

  int hitPoints;
};

#endif