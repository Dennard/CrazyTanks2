#ifndef GENERATOR_H
#define GENERATOR_H

#include "Generation.h"

class Generator {
public:
  Generator(Generation* gen) : p(gen) {}
  ~Generator();
  void generateGameObjects(int count,
                        std::vector<GameObject>& objVect,
                        std::vector<GameObject>& tankVect);
private:
  Generation * p;
};

#endif 
