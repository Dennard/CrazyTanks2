#ifndef GRAPHICSCONTROLLER_H
#define GRAPHICSCONTROLLER_H

#include "GameController.h"


class GraphicsController {
public:
  HDC hdc;
  HWND hwnd;
  GraphicsController();
  ~GraphicsController();
  void DrawFrame(Gdiplus::Graphics& graphics, std::vector<GameObject*>& wallvect);
private:

};




#endif
