#include "WallsGeneration.h"

WallsGeneration::WallsGeneration()
{
}

WallsGeneration::~WallsGeneration()
{
}

void WallsGeneration::generateGameObjects(int count,
                                         std::vector<std::shared_ptr<Wall>>& wallVect,
                                         std::vector<std::shared_ptr<Tank>>& tankVect)
{
  bool flag = false;
  for (int i = 0; i < count; i++) {
    Wall wall;
    auto wall_ptr = std::make_shared<Wall>(wall);
    wallVect.push_back(wall_ptr);
    randomizeWall(*wallVect[i]);
    if (i >= 1) {
      flag = false;
      while (flag == false) {
        flag = true;
        for (int j = 0; j <= i - 1; j++) {
          if (wallVect[i]->getMask().IntersectsWith(wallVect[j]->getMask())) {
            flag = false;
            randomizeWall(*wallVect[i]);
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
