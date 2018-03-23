#include "WallsGeneration.h"

WallsGeneration::WallsGeneration()
{
}

WallsGeneration::~WallsGeneration()
{
}

void WallsGeneration::generateGameObjects(int count,
                                         std::vector<GameObject*>& objVect,
                                         std::vector<GameObject*>& tankVect)
{
  bool flag = false;
  for (int i = 0; i < count; i++) {
    objVect.push_back(GameObject::createGameObject(WALL));
    randomizeWall(*objVect[i]);
    if (i >= 1) {
      flag = false;
      while (flag == false) {
        flag = true;
        for (int j = 0; j <= i - 1; j++) {
          if (objVect[i]->getMask().IntersectsWith(objVect[j]->getMask())) {
            flag = false;
            randomizeWall(*objVect[i]);
            break;
          }
        }
      }
    }
  }
}

void WallsGeneration::randomizeWall(GameObject& wall)
{
  std::random_device rd;
  std::mt19937 mt(rd());
  std::uniform_int_distribution<int> randomX(20, 450);
  std::uniform_int_distribution<int> randomY(20, 400);
  std::uniform_int_distribution<int> randomsize(70, 120);
  wall.getMask().X = randomX(mt);
  wall.getRect().X = wall.getMask().X + 20;
  wall.getMask().Y = randomY(mt);
  wall.getRect().Y = wall.getMask().Y + 20;
  wall.getMask().Height = randomsize(mt);
  wall.getRect().Height = wall.getMask().Height - 40;
  wall.getMask().Width = randomsize(mt);
  wall.getRect().Width = wall.getMask().Width - 40;
}
