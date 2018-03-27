#include <memory>
#include <thread>

#include "GraphicsController.h"
#include "WallsGeneration.h"
#include "TanksGeneration.h"

int main() {
  system("mode con lines=50 cols=75");
  GraphicsController graphicController;

  Generator* ptr = new Generator(new WallsGeneration);
  ptr->generateGameObjects(10, GameController::getInstance().wallVect,
                               GameController::getInstance().tankVect);
  delete ptr;
  ptr = new Generator(new TanksGeneration);
  ptr->generateGameObjects(5, GameController::getInstance().wallVect,
                              GameController::getInstance().tankVect);
  delete ptr;
  
  std::thread controls_thread(GameController::getControlKeys, 
                                  std::ref(Player::getInstance()), 
                                  std::ref(GameController::getInstance().wallVect),
                                  std::ref(GameController::getInstance().tankVect),
                                  std::ref(GameController::getInstance().missileVect));
  controls_thread.detach();

  while (true) {

    for (int i = 0; i < GameController::getInstance().missileVect.size(); i++) {
      GameController::getInstance().missileVect[i]->move();
    }

    GameController::getInstance().checkMissilesCollision();

    graphicController.DrawFrame( 
                                GameController::getInstance().wallVect,
                                GameController::getInstance().tankVect,
                                GameController::getInstance().missileVect,
                                Player::getInstance());

    Sleep(16);
  }
  return 0;
}