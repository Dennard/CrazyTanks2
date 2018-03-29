#include "Missile.h"

Missile::Missile()
{

}

Missile::Missile(Tank& tank, std::vector<std::shared_ptr<Missile>>& missVect)
{
  getRect().Height = 10;
  getRect().Width = 10;

  switch (tank.tankDirection) {
  case UP:
    getRect().X = tank.getRect().X + 10;
    getRect().Y = tank.getRect().Y - 10;
    missDirection = UP;
    break;
  case DOWN:
    getRect().X = tank.getRect().X + 10;
    getRect().Y = tank.getRect().Y + 30;
    missDirection = DOWN;
    break;
  case LEFT:
    getRect().X = tank.getRect().X - 10;
    getRect().Y = tank.getRect().Y + 10;
    missDirection = LEFT;
    break;
  case RIGHT:
    getRect().X = tank.getRect().X + 30;
    getRect().Y = tank.getRect().Y + 10;
    missDirection = RIGHT;
    break;
  }

  auto ptr = std::make_shared<Missile>(*this);
  missVect.push_back(ptr);
}

Missile::~Missile()
{

}

void Missile::move()
{
  switch (missDirection) {
  case UP:
    getRect().Y -= 20;
    break;
  case DOWN:
    getRect().Y += 20;
    break;
  case LEFT:
      getRect().X -= 20;
    break;
  case RIGHT:
    getRect().X += 20;
    break;
  }
}
