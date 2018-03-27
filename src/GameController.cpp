#include "GameController.h"
#include <conio.h>

GameController* GameController::p_instance = nullptr;

GameController & GameController::getInstance()
{
  if (!p_instance)
    p_instance = new GameController();
  return *p_instance;
}

void GameController::getControlKeys(Player& player,
                                    std::vector<std::shared_ptr<Wall>>& wallVect,
                                    std::vector<std::shared_ptr<Tank>>& tankVect,
                                    std::vector<std::shared_ptr<Missile>>& missVect)
{
  char symbol = _getch();
  while ((symbol = _getch())) {
  if (symbol == 32) {
    Missile fire(player, missVect);
  }
  else {
      switch (symbol) {
      case 72://up
        player.moveForward(wallVect, tankVect);
        break;
      case 75://left
        player.turnLeft();
        break;
      case 77://right
        player.turnRight();
        break;
      case 80://down
        player.moveBackward(wallVect, tankVect);
        break;
      default:
        break;
      }
    }
  }
}

void GameController::checkMissilesCollision()
{
  if (missileVect.size() > 0) {
    for (int i = 0; i < missileVect.size(); i++) {
      int count = missileVect.size();
      if (missileVect.size() > 0) {
        if (missileVect[i]->getRect().Y <= 20 ||
          missileVect[i]->getRect().Y >= 570 ||
          missileVect[i]->getRect().X >= 570 ||
          missileVect[i]->getRect().X <= 20) {
          missileVect.erase(missileVect.begin() + i);
          break;
        }
      }
      if (missileVect.size() > 0 && missileVect.size() >= count) {
        for (int j = 0; j < wallVect.size(); j++) {
          if (missileVect[i]->getRect().IntersectsWith(wallVect[j]->getRect())) {
            wallVect.erase(wallVect.begin() + j);
            missileVect.erase(missileVect.begin() + i);
            break;
          }
        }
      }
      if (missileVect.size() > 0 && missileVect.size() >= count) {
        for (int n = 0; n < tankVect.size(); n++) {
          if (missileVect[i]->getRect().IntersectsWith(tankVect[n]->getRect())) {
            tankVect.erase(tankVect.begin() + n);
            missileVect.erase(missileVect.begin() + i);
            break;
          }
        }
      }
    }
  }
}

GameController::GameController()
{

}

GameController::GameController(const GameController &)
{

}

GameController::~GameController()
{

}
