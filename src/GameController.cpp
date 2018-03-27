#include "GameController.h"
#include <conio.h>

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
