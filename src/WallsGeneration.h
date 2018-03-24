#ifndef WALLSGENERATING_H
#define WALLSGENERATING_H

#include "Generation.h"

class WallsGeneration :public Generation {
public:
  WallsGeneration();
  ~WallsGeneration();
  void generateGameObjects(int count,
                          std::vector<GameObject>& objVect,
                          std::vector<GameObject>& tankVect);
  void randomizeWall(GameObject& wall);
private:

};

#endif