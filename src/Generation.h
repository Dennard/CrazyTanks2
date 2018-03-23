#ifndef GENERATION_H
#define GENERATION_H

#include "GameObject.h"
#include <random>

class Generation {
public:
  virtual void generateGameObjects(int count,
                                  std::vector<GameObject*>& objVect, 
                                  std::vector<GameObject*>& tankVect) = 0;
};

#endif