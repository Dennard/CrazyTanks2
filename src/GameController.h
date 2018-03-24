#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include "Generator.h"
#include "Player.h"

class GameController {
public:
  std::vector<GameObject> wallVect;
  std::vector<GameObject> tankVect;
  static void getControlKeys(Tank & player, 
                    std::vector<GameObject>& wallVect,
                    std::vector<GameObject>& tankVect);

private:

};

#endif