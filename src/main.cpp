#include <memory>
#include <thread>

#include "GraphicsController.h"
#include "WallsGeneration.h"
#include "TanksGeneration.h"

int main() {

  GraphicsController graphicController;

  GameController::getInstance().gameInitialization();

  while (true) {

    graphicController.DrawFrame( 
                                GameController::getInstance().wallVect,
                                GameController::getInstance().tankVect,
                                GameController::getInstance().missileVect,
                                Player::getInstance());

    for (int i = 0; i < GameController::getInstance().missileVect.size(); i++) {
      GameController::getInstance().missileVect[i]->move();
    }

    GameController::getInstance().checkMissilesCollision();

    Sleep(16);
  }
  return 0;
}