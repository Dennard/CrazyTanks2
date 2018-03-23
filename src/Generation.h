#ifndef GENERATION_H
#define GENERATION_H

#include "GameObject.h"

class Generation {
public:
  virtual void generateGameObjects(int count, std::vector<GameObject*>& objVect) = 0;
};

#endif