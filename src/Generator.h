#ifndef GENERATOR_H
#define GENERATOR_H

#include "WallsGeneration.h"
#include "TanksGeneration.h"

class Generator {
public:

  Generator(Generation* gen) : p(gen) {}
  ~Generator();

  void generateGameObjects(int count,
                        std::vector<std::shared_ptr<Wall>>& wallVect,
                        std::vector<std::shared_ptr<Tank>>& tankVect);

private:
  Generation * p;
};

#endif 
