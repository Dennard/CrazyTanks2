#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include "Generator.h"
#include "Player.h"
#include "Missile.h"
#include "Wall.h"

class GameController {
public:

  static GameController& getInstance();

  std::vector<std::shared_ptr<Wall>> wallVect;
  std::vector<std::shared_ptr<Tank>> tankVect;
  std::vector<std::shared_ptr<Missile>> missileVect;

  static void getControlKeys(Player& player, 
                            std::vector<std::shared_ptr<Wall>>& wallVect,
                            std::vector<std::shared_ptr<Tank>>& tankVect,
                            std::vector<std::shared_ptr<Missile>>& missVect);

  void checkMissilesCollision();

private:

  static GameController * p_instance;

  GameController();
  GameController(const GameController&);
  GameController& operator=(GameController&);
  ~GameController();

};

#endif