#include <memory>
#include <thread>

#include "GameController.h"
#include "GraphicsController.h"
#include "WallsGeneration.h"
#include "TanksGeneration.h"

int main() {
  system("mode con lines=50 cols=75");
  GraphicsController graphicController;
  GameController gameController;
  Player player;

  Generator* ptr = new Generator(new WallsGeneration);
  ptr->generateGameObjects(5, gameController.wallVect,
                               gameController.tankVect);
  delete ptr;
  ptr = new Generator(new TanksGeneration);
  ptr->generateGameObjects(5, gameController.wallVect,
                              gameController.tankVect);
  delete ptr;
  
  std::thread first_thread(GameController::getControlKeys, 
                                  std::ref(player), 
                                  std::ref(gameController.wallVect), 
                                  std::ref(gameController.tankVect),
                                  std::ref(gameController.missileVect));
  first_thread.detach();

  while (true) {
    graphicController.DrawFrame( 
                                gameController.wallVect,
                                gameController.tankVect,
                                gameController.missileVect,
                                player);
    for (int i = 0; i < gameController.missileVect.size(); i++) {
      gameController.missileVect[i]->move();
    }
    Sleep(16);
  }
  return 0;
}