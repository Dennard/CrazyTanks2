#include "GraphicsController.h"
#include <string>
#include <mutex>

GraphicsController* GraphicsController::p_instance = nullptr;

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

GraphicsController & GraphicsController::getInstance()
{
  if (!p_instance)
    p_instance = new GraphicsController();
  return *p_instance;
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

  std::mutex stime;
  stime.lock();

  std::wstring time = L"TIME: " + std::to_wstring(minutes) + L":" + std::to_wstring(seconds);
  const wchar_t* chr = time.c_str();

  stime.unlock();
  Gdiplus::PointF ptf(10, 610);
  Gdiplus::FontFamily  fontFamily(L"Times New Roman");
  //Gdiplus::Font stdfont(&fontFamily, 28, Gdiplus::FontStyleRegular, Gdiplus::UnitPixel);
  buf.DrawString(chr, -1, GameConstants::getStandartFont(),
    *GameConstants::getTimeStringPoint(),
    GameConstants::getWhiteBrush());

  main.DrawImage(&buffer, 0, 0, 0, 0, 
                 GameConstants::getMainFieldRect().Width, 
                 GameConstants::getMainFieldRect().Height,
                 Gdiplus::UnitPixel);
}

void GraphicsController::drawStats(Gdiplus::Graphics & graph)
{

}

