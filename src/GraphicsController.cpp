#include "GraphicsController.h"

GraphicsController::GraphicsController()
{
  hwnd = GetConsoleWindow();
  hdc = GetDC(hwnd);
  Gdiplus::GdiplusStartupInput gdiplusStartupInput;
  Gdiplus::GdiplusStartup(&m_gdiplusToken, &gdiplusStartupInput, nullptr);
  blackBrush = new Gdiplus::SolidBrush(Gdiplus::Color(0, 0, 0));
  whiteBrush = new Gdiplus::SolidBrush(Gdiplus::Color(255, 255, 255));
  transpBrush = new Gdiplus::SolidBrush(Gdiplus::Color(100, 0, 0, 0));
  redBrush = new Gdiplus::SolidBrush(Gdiplus::Color(255, 0, 0));
  blueBrush = new Gdiplus::SolidBrush(Gdiplus::Color(0, 0, 255));
  upperBound = new Gdiplus::Rect(0,0,600,20);

}

GraphicsController::~GraphicsController()
{
  delete blackBrush;
  delete transpBrush;
  delete whiteBrush;
  delete redBrush;
  delete blueBrush;
  Gdiplus::GdiplusShutdown(m_gdiplusToken);
}

void GraphicsController::DrawFrame(Gdiplus::Graphics & graphics,
                                 std::vector<GameObject>& wallvect,
                                 std::vector<GameObject>& tankvect,
                                 Player& player)
{

  graphics.FillRectangle(whiteBrush, 0, 0, 600, 600);
  graphics.FillRectangle(transpBrush, 0, 601,600,100);
  graphics.FillRectangle(transpBrush, *upperBound);
  for (int i = 0; i < wallvect.size(); i++) {
    graphics.FillRectangle(blackBrush, wallvect[i].getRect());
    //graphics.FillRectangle(transpBrush, wallvect[i].getMask());
  }
  for (int i = 0; i < tankvect.size(); i++) {
    graphics.FillRectangle(redBrush, tankvect[i].getRect());
  }
  graphics.FillRectangle(transpBrush, player.getRect());
  graphics.FillRectangle(blueBrush, player.getCannon());
}
