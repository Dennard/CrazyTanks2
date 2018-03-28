#include "GraphicsController.h"

GraphicsController::GraphicsController()
{
  Gdiplus::GdiplusStartupInput gdiplusStartupInput;
  Gdiplus::GdiplusStartup(&m_gdiplusToken, &gdiplusStartupInput, nullptr);
  hwnd = GetConsoleWindow();
  hdc = GetDC(hwnd);
  mem_DC = CreateCompatibleDC(hdc);
  system("mode con lines=50 cols=75");
}

GraphicsController::~GraphicsController()
{
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

  buf.FillRectangle(GameConstants::getWhiteBrush(), 
                    GameConstants::getMainFieldRect());

  buf.FillRectangle(GameConstants::getBlackBrush(), 
                    GameConstants::getStatFieldRect());

  buf.FillRectangle(GameConstants::getTranspBrush(),
                    GameConstants::getDownBorderRect());

  buf.FillRectangle(GameConstants::getTranspBrush(),
                    GameConstants::getUpperBorderRect());

  buf.FillRectangle(GameConstants::getTranspBrush(),
                    GameConstants::getLeftBorderRect());

  buf.FillRectangle(GameConstants::getTranspBrush(),
                    GameConstants::getRightBorderRect());

  for (int i = 0; i < wallvect.size(); i++) {
    buf.FillRectangle(GameConstants::getBlackBrush(), wallvect[i]->getRect());
  }
  for (int i = 0; i < tankvect.size(); i++) {
    buf.FillRectangle(GameConstants::getRedBrush(), tankvect[i]->getRect());
    buf.FillRectangle(GameConstants::getBlackBrush(), tankvect[i]->getCannon());
  }
  for (int i = 0; i < missvect.size(); i++) {
    buf.FillRectangle(GameConstants::getBlackBrush(), missvect[i]->getRect());
  }  

  buf.FillRectangle(GameConstants::getBlueBrush(), player.getRect());
  buf.FillRectangle(GameConstants::getBlackBrush(), player.getCannon());
  main.DrawImage(&buffer, 0, 0, 0, 0, 
                 GameConstants::getMainFieldRect().Width, 
                 GameConstants::getMainFieldRect().Height,
                 Gdiplus::UnitPixel);
}
