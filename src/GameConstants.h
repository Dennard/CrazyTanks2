#ifndef GAMECONSTANTS_H
#define GAMECONSTANTS_H

#include <ObjIdl.h>
#include <gdiplus.h>

  class GameConstants {
  public:

    static GameConstants & getInstance();

    const Gdiplus::Rect getMainFieldSize();
    const Gdiplus::Rect getStatFieldSize();

    const int getTankSize();

    const int getPlayerStartingPosX();
    const int getPlayerStartingPosY();

  private:

    GameConstants();
    GameConstants(const GameConstants&);
    //GameConstants& operator=(const GameConstants&);

    static GameConstants* p_instance;
  };

#endif