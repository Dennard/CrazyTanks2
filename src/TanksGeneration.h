#ifndef TANKSGENERATION_H
#define TANKSGENERATION_H

#include "Generation.h"

class TanksGeneration :public Generation {
public:

  void generateGameObjects(int count, 
                           std::vector<std::shared_ptr<Wall>>& wallVect,
                           std::vector<std::shared_ptr<Tank>>& tankVect);

  void randomizeTank(GameObject& tank);

};





#endif
