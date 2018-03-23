#ifndef GRAPHICSCONTROLLER_H
#define GRAPHICSCONTROLLER_H

#include "GameController.h"

class GraphicsController {
public:
  HDC hdc;
  HWND hwnd;
  GraphicsController();
  ~GraphicsController();
  void DrawFrame(Gdiplus::Graphics& graphics, 
                std::vector<GameObject*>& wallvect,
                std::vector<GameObject*>& tankvect,
                  Player& player);
private:
  ULONG_PTR m_gdiplusToken;
  const Gdiplus::SolidBrush* blackBrush;
  const Gdiplus::SolidBrush* whiteBrush;
  const Gdiplus::SolidBrush* transpBrush;
  const Gdiplus::SolidBrush* redBrush;
  const Gdiplus::SolidBrush* blueBrush;
};

#endif
