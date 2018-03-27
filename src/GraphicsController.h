#ifndef GRAPHICSCONTROLLER_H
#define GRAPHICSCONTROLLER_H

#include "GameController.h"

class GraphicsController {
public:
  HDC hdc;
  HDC mem_DC;
  HWND hwnd;
  GraphicsController();
  ~GraphicsController();
  void DrawFrame( 
                std::vector<std::shared_ptr<Wall>>& wallvect,
                std::vector<std::shared_ptr<Tank>>& tankvect,
                std::vector<std::shared_ptr<Missile>>& missvect,
                Player& player);

private:

  ULONG_PTR m_gdiplusToken;
  const Gdiplus::SolidBrush* blackBrush;
  const Gdiplus::SolidBrush* whiteBrush;
  const Gdiplus::SolidBrush* transpBrush;
  const Gdiplus::SolidBrush* redBrush;
  const Gdiplus::SolidBrush* blueBrush;
  const Gdiplus::Rect* upperBound;
  const Gdiplus::Rect* downBound;
  const Gdiplus::Rect* leftBound;
  const Gdiplus::Rect* rightBound;
  const Gdiplus::Rect* mainField;
  const Gdiplus::Rect* statField;
};

#endif
