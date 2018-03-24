#include "GameController.h"
#include <conio.h>
//#include "Wallsgenerating.h"

void GameController::getControlKeys(Tank & player, 
                                    std::vector<GameObject>& wallVect, 
                                    std::vector<GameObject>& tankVect)
{
  player.tankDirection = UP;
  char symbol = _getch();
  while ((symbol = _getch())) {
    switch (symbol) {
    case 72://up
      if (player.tankDirection == UP) {
        if (player.isCollisionCausedForward(wallVect, tankVect) == false) {
          player.getRect().Y -= 2;
          player.getMask().Y -= 2;
          player.getCannon().Y -= 2;
        }
      }
      if (player.tankDirection == DOWN) {
        if (player.isCollisionCausedBackward(wallVect, tankVect) == false) {
          player.getRect().Y += 2;
          player.getMask().Y += 2;
          player.getCannon().Y += 2;
        }
      }
      if (player.tankDirection == RIGHT) {
        if (player.isCollisionCausedRight(wallVect, tankVect) == false) {
          player.getRect().X += 2;
          player.getMask().X += 2;
          player.getCannon().X += 2;
        }
      }
      if (player.tankDirection == LEFT) {
        if (player.isCollisionCausedLeft(wallVect, tankVect) == false) {
          player.getRect().X -= 2;
          player.getMask().X -= 2;
          player.getCannon().X -= 2;
        }
      }
      break;
    case 75://left
      if (player.tankDirection == UP) {
        player.getCannon().X = player.getRect().X + 10;
        player.getCannon().Y = player.getRect().Y + 10;
        player.getCannon().Height = player.getRect().Height - 10;
        player.getCannon().Width = player.getRect().Width - 20;
        player.tankDirection = LEFT;
        break;
      }
      if (player.tankDirection == LEFT) {
        player.getCannon().X = player.getRect().X + 10;
        player.getCannon().Y = player.getRect().Y;
        player.getCannon().Height = player.getRect().Height - 20;
        player.getCannon().Width = player.getRect().Width - 10;
        player.tankDirection = DOWN;
        break;
      }
      if (player.tankDirection == DOWN) {
        player.getCannon().X = player.getRect().X;
        player.getCannon().Y = player.getRect().Y+10;
        player.getCannon().Height = player.getRect().Height - 10;
        player.getCannon().Width = player.getRect().Width - 20;
        player.tankDirection = RIGHT;
        break;
      }
      if (player.tankDirection == RIGHT) {
        player.getCannon().X = player.getRect().X + 10;
        player.getCannon().Y = player.getRect().Y + 10;
        player.getCannon().Height = player.getRect().Height - 20;
        player.getCannon().Width = player.getRect().Width - 10;
        player.tankDirection = UP;
        break;
      }

    case 77://right
      if (player.tankDirection == UP) {
        player.getCannon().X = player.getRect().X;
        player.getCannon().Y = player.getRect().Y+10;
        player.getCannon().Height = player.getRect().Height-10;
        player.getCannon().Width = player.getRect().Width-20;
        player.tankDirection = RIGHT;
        break;
      }
      if (player.tankDirection == LEFT) {
        player.getCannon().X = player.getRect().X+10;
        player.getCannon().Y = player.getRect().Y+10;
        player.getCannon().Height = player.getRect().Height-20;
        player.getCannon().Width = player.getRect().Width-10;
        player.tankDirection = UP;
        break;
      }
      if (player.tankDirection == DOWN) {
        player.getCannon().X = player.getRect().X+10;
        player.getCannon().Y = player.getRect().Y+10;
        player.getCannon().Height = player.getRect().Height-10;
        player.getCannon().Width = player.getRect().Width-20;
        player.tankDirection = LEFT;
        break;
      }
      if (player.tankDirection == RIGHT) {
        player.getCannon().X = player.getRect().X = 10;
        player.getCannon().Y = player.getRect().Y;
        player.getCannon().Height = player.getRect().Height - 20;
        player.getCannon().Width = player.getRect().Width - 10;
        player.tankDirection = DOWN;
        break;
      }
    case 80://down
      if (player.tankDirection == UP) {
        if (player.isCollisionCausedForward(wallVect, tankVect) == false) {
          player.getRect().Y += 2;
          player.getMask().Y += 2;
          player.getCannon().Y += 2;
        }
      }
      if (player.tankDirection == DOWN) {
        if (player.isCollisionCausedBackward(wallVect, tankVect) == false) {
          player.getRect().Y -= 2;
          player.getMask().Y -= 2;
          player.getCannon().Y -= 2;
        }
      }
      if (player.tankDirection == RIGHT) {
        if (player.isCollisionCausedLeft(wallVect, tankVect) == false) {
          player.getRect().X -= 2;
          player.getMask().X -= 2;
          player.getCannon().X -= 2;
        }
      }
      if (player.tankDirection == LEFT) {
        if (player.isCollisionCausedRight(wallVect, tankVect) == false) {
          player.getRect().X += 2;
          player.getMask().X += 2;
          player.getCannon().X += 2;
        }
      }
      break;
    default:
      break;
    }
  }
}
