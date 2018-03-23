#ifndef TANKSGENERATION_H
#define TANKSGENERATION_H

#include "Generation.h"

class TanksGeneration :public Generation {
public:
  void randomizeTank(GameObject& tank);
  void generateGameObjects(int count, 
                           std::vector<GameObject*>& objVect,
                           std::vector<GameObject*>& tankVect);
};





#endif
