#include <memory>
#include <thread>

#include "GraphicsController.h"

int main() {

  GameController::getInstance().gameInitialization();

  while (true) {

    GraphicsController::getInstance().DrawFrame( 
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