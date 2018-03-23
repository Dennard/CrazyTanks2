#include "TanksGeneration.h"

void TanksGeneration::randomizeTank(GameObject & tank)
{
  std::random_device rd;
  std::mt19937 mt(rd());
  std::uniform_int_distribution<int> randomX(20, 450);
  std::uniform_int_distribution<int> randomY(20, 400);
  tank.getMask().X = randomX(mt);
  tank.getRect().X = tank.getMask().X + 15;
  tank.getMask().Y = randomY(mt);
  tank.getRect().Y = tank.getMask().Y + 15;
}

void TanksGeneration::generateGameObjects(int count, 
                                          std::vector<GameObject*>& objVect, 
                                          std::vector<GameObject*>& tankVect)
{
  bool flag = false;
  for (int i = 0; i < count; i++) {
    tankVect.push_back(GameObject::createGameObject(TANK));
    randomizeTank(*tankVect[i]);
    if (i >= 1) {
      flag = false;
      while (flag == false) {
        flag = true;
          for (int j = 0; j <objVect.size(); j++) {
            if (tankVect[i]->getRect().IntersectsWith(objVect[j]->getRect())) {
              flag = false;
              randomizeTank(*tankVect[i]);
              break;
            }
            for (int n = 0; n < i - 1; n++) {
              if (tankVect[i]->getMask().IntersectsWith(tankVect[n]->getMask())) {
                flag = false;
                randomizeTank(*tankVect[i]);
                break;
              }
            }
          }
        
        }

      }
    }
  }

