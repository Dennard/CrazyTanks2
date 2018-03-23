#include "Generator.h"

Generator::~Generator()
{
}

void Generator::generateGameObjects(int count, std::vector<GameObject*>& objVect)
{
  p->generateGameObjects(count, objVect);
}
