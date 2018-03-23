#ifndef WALLSGENERATING_H
#define WALLSGENERATING_H

#include "Generation.h"
#include <random>

class WallsGeneration :public Generation {
public:
  WallsGeneration();
  ~WallsGeneration();
  void generateGameObjects(int count, std::vector<GameObject*>& objVect);
  void randomizeWall(GameObject& wall);
private:

};

#endif