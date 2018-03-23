#include <memory>
#include <thread>

#include "GameController.h"
#include "GraphicsController.h"
#include "WallsGeneration.h"
#include "TanksGeneration.h"

int main() {
  system("mode con lines=44 cols=75");
  GraphicsController graphicController;
  GameController gameController;
  Player player;

  Gdiplus::Graphics graphics(graphicController.hdc);

  Generator* ptr = new Generator(new WallsGeneration);
  ptr->generateGameObjects(12, gameController.wallVect,
                               gameController.tankVect);
  delete ptr;
  ptr = new Generator(new TanksGeneration);
  ptr->generateGameObjects(5, gameController.wallVect,
                              gameController.tankVect);
  delete ptr;
  
  std::thread first_thread(GameController::getControlKeys, 
                                  std::ref(player), 
                                  std::ref(gameController.wallVect), 
                                  std::ref(gameController.tankVect));
  first_thread.detach();

  while (true) {
    graphicController.DrawFrame(graphics, 
                                gameController.wallVect,
                                gameController.tankVect,
                                player);
    Sleep(33);
  }
  return 0;
}