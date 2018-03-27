#include "GraphicsController.h"

GraphicsController::GraphicsController()
{
  Gdiplus::GdiplusStartupInput gdiplusStartupInput;
  Gdiplus::GdiplusStartup(&m_gdiplusToken, &gdiplusStartupInput, nullptr);
  hwnd = GetConsoleWindow();
  hdc = GetDC(hwnd);
  mem_DC = CreateCompatibleDC(hdc);
  blackBrush = new Gdiplus::SolidBrush(Gdiplus::Color(0, 0, 0));
  whiteBrush = new Gdiplus::SolidBrush(Gdiplus::Color(255, 255, 255));
  transpBrush = new Gdiplus::SolidBrush(Gdiplus::Color(100, 0, 0, 0));
  redBrush = new Gdiplus::SolidBrush(Gdiplus::Color(255, 0, 0));
  blueBrush = new Gdiplus::SolidBrush(Gdiplus::Color(0, 0, 255));
  upperBound = new Gdiplus::Rect(0,0,600,20);
  downBound = new Gdiplus::Rect(0, 580, 600, 20);
  leftBound = new Gdiplus::Rect(0, 20, 20, 560);
  rightBound = new Gdiplus::Rect(580, 20, 20, 560);
  mainField = new Gdiplus::Rect(0, 0, 600, 600);
  statField = new Gdiplus::Rect(0, 601, 600, 100);
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

void GraphicsController::DrawFrame(
                                 std::vector<std::shared_ptr<Wall>>& wallvect,
                                 std::vector<std::shared_ptr<Tank>>& tankvect,
                                 std::vector<std::shared_ptr<Missile>>& missvect,
                                 Player& player)
{
  Gdiplus::Graphics main(hdc);
  Gdiplus::Bitmap buffer(600, 700, &main);
  Gdiplus::Graphics buf(&buffer);
  buf.FillRectangle(whiteBrush, *mainField);
  buf.FillRectangle(transpBrush, *statField);
  buf.FillRectangle(transpBrush, *upperBound);
  buf.FillRectangle(transpBrush, *downBound);
  buf.FillRectangle(transpBrush, *leftBound);
  buf.FillRectangle(transpBrush, *rightBound);
  for (int i = 0; i < wallvect.size(); i++) {
    buf.FillRectangle(blackBrush, wallvect[i]->getRect());
  }
  for (int i = 0; i < tankvect.size(); i++) {
    buf.FillRectangle(redBrush, tankvect[i]->getRect());
  }
  for (int i = 0; i < missvect.size(); i++) {
    buf.FillRectangle(blackBrush, missvect[i]->getRect());
  }
  buf.FillRectangle(transpBrush, player.getCannon());
  buf.FillRectangle(blueBrush, player.getRect());
  main.DrawImage(&buffer, 0, 0, 0, 0, 600, 700,Gdiplus::UnitPixel);
}
