#include "Generator.h"

Generator::~Generator()
{
}

void Generator::generateGameObjects(int count, 
                                  std::vector<GameObject*>& objVect, 
                                  std::vector<GameObject*>& tankVect)
{
  p->generateGameObjects(count, objVect,tankVect);
}
