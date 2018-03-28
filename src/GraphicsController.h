#ifndef GRAPHICSCONTROLLER_H
#define GRAPHICSCONTROLLER_H

#include "GameController.h"

class GraphicsController {
public:
  int seconds;
  int minutes;

  static GraphicsController& getInstance();

  void DrawFrame( 
                std::vector<std::shared_ptr<Wall>>& wallvect,
                std::vector<std::shared_ptr<Tank>>& tankvect,
                std::vector<std::shared_ptr<Missile>>& missvect,
                Player& player);

  void drawStats(Gdiplus::Graphics& graph);

private:

  static GraphicsController * p_instance;

  ULONG_PTR m_gdiplusToken;
  HDC hdc;
  HDC mem_DC;
  HWND hwnd;

  GraphicsController();
  GraphicsController(const GraphicsController&);
  GraphicsController& operator=(GraphicsController&);
  ~GraphicsController();

};

#endif
