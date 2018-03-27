#include "Generator.h"

Generator::~Generator()
{
}

void Generator::generateGameObjects(int count, 
                                  std::vector<std::shared_ptr<Wall>>& objVect,
                                  std::vector<std::shared_ptr<Tank>>& tankVect)
{
  p->generateGameObjects(count, objVect,tankVect);
}
