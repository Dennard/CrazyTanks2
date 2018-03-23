#include "GraphicsController.h"

GraphicsController::GraphicsController()
{
  hwnd = GetConsoleWindow();
  hdc = GetDC(hwnd);
}

GraphicsController::~GraphicsController()
{

}

void GraphicsController::DrawFrame(Gdiplus::Graphics & graphics,
                                 std::vector<GameObject*>& wallvect)
{
  static const Gdiplus::SolidBrush blackBrush(Gdiplus::Color(0, 0, 0));
  static const Gdiplus::SolidBrush whiteBrush(Gdiplus::Color(255, 255, 255));
  static const Gdiplus::SolidBrush transpBrush(Gdiplus::Color(100,0, 0, 0));
  static const Gdiplus::SolidBrush redBrush(Gdiplus::Color(255, 0, 0));

  graphics.FillRectangle(&whiteBrush, 0, 0, 600, 600);
  graphics.FillRectangle(&transpBrush, 0, 601,600,100);
  for (int i = 0; i < wallvect.size(); i++) {
    graphics.FillRectangle(&transpBrush, wallvect[i]->getMask());
    graphics.FillRectangle(&blackBrush, wallvect[i]->getRect());
  }
}
