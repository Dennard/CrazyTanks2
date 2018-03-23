#include "GameController.h"
#include "GraphicsController.h"
#include "WallsGeneration.h"


int main() {
  system("mode con lines=44 cols=75");
  ULONG_PTR m_gdiplusToken;
  Gdiplus::GdiplusStartupInput gdiplusStartupInput;
  Gdiplus::GdiplusStartup(&m_gdiplusToken, &gdiplusStartupInput, nullptr);

  GraphicsController tmp;
  GameController gmc;
  Gdiplus::Graphics graphics(tmp.hdc);
  Generator* ptr = new Generator(new WallsGeneration);
  ptr->generateGameObjects(12, gmc.wallVect);

  while (true) {
    tmp.DrawFrame(graphics, gmc.wallVect);
    Sleep(500);
  }
 
  Gdiplus::GdiplusShutdown(m_gdiplusToken);
  return 0;
}