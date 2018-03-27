#ifndef WALLSGENERATING_H
#define WALLSGENERATING_H

#include "Generation.h"


class WallsGeneration :public Generation {
public:
  WallsGeneration();
  ~WallsGeneration();

  void generateGameObjects(int count,
                          std::vector<std::shared_ptr<Wall>>& wallVect,
                          std::vector<std::shared_ptr<Tank>>& tankVect);

  void randomizeWall(GameObject& wall);

private:

};

#endif