#ifndef GAMECONSTANTS_H
#define GAMECONSTANTS_H

#include <ObjIdl.h>
#include <gdiplus.h>

class GameConstants {
public:

  static const Gdiplus::Rect getMainFieldRect();
  static const Gdiplus::Rect getStatFieldRect();

  static const Gdiplus::Rect getDownBorderRect();
  static const Gdiplus::Rect getUpperBorderRect();
  static const Gdiplus::Rect getLeftBorderRect();
  static const Gdiplus::Rect getRightBorderRect();

  static Gdiplus::SolidBrush* getWhiteBrush();
  static Gdiplus::SolidBrush* getBlackBrush();
  static Gdiplus::SolidBrush* getRedBrush();
  static Gdiplus::SolidBrush* getBlueBrush();
  static Gdiplus::SolidBrush* getTranspBrush();

  static const int getTankSize();

  static const int getPlayerStartingPosX();
  static const int getPlayerStartingPosY();

private:

  GameConstants();
  GameConstants(const GameConstants&);
  GameConstants& operator=(const GameConstants&);
  ~GameConstants();

};

#endif