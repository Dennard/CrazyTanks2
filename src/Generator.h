#ifndef GENERATOR_H
#define GENERATOR_H

//#include "WallsGeneration.h"
#include "Generation.h"
/*enum GeneratorType {
  WALL,
  TANK
};*/

class Generator {
public:
  Generator(Generation* gen) : p(gen) {}
  ~Generator();
  void generateGameObjects(int count,
                        std::vector<GameObject*>& objVect,
                        std::vector<GameObject*>& tankVect);
private:
  Generation * p;
};

#endif 
