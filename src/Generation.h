#ifndef GENERATION_H
#define GENERATION_H

#include <random>
#include "Wall.h"
#include "Tank.h"

class Generation {
public:
  virtual void generateGameObjects(int count,
                                  std::vector<std::shared_ptr<Wall>>& wallVect,
                                  std::vector<std::shared_ptr<Tank>>& tankVect) = 0;
};

#endif